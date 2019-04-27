/**
* 
*   Esamc - Engenharia da computação 6 semestre 
*   Projeto Robotico Educacional - Trabalho de Sistema Embarcados
*  
*  
*   Integrantes:
*   Bruno Silva Carvalho
*   Bruno Da Silva Lara
*   Sergio Tadeu
*   
*
*   Objetivo do Projeto:
* 
*   Com intuito de estimular e interesar dos jovens na área de robotica e computacional 
*   o robo desenvolvido tem como funcionalidade, controle de entradas e saidas digitais 
*   e analogicas. Com (3) sensores ultrasonicos para verificar obstaculos em seu caminho, 
*   e analise logica possiveis decições de caminhos a serem redirecionadas
*   
*/

//Biblioteca
#include<Ultrasonic.h>

/*############################# Classes #########################################################*/

/* ------------------------------ Classe dos sensor ultrasonic ----------------------------------*/
class Ultrasonico{
  
  public:
  
    /*___________________________________ Atributos ______________________________________________*/
    
    long Emitir; // Emitir(trig)
    long Escutar; // Escutar (echo) 
    
    /*___________________________________ Metodos ________________________________________________*/
    
    // metodo de medir em centimetros
    long DistanciaCM(){
      Ultrasonic Sonar(Emitir, Escutar);//Acionando o sensor do pino emitir e escutar
      long dados = Sonar.timing();// Coleta dos dados do sensor
      return (Sonar.convert(dados, Ultrasonic::CM));
    }
    // metodo de medir em polegadas
    long DistanciaPOL(){
      Ultrasonic Sonar(Emitir, Escutar);// Acionando o sensor com os pinos emitir e escutar
      long dados = Sonar.timing();// Coleta dos dados do sensor
      return (Sonar.convert(dados, Ultrasonic::IN));
    }
};

/*################################# Código principal do arduino ###################################*/
void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}

void loop() {
  Ultrasonico sensor1; // Criando uma instancia
  sensor1.Emitir = 4; // Definindo pino que liga na entrada TRIG
  sensor1.Escutar = 5; // Definindo pino que liga na entrada ECHO
  Serial.print("Distancia em CM: ");
  Serial.print(sensor1.DistanciaCM());
  Serial.print("  Distancia em POL: ");
  Serial.println(sensor1.DistanciaPOL());
}
