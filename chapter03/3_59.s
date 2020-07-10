	.file	"3_59.c"
	.text
	.globl	cread
	.type	cread, @function
cread:
.LFB23:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L3
	movq	(%rdi), %rax
	ret
.L3:
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE23:
	.size	cread, .-cread
	.globl	cread_alt
	.type	cread_alt, @function
cread_alt:
.LFB24:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L6
	movq	(%rdi), %rax
	ret
.L6:
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE24:
	.size	cread_alt, .-cread_alt
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"3_59.c"
.LC1:
	.string	"cread(&a) == cread_alt(&a)"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"cread(NULL) == cread_alt(NULL)"
	.text
	.globl	main
	.type	main, @function
main:
.LFB25:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movq	$0, (%rsp)
	movq	%rsp, %rbx
	movq	%rbx, %rdi
	call	cread
	movq	%rax, %rbp
	movq	%rbx, %rdi
	call	cread_alt
	cmpq	%rax, %rbp
	jne	.L12
	movl	$0, %edi
	call	cread
	movq	%rax, %rbx
	movl	$0, %edi
	call	cread_alt
	cmpq	%rax, %rbx
	jne	.L13
	movl	$0, %eax
	movq	8(%rsp), %rdx
	xorq	%fs:40, %rdx
	jne	.L14
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L12:
	.cfi_restore_state
	leaq	__PRETTY_FUNCTION__.2469(%rip), %rcx
	movl	$17, %edx
	leaq	.LC0(%rip), %rsi
	leaq	.LC1(%rip), %rdi
	call	__assert_fail@PLT
.L13:
	leaq	__PRETTY_FUNCTION__.2469(%rip), %rcx
	movl	$18, %edx
	leaq	.LC0(%rip), %rsi
	leaq	.LC2(%rip), %rdi
	call	__assert_fail@PLT
.L14:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE25:
	.size	main, .-main
	.section	.rodata
	.type	__PRETTY_FUNCTION__.2469, @object
	.size	__PRETTY_FUNCTION__.2469, 5
__PRETTY_FUNCTION__.2469:
	.string	"main"
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
