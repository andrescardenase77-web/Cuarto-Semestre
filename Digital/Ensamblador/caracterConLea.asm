org 100h
lea dx, msg
mov ah, 9
int 21h
ret
msg db "hello world $"


