/**
 * @package Robo educacional autonomo
 * 
 *   Esamc - Engenharia da computação 6 semestre 
 *   Projeto Robotico Educacional - Trabalho de Sistema Embarcados
 *  
 *  
 *   Integrantes:
 *   Bruno Silva Carvalho
 *   Bruno Da Silva Lara
 *   Sergio Tadeu
 *   Kaique 
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
 
//Bibliotecas
#include <Ultrasonic.h>// Biblioteca do sensor Ultrasonico
#include <Wire.h> // Biblioteca do Módulo I2C
#include <LiquidCrystal_I2C.h>// Bilioteca do LCD

// Classes 
class Ultrasonico {
  
  //Atributos de definição dos pinos usados
  private:    
    int Tring; // Emitir(trig)
    int Echo; // Escutar (echo) 

  //Metodos
  public:
    void pinoSensor(int Emitir, int Escutar)
    {
      Tring = Emitir;
      Echo = Escutar;
    }
    
    float Centimetro(){
      Ultrasonic Sonar(Tring, Echo);//Acionando o sensor do pino emitir e escutar
      return (Sonar.convert(Sonar.timing(), Ultrasonic::CM));
    }
    
    float Polegadas(){
      Ultrasonic Sonar(Tring, Echo);// Acionando o sensor com os pinos emitir e escutar
      return (Sonar.convert(Sonar.timing(), Ultrasonic::IN));
    }
};

class Motor {
  
    // Atributos de definição do pinos usados
    private:
        int IN1;
        int IN2;
        int IN3;
        int IN4;

    //Metódos
    public:
        // Metódos usado para inicializar os pinos para o Driver Ponte H L298N
        void PinMotor(int motorA1,int motorA2,int motorB1,int motorB2)
        {
          IN1 = motorA1;
          IN2 = motorA2;
          IN3 = motorB1;
          IN4 = motorB2;
        }
        void inicializarMotores()
        {
            //Definindo os pinos como saida
            pinMode(IN1, OUTPUT);
            pinMode(IN2, OUTPUT);
            pinMode(IN3, OUTPUT);
            pinMode(IN4, OUTPUT);
        }

        /**
         * Metódos utilizados para controler dos motores 
         */
        void FrenteAmbos()
        {
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, LOW);
            delay(2000);
        }
        void ParaTrasAmbos()
        {
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, HIGH);
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, HIGH);
            delay(2000);
        }
        void PararAmbos()
        {
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, HIGH);
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, HIGH);
            delay(500);
        }
        //Movimentos do motor A
        void MotorA_Frente()
        {
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            delay(2000);
        }
        void MotorA_Parar()
        {
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, HIGH);
            delay(500);
        }
        void MotorA_ParaTras()
        {
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
            delay(2000);
        }

        //Movimentos do motor B
        void MotorB_Frente()
        {
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, LOW);
            delay(2000);
        }
        void MotorB_Parar()
        {
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, HIGH);
            delay(500);
        }
        void MotorB_ParaTras()
        {
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
            delay(2000);
        }
};

LiquidCrystal_I2C rosto(0x27,2,1,0,4,5,6,7,3, POSITIVE);
class lcd{

    //atributos
    private:
        byte Olhando_esquerda[8] = {B01110,B10011,B10111,B10111,B10111,B10111,B10011,B01110};
        byte Olhando_direita[8] = {B01110,B11001,B11101,B11101,B11101,B11101,B11001,B01110};
        byte BOCA[8] = {B00000,B00000,B00000,B00000,B11111,B11111,B00000,B00000};
        byte Acordado[8] = {B01110,B11001,B11101,B11111,B11111,B11111,B11111,B01110};
    //Metodos
    public:
        void inicializando()
        {
            rosto.begin(16,2);
            rosto.createChar(0, Acordado);// Definindo numero do byte
            rosto.createChar(1, BOCA);
            rosto.createChar(2, Olhando_esquerda);
            rosto.createChar(3, Olhando_direita);
            rosto.clear();  //Limpa o LCD
        }
        void Boca()
        {
            rosto.setCursor(5, 1); //Imprime parte da boca na posição 5 linha 1 do LCD
            rosto.write((byte)1);  //Objeto boca
            rosto.setCursor(6, 1); //Imprime parte da boca na posição 6 linha 1 do LCD
            rosto.write((byte)1);  //Objeto boca
            rosto.setCursor(7, 1); //Imprime parte da boca na posição 7 linha 1 do LCD
            rosto.write((byte)1);   //Objeto boca
            rosto.setCursor(8, 1); //Imprime parte da boca na posição 8 linha 1 do LCD
            rosto.write((byte)1);   //Objeto boca
            rosto.setCursor(9, 1);  //Imprime parte da boca na posição 9 linha 1 do LCD
            rosto.write((byte)1);   //Objeto boca
            rosto.setCursor(10, 1);  //Imprime parte da boca na posição 10 linha 1 do LCD
            rosto.write((byte)1);   //Objeto boca
        }
        void Olhar_Pensativo()
        {
            rosto.setCursor(3, 0);  //Imprime o olho na posição 3 linha 0 do LCD
            rosto.write((byte)1);   //Objeto olho
            rosto.setCursor(12, 0); //Imprime o olho na posição 12 linha 0 do LCD
            rosto.write((byte)1);   //Objeto olho
        }
        void Olhando_Esquerda()
        {
            rosto.setCursor(3, 0); //Imprime o olho na posição 12 linha 0 do LCD
            rosto.write((byte)2);   //Objeto olho
            rosto.setCursor(12, 0);  //Imprime o olho na posição 3 linha 0 do LCD
            rosto.write((byte)2);   //Objeto olho
        }
        void Olhando_Direita()
        {
            rosto.setCursor(3, 0); //Imprime o olho na posição 12 linha 0 do LCD
            rosto.write((byte)3);   //Objeto olho
            rosto.setCursor(12, 0);  //Imprime o olho na posição 3 linha 0 do LCD
            rosto.write((byte)3);   //Objeto olho
        }
        void VendoOsLados()
        {
            delay(500);
            rosto.setCursor(3, 0); //Imprime o olho na posição 12 linha 0 do LCD
            rosto.write((byte)2);   //Objeto olho
            rosto.setCursor(12, 0);  //Imprime o olho na posição 3 linha 0 do LCD
            rosto.write((byte)2);   //Objeto olho
            delay(1000);
            rosto.setCursor(3, 0); //Imprime o olho na posição 12 linha 0 do LCD
            rosto.write((byte)3);   //Objeto olho
            rosto.setCursor(12, 0);  //Imprime o olho na posição 3 linha 0 do LCD
            rosto.write((byte)3);   //Objeto olho
        }
        void Vendo()
        {
            rosto.setCursor(3, 0);  //Imprime o olho na posição 3 linha 0 do LCD
            rosto.write((byte)0);   //Objeto olho
            rosto.setCursor(12, 0); //Imprime o olho na posição 12 linha 0 do LCD
            rosto.write((byte)0);   //Objeto olho
        }
};

//Referênciando Classes

  Ultrasonico sensorFrontal;
  Ultrasonico sensorEsquerdo; 
  Ultrasonico sensorDireito;
  Motor partida;
  lcd expressao;

// Variavel Global

float ObstaculoDis = 2.50;//Variavel distancia limite

//Codigo Principal
void setup() {

    Serial.begin(9600);//Iniciando a leitura serial
    
    sensorFrontal.pinoSensor(4,5);//Sensor Fronta denifindo os pinos (tring,echo)
    sensorDireito.pinoSensor(6,7);//Sensor Esquerdo denifindo os pinos(tring,echo)
    sensorEsquerdo.pinoSensor(3,2);//Sensor Direito denifindo os pinos (tring,echo)
    
    partida.PinMotor(8,9,10,11);//Definindo Pinos do modulo ligado no motor
    partida.inicializarMotores();
    
    expressao.inicializando();//Ligando o lcd
    expressao.Boca();//Desenhando a boca

}

void loop() { 

  Serial.println(sensorFrontal.Centimetro());//Leitura da distancia
  if(sensorFrontal.Centimetro() > ObstaculoDis)
  {
    expressao.Vendo();//Rosto no lcd
    partida.FrenteAmbos();//Indo para a Frente
  }
  else 
  {
    partida.PararAmbos();//Parar motor
    expressao.VendoOsLados();//Rosto para olhar para os lados
    expressao.Olhar_Pensativo();//Expressao de pensativo
    if(sensorDireito.Centimetro() == sensorEsquerdo.Centimetro())
    {
        partida.ParaTrasAmbos();//Andando para trás
        expressao.Olhar_Pensativo();//Expressao de pensativo
        if(sensorDireito.Centimetro() == sensorEsquerdo.Centimetro())
        {
            //Girar 180 graus
            expressao.VendoOsLados();//Rosto para olhar para os lados
            partida.MotorA_Frente();
            partida.MotorB_ParaTras();
            delay(2000);
        }
        else if(sensorDireito.Centimetro()>sensorEsquerdo.Centimetro())
        {
            //Virar para a direita (90 graus)
            expressao.Olhando_Direita();
        }
        else
        {
            //Virar para a esquerda (-90 graus)
            expressao.Olhando_Esquerda();
        }
    }
    else if ( sensorEsquerdo.Centimetro()>sensorDireito.Centimetro() )
    {
        //Virar para a esquerda ( - 90 graus)
        expressao.Olhando_Esquerda();
    }
    else
    {
        //Virar para a direita (90 graus) 
        expressao.Olhando_Direita();
    }
  }
}
