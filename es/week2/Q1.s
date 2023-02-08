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
     MOV R1, #10
	 LDR R2, =SRC
	 LDR R3, =DST
LOOP LDR R4, [R2], #4
     ADD R5, R4
	 SUBS R1, #1
	 BNE LOOP
	 
	 STR R5, [R3]
STOP B STOP
SRC DCD 1,2,3,4,5,6,7,8,9,10
    AREA mydata, DATA, READWRITE	
DST DCD 0 ;DST location in data memory
	END