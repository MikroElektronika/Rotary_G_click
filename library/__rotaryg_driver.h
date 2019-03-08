/*
    __rotaryg_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __rotaryg_driver.h
@brief    Rotary_G Driver
@mainpage Rotary_G Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   ROTARYG
@brief      Rotary_G Click Driver
@{

| Global Library Prefix | **ROTARYG** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jul 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _ROTARYG_H_
#define _ROTARYG_H_

/** 
 * @macro T_ROTARYG_P
 * @brief Driver Abstract type 
 */
#define T_ROTARYG_P    const uint8_t*

/** @defgroup ROTARYG_COMPILE Compilation Config */              /** @{ */

   #define   __ROTARYG_DRV_SPI__                            /**<     @macro __ROTARYG_DRV_SPI__  @brief SPI driver selector */
//  #define   __ROTARYG_DRV_I2C__                            /**<     @macro __ROTARYG_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __ROTARYG_DRV_UART__                           /**<     @macro __ROTARYG_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup ROTARYG_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup ROTARYG_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup ROTARYG_INIT Driver Initialization */              /** @{ */

#ifdef   __ROTARYG_DRV_SPI__
void rotaryg_spiDriverInit(T_ROTARYG_P gpioObj, T_ROTARYG_P spiObj);
#endif
#ifdef   __ROTARYG_DRV_I2C__
void rotaryg_i2cDriverInit(T_ROTARYG_P gpioObj, T_ROTARYG_P i2cObj, uint8_t slave);
#endif
#ifdef   __ROTARYG_DRV_UART__
void rotaryg_uartDriverInit(T_ROTARYG_P gpioObj, T_ROTARYG_P uartObj);
#endif

                                                                       /** @} */
/** @defgroup ROTARYG_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Generic data write function
 *
 * @param[in] dataToWrite Data to write
 *
 * Function turn on led by data
 */
void rotaryg_turnOnLedByData( uint16_t dataToWrite );

/**
 * @brief Turn on led by position
 *
 * @param[in] ledPosition Led position
 *
 * Function turn on led by position
 */
void rotaryg_turnOnLedByPosition( uint8_t ledPosition );

/**
 * @brief Button push state
 *
 * Function return 1 if button is pushed and return 0 if not
 */
uint8_t rotaryg_buttonPush();

/**
 * @brief Get led data state
 *
 * Function return 16-bit data by current led state
 */
uint16_t rotaryg_getLedData( uint8_t Current_Led_State );

/**
 * @brief Reset led
 *
 * Function turn off all led
 */
void rotaryg_resetLed();

/**
 * @brief State AN pin
 *
 * Function return AN state
 */
uint8_t rotaryg_getANstate();

/**
 * @brief State PWM pin
 *
 * Function return PWM state
 */
uint8_t rotaryg_getPWMstate();





                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Rotary_G_STM.c
    @example Click_Rotary_G_TIVA.c
    @example Click_Rotary_G_CEC.c
    @example Click_Rotary_G_KINETIS.c
    @example Click_Rotary_G_MSP.c
    @example Click_Rotary_G_PIC.c
    @example Click_Rotary_G_PIC32.c
    @example Click_Rotary_G_DSPIC.c
    @example Click_Rotary_G_AVR.c
    @example Click_Rotary_G_FT90x.c
    @example Click_Rotary_G_STM.mbas
    @example Click_Rotary_G_TIVA.mbas
    @example Click_Rotary_G_CEC.mbas
    @example Click_Rotary_G_KINETIS.mbas
    @example Click_Rotary_G_MSP.mbas
    @example Click_Rotary_G_PIC.mbas
    @example Click_Rotary_G_PIC32.mbas
    @example Click_Rotary_G_DSPIC.mbas
    @example Click_Rotary_G_AVR.mbas
    @example Click_Rotary_G_FT90x.mbas
    @example Click_Rotary_G_STM.mpas
    @example Click_Rotary_G_TIVA.mpas
    @example Click_Rotary_G_CEC.mpas
    @example Click_Rotary_G_KINETIS.mpas
    @example Click_Rotary_G_MSP.mpas
    @example Click_Rotary_G_PIC.mpas
    @example Click_Rotary_G_PIC32.mpas
    @example Click_Rotary_G_DSPIC.mpas
    @example Click_Rotary_G_AVR.mpas
    @example Click_Rotary_G_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __rotaryg_driver.h

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