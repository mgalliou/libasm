bits 64

section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_strdup:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	mov  rbx, rdi ; save ptr on str to be dup
	call _ft_strlen
	inc  rax ; inc len for terminating null
	mov  rdi, rax
	call _malloc
	test rax, rax
	jz   .done ; leave if malloc returned null
	mov  rdi, rax
	mov  rsi, rbx
	leave
	jmp _ft_strcpy

.done:
	leave
	ret
