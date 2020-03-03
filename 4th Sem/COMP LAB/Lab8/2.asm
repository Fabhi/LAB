Data Segment
Entry db 'Enter a 2 Digit HEX number $'
newline db 10 13 '$'
Data ends

Code Segment
Assume CS:Code, DS:Data
Start:
    MOV AX, Data
    MOV DS, AX
    MOV AH, 
