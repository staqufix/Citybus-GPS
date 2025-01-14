
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
 
// GPS

TinyGPSPlus gps;
 
void setup() {
  // Serieller Monitor

  Serial.begin(9600);

  Serial.println("GPS Tracker startet...");
 
  // GPS-Modul

  Serial1.begin(9600); // GPS auf Serial1

}
 
void loop() {

  // Überprüfe, ob Daten vom GPS-Modul verfügbar sind

  while (Serial1.available() > 0) {

    gps.encode(Serial1.read());

    if (gps.location.isUpdated()) {

      // GPS-Daten extrahieren

      double latitude = gps.location.lat();

      double longitude = gps.location.lng();
 
      // Ausgabe als lesbare Nachricht

      String message = "Position: https://maps.google.com/?q=" + String(latitude, 6) + "," + String(longitude);

      Serial.println(message);
 
      // JSON-Darstellung der GPS-Daten

      String json = "{";

      json += "\"latitude\": " + String(latitude, 6) + ",";

      json += "\"longitude\": " + String(longitude, 6);

      json += "}";
 
      Serial.println("JSON-Daten:");

      Serial.println(json);
 
      delay(10000); // Warte 10 Sekunden

    }

  }
 
  // Dummy-Daten senden (falls keine echten GPS-Daten verfügbar sind)

  // Hinweis: Dummy-Daten werden hier zur Demonstration verwendet.

  if (!gps.location.isValid()) {

    double dummyLatitude = 48.8566; // Beispielkoordinaten für Paris

    double dummyLongitude = 2.3522;
 
    Serial.print("Dummy-Daten - Latitude: ");

    Serial.print(dummyLatitude, 6);

    Serial.print(", Longitude: ");

    Serial.println(dummyLongitude, 6);
 
    delay(2000); // Warte 2 Sekunden

  }

}

 