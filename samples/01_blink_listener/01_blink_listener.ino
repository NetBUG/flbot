#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#define PIN_LED 13

void messageCb( const std_msgs::Empty& toggle_msg){
  digitalWrite(PIN_LED, HIGH-digitalRead(PIN_LED));   // blink the led
}

ros::NodeHandle nh;
ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );

void setup() {
  pinMode(PIN_LED, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {
  nh.spinOnce();
  delay(1);
}
