/*Modified by
 * ProfessorHulk and HACKITT from Smasher
 */
#define ledPin D7 
#define pirPin D6 // Input for HC-S501

#define MQ2pin (0)
#define BLYNK_PRINT Serial
#define buzzerPin 16 
#define DHTPIN 14 
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <BlynkSimpleEsp8266.h>]
#include <DHT.h>
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
char auth[] = "wKqP98rUsa--qZO-6XMHjvxy6W1whgNf";
char ssid[] = "Redmi Note 4";
char pass[] = "12345678";

float sensorValue,h,t;

int pirValue; // Place to store read PIR Value
int n,m;

void setup()
{

  Serial.begin(9600);
  Serial.println("Gas sensor warming up!");
  delay(5000);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  dht.begin();
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  pinMode(4,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  digitalWrite(ledPin, LOW);
  timer.setInterval(1000L, sendUptime);
}


void sendUptime()
{
  Blynk.virtualWrite(V1, n);  //V1 is for Gas
  Blynk.virtualWrite(V2, m);  //V2 is for Alcohol
  Blynk.virtualWrite(V5, h);  //V5 is for Humidity
  Blynk.virtualWrite(V6, t);  //V6 is for Temperature
}

void loop()
{
  sensorValue = analogRead(MQ2pin); // read analog input pin 0
  h = dht.readHumidity();
  t = dht.readTemperature(); 
  Serial.println("");
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.println("");
  if(sensorValue > 300 && sensorValue < 600)
  {
    Serial.print("Smoke detected!");
  }
  Serial.println("");
  delay(2000);
  if(sensorValue > 600)
  { 
    digitalWrite(4,LOW);
    digitalWrite(0,LOW);
    digitalWrite(5,HIGH);
    Serial.print("Alcohol detected!");
  }
  
  Serial.println("");
  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print("°C");
  Serial.println("");
  Serial.print("Humid: ");
  Serial.print(h);
  Serial.print("%");
  delay(2000);// wait 2s for next reading
  Blynk.run();
  timer.run();
  
  n=analogRead(A0);

  if(n>600)
  {
  
    n==m;
    m=analogRead(A0);
    Serial.println(m);
    
  }
  if(n>300 && n<600)
  {
    digitalWrite(4,LOW);
    digitalWrite(0,HIGH); 
    digitalWrite(5,LOW);
    tone(buzzerPin,800,80);
    delay(2000);  
  }
  
  if(n<300)
  {
      digitalWrite(4,HIGH);
      digitalWrite(0,LOW);
      digitalWrite(5,LOW);
      delay(2000);
      noTone(buzzerPin);
  }
 getPirValue();
  Blynk.run();
}

void getPirValue(void)
{
  pirValue = digitalRead(pirPin);
  if (pirValue) 
  { 
    Serial.println("==> Motion detected");
    Blynk.notify("T==> Motion detected");  
  }
  digitalWrite(ledPin, pirValue);
}
