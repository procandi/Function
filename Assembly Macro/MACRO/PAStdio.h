putchar macro c
	push ax
	push dx
	
	mov dl,c
	mov ah,02h
	int 21h
	
	pop ax
	pop dx
endm

getchar macro c
	push ax
	push dx
	
	mov ah,01h
	int 21h
	
	mov c,al
	
	pop ax
	pop dx
endm

write macro wd
	push ax
	push dx
	
	mov dx,offset wd	;怕會有問題，所以加上offset
	mov ah,09h
	int 21h
	
	pop ax
	pop dx
endm

read macro wd
	local next,exit
	push ax
	push cx
	push dx
	push si

	lea si,wd		;將si指到wd的記憶體位址
next:
	mov ah,01h
	int 21h
	
	cmp al,20h		;當發現使用者輸入的是一個space字元後就跳開迴圈
	je exit
	mov [si],al		;將si所指的記憶體位址的空間放入輸入的字元
	inc si			;指到下一個位址
	jmp next		;回去接收下一個字
exit:
	mov [si],'$'		;在最後面加上一個字串結束符號
	
	pop ax
	pop cx
	pop dx
	pop si
endm

writeln macro wd
	push ax
	push dx
	
	mov dx,offset wd	;怕會有問題，所以加上offset
	mov ah,09h
	int 21h
	
	mov dl,13
	mov ah,02h
	int 21h
	
	mov dl,10
	mov ah,02h
	int 21h
	
	pop ax
	pop dx
endm

readln macro wd
	local next,exit
	push ax
	push cx
	push dx
	push si

	lea si,wd		;將si指到wd的記憶體位址
next:
	mov ah,01h
	int 21h
	
	cmp al,0dh		;當發現使用者輸入的是一個'\n'字元後就跳開迴圈
	je exit
	mov [si],al		;將si所指的記憶體位址的空間放入輸入的字元
	inc si			;指到下一個位址
	jmp next		;回去接收下一個字
exit:
	mov [si],'$'		;在最後面加上一個字串結束符號
	
	putchar(13)
	putchar(10)
	
	pop ax
	pop cx
	pop dx
	pop si
endm