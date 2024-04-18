.code
	asm01_01 PROC
		xor rax, rax
		movsxd rdx, edx
		movsxd r8, r8d
	_rows_loop:
		mov r10, qword ptr[rcx + 8 * rdx - 8]
		mov r9,r8
	_cols_loop:
		mov r11d, dword ptr[r10 + 4 * r9 -4]
		add eax, r11d
		dec r9
		jnz _cols_loop
		dec rdx
		jnz _rows_loop

		movsxd rax, eax
		ret
	asm01_01 ENDP

	asm01_06 PROC USES RSI RDI
		xor eax, eax
		movsxd r8, r8d
		mov rsi, r8			;indeks rows
		movsxd r9, r9d
		mov rdi, r9			;indeks cols
	_rows_loop:
		mov r8, qword ptr[rcx + 8 * rsi - 8] ;col A 
		mov r9, qword ptr[rdx + 8 * rsi - 8] ;col B
		mov r10, rdi
	_cols_loop:
		mov r11d, dword ptr[r8 + 4 * r10 -4]  ;row A
		imul r11d, dword ptr[r9 + 4 * r10 -4] ; row A * row B
		add eax, r11d	;Sum A*B
		dec r10
		jnz _cols_loop
		dec rsi
		jnz _rows_loop

		ret
	asm01_06 ENDP

	asm02_08 PROC 
		movsxd rdx, edx
		movsxd r8, r8d
	_rows_loop:
		mov r9, qword ptr[rcx +8 * rdx -8]
		mov r10 ,r8
		bt rdx, 0		;copy rdx[0] (LSB(rdx)) to CF Sprawdza najstarszy bit i je¿eli jest nieparzysta to skacze
		jnc _skip_row
	_cols_loop:
		bt r10, 0		;copy r10[0] (LSB(r10)) to CF	
		jnc _skip_col
		mov word ptr [r9 + 2 * r10 - 2], 0

	_skip_col:
		dec r10
		jnz _cols_loop
	_skip_row:
		dec rdx
		jnz _rows_loop

		ret
	asm02_08 ENDP

	asm02_11 PROC
		movsxd rdx, edx
		movsxd r8, r8d
	_rows:
		mov r9, r8
		mov r10, qword ptr [rcx+8*rdx-8]
		_cols:
			cmp rdx, r9
			jle _skip
			mov qword ptr [r10+8*r9-8], 0
		_skip:
			dec r9
			jnz _cols
		dec rdx
		jnz _rows
		ret
	asm02_11 ENDP

END
