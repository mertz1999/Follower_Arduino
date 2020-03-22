/*
Mertz 
reza Tanaki zadeh 
this code send some data by GET method and recive a data from server
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

/* Set these to your desired credentials. */
const char *ssid = "SSID";  //ENTER YOUR WIFI SETTINGS
const char *password = "PASS";

//Web/Server address to read/write from 
const char *host = "http://test2.spschemco.com/esp.php"; 
//=======================================================================
//                    Power on setup
//=======================================================================

void setup() {
  delay(1000);
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
}

//=======================================================================
//                    Main Program Loop
//=======================================================================
void loop() {
  String getData;
  HTTPClient http;    //Declare object of class HTTPClient

  String username;

  //Post Data
  
    username = "reza.tz1999"; //username of Your instagram ID
    delay(100);
    getData = "?reza="+username; //GET data
    
    http.begin("http://test2.spschemco.com/esp.php"+gettData);              //Specify request destination

    int httpCode = http.GET();   //Send the request
    String payload = http.getString();    //Get the response payload
  
    Serial.println(httpCode);   //Print HTTP return codes
    Serial.println(payload);    //Print request response payload
  
    http.end();  //Close connection
    
    delay(5000);  //Post Data at every 5 seconds
  
}
//=======================================================================
