;Objetivo: Pedir al usuario un número
; del 0 al 9 (una nota).

;Si el número es mayor o igual a 7, 
;imprimir "P" (Pasó).

;Si el número es menor a 7, imprimir 
;"R" (Reprobó).

org 100h

mov dx, offset msg_solicitud
mov ah, 9
int 21h

mov ah, 1
int 21h
sub al, 30h
mov nota, al
call saltoLinea

cmp nota, 7
jge mensajeMayor
jmp mensajeMenor
ret

mensajeMayor:
    mov dl, 'P'
    mov ah, 02h
    int 21h
    ret
    
mensajeMenor:
    mov dl, 'R'
    mov ah, 02h
    int 21h
    ret
    
;funciones

saltoLinea PROC

    mov dl, 10

    mov ah, 2

    int 21h

    mov dl, 13

    mov ah, 2

    int 21h

    ret

saltoLinea ENDP




;variables
msg_solicitud db "Ingresa tu nota: $"
nota db 0