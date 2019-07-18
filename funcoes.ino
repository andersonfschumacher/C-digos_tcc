/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
*                FUNÇÕES ORDINÁRIAS                  *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

//-------------- INÍCIO da função ESCREVE_8vias ---------------
void PULSE()
{
    digitalWrite(ENABLE, HIGH);
    delayMicroseconds(1);
    digitalWrite(ENABLE, LOW);
}
//-------------- FIM da função PULSE ------------------


//-------------- INÍCIO da função ESCREVE_8vias ---------------
void ESCREVE_8vias(int DADO)
{
    digitalWrite(LCD_D4, (DADO & 0b00010000));
    digitalWrite(LCD_D5, (DADO & 0b00100000));
    digitalWrite(LCD_D6, (DADO & 0b01000000));
    digitalWrite(LCD_D7, (DADO & 0b10000000));
    PULSE();
    delay(1);
}
//-------------- FIM da função ESCREVE_8vias ------------------

//-------------- INÍCIO da função ESCREVE_4vias ---------------
void ESCREVE_4vias(int DADO)
{
    //----- ENVIANDO A PARTE ALTA ---------
    int aux = (DADO & 0b11110000);
    
    aux = aux >> 4;
    digitalWrite(LCD_D4, (aux & 0b00000001));
    digitalWrite(LCD_D5, (aux & 0b00000010));
    digitalWrite(LCD_D6, (aux & 0b00000100));
    digitalWrite(LCD_D7, (aux & 0b00001000));
    PULSE();
    delay(1);
//----- PARTE ALTA ENVIADA ------------


//----- ENVIANDO A PARTE BAIXA --------
    aux = (DADO & 0b00001111);
    
    digitalWrite(LCD_D4, (aux & 0b00000001));
    digitalWrite(LCD_D5, (aux & 0b00000010));
    digitalWrite(LCD_D6, (aux & 0b00000100));
    digitalWrite(LCD_D7, (aux & 0b00001000));
    
    PULSE();
    delay(1);
//----- PARTE BAIXA ENVIADA ---------
}
//-------------- FIM da função ESCREVE_4vias ------------------


//-------------- INÍCIO da função INICIALIZANDO_LCD ---------------
void INICIALIZANDO_LCD()
{
// ---- * ----- * estabilização do display * ------ * ----- * ------
    delay(50);

    digitalWrite(RS, LOW);
    digitalWrite(ENABLE, LOW);

    ESCREVE_8vias(0x30);
    delay(5);

    ESCREVE_8vias(0x30);
    delayMicroseconds(200);

    ESCREVE_8vias(0x30);
    delayMicroseconds(80);

    ESCREVE_8vias(0x20);
    delayMicroseconds(80);
// ---- * ----- * estabilização do display * ------ * ----- * ------


    ESCREVE_4vias(0x28);  /*Estabelece as condições de utilização. Neste caso, comunicação em quatro
vias, display de duas linhas e matriz de 7x5.*/
    delayMicroseconds(80);
    
//**** a partir daqui o display está configurado para comunicação em 4 vias ****

    ESCREVE_4vias(0x08);
    delayMicroseconds(80);
    
    ESCREVE_4vias(0x01);  /*Comando para limpar o display e posicionar o cursor na primeira linha,
primeira coluna (esquerda).*/
    delay(4);

    ESCREVE_4vias(0x0C);/*comando para ligar o display sem cursor.*/
    delayMicroseconds(80);

   // ESCREVE_4vias(0x0C);;/*comando para ligar o display sem cursor.*/
    //delayMicroseconds(80);
    
    ESCREVE_4vias(0x06);/*comando para estabelecer o modo de entrada. Deslocamento automático do cursor para a direita.*/
    delay(20);
}
//-------------- FIM da função INICIALIZANDO_LCD ------------------

//-------------- INÍCIO da função espera_tecla -----------------
void espera_tecla()
{
    delay(40); // debounce

    while( (digitalRead(SETA_CIMA) == 0) || (digitalRead(SETA_BAIXO) == 0) ||
           (digitalRead(ENTER) == 0) )
    {

    };
    delay(40); // debounce
}
//-------------- FIM da função espera_tecla ---------------------
 
//-------------- INÍCIO da função INICIA_TXT_LCD -----------------
void INICIA_TXT_LCD()
{
  digitalWrite(RS, LOW);
  ESCREVE_4vias(0x01); // apaga todo o conteúdo no LCD, posiciona o cursor no início
  delay(20);
    
  digitalWrite(RS, HIGH); // para o LCD reconhecer como letras o código passado
  ESCREVE_4vias(' ');
  ESCREVE_4vias(' ');
  ESCREVE_4vias('C');
  ESCREVE_4vias('a');
  ESCREVE_4vias('p');
  ESCREVE_4vias('a');
  ESCREVE_4vias('c');
  ESCREVE_4vias('i');
  ESCREVE_4vias('t');
  ESCREVE_4vias('a');
  ESCREVE_4vias('n');
  ESCREVE_4vias('c');
  ESCREVE_4vias('i');
  ESCREVE_4vias('a');
}
//-------------- FIM da função INICIA_TXT_LCD --------------------

//-------------- INÍCIO da função MOSTRA_OPCAO_CAPACITANCIA -----------------
void MOSTRA_OPCAO_CAPACITANCIA(int cap_op)
{
  INICIA_TXT_LCD();
  
  digitalWrite(RS, LOW); 
  ESCREVE_4vias(0xC0); // posiciona cursor no início da segunda linha
  
  digitalWrite(RS, HIGH);
  if(cap_op == 1)
  {
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias('0');
      ESCREVE_4vias(',');
      ESCREVE_4vias('5');
      ESCREVE_4vias('0');
      ESCREVE_4vias('0');
      ESCREVE_4vias('x');
      ESCREVE_4vias('C');
  }else if(cap_op == 2)
  {
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias('1');
      ESCREVE_4vias(',');
      ESCREVE_4vias('0');
      ESCREVE_4vias('0');
      ESCREVE_4vias('0');
      ESCREVE_4vias('x');
      ESCREVE_4vias('C');
  }else if(cap_op == 3)
  {
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias('1');
      ESCREVE_4vias(',');
      ESCREVE_4vias('5');
      ESCREVE_4vias('0');
      ESCREVE_4vias('0');
      ESCREVE_4vias('x');
      ESCREVE_4vias('C');
  }else if(cap_op == 4)
  {
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias('2');
      ESCREVE_4vias(',');
      ESCREVE_4vias('0');
      ESCREVE_4vias('0');
      ESCREVE_4vias('0');
      ESCREVE_4vias('x');
      ESCREVE_4vias('C');
  }else if(cap_op == 5)
  { 
      digitalWrite(RS, LOW);
      ESCREVE_4vias(0x01); // apaga todo o conteúdo no LCD, posiciona o cursor no início
      delay(20);
      ESCREVE_4vias(0xC0); // posiciona cursor no início da segunda linha

      digitalWrite(RS, HIGH);
      
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias(' ');
      ESCREVE_4vias('A');
      ESCREVE_4vias('B');
      ESCREVE_4vias('E');
      ESCREVE_4vias('R');
      ESCREVE_4vias('T');
      ESCREVE_4vias('O');
  }
    
}
//-------------- FIM da função MOSTRA_OPCAO_CAPACITANCIA --------------------

//-------------- INÍCIO da função SELECIONA_CAPACITANCIA -----------------
void SELECIONA_CAPACITANCIA(int cap_op)
{
    // 0 -> rele ligado
    // 1 -> rele desligado
    if(cap_op == 1) // capacitância em 0,5*C
    {
        digitalWrite(RELE_A1, LOW); // somente A1 e A2 ligados
        digitalWrite(RELE_A2, LOW);
        digitalWrite(RELE_B1, HIGH);
        digitalWrite(RELE_B2, HIGH);
    }else if(cap_op == 2) // capacitância em 1,0*C
    {
        digitalWrite(RELE_A1, LOW); // somente A1 ligado
        digitalWrite(RELE_A2, HIGH);
        digitalWrite(RELE_B1, HIGH);
        digitalWrite(RELE_B2, HIGH);
    }else if(cap_op == 3) // capacitância em 1,5*C
    {
        digitalWrite(RELE_A1, LOW); // somente A1, B1 e B2 ligados
        digitalWrite(RELE_A2, HIGH);
        digitalWrite(RELE_B1, LOW);
        digitalWrite(RELE_B2, LOW);
    }else if(cap_op == 4) // capacitância em 2,0*C
    {
        digitalWrite(RELE_A1, LOW); // somente A1 e B1 ligados
        digitalWrite(RELE_A2, HIGH);
        digitalWrite(RELE_B1, LOW);
        digitalWrite(RELE_B2, HIGH);
    }else if(cap_op == 5) // circuito aberto
    {
        digitalWrite(RELE_A1, HIGH); // todos os relés desligados
        digitalWrite(RELE_A2, HIGH);
        digitalWrite(RELE_B1, HIGH);
        digitalWrite(RELE_B2, HIGH);
    }
}
//-------------- FIM da função SELECIONA_CAPACITANCIA --------------------
