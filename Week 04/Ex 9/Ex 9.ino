#define SIZE 8
const int LED_PINS[SIZE]={6,7,8,9,10,11,12,13};
const int LED_ON[SIZE]={781,2014,343,678,342,1478,1859,777};
const int LED_OFF[SIZE]={515,1348,573,1839,534,326,351,888};
struct LED{
	int pin, on, off;
	unsigned long current, prev;
} led[SIZE];

void blink(int i){
	led[i].prev = led[i].current;
	digitalWrite(led[i].pin,digitalRead(led[i].pin)?LOW:HIGH);
}

void setup(){
	for(int i=0;i<SIZE;i++){
		led[i].pin = LED_PINS[i];
		led[i].on = LED_ON[i];
		led[i].off = LED_OFF[i];
		pinMode(led[i].pin, OUTPUT);
	}
}

void loop(){
	for(int i=0;i<SIZE;i++){
		led[i].current = millis();
		(led[i].current-led[i].prev>=led[i].on && digitalRead(led[i].pin))? blink(i)
		:(led[i].current-led[i].prev>=led[i].off && !digitalRead(led[i].pin))? blink(i):void(0);
	}
}