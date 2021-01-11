section .text
		global ft_strdup
		extern malloc
		extern ft_strlen
		extern ft_strcpy

ft_strdup:
		push	rdi				; store arg
		call	ft_strlen		; rax = ft_strlen(src)
		inc		rax				; rax++ '\0'
		mov		rdi, rax

		call	malloc
		cmp		rax, 0			; check malloc
		je		.error
		
		mov		rdi, rax
		pop		rsi				; get stored arg
		call	ft_strcpy
		ret

.error:
		ret