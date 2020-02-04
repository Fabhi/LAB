Data Segment
arr dW 1111H, 2222H, 3333H, 4444H, 5555H, 6666H, 7777H, 8888H, 9999H, 0AAAAH
sum dW 0000H
carry dB 00H
Data ends

Code Segment
Assume CS:Code, DS:Data
Start:
        MOV AX, Data
        MOV DS, AX
        LEA SI, arr
        LEA DI, sum
        MOV CH, 00H
        MOV CL, 05H
        CLC

BACK:   MOV AL, [SI]
        MOV BL, [SI+2]
        ADD AL, BL
        DAA
        ADD [DI], AL
        MOV AL, [SI+1]
        MOV BL, [SI+3]
        ADC AL, BL
        DAA
        ADD [DI+1], AL
        ADC CARRY, 0
        CLC
        LOOP BACK
        MOV AH, 4CH
        INT 21H
CODE ENDS
END START
