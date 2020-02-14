bits 64

%include "libasm.s"

section .text
	global _ft_list_size

_ft_list_size:
	push rbp
	mov  rbp, rsp
	
	mov  rax, 0 ; init counter
.loop:
	cmp  rdi, 0
	je   .done  ; jmp if cur ptr is null
	inc  rax    ; if not increment counter
	mov  rdi, [rdi + t_list.next] ; mov next ptr to cur ptr
	jmp  .loop
	
.done:
	leave
	ret 
