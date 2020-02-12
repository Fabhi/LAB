;PROGRAM TO ADD 10 4-DIGIT DECIMAL NUMBERS STORED IN DS AND STORE THE RESULT IN DS
Data Segment
arr dW 1111H, 2222H, 3333H, 4444H, 5555H, 6666H, 7777H, 8888H, 9999H, 1111H
sum dW 0000H
carry dB 00H
Data ends

Code Segment
Assume CS:Code, DS:Data
Start:
        MOV AX, Data
        MOV DS, AX
        LEA SI, arr
        MOV CX, 10
        MOV AX, 0H ;STORING SUM IN AX
        MOV DL, 0H ;STORING CARRY IN DL
        CLC

BACK:   
        MOV BL, [SI]
        ADD AL, BL
        DAA
        XCHG AL, AH

        MOV BL, [SI+1]
        ADC AL , BL
        DAA
        XCHG AL , AH

        ADC DL, 0
        INC SI
        INC SI
        CLC

        LOOP BACK

        MOV SUM, AX
        MOV CARRY, DL

        MOV AH, 4CH
        INT 21H
CODE ENDS
END START
