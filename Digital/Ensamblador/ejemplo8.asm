  include 'emu8086.inc'
  
org 100h
inicio:
mov M,9
ciclo2:
    mov N,9
ciclo1:   
    dec N
    mov dl, N
    mov ah, 6 
    int 21h
    jnz ciclo1
    dec M
    mov dl, M
    mov ah, 6 
    int 21h
    jnz ciclo2
    loop inicio 
ret 
N db 9 
M db 9    



