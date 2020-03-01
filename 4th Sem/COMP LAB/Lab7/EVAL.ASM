Data Segment
array db -10H, 1H ,8H, -3H, 4H, 15H, 6H, 1H, 4H, 6H
sum db 2 dup(?)
Data ends

Code Segment
Assume CS:Code, DS:Data
Start:
    MOV AX, Data
    MOV DS, AX

    MOV CX, 0AH;
    MOV AX, 0H
    LEA SI, array
BACK:
    MOV BL, [SI]
    CMP BL, 0H
    JLE NEXT
    ADD AL, [SI]
    DAA
    xchg ah, al
    ADC Al, 0H
    DAA
    xchg ah, al
NEXT:
    INC SI
    LOOP BACK

    MOV SUM , AL
    MOV SUM+1, AH
    MOV AH, 4CH
    INT 21H

CODE ends
END Start
