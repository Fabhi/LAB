Data Segment
    Hexa dB ?
    Sum dB 00H
    New dB 10, 13, "$"
Data Ends

Code Segment
Assume CS:Code, DS: Data
Start:
        MOV AX, Data
        MOV DS, AX

        MOV AH, 01
        INT 21H

        SUB AL, 30H
        CMP AL, 0AH
        JC DOWN
        SUB AL, 07H
DOWN:   
        MOV BL, 10H
        MUL BL
        MOV BL, AL

        MOV AH, 01H
        INT 21H
        SUB AL, 30H
        CMP AL, 0AH
        JC DOWN1
        SUB AL, 07H

DOWN1:
        ADD AL, BL
        MOV Hexa, AL

        MOV CX, 08H
BACK:   
        SHL AL, 01H
        ADC Sum, 00H
        LOOP BACK

        LEA DX, New
        MOV AH, 09H
        INT 21H

        ADD Sum, 30H
        MOV DL, Sum
        MOV AH, 02H
        INT 21H

        MOV AH, 4CH
        INT 21H
Code Ends
End Start