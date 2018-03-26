#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

// ------------------ EDIT mac --------------------------
byte mac[]    = { 0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
char server[] = "broker.mqttdashboard.com";

void callback(char* topic, byte* payload, unsigned int length) {
  String bufferMessage = "";
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
    bufferMessage += (char)payload[i];
  }
  Serial.println();
  
  // -------------using bufferMessage to implement ------------
}

EthernetClient ethClient;
PubSubClient client(ethClient);

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    //
    // ----------- EDIT arduinoClient ------------------------
    //
    if (client.connect("arduinoClient")) {
      Serial.println("connected");

      // -------------- publish here !!!! -----------
      client.publish("fat", "hello world");
      // -------------- publish here !!!! -----------


      // -------------- subscribe here !!!! -----------
      client.subscribe("fat");
      // -------------- subscribe here !!!! -----------

    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(57600);

  client.setServer(server, 1883);
  client.setCallback(callback);

  Ethernet.begin(mac);
  delay(1500);
}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

// ------------------ Addtional -------------------------
//  int val = analogRead(A0);
//  String val_str = String(val);
//  char val_char[10];
//  val_str.toCharArray(val_char, 10);
//  client.publish("fat", val_char);
  
}
