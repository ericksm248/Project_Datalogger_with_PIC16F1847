//////////////////////////////////////////////////////////////////////////////////	 
//RTC library
//Author: ericksm248
//This library is based on rtclib in some operations:
//https://github.com/adafruit/RTClib/tree/master
/****************************************************************************************************/

#ifndef _RTC_H_
#define _RTC_H_

#include "mcc_generated_files/examples/i2c2_master_example.h"
#include "Utils.h"

/***************************************************************************************************
                             Commonly used Ds1307 macros/Constants
***************************************************************************************************
  Below values are fixed and should not be changed. Refer Ds1307 DataSheet for more info*/

#define DS1307_ADDRESS    0x68  // I2C address for DS1307
#define DS1307_CONTROL    0x07  // Control register
/**************************************************************************************************/

/*******************************************************************
 * @name       :RTC_SetTime(DateTime * data);
 * @function   :Sets the internal date of the RTC to the one contained in the DateTime object.
 * @parameters :data: DateTime object containing the current date
 *                    (year, month, day / hour, min, sec)
 * @Author   :ericksm248
********************************************************************/
void RTC_SetTime(DateTime data);

/*******************************************************************
 * @name       :RTC_GetTime(DateTime * data);
 * @function   :Requests the date from the RTC and formats it accordingly.
 * @parameters :data: DateTime object used for reading the date from the RTC.
 *                    (year, month, day / hour, min, sec)
 * @Author   :ericksm248
********************************************************************/
void RTC_GetTime(DateTime * data);

#endif