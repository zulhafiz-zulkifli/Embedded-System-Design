#define BTN1 2
#define BTN2 3
#define BTN3 4
#define BTN4 5
#define DEBOUNCE 100

struct Millis{
	unsigned long curr, prev;
	int count = 0;
};
Millis b1, b2, b3, b4;

void printState(){
	Serial.print(b1.count);
	Serial.print("\t");
	Serial.print(b2.count);
	Serial.print("\t");
	Serial.print(b3.count);
	Serial.print("\t");
	Serial.println(b4.count);
}

void setup(){
	Serial.begin(9600);
	pinMode(BTN1, INPUT_PULLUP);
	pinMode(BTN2, INPUT_PULLUP);
	pinMode(BTN3, INPUT_PULLUP);
	pinMode(BTN4, INPUT_PULLUP);
	printState();
}

void loop(){
	b1.curr = millis();b2.curr = millis();b3.curr = millis();b4.curr = millis();
	if(b1.curr-b1.prev>=DEBOUNCE){
		b1.prev = b1.curr;
		if(!digitalRead(BTN1)) b1.count++;
		printState();
	}
	if(b2.curr-b2.prev>=DEBOUNCE){
		b2.prev = b2.curr;
		if(!digitalRead(BTN2)) b2.count++;
		printState();
	}
	if(b3.curr-b3.prev>=DEBOUNCE){
		b3.prev = b3.curr;
		if(!digitalRead(BTN3)) b3.count++;
		printState();
	}
	if(b4.curr-b4.prev>=DEBOUNCE){
		b4.prev = b4.curr;
		if(!digitalRead(BTN4)) b4.count++;
		printState();
	}
}