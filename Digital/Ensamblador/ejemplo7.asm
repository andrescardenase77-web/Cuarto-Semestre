  include 'emu8086.inc'
  
org 100h
inicio:
    mov M,9
ciclo3:
    mov N,9
ciclo1:   
    dec N
    jz ciclo2
    loop ciclo1
ciclo2:
    dec M
    jz inicio
    loop ciclo3 
ret 
N db 0 
M db 0
