#include <WiFi.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Float64.h>

//////////////////////
// WiFi Definitions //
//////////////////////
const char* ssid = "******";
const char* password = "*******";

IPAddress server(192, 168, 0, 25); // ip of your ROS server
IPAddress ip_address;
int status = WL_IDLE_STATUS;

int led = 2;
int button = 0;
bool state = true;

WiFiClient client;

class WiFiHardware {

  public:
  WiFiHardware() {};

  void init() {
    // do your initialization here. this probably includes TCP server/client setup
    client.connect(server, 11411);
  }

  // read a byte from the serial port. -1 = failure
  int read() {
    // implement this method so that it reads a byte from the TCP connection and returns it
    //  you may return -1 is there is an error; for example if the TCP connection is not open
    return client.read();         //will return -1 when it will works
  }

  // write data to the connection to ROS
  void write(uint8_t* data, int length) {
    // implement this so that it takes the arguments and writes or prints them to the TCP connection
    for(int i=0; i<length; i++)
      client.write(data[i]);
  }

  // returns milliseconds since start of program
  unsigned long time() {
     return millis(); // easy; did this one for you
  }
};

//int i;
const char* i;

void chatterCallback(const std_msgs::String& msg) {
  //i = atoi(msg.data);
  i = msg.data;
  Serial.println(i);
}

std_msgs::String str_msg;
ros::Subscriber<std_msgs::String> sub("message", &chatterCallback);
ros::Publisher chatter("esp32/button", &str_msg);
ros::NodeHandle_<WiFiHardware> nh;

void setupWiFi()
{
  WiFi.begin(ssid, password);
  Serial.print("\nConnecting to "); Serial.println(ssid);
  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED && i++ < 20) delay(500);
  if(i == 21){
    Serial.print("Could not connect to"); Serial.println(ssid);
    while(1) delay(500);
  }
  Serial.print("Ready! Use ");
  Serial.print(WiFi.localIP());
  Serial.println(" to access client");
}

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(button,INPUT_PULLUP);
  setupWiFi();
  delay(2000);
  //Serial.print("Setup function");
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);
}

void loop() {
  if(digitalRead(button) == LOW){
    str_msg.data = "on";
    digitalWrite(led,HIGH);
    chatter.publish(&str_msg);
  } else{
    str_msg.data = "off";
    digitalWrite(led,LOW);
    chatter.publish(&str_msg);
  }
  nh.spinOnce();
  delay(1000);
}
