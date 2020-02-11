bits 64

section .text
	global _ft_atoi_base
	extern _ft_strlen
	extern _ft_strchr

base_is_valid:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	push rdi
	cmp  rdi, 0 
	je   .false     ; jmp if base str ptr is null
	call _ft_strlen
	cmp  al, 2      ; jmp if base len is less than 2
	jle  .false
	pop rdi

.loop:
	cmp   byte [rdi], '+'  
	je    .false            ; jmp if char is + sign
	cmp   byte [rdi], '-'
	je    .false            ; jmp if char is - sign
	movzx rsi, byte [rdi + 1]
	call  _ft_strchr
	cmp   rax, 0
	jne   .false
	cmp   byte [rdi + 1], 0
	jz    .true             ; jmp if next char is null
	inc   rdi
	jmp   .loop

.true:
	jmp .exit

.false:
	xor rax, rax
	jmp .exit

.exit:
	leave
	ret

_ft_atoi_base:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	push rdi
	mov  rdi, rsi
	call base_is_valid
	pop  rdi

.done:
	leave
	ret
