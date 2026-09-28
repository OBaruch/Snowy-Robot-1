//lib necessária para conectar o wifi
#include <WiFi.h>
//led conectado no pino 23
#define ledVerde 23
//mensagem enviada pelo client (aplicativo)
String ClientRequest;
//Estas lineas se comentan para dejar la configuracion de IP dinamica //////////////
//ip estático, o mesmo deve ser usado no app do smartphone
IPAddress staticIP(192,168,43,211); //http://192.168.43.211
//gateway, deixe aqui o gateway da rede em que está conectado
IPAddress gateway(192,168,3,255);
//máscara, deixe aqui a máscara da rede em que está conectado
IPAddress subnet(255,255,255,0);
//////////////////////////////////////////////////////////////////////////
//objeto do servidor
WiFiServer server(80);
//objeto do cliente
WiFiClient client;
//variável usada para obter o request do client
String myresultat;

//função usada para a leitura do request sem caracteres de quebra de linha como "\n" ou "\r"
String ReadIncomingRequest()
{
//enquanto houver bytes enviados pelo client
while(client.available())
{
//atribui para a variável String o comando enviado pelo cliente sem "\r"
ClientRequest = (client.readStringUntil('\r'));
//se existir "HTTP/1.1" na String então recebe comando, senão o comando não é aceito
//isso verifica que a solicitação seja HTTP/1.1
if ((ClientRequest.indexOf("HTTP/1.1")>0))
myresultat = ClientRequest;
}
//retorna variável
return myresultat;
}



void setup()
{
//inicializa varíavel como vazia
ClientRequest = "";
//define pino do led como saída
pinMode(ledVerde,OUTPUT);
//inicializa serial com 115200 bits por segundo
Serial.begin(115200);
//aguarda 10ms
delay(10);
//A partir daqui conecta wifi
Serial.println("START");
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println("virus");
//configura ssid e senha da rede
WiFi.begin("virus", "123123123");
//enquanto não conectar exibe "."
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
//exibe "conectado"
Serial.println("Connected");
//configura ip estático, gateway e máscara (definidos globais no início do código)
    
//esta linea se comenta para configurar la IP dinamica 
WiFi.config(staticIP, gateway, subnet);
///////////////////////////////////////////////////////////
//exibe ip utilizado pelo ESP
Serial.println("Your IP is");
Serial.println((WiFi.localIP()));
//inicializa servidor
server.begin();
}


void loop()
{
//obtém cliente
client = server.available();
//se ele for nulo, retorna até que ele realmente exista
if (!client)
return;
//enquanto não existir request aguarda
while(!client.available())
delay(1);
//obtém request utilizando a função local ReadIncomingRequest
ClientRequest = (ReadIncomingRequest());
Serial.println("respuesta");
//retira dados da página e obtém apenas o comando enviado
ClientRequest.remove(0, 5);
ClientRequest.remove(ClientRequest.length()-9,9);
//controla led conforme o comando recebido
if (ClientRequest == "navidad")
{
    digitalWrite(ledVerde,HIGH);
}

if (ClientRequest == "hora")
{
    digitalWrite(ledVerde,LOW);
}
if (ClientRequest == "luces")
{
    digitalWrite(ledVerde,HIGH);
    delay(500);
    digitalWrite(ledVerde,LOW);
    delay(500);
    digitalWrite(ledVerde,HIGH);
    delay(500);
    digitalWrite(ledVerde,LOW);
    delay(500);
}
    if (ClientRequest == "baila")
{
    digitalWrite(ledVerde,HIGH);
    delay(500);
    digitalWrite(ledVerde,LOW);
    delay(500);
    digitalWrite(ledVerde,HIGH);
    delay(500);
    digitalWrite(ledVerde,LOW);
    delay(500);
}
        if (ClientRequest == "no")
{
    digitalWrite(ledVerde,HIGH);
    delay(500);
    digitalWrite(ledVerde,LOW);
    delay(500);
    digitalWrite(ledVerde,HIGH);
    delay(500);
    digitalWrite(ledVerde,LOW);
    delay(500);
}
            if (ClientRequest == "si")
{
    digitalWrite(ledVerde,HIGH);
    delay(500);
    digitalWrite(ledVerde,LOW);
    delay(500);
    digitalWrite(ledVerde,HIGH);
    delay(500);
    digitalWrite(ledVerde,LOW);
    delay(500);
}
//exibe na página a palavra "OK", caso acessado por um navegador
//se estiver no aplicativo esta exibição não será feita
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
