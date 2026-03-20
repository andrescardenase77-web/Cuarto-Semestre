;tabla del 2 hasta el 8
org 100h

mov bl, 2
mov cl, 4
mov ch, 0
ciclo:
    mov dl, bl
    mov ah, 02h
    add dl, 30h
    int 21h
    add bl, 2
    call saltoLinea
    loop ciclo
ret    




saltoLinea PROC
    mov dl, 10

    mov ah, 2

    int 21h

    mov dl, 13

    mov ah, 2

    int 21h

    ret
saltoLinea ENDP
