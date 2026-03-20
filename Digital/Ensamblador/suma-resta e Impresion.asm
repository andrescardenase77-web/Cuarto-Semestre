org 100h

mov al, num1     
mov bl, num2     


mov ah, 02h
mov dl, al
add dl, bl
add dl, 30h   
int 21h       


mov dl, 0Ah
int 21h


mov al, 5      
mov ah, 02h    
mov dl, al     
sub dl, bl      
add dl, 30h   
int 21h

num1 db 5
num2 db 3      

ret