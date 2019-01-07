#include <SPI.h>
#include <WiFi101.h>
#include <WiFiUdp.h>

int led =13;//the led pin
char input;// to save the input
int button1 = 9;
int button2 = 6;
char sosc[4];
char helpc[5];

///////please enter your sensitive data in the Secret tab/arduino_secrets.h

char ssid[] = "vaughns laptop";        // your network SSID (name)
char pass[] = "vaughn14";    // your network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS;     // the WiFi radio's status

unsigned int localPort = 8080;
IPAddress boardIp(192, 168, 137, 233);
unsigned int remotePort = 7171;
WiFiUDP Udp;

char packetBuffer[255]; //buffer to hold incoming packet
char  ReplyBuffer[] = "acknowledged";       // a string to send back
char inputc[1];

void setup () {
  pinMode (led,OUTPUT);//tell that the 13 pin is an output
  WiFi.setPins(8,7,4,2);
  pinMode (button1, INPUT);
  pinMode (button2, INPUT);
  digitalWrite(13, HIGH);
  Serial.begin(9600);//for the connect with the boared
 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
Serial.begin(9600);
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);                   // print the network name (SSID);

    // Connect to WPA/WPA2 network:
    status = WiFi.begin(ssid, pass);
  }

  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  Udp.begin(localPort);
}

 

void loop () {
    int btn = digitalRead(button1);
    if(btn == 0){
      delay(500);
       String sos = "sos";
       sos.toCharArray(sosc, 4);
       for(int i = 0; i<4; i++){
       Udp.beginPacket(boardIp, remotePort);

    Udp.write(sosc[i]);
    Udp.endPacket();
       }
      Serial.println("sos");
    }
    int btn2 = digitalRead(button2);
    if(btn2 == 0){
      delay(500);
       String help = "help";
       help.toCharArray(helpc, 5);
       for(int i = 0; i<5; i++){
       Udp.beginPacket(boardIp, remotePort);

    Udp.write(helpc[i]);
    Udp.endPacket();
       }
      Serial.println("help");
    }
    
     int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");

    Serial.print(boardIp);
    Serial.print(", port ");
    Serial.println(Udp.remotePort());

    // read the packet into packetBufffer
    int len = Udp.read(packetBuffer, 255);
    if (len > 0) packetBuffer[len] = 0;

     if (packetBuffer[0] == 'a' || packetBuffer[0] == 'A') {lA();}//if the input is a or A go to function lA
    if (packetBuffer[0] == 'b' || packetBuffer[0] == 'B') {lB();}//same but with b letter
     if (packetBuffer[0] == 'c' || packetBuffer[0] == 'C') {lC();}
    if (packetBuffer[0] == 'd' || packetBuffer[0] == 'D') {lD();}
    if (packetBuffer[0] == 'e' || packetBuffer[0] == 'E') {lE();}
    if (packetBuffer[0] == 'f' || packetBuffer[0] == 'F') {lF();}
    if (packetBuffer[0] == 'g' || packetBuffer[0] == 'G') {lG();}
    if (packetBuffer[0] == 'h' || packetBuffer[0] == 'H') {lH();}
    if (packetBuffer[0] == 'i' || packetBuffer[0] == 'I') {lI();}
    if (packetBuffer[0] == 'j' || packetBuffer[0] == 'J') {lJ();}
    if (packetBuffer[0] == 'k' || packetBuffer[0] == 'K') {lK();}
    if (packetBuffer[0] == 'l' || packetBuffer[0] == 'L') {lL();}
    if (packetBuffer[0] == 'm' || packetBuffer[0] == 'M') {lM();}
    if (packetBuffer[0] == 'n' || packetBuffer[0] == 'N') {lN();}
    if (packetBuffer[0] == 'o' || packetBuffer[0] == 'O') {lO();}
    if (packetBuffer[0] == 'p' || packetBuffer[0] == 'P') {lP();}
    if (packetBuffer[0] == 'q' || packetBuffer[0] == 'Q') {lQ();}
    if (packetBuffer[0] == 'r' || packetBuffer[0] == 'R') {lR();}
    if (packetBuffer[0] == 's' || packetBuffer[0] == 'S') {lS();}
    if (packetBuffer[0] == 't' || packetBuffer[0] == 'T') {lT();}
    if (packetBuffer[0] == 'u' || packetBuffer[0] == 'U') {lU();}
    if (packetBuffer[0] == 'v' || packetBuffer[0] == 'V') {lV();}
    if (packetBuffer[0] == 'w' || packetBuffer[0] == 'W') {lW();}
    if (packetBuffer[0] == 'x' || packetBuffer[0] == 'X') {lX();}
    if (packetBuffer[0] == 'y' || packetBuffer[0] == 'Y') {lY();}
    if (packetBuffer[0] == 'z' || packetBuffer[0] == 'Z') {lZ();}
    if (packetBuffer[0] == '1') {n1();}// the numbers
    if (packetBuffer[0] == '2') {n2();}
    if (packetBuffer[0] == '3') {n3();}
    if (packetBuffer[0] == '4') {n4();}
    if (packetBuffer[0] == '5') {n5();}
    if (packetBuffer[0] == '6') {n6();}
    if (packetBuffer[0] == '7') {n7();}
    if (packetBuffer[0] == '8') {n8();}
    if (packetBuffer[0] == '9') {n9();}
    if (packetBuffer[0] == '0') {n0();}
    if (packetBuffer[0] == ' ') {space();}//the space
     Serial.println (packetBuffer[0]);//print the latter saved in the input var
  }
 
    if (Serial.available()) {
   input = Serial.read();//read the input
      Udp.beginPacket(boardIp, remotePort);
    
    Udp.write(inputc);
    Udp.endPacket();
 
    if (input == 'a' || input == 'A') {lA();}//if the input is a or A go to function lA
    if (input == 'b' || input == 'B') {lB();}//same but with b letter
    if (input == 'c' || input == 'C') {lC();}
    if (input == 'd' || input == 'D') {lD();}
    if (input == 'e' || input == 'E') {lE();}
    if (input == 'f' || input == 'F') {lF();}
    if (input == 'g' || input == 'G') {lG();}
    if (input == 'h' || input == 'H') {lH();}
    if (input == 'i' || input == 'I') {lI();}
    if (input == 'j' || input == 'J') {lJ();}
    if (input == 'k' || input == 'K') {lK();}
    if (input == 'l' || input == 'L') {lL();}
    if (input == 'm' || input == 'M') {lM();}
    if (input == 'n' || input == 'N') {lN();}
    if (input == 'o' || input == 'O') {lO();}
    if (input == 'p' || input == 'P') {lP();}
    if (input == 'q' || input == 'Q') {lQ();}
    if (input == 'r' || input == 'R') {lR();}
    if (input == 's' || input == 'S') {lS();}
    if (input == 't' || input == 'T') {lT();}
    if (input == 'u' || input == 'U') {lU();}
    if (input == 'v' || input == 'V') {lV();}
    if (input == 'w' || input == 'W') {lW();}
    if (input == 'x' || input == 'X') {lX();}
    if (input == 'y' || input == 'Y') {lY();}
    if (input == 'z' || input == 'Z') {lZ();}
    if (input == '1') {n1();}// the numbers
    if (input == '2') {n2();}
    if (input == '3') {n3();}
    if (input == '4') {n4();}
    if (input == '5') {n5();}
    if (input == '6') {n6();}
    if (input == '7') {n7();}
    if (input == '8') {n8();}
    if (input == '9') {n9();}
    if (input == '0') {n0();}
    if (input == ' ') {space();}//the space
    Serial.println (input);//print the latter saved in the input var 
    
    }
  }

//fonctions for the letters and the numbers
void lA () {dot();dash();shortspace();}//letter A in morse code!
void lB () {dash();dot();dot();dot();shortspace();}//same for B
void lC () {dash();dot();dash();dot();shortspace();}
void lD () {dash();dot();dot();shortspace();}
void lE () {dot();shortspace();}
void lF () {dot();dot();dash();dot();shortspace();}
void lG () {dash();dash();dot();shortspace();}
void lH () {dot();dot();dot();dot();shortspace();}
void lI () {dot();dot();shortspace();}
void lJ () {dot();dash();dash();dash();shortspace();}
void lK () {dash();dot();dash();shortspace();}
void lL () {dot();dash();dot();dot();shortspace();}
void lM () {dash();dash();shortspace();}
void lN () {dash();dot();shortspace();}
void lO () {dash();dash();dash();shortspace();}
void lP () {dot();dash();dash();dot();shortspace();}
void lQ () {dash();dash();dot();dash();shortspace();}
void lR () {dot();dash();dot();shortspace();}
void lS () {dot();dot();dot();shortspace();}
void lT () {dash();shortspace();}
void lU () {dot();dot();dash();shortspace();}
void lV () {dot();dot();dot();dash();shortspace();}
void lW () {dot();dash();dash();shortspace();}
void lX () {dash();dot();dot();dash();shortspace();}
void lY () {dash();dot();dash();dash();shortspace();}
void lZ () {dash();dash();dot();dot();shortspace();}
void n1 () {dot();dash();dash();dash();dash();shortspace();}//number 1 in morse code
void n2 () {dot();dot();dash();dash();dash();shortspace();}
void n3 () {dot();dot();dot();dash();dash();shortspace();}
void n4 () {dot();dot();dot();dot();dash();shortspace();}
void n5 () {dot();dot();dot();dot();dot();shortspace();}
void n6 () {dash();dot();dot();dot();dot();shortspace();}
void n7 () {dash();dash();dot();dot();dot();shortspace();}
void n8 () {dash();dash();dash();dot();dot();shortspace();}
void n9 () {dash();dash();dash();dash();dot();shortspace();}
void n0 () {dash();dash();dash();dash();dash();shortspace();}
void space () {delay (1200);}//space between words
void dot () {digitalWrite(led,HIGH); delay (300); digitalWrite(led,LOW); delay (300);}//the dot this code make the led on for 300 than off for 300
void dash () {digitalWrite(led,HIGH); delay (900); digitalWrite(led,LOW); delay (300);}//the dash this code make the led on for 900 than off for 300
void shortspace () {delay(600);}//space between letters
void printWiFiData() {
  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  Serial.println(ip);

  // print your MAC address:
  byte mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC address: ");
  Serial.print(mac[5], HEX);
  Serial.print(":");
  Serial.print(mac[4], HEX);
  Serial.print(":");
  Serial.print(mac[3], HEX);
  Serial.print(":");
  Serial.print(mac[2], HEX);
  Serial.print(":");
  Serial.print(mac[1], HEX);
  Serial.print(":");
  Serial.println(mac[0], HEX);

}

void printCurrentNet() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print the MAC address of the router you're attached to:
  byte bssid[6];
  WiFi.BSSID(bssid);
  Serial.print("BSSID: ");
  Serial.print(bssid[5], HEX);
  Serial.print(":");
  Serial.print(bssid[4], HEX);
  Serial.print(":");
  Serial.print(bssid[3], HEX);
  Serial.print(":");
  Serial.print(bssid[2], HEX);
  Serial.print(":");
  Serial.print(bssid[1], HEX);
  Serial.print(":");
  Serial.println(bssid[0], HEX);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.println(rssi);

  // print the encryption type:
  byte encryption = WiFi.encryptionType();
  Serial.print("Encryption Type:");
  Serial.println(encryption, HEX);
  Serial.println();
}

/*done*/
