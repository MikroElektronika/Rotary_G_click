![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Rotary_G Click

---

- **CIC Prefix**  : ROTARYG
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Jul 2018.

---

### Software Support

We provide a library for the Rotary_G Click on our [LibStock](https://libstock.mikroe.com/projects/view/2496/rotary-g-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

This library contains two drivers for controling  the LEDs, 
as well as the functions of the encoder, the rotation in both directions, and  button press function.

Key functions :

- ``` void rotaryg_turnOnLedByData( uint16_t dataToWrite ) ``` - Function turn on led by data
- ``` void rotaryg_turnOnLedByPosition( uint8_t ledPosition ) ``` - Function turn on led by position
- ``` void rotaryg_resetLed() ``` - Function turn off all led

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes peripherals and set pins.
- Application Initialization - Initializes SPI driver, set initial states, set RST logic high and performs device configuration.
- Application Task - (code snippet) Show functionality of Rotary_G Click, rotating and turn on/off led's, using the SPI interface.


```.c

void applicationTask()
{
    rotaryg_turnOnLedByData( ledData );

    // Push button
    if ( rotaryg_buttonPush() )
    {
        stateNew = 1;
        if ( stateNew == 1 &&  stateOld == 0 )
        {
            stateOld = 1;
            ledState = ( ledState + 1 ) % 5;
            if ( ledState == 4 )
            {
                for ( stateOld=0; stateOld < 17; stateOld++ )
                {
                    rotaryg_turnOnLedByData( 0xAAAA );
                    Delay_100ms();
                    rotaryg_turnOnLedByData( 0x5555 );
                    Delay_100ms();
                }

                for ( stateOld=0; stateOld < 17; stateOld++ )
                {
                    rotaryg_turnOnLedByPosition( stateOld );
                    Delay_100ms();
                }

                ledState = 0;
                ledData = rotaryg_getLedData( ledState );
            }
            else
            {
                ledData = rotaryg_getLedData( ledState );
            }
        }
    }
    else
    {
        stateOld = 0;
    }

    // Rotate Clockwise and CounterClockwise
    if ( rotaryg_getPWMstate() == rotaryg_getANstate() )
    {
        stateOldRotate = 0;
        startStatus = rotaryg_getPWMstate() && rotaryg_getANstate();
    }
    else
    {
        stateNewRotate = 1;
        if ( stateNewRotate != stateOldRotate )
        {
            stateOldRotate = 1;
            if ( startStatus != rotaryg_getPWMstate() )
            {
                ledData = ( ledData << 1 ) | ( ledData >> 15 );
            }
            else
            {
                ledData = ( ledData >> 1 ) | ( ledData << 15 );
            }
        }
    }
}

```


The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2496/rotary-g-click) page.

Other mikroE Libraries used in the example:

- SPI

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
