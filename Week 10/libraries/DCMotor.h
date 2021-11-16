#ifndef DCMOTOR_H
#define DCMOTOR_H

#include "Arduino.h"
#include "Blinky.h"

class DCMotor
{
	private:
		Blinky oscillator;
		unsigned long Period;
	public:
		DCMotor()
		{
		Initialize('B', 5,100);
		}
		DCMotor(char port, int pin,double frequency_in_herts)
		{
		Initialize(port,pin,frequency_in_herts);
		}
		void Initialize(char port,int pin,double frequency_in_herts)
		{
		Period =1000000 /frequency_in_herts;
		oscillator.Initialize(port,pin,0,Period);
		}
		void Write(double duty_cycle)
		{
		unsigned long OnTime=Period * duty_cycle;
		unsigned long OffTime=Period -OnTime;
		oscillator.ChangeOnOffTimes(OnTime,OffTime);
		}
		void Refresh()
		{
		oscillator.Refresh();
		}
};

#endif
