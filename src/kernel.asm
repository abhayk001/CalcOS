bits	32
section	.text
	align	4
	dd	0x1BADB002
	dd	0x00
	dd	- (0x1BADB002 + 0x00)

global start
extern kmain	; This function is in kernel.c
start:
	cli	; Clears the interrupts
	call kmain	; Sends the processor to continue execution from kmain function in kernel.c
	hlt		; Halts the CPU (Pause it from executing from this address)
