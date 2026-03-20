;Elaborado por Andres Cardenas y Nelson Andino

org 100h

mov dx, offset msgResultado
mov ah, 9
int 21h

mov al, dividendo   
mov ah, 0           
mov bl, divisor     
div bl              
                    

mov cl, ah      ;guardamos en cl el residuo        

mov dl, al          
add dl, 30h         
mov ah, 2
int 21h         ;imprime la parte entera    


mov dl, ','        
mov ah, 2
int 21h          



mov al, cl         
mov bl, 10      
mul bl              
                  ;calculo la parte decimal 

mov bl, divisor     
div bl               
                    


mov dl, al          
add dl, 30h         
mov ah, 2          ;imprime la parte decimal
int 21h             

ret                 

;Variables
dividendo db 9      
divisor   db 2

; Mensajes
msgResultado db "El resultado es: $"