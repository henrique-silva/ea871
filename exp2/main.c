/*!
 * @file main.c
 * @brief Pisca-pisca de um led rgb na cor branca com codigo modular
 *
 * @mainpage Projeto de Pisca-Pisca RGB Branco com codigo modular
 * Projeto referente ao Roteiro 2 da disciplina EA871, baseado no modelo fornecido por Wu, Shin-Ting
 *
 * @author Henrique Aires Silva
 * @date 22/03/2017
 *
 */

/* */
#include "led_rgb.h"
#include "delay.h"

/*!
 * @brief Led RGB na cor branca piscante
 * @return 1 somente para satisfazer a sintaxe C
 */
int main( void )
{

    /*! Inicializa os pinos dos LEDs RGB e apaga todos */
    led_init_rgb();

    /*!
     * La&ccedil;o para produzir efeito piscante
     */
    for(;;)
    {
        delay( 500000 );        /*! \li Espera um tempo */
        /*! Inverte o estado dos bits do LED RGB */
        led_toggle( LED_RED );
        led_toggle( LED_GREEN );
        led_toggle( LED_BLUE );
    }

    return 1;
}
