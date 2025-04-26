#include <WiFi.h>
#include <HTTPClient.h>
//project by esc
// Discord webhook URL
const char* webhookUrl = "enter your discord webbhook";

// Ultrasonic sensor pins
const int trigPin = 5;
const int echoPin = 18;

// LED pin
const int ledPin = 2;

// WiFi credentials
const char* ssid = "enter wifi ssid";
const char* password = "enter wifi password";

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Send a trigger signal to the ultrasonic sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time it takes for the signal to bounce back
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;

  // Check if an obstacle is detected
  if (distance < 20) { // adjust this value to your needs
    // Send a Discord message
    sendDiscordMessage();
    // Light up the LED
    digitalWrite(ledPin, HIGH);
    delay(1000); // wait for 1 second
    digitalWrite(ledPin, LOW);
  }

  delay(50);
}

void sendDiscordMessage() {
  HTTPClient http;
  http.begin(webhookUrl);
  http.addHeader("Content-Type", "application/json");
  String jsonData = "{\"content\":\"Obstacle detected!\"}";
  int httpCode = http.POST(jsonData);
  if(httpCode == 200) {
    Serial.println("Discord message sent");
  } else {
    Serial.println("Error sending Discord message");
  }
  http.end();
}

