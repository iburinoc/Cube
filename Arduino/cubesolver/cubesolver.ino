/*
const int armDirectionPin = ;
const int armBreakerPin = ;
const int armPowerPin = ;
const int baseDirectionPin = ;
const int baseBreakerPin = ;
const int basePowerPin = ;
const int flipperDirectionPin = ;
const int flipperBreakerPin = ;
const int flipperPowerPin = ;
const int armExtendMovementDelay = ;
const int armRetractMovementDelay = ;
const int baseRightRotationDelay = ;
const int baseLeftRotationDelay = ;
const int flipperUpRotationDelay = ;
const int flipperDownRotationDelay = ;
const int moveSplitDelay = ;
const boolean EXTEND = true;
const boolean RETRACT = false;
const boolean RIGHT = true;
const boolean LEFT = false;
const boolean UP = true;
const boolean DOWN = false;
*/

void arm(boolean extend) {
    digitalWrite(armDirectionPin, extend ? HIGH : LOW);
    digitalWrite(armBreakerPin, LOW);
    delay(extend ? armExtendMovementDelay : armRetractMovementDelay);
    digitalWrite(armBreakerPin, HIGH);
	delay(moveSplitDelay);
}

void base(boolean right) {
    digitalWrite(baseDirectionPin, right ? HIGH : LOW);
    digitalWrite(baseBreakerPin, LOW);
    delay(right ? baseRightRotationDelay : baseLeftRotationDelay);
    digitalWrite(baseBreakerPin, HIGH);
	delay(moveSplitDelay);
}

void flip(boolean up) {
    digitalWrite(flipperDirectionPin, up ? HIGH : LOW);
    digitalWrite(flipperBreakerPin, LOW);
    delay(up ? flipperUpRotationDelay : flipperDownRotationDelay);
    digitalWrite(flipperBreakerPin, HIGH);
	delay(moveSplitDelay);
}

void setup() {
    Serial.begin(9600);
    pinMode(armDirectionPin, OUTPUT);
    pinMode(armBreakerPin, OUTPUT);
    pinMode(baseDirectionPin, OUTPUT);
    pinMode(baseBreakerPin, OUTPUT);
    pinMode(flipperDirectionPin, OUTPUT);
    pinMode(flipperBreakerPin, OUTPUT);
    digitalWrite(armBreakerPin, HIGH);
    digitalWrite(baseBreakerPin, HIGH);
    digitalWrite(flipperBreakerPin, HIGH);
    analogWrite(armPowerPin, 50);
    analogWrite(basePowerPin, 50);
    analogWrite(flipperPowerPin, 255);
	arm(RETRACT);
}

boolean armExtended = false;

void loop() {
    char instruction = Serial.read()[0];
    switch (instruction) {
        case 'r':
            if (armExtended) {
                arm(RETRACT);
            }
            armExtended = false;
            base(RIGHT);
            break;
        case 'l':
            if (armExtended) {
                arm(RETRACT);
            }
            armExtended = false;
            base(LEFT);
            break;
        case 'f':
            if (armExtended) {
                arm(RETRACT);
            }
            flip(UP);
			flip(DOWN);
            arm(EXTEND);
            armExtended = true;
            break;
        case 'c':        
            if (!armExtended) {
                arm(EXTEND);
            }
            armExtended = true;
            base(RIGHT);
            break;
        case 'w':        
            if (!armExtended) {
                arm(EXTEND);
            }
            armExtended = true;
            base(LEFT);
            break;
    }
}

