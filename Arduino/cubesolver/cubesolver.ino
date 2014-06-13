void setup() {
    Serial.begin(9600);
}

boolean a = false;

void loop() {
    char m = Serial.read()[0];
    switch (m) {
        case 'r':
            if (a) {
                //command for moving the arm back
            }
            a = false;
            //command for moving the motor
            break;
        case 'l':
            if (a) {
                //command for moving the arm back
            }
            a = false;
            //command for moving the motor the other way
            break;
        case 'f':
            if (a) {
                //command for moving the arm back
            }
            /*
            command for moving the other motor up
            command for moving the other motor down
            command for moving the arm forward            
            */            
            a = true;
            break;
        case 'c':        
            if (!a) {
                //command for moving the arm forward
            }
            a = true;
            //command for moving the motor
            break;
        case 'w':        
            if (!a) {
                //command for moving the arm forward
            }
            a = true;
            //command for moving the motor the other way
            break;    
           
  }
}

