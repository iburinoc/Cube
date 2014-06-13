/*
const int aD = ;
const int aB = ;
const int aP = ;
const int bD = ;
const int bB = ;
const int bP = ;
const int fD = ;
const int fB = ;
const int fP = ;
const int t = ;
const int a = ;
const int f = ;
*/

void arm(boolean e) {
    digitalWrite(aD, e ? HIGH : LOW);
}

void setup() {
    Serial.begin(9600);
    pinMode(aD, OUTPUT);
    pinMode(aB, OUTPUT);
    pinMode(bD, OUTPUT);
    pinMode(bB, OUTPUT);
    pinMode(fD, OUTPUT);
    pinMode(fB, OUTPUT);
    digitalWrite(aB, HIGH);
    digitalWrite(bB, HIGH);
    digitalWrite(fB, HIGH);
    analogWrite(aP, 50);
    analogWrite(bP, 50);
    analogWrite(fP, 255);
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

