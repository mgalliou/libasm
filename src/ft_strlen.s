bits 64

section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	mov rax, rdi ; save string beg ptr
.loop:
	cmp byte [rdi], ''
	jz  .done ; if byte is zeroed jump out of the loop
	inc rdi   ; else increment ptr addr
	jmp .loop

.done:
	sub rdi, rax ; sub end addr to beg addr
	mov rax, rdi ; move diff to ret register

	leave
	ret
