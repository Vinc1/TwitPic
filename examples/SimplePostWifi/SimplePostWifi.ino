//#include <Ethernet.h>
#include <SPI.h> // needed in Arduino 0019 or later
#include <WiFi.h>

#include <TwitPic.h>
#include "SampleImage.h"


char ssid[] = "nomdeSSID";
char pass[] = "motdepasse"; 

// Your TwitPic API Key(key)
const prog_char twitpic_api_key[] PROGMEM     = "Your TwitPic API Key";

// Your Twitter Consumer key(consumer_token)/Consumer Secret(consumer_secret)
const prog_char consumer_key[] PROGMEM        = "Your Consumer key";
const prog_char consumer_secret[] PROGMEM     = "Your Consumer Secret";

// Your Twitter Access Token (oauth_token)/Access Token Secret (oauth_token_secret)
const prog_char access_token[] PROGMEM        = "Your Access Token";
const prog_char access_token_secret[] PROGMEM = "Your Access Token Secret";

TwitPic twitpic;

void sampleImageTransfer(Client *client)
{
  for(uint32_t i=0; i<sizeof(sampleImage); i++){
    client->print(pgm_read_byte(sampleImage+i));
  }
}

byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 
  10, 0, 0, 177 };

void setup()
{
//pour ethernet :
  /*Ethernet.begin(mac, ip);
  Serial.begin(57600);
  */
  
//pour le wifi
    Serial.begin(9600);
    Serial.println("Démarrage ...");
  
  delay(1000);
  WiFi.begin(ssid, pass);
  delay(10000);
  
  Serial.println("connecting ..."); 
  delay(3000);

//tweet d'une image
  int ret = twitpic.uploadAndPost("Sample Image Post from Arduino", sizeof(sampleImage), &sampleImageTransfer);

  if(ret < 0){
    Serial.print("post failed : err code = ");
    Serial.println(ret);
  }
  else{
    Serial.println("OK.");
  }
}

void loop()
{
}

