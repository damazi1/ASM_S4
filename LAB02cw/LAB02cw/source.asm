.code

	asmADD PROC
		add ecx, edx
		movsxd rax, ecx
		ret
	asmADD ENDP

	asmSUB PROC
		sub ecx, edx
		movsxd rax, ecx
		ret
	asmSUB ENDP

	asmSHL PROC
		shl ecx, 5
		movsxd rax, ecx
		ret
	asmSHL ENDP

	asmSHR PROC
		shr ecx, 2
		movsxd rax, ecx
		ret
	asmSHR ENDP

	asmSAR PROC
		movsxd rax, ecx
		sar rax, 1
		ret
	asmSAR ENDP

	asmMUL PROC
		mov eax, ecx
		mul edx
		movsxd rax, eax
		ret
	asmMUL ENDP

	asmDIV PROC
		mov eax, ecx
		movsxd rcx, edx
		cqo
		div rcx
		movsxd rax, eax
		ret
	asmDIV ENDP

	asmIMUL PROC
		movsxd rax, ecx
		movsxd rcx, edx
		imul rcx
		ret
	asmIMUL ENDP

	asmIDIV PROC
		movsxd rax, ecx
		movsxd rcx, edx
		cqo
		idiv rcx 
		ret
	asmIDIV ENDP

END