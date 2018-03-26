import paho.mqtt.client as mqtt

def on_connect(client, userdata, flags_dict, rc):
    print("Connected: " + str(rc))
    client.subscribe("hiwhiw")

def on_message(client, userdata, msg):
    print(msg.topic + ": " + str(msg.payload))

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("broker.mqttdashboard.com", 1883)
client.loop_forever()