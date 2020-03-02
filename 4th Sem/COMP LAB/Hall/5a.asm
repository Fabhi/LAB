; Program to add two BCD bytes using DAA and store the result in two consecutive bytes 
DATA    SEGMENT
        NUM1 DB 99H
        NUM2 DB 95H
        RES1 DB ?
        RES2 DB ?
DATA    ENDS

CODE    SEGMENT
        ASSUME CS:CODE, DS:DATA
START:  MOV AX, DATA
        MOV DS, AX
        
        ;Add the two numbers and store in RES1
        MOV AL, NUM1
        MOV BL, NUM2
        ADD AL, BL
        DAA
        MOV RES1, AL
        
        ;Store the carry in RES2
        MOV BL, 00H
        ADC BL, 0H
        DAA
        MOV RES2, BL

        MOV AH, 4CH
        INT 21H
CODE    ENDS
        END START

