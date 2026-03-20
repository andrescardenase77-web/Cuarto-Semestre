;Elaborado por Andres Cardenas y Nelson Andino
; la suma de cuadrados debe ser de maximo 2 digitos
org 100h

mov dx, offset msgCantidad
mov ah, 9
int 21h

mov ah, 1
int 21h
sub al, 30h     
mov cl, al  ;aqui en cl esta el contador de cuantos numeros se ingresan
mov ch, 0   ;pongo 0 en ch para poder usar bien el contador       
call saltoLinea
ingresoSerie:
    mov dx, offset msgIngresarNum
    mov ah, 9
    int 21h ;mensaje de ingreso

    mov ah, 1
    int 21h
    sub al, 30h ;guardo en al el numero transformado a decimal     
     
    mul al      ; elevo al cuadrado           
    
    add suma, al 
    
    call saltoLinea
    
    loop ingresoSerie ; Repito el ciclo segun el numero de cx

;Impresion del resultado
mov dx, offset msgSuma
mov ah, 9
int 21h

mov ah, 0       
mov al, suma
mov bl, 10
div bl          ; en ax guardo la division de ax/10, en al va la decena y en ah la unidad
    
mov bx, ax      ; guardo los 2 digitos en bx
    
;Impresion de la decena
mov dl, bl      ;guardo la decena (numero) en dl
add dl, 30h     ;paso del numero a carcater 
mov ah, 2
int 21h         
    
;Impresion de la unidad
mov dl, bh      ; lo mismo pero uso bh
add dl, 30h
mov ah, 2
int 21h

ret


saltoLinea:
    mov ah, 2
    mov dl, 0Ah
    int 21h
    mov ah, 2
    mov dl, 0Dh
    int 21h
    ret

msgCantidad db "Ingrese la cantidad de numeros de la serie: $"
msgIngresarNum  db "Ingrese numero: $"
msgSuma  db "La suma de cuadrados es: $"
suma db 0