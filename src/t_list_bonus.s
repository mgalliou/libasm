%ifndef LIBASM_S
	%define LIBASM_S

	struc t_list
		.data: resq 1
		.next: resq 1
	endstruc

%endif
