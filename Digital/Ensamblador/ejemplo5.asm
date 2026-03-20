  include 'emu8086.inc'
  
org 100h
inicio: 
    mov bl,N
ciclo:
    dec bl
    jnz ciclo
    loop inicio 
ret 
N db 20
