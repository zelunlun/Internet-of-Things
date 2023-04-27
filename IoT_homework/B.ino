void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  int incoming_byte;
  
  if(Serial.available() > 0) {
    incoming_byte = Serial.read();  // read the incoming byte
    Serial1.write(incoming_byte);
  }
  if(Serial1.available() > 0) {
    incoming_byte = Serial1.read();  // read the incoming byte
    Serial.write(incoming_byte);
  }

}
