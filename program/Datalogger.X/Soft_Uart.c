//////////////////////////////////////////////////////////////////////////////////	 
//Software UART library
//Original author: chayanforyou

#include "Soft_Uart.h"

// Constants necessary for the calculation of bauds and delays in the program
const unsigned char cristal = 16;    // Get the clock in MHz
#define DELAY_FOR_WRITE (4*14/cristal)        // Dxtra delay on writing 14us
#define DELAY_FOR_READ (4*10/cristal)         // Extra delay in reading 10us

#define BITPERIOD ((1000000/BAUDRATE))                      // 1-bit duration
#define BITPERIOD_FOR_WRITE (BITPERIOD - DELAY_FOR_WRITE)   // Actual write delay
#define BITPERIOD_FOR_READ (BITPERIOD - DELAY_FOR_READ)     // Actual read delay
#define HALFBITPERIOD (BITPERIOD/2)                         // Half bit duration
// End serial port constants


// Initialize serial communication
void  SoftUart_Init(void)
{
  Soft_Uart_Tx = 1;
  Soft_Uart_Rx = 1;
  Soft_Uart_Tx_Direction = 0;
  Soft_Uart_Rx_Direction = 1;
  Soft_Uart_Tx = 1;
  __delay_us(BITPERIOD);
}

// Send data through the serial port
void Soft_UART_Write(unsigned char Data)
{
  unsigned char mask;
  Soft_Uart_Tx = 0;
  __delay_us(BITPERIOD);

  // 14 clock cycles
  for (mask = 0x01; mask != 0; mask = mask << 1)
  {
    if (Data & mask) Soft_Uart_Tx = 1;
    else Soft_Uart_Tx = 0;
    __delay_us(BITPERIOD_FOR_WRITE);      // For greater precision according to the crystal because it is 14 clock cycles
  }
  Soft_Uart_Tx = 1;
  __delay_us(BITPERIOD);
}

// Send string through the serial port
void Soft_UART_Write_Text(char* Text)
{
  while (*Text)Soft_UART_Write(*Text++);
}

// Send const string through the serial port
void Soft_UART_Write_Text_Const(const char* Text)
{
  while (*Text)Soft_UART_Write(*Text++);
}

void SendNumber(uint16_t num) 
{
    char buffer[5]; 
	buffer[0] = (num / 1000) + '0'; 
	buffer[1] = (num / 100)%10 + '0'; 
	buffer[2] = (num / 10)%10  + '0'; 
	buffer[3] = (num % 10) + '0'; 
	buffer[4] = '\0'; 
    Soft_UART_Write_Text(buffer);

}

// Read data from serial port (blocking function)
unsigned char Soft_UART_Read()
{
  char mask;
  char Data = 0;

  while (Soft_Uart_Rx == 1);            // Wait for start bit
  __delay_us(HALFBITPERIOD);
  for (mask = 0x01; mask != 0; mask = mask << 1)
  {
    __delay_us(BITPERIOD_FOR_READ);       // Delay to read
    if (Soft_Uart_Rx) Data = Data | mask;
  }
  __delay_us(BITPERIOD);
  return Data;
}

void Soft_UART_Read_Text(char* Buffer, char StopChar)
{
  while (*(Buffer - 1) != StopChar)    // Wait until desired character does not arrive
  {
    *Buffer++ = Soft_UART_Read();      // Keep buffering
  }
  *--Buffer = 0;                       // Put trailing zero to make it string
}