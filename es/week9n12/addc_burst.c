#include <LPC17xx.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "lcd_display.c"
unsigned char str[]={"0123456789"};
unsigned long x;
float t1=0,t2=0;
unsigned char vtg1[7],vtg2[7];
int main(void)
{
    
    lcd_init();
    LPC_PINCON->PINSEL3=(0xF)<<28; //P1.30 as AD0.4 and P1.31 as AD0.5
    LPC_SC->PCONP |=(1<<12);
    LPC_ADC->ADCR = (1 << 4 | 1 << 5 | 1 << 16 | 1 << 21);
    LPC_ADC->ADINTEN = (1<<4|1<<5);
    NVIC_EnableIRQ(ADC_IRQn);
    while(1);
}
void ADC_IRQHandler(void)
{x=LPC_ADC->ADSTAT&(3<<4);
 
    if(x>>4 & 1) {
        t1 = (LPC_ADC->ADDR4>>4)&0xFFF;
        t1 = (float)((t1*3.3)/4096);
        sprintf(vtg1,"%3.2fV",t1);
      lcd_comdata(0x80,0);
      delay_lcd(800);
      lcd_puts(&vtg1[0]);
    } if(x>>5 & 1){
        t2 = (LPC_ADC->ADDR5>>4)&0xFFF;
        t2 = (float)((t2*3.3)/4096);
      sprintf(vtg2,"%3.2fV",t2);
      lcd_comdata(0xc0,0);
      delay_lcd(800);
      lcd_puts(&vtg2[0]);
    }
}