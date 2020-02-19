%include "t_list.s"

section .text
	global _ft_list_remove_if
	extern _free

_ft_list_remove_if:
	push rbp
	mov  rbp, rsp
	sub  rsp, 8
	push rbx
	push r12
	push r13
	push r14
	push r15

	xor  rax, rax ; prev elem is null at the beginning
	push rax      ; use stack to store prev elem addr

	test rdi, rdi
	jz  .done      ; jmp if begin list addr is null
	test rdx, rdx
	je  .done      ; jmp if cmp is null
	test rcx, rcx
	jz  .done      ; jmp if free_fct is null
	mov rbx, [rdi] ; get ptr to first elem
	mov r12, rdi   ; save list beg ptr addr
	mov r13, rsi   ; save data_ref
	mov r14, rdx   ; save cmp
	mov r15, rcx   ; save free_fct

.loop:
	test rbx, rbx
	jz   .done                    ; jmp if cur elem is null
	mov  rdi, [rbx + t_list.data]
	mov  rsi, r13
	call r14                      ; call cmp
	test rax, rax
	jnz  .next                    ; jmp if cmp did not returned 0
	mov  rdi, [rbx + t_list.data]
	call r15                      ; call free_fct

	cmp  rbx, [r12]
	jne  .skip_beg_swap ; if cur elem equal beg list, point beg list to cur->next
	mov  rax, [rbx + t_list.next]
	mov  [r12], rax

.skip_beg_swap:
	mov  rax, [rbx + t_list.next] ; save next elem addr
	push rax                      ;  //
	mov  rdi, rbx
	call _free                    ; free cur elem
	pop  rax                      ; restore next elem addr
	mov  rbx, rax                 ; set next elem as cur elem
	pop  rax                      ; restore addr of prev elem
	test rax, rax
	jz   .skip_prev_link          ; jmp if prev elem is null
	mov  [rax + t_list.next], rbx ; point prev-next to cur
.skip_prev_link:
	push rax
	jmp  .loop

.next:
	pop  rax
	mov  rax, rbx ; save cur addr to prev
	push rax
	mov  rbx, [rbx + t_list.next]
	jmp  .loop

.done:
    pop rax
	pop r15
	pop r14
	pop r13
	pop r12
	pop rbx
	leave
	ret
