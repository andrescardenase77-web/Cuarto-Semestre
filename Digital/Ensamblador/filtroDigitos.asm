; Elaborado por Andres Cardenas, Nelson Andino 

org 100h

    mov dx, offset msgentrada
    mov ah, 9
    int 21h

    mov si, offset entrada
    mov di, offset salida

leer_cadena:
    mov ah, 1
    int 21h
    cmp al, 0Dh        
    je fin_lectura   ; Al presionar ENTER finalizar

    mov [si], al
    inc si
    jmp leer_cadena

fin_lectura:
    mov [si], 0        ; Marca final de cadena

    ; Filtrar solo digitos en el arreglo entrada -> salida
    mov si, offset entrada
    mov di, offset salida

filtrar_digitos:
    mov al, [si]
    cmp al, 0
    je mostrar

    cmp al, 48          ; 48 es el codigo ASCII de '0'
    jb sig              ; menor que '0' (no es digito)
    cmp al, 57          ; 57 es el codigo ASCII de '9'
    ja sig              ; mayor que '9' (no es dígito)
    mov [di], al        ; es digito (48 <= al <= 57)
    inc di

sig:
    inc si
    jmp filtrar_digitos

mostrar:
    mov [di], '$'       ; Fin para mostrar con "int 21h, ah=9"
    mov dx, offset msgfinal
    mov ah, 9
    int 21h

    mov dx, offset salida
    mov ah, 9
    int 21h

    mov ah, 4ch
    int 21h

msgentrada db 'Ingrese una cadena y finalice con ENTER:$'
msgfinal db 0dh,0ah, 'Solo los digitos: $'
entrada db 100 dup(0)
salida db 100 dup(0)