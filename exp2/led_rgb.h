#ifndef LED_RGB_H_
#define LED_RGB_H_

/*! Habilita as portas do GPIO (Reg. SIM_SCGC5) */
#define SIM_SCGC5   (*(unsigned int *) 0x40048038)

/*! MUX do pino PTB18 (Reg. PORTB_PCR18) */
#define PORTB_PCR18 (*(unsigned int *) 0x4004A048)
/*! MUX do pino PTB18 (Reg. PORTB_PCR18) */
#define PORTB_PCR19 (*(unsigned int *) 0x4004A04C)
/*! MUX do pino PTD1 (Reg. PORTD_PCR1) */
#define PORTD_PCR1  (*(unsigned int *) 0x4004C004)

/*!  Dire&ccedil;&atilde;o dos dados nos pinos da porta PORTB (Reg. GPIOB_PDDR) */
#define GPIOB_PDDR  (*(unsigned int *) 0x400FF054)
/*!  Dire&ccedil;&atilde;o dos dados nos pinos da porta PORTD (Reg. GPIOD_PDDR) */
#define GPIOD_PDDR  (*(unsigned int *) 0x400FF0D4)

/*! Inverte o estado bit nos pinos da porta PORTB (Reg. GPIOB_PTOR) */
#define GPIOB_PTOR  (*(unsigned int *) 0x400FF04C)
/*! Inverte o estado bit nos pinos da porta PORTD (Reg. GPIOD_PTOR) */
#define GPIOD_PTOR  (*(unsigned int *) 0x400FF0CC)

/*! Seta o bit nos pinos da porta PORTB (Reg. GPIOB_PTOR) */
#define GPIOB_PSOR  (*(unsigned int *) 0x400FF044)
/*! Seta o bit nos pinos da porta PORTD (Reg. GPIOD_PTOR) */
#define GPIOD_PSOR  (*(unsigned int *) 0x400FF0C4)

/*! Limpa o bit nos pinos da porta PORTB (Reg. GPIOB_PCOR) */
#define GPIOB_PCOR  (*(unsigned int *) 0x400FF048)
/*! Limpa o bit nos pinos da porta PORTD (Reg. GPIOD_PCOR) */
#define GPIOD_PCOR  (*(unsigned int *) 0x400FF0C8)

/* Definição do bit correspondente ao pino do LED vermelho (bit 18 da porta B) */
#define LED_RED_PIN (1<<18)
/* Definição do bit correspondente ao pino do LED verde (bit 19 da porta B) */
#define LED_GREEN_PIN (1<<19)
/* Definição do bit correspondente ao pino do LED azul (bit 1 da porta D) */
#define LED_BLUE_PIN (1<<1)

/*!
 * @brief Estrutura que guarda as informa&ccedil;&otilde;es dos registradores que controlam cada cor do LED RGB
 */
typedef struct led {
    uint32_t psor;    /*!< Registrador PSOR (seta o bit) */
    uint32_t pcor;    /*!< Registrador PCOR (limpa o bit) */
    uint32_t ptor;    /*!< Registrador PTOR (inverte o bit) */
    uint32_t pin;     /*!< N&uacute;mero do pino dentro do registrador */
} led_t;

/*!
 * @brief Enumera&ccedil;&atilde;o das cores poss&iacute;veis do LED RGB
 */
typedef enum led_color {
    LED_RED = 0,
    LED_GREEN,
    LED_BLUE,
    MAX_LED_RGB
} led_color_t;

/*!
 * @brief Configura e inicializa apagada uma das cores do LED RGB (deve ser chamada uma vez antes das outras funções de controle do LED)
 * @param [in] color Cor do LED a ser inicializada
 */
void led_init( led_color_t color );

/*!
 * @brief Configura e inicializa apagada todas as cores do LED RGB (deve ser chamada uma vez antes das outras funções de controle do LED)
 */
void led_init_rgb( void );


/*!
 * @brief Acende uma das cores do LED RGB
 * @param [in] color Cor do LED a ser acesa
 */
void led_on( led_color_t color );

/*!
 * @brief Apaga uma das cores do LED RGB
 * @param [in] color Cor do LED a ser apagada
 */
void led_off( led_color_t color );

/*!
 * @brief Inverte o estado de uma das cores do LED RGB
 * @param [in] color Cor do LED a ser invertida
 */
void led_toggle( led_color_t color );

#endif
