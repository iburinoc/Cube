void setup() {
    Serial.begin(9600);
}

boolean a = false;

void rot_right() {
    //code for rotating base 90 degrees clockwise.
}

void rot_left() {
    //code for rotating base 90 degrees counter-clockwise.
}

void flip_up() {
    //code for flipping the base up by 90 degrees.
}

void flip_down() {
    //code for flipping the base down by 90 degrees.
}

void arm_extend() {
    //code for extending the arm to full length.
}

void arm_retract() {
    //code for retracting the arm as far back as possible.
}

void loop() {
    char m = Serial.read()[0];
    switch (m) {
        case 'r':
            if (a) {
                arm_retract();
            }
            a = false;
            rot_right();
            break;
        case 'l':
            if (a) {
				arm_retract();
            }
            a = false;
			rot_left();
            break;
        case 'f':
            if (a) {
				arm_retract();
            }
			flip_up();
			flip_down();
			arm_extend();
            a = true;
            break;
        case 'c':        
            if (!a) {
				arm_extend();
            }
            a = true;
			rot_right();
            break;
        case 'w':        
            if (!a) {
				arm_extend();
            }
            a = true;
			rot_left();
            break;    
           
	}
}

