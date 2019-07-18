/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
*                           ENTRADAS                              *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

// botões conectados aos bits 0, 1 e 2 da PORTB
#define SETA_CIMA   2
#define SETA_BAIXO  3
#define ENTER       4


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
*                           SAÍDAS                                *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

// barramento de dados do LCD conectado à PORTD
#define LCD_D4 13 // d4
#define LCD_D5 12 // d5
#define LCD_D6 11 // d6
#define LCD_D7 10 // d7

#define RS          A1  /* INDICA P/ O DISPLAY UM DADO OU COMANDO
                            1 -> DADO
                            0 -> COMANDO            */
#define ENABLE      A0   /* SINAL DE ENABLE P/ DISPLAY
                         ATIVO NA BORDA DE DESCIDA */
                         
// Relés conectados aos bits 0,1,2 e 3 da PORTA
#define RELE_A1     6 //
#define RELE_A2     7
#define RELE_B1     8
#define RELE_B2     9
