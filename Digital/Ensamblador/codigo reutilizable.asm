
;Leer un numero
mov ah, 1
int 21h
sub al, 30h
mov numero, al ;guardas el numero

;Imprimir mensaje

mov dx, offset msg
mov ah, 9
int 21h

;Imprimir registro
mov dl, lo que quieres imprimir
add dl, 30h ;quita esto si el registro tiene una 'A'
mov ah, 2
int 21h

;Imprimir numero de 2 digitos
mov al, numero
mov ah, 0
mov bl, 10
div bl             ; AL=decena, AH=unidad
mov bx, ax         

mov dl, bl
add dl, 30h
mov ah, 2
int 21h             ;imprime decena

mov dl, bh
add dl, 30h
int 21h             ;imprime unidad

;Intercambiar 2 variables
mov al, variable1
mov bl, variable2
mov variable1, bl
mov variable2, al

;Funcion saltoLinea
saltoLinea PROC

    mov dl, 10

    mov ah, 2

    int 21h

    mov dl, 13

    mov ah, 2

    int 21h

    ret

saltoLinea ENDP 