section .text
	global _ft_strcpy

_ft_strcpy:
	push rbp
	mov  rbp, rsp

	mov rax, rdi ; set return to dst
	cld
.loop:
	movsb
	cmp byte [rdi - 1], 0
	loopne .loop          ; loop until last byte copied is null

	leave
	ret
