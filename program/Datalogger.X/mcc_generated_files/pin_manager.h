/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1847
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set TX aliases
#define TX_TRIS                 TRISAbits.TRISA0
#define TX_LAT                  LATAbits.LATA0
#define TX_PORT                 PORTAbits.RA0
#define TX_ANS                  ANSELAbits.ANSA0
#define TX_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define TX_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define TX_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define TX_GetValue()           PORTAbits.RA0
#define TX_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define TX_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define TX_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define TX_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RX aliases
#define RX_TRIS                 TRISAbits.TRISA1
#define RX_LAT                  LATAbits.LATA1
#define RX_PORT                 PORTAbits.RA1
#define RX_ANS                  ANSELAbits.ANSA1
#define RX_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RX_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RX_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RX_GetValue()           PORTAbits.RA1
#define RX_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RX_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RX_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define RX_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set LED_RED aliases
#define LED_RED_TRIS                 TRISAbits.TRISA2
#define LED_RED_LAT                  LATAbits.LATA2
#define LED_RED_PORT                 PORTAbits.RA2
#define LED_RED_ANS                  ANSELAbits.ANSA2
#define LED_RED_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_RED_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_RED_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_RED_GetValue()           PORTAbits.RA2
#define LED_RED_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_RED_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_RED_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_RED_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set LED_GREEN aliases
#define LED_GREEN_TRIS                 TRISAbits.TRISA3
#define LED_GREEN_LAT                  LATAbits.LATA3
#define LED_GREEN_PORT                 PORTAbits.RA3
#define LED_GREEN_ANS                  ANSELAbits.ANSA3
#define LED_GREEN_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LED_GREEN_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LED_GREEN_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LED_GREEN_GetValue()           PORTAbits.RA3
#define LED_GREEN_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LED_GREEN_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LED_GREEN_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define LED_GREEN_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set RA6 procedures
#define RA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define RA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define RA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define RA6_GetValue()              PORTAbits.RA6
#define RA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define RA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)

// get/set SD_CS aliases
#define SD_CS_TRIS                 TRISBbits.TRISB0
#define SD_CS_LAT                  LATBbits.LATB0
#define SD_CS_PORT                 PORTBbits.RB0
#define SD_CS_WPU                  WPUBbits.WPUB0
#define SD_CS_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define SD_CS_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define SD_CS_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define SD_CS_GetValue()           PORTBbits.RB0
#define SD_CS_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define SD_CS_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define SD_CS_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define SD_CS_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RTC_INT aliases
#define RTC_INT_TRIS                 TRISBbits.TRISB3
#define RTC_INT_LAT                  LATBbits.LATB3
#define RTC_INT_PORT                 PORTBbits.RB3
#define RTC_INT_WPU                  WPUBbits.WPUB3
#define RTC_INT_ANS                  ANSELBbits.ANSB3
#define RTC_INT_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RTC_INT_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RTC_INT_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RTC_INT_GetValue()           PORTBbits.RB3
#define RTC_INT_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RTC_INT_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RTC_INT_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define RTC_INT_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define RTC_INT_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define RTC_INT_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set VOLTAGE aliases
#define VOLTAGE_TRIS                 TRISBbits.TRISB6
#define VOLTAGE_LAT                  LATBbits.LATB6
#define VOLTAGE_PORT                 PORTBbits.RB6
#define VOLTAGE_WPU                  WPUBbits.WPUB6
#define VOLTAGE_ANS                  ANSELBbits.ANSB6
#define VOLTAGE_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define VOLTAGE_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define VOLTAGE_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define VOLTAGE_GetValue()           PORTBbits.RB6
#define VOLTAGE_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define VOLTAGE_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define VOLTAGE_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define VOLTAGE_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define VOLTAGE_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define VOLTAGE_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set CURRENT aliases
#define CURRENT_TRIS                 TRISBbits.TRISB7
#define CURRENT_LAT                  LATBbits.LATB7
#define CURRENT_PORT                 PORTBbits.RB7
#define CURRENT_WPU                  WPUBbits.WPUB7
#define CURRENT_ANS                  ANSELBbits.ANSB7
#define CURRENT_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define CURRENT_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define CURRENT_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define CURRENT_GetValue()           PORTBbits.RB7
#define CURRENT_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define CURRENT_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define CURRENT_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define CURRENT_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define CURRENT_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define CURRENT_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF3 pin functionality
 * @Example
    IOCBF3_ISR();
 */
void IOCBF3_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF3 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF3 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF3_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF3 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF3_SetInterruptHandler() method.
    This handler is called every time the IOCBF3 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF3_SetInterruptHandler(IOCBF3_InterruptHandler);

*/
extern void (*IOCBF3_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF3 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF3_SetInterruptHandler() method.
    This handler is called every time the IOCBF3 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF3_SetInterruptHandler(IOCBF3_DefaultInterruptHandler);

*/
void IOCBF3_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/