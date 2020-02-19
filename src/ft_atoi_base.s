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
	jmp  .exit

.true:
	mov rax, 1

.exit:
	leave
	ret

base_is_valid:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	test rdi, rdi
	jz   .false     ; jmp if base str ptr is null
	push rdi
	call _ft_strlen
	pop  rdi
	push rax
	cmp  rax, 2      ; jmp if base len is less than 2
	jb  .false

.loop:
	cmp   byte [rdi], '+'
	je    .false            ; jmp if char is + sign
	cmp   byte [rdi], '-'
	je    .false            ; jmp if char is - sign
	push  rdi
	movzx rdi, byte [rdi]
	call  _ft_isspace
	pop   rdi
	test  rax, rax
	jnz   .false
	movzx rsi, byte [rdi]
	push  rdi
	inc   rdi
	call  _ft_strchr
	pop   rdi
	test  rax, rax			; check for duplicate char in str
	jnz   .false
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
	test  rax, rax
	jz    .skip_sign_loop   ; jmp if not a space
	inc   rdi
	jmp   .skip_space_loop

.skip_sign_loop:
	push  rdi
	movzx rdi, byte [rdi]
	call  ft_issign
	pop   rdi
	test  rax, rax
	jz    .convert        ; jmp if not a sign
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
	mov   rcx, rax        ; save found char
	pop   rdi             ; pop ptr on converted str
	test  rax, rax
	pop   rax             ; pop result
	jz    .done           ; jmp if char not
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
