
  
org 100h

; Mensaje
mov dx, offset msg1 
mov ah, 9 
int 21h

;lectura primer numero
mov ah,1
int 21h 
sub al,30h
mov num1,al
;salto de linea
mov ah, 2
mov dl,0Ah
int 21h
;retorno inicio de linea
mov ah, 2
mov dl,0Dh
int 21h

; Mensaje
mov dx, offset msg2 
mov ah, 9 
int 21h

;lectura segundo numero
mov ah,1
int 21h 
sub al,30h
mov num2,al

cmp num1, al
je igual
jg mayor
jl menor

igual:
    mov dx, offset msgigual 
    mov ah, 9 
    int 21h
    loop  fin
mayor:
    mov dx, offset msgmayor 
    mov ah, 9 
    int 21h
    loop  fin 
menor:
    mov dx, offset msgmenor
    mov ah, 9 
    int 21h
fin:
ret

msg1 db "Ingrese el numero 1: $"
msg2 db "Ingrese el numero 2: $"
msgigual db 0ah, 0dh,"Los numeros son iguales $"
msgmayor db 10, 13, "El numero 1 es mayor que el numero 2 $"
msgmenor db 10, 13, "El numero 1 es menor que el numero 2 $"
num1 db 0
num2 db 0