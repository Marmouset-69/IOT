# python 3.6


import random
import time
import serial
ser = serial.Serial('/dev/ttyUSB0', 9600)

from paho.mqtt import client as mqtt_client

broker = 'homeassistant.local'
port = 1883
# generate client ID with pub prefix randomly
client_id = f'RaspCuisine'
username = 'homeassistant'
password = 'weiyai1eFeidaeLithoom6go0OhThooz1IePhaiPh0thae5haephei5siele8aM2'

def connect_mqtt():
    def on_connect(client, userdata, flags, rc):
        if rc == 0:
            print("Connected to MQTT Broker!")
        else:
            print("Failed to connect, return code %d\n", rc)

    client = mqtt_client.Client(client_id)
    client.username_pw_set(username, password)
    client.on_connect = on_connect
    client.connect(broker, port)
    return client


def publish(client):
    while True:
        # Wait for a new line on the serial port
        # b'23;3;172;460;235\n'
        data = ser.readline()
        d=data.decode()
        dd = d.rstrip("\n")
        ddd=dd.split(';')

        # Decrypt received string
        count = ddd[0]
        id = ddd[1]
        temp = str(float(ddd[2]) / 10)
        lumi = ddd[3]
        humi = str(float(ddd[4]) / 10)
        print(f"\ncount `{count}`")
        print(f"id `{id}`")
        print(f"Temp `{temp}°C`")
        print(f"Lumi `{lumi}`")
        print(f"Humi `{humi}`")

        msg = '{"temperature": ' + temp + ',"humidite": ' + humi + ',"luminosity": ' + lumi + '}'
        #print (msg)

        topic = "NRF24/Unknow Sensor"
        # Submit the values to the correct topic
        if (id == "13"): # Cuisine
            topic = "NRF24/Cuisine_NRF24"
            print("--> Cuisine")
        elif (id == "1"): # Salle a manger
            topic = "NRF24/Salle_a_manger_NRF24"
            print("--> Salle a manger")
        elif (id == "2"): # Bureau
            topic = "NRF24/Bureau_NRF24"
            print("--> Bureau")
        elif (id == "3"): # Chambre parents
            topic = "NRF24/Chambre_parents_NRF24"
            print("--> Chambre parents")
        elif (id == "4"): # Garage
            topic = "NRF24/Garage_NRF24"
            print("--> Garage")
        elif (id == "5"): # Exterieur devant maison
            topic = "NRF24/Exterieur_NRF24"
            print("--> Exterieur devant maison")
        elif (id == "11"): # Salle de bain
            topic = "NRF24/Salle_de_bain_NRF24"
            print("--> Salle de bain")
        elif (id == "12"): # Vide sanitaire
            topic = "NRF24/Vide_sanitaire_NRF24"
            print("--> Vide sanitaire")
        elif (id == "19"): # Chambre Damien
            topic = "NRF24/Chambre_Damien_NRF24"
            print("--> Chambre Damien")
        elif (id == "27"): # Chambre Amelie
            topic = "NRF24/Chambre_Amelie_NRF24"
            print("--> Chambre Amelie")
        else:
            msg = '{"Unknow id": ' + id + ',"Unknow id": ' + id + ',"Unknow id": ' + id + '}'
            print("--> Unknow id")


        result = client.publish(topic, msg)
        # result: [0, 1]
        status = result[0]
        if status == 0:
            print(f"Send `{msg}` to topic `{topic}`")
        else:
            print(f"Failed to send message to topic {topic}")

def run():
    client = connect_mqtt()
    client.loop_start()
    publish(client)

if __name__ == '__main__':
    run()
