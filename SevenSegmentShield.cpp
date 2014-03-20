#include "OneSheeld.h"
#include "SevenSegmentShield.h"

//setting the Seven Segment by sending the number from the user 
void SevenSegmentShieldClass::setNumber(byte x)
{
	byte data2[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x47,0x7F,0x6F};
	
	switch (x)
	{

		case 0 : setValue(data2[0]);break;
		case 1 : setValue(data2[1]);break;
		case 2 : setValue(data2[2]);break;
		case 3 : setValue(data2[3]);break;
		case 4 : setValue(data2[4]);break;
		case 5 : setValue(data2[5]);break;
		case 6 : setValue(data2[6]);break;
		case 7 : setValue(data2[7]);break;
		case 8 : setValue(data2[8]);break;
		case 9 : setValue(data2[9]);break;
	}

}


void SevenSegmentShieldClass::setValue(byte shape)
{

	OneSheeld.sendPacket(SEV_SEG_ID,0,SET_VALUE,1,new FunctionArg(1,&shape));

}


SevenSegmentShieldClass SevenSegment;