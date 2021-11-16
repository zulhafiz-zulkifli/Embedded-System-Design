#ifndef STEPPER
#define STEPPER

#include "Arduino.h"

class Stepper
{
	private:
		char* DDR;
		char* PORT;
		char DriveSteps[8];
		char Position;
		char MaximumPosition;
	public:
		Stepper(char port,char mode)
		{
			Position =0;
			switch(port)
			{
				case'B':
					DDR =(char*)0x24;
					PORT =(char*)0x25;
					break;
				case'C':
					DDR =(char*)0x27;
					PORT =(char*)0x28;
					break;
				case'D':
					DDR = (char*)0x2A;
					PORT = (char*)0x2B;
					break;
			}
			*DDR |=0b00001111;
			switch(mode)
			{
				case'W':
					MaximumPosition=4;
					DriveSteps[0]=1;
					DriveSteps[1]=2;
					DriveSteps[2]=4;
					DriveSteps[3]=8;
					break;
				case'F':
					MaximumPosition=4;
					DriveSteps[0]=3;
					DriveSteps[1]=6;
					DriveSteps[2]=12;
					DriveSteps[3]=9;
					break;
				case'H':
					MaximumPosition=8;
					DriveSteps[0]=1;
					DriveSteps[1]=3;
					DriveSteps[2]=2;
					DriveSteps[3]=6;
					DriveSteps[4]=4;
					DriveSteps[5] =12;
					DriveSteps[6]=8;
					DriveSteps[7]=9;
				break;
			}
		}
		
		void DriveCW()
		{
			*PORT =DriveSteps[Position];
			Position++;
			if (Position>=MaximumPosition)
			{
				Position = 0;
			}
		}
		
		void DriveCCW()
		{
			*PORT =DriveSteps[Position];
			Position--;
			if(Position<0)
			{
				Position =MaximumPosition-1;
			}
		}
};

#endif
