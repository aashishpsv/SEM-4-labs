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
    LDR R0,=num1
	LDR R1,=num2
	LDR R6,=result
	LDR R2,[R0]
	LDR R3,[R1]
	MOV R4,#0
loop  CMP R2,R3
	BCC over
	SUB R2,R3
	ADD R4,#1
	B loop
over 	STR R4,[R6],#4
		STR R2,[R6]
STOP B STOP
num1 DCD 20
num2 DCD 3

	AREA mydata, DATA, READWRITE
result DCD 0,0
		
	END