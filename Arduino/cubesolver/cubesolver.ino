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
const int a = ;
const int b = ;
const int f = ;
*/

void arm(boolean e) {
    digitalWrite(aD, e ? HIGH : LOW);
    digitalWrite(aB, LOW);
    delay(a);
    digitalWrite(aB, HIGH);
}

void base(boolean r) {
    digitalWrite(bD, r ? HIGH : LOW);
    digitalWrite(bB, LOW);
    delay(b);
    digitalWrite(bB, HIGH);
}

void flip() {
    digitalWrite(fD, HIGH);
    digitalWrite(fB, LOW);
    delay(f);
    digitalWrite(fD, LOW);
    delay(f);
    digitalWrite(fB, HIGH);
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
                arm(false);
            }
            a = false;
            base(true);
            break;
        case 'l':
            if (a) {
                arm(false);
            }
            a = false;
            base(false);
            break;
        case 'f':
            if (a) {
                arm(false);
            }
            flip();
            arm(true);
            a = true;
            break;
        case 'c':        
            if (!a) {
                arm(true);
            }
            a = true;
            base(true);
            break;
        case 'w':        
            if (!a) {
                arm(true);
            }
            a = true;
            base(false);
            break;
    }
}

