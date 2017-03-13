/*!
 * @file pisca_rgb.c
 * @brief Pisca-pisca de um led rgb na cor branca
 *
 * @mainpage Projeto de Pisca-Pisca RGB Branco
 * Projeto referente ao Roteiro 1 da disciplina EA871, baseado no modelo fornecido por Wu, Shin-Ting
 *
 * @author Henrique Aires Silva
 * @date 15/03/2017
 *
 */

/*! Habilita as portas do GPIO (Reg. SIM_SCGC5) */
#define SIM_SCGC5   (*(unsigned int volatile *) 0x40048038)

/*! MUX do pino PTB18 (Reg. PORTB_PCR18) */
#define PORTB_PCR18 (*(unsigned int volatile *) 0x4004A048)
/*! MUX do pino PTB18 (Reg. PORTB_PCR18) */
#define PORTB_PCR19 (*(unsigned int volatile *) 0x4004A04C)
/*! MUX do pino PTD1 (Reg. PORTD_PCR1) */
#define PORTD_PCR1 (*(unsigned int volatile *) 0x4004C004)

/*!  Dire&ccedil;&atilde;o dos dados nos pinos da porta PORTB (Reg. GPIOB_PDDR) */
#define GPIOB_PDDR  (*(unsigned int volatile *) 0x400FF054)
/*!  Dire&ccedil;&atilde;o dos dados nos pinos da porta PORTD (Reg. GPIOD_PDDR) */
#define GPIOD_PDDR  (*(unsigned int volatile *) 0x400FF0D4)

/*! Inverte o estado bit nos pinos da porta PORTB (Reg. GPIOB_PTOR) */
#define GPIOB_PTOR  (*(unsigned int volatile *) 0x400FF04C)
/*! Inverte o estado bit nos pinos da porta PORTD (Reg. GPIOD_PTOR) */
#define GPIOD_PTOR  (*(unsigned int volatile *) 0x400FF0CC)

/*! Seta o bit nos pinos da porta PORTB (Reg. GPIOB_PTOR) */
#define GPIOB_PSOR  (*(unsigned int volatile *) 0x400FF044)
/*! Seta o bit nos pinos da porta PORTD (Reg. GPIOD_PTOR) */
#define GPIOD_PSOR  (*(unsigned int volatile *) 0x400FF0C4)

/*!
 * @brief gera um atraso correspondente a i itera&ccedil;&otilde;es
 * @param i n&uacute;mero de itera&ccedil;&otilde;es
 */
void delay( unsigned int i)
{
    while (i) i--;        /*! Decrementa on&uacute;mero de itera&ccedil;&otilde;es at&eacute; zero */
}

/*!
 * @brief Led RGB na cor branca piscante
 * @return 1 somente para satisfazer a sintaxe C
 */
int main( void)
{
    SIM_SCGC5 |= ((1<<10) | (1<<12));    /*!  Habilita clock GPIO do PORTB (bit 10) e PORTD (bit 12) */

    PORTB_PCR18 &= 0xFFFFF8FF; /*! Zera bits 10, 9 e 8 (MUX) de PTB18 */
    PORTB_PCR18 |= 0x00000100; /*! Seta bit 8 do MUX de PTB18, assim os 3 bits de MUX ser&atilde;o 001 = fun&ccedil;&atilde;o GPIO */

    PORTB_PCR19 &= 0xFFFFF8FF; /*! Zera bits 10, 9 e 8 (MUX) de PTB19 */
    PORTB_PCR19 |= 0x00000100; /*! Seta bit 8 do MUX de PTB19, assim os 3 bits de MUX ser&atilde;o 001 = fun&ccedil;&atilde;o GPIO */

    PORTD_PCR1 &= 0xFFFFF8FF; /*! Zera bits 10, 9 e 8 (MUX) de PTD1 */
    PORTD_PCR1 |= 0x00000100; /*! Seta bit 8 do MUX de PTD1, assim os 3 bits de MUX ser&atilde;o 001 = fun&ccedil;&atilde;o GPIO */

    GPIOB_PDDR |= (1 << 18);    /*! Seta dire&ccedil;&atilde;o do pino 18 de PORTB como sa&iacute;da */
    GPIOB_PDDR |= (1 << 19);    /*! Seta dire&ccedil;&atilde;o do pino 19 de PORTB como sa&iacute;da */
    GPIOD_PDDR |= (1 << 1);    /*! Seta dire&ccedil;&atilde;o do pino 1 de PORTD como sa&iacute;da */

    /*! Inicializa os LEDs apagados (nível lógico 1) */
    GPIOB_PSOR = (1 << 18);
    GPIOB_PSOR = (1 << 19);
    GPIOD_PSOR = (1 << 1);

    /*!
     * La&ccedil;o para produzir efeito piscante
     */
    for(;;)
    {
        delay(500000);        /*! \li Espera um tempo */
        GPIOB_PTOR = (1<<18) | (1<<19); /*! \li Inverte bit 18 (LED vermelho) e bit 19 (LED verde) */
        GPIOD_PTOR = (1<<1);  /*! \li Inverte bit 1, LED azul em PTD1 */
    }
    return 1;
}
