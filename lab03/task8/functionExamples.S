
	.global sumAsm

sumAsm:
	movl	%edi,  %edx
	movl	%esi, %eax
	addl	%edx, %eax
	ret


