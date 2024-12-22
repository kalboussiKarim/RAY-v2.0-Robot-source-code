/*
  -----------------------------------------------------------------------------
  Projet : RocketBot 2.0 Competition
  Fichier : RAY v2.0
  -----------------------------------------------------------------------------
  Propriétaire : KALBOUSSI MOHAMED KARIM
  Créé le     : 10/11/2023
  Dernière modification : 23/12/2024
  -----------------------------------------------------------------------------
  Description :
  Ce code est conçu pour la carte ESP32 et sert à contrôler mon robot, RAY v2.0. 
  Ce robot participe à une compétition de football où le robot qui marque le plus 
  de buts remporte la partie.
  
  Licence :
  Licence MIT
  (c) 2023-2024 KALBOUSSI MOHAMED KARIM
  Permission est accordée, gratuitement, à toute personne obtenant une copie 
  de ce logiciel et des fichiers de documentation associés, 
  d'utiliser le Logiciel sans restriction, y compris sans limitation les droits 
  d'utiliser, copier, modifier, fusionner, publier, distribuer, sous-licencier, 
  et/ou vendre des copies du Logiciel, sous réserve des conditions suivantes :
  - La notice de copyright ci-dessus et cette permission doivent être incluses 
    dans toutes les copies ou portions substantielles de ce code.
  -----------------------------------------------------------------------------
*/

#include <Ps3Controller.h>
#include "secrets.h"


//Moteurs à droit
int enableRightMotor = 22; 
int rightMotorPin1 = 21;
int rightMotorPin2 = 19;
//Moteurs à gauche
int enableLeftMotor = 23;
int leftMotorPin1 = 18;
int leftMotorPin2 = 5;

//Frequence
const int PWMFreq = 1000;              // 1 KHZ

//résolution
const int PWMResolution = 8;           // 8 bits, 256 niveaux (allant de 0 à 255)


//PWMChannels choisir de 0 à 15 (16 chaines)
const int rightMotorPWMSpeedChannel = 14;


float steeringCoef;
int yAxisValue = 0;
int xAxisValue = 0;


void notify()
{
  //analogue gauche
  yAxisValue =(Ps3.data.analog.stick.ly);
  //Serial.println(yAxisValue);

  //analogue droite
  xAxisValue =(Ps3.data.analog.stick.rx);
  //Serial.println(xAxisValue);

  //obtention de données
  int throttle = map( yAxisValue, 127, -127, -255, 255);
  int steering = map( xAxisValue, -127, 127, -255, 255);
  steeringCoef = map( abs(throttle), 0, 255,6.5,10);

  //tratement de données
  int rightMotorSpeed, leftMotorSpeed;
  rightMotorSpeed =  throttle - ((int)(steering*steeringCoef/6.5));
  leftMotorSpeed =  throttle + ((int)(steering*steeringCoef/6.5));
  rightMotorSpeed = constrain(rightMotorSpeed, -255, 255);
  leftMotorSpeed = constrain(leftMotorSpeed, -255, 255);
  walkCar(rightMotorSpeed, leftMotorSpeed );

}

void onConnect()
{
  Serial.println("Connected.");
}

void onDisConnect()
{
  walkCar(0, 0);
  Serial.println("Disconnected.");    
}

void walkCar(int rightMotorSpeed, int leftMotorSpeed)
{
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);      
  }
  else
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);      
  }
  
  if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);    
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);      
  }
  else
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,LOW);      
  } 
  ledcWrite(rightMotorPWMSpeedChannel, abs(rightMotorSpeed));
  ledcWrite(leftMotorPWMSpeedChannel, abs(leftMotorSpeed)); 
}

void setUpPinModes()
{
  pinMode(enableRightMotor,OUTPUT);
  pinMode(rightMotorPin1,OUTPUT);
  pinMode(rightMotorPin2,OUTPUT);
  
  pinMode(enableLeftMotor,OUTPUT);
  pinMode(leftMotorPin1,OUTPUT);
  pinMode(leftMotorPin2,OUTPUT);

  ledcSetup(rightMotorPWMSpeedChannel, PWMFreq, PWMResolution);
  ledcSetup(leftMotorPWMSpeedChannel, PWMFreq, PWMResolution); 
 
  ledcAttachPin(enableRightMotor, rightMotorPWMSpeedChannel);
  ledcAttachPin(enableLeftMotor, leftMotorPWMSpeedChannel);
  
  walkCar(0, 0);
}


void setup()
{
  setUpPinModes();
  Serial.begin(115200);
  Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.attachOnDisconnect(onDisConnect);
  Ps3.begin(bluetooth);              // La valeur bluetooth provient du fichier secrets.h. Assurez-vous de la remplacer par l'adresse MAC de votre manette.
  Serial.println("Ready.");
}

void loop()
{
}
