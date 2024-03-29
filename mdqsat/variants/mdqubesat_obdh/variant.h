/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_METRO_M4_
#define _VARIANT_METRO_M4_

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK	(F_CPU)

#define VARIANT_GCLK0_FREQ (F_CPU)
#define VARIANT_GCLK1_FREQ (48000000UL)
#define VARIANT_GCLK2_FREQ (100000000UL)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (26u)
#define NUM_DIGITAL_PINS     (20u)
#define NUM_ANALOG_INPUTS    (8u)
#define NUM_ANALOG_OUTPUTS   (2u)
#define analogInputToDigitalPin(p)  ((p < 6u) ? (p) + 14u : -1)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

/*
 * Analog pins
 */
#define PIN_A0               (14ul)
#define PIN_A1               (PIN_A0 + 1)
#define PIN_A2               (PIN_A0 + 2)
#define PIN_A3               (PIN_A0 + 3)
#define PIN_A4               (PIN_A0 + 4)
#define PIN_A5               (PIN_A0 + 5)
#define PIN_A6               (PIN_A0 + 6)
#define PIN_A7               (PIN_A0 + 7)
#define PIN_DAC0             PIN_A0
#define PIN_DAC1             PIN_A1

static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;
static const uint8_t A4  = PIN_A4;
static const uint8_t A5  = PIN_A5;
static const uint8_t A6  = PIN_A6 ;
static const uint8_t A7  = PIN_A7 ;

static const uint8_t DAC0 = PIN_DAC0;
static const uint8_t DAC1 = PIN_DAC1;

#define ADC_RESOLUTION		12

// Other pins
#define PIN_ATN              (39ul)
static const uint8_t ATN = PIN_ATN;

/*
 * Serial interfaces
 */

// Serial1 (sercom0) [UART2]
#define PIN_SERIAL1_RX       (0ul)
#define PIN_SERIAL1_TX       (1ul)
#define PAD_SERIAL1_TX       (UART_TX_PAD_0)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_1)

/*
 * SPI iNTERFACES
 */
#define SPI_INTERFACES_COUNT 3

//*****RADIO SPI BUS******
#define PIN_SPI_MISO         (40u) // 39u en placa fabricada
#define PIN_SPI_MOSI         (21u)
#define PIN_SPI_SCK          (20u)
#define PIN_SPI_SS           (39u) // 40u en placa fabricada
#define PERIPH_SPI           sercom1
#define PAD_SPI_TX           SPI_PAD_0_SCK_1
#define PAD_SPI_RX           SERCOM_RX_PAD_3 //SERCOM_RX_PAD_2 en placa fabricada

static const uint8_t SS	  = PIN_SPI_SS ;	
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

//*****SD SPI BUS******
#define PIN_SPI2_MISO         (24u)
#define PIN_SPI2_MOSI         (26u)
#define PIN_SPI2_SCK          (25u)
#define PIN_SPI2_SS           (12u)
#define PERIPH_SPI2           sercom4
#define PAD_SPI2_TX           SPI_PAD_0_SCK_1
#define PAD_SPI2_RX           SERCOM_RX_PAD_2

static const uint8_t SS2	  = PIN_SPI_SS ;	
static const uint8_t MOSI2 = PIN_SPI_MOSI ;
static const uint8_t MISO2 = PIN_SPI_MISO ;
static const uint8_t SCK2  = PIN_SPI_SCK ;

// Needed for SD library
#define SDCARD_SPI          SPI2
#define SDCARD_MISO_PIN     PIN_SPI2_MISO
#define SDCARD_MOSI_PIN     PIN_SPI2_MOSI
#define SDCARD_SCK_PIN      PIN_SPI2_SCK
#define SDCARD_SS_PIN       PIN_SPI2_SS

//****FLASH SPI BUS****
#define PIN_SPI1_MISO       (32u)
#define PIN_SPI1_MOSI       (34u)
#define PIN_SPI1_SCK        (33u)
#define PIN_SPI1_SS         (10u)
#define PERIPH_SPI1         sercom2
#define PAD_SPI1_TX         SPI_PAD_0_SCK_1
#define PAD_SPI1_RX         SERCOM_RX_PAD_2

static const uint8_t SS1	 = PIN_SPI1_SS;
static const uint8_t MOSI1 = PIN_SPI1_MOSI;
static const uint8_t MISO1 = PIN_SPI1_MISO;
static const uint8_t SCK1  = PIN_SPI1_SCK;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (22u)
#define PIN_WIRE_SCL         (23u)
#define PERIPH_WIRE          sercom3
#define WIRE_IT_HANDLER      SERCOM3_Handler
#define WIRE_IT_HANDLER_0    SERCOM3_0_Handler
#define WIRE_IT_HANDLER_1    SERCOM3_1_Handler
#define WIRE_IT_HANDLER_2    SERCOM3_2_Handler
#define WIRE_IT_HANDLER_3    SERCOM3_3_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

/*
 * USB
 */
#define PIN_USB_HOST_ENABLE (29ul)
#define PIN_USB_DM          (30ul)
#define PIN_USB_DP          (31ul)

/*
 * I2S Interfaces
 */
#define I2S_INTERFACES_COUNT 0

//PCC Pins
#define PIN_PCC_DEN1    (PIN_SPI_MOSI)
#define PIN_PCC_DEN2    (PIN_SPI_SCK)
#define PIN_PCC_CLK     (PIN_SPI_MISO)
#define PIN_PCC_D0      (13u)
#define PIN_PCC_D1      (12u)
#define PIN_PCC_D2      (10u)
#define PIN_PCC_D3      (11u)
#define PIN_PCC_D4      (9u)
#define PIN_PCC_D5      (8u)
#define PIN_PCC_D6      (1u)
#define PIN_PCC_D7      (0u)
#define PIN_PCC_D8      (5u)
#define PIN_PCC_D9      (6u)

#if !defined(VARIANT_QSPI_BAUD_DEFAULT)
  // TODO: meaningful value for this
  #define VARIANT_QSPI_BAUD_DEFAULT 5000000
#endif

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart Serial1;

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      Serial
#define SERIAL_PORT_MONITOR         Serial
// Serial has no physical pins broken out, so it's not listed as HARDWARE port
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

#endif /* _VARIANT_METRO_M4_ */

