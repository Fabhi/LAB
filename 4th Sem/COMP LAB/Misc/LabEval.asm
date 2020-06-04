
Data Segment
    hex dW 1111H, 2222H, 3333H, 4444H, 5555H, 6666H, 7777H, 8888H, 9999H, 0AAAAH
    decimal dd 10 dup (?)
    max dw ?
    min dw ?
Data Ends

Stack Segment
    dW 100 dup(?)
    TOS Label Word
Stack ends

Code Segment
Assume CS:Code, DS: Data
Start:
        MOV AX, Data
        MOV DS, AX

        LEA SI,hex
        MOV AX,[SI]
        MOV Max,AX
        MOV Min,AX
        ADD SI,02H
        MOV CX,09H
        MOV BX,[SI]

BACK:  CMP [SI],AX
        JNC SMALL
        MOV AX,[SI]

SMALL:   ADD SI,02H
        LOOP BACK

        MOV Min,AX

        MOV AX,hex
        MOV CX,09H
        LEA SI,hex
        ADD SI,02H

BACK1:  CMP [SI],AX
        JC LARGE
        MOV AX,[SI]

LARGE:  ADD SI,02H
        LOOP BACK1
        MOV Max,AX     


        LEA SI, hex
        LEA DI, decimal
        MOV CX, 0AH
NEXT:   MOV AX, [SI] ;AX <- Hex number
        PUSH CX
        CALL CONVERT
        INC SI
        INC SI
        INC DI
        POP CX
        LOOP NEXT
        MOV AH, 4CH
        INT 21H        

CONVERT PROC
        MOV CX,2
  BACK2: MOV DX,0
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
        LOOP BACK2
        MOV [DI],AL
CONVERT ENDP

Code Ends
End Start