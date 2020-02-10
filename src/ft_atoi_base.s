bits 64

section .text
	global _ft_atoi_base
	extern _ft_strlen

base_is_valid:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	test rdi, rdi	
	jz   .false
	call _ft_strlen
	test rdi, 2
	jle  .false

.loop
	test [rdi], [rdi]
	jz  .true
	test [rdi + 1], [rdi + 1]
	jz  .true
	cmp [rdi], '+'
	je  .false
	cmp [rdi], '-'
	je  .false
	mov rsi, rdi
	mov rdi, rdi + 1
	call _ft_strchr
	test [rax], [rax]
	jz   .false

.false:
	xor rax, rax
.true:
	leave
	ret

_ft_atoi_base:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	push rdi
	mov  rdi, rsi
	call base_is_valid
	test rax, rax
	jnz

.done
	leave
	ret
