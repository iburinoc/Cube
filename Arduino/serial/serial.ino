void setup() {
	Serial.begin(9600);
}

void loop() {
	if(Serial.available() > 0) {
		int b = Serial.read();
		Serial.write(b);
	}
}
