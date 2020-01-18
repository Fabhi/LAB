Data Segment
Array1 dW 1145H, 0B123H, 7956H, 2310H, 769AH
Array2 dW 5 dup (?)
Data ends

Code Segment
Assume CS:Code, DS:Data
Start:
MOV AX, Data
MOV DS, AX

LEA SI, Array1
LEA DI, Array2
MOV AX, [SI]
MOV [DI], AX

INC SI
INC DI
MOV AX, [SI]
MOV [DI], AX

INC SI
INC DI
MOV AX, [SI]
MOV [DI], AX

INC SI
INC DI
MOV AX, [SI]
MOV [DI], AX

INC SI
INC DI
MOV AX, [SI]
MOV [DI], AX

Code ends
end Start
