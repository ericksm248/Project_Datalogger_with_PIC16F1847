<h1 align="center">Datalogger with the PIC16F1847 and SD card</h1>
<br>

In this project I use the PIC16F1847 and an SD card. This datalogger register the voltage and current from a lithium battery charger

## How does it work?
The datalogger measures the voltage and current from a lithium battery charger using analog inputs of the PIC16F1847. These measurements are then processed by the microcontroller and stored on the SD card in a txt file. The stored data can be extracted later for further analysis on a computer. Two LEDs and a serial communication port provide real-time feedback  on the operation of the datalogger. It is also necessary to obtain the time and date in which the data is recorded, for this purpose an RTC module is used.
      

### Mplab X IDE Project
The code of the project can be opened with Mplab X IDE and works very well. The project uses the libraries: Petit Fafts and softUart.

### SD CARD library aspects
The most popular library for managing file operations on an SD card is FatFs. However, in this case, using the PIC16F1847, it is necessary to use the lightweight version of this library, the Petit FatFs library. This library has limitations, but the functionalities that were tested are sufficient for this project. The library must be ported to the PIC. For this purpose, I used the examples provided by the library.   
More than 1,000 records were successfully stored!

### Data processing and graphics obtained


[![Texto alternativo](https://img.youtube.com/vi/qekGmXMEP9A/maxresdefault.jpg)](https://www.youtube.com/watch?v=qekGmXMEP9A)

Watch the explanation and demonstration video on YouTube by clicking the image!


Background image from Freepik
