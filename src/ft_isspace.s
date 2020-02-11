bits 64

section .text
	global _ft_isspace

_ft_isspace:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	xor rax, rax
	cmp rdi, ' '
	je  .true
	cmp rdi, 9
	jb  .exit
	cmp rdi, 13
	ja  .exit

.true:
	mov rax, 1

.exit:
	leave
	ret
