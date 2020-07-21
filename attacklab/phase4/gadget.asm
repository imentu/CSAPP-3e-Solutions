000000000000000b <getval_142>:
   b:	55                   	push   %rbp
   c:	48 89 e5             	mov    %rsp,%rbp
   f:	b8 fb 78 90 90       	mov    $0x909078fb,%eax
  14:	5d                   	pop    %rbp
  15:	c3                   	retq   

0000000000000016 <addval_273>:
  16:	55                   	push   %rbp
  17:	48 89 e5             	mov    %rsp,%rbp
  1a:	89 7d fc             	mov    %edi,-0x4(%rbp)
  1d:	8b 45 fc             	mov    -0x4(%rbp),%eax
  20:	2d b8 76 38 3c       	sub    $0x3c3876b8,%eax
  25:	5d                   	pop    %rbp
  26:	c3                   	retq   

0000000000000027 <addval_219>:
  27:	55                   	push   %rbp
  28:	48 89 e5             	mov    %rsp,%rbp
  2b:	89 7d fc             	mov    %edi,-0x4(%rbp)
  2e:	8b 45 fc             	mov    -0x4(%rbp),%eax
  31:	2d af 8c a7 6f       	sub    $0x6fa78caf,%eax
  36:	5d                   	pop    %rbp
  37:	c3                   	retq   

0000000000000038 <setval_237>:
  38:	55                   	push   %rbp
  39:	48 89 e5             	mov    %rsp,%rbp
  3c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  40:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  44:	c7 00 48 89 c7 c7    	movl   $0xc7c78948,(%rax)
  4a:	90                   	nop
  4b:	5d                   	pop    %rbp
  4c:	c3                   	retq   

000000000000004d <setval_424>:
  4d:	55                   	push   %rbp
  4e:	48 89 e5             	mov    %rsp,%rbp
  51:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  55:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  59:	c7 00 54 c2 58 92    	movl   $0x9258c254,(%rax)
  5f:	90                   	nop
  60:	5d                   	pop    %rbp
  61:	c3                   	retq   

0000000000000062 <setval_470>:
  62:	55                   	push   %rbp
  63:	48 89 e5             	mov    %rsp,%rbp
  66:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  6a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  6e:	c7 00 63 48 8d c7    	movl   $0xc78d4863,(%rax)
  74:	90                   	nop
  75:	5d                   	pop    %rbp
  76:	c3                   	retq   

0000000000000077 <setval_426>:
  77:	55                   	push   %rbp
  78:	48 89 e5             	mov    %rsp,%rbp
  7b:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  7f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  83:	c7 00 48 89 c7 90    	movl   $0x90c78948,(%rax)
  89:	90                   	nop
  8a:	5d                   	pop    %rbp
  8b:	c3                   	retq   

000000000000008c <getval_280>:
  8c:	55                   	push   %rbp
  8d:	48 89 e5             	mov    %rsp,%rbp
  90:	b8 29 58 90 c3       	mov    $0xc3905829,%eax
  95:	5d                   	pop    %rbp
  96:	c3                   	retq  