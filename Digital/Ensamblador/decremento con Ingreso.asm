org 100h 
; Elaborado por Andres Cardenas y Nelson Andino

inicio:
    mov dx, offset msgIngreso
    mov ah, 9
    int 21h

    ; Leemos la decena
    mov ah, 1
    int 21h
    sub al, 30h   
    mov decena, al

    ; Leemos la Unidad
    mov ah, 1
    int 21h
    sub al, 30h          
    mov unidad, al
    call saltoLinea

cicloDecena:
    cmp unidad, 0
    je imprimirCeroUnidad

cicloUnidad: 
    call imprimirNumero

    dec unidad      
    jnz cicloUnidad ;

imprimirCeroUnidad:
    call imprimirNumero
    dec decena
    cmp decena, 0FFh
    je fin
    mov unidad, 9   
    jnz cicloDecena

fin:
    ret

;Funciones
imprimirNumero:
    ; Imprimimos la decena
    mov dl, decena
    add dl, 30h          
    mov ah, 2
    int 21h

    ; Imprimimos la unidad
    mov dl, unidad
    add dl, 30h          
    mov ah, 2
    int 21h
    
    call saltoLinea
    ret

saltoLinea:
    mov dl, 10           
    mov ah, 2
    int 21h
    mov dl, 13           
    mov ah, 2
    int 21h
    ret

;Variables
msgIngreso db "Inicio cuenta: $"
decena    db 0
unidad    db 0