bits 64

%include "libasm.s"

section .text
	global _ft_list_push_front
	extern _ft_create_elem

_ft_list_push_front:
	push rbp
	mov  rbp, rsp
	sub  rsp, 8
	push rbx
	
	mov  rbx, rdi        ; save ptr on list addr
	mov  rdi, rsi        ; move data to first param reg for create_elem
	call _ft_create_elem
	cmp  rax, 0
	je   .done           ; jmp if create_elem failed
	mov  rdi, [rbx]      ; 
	mov  [rax + t_list.next], rdi  ; make new_elem->next point on list beg
	mov  [rbx], rax      ; make beg list ptr point on new elem

.done:
	pop rbx
	leave
	ret
