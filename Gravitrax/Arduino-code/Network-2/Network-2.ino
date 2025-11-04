/*
   ______               _                  _///  _           _                   _
  /   _  \             (_)                |  __\| |         | |                 (_)
  |  [_|  |__  ___  ___ _  ___  _ __      | |__ | | ___  ___| |_ _ __ ___  _ __  _  ___  _   _  ___
  |   ___/ _ \| __|| __| |/ _ \| '_ \_____|  __|| |/ _ \/  _|  _| '__/   \| '_ \| |/   \| | | |/ _ \
  |  |  | ( ) |__ ||__ | | ( ) | | | |____| |__ | |  __/| (_| |_| | | (_) | | | | | (_) | |_| |  __/
  \__|   \__,_|___||___|_|\___/|_| [_|    \____/|_|\___|\____\__\_|  \___/|_| |_|_|\__  |\__,_|\___|
                                                                                      | |
                                                                                      \_|
  Fichier:      NetworkNRF24L01-Arduino2
  Description:  Construction d'un réseau communicant, via des NRF24L01 connectés à des Arduino
  Auteur:       Passion-Électronique

  Librairie utilisée : https://github.com/nRF24/RF24

  Créé le 21.03.2021
*/
#include <SPI.h>
#include <RF24.h>
#include <RF24Network.h>
#include <Servo.h>

#define pinCE     8         // On associe la broche "CE" du NRF24L01 à la sortie digitale D7 de l'arduino
#define pinCSN    7         // On associe la broche "CSN" du NRF24L01 à la sortie digitale D8 de l'arduino
#define pinSERVO  9         // On associe la broche "SIGNAL" du SERVO à la sortie digitale D9 de l'arduino
#define pinPOT    A0        // On associe le point milieu du potentiomètre à l'entrée analogique A0 de l'arduino

RF24 radio(pinCE, pinCSN);    // Instanciation du NRF24L01
RF24Network network(radio);   // Nota : "Network" utilise la librairie "radio"
Servo servomoteur;            // Instanciation d'un objet pour contrôler le servomoteur

// Réseau
// const uint16_t noeud0 = 00;     // Valeur "0" écrit au format "octal" (d'où l'autre "0" devant)
// const uint16_t noeud1 = 01;     // Valeur "1" écrit au format "octal" (d'où l'autre "0" devant)
// const uint16_t noeud11 = 011;   // Valeur "11" écrit au format "octal" (d'où l'autre "0" devant)
// const uint16_t noeud12 = 012;   // Valeur "12" écrit au format "octal" (d'où l'autre "0" devant)
uint16_t current_node_number = 01;
uint16_t targetNode = 00;   // Ici, le noeud sera donc le "noeud1", et le noeud cible, le "noeud0" (l'exact opposé de l'autre programme, en fait)

//unsigned long msg_received;     // Variable contenant la valeur de l'angle du servomoteur
//unsigned long msg_send;   // Variable contenant la valeur de l'angle du servomoteur
char msg_received[32];
char msg_send[32];

void setup() {
  Serial.begin(9600);
  Serial.println("Client 01");

  SPI.begin();
    
  radio.begin();                           // Initialisation du module NRF24
  radio.setPALevel(RF24_PA_MAX);           // Sélection d'un niveau "MINIMAL" pour communiquer (pas besoin d'une forte puissance, pour nos essais)
  radio.setDataRate(RF24_1MBPS);         // Vitesse : RF24_250KBPS, RF24_1MBPS, RF24_2MBPS
  network.begin(64, current_node_number);      // Canal 64 choisi arbitrairement (valeurs possibles : entre 0..125)
}
void loop() {
  network.update();
  
  // ******** RÉCEPTION ********
  bool is_msg=false;
  while (network.available()) {                                           // Si une donné est en attente de lecture, on va la lire
    RF24NetworkHeader nHeader(current_node_number);
    network.read(nHeader, &msg_received, sizeof(msg_received));  // Lecture des données reçues, une par une
    Serial.print("Received: ");
    Serial.println(msg_received);
    is_msg = true;
  }
  if(is_msg) { 
    sprintf(msg_send, "ACK");
    RF24NetworkHeader nHeader_target(targetNode);
    network.write(nHeader_target, &msg_send, sizeof(msg_send));  
    Serial.print("Send: ");
    Serial.println(msg_send);
    is_msg=false;
}
  delay(5);

  // ******** ENVOI ********
  // msg_send = i++;           // Léger arrondi, pour limiter les "tremblements" du servomoteur
  // RF24NetworkHeader nHeader(noeudCible);
  // network.write(nHeader, &msg_send, sizeof(msg_send));  // On envoi à l'autre carte la valeur de l'angle souhaité, pour son servomoteur
  // delay(5); 
  // delay(500);                                                              // avec une petite pause
  
  // Serial.print("Send:");
  // Serial.println(msg_send);
}