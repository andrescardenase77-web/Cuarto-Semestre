;imprimir secuencia de numeros pares de 2 digitos
mov dx, offset msg
mov ah, 9
int 21h

;aqui quiero complicar un poco el calculo de los datos
mov ah, 1
int 21h
sub al, 30h

mov ah, 0
mov bl, 10
mul bl
mov num, al

mov ah, 1
int 21h
sub al, 30h
add num, al

call saltoLinea

esPar:
    mov ah, 0
    mov al, num
    mov bl, 2
    div bl
    cmp ah, 0
    je ciclo
    dec num
ciclo:
      call imprimirNumero
      sub num, 2
      cmp num, 0
      jge ciclo
ret




imprimirNumero PROC
    mov ah, 0
    mov al, num
    mov bl, 10
    div bl
    
    mov bx, ax
    
    mov dl, bl
    add dl, 30h
    mov ah, 02h
    int 21h
    
    mov dl, bh
    add dl, 30h
    mov ah, 02h
    int 21h
    
    call saltoLinea    
    ret
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


msg db "Ingresa numero: $"
num db 0