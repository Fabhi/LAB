Code Segment
sum dW 0H
carry dW 0H
Code ends

Data Segment
Assume CS:Code, DS:Data
Start:

MOV AX,Data
MOV DS,AX

MOV AX, 1234H
MOV BX, 2345H

CLC
ADC AX, BX
MOV sum, AX
ADC carry, 0

MOV AH, 4CH
INT 21H

Code ends
End Start