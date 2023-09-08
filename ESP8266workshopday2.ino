#define BLYNK_TEMPLATE_ID "TMPL3DUNbGHVI"
#define BLYNK_TEMPLATE_NAME "DHT IoT Sensor"
#define BLYNK_AUTH_TOKEN "Ka5_xrssBc-MJTHs6K7XtYxM0qShPH5i"

#include <DHT.h>
#include<BlynkSimpleEsp8266.h>

#define DHTPIN 4  //Data pin is connected to D2  on ESP8266 (GPIO4)

#define DHTTYPE DHT11  //Name the sensor as an object

char auth[]= "Ka5_xrssBc-MJTHs6K7XtYxM0qShPH5i"; // Auth taken from blynk
char ssid[]= "OPPO F17";
char pass[]= "pranav2005";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Test successful");
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk connected successfully"); // println- \n which is to print in the next line
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h=dht.readHumidity(); // h Humidity
  float t=dht.readTemperature(); // t Temperature
  float f=dht.readTemperature(true);
  if(isnan(h) || isnan(t) || isnan(f)){
    Serial.println("Something is not working as intended");
    return; // void function
  }  // nan=not a number
  Serial.println("HUmidity: ");
  Serial.print(h);
  Serial.print("%");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("Degrees Celsius");
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  delay(1000); // before it was 2000
  }
