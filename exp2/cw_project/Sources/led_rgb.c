/*!
 * @file led_rgb.c
 * @brief M&oacute;dulo de controle do LED RGB
 *
 * @author Henrique Aires Silva
 * @date 22/03/2017
 *
 */

#include "led_rgb.h"

led_t led_rgb[3] = {
    [LED_RED] = {
	.psor = GPIOB_PSOR,
	.pcor = GPIOB_PCOR,
	.ptor = GPIOB_PTOR,
	.pin = LED_RED_PIN
    },
    [LED_GREEN] = {
	.psor = GPIOB_PSOR,
	.pcor = GPIOB_PCOR,
	.ptor = GPIOB_PTOR,
	.pin = LED_GREEN_PIN
    },
    [LED_BLUE] = {
	.psor = GPIOD_PSOR,
	.pcor = GPIOD_PCOR,
	.ptor = GPIOD_PTOR,
	.pin = LED_BLUE_PIN
    }
};

void led_on( led_color_t color )
{
    *(led_rgb[color].pcor) = led_rgb[color].pin;
}

void led_off( led_color_t color )
{
    *(led_rgb[color].psor) = led_rgb[color].pin;
}

void led_toggle( led_color_t color )
{
    *(led_rgb[color].ptor) = led_rgb[color].pin;
}

void led_init( led_color_t color )
{
    switch (color) {

    case LED_RED:
	SIM_SCGC5 |= ( 1 << 10 ); /*!  Habilita clock GPIO do PORTB (bit 10) */
	PORTB_PCR18 &= 0xFFFFF8FF; /*! Zera bits 10, 9 e 8 (MUX) de PTB18 */
	PORTB_PCR18 |= 0x00000100; /*! Seta bit 8 do MUX de PTB18, assim os 3 bits de MUX ser&atilde;o 001 = fun&ccedil;&atilde;o GPIO */
	GPIOB_PDDR |= (LED_RED_PIN);    /*! Seta dire&ccedil;&atilde;o do pino 18 de PORTB como sa&iacute;da */
	break;

    case LED_GREEN:
	SIM_SCGC5 |= ( 1 << 10 ); /*!  Habilita clock GPIO do PORTB (bit 10) */
	PORTB_PCR19 &= 0xFFFFF8FF; /*! Zera bits 10, 9 e 8 (MUX) de PTB19 */
	PORTB_PCR19 |= 0x00000100; /*! Seta bit 8 do MUX de PTB19, assim os 3 bits de MUX ser&atilde;o 001 = fun&ccedil;&atilde;o GPIO */
	GPIOB_PDDR |= (LED_GREEN_PIN);    /*! Seta dire&ccedil;&atilde;o do pino 19 de PORTB como sa&iacute;da */
	break;

    case LED_BLUE:
	SIM_SCGC5 |= ( 1 << 12 ); /*!  Habilita clock GPIO do PORTD (bit 12) */
	PORTD_PCR1 &= 0xFFFFF8FF; /*! Zera bits 10, 9 e 8 (MUX) de PTD1 */
	PORTD_PCR1 |= 0x00000100; /*! Seta bit 8 do MUX de PTD1, assim os 3 bits de MUX ser&atilde;o 001 = fun&ccedil;&atilde;o GPIO */
	GPIOD_PDDR |= (LED_BLUE_PIN);    /*! Seta dire&ccedil;&atilde;o do pino 1 de PORTD como sa&iacute;da */
	break;

    default:
	return;
    }

    /*! Inicializa o LED apagado (n&iacute;vel l&oacute;gico 1) */
    led_off(color);
}

void led_init_rgb( void )
{
    uint8_t led_count;
	for( led_count = 0; led_count < MAX_LED_RGB ; led_count++) {
        led_init( led_count );
    }
}
