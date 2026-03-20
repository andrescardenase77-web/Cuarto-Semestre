  include 'emu8086.inc'
  
org 100h
inicio:
    mov M,9
ciclo2:
    mov N,9
ciclo1:   
    dec N
    jnz ciclo1
    dec M
    jnz ciclo2
    loop inicio 
ret 
N db 0 
M db 0
