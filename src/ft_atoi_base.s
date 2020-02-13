bits 64

section .text
	global _ft_atoi_base
	extern _ft_strlen
	extern _ft_strchr
	extern _ft_isspace

ft_issign:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	xor rax, rax
	cmp rdi, '+'
	je  .true
	cmp rdi, '-'
	je  .true
	ja  .exit

.true:
	mov rax, 1

.exit:
	leave
	ret

base_is_valid:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	cmp  rdi, 0
	je   .false     ; jmp if base str ptr is null
	push rdi
	call _ft_strlen
	pop  rdi
	push rax
	cmp  rax, 2      ; jmp if base len is less than 2
	jle  .false

.loop:
	cmp   byte [rdi], '+'
	je    .false            ; jmp if char is + sign
	cmp   byte [rdi], '-'
	je    .false            ; jmp if char is - sign
	movzx rsi, byte [rdi]
	push  rdi
	inc   rdi
	call  _ft_strchr
	pop   rdi
	cmp   rax, 0			; check for duplicate char in str
	jne   .false
	cmp   byte [rdi + 1], 0
	jz    .true             ; jmp if next char is null
	inc   rdi
	jmp   .loop

.true:
	pop rax
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
	push rbx
	push r12
	push r13

	mov  r12, rsi      ; save base string
	push rdi           ; push number string
	mov  rdi, rsi
	call base_is_valid ; base_is_valid return base len
	mov  r13, rax      ; save base len
	pop  rdi           ; pop number string
	cmp  rax, 0
	je   .done         ; jmp if base is not valid

	mov rbx, 1         ; used for sign
.skip_space_loop:
	push  rdi
	movzx rdi, byte [rdi]
	call  _ft_isspace
	pop   rdi
	cmp   rax, 0
	je    .skip_sign_loop   ; jmp if not a space
	inc   rdi
	jmp   .skip_space_loop

.skip_sign_loop:
	push  rdi
	movzx rdi, byte [rdi]
	call  ft_issign
	pop   rdi
	cmp   rax, 0
	je    .convert        ; jmp if not a sign
	cmp   byte [rdi], '-'
	je    .negate
.after_negate:
	inc   rdi
	jmp   .skip_sign_loop

.negate:
	neg   rbx
	jmp   .after_negate

.convert:
	xor   rax, rax
.convert_loop:
	cmp   byte [rdi], 0
	je    .done           ; jmp if end of string
	push  rax             ; push result
	push  rdi             ; push ptr on converted str
	movzx rsi, byte [rdi] ; prepare strchr call
	mov   rdi, r12        ; 	to verify cur char is in base str
	call  _ft_strchr
	pop   rdi             ; pop ptr on converted str
	cmp   rax, 0
	je    .done           ; jmp if char not
	mov   rcx, rax        ; save found char
	pop   rax             ; pop result
	mul   r13             ; multiply base len
	add   rax, rcx        ; add found char addr
	sub   rax, r12        ; sub first base str char addr
	inc   rdi
	jmp   .convert_loop

.done:
	imul  rbx
	pop   r13
	pop   r12
	pop   rbx
	leave
	ret
