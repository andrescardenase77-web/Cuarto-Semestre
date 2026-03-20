#start=Traffic_Lights.exe#
name "traffic"
; Elaborado por Andres Cardenas, Nelson Andino
inicio:
    mov ax, all_red
    out 4, ax
    call espera

    mov ax, verde_vertical
    out 4, ax
    call espera

    mov ax, amarillo_vertical
    out 4, ax
    call espera

    mov ax, all_red
    out 4, ax
    call espera

    mov ax, verde_horizontal
    out 4, ax
    call espera

    mov ax, amarillo_horizontal
    out 4, ax
    call espera

    jmp inicio

espera:
    mov cx, 4Ch
    mov dx, 4B40h
    mov ah, 86h
    int 15h
    ret

verde_vertical      equ 0000_0010_0100_1001b 
amarillo_vertical   equ 0000_0010_1000_1010b
verde_horizontal    equ 0000_1000_0110_0001b
amarillo_horizontal equ 0000_0100_0101_0001b
all_red             equ 0000_0010_0100_1001b