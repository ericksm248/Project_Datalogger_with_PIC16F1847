<h1 align="center">Datalogger with the PIC16F1847 </h1>
<br>

This project uses Ngrok to make a local web server accessible on the internet. The web interface was created with HTML, CSS, and JavaScript, which is programmed on the ESP32. The web server uses HTTP GET and POST methods to interact with it.

## How does it work?

Anyone in the world can send a message using the web server on the ESP32, and the circuit displays this message on the TFT screen connected to the ESP32. For security reasons, Ngrok is used. You can also open ports on your router to make your app public, but this method is less secure.

The code on the ESP32 allows multiple connections and transfers data emulating **concurrency** thanks to the AsyncTCP library.
We have 3 pages, each containing 10 messages. New messages replace the old ones. You can switch between pages by pressing a button. The new messages always appear at the top of page 1, with older messages arranged consecutively below.

### Platformio Project
This project can be opened with PlatformIO and works very well. The project uses the libraries: ESPAsyncWebServer, AsyncTCP, and WiFi. For the TFT, I use the library from LCDWiki but have applied some custom modifications to it, adding new functions developed by me.

### TFT features
The TFT uses an SPI interface with an 8MHz data clock. The TFT used in this project has a resolution of 480x320 pixels, a 4-inch screen, and uses the ST7796 driver with 16 bits per pixel. 
This TFT requires commands and parameters for initial configuration, after which the screen can be used normally.

[![Texto alternativo](https://img.youtube.com/vi/eTEYG0FsEEo/maxresdefault.jpg)](https://www.youtube.com/watch?v=eTEYG0FsEEo)

Watch the explanation and demonstration video on YouTube by clicking the image!


Background image from Freepik
