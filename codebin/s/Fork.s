	.file	"Fork.c"
	.text
	.section	.rodata
.LC0:
	.string	"Fork failed!"
.LC1:
	.string	"42"
.LC2:
	.string	"ForkChild"
.LC3:
	.string	"./ForkChild"
.LC4:
	.string	"excel failed"
	.align 8
.LC5:
	.string	"I am Parent process and my pid is %d and my parent PID is %d\n"
.LC6:
	.string	"Child process completed"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	call	fork@PLT
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jns	.L2
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$1, %eax
	jmp	.L3
.L2:
	cmpl	$0, -4(%rbp)
	jne	.L4
	movl	$0, %ecx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	execl@PLT
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	perror@PLT
	jmp	.L5
.L4:
	call	getpid@PLT
	movl	%eax, %ecx
	movl	-4(%rbp), %eax
	movl	%eax, %edx
	movl	%ecx, %esi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L5:
	movl	$0, %eax
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.2.0-23ubuntu4) 13.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
