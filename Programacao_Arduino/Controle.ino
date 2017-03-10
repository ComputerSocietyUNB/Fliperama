#include <Controle.h>
#include <HID.h>
#include <Mouse.h>
#include <Platform.h>
#include <Keyboard.h>
#include <HID_Reports.h>
#include <Gamepad.h>
#include <Media.h>
#include <System.h>
#include <RawHID.h>


#define pressionado LOW
/* Objetivos do codigo:
* Mapear entradas (analogicas e digitais) do arduino para botoes de um controle de playstation 1
* Fazer com que ao se apertar um botao do fliperama, o correspondente botao do emulador seja pressionado no teclado 
*/

// Feito por Pedro Aurelio e testado no Windows 10 e a versao mais recenete em Ubuntu 16.04 

/*Inicio da definicao das funcoes a serem utilizadas para o controle
  *
  */
  void configura_controle (Mapeamento_jogo*,int);// o inteiro eh pra saber se o controle eh do jogador 1 ou 2
  void mapeia_entradas_arduino(Mapeamento_jogo*);
  void procura_por_tecla_pressionada (Mapeamento_jogo);
  
 /*Fim da definicao das funcoes a serem utilizadas para o controle
 */

Mapeamento_jogo Controle;

void setup() {
  configura_controle(&Controle,2);//para mudar para jogador 2, substitua o 1 por 2 
  Serial.begin(SERIAL_HID_BAUD);
 /* Para ligar a comunicacao usb do arduino no Ubuntu 16.04, evitando a funcao autosuspend:
  *    Carregue este codigo;
  *    Apos o carregamento ser completado, abra o monitor serial (Ctrl + Shift + m)
  *    Mude a selecao "9600 baud" para "115200"
  *    Feche o monitor serial  e o arduino devera executar o programa normalmente
  */ 
  Serial.println("Configuracao comunicacao usb");//colocar uma comunicacao com a porta serial impede o ubuntu de suspender automaticamente o dispositvo (se nao der certo de primeira, tente abrir o monitor serial e configurar a taxa para 11520)
  Keyboard.begin();

}

void loop() {
  procura_por_tecla_pressionada(Controle);
}
void configura_controle(Mapeamento_jogo* Controle, int jogador){
  int entrada;
  mapeia_entradas_arduino(Controle);
  // Incio da configuracao das entradas do arduino para serem portas de leitura
  for(entrada = 2;entrada<=12;entrada++){
      pinMode(entrada, INPUT_PULLUP);
  }
  pinMode(A0,INPUT_PULLUP);
  pinMode(A1,INPUT_PULLUP);
  pinMode(A2,INPUT_PULLUP);
  pinMode(A3,INPUT_PULLUP);
  // Fim da configuracao das entradas do arduino para serem portas de leitura
  /*Incio do mapeamento dos botoes do controle para teclas
   *
   *
   */
    if(jogador == 1){
          Controle->tecla_tri= 't';
          Controle->tecla_x= 'g';
          Controle->tecla_quad= 'f';
          Controle->tecla_bol= 'h';
          Controle->tecla_r1= '0';
          Controle->tecla_l1= '1';
          Controle->tecla_l2= '2';
          Controle->tecla_r2= '9';
          Controle->tecla_start= KEY_LEFT_ALT;
          Controle->tecla_select= (char) 10;// enter
          Controle->tecla_cima ='w' ;
          Controle->tecla_esq ='a';
          Controle->tecla_baixo ='s';
          Controle->tecla_dir ='d';
    }else{
        Controle->tecla_tri= 'e';
          Controle->tecla_x= 'u';
          Controle->tecla_quad= 'i';
          Controle->tecla_bol= 'o';
          Controle->tecla_r1= '3';
          Controle->tecla_l1= '4';
          Controle->tecla_l2= '5';
          Controle->tecla_r2= '6';
          Controle->tecla_start= '7';
          Controle->tecla_select= '8';// enter
          Controle->tecla_cima ='b' ;
          Controle->tecla_esq ='c';
          Controle->tecla_baixo ='v';
          Controle->tecla_dir ='k';
    }
   /*Fim do mapeamento dos botoes do controle para teclas
   *
   */

}
void mapeia_entradas_arduino(Mapeamento_jogo* Controle){
   /*Incio do mapeamento das entradas do arduino para os botoes do controle
   */
    Controle->triangulo = 2;
    Controle->x = 3;
    Controle->quadrado = 4;
    Controle->bola = 5;
    Controle->r1= 6;
    Controle->l1= 7;
    Controle->l2= 8;
    Controle->r2= 9;
    Controle->start= 10;
    Controle->select   = 11;
    Controle->cima = A0;
    Controle->esq = A1;
    Controle->dir = A2;
    Controle->baixo = A3;
  /*Fim do mapeamento das entradas do arduino para os botoes do controle
   */
}
 void procura_por_tecla_pressionada (Mapeamento_jogo Controle){
  // nao ha eslse ifs pois 2 btotoes podem ser pressionados ao mesmo tempo

    if(digitalRead(Controle.triangulo) == pressionado){
      Keyboard.press(Controle.tecla_tri);
    }
       if(digitalRead(Controle.x) == pressionado){
      Keyboard.press(Controle.tecla_x);
    }
      if(digitalRead(Controle.quadrado) == pressionado){
      Keyboard.press(Controle.tecla_quad);
    }
      if(digitalRead(Controle.bola) == pressionado){
      Keyboard.press(Controle.tecla_bol);
    }
      if(digitalRead(Controle.r1) == pressionado){
      Keyboard.press(Controle.tecla_r1);
    }
      if(digitalRead(Controle.l1) == pressionado){
      Keyboard.press(Controle.tecla_l1);
    }
      if(digitalRead(Controle.l2) == pressionado){
      Keyboard.press(Controle.tecla_l2);
    }
      if(digitalRead(Controle.r2) == pressionado){
      Keyboard.press(Controle.tecla_r2);
    }
      if(digitalRead(Controle.start) == pressionado){
      Keyboard.press(Controle.tecla_start);
    }
      if(digitalRead(Controle.select) == pressionado){
      Keyboard.press(Controle.tecla_select);
    }

      if(analogRead(Controle.cima) <= 500){
      Keyboard.press(Controle.tecla_cima);
    }

      if(analogRead(Controle.esq) <= 500){
     Keyboard.press(Controle.tecla_esq);
    }
      if(analogRead(Controle.baixo) <= 500){
      Keyboard.press(Controle.tecla_baixo);
    }
       if(analogRead(Controle.dir) <= 500){
      Keyboard.press(Controle.tecla_dir);
    }

    //
    delay(100);
    Keyboard.releaseAll();
     delay(100);

 }
