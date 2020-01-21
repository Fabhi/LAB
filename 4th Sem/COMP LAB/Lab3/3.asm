;Program to add two 32 bit HEXADECIMAL numbers
Data Segment
num1 dD 12345678H
num2 dD 87654321H
sum dD 0H
carry dB 0H
Data ends

Code Segment
Assume CS:Code, DS:Data
Start:

MOV AX,Data
MOV DS,AX

LEA SI, num1
LEA DI, num2
LEA BX, sum 

CLC
MOV AL, [SI]
ADC AL, [DI]
MOV [BX], AL
INC SI
INC DI
INC BX
MOV AL, [SI]
ADC AL, [DI]
MOV [BX], AL
INC SI
INC DI
INC BX
MOV AL, [SI]
ADC AL, [DI]
MOV [BX], AL
INC SI
INC DI
INC BX
MOV AL, [SI]
ADC AL, [DI]
MOV [BX], AL
ADC carry, 0

MOV AH, 4CH
INT 21H

Code ends
End Start
