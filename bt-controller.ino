#include "BluetoothSerial.h"
#define led 27


BluetoothSerial serialBT;
char cmd;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  serialBT.begin("Esp32-BT2");
  pinMode(led,OUTPUT);

  // Initialize Bluetooth with a custom name
  if (!serialBT.begin("Esp32-BT2")) {
    Serial.println("An error occurred initializing Bluetooth");
  } else {
    Serial.println("Bluetooth initialized successfully");
  }

  String btAddress = serialBT.getBtAddressString();
    Serial.print("Bluetooth MAC Address: ");
    Serial.println(btAddress);

}

void fastBlink(){
  digitalWrite(led,HIGH);
  delay(100);
  digitalWrite(led,LOW);
  delay(100);
}

void slowBlink(){
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(led,LOW);
  delay(1000);
}

void loop() {
  // Variable to store the received command

  // Check if there is data available from the Bluetooth connection
  if (serialBT.available()) {
    cmd = serialBT.read();
    Serial.println(cmd);
  }

  // Use a switch-case structure to handle different commands
  switch (cmd) {
    case 'F':  // Command
      fastBlink();
      break;

    case 'B':  // Command
      slowBlink();
      break;

    default:  // Default case if an unknown command is received
      // No action or add some debugging message if needed
      break;
  }

  delay(10);  // Small delay to avoid overwhelming the loop
}
