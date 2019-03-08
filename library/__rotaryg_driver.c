/*
    __rotaryg_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__rotaryg_driver.h"
#include "__rotaryg_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __ROTARYG_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __ROTARYG_DRV_SPI__

void rotaryg_spiDriverInit(T_ROTARYG_P gpioObj, T_ROTARYG_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet(0);
    hal_gpio_rstSet(1);
}

#endif
#ifdef   __ROTARYG_DRV_I2C__

void rotaryg_i2cDriverInit(T_ROTARYG_P gpioObj, T_ROTARYG_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __ROTARYG_DRV_UART__

void rotaryg_uartDriverInit(T_ROTARYG_P gpioObj, T_ROTARYG_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif


/* ----------------------------------------------------------- IMPLEMENTATION */

/* Generic data write function */
void rotaryg_turnOnLedByData( uint16_t dataToWrite )
{
    uint8_t temp_buffer[ 2 ];
    temp_buffer[ 0 ] = dataToWrite >> 8;
    temp_buffer[ 1 ] = dataToWrite & 0x00FF;

    hal_gpio_csSet( 0 );
    hal_spiWrite( temp_buffer, 2 );
    Delay_10us();
    hal_gpio_csSet( 1 );
}

/* Generic data write function by led position */
void rotaryg_turnOnLedByPosition( uint8_t ledPosition )
{
    ledPosition %= 17;
    if ( ledPosition > 0 )
    {
        rotaryg_turnOnLedByData( 1 << ( ledPosition-1 ) );
    }
    if ( ledPosition == 0 )
    {
        rotaryg_resetLed();
    }
}

/* Button push state */
uint8_t rotaryg_buttonPush()
{
    return hal_gpio_intGet();
}

/* Get led data state */
uint16_t rotaryg_getLedData( uint8_t Current_Led_State )
{
      switch ( Current_Led_State )
      {
          case 0 : return 0x0001;                      // One LED
          break;
          case 1 : return 0x0101;                      // Two LED
          break;
          case 2 : return 0x1111;                      // Four LED
          break;
          case 3 : return 0x5555;                      // Eight LED
          break;
          default : return 0x0001;                     // One LED
          break;
      }
}

/* Reset led */
void rotaryg_resetLed()
{
    rotaryg_turnOnLedByData( 0x0000 );
}

/* State AN pin */
uint8_t rotaryg_getANstate()
{
    return hal_gpio_anGet();
}

/* State PWM pin */
uint8_t rotaryg_getPWMstate()
{
    return hal_gpio_pwmGet();
}





/* -------------------------------------------------------------------------- */
/*
  __rotaryg_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */