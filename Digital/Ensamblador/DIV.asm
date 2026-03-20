
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV AL, dato_a

MOV BL, dato_b 

DIV BL     ; En este caso Divide AX con BL, resultado en AX

MOV entero, AL
MOV residuo, AH

CALL decimales
CALL impresion    
 
ret
 
impresion PROC 
    MOV AL, entero
    MOV AH, 0
    MOV BL, 10
    DIV BL        ;realiza la division entre AX y BL
    MOV decenas, AL
    MOV unidades, AH   
    
    ;imprime mensaje
    lea dx, msg 
    mov ah, 9 
    int 21h 
    ;imprime decenas
    mov ah, 2
    mov dl,decenas
    add dl,30h
    int 21h
    ; imprime unidades
    mov ah, 2
    mov dl,unidades
    add dl,30h
    int 21h
    ; imprime coma
    mov ah, 2
    mov dl,','
    int 21h
    ; imprime decimal
    mov ah, 2
    mov dl,decimal
    add dl,30h
    int 21h
    
    
    ret  
impresion ENDP

decimales PROC
    push ax
    push bx
    MOV AL, residuo
    MOV BL, 10
    MUL BL
    
    MOV BL, dato_b
    DIV BL
    
    MOV decimal, AL
    MOV residuo2, AH
    pop bx
    pop ax
    RET     ; return to caller.
decimales ENDP  

msg db "La respuesta es $" 
dato_a db 90
dato_b db 7
resp db 0
entero db 0
residuo db 0
decimal db 0
residuo2 db 0 
decenas db 0
unidades db 0