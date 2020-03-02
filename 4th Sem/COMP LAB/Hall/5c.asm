;Program to add two BCD bytes without using DAA

DATA    SEGMENT
        BCD1 DB 99H;
        BCD2 DB 95H;
        RES1 DB ?
        RES2 DB ?
DATA    ENDS

CODE    SEGMENT
        ASSUME CS:CODE, DS:DATA
START:  MOV AX, DATA
        MOV DS, AX
        MOV CX, 2H
        MOV DL, 00H; Contains the carry flag info
NIBB1:  MOV AL, BCD1
        MOV BL, BCD2
        AND AL, 00001111B  ; Extract first nibble
        AND BL, 00001111B
        ADD AL, BL
        CMP AL, 9H
        JG CORR
NIBB2:  PUSH AX;
        MOV AL, BCD1
        MOV BL, BCD2
        PUSH CX
        MOV CL, 04H
        SHR AL, CL
        SHR BL, CL
        POP CX
        ADD AL, BL
        ADD AL, DL
        MOV DL, 0H
        DEC CX
        CMP AL, 9H
        JG CORR
NIBB3:  PUSH AX
        MOV RES2, DL
        DEC CX
        JMP FINISH
CORR:   ADD AL, 06H;
        MOV DL, 01H
        CMP CX, 02H
        JE NIBB2
        CMP CX, 01H
        JE NIBB3
FINISH: POP AX
        PUSH CX
        MOV CL, 04H
        SHL AL, CL
        POP CX
        AND AL, 11110000B
        POP BX
        AND BL, 00001111B
        OR AL, BL
        MOV RES1, AL

        MOV AH, 4CH
        INT 21H
CODE    ENDS
        END START
        