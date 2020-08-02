Printstr MACRO msg
    LEA DX, msg
    mov AH, 09H
    INT 21H
ENDM

Data Segment
    Buffer dB 20H
    len dB ?
    string dB 20 dup (?)
    Yes db "Palindrome $"
    No db "Not Palindrome $"
    newline db 10,13,"$"
Data Ends

Code Segment
Assume CS:Code, DS: Data
Start:
        MOV AX, Data
        MOV DS, AX
        MOV ES, AX
        LEA SI, string
        LEA DI, string

        LEA DX, Buffer
        MOV AH, 0AH
        INT 21H
        MOV CH, 00H
        MOV CL, LEN
        ADD DI, CX
        MOV BYTE PTR[DI], '$'
        DEC DI
        SHR CX, 1
        Printstr newline
BACK:   CLD
        CMPSB
        JNE NEXT
        DEC DI
        DEC DI
        LOOP BACK 
        Printstr Yes
        JMP EXIT
NEXT:   Printstr No
EXIT:   MOV AH, 4CH
        INT 21H
Code Ends
End Start
this code has bene desdasd