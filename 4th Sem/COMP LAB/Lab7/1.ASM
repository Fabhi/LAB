data segment
array db 12, 23, 34, 45, 56, 67, 78, 89, 90, 01
num db 67
yes db "found at : $"
no db "not found $"
data ends

code segment
assume cs:code, ds:data
start:
        mov ax, data
        mov ds, ax
        mov cl, 0AH

        lea si, array
        mov al, num
back:   cmp [si], al
        je exit
        inc si
        loop back
        lea dx, no
        mov ah, 09
        int 21h
        mov ah, 4ch
        int 21h
exit:
        lea dx, yes
        mov ah, 09
        int 21h

        mov dx, 0Ah
        sub dl, cl
        mov cl, dl
        add dl, 30H
        mov ah, 02h
        int 21h

        mov ah, 4ch
        int 21h
code ends
end start
