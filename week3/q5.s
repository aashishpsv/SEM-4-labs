    AREA  RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors
 
    DCD 0X10001000 
    DCD Reset_Handler 
    ALIGN
    AREA mycode, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler
Reset_Handler
    LDR R0,=NUM1
    LDR R3,=NUM2
    LDR R1,=DST
    LDR R2,[R0]
    LDR R4,[R3]
    MOV R5,R2,LSL#4
    ORR R6,R5,R4
    STR R6,[R1]
STOP B STOP

NUM1 DCD 4
NUM2 DCD 6
    AREA mydata,DATA,READWRITE
DST DCD 0
    END

