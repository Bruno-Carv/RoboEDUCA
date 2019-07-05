/**
 *   @package RoboEDUCA (Robo educacional).
 *  
 *   Esamc - Engenharia da computação 6 semestre 
 *   Projeto Robotico Educacional - Trabalho de Sistema Embarcados
 *  
 *  
 *   Integrantes:
 *   Bruno Silva Carvalho
 *   Bruno Da Silva Lara
 *   Kaique Leal Santos
 *   Sergio Tadeu
 *    
 *
 *
 *   Objetivo do Projeto:
 * 
 *   Com intuito de estimular e interessar dos jovens na área de
 *   robótica e computacional o robô desenvolvido tem como funcionalidade, 
 *   controle de entradas e saídas digitais e analógicas. Com (3) sensores 
 *   ultrassónicos para verificar obstáculos em seu caminho, e analise 
 *   logica possíveis decisões de caminhos a serem redirecionadas
 *   
 */
 
//Bibliotecas

// Biblioteca do sensor Ultrassónico
#include <Ultrasonic.h>

// Biblioteca do Módulo I2C
#include <Wire.h>

// Biblioteca do LCD
#include <LiquidCrystal_I2C.h>



// Classes 
class Ultrasonico {
  
  //Atributos de definição dos pinos usados
  private:    
    int Tring; // Emitir(trig)
    int Echo; // Escutar (echo) 

  //Métodos
  public:
    void pinoSensor(int Emitir, int Escutar)
    {
      Tring = Emitir;
      Echo = Escutar;
    }
    
    float Centimetro(){
      //Acionando o sensor do pino emitir e escutar
      Ultrasonic Sonar(Tring, Echo);
      return (Sonar.convert(Sonar.timing(), Ultrasonic::CM));
    }
    
    float Polegadas(){
      // Acionando o sensor com os pinos emitir e escutar
      Ultrasonic Sonar(Tring, Echo);
      return (Sonar.convert(Sonar.timing(), Ultrasonic::IN));
    }
};


    /***
     * Classe do motor sendo definido 
     * 
     * Motor A - Direita
     * Motor B - Esquerda
     */ 

class Motor {


    // Atributos de definição dos pinos usados
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
         * Métodos utilizados para controle dos motores 
         */
        void FrenteAmbos()
        {
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, LOW);
        }
        void ParaTrasAmbos()
        {
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, HIGH);
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, HIGH);
        }
        void PararAmbos()
        {
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, HIGH);
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, HIGH);
        }


        //Movimentos do motor A
        void MotorA_Frente()
        {
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
        }
        void MotorA_Parar()
        {
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, HIGH);
        }
        void MotorA_ParaTras()
        {
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
        }


        //Movimentos do motor B
        void MotorB_Frente()
        {
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, LOW);
        }
        void MotorB_Parar()
        {
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, HIGH);
        }
        void MotorB_ParaTras()
        {
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
        }
};

LiquidCrystal_I2C rosto(0x27,2,1,0,4,5,6,7,3, POSITIVE);
class lcd{

    //atributos
    private:
        byte Olhando_esquerda[8] = 
        { 
          B01110,
          B10011,
          B10111,
          B10111,
          B10111,
          B10111,
          B10011,
          B01110
        };
        byte Olhando_direita[8] = 
        {
          B01110,
          B11001,
          B11101,
          B11101,
          B11101,
          B11101,
          B11001,
          B01110
        };
        byte BOCA[8] = 
        {
          B00000,
          B00000,
          B00000,
          B00000,
          B11111,
          B11111,
          B00000,
          B00000
        };
        byte Acordado[8] = 
        {
          B01110,
          B11001,
          B11101,
          B11111,
          B11111,
          B11111,
          B11111,
          B01110
        };
        
    //Metodos
    public:
        void inicializando()
        {
            // Iniciando o LCD
            rosto.begin(16,2);
            // Definindo numero do byte
            rosto.createChar(0, Acordado);
            rosto.createChar(1, BOCA);
            rosto.createChar(2, Olhando_esquerda);
            rosto.createChar(3, Olhando_direita);
            //Limpa o LCD
            rosto.clear();  
        }
        void Boca()
        {
            //Imprime parte da boca nas posições do (5 ao 10) linha 1 do LCD
            rosto.setCursor(5, 1);
            rosto.write((byte)1);
            rosto.setCursor(6, 1); 
            rosto.write((byte)1);
            rosto.setCursor(7, 1);
            rosto.write((byte)1);
            rosto.setCursor(8, 1);
            rosto.write((byte)1);
            rosto.setCursor(9, 1);
            rosto.write((byte)1);
            rosto.setCursor(10, 1);
            rosto.write((byte)1);
        }
        void Olhar_Pensativo()
        {
            //Imprime o olho na posição 3 e 12 linha 0 do LCD
            rosto.setCursor(3, 0);  
            rosto.write((byte)1);
            rosto.setCursor(12, 0);
            rosto.write((byte)1);
        }
        void Olhando_Esquerda()
        {
            //Imprime o olho na posição 12 linha 0 do LCD
            rosto.setCursor(3, 0); 
            rosto.write((byte)2);
            rosto.setCursor(12, 0);
            rosto.write((byte)2);
        }
        void Olhando_Direita()
        {
            //Imprime o olho na posição 12 linha 0 do LCD
            rosto.setCursor(3, 0);
            rosto.write((byte)3);
            rosto.setCursor(12, 0);
            rosto.write((byte)3);
        }
        void VendoOsLados()
        {
            delay(500);
            //Imprime o olho na posição 12 linha 0 do LCD
            rosto.setCursor(3, 0); 
            rosto.write((byte)2);   
            rosto.setCursor(12, 0); 
            rosto.write((byte)2);   
            delay(1000);
            //Imprime o olho na posição 12 linha 0 do LCD
            rosto.setCursor(3, 0); 
            rosto.write((byte)3);
            rosto.setCursor(12, 0); 
            rosto.write((byte)3);
        }
        void Vendo()
        {
            //Imprime o olho na posição 3 linhas 0 do LCD
            rosto.setCursor(3, 0);
            rosto.write((byte)0);
            rosto.setCursor(12, 0);
            rosto.write((byte)0);
        }
};

//Referênciando Classes

  Ultrasonico sensorFrontal;
  Ultrasonico sensorEsquerdo; 
  Ultrasonico sensorDireito;
  Motor partida;
  lcd expressao;

// Variavel Global

//Variavel distancia limite
float ObstaculoDis = 15;
long direita, esquerda;

//Codigo Principal
void setup() {

    //Iniciando a leitura serial
    Serial.begin(9600);


    //Sensor Fronta denifindo os pinos (tring,echo)
    sensorFrontal.pinoSensor(4,5);
    //Sensor Esquerdo denifindo os pinos(tring,echo)
    sensorDireito.pinoSensor(6,7);
    //Sensor Direito denifindo os pinos (tring,echo)
    sensorEsquerdo.pinoSensor(3,2);


    //Definindo Pinos do modulo ligado no motor
    partida.PinMotor(8,9,10,11);
    //Função de inicializar Motores
    partida.inicializarMotores();
    
    //Ligando o lcd
    expressao.inicializando();
    //Desenhando a boca
    expressao.Boca();

}

void loop() 
{ 
    if(sensorFrontal.Centimetro()>ObstaculoDis)
    {
        //Rosto olhando para frente
        expressao.Vendo();
        //Andar para frente
        partida.FrenteAmbos();
        delay(50);
        //Mostrando os dados
        Serial.print("Andando :");
        Serial.println(sensorFrontal.Centimetro());
    }
    else
    {
        //Parar
        partida.PararAmbos();
        expressao.Olhar_Pensativo();
        delay(400);
        //Mostrando os dados abaixo do frontal
        Serial.print("Parando :");
        Serial.println(sensorFrontal.Centimetro());
        //Mostrando os dados da direita
        expressao.Olhando_Direita();
        direita = sensorDireito.Centimetro();
        Serial.print("Direita :");
        Serial.println(sensorDireito.Centimetro());
        //Mostrando os dados da esquerda
        expressao.Olhando_Esquerda();
        esquerda = sensorEsquerdo.Centimetro();
        Serial.print("Esquerda :");
        Serial.println(sensorEsquerdo.Centimetro());
        expressao.Olhar_Pensativo();
        //Estrutura de decição
        if(direita > esquerda)
        {
            //Virando para direita
            partida.MotorA_ParaTras();
            partida.MotorB_Frente();
            expressao.Olhando_Direita();
            delay(700);
        }
        else if( esquerda == direita)
        {
            //Para trás
            expressao.VendoOsLados();
            partida.ParaTrasAmbos();
            delay(200);
            //Virando 180 graus
            partida.MotorA_Frente();
            partida.MotorB_ParaTras();
            expressao.Olhando_Esquerda();
            delay(350);
            //Ir para frente
            partida.FrenteAmbos();
            expressao.Vendo();
            delay(100);
        }
        else
        {
            //Virando para esquerda
            partida.MotorA_Frente();
            partida.MotorB_ParaTras();
            expressao.Olhando_Esquerda();
            delay(700);
        }
    }
}
