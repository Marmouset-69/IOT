/*
   ______               _                  _///  _           _                   _
  /   _  \             (_)                |  __\| |         | |                 (_)
  |  [_|  |__  ___  ___ _  ___  _ __      | |__ | | ___  ___| |_ _ __ ___  _ __  _  ___  _   _  ___
  |   ___/ _ \| __|| __| |/ _ \| '_ \_____|  __|| |/ _ \/  _|  _| '__/   \| '_ \| |/   \| | | |/ _ \
  |  |  | ( ) |__ ||__ | | ( ) | | | |____| |__ | |  __/| (_| |_| | | (_) | | | | | (_) | |_| |  __/
  \__|   \__,_|___||___|_|\___/|_| [_|    \____/|_|\___|\____\__\_|  \___/|_| |_|_|\__  |\__,_|\___|
                                                                                      | |
                                                                                      \_|
  Fichier:      HelloWorldNRF24L01-Emetteur
  Description:  Emission d'un "Hello World" via un NRF24L01
  Auteur:       Passion-Électronique

  Librairie utilisée : https://github.com/nRF24/RF24

  Créé le 19.03.2021
*/

// 110 >>>>>>>>>>>
#include <SPI.h>
#include <RF24.h>

#define pinCE   8           // On associe la broche "CE" du NRF24L01 à la sortie digitale D7 de l'arduino
#define pinCSN  7             // On associe la broche "CSN" du NRF24L01 à la sortie digitale D8 de l'arduino
#define tunnel  "PIPE1"       // On définit un "nom de tunnel" (5 caractères), pour pouvoir communiquer d'un NRF24 à l'autre

RF24 radio(pinCE, pinCSN);    // Instanciation du NRF24L01

const byte adresse[6] = tunnel;               // Mise au format "byte array" du nom du tunnel
const char message[] = "Hello World !!!";     // Message à transmettre à l'autre NRF24 (32 caractères maxi, avec cette librairie)

#define LED_GREEN_PIN 6
#define LED_YELLOW_PIN 5

void setup() {
  Serial.begin(9600);

  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);

  for (int i=0; i < 5; i++) {
    digitalWrite(LED_GREEN_PIN, HIGH);
    delay(100);
    digitalWrite(LED_GREEN_PIN, LOW);

    digitalWrite(LED_YELLOW_PIN, HIGH);
    delay(100);
    digitalWrite(LED_YELLOW_PIN, LOW);
    Serial.println(i); 
  }
  digitalWrite(LED_GREEN_PIN, HIGH);
  
  radio.begin();                      // Initialisation du module NRF24
  radio.openWritingPipe(adresse);     // Ouverture du tunnel en ÉCRITURE, avec le "nom" qu'on lui a donné
  radio.setPALevel(RF24_PA_MIN);      // Sélection d'un niveau "MINIMAL" pour communiquer (pas besoin d'une forte puissance, pour nos essais)
  radio.stopListening();              // Arrêt de l'écoute du NRF24 (signifiant qu'on va émettre, et non recevoir, ici)
}

void loop() {
  radio.write(&message, sizeof(message));     // Envoi de notre message
  Serial.print(">>>>>>< send: ");
  Serial.println(message);
  //delay(50);                                // … toutes les secondes !
  digitalWrite(LED_YELLOW_PIN, LOW);
  delay(50);
  digitalWrite(LED_YELLOW_PIN, HIGH);
}