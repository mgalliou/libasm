%include "t_list.s"

section .text
	global _ft_list_sort

_ft_list_sort:
	push rbp
	mov  rbp, rsp
	push rbx
	push r12
	push r13
	push r14

	test rsi, rsi
	jz  .done       ; jmp if cmp is null
	test rdi, rdi
	jz  .done       ; jmp if addr of beg list ptr is null
	mov rbx, [rdi]  ; save list beg ptr in tmp reg
	test rbx, rbx
	jz  .done       ; jmp if beg list ptr is null
	mov r12, rsi    ; save ptr on cmp
	mov r13, rbx    ; save list beg ptr

.loop:
	cmp qword [rbx + t_list.next], 0
	je  .done ; jmp if cur->next is null

	mov  r14, [rbx + t_list.next] ; save ptr on next elem
	mov  rdi, [rbx + t_list.data]
	mov  rsi, [r14 + t_list.data]
	call r12
	cmp  rax, 0
	jg  .swap_data
	mov  rbx, [rbx + t_list.next] ; mov next ptr to cur ptr
	jmp  .loop

.swap_data:
	mov rcx, [rbx + t_list.data] ; save ptr on cur elem data
	mov rdi, [r14 + t_list.data] ; save ptr on next elem data
	mov [rbx + t_list.data], rdi ; move next elem data to cur data
	mov [r14 + t_list.data], rcx ; move cur data to next elem data
	mov rbx, r13                 ; move cur ptr to beg list ptr
	jmp .loop

.done:
	pop r14
	pop r13
	pop r12
	pop rbx
	leave
	ret
