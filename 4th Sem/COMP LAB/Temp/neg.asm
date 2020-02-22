Data Segment
num1 dB 25H
num2 dB 10
res dW ?
Data ends

Code Segment
Assume CS:Code, DS:Data
Start:
    MOV AX, Data
    MOV DS, AX
    MOV CH, 0
    MOV CL, NUM2
    MOV AX, 0
BACK:
    ADD AL, NUM1
    DAA
    ADC AH, 0
    DAA
    LOOP BACK
    mov res, AX
    
    MOV AH, 4CH
    INT 21H

Code ends
end start