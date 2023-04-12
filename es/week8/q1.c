#include<LPC17xx.h>
#include "lcd.c"
#include<stdlib.h>

unsigned char msg1[13]="Dice Result";
unsigned char key;
unsigned int temp1;

int main(void)
{
	unsigned char k;
	lcd_init();
	temp1 = 0x80;
	lcd_comdata(0x80, 0);
	delay_lcd(800);
	lcd_puts(&msg1[0]);
	while(1)
	{
		
		if(!(LPC_GPIO2->FIOPIN & 1<<12))
		{
			k = (rand()%6)+1;
			k=k+0x30;
			temp1 = 0xc0;
			lcd_comdata(0xc0, 0);
			delay_lcd(800);
			lcd_puts(&k);
		}
	}
}
