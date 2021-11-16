#ifndef SERVOSWEEPER
#define SERVOSWEEPER

#include "Servo.h"

class ServoSweeper
{
	private:
		Servo* servo;
		int Min,Max,Step,Delay_ms;
		int Current;
		unsigned long last_time=0;
	public:
	ServoSweeper()
	{
	}
	ServoSweeper(Servo* _servo,int _Min,int _Max,int _Step,int _Delay_ms)
	{
		Initialize(_servo,_Min,_Max,_Step,_Delay_ms);
	}
	void Initialize(Servo* _servo,int _Min,int _Max,int _Step,int _Delay_ms)
	{
		servo =_servo;
		Min =_Min;
		Max =_Max;
		Step =_Step;
		Delay_ms=_Delay_ms;
		Current =_Min;
	}
	
	void Refresh()
	{
		unsigned long now =millis();
		if(now -last_time>=Delay_ms)
		{
			last_time=now;
			Current +=Step;
			servo->Write(Current);//equivalent to (*servo).Write(Current);
			if(Current >=Max ||Current <=Min)
			{
			Step = -Step;
			}
		}
		servo->Refresh(); //equivalent to (*servo).Refresh()
		}
};

#endif
