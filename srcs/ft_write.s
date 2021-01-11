section	.text
		global	ft_write
		extern __errno_location

ft_write:
		mov		rax, 1				; 1 = write
		syscall
		cmp 	rax, 0				; check rax
		jl		.error				; error if < 0
		mov 	r8, rax
		call	__errno_location
		mov		byte[rax], 0
		mov		rax, r8
		ret

.error:
		mov		r8, rax
		imul	r8, -1
		call	__errno_location
		mov		[rax], r8
		mov		rax, -1
		ret
