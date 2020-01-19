Data Segment
Array1 dB 45H, 0B1H, 79H, 10H, 9AH
Array2 dB 5 dup (?)
Data ends

Code Segment
Assume CS:Code, DS:Data
Start:
MOV AX, Data
MOV DS, AX

LEA SI, Array1
LEA DI, Array2
MOV AL, [SI]
MOV [DI], AL

INC SI
INC DI
MOV AL, [SI]
MOV [DI], AL

INC SI
INC DI
MOV AL, [SI]
MOV [DI], AL

INC SI
INC DI
MOV AL, [SI]
MOV [DI], AL

INC SI
INC DI
MOV AL, [SI]
MOV [DI], AL

Code ends
end Start
