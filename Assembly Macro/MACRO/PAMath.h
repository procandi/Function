sum macro num1,num2
	local c
	push ax
	push dx
	
	mov dl,c
	mov ah,02h
	int 21h
	
	pop ax
	pop dx
endm