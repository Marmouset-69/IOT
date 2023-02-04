# python 3.6

# See https://www.emqx.com/en/blog/how-to-use-mqtt-in-python

import random
import time

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
        time.sleep(1)
        # {"Temperature":11.44751815947774,"Humidite":85.19176787958504"}"

        ## Cuisine
        topic = "NRF24/Cuisine"
        temp = random.uniform(10.0, 20.0)
        humi = random.uniform(80.0, 99.0)
        msg = '{"temperature": ' + str(temp) + ',"humidite": ' + str(humi) + '}'
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
