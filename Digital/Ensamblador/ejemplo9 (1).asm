  include 'emu8086.inc'
  
org 100h
inicio:
    mov M,9
ciclo2:
    mov N,9
ciclo1:   

    mov dl, M
    add dl,'0'   ;ASCII
    mov ah, 2 
    int 21h
    mov dl, N
    add dl,48    ;valor decimal ASCII 0
    mov ah, 2 
    int 21h
    mov dl,10
    mov ah, 2 
    int 21h
    mov dl,13
    mov ah, 2 
    int 21h
    
    dec N
    jnz ciclo1
    mov dl, M
    add dl,48
    mov ah, 2 
    int 21h
    mov dl, N
    add dl,48
    mov ah, 2 
    int 21h
    mov dl,10
    mov ah, 2 
    int 21h
    mov dl,13
    mov ah, 2 
    int 21h
    dec M
    cmp M,0FFh
    jnz ciclo2
    loop inicio 
ret 
N db 0 
M db 0    



