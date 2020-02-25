Data segment
array dw 1112h, 2343h, 2311h, 4322h, 5346h, 6785h, 9767h, 9463h, 9865h, 2323h
num dw 2311h;
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
        mov ax, num

back:   cmp [si], ax
        je exit
        inc si
        inc si
        loop back

        lea dx, no
        mov ah, 09
        int 21h

        mov ah, 4ch
        int 21h

exit:   lea dx, yes
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
