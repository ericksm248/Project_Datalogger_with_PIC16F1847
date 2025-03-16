/*
 * 
*/

#include "mcc_generated_files/mcc.h"
#include "Soft_Uart.h"
#include "rtc.h"
#include "Utils.h"
#include <stdio.h>
#include "diskio.h"
#include "pff.h"

volatile uint8_t counter_timer_send_data = 0;

typedef enum
{
    Get_Measure,
    Battery_Charging,
    Finish_Charging,
    Battery_Disconnected,
    Charger_Disconnect,
    Unpowered
}Charging_State;

void main(void)
{
    SYSTEM_Initialize();
    DateTime time = {30,23,13,21,2,25};
    I2C2_Write1ByteRegister(DS1307_ADDRESS,DS1307_CONTROL,0b00010000);
    RTC_SetTime(time);//
    LED_RED_SetHigh();
    while(1)CLRWDT();
}
/**
 End of File
*/