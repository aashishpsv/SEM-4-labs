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
    LDR R0,=source
	LDR R1,=result
	MOV R2,#0
	LDR R3,[R0]
	MLA R2,R3,R3,R3
	LSR R2,#1
	STR R2,[R1]
STOP B STOP
source DCD 3
	AREA mydata, DATA, READWRITE
result DCD 0
	END