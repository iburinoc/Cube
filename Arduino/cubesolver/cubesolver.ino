#include <Wire.h>
#include <Adafruit_MotorShield.h>

/*
const int armPower = ;
const int basePower = ;
const int flipperPower = ;
const int armExtendMovementDelay = ;
const int armRetractMovementDelay = ;
const int baseRightRotationDelay = ;
const int baseLeftRotationDelay = ;
const int flipperUpRotationDelay = ;
const int flipperDownRotationDelay = ;
*/
const int armMotorNumber = 1;
const int baseMotorNumber = 3;
const int flipperMotorNumber = 4;
const int moveSplitDelay = 500;
const boolean EXTEND = true;
const boolean RETRACT = false;
const boolean RIGHT = true;
const boolean LEFT = false;
const boolean UP = true;
const boolean DOWN = false;

Adafruit_MotorShield AFMS() = Adafruit_ModorShield();
Adafruit_DCMotor *arm = AFMS.getMotor(armMotorNumber);
Adafruit_DCMotor *base = AFMS.getMotor(baseMotorNumber);
Adafruit_DCMotor *flipper = AFMS.getMotor(flipperMotorNumber);

boolean armExtended = false;

void arm(boolean extend) {
	arm->run(extend ? FORWARD : BACKWARD);
	delay(extend ? armExtendMovementDelay : armRetractMovementDelay);
	arm->run(RELEASE);
	delay(moveSplitDelay);
	armExtended = extend;
}

void base(boolean right) {
	base->run(right ? FORWARD : BACKWARD);
	delay(right ? baseRightRotationDelay : baseLeftRotationDelay);
	base->run(RELEASE);
	delay(moveSplitDelay);
}

void flip(boolean up) {
	flipper->run(up ? FORWARD : BACKWARD);
	delay(up ? flipperUpRotationDelay : flipperDownRotationDelay);
	flipper->run(RELEASE);
	delay(moveSplitDelay);
}

void setup() {
	Serial.begin(9600);
	arm->setSpeed(armPower);
	base->setSpeed(basePower);
	flipper->setSpeed(flipperPower);
	arm(RETRACT);
}


void loop() {
	char instruction = Serial.read();
	switch (instruction) {
		case 'r':
			if (armExtended) {
				arm(RETRACT);
			}
			base(RIGHT);
			break;
		case 'l':
			if (armExtended) {
				arm(RETRACT);
			}
			base(LEFT);
			break;
		case 'f':
			if (armExtended) {
				arm(RETRACT);
			}
			flip(UP);
			flip(DOWN);
			arm(EXTEND);
			break;
		case 'c':
			if (!armExtended) {
				arm(EXTEND);
			}
			base(RIGHT);
			break;
		case 'w':
			if (!armExtended) {
				arm(EXTEND);
			}
			base(LEFT);
			break;
	}
}

