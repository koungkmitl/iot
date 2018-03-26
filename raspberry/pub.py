import paho.mqtt.client as mqtt
import time

mqttc = mqtt.Client()
mqttc.connect('broker.mqttdashboard.com', 1883)

while True:
    mqttc.publish('hiw', 'Hello World')
    time.sleep(2)