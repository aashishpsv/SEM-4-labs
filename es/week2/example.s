    AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors 
	DCD 0x10001000 ; stack pointer value when stack is empty
	DCD Reset_Handler ; reset vector
	ALIGN
	AREA mycode, CODE, READONLY
ENTRY
	EXPORT Reset_Handler
Reset_Handler
    LDR R0, =VALUE1
	LDR R1, [R0]
	LDR R0, =VALUE2
	LDR R3, [R0]
	ADDS R6, R1, R3
	LDR R2, =RESULT
	STR R6, [R2]
STOP B STOP
VALUE1 DCD 0X12345678
VALUE2 DCD 0XABCDEF12
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END