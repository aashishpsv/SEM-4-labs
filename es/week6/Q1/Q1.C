#include <LPC17xx.h>
unsigned int i,j; 
unsigned long LED = 0x00000010;
int main(void)
{
	unsigned long LED = 0x00000010;
 SystemInit(); //Add these two function for its internal operation
 SystemCoreClockUpdate();
 LPC_PINCON->PINSEL0 &= 0xFF0000FF;
 //Configure Port0 PINS P0.4-P0.11 as GPIO function
 LPC_GPIO0->FIODIR |= 0x00000FF0;
//Configure P0.4-P0.11 as output port 
 while(1)
 {
 for(LED=0;LED<=255;LED++)
	 { LPC_GPIO0->FIOPIN = LED<<4;
for(j=0;j<100000;j++);//a random delay
	 }
}
}
