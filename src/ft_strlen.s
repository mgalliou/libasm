section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov  rbp, rsp

	mov   rdx, rdi  ; save string beg ptr
	cld             ; clear direction flag
	xor   al, al    ; set byte to be scanned by scas at 0
	mov   rcx, -1   ; start decremanting at -1
	repne scasb     ; rep until byte scanned (al) is not found

	dec rdi      ; scasb increment rdi one more time after al has been found
	sub rdi, rdx ; sub end addr to beg addr
	mov rax, rdi ; move diff to ret register

	leave
	ret
