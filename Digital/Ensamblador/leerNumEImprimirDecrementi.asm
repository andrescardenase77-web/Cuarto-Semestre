org 100h

; 1. PREPARACIÓN: Separar el número inicial

mov dx, offset msg
mov ah, 9
int 21h

mov ah,1
int 21h 
sub al,30h
mov decena, al

mov ah,1
int 21h 
sub al,30h
mov unidad, al

call saltoLinea


ciclo:
    call imprimirNumero
    
    ; ¿Es el número 00? Si es así, terminamos
    cmp decena, 0
    jne continuar   ; Si decena > 0, aún no terminamos
    cmp unidad, 0
    je fin          ; Si decena es 0 Y unidad es 0, fin.

continuar:
    ; Lógica de resta (como un reloj)
    cmp unidad, 0
    je restarDecena ; Si la unidad es 0, hay que pedir prestado a la decena
    
    dec unidad      ; Si no es 0, solo restamos a la unidad
    jmp ciclo

restarDecena:
    mov unidad, 9   ; Reiniciamos unidad a 9
    dec decena      ; Bajamos una decena
    jmp ciclo

fin:
    ret

; --- FUNCIONES ---
imprimirNumero PROC
    mov dl, decena
    add dl, 30h
    mov ah, 02h
    int 21h
    
    mov dl, unidad
    add dl, 30h
    int 21h
    
    call saltoLinea
imprimirNumero ENDP


saltoLinea PROC

    mov dl, 10

    mov ah, 2

    int 21h

    mov dl, 13

    mov ah, 2

    int 21h

    ret

saltoLinea ENDP

decena db 0
unidad db 0
msg db "Ingresa el numero: $"