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
	cmp  al, 2      ; jmp if base len is less than 2
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
	mov rax, 1
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

	push rdi           ; push number string
	mov  rdi, rsi
	call base_is_valid
	pop  rdi           ; pop number string
	cmp  rax, 0
	je   .done         ; jmp if base is not valid
	mov  rax, 5		   ; tmp return value to check base_is_valid is working
	jmp  .done

;	mov rbx, 1
;.skip_space_loop:
;	push  rdi
;	movzx rdi, byte [rdi]
;	call  _ft_isspace
;	cmp   rax, 0
;	je   .skip_sign_loop
;	pop   rdi
;	inc   rdi
;	jmp   .skip_space_loop
;
;.skip_sign_loop:
;	push  rdi
;	movzx rdi, byte [rdi]
;	call  ft_issign
;	cmp   rax, 0
;	je    .convert   ;jmp if not a sign
;	pop   rdi
;	cmp   byte [rdi], '-'
;	je    .negate
;.after_negate:
;	inc  rdi
;	jmp .skip_sign_loop
;
;.negate:
;	neg rbx
;
;.convert:

.done:
	pop rbx
	leave
	ret
