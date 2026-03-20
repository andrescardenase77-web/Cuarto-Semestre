org 100h    

mov bl,N
ciclo:
    dec bl
    mov dl,bl
    add dl,30h
    mov ah, 02h 
    int 21h
    loop ciclo 
ret 
N db 10
