#include <string.h>
#define LED_FLASH_INTERVAL  500 // ms
#define RED_LED 2
#define GREEN_LED 3

void setup() {  
  static int Serial1;
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT); 
}
//紅綠開
void led_on(int turn)
{
  switch (turn) {
    case 0:
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
      break;
    case 1:
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
      break;
    default:
      break;
  }
}
//全關
void led_off()
{
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
}

void loop() {
  static unsigned long last_time_led;
  static bool toggle_on = false;
  static int turn = 0;
  //----------38
  static char buf[200];
  static int  length = 0;
  static int Serial1;
  int incoming_byte;
  //----------
  //----------
  if(Serial1.available() > 0) { // check if there is incoming data
    incoming_byte = Serial1.read();  // read the incoming byte
    buf[length++] = incoming_byte;  // put the incoming byte to string buffer
    if(incoming_byte == '\n') { // check if LF is incoming
      // append '\0' to buf[] as the end of the string
      buf[length++] = '\0';
      // do job
      if(strcmp(buf, "on\n")==0) { // check if the incoming string is "on"
        toggle_on = !toggle_on;
        if(toggle_on) {
          last_time_led = millis();
          led_on(turn);
          turn = (turn+1)%2;
          Serial.println("LED ON");
          Serial1.println("LED ON");
        }
       }
       else if(strcmp(buf, "off\n")==0) { // check if the incoming string is "on"
          led_off();
          toggle_on = false;
          Serial.println("LED OFF");
          Serial1.println("LED OFF");
       }
       else { // Otherwise, it is unknown command
          Serial.print("Unknown command: ");
          Serial.println(buf);
       }
       length = 0; // reset the length for receiving next string
      }
    }
  //----------
  // light led
    if(toggle_on && millis()-last_time_led >= LED_FLASH_INTERVAL) {
      last_time_led = millis();
      led_on(turn);
      turn = (turn+1)%2;
    }
}
