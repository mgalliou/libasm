bits 64

section .text
	global _ft_atoi_base

_ft_atoi_base:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	leave
	ret
