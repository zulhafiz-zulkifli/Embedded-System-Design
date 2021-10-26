#define SIZE 4
#define DEBOUNCE_DELAY 50
const int LED_PINS[SIZE]={2,3,4,5};


struct Button{
	int count = 0,pin;
	unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
	int lastSteadyState = LOW;       // the previous steady state from the input pin
	int lastFlickerableState = LOW;  // the previous flickerable state from the input pin
	int currentState;                // the current reading from the input pin
}buttons[SIZE];

void printState(){
	for(int i=0;i<SIZE;i++){
		if(i<SIZE-1){
			Serial.print(buttons[i].count);
			Serial.print("\t");			
		}
		else{
			Serial.println(buttons[i].count);
		}
	}
}

void setup(){
	Serial.begin(9600);
	for(int i=0;i<SIZE;i++){
		buttons[i].pin = LED_PINS[i];
		pinMode(buttons[i].pin, INPUT_PULLUP);
	}
}

void loop(){
	for(int i=0;i<SIZE;i++){
		buttons[i].currentState = digitalRead(buttons[i].pin);
		if (buttons[i].currentState != buttons[i].lastFlickerableState){
			buttons[i].lastDebounceTime = millis();
			buttons[i].lastFlickerableState = buttons[i].currentState;
		}

		if ((millis() - buttons[i].lastDebounceTime) > DEBOUNCE_DELAY){
			if(buttons[i].lastSteadyState == HIGH && buttons[i].currentState == LOW)
				buttons[i].count++;
			else if(buttons[i].lastSteadyState == LOW && buttons[i].currentState == HIGH){
				printState();
			}
			buttons[i].lastSteadyState = buttons[i].currentState;
		}
	}
}