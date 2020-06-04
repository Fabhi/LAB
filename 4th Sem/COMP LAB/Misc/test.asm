DATA SEGMENT
     hex DW 1111H,2222H,3333H,4444H,5555,6666H,7777H,8888H,9999H,0ffffH		
     BCD  DD 10 DUP (?)
     max Dw ?
     mIN Dw ?	
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:  MOV AX,DATA
        MOV DS,AX
	    LEA SI,hex
        MOV AX,[SI]
        MOV Max,AX
        MOV Min,AX
        ADD SI,02H
        MOV CX,09H
        MOV BX,[SI]

        BACKS:  CMP [SI],AX
                JNC SMOL
                        MOV AX,[SI]

        SMOL:   ADD SI,02H
                LOOP BACKS

                MOV Min,AX

                MOV AX,hex
                MOV CX,09H
                LEA SI,hex
                ADD SI,02H

        BACKL:  CMP [SI],AX
                JC LORGE
                        MOV AX,[SI]

        LORGE:  ADD SI,02H
                LOOP BACKL

                MOV Max,AX     
    LEA DI,BCD
	lea si,hex
	MOV CX,0AH
loop1:	PUSH CX
        MOV AX,[SI]
        MOV CX,2
  BACK: MOV DX,0
        MOV BX,0AH
        DIV BX
        MOV [DI],DL
        MOV DX,0
        DIV BX
        PUSH CX
        MOV CX,4
        SHL DL,CL
        ADD [DI],DL
        POP CX
        INC DI
        LOOP BACK
        MOV [DI],AL
	POP CX
	inc di
	INC SI
	INC SI
	LOOP loop1
        MOV AH,4CH
        INT 21H
CODE ENDS
END START