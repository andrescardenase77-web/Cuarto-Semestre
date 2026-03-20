org 100h
;Elaborado por Nelson Andino y Andres Cardenas

mov dx, offset msgIngreso
mov ah, 9
int 21h

; Ingresamos las 4 letras

mov ah, 1
int 21h
mov letra1, al 

mov ah, 1
int 21h
mov letra2, al

mov ah, 1
int 21h
mov letra3, al

mov ah, 1
int 21h
mov letra4, al

call saltoLinea

; Imprimimos la palabra original
mov dx, offset msgOriginal
mov ah, 9
int 21h

call imprimirLas4Letras
call saltoLinea


;Ciclo de ordenamiento de las 4 letras
mov cx, 4 ;Contador del ciclo

cicloOrdenamiento:
    mov al, letra1
    cmp al, letra2
    ja cambiar1con2    ; Si letra1 > letra2 las intercambiamos
    jmp chequear2y3    ; Si no seguimos comparando

    cambiar1con2:
        mov bl, letra2     ; Guardamos la menor en bl temporalmente
        mov letra2, al     ; Realizamos el intercambio aprovechando que ya teniamos el 
        mov letra1, bl     ; mayor en al

    chequear2y3:
    mov al, letra2
    cmp al, letra3
    ja cambiar2con3
    jmp chequear3y4

    cambiar2con3:
        mov bl, letra3
        mov letra3, al
        mov letra2, bl

    chequear3y4:
    mov al, letra3
    cmp al, letra4
    ja cambiar3con4
    jmp finCiclo

    cambiar3con4:
        mov bl, letra4
        mov letra4, al
        mov letra3, bl

    finCiclo:
    loop cicloOrdenamiento


; Imprimimos la plabra ordenada
mov dx, offset msgOrdenado
mov ah, 9
int 21h

call imprimirLas4Letras

ret


; Funciones

imprimirLas4Letras PROC
    mov dl, letra1
    mov ah, 2
    int 21h
    

    mov dl, letra2
    int 21h

    mov dl, letra3
    int 21h

    mov dl, letra4
    int 21h
    ret
imprimirLas4Letras ENDP

saltoLinea PROC
    mov dl, 10
    mov ah, 2
    int 21h
    mov dl, 13
    mov ah, 2
    int 21h
    ret
saltoLinea ENDP

; Variables
msgIngreso   db "INGRESE 4 LETRAS MAYUSCULAS: $"
msgOriginal  db "ORIGINAL: $"
msgOrdenado  db "ORDENADO: $"
letra1 db 0
letra2 db 0
letra3 db 0
letra4 db 0