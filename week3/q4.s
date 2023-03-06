    AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors 
	DCD 0x10001000 
	DCD Reset_Handler 
	ALIGN
	AREA mycode, CODE, READONLY
 ENTRY
	EXPORT Reset_Handler
Reset_Handler
    LDR R0,=NUM
	LDR R3,=result
	LDRB R1,[R0]
	AND R2,R1,#0X0F
	CMP R2,#09
	BLS DOWN1
	ADD R2,#07
DOWN1 ADD R2,#0X30
     STRB R2,[R3,#1]
	 AND R4,R1,#0XF0
	 MOV R4,R4,LSR#04
	 CMP R4,#09
	 BLS DOWN2
	 ADD R4,#07
DOWN2 ADD R4,#0X30
      STRB R4,[R3]
STOP B STOP
NUM DCD 0X0000003A
	AREA mydata, DATA, READWRITE
result DCD 0
	END