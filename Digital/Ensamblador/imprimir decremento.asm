;imprimir decremento
org 100h

mov dx, offset msg
mov ah, 9
int 21h

mov ah, 1
int 21h
sub al, 30h
mov decena, al

mov ah, 1
int 21h
sub al, 30h
mov unidad, al

call saltoLinea

cicloDecena:
    call imprimirNumero
    cmp decena, 0
    jne cicloUnidad
    cmp unidad, 0
    je fin
        
cicloUnidad:
    cmp unidad, 0
    je disminuirDecena 
    dec unidad
    jmp cicloDecena
    
    
disminuirDecena:
    dec decena
    mov unidad, 9
    jmp cicloDecena
    
    
fin:
    ret

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

imprimirNumero PROC
    mov dl, decena
    add dl, 30h ;quita esto si el registro tiene una 'A'
    mov ah, 02h
    int 21h
    
    mov dl, unidad
    add dl, 30h ;quita esto si el registro tiene una 'A'
    mov ah, 02h
    int 21h
    
    call saltoLinea
    ret
imprimirNumero ENDP
    

;Variables

msg db "Ingresa inicio cuenta: $"
decena db 0
unidad db 0