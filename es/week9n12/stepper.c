#include <LPC17xx.H>
void clock_wise(void);
void anti_clock_wise(void);
unsigned long int var1,var2;
unsigned int i=0,j=0,k=0;
int main(void)
{
SystemInit();
SystemCoreClockUpdate();
	
LPC_PINCON->PINSEL0 = 0xFFFF00FF; //P0.4 to P0.7 GPIO
LPC_GPIO0->FIODIR = 0x000000F0; //P0.4 to P0.7 output
	
LPC_PINCON->PINSEL4 &= 0XFCFFFFFF;
	LPC_GPIO2->FIODIR |= 0X0;
while(1)
{
	if(LPC_GPIO2->FIOPIN & 1<<12)
	{ for(j=0;j<50;j++) 
        {  anti_clock_wise();
				  if(!(LPC_GPIO2->FIOPIN & 1<<12)){break;}}
				//for(k=0;k<65000;k++); 
	}
	
if(!(LPC_GPIO2->FIOPIN & 1<<12)){for(j=0;j<50;j++) 
{clock_wise();
 if((LPC_GPIO2->FIOPIN & 1<<12)){break;} }
	
//for(k=0;k<65000;k++); 
	}
	

}
}

void clock_wise(void)
{
var1 = 0x00000008; //For Clockwise
 for(i=0;i<=3;i++) // for A B C D Stepping
{
var1 = var1<<1; //For Clockwise
 LPC_GPIO0->FIOPIN = var1;
 
 for(k=0;k<3000;k++); //for step speed variation 
 }
}
void anti_clock_wise(void)
{
var1 = 0x00000100; //For Anticlockwise
 for(i=0;i<=3;i++) // for A B C D Stepping
 {
 var1 = var1>>1; //For Anticlockwise
 LPC_GPIO0->FIOPIN = var1;
 
 for(k=0;k<3000;k++); //for step speed variation 
 }
 }