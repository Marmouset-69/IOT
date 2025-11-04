/*
   ______               _                  _///  _           _                   _
  /   _  \             (_)                |  __\| |         | |                 (_)
  |  [_|  |__  ___  ___ _  ___  _ __      | |__ | | ___  ___| |_ _ __ ___  _ __  _  ___  _   _  ___
  |   ___/ _ \| __|| __| |/ _ \| '_ \_____|  __|| |/ _ \/  _|  _| '__/   \| '_ \| |/   \| | | |/ _ \
  |  |  | ( ) |__ ||__ | | ( ) | | | |____| |__ | |  __/| (_| |_| | | (_) | | | | | (_) | |_| |  __/
  \__|   \__,_|___||___|_|\___/|_| [_|    \____/|_|\___|\____\__\_|  \___/|_| |_|_|\__  |\__,_|\___|
                                                                                      | |
                                                                                      \_|
  Fichier:      NetworkNRF24L01-Arduino1
  Description:  Construction d'un réseau communicant, via des NRF24L01 connectés à des Arduino
  Auteur:       Passion-Électronique

  Librairie utilisée : https://github.com/nRF24/RF24
*/

// NOEUD 0 : HUB

#include <SPI.h>
#include <RF24.h>
#include <RF24Network.h>
#include <Servo.h>

#define pinCE     8         // On associe la broche "CE" du NRF24L01 à la sortie digitale D7 de l'arduino
#define pinCSN    7         // On associe la broche "CSN" du NRF24L01 à la sortie digitale D8 de l'arduino

RF24 radio(pinCE, pinCSN);    // Instanciation du NRF24L01
RF24Network network(radio);   // Nota : "Network" utilise la librairie "radio"

// Réseau
// const uint16_t noeud0 = 00;     // Valeur "0" écrite au format "octal" (d'où l'autre "0" devant)
// const uint16_t noeud1 = 01;     // Valeur "1" écrite au format "octal" (d'où l'autre "0" devant)
// const uint16_t noeud11 = 011;   // Valeur "11" écrite au format "octal" (d'où l'autre "0" devant)
// const uint16_t noeud12 = 012;   // Valeur "12" écrite au format "octal" (d'où l'autre "0" devant)
uint16_t current_node_number = 00;
uint16_t targetNode = 01;   // Ici, le noeud sera donc le "noeud0", et le noeud cible, le "noeud1"

char msg_received[20];
char msg_send[20];

bool waitingForACK = false;
unsigned long lastMessageTime = 0;
const unsigned long ACK_TIMEOUT = 10; // Temps d'attente de l'ACK en millisecondes


void setup() {
  Serial.begin(9600);
  Serial.println("Noeud 0 (HUB)");

  SPI.begin();
    
  radio.begin();                           // Initialisation du module NRF24
  radio.setPALevel(RF24_PA_MIN);           // Sélection d'un niveau "MINIMAL" pour communiquer (pas besoin d'une forte puissance, pour nos essais)
  radio.setDataRate(RF24_250KBPS);         // Vitesse : RF24_250KBPS, RF24_1MBPS, RF24_2MBPS
  network.begin(64, current_node_number);      // Canal 64 choisi arbitrairement (valeurs possibles : entre 0..125)
}

void send_ACK(uint16_t targetNode) {
  // Envoi d'un message ACK en réponse
  char ackMsg[20];
  sprintf(ackMsg, "ACK from %02o", current_node_number);
  RF24NetworkHeader nHeader(targetNode);
  network.write(nHeader, &ackMsg, sizeof(ackMsg));
  Serial.println("Sent ACK");
}

void send_message(const char* message, uint16_t targetNode) {
  RF24NetworkHeader nHeader(targetNode);
  network.write(nHeader, message, strlen(message));
  Serial.print("Send:");
  Serial.println(message);
  waitingForACK = true;
  lastMessageTime = millis();
  delay(5);
}

int i=0;
void loop() {
  network.update();
  
  // ******** RÉCEPTION ********
  while (network.available()) {                                           // Si une donné est en attente de lecture, on va la lire
    RF24NetworkHeader nHeader(current_node_number);
    network.read(nHeader, &msg_received, sizeof(msg_received));  // Lecture des données reçues, une par une

    Serial.print("Received:");
    Serial.println(msg_received);
  }
  delay(5);


  // ******** SEND ********
  sprintf(msg_send, "00 -> 0%o,%d,%d,%d", current_node_number, i, i, i++);
  send_message(msg_send, targetNode);

  // Wait for ack
  if (waitingForACK) {
    if (millis() - lastMessageTime > ACK_TIMEOUT) {
        Serial.println("ACK timeout, resending message");
        send_message(msg_send, targetNode);
    } else {
      while (network.available()) {
        RF24NetworkHeader nHeader(current_node_number);
        network.read(nHeader, &msg_received, sizeof(msg_received));
        Serial.print("Received:");
        Serial.println(msg_received);
        //send_ACK(nHeader.from_node);
    }
   }
    // if (!waitingForACK) {
    //   sprintf(msg_send, "00 -> 0%o,%d,%d,%d", current_node_number, random(0, 100), random(0, 100), random(0, 100));
    //   send_message(msg_send, targetNode);
    // }

  Serial.print("Send:");
  Serial.println(msg_send);
  delay(1000);
}}