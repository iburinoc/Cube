void setup() {
	Serial.begin(9600);
	Serial.println("heyo");
}

int i = 0;

void loop() {
	Serial.print("heyo");
	Serial.println(i);
	i++;
	delay(500);
}
