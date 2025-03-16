//////////////////////////////////////////////////////////////////////////////////	 
//Utils library
//Original author: ericksm248
//Useful constants/functions required in the project.
/****************************************************************************************************/

#ifndef UTILS_H
#define	UTILS_H

#include <xc.h>
#include <stdint.h>

#define SAMPLE_SIZE 5

// Structure of a DateTime object
typedef struct {
    uint8_t sec;
    uint8_t min;
    uint8_t hour;
    uint8_t day;
    uint8_t month;
    uint8_t year;
} DateTime;

/*******************************************************************
 * @name       :bin2bcd(), bcd2bin()
 * @date       :Feb 2022 
 * @function   :Functions in charge of translating between binary and bcd data
 *              to be sent through the serial port.
 * @parameters :val: Value to be translated
********************************************************************/
uint8_t bin2bcd(uint8_t val);
uint8_t bcd2bin(uint8_t val); 


/*******************************************************************
 * @name       :get_time_text(char* buff,DateTime date)
 * @date       :Feb 2022 
 * @function   :Extracts the text of a DateTime object and stores it in a buffer.
 * @parameters :buff: Buffer where the date will be saved.
 *                    In its current implementation, its the buffer that sends data
 *                    to the SD card.
 *              date: DateTime object with the RTC time information.
 * @author	   :ericksm248
********************************************************************/
void get_time_text(char* buff,DateTime date);


/*******************************************************************
 * @name       :get_volt_curr_text(char* buff,uint16_t voltage,uint16_t current);
 * @date       :Feb 2022 
 * @function   :Extracts the text of the electrical measures and stores it in a buffer.
 * @parameters :buff: Buffer where the date will be saved.
 *                    In its current implementation, its the buffer that sends data
 *                    to the SD card.
 *              voltage: Measured average voltage.
 *              current: Measured average current.
 * @author	   :ericksm248
********************************************************************/
void get_volt_curr_text(char* buff,uint16_t voltage,uint16_t current);


/*******************************************************************
 * @name       :add_int(), mean(), variation()
 * @function   :Array and statistics functions:
 *              add_int() adds rolls the array and adds a sample
 *              mean() gets the statistical mean
 *              variation() gets the difference between maximum and minimum values.
********************************************************************/
void add_int(uint16_t val, uint16_t* arr);
uint16_t mean(uint16_t* arr);
uint16_t variation(uint16_t* arr);

#endif	/* XC_HEADER_TEMPLATE_H */