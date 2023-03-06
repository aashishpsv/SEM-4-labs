    AREA RESET, DATA, READONLY
	EXPORT __Vectors
		
__Vectors
	
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
	
Reset_Handler

	LDR r0,=input
	LDR r1,=result
	LDR r2,[r0]
	BL fact
	STR r2,[r1]
stop B stop
fact PUSH{r3,LR}
	MOV r3,r2
	CMP r2,#0
	BNE down1
	MOV r2,#1
	B down2
down1 SUB r2,#1
	BL fact
	MOV r4,r3
	MUL r2,r4
down2 POP{r3,LR}
	BX LR
	
input DCD 0x05
	AREA mydata, DATA, READWRITE
result DCD 0
	END