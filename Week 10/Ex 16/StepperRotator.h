#ifndef STEPPERROTATOR
#define STEPPERROTATOR

#include "Arduino.h"
#include "Stepper.h"

class StepperRotator
{
	private:
		Stepper* stepper;
		unsigned long delay_us;
		bool clockwise;
		unsigned long previous=0;
		
	public:
		StepperRotator(Stepper* _stepper,bool _clockwise,unsigned long _delay_us)
		{
			stepper = _stepper;
			delay_us= _delay_us;
			clockwise = _clockwise;
		}
		void Refresh()
		{
			unsigned long now =micros();
			if(now-previous>=delay_us)
			{
				if(clockwise)
				{
					stepper->DriveCW();
				}
				else
				{
					stepper->DriveCCW();
				}
				previous = now;
			}
		}
};

#endif
