
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x27,16,2);  

//GSM Module TX is connected to Arduino D8
#define PIR_SENSOR_1 7


//GSM Module RX is connected to Arduino D9
#define SIM800_RX_PIN 5
#define SIM800_TX_PIN 4

SoftwareSerial mySerial(SIM800_TX_PIN, SIM800_RX_PIN); //Create software serial object to communicate with GSM Module

int device_1 = 2; // attach pin D13 of Arduino to Device-1

// defines variables
int index = 0;
String number = "";
String message = "";

char incomingByte;
String incomingData;
bool atCommand = true;

void setup()
{
  Serial.begin(9600); // Serial Communication for Serial Monitor is starting with 9600 of baudrate speed
  mySerial.begin(9600); // Serial Communication for GSM Module is starting with 9600 of baudrate speed

  pinMode(device_1, OUTPUT);//set the device_1 as an OUTPUT
  pinMode(PIR_SENSOR_1, INPUT);//Sets the pir sensor as an INPUT
  pinMode(PIR_SENSOR_2, INPUT);//Sets the pir sensor as an INPUT
  pinMode(PIR_SENSOR_3, INPUT);//Sets the pir sensor as an INPUT

  digitalWrite(device_1, LOW); //Sets the device_1 in to OFF state at the beginning
   lcd.init();  //initialized LCD 
  lcd.clear();         
  lcd.backlight(); //turn on the backlight of the lcd

  // Check if you're currently connected to SIM800L
  while (!mySerial.available()) {
    mySerial.println("AT");
    delay(1000);
    Serial.println("connecting....");
    lcd.connecting...");setCursor(2,0); 
    lcd.print("connecting...");
  }

  Serial.println("Connected..");

  mySerial.println("AT+CMGF=1");  //Set SMS Text Mode
  delay(1000);
  mySerial.println("AT+CNMI=1,2,0,0,0");  //procedure, how to receive messages from the network
  delay(1000);
  mySerial.println("AT+CMGL=\"REC UNREAD\""); // Read unread messages

  Serial.println("Ready to received Commands..");
   for (int position = 0; position < 16; position++) {
    lcd.scrollDisplayLeft();
    delay(300);  // Adjust this delay to control scrolling speed
    lcd.setCursor(0,1); 
    lcd.print("Ready to received Commands..");
  }

}

void loop()
{
  if (mySerial.available()) {
    delay(100);
    // Serial buffer
    while (mySerial.available()) {
      incomingByte = mySerial.read();
      incomingData += incomingByte;
    }

    delay(10);
    if (atCommand == false) {
      receivedMessage(incomingData);
    } else {
      atCommand = false;
    }

    //delete messages to save memory
    if (incomingData.indexOf("OK") == -1) {
      mySerial.println("AT+CMGDA=\"DEL ALL\"");
      delay(1000);
      atCommand = true;
    }

    incomingData = "";
  }

}

void receivedMessage(String inputString) {


  //Get The number of the sender
  index = inputString.indexOf('"') + 1;
  inputString = inputString.substring(index);
  index = inputString.indexOf('"');
  number = inputString.substring(0, index);
  Serial.println("Number: " + number);
  lcd.clear();
  lcd.setCursor(2, 1);
  lcd.print( number);

  //Get The Message of the sender
  index = inputString.indexOf("\n") + 1;
  message = inputString.substring(index);
  message.trim();
  Serial.println("Message: " + message);
  message.toUpperCase(); // uppercase the message received


  //turn Device 1 ON
  if (message.indexOf("START") > -1 ) {
    digitalWrite(device_1, LOW);
    delay(1000);
    Serial.println("LIGHT ON");
    lcd.setCursor(3,0);
    lcd.print("LIGHT ON");
  }

  //turn Device 1 OFF
  if (message.indexOf("STOP") > -1 ) {
    digitalWrite(device_1, HIGH);
    Serial.println("LIGHT OFF");
    lcd.setCursor(3,0);
    lcd.print("LIGHT OFF ");
  }

  delay(10);// Added delay between two readings
}

void pir_sensor_message()
{
  int motion1 = digitalRead(PIR_SENSOR_1);// Declaring the the reading of the sensors
  int motion2 = digitalRead(PIR_SENSOR_2);
  int motion3 = digitalRead(PIR_SENSOR_3);

  if (motion1 == HIGH) {
        digitalWrite(device_1, LOW);
    Serial.println("Motion detected by sensor 1");
    // delay(200000);
    // Perform actions for sensor 1 motion detection
  }

   else if (motion2 == HIGH) {
    digitalWrite(device_1, LOW);
    Serial.println("Motion detected by sensor 2");
    // delay(200000);
    // Perform actions for sensor 2 motion detection
  }

  else if (motion3 == HIGH) {
    digitalWrite(device_1, LOW);
    Serial.println("Motion detected by sensor 3");
    // delay(200000);
    // Perform actions for sensor 3 motion detection
   }
   delay(1000);
}




