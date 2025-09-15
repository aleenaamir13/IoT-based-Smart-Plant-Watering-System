#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6T-GtCpDD"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "8IAgMavNf94hynQL81uz4hut8NmfzdJp"
#include <DHT11.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "8IAgMavNf94hynQL81uz4hut8NmfzdJp";  //Enter your Blynk Auth token
char ssid[] = "ABH-WiFi";  //Enter your WIFI SSID
char pass[] = "";  //Enter your WIFI Password

int dht_11= D1;
int soil = A0;
DHT11 dht11(dht_11); 
int relay = D3;
int relayState = LOW;
void setup()
{
   Serial.begin(9600);

  pinMode(relay, OUTPUT);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

}

BLYNK_WRITE(V0) {
  relayState = param.asInt();
  digitalWrite(relay, relayState);
}
BLYNK_CONNECTED() {
  // Request the latest state from the server
  Blynk.syncVirtual(V0);
}

void loop()
{
  Blynk.run();//Run the Blynk library

  float temp, humi;
  temp = dht11.readTemperature();
  humi = dht11.readHumidity();
  int moisture = analogRead(soil);

    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
    Serial.print("soil moisture: ");
    Serial.print(moisture);
    Blynk.virtualWrite(V1,temp);
    Blynk.virtualWrite(V2,humi);
    Blynk.virtualWrite(V3,moisture);
    if(humidity < 408){
      digitalWrite(relay,HIGH);
      delay(5000);
    }

}
