/*
Date: 12/02/2025
Documentation: ----
Author of the project: Ericsón Vilcahuamán
-Contact: ericksm.electronica@gmail.com

*/

#include "mcc_generated_files/mcc.h"
#include "Soft_Uart.h"
#include "rtc.h"
#include "Utils.h"
#include <stdio.h>
#include "diskio.h"
#include "pff.h"

typedef enum
{
    Battery_Charging,
    Finish_Charging,
    Battery_Disconnected,
    Charger_Disconnect,
    Unpowered,
    Indefinite
}Charging_State;

volatile uint8_t counter_timer_send_data = 0;
char data_case[6][21]={"Battery Charging","Finish Charging","Battery Disconnected","Charger Disconnect","Unpowered","Indefinite"};

void main(void)
{
    uint8_t i_index=0;
    uint16_t v_pp;
    uint16_t i_pp;   
    uint16_t voltages[SAMPLE_SIZE] = {0};
    uint16_t intensities[SAMPLE_SIZE] = {0};   
    uint8_t counter_charger = 0;
    uint8_t send_data_sdcard = 1;
    Charging_State Battery_State = Unpowered;
    char data_record[32]="0000,2334,34:23:34,12/23/34\n";
    FRESULT res;
    FATFS fs;			/* File system object */
    UINT w;
    int24_t voltage;
    int24_t current;
    int24_t adc_read;
    SYSTEM_Initialize();
    SoftUart_Init();
    DateTime time = {5,6,7,8,9,5};

    LED_GREEN_SetHigh();
    __delay_ms(800);
    LED_GREEN_SetLow();
    CLRWDT();
    res = pf_mount(&fs);
    if(res==FR_OK)
    {
       LED_RED_SetHigh();
       __delay_ms(500);
       LED_RED_SetLow(); 
       __delay_ms(200);
       CLRWDT();
    }
    else while(1);//Auto restart
    LED_RED_SetHigh();
    __delay_ms(50);  // Wait 50ms to open the file
    res = pf_open("test.txt");//This task takes time to be processed
    if(res==FR_OK)
    {
       LED_RED_SetLow();   
    }
    else while(1);//Auto restart
    CLRWDT();
    for(i_index=0; i_index<SAMPLE_SIZE; i_index++)
    {
        adc_read = ADC_GetConversion(VOLTAGE);
        if(adc_read==0)adc_read = 1;//void negative voltage
        voltage = ( (4867 * adc_read) - 1371)/1000;
        voltages[i_index] = (uint16_t)voltage;
        adc_read = ADC_GetConversion(CURRENT);
        current = (1295 + 2270 * adc_read)/1000;
        intensities[i_index] = (uint16_t)current;
        __delay_ms(100);
        CLRWDT();
    }
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    RTC_GetTime(&time);//Add this function to check the correct operation of this module

    while (1)
    {
        adc_read = ADC_GetConversion(VOLTAGE);
        if(adc_read==0)adc_read = 1;//void negative voltage
        voltage = ((4867 * adc_read) -1371 )/1000;
        adc_read = ADC_GetConversion(CURRENT);
        current = (2129 + (1129 * adc_read))/1000;
        //Sample process voltage and current
        add_int((uint16_t)voltage, voltages);        
        add_int((uint16_t)current, intensities);
        //take the mean of measures
        voltage = mean(voltages);
        current = mean(intensities);
        v_pp = variation(voltages);
        i_pp = variation(intensities);
        
        //init state = Indefinite, if the program does not enter any conditional this will be its state
        Battery_State = Indefinite;
        if (current >4)
            Battery_State = Battery_Charging;
        else if (voltage > 4200)//before 4100 but some batteries reach this level when charged
        {
            if (v_pp > 80)
            {
                if (Battery_State == Battery_Charging)//In case the battery is removed when it is charging
                    Battery_State = Finish_Charging;
                else
                {
                    Battery_State = Battery_Disconnected;
                    LED_GREEN_SetLow();
                }
            }
            else
                Battery_State = Indefinite;                
        }
        else 
            if (v_pp>50)
            {
                if (voltage < 2900)
                {
                    Battery_State = Unpowered;
                    LED_GREEN_SetLow();
                }            
                else 
                    //before Indefinite but sometimes the voltage of charger drops below 4200
                    Battery_State = Battery_Disconnected; 
            }
            else if (v_pp < 7)
            {
                if (voltage > 2200)//This voltage level detects both charged and discharged batteries
                    if (Battery_State == Battery_Charging)
                        Battery_State = Finish_Charging;
                    else
                    {
                        Battery_State = Charger_Disconnect;
                        LED_RED_SetLow();
                    }                    
                else
                    Battery_State = Indefinite;
            }

        Soft_UART_Write_Text(data_case[Battery_State]);
        Soft_UART_Write_Text_Const("\n");
        Soft_UART_Write_Text_Const("Voltaje samp: ");
        SendNumber((uint16_t)voltage);
        Soft_UART_Write_Text_Const("\nCorriente samp: ");
        SendNumber((uint16_t)current);
        Soft_UART_Write_Text_Const("\nVoltaje pp: ");
        SendNumber(v_pp);
        Soft_UART_Write_Text_Const("\nCorriente pp: ");
        SendNumber(i_pp);
        Soft_UART_Write_Text_Const("\n\n");
        switch(Battery_State)
        {          
            case Battery_Charging:
                //send data to the sd card every 10 seconds
                if(counter_timer_send_data>=10)
                {
                    counter_timer_send_data = 0;
                    send_data_sdcard = 1;
                    counter_charger = 0;
                    RTC_GetTime(&time);
                    get_volt_curr_text(data_record,voltage,current);
                    get_time_text(data_record,time);
                    pf_write(data_record, 28, &w);
                    Soft_UART_Write_Text(data_record);
                    LED_GREEN_SetHigh();
                }
                else
                {
                    if(send_data_sdcard == 1)
                    {
                        counter_charger++;
                        if(counter_charger >=5)
                        {
                            counter_charger = 0;
                            send_data_sdcard = 0;
                            LED_GREEN_SetLow();
                        }
                    }
                }           

                break;
            case Finish_Charging:
                LED_RED_SetHigh();
                LED_GREEN_SetHigh();
                pf_write(0, 0, &w);//finish write process in sd card
                while(1)CLRWDT();
            case Battery_Disconnected:
                counter_charger++;
                if ( counter_charger>=5)
                {
                    LED_RED_Toggle();
                    counter_charger =0;
                } 
                break;
            case Charger_Disconnect:
                counter_charger++;
                if ( counter_charger>=5)
                {
                    LED_GREEN_Toggle();
                    counter_charger =0;
                }         
                break;
            case Unpowered:
                LED_RED_Toggle(); 
                break;
            default:
                asm("NOP");
        }
        CLRWDT();
    }
}