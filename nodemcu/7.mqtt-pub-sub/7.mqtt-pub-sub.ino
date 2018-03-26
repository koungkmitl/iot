#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// -------------------------------- EDIT here -----------------------------
char* ssid = "hiwhiw";
char* password = "1212312121";
char* mqtt_server = "broker.mqttdashboard.com";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {

  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  String bufferMessage = "";
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    bufferMessage += (char)payload[i];
  }
  Serial.println();

}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    //
    // ------------------- EDIT clientId ---------------------
    //
    String clientId = "ESP8266Client-";
    
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");

      // ---------------- publish here --------------------
      client.publish("fat", "hello world");
      // ---------------- publish here --------------------


      // ---------------- subscribe here --------------------
      client.subscribe("fat");
      // ---------------- subscribe here --------------------
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

// ------------------ Addtional -------------------------
  int val = analogRead(A0);
  String val_str = String(val);
  char val_char[10];
  val_str.toCharArray(val_char, 10);
  client.publish("fat", val_char);

}
