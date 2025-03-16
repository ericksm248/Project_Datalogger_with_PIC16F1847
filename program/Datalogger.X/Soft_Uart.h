//////////////////////////////////////////////////////////////////////////////////	 
//Software UART library
//Original author: chayanforyou
//Some functions have been added for this specific implementation. Some have been removed for the sake of saving space.
//From GitHub: https://github.com/chayanforyou/Soft-UART-PIC12F675/tree/main
/****************************************************************************************************/

#include <xc.h>
#define _XTAL_FREQ 16000000
#define BAUDRATE 9600

// Define TX, RX Pin
#define Soft_Uart_Tx  LATAbits.LATA0//GPIOBtris.///GPIOB.B0;
#define Soft_Uart_Rx PORTAbits.RA1
#define Soft_Uart_Tx_Direction TRISAbits.TRISA0
#define Soft_Uart_Rx_Direction TRISAbits.TRISA1

/*******************************************************************
 * @name       :SoftUart_Init()
 * @date       :Nov 2022 
 * @function   :Initializes serial communications
 * @parameters :None
 * @author	   :chayanforyou
********************************************************************/
void SoftUart_Init(void);

/*******************************************************************
 * @name       :Soft_UART_Write(unsigned char Data)
 * @date       :Nov 2022 
 * @function   :Sends a single byte of data (0-255) through the serial port
 * @parameters :Data: Char to be sent
 * @author	   :chayanforyou
********************************************************************/
void Soft_UART_Write(unsigned char Data);

/*******************************************************************
 * @name       :Soft_UART_Write_Text(char* Text)
 * @date       :Nov 2022 
 * @function   :Sends string through serial port
 * @parameters :Text: String to be sent
 * @author	   :chayanforyou
********************************************************************/
void Soft_UART_Write_Text(char* Text);

/*******************************************************************
 * @name       :Soft_UART_Write_Text_Const(char* Text)
 * @date       :Nov 2022 
 * @function   :Sends const string through serial port
 * @parameters :Text: Const string to be sent
 * @author	   :chayanforyou
********************************************************************/
void Soft_UART_Write_Text_Const(const char* Text);

/*******************************************************************
 * @name       :SendNumber(uint16_t num)
 * @date       :Feb 2025 
 * @function   :Sends a single 4-digit number through the serial port.
 * @parameters :num: Number to  be sent. Note that because of its type (uint16_t),
 *                   it has to be in the range 0-65535. Additionally, numbers
 *                   bigger than 9999 aren't supported, albeit the change to do so
 *                   is simple.
 * @author	   :ericksm248
********************************************************************/
void SendNumber(uint16_t num);

/*******************************************************************
 * @name       :Soft_UART_Read()
 * @date       :Nov 2022 
 * @function   :Read one chart data from soft serial
 * @parameters :void
 * @return value: unsigned char serial soft data
 * @author	   :chayanforyou
********************************************************************/
unsigned char Soft_UART_Read();

/*******************************************************************
 * @name       :Soft_UART_Read_Text(char* Buffer, char StopChar)
 * @date       :Nov 2022 
 * @function   :Read one chart data from soft serial
 * @parameters :Buffer: stores the text from serial communication
 *              StopChar: character data to stop reading text
 * @author	   :chayanforyou
********************************************************************/
void Soft_UART_Read_Text(char* Buffer, char StopChar);