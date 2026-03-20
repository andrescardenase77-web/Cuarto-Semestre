org 100h
;main
inicio:
    mov bl, H
ciclo:
    dec bl
    mov dl, bl
    mov ah, 2
    int 21h
    jnz ciclo
    loop inicio
ret
;variables
H db 20


