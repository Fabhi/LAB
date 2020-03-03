Data Segment
cr db 10
lf db 13
Data ends

Code Segment
Assume CS:Code, DS:Data
Start:
    MOV AX, Data
    MOV DS, AX

    MOV AH, 01H ;Read with echo to AL
    INT 21H
    PUSH AX

    MOV DL, cr
    MOV AH, 02H ;Print from DL
    INT 21H

    MOV DL, LF
    MOV AH, 02H ;Print from DL
    INT 21H

    POP AX
    MOV DL, AL
    MOV AH, 02H ;Print from DL
    INT 21H

    MOV AH, 08H ;Read without echo to AL
    INT 21H
    PUSH AX
    
    MOV DL, cr
    MOV AH, 02H ;Print from DL
    INT 21H

    MOV DL, LF
    MOV AH, 02H ;Print from DL
    INT 21H

    POP AX
    MOV DL, AL
    MOV AH, 02H ;Print from DL
    INT 21H

    MOV AH, 4CH
    INT 21H
code ends
end start