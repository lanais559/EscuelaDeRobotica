// Esta aplicacion fue desarrollada por facilitadores de la Escuela de Robotica de Misiones - Argentina
//Participaron Sede Comandante Andresito - ElSoberbio - Campo Grande
//Programación: Añais Leandro Ismael  

// Conexion display 16x2 i2c
//vcc ==>>5v
//gnd ==>> gnd
//sda ==>> pin analogico A4
//scl ==>> pin analogico A5

// relay 5v a 220v
// vcc  5v arduino
// gnd  gnd arduino
// señalpin digital 4

//Sensor Ultrasónico:
//Trig Pin 3
//Echo  pin 2
//vcc  5v 
//gnd  gnd

#include <LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
// definimos los pins numbers
const int trigPin = 3;
const int echoPin = 2;
const int relayPin = 4;

const  int Buzzer=8;
int tiempo=0;
int distancia=0;
int contador=0;


// definimos variables
long duration;
int distance;
long distancemm;

void setup() {

///////codigo para mostrar el display/////////
Wire.begin();
lcd.begin(16,2);
lcd.backlight();
lcd.clear();
Serial.begin(9600);  

pinMode(trigPin, OUTPUT); // ponemos trigPin como Output
pinMode(echoPin, INPUT); // Ponemos echoPin como Input
pinMode(relayPin, OUTPUT);// Control Pin
pinMode(Buzzer, OUTPUT);// Control Pin 

}

void loop() {

// limpiamos trigPin
digitalWrite(Buzzer,HIGH);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// ponemos trigPin en HIGH por 10 micro segundos
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// leemos echoPin
duration = pulseIn(echoPin, HIGH);
// calculamos la distancia
distance= duration*0.034/2;
distancemm = distance*10+30;

//Control 
if (distancemm <= 1200)
{
 for (int i=0; i <= 50; i++){
      digitalWrite(relayPin, HIGH);
      digitalWrite(Buzzer,LOW);
      delay(100);
     
      
   }
   
}
else if (distancemm >= 121)
{
  digitalWrite(relayPin, LOW); 
}
else
{
  
}
if(digitalRead(relayPin)==HIGH)
{
  contador++;
  delay(100);
    
}

lcd.setCursor(0,0);
lcd.print("Personas ");
lcd.setCursor(0,1);
lcd.print("Desinf: ");
lcd.print(contador);
}
