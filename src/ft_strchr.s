bits 64

section .text
	global _ft_strchr

_ft_strchr:
	push rbp
	mov  rbp, rsp

	xor  rax, rax
	test rdi, rdi
	jz  .done     ; jmp if string is null
	cld
	mov rax, rsi  ; set byte to be scanned by scas

.loop:
	cmp    byte [rdi], 0
	je     .check_null   ; jmp if reach end of string
	scasb
	loopne .loop
	lea    rax, [rdi - 1]
	jmp    .done

.check_null:
	test   rax, rax
	cmove  rax, rdi ; if scanned byte is null set return to cur byte addr
	je     .done
	xor    rax, rax ; else set return to null

.done:
	leave
	ret
