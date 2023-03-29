#include <LPC17xx.h>
unsigned int i,l,j,c=0;
int main(void)
{
	unsigned long LED = 0x00000010;
	LPC_PINCON->PINSEL0 &= 0XFF0000FF;
	LPC_GPIO0->FIODIR |= 0X00000FF0;
	LPC_PINCON->PINSEL4 &= 0XFCFFFFFF;
	LPC_GPIO2->FIODIR |= 0X0;
	while(1)
	{
		if(LPC_GPIO2->FIOPIN & 1<<12){
			for(LED=0;LED<=255;LED++){
				LPC_GPIO0->FIOPIN = LED<<4;
         for(j=0;j<100000;j++);//a random delay
				if(!(LPC_GPIO2->FIOPIN & 1<<12))
				break;
	 }
   }
		else
			{for(LED=255;LED>=0;LED--)
	 { LPC_GPIO0->FIOPIN = LED<<4;
      for(j=0;j<100000;j++);//a random delay
		  if(LPC_GPIO2->FIOPIN & 1<<12)
			break;
	 }}
	
}
}