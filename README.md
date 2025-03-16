<h1 align="center">Datalogger with the PIC16F1847 and SD card</h1>
<br>

In this project I use the PIC16F1847 and an SD card. This datalogger register the voltage and current from a lithium battery charger

## How does it work?
The datalogger measures the voltage and current from a lithium battery charger using analog inputs of the PIC16F1847. These measurements are then processed by the microcontroller and stored on the SD card in a txt file. The stored data can be extracted later for further analysis on a computer. Two LEDs and a serial communication port provide real-time feedback  on the operation of the datalogger. It is also necessary to obtain the time and date in which the data is recorded, for this purpose an RTC module is used.
      

### Mplab X IDE Project
The code of the project can be opened with Mplab X IDE and works very well. The project uses the libraries: Petit Fafts and softUart.

### SD CARD library aspects
The most popular library to manage the files operations in sd card is FatFs but in this case, using the PIC16F1847, is necesarry to take the ligth version of this library, the Petit Fafts library.
This library have limitations but the functionalitys that probed is enough for this project. More than 1,000 records were successfully stored!

### Data processing and graphics obtained


[![Texto alternativo](https://img.youtube.com/vi/qekGmXMEP9A/maxresdefault.jpg)](https://www.youtube.com/watch?v=qekGmXMEP9A)

Watch the explanation and demonstration video on YouTube by clicking the image!


Background image from Freepik
