Data Segment
BCD dW 1234H
HEX dW ?
Data ends

Code Segment
Assume CS:Code, DS:Data

HexConvert PROC  ; Converts BCD Stored in AL Register to its HEX Equivalent
    MOV CL,4
    SHR AL,CL ; EXTRACT MSD
    MOV CL, 0AH 
    MUL CL ; MULTIPLY MSD BY 10

    MOV BL, 
    RET
HexConvert ENDP
Start:
	MOV AX, Data
	MOV DS, AX
	MOV AX, BCD     ; AX <- 1234H
	MOV CL, 4
    SHR AL, CL
    CALL HexConvert     ; WORKING ON AL
    XCHG AH, AL     ; 
    MOV 
    MOV AH, 4CH
	INT 21H
Code ends
end start	