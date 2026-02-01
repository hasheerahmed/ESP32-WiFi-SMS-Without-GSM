#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <DHT.h>

// ---------------- WIFI ----------------
const char* ssid = "Hasheer's M35";
const char* password = "123456789";

// ---------------- TEXTBEE ----------------
const char* apiKey   = "458bf3d6-1387-41d5-bc63-6c9b66b491b5";
const char* deviceID = "697dd4b538c16aebc78ec89f";
const char* recipient = "+918867621615";

// ---------------- DHT ----------------
#define DHTPIN 4        // GPIO where DHT22 is connected
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// ---------------- SETTINGS ----------------
float tempLimit = 27.0;     // Alert limit
bool alertSent = false;     // Prevent multiple SMS

// ---------------- SMS FUNCTION ----------------
void sendSMS(String message) {

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi not connected!");
    return;
  }

  HTTPClient http;

  String url = "https://api.textbee.dev/api/v1/gateway/devices/" +
               String(deviceID) + "/send-sms";

  http.begin(url);

  http.addHeader("Content-Type", "application/json");
  http.addHeader("x-api-key", apiKey);

  StaticJsonDocument<200> doc;

  JsonArray recipients = doc.createNestedArray("recipients");
  recipients.add(recipient);

  doc["message"] = message;

  String requestBody;
  serializeJson(doc, requestBody);

  int httpCode = http.POST(requestBody);

  if (httpCode > 0) {
    Serial.println("SMS Sent Successfully!");
    Serial.println(http.getString());
  } 
  else {
    Serial.print("SMS Failed. Error: ");
    Serial.println(httpCode);
  }

  http.end();
}

// ------------------------------------------------

void setup() {

  Serial.begin(115200);

  // Start DHT
  dht.begin();

  // Connect WiFi
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
}

// ------------------------------------------------

void loop() {

  float temperature = dht.readTemperature(); // Celsius

  // Check if reading failed
  if (isnan(temperature)) {
    Serial.println("Failed to read DHT!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // -------- ALERT CONDITION --------
  if (temperature > tempLimit && !alertSent) {

    String msg = "ALERT! Temperature crossed 27C.\nCurrent Temp: ";
    msg += String(temperature);
    msg += " C";

    sendSMS(msg);

    alertSent = true;   // Stop repeated SMS
  }

  // Reset alert if temperature drops back
  if (temperature <= tempLimit) {
    alertSent = false;
  }

  delay(5000); // Check every 5 seconds
}
