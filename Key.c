#include <REGX52.H>
#include "Delay.h"

unsigned char Key_KeyNumber;//key state°´¼ü×´Ì¬

unsigned char Key(void)//acquire key state
{
	unsigned char Temp=0;
	Temp=Key_KeyNumber;
	Key_KeyNumber=0;
	return Temp;
}

static unsigned char Key_GetState()//
{
	unsigned char KeyNumber=0;
	
	if(P3_1==0){KeyNumber=1;}
	if(P3_0==0){KeyNumber=2;}
	if(P3_2==0){KeyNumber=3;}
	if(P3_3==0){KeyNumber=4;}
	
	return KeyNumber;
}


	

void Key_Loop(void)// short press or not
{
	if(P3_1==0)
	{
		Delay(30);
		if(P3_1==1)
		{
			Key_KeyNumber=1;
		}
	}
	if(P3_0==0)
	{
		Delay(30);
		if(P3_0==1)
		{
		Key_KeyNumber=2;
		}
	}
	if(P3_2==0)
	{
		Delay(30);
		if(P3_2==1)
		{
		Key_KeyNumber=3;
		}
	}
	if(P3_3==0)
	{
		Delay(30);
		if(P3_3==0)
		{
		Key_KeyNumber=4;
		}
	}
}

void key_Loop2(void)// long press or not 
{  
	static unsigned char NowState,LastState;
	unsigned char i;
	LastState=NowState;	
	NowState=Key_GetState();
	
	for(i=1;i!=5;i++)
	{
		if(LastState==i&&NowState==i)
		{
			NowState==Key_GetState();
			if(NowState==i)
			{
				Key_KeyNumber=i;
				break;
			}
		}
	}
}

	
		

