#ifndef SERVO
#define SERVO

#include "Arduino.h"
#include "Blinky.h"

class Servo
{
	private:
		Blinky oscillator;
		int Period;
	public:
		Servo()
		{
		Initialize('B',5,20000);
		}
		Servo(char port,int pin,int period)
		{
		Initialize(port,pin,period);
		}
		void Initialize(char port,int pin,int period)
		{
		Period =period;
		oscillator.Initialize(port,pin,0,period);
		}
		void Write(int ontime)
		{
		oscillator.ChangeOnOffTimes(ontime, Period -ontime);
		}
		void Refresh()
		{
		oscillator.Refresh();
		}
};

#endif
