#include "rtc.h"

void RTC_SetTime(DateTime data)
{
    uint8_t data_time[8] = {0,
                            bin2bcd(data.sec),
                            bin2bcd(data.min),
                            bin2bcd(data.hour),
                            0,
                            bin2bcd(data.day),
                            bin2bcd(data.month),
                            bin2bcd(data.year)};
    I2C2_WriteNBytes(DS1307_ADDRESS,data_time,8);
}

void RTC_GetTime(DateTime* data)
{
    uint8_t data_time[8];
    I2C2_ReadDataBlock(DS1307_ADDRESS,0x00,data_time,7);
    data->year = bcd2bin(data_time[6]);
    data->month = bcd2bin(data_time[5]);
    data->day = bcd2bin(data_time[4]);
    data->hour = bcd2bin(data_time[2]);
    data->min = bcd2bin(data_time[1]);
    data->sec = bcd2bin(data_time[0] & 0x7F);
}