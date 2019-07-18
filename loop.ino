void loop() {
    int cap_selecionada = 1;
    INICIALIZANDO_LCD();
    
    delay(100);
    unsigned time;
    
    INICIA_TXT_LCD();
    MOSTRA_OPCAO_CAPACITANCIA(cap_selecionada); // inicia com capacitância em 0,5*C
    
    
    while(1)
    {
      delay(2); //estabilização
      
      if(digitalRead(SETA_CIMA) == 0)// seta pra cima pressionada - aumenta 0,5*C a capacitância no LCD
      {
          if(cap_selecionada == 5)
          {
              cap_selecionada = 1;
          }else
          {
              cap_selecionada = cap_selecionada + 1;
          }
          
          MOSTRA_OPCAO_CAPACITANCIA(cap_selecionada);
          espera_tecla(); // debounce e espera soltar a tecla pra voltar a executar o programa
      }else if(digitalRead(SETA_BAIXO) == 0)// seta pra baixo pressionada - diminui 0,5*C a capacitÃ¢ncia no LCD
      { 
              
        if(cap_selecionada == 1)
        {
            cap_selecionada = 5;
        }else
        {
            cap_selecionada = cap_selecionada - 1;
        }
        MOSTRA_OPCAO_CAPACITANCIA(cap_selecionada);
        espera_tecla(); // debounce e espera soltar a tecla pra voltar a executar o programa
      }else if(digitalRead(ENTER) == 0)// tecla enter pressionado entrega na saída do circuito o valor de capacitância selecionado
      {
        SELECIONA_CAPACITANCIA(cap_selecionada);
        espera_tecla(); // debounce e espera soltar a tecla pra voltar a executar o programa
      }
    };

}
