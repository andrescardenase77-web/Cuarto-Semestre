org 100h
;main
mov bl, H
ciclo:
    dec bl
    mov dl, bl
    add dl, 30h ;tamb vale con 48 (asi, sin nada mas, solo 48)
    mov ah, 2
    int 21h
    loop ciclo
ret
;variab;es
H db 10