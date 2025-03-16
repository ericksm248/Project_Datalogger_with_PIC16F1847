
#include "Utils.h"

uint8_t bin2bcd(uint8_t val) 
{ 
    return val + 6 * (val / 10); 
}

uint8_t bcd2bin(uint8_t val) 
{ 
    return val - 6 * (val >> 4); 
}

//data record format {0000,2334,34:23:34,12/23/34\n}
void get_time_text(char* buff,DateTime time)
{
    buff[10]= time.hour/10+'0';
    buff[11]= time.hour%10+'0';    
    buff[13]= time.min/10+'0';
    buff[14]= time.min%10+'0';
    buff[16]= time.sec/10+'0';
    buff[17]= time.sec%10+'0';
    
    buff[19]= time.day/10+'0';
    buff[20]= time.day%10+'0';    
    buff[22]= time.month/10+'0';
    buff[23]= time.month%10+'0';
    buff[25]= time.year/10+'0';
    buff[26]= time.year%10+'0';    
}

void get_volt_curr_text(char* buff,uint16_t voltage,uint16_t current)
{
    int8_t j = 0;
    uint16_t aux = current;
    for (j=8;j>=0;j--)
    {
        if(j==4)
        {
            aux = voltage;
            continue;
        }
        buff[j]=(aux%10) + '0';
        aux/=10;
    }
}

void add_int(uint16_t val, uint16_t* arr)
{
    for(char i=0; i<SAMPLE_SIZE-1; i++) arr[i] = arr[i+1];
    arr[SAMPLE_SIZE-1] = val;
}

uint16_t mean(uint16_t* arr)
{
    uint16_t sum = 0;
    uint16_t out = 0;
    for(char i=0; i<SAMPLE_SIZE; i++) sum += arr[i];
    out = sum/SAMPLE_SIZE;
    
    return out;
}

uint16_t variation(uint16_t* arr)
{
    uint16_t v_max = 0;
    uint16_t v_min = 65535;
    for(char i=0; i<SAMPLE_SIZE; i++)
    {
        if(arr[i] > v_max) v_max = arr[i];
        if(arr[i] < v_min) v_min = arr[i];
    }
    
    return v_max - v_min;
}