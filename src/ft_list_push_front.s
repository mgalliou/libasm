bits 64

section .text
	global _ft_list_push_front
	extern _ft_create_elem

_ft_list_push_front:
	push rbp
	mov  rbp, rsp
	push rbx
	sub  rsp, 8
	
	mov  rbx, rdi        ; save ptr on list addr
	mov  rdi, rsi        ; move data to first param for create_elem
	call _ft_create_elem
	cmp  rax, 0
	je   .done
	mov  rdi, [rbx]
	mov  [rax + 8], rdi
	mov  [rbx], rax

.done:
	pop rbx
	leave
	ret
