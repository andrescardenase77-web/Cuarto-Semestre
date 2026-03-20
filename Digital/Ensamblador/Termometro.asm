#start=thermometer.exe#
;Elaborado por Nelson Andino y Andres Cardenas

org 100h

ciclo:
    in al, 125

    cmp al, 40
    jle encender

    cmp al, 60
    jge apagar

    jmp ciclo

encender:
    cmp estado, 1
    je ciclo

    mov dx, offset msgBajo
    mov ah, 9
    int 21h
    call saltoLinea

    mov al, 1
    out 127, al
    mov estado, 1
    jmp ciclo

apagar:
    cmp estado, 0
    je ciclo

    mov dx, offset msgAlto
    mov ah, 9
    int 21h
    call saltoLinea

    mov al, 0
    out 127, al
    mov estado, 0
    jmp ciclo
    
;Funciones
saltoLinea PROC
    mov dl, 10
    mov ah, 2
    int 21h
    mov dl, 13
    mov ah, 2
    int 21h
    ret
saltoLinea ENDP

;Variables
msgBajo db "El termometro llego a la temperatura mas baja, encendiendo la mecha$"
msgAlto db "El termometro llego a la temperatura mas alta, apagando la mecha$"
estado db 0