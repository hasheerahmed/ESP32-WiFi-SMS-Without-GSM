#include <WiFi.h>

#include <HTTPClient.h>

#include <ArduinoJson.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// TextBee API Info
const char* apiKey   = "YOUR_TEXTBEE_API_KEY";
const char* deviceID = "YOUR_DEVICE_ID";
const char* recipient = "+91XXXXXXXXXX";


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

  // Headers
  http.addHeader("Content-Type", "application/json");
  http.addHeader("x-api-key", apiKey);

  // JSON Body
  StaticJsonDocument<200> doc;

  JsonArray recipients = doc.createNestedArray("recipients");
  recipients.add(recipient);

  doc["message"] = message;

  String requestBody;
  serializeJson(doc, requestBody);

  // Send POST Request
  int httpCode = http.POST(requestBody);

  if (httpCode > 0) {

    Serial.println("SMS Sent Successfully!");
    Serial.println(http.getString());

  } else {

    Serial.print("SMS Failed. Error: ");
    Serial.println(httpCode);
  }

  http.end();
}
// ------------------------------------------------


void setup() {

  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
}


void loop() {

  // Nothing here
  // Call sendSMS() whenever you want in your project

}