Data Segment
    A dw 1234H
    B dw 2234H
    Sum dw ?
    Carry dB 00H
Data Ends

Code Segment
Assume CS:Code, DS: Data
Start:
        MOV AX, Data
        MOV DS, AX

        MOV AX, A
        ADD AX, B
        JNC Next
        INC Carry
Next:   MOV Sum, AX
   
INT 03H
Code Ends
End Start