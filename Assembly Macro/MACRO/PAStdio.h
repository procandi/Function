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
	
	mov dx,offset wd	;�ȷ|�����D�A�ҥH�[�Woffset
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

	lea si,wd		;�Nsi����wd���O�����}
next:
	mov ah,01h
	int 21h
	
	cmp al,20h		;��o�{�ϥΪ̿�J���O�@��space�r����N���}�j��
	je exit
	mov [si],al		;�Nsi�ҫ����O�����}���Ŷ���J��J���r��
	inc si			;����U�@�Ӧ�}
	jmp next		;�^�h�����U�@�Ӧr
exit:
	mov [si],'$'		;�b�̫᭱�[�W�@�Ӧr�굲���Ÿ�
	
	pop ax
	pop cx
	pop dx
	pop si
endm

writeln macro wd
	push ax
	push dx
	
	mov dx,offset wd	;�ȷ|�����D�A�ҥH�[�Woffset
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

	lea si,wd		;�Nsi����wd���O�����}
next:
	mov ah,01h
	int 21h
	
	cmp al,0dh		;��o�{�ϥΪ̿�J���O�@��'\n'�r����N���}�j��
	je exit
	mov [si],al		;�Nsi�ҫ����O�����}���Ŷ���J��J���r��
	inc si			;����U�@�Ӧ�}
	jmp next		;�^�h�����U�@�Ӧr
exit:
	mov [si],'$'		;�b�̫᭱�[�W�@�Ӧr�굲���Ÿ�
	
	putchar(13)
	putchar(10)
	
	pop ax
	pop cx
	pop dx
	pop si
endm