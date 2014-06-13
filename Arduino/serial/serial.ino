/*
void synchronize() {
syn:
	/* connect with TCP connection establishment cuz why not 
	char* conn = "SYN";
	int i = 0;
	while(conn[i]) {
		int b = Serial.read();
		if(b != -1) {
			if(b == conn[i]) {
				i++;
			} else {
				goto syn;
			}
		}
	}
	char* response = "SYN-ACK";
	i = 0;
	while(conn[i]) {
		Serial.write(response[i]);
		i++;
	}
	char* final = "ACK";
	i = 0;
	while(final[i]) {
		int b = Serial.read();
		if(b != -1) {
			if(b == final[i]) {
				i++;
			} else {
				goto syn;
			}
		}
	}
}
*/

void setup() {
	Serial.begin(9600);
}

void loop() {
	if(Serial.available() > 0) {
		int b = Serial.read();
		Serial.write(b);
	}
}
