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
	
	LDR R6,=RESULT
	MOV R2,#00
	LDR R0,=VALUE1
	LDR R1,[R0]
up	CMP R1,#0xA
	BCC store
	SUB R1,#0xA
	ADD R2,#01
	B up
store STRB R1,[R6],#1
    MOV R1,R2
	MOV R2,#0
	CMP R1,#0xA
	BCS up
	STRB R1,[R6]
	MOV R3,R6
	LDR R2,=packed
	LDR R6,=RESULT
	ADD R2,#10
	SUB R4,R3,R6
up1	LDRB R0,[R6],#1
	LDRB R1,[R6],#1
	LSL R1,#4
	ORR R1,R0
	STRB R1,[R2],#1
	SUB R4,#1
	CMP R4,#2
	BCS up1
STOP B STOP
VALUE1 DCD 0xF
	AREA mydata, DATA, READWRITE
RESULT DCD 0
packed DCD 0
	END