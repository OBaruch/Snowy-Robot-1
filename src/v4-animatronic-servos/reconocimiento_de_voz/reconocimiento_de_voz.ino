#include <Servo.h>
#include <WiFi.h>
#define ledVerde 23
String ClientRequest;
///////////////////////////////////////////////////////////////////////////////////////////////////////ESTABLECER IP
IPAddress staticIP(192, 168, 43, 211); //http://192.168.43.211
IPAddress gateway(192, 168, 3, 255);
IPAddress subnet(255, 255, 255, 0);
WiFiServer server(80);
WiFiClient client;
String myresultat;
///////////////////////////////////////////////////////////////////////////////////////////////////////VARIABLES DE SERVOS
static const int servosPins[3] = {18, 19, 21}; 
Servo servos[3];
///////////////////////////////////////////////////////////////////////////////////////////////////////FUNCIONES

void setServos(int degrees,int s) {
  servos[s].write((degrees + (35 * s)) % 180);  
}


String ReadIncomingRequest()
{
  while (client.available())
  {
    ClientRequest = (client.readStringUntil('\r'));
    if ((ClientRequest.indexOf("HTTP/1.1") > 0))
      myresultat = ClientRequest;
  }
  return myresultat;
}













void setup()
{
  Serial.begin(115200);
  ClientRequest = "";
  pinMode(ledVerde, OUTPUT);
  Serial.begin(115200);
  delay(10);
///////////////////////////////////////////////////////////////////////////////////////////////////////CONECTAR A WIFI
  Serial.println("START");
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println("virus");
  WiFi.begin("virus", "123123123");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected");
  WiFi.config(staticIP, gateway, subnet);  
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP()));
///////////////////////////////////////////////////////////////////////////////////////////////////////INICIALIZAR SERVIDOR
  server.begin();
///////////////////////////////////////////////////////////////////////////////////////////////////////CONEXION DE SERVOS
      for(int i = 0; i < 3; ++i) {
        if(!servos[i].attach(servosPins[i])) {
            Serial.print("Servo ");
            Serial.print(i); 
            Serial.println("attach error");
        }
    }
}















void loop()
{

///////////////////////////////////////////////////////////////////////////////////////////////////////BUSCAR CLIENTE EN EL SERVIDOR
  //obtém cliente
  client = server.available();
  if (!client)
    return;
  while (!client.available())
    delay(1);
///////////////////////////////////////////////////////////////////////////////////////////////////////LEER URL
  ClientRequest = (ReadIncomingRequest());
  ClientRequest.remove(0, 5);
  ClientRequest.remove(ClientRequest.length() - 9, 9);
  Serial.println(ClientRequest);
///////////////////////////////////////////////////////////////////////////////////////////////////////COMANDOS
  if (ClientRequest == "navidad")
  {
  }

  if (ClientRequest == "hora")
  {
  }
  if (ClientRequest == "luces")
  {
  }
  if (ClientRequest == "baila")
  {

  }
  if (ClientRequest == "no")
  {
    int pos =0;
    while (pos <= 179) {
    setServos(pos,2);
    delay(20);
    Serial.println(pos);
    pos=pos+20;  
    }    
    int posD = 179;
    while (posD >= 0) {
    setServos(posD,2);
    Serial.println(posD);
    delay(20);
    posD=posD-20;
    }
      
  }
  if (ClientRequest == "si")
  {

  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("");
  client.println("");
  client.println("OK");
  client.println("");
  client.flush();
  client.stop();
  delay(1);
}
