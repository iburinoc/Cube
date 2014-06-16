#include <Wire.h>
#include <Adafruit_MotorShield.h>

const int armPower = 90;
const int basePower = 50;
const int baseCubePower = 90;
const int flipperPower = 255;
const int armExtendMovementDelay = 700;
const int armRetractMovementDelay = 700;
const int baseRightRotationDelay = 247;
const int baseLeftRotationDelay = 200;
const int baseRightCubeRotationDelay = 500;
const int baseLeftCubeRotationDelay = 210;
const int flipperUpRotationDelay = 3000;
const int flipperDownRotationDelay = 2600;
const int adjustRightDelay = 25;
const int adjustLeftDelay = 15;

#define ARM_MOTOR_NUMBER 1
#define BASE_MOTOR_NUMBER 3
#define FLIPPER_MOTOR_NUMBER 4
const int moveSplitDelay = 2000;
const boolean EXTEND = true;
const boolean RETRACT = false;
const boolean RIGHT = true;
const boolean LEFT = false;
const boolean UP = true;
const boolean DOWN = false;

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *armm = AFMS.getMotor(ARM_MOTOR_NUMBER);
Adafruit_DCMotor *basem = AFMS.getMotor(BASE_MOTOR_NUMBER);
Adafruit_DCMotor *flipperm = AFMS.getMotor(FLIPPER_MOTOR_NUMBER);

boolean armExtended = false;

void arm(boolean extend) {
	armm->run(!extend ? FORWARD : BACKWARD);
	delay(extend ? armExtendMovementDelay : armRetractMovementDelay);
	armm->run(RELEASE);
	delay(moveSplitDelay);
	armExtended = extend;
}

void base(boolean right) {
        basem->setSpeed(armExtended ? baseCubePower : basePower);
	basem->run(right ? FORWARD : BACKWARD);
	delay(armExtended ? (right ? baseRightCubeRotationDelay : baseLeftCubeRotationDelay) : (right ? baseRightRotationDelay : baseLeftRotationDelay));
	basem->run(RELEASE);
	delay(moveSplitDelay);
}

void flip(boolean up) {
	flipperm->run(up ? FORWARD : BACKWARD);
	delay(up ? flipperUpRotationDelay : flipperDownRotationDelay);
	flipperm->run(RELEASE);
	delay(moveSplitDelay);
}

void adjust(boolean right) {
	basem->run(right ? FORWARD : BACKWARD);
	delay(right ? adjustRightDelay : adjustLeftDelay);
	basem->run(RELEASE);
	delay(moveSplitDelay);
}

void setup() {
	Serial.begin(9600);
	AFMS.begin();
	armm->setSpeed(armPower);
	basem->setSpeed(basePower);
	flipperm->setSpeed(flipperPower);
	armm->run(RELEASE);
	basem->run(RELEASE);
	flipperm->run(RELEASE);
	delay(1000);
	Serial.write('b');
}

void loop() {
	int instruction = Serial.read();
	if(instruction != -1) {
		Serial.write(instruction);
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
				arm(RETRACT);
				adjust(RIGHT);
				break;
			case 'c':
				if (!armExtended) {
					arm(EXTEND);
				}
				base(RIGHT);
                                //adjust(RIGHT);
                                adjust(LEFT);
				break;
			case 'w':
				if (!armExtended) {
					arm(EXTEND);
				}
				base(LEFT);
                                //adjust(LEFT);
                                adjust(RIGHT);
				break;
		}
	}
	delay(10);
}

