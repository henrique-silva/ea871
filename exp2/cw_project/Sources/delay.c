/*!
 * @file delay.c
 * @brief Fun&ccedil;&otilde;es de delay por la&ccedil;o
 *
 * @author Henrique Aires Silva
 * @date 22/03/2017
 *
 */

#include "delay.h"

void delay( uint32_t ticks )
{
    /*! Decrementa on&uacute;mero de itera&ccedil;&otilde;es at&eacute; zero */
    while ( ticks ) {
	ticks--;
    }
}
