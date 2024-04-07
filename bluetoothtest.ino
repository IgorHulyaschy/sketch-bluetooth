#include <SoftwareSerial.h>

SoftwareSerial HM10(3, 2); // RX = 2, TX = 3

char appData;  

String inData = "";

void setup() {
  Serial.begin(9600);
  HM10.begin(9600); // set HM10 serial at 9600 baud rate
  pinMode(7, OUTPUT); // onboard LED
  digitalWrite(7, LOW);
}


void loop() {
  HM10.listen();
  if (HM10.available()) {   // if HM10 sends something then read
    Serial.print("here");
    inData = HM10.readString();  // save the data in string format
    Serial.println(inData);
    
    if (inData == "F") {
      Serial.println("LED OFF");
      digitalWrite(7, LOW); // switch OFF LED
    }

    if(inData == "N") {
      Serial.println("LED ON");
      digitalWrite(7, HIGH); // switch ON LED
    }
  }

  if (Serial.available()) {           // Read user input if available.
    char userInput = Serial.read();
    HM10.write(userInput);
  }
}
