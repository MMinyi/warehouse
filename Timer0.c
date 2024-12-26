#include <REGX52.H>
#include "Key.H"

void Timer0_Init(void)
{
	TMOD &= 0xF0;		
	TMOD |= 0x01;	
	TL0 = 0xF7;		
	TH0 = 0xFF;		
	TF0 = 0;		
	TR0 = 1;		
	ET0=1;
	EA=1;
	PT0=0;
}



