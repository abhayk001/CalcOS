COMPILER = gcc
LINKER = ld
ASSEMBLER = nasm
CFLAGS = -m32 -c -ffreestanding
ASFLAGS = -f elf32
LDFLAGS = -m elf_i386 -T src/link.ld
EMULATOR = qemu-system-i386
EMULATOR_FLAGS = -kernel

SRCS = src/kernel.asm src/kernel.c src/idt.c src/isr.c src/kb.c src/screen.c src/string.c src/system.c src/util.c src/shell.c src/algo.c
OBJS = obj/kasm.o obj/kc.o obj/idt.o obj/isr.o obj/kb.o obj/screen.o obj/string.o obj/system.o obj/util.o obj/shell.o obj/algo.o
OUTPUT = CalOS/boot/kernel.bin

run:link
	$(EMULATOR) $(EMULATOR_FLAGS) $(OUTPUT)

link:compile $(OBJS)
	rm -r -f CalOS/
	mkdir CalOS/
	mkdir CalOS/boot/
	$(LINKER) $(LDFLAGS) -o $(OUTPUT) $(OBJS)

compile:$(SRCS)
	rm obj/ -r -f
	mkdir obj/

obj/kasm.o:src/kernel.asm
	$(ASSEMBLER) $(ASFLAGS) -o obj/kasm.o src/kernel.asm

obj/kc.o:src/kernel.c
	$(COMPILER) $(CFLAGS) src/kernel.c -o obj/kc.o

obj/idt.o:src/idt.c
	$(COMPILER) $(CFLAGS) src/idt.c -o obj/idt.o

obj/isr.o:src/isr.c
	$(COMPILER) $(CFLAGS) src/isr.c -o obj/isr.o

obj/kb.o:src/kb.c
	$(COMPILER) $(CFLAGS) src/kb.c -o obj/kb.o

obj/screen.o:src/screen.c
	$(COMPILER) $(CFLAGS) src/screen.c -o obj/screen.o

obj/string.o:src/string.c
	$(COMPILER) $(CFLAGS) src/string.c -o obj/string.o

obj/system.o:src/system.c
	$(COMPILER) $(CFLAGS) src/system.c -o obj/system.o

obj/util.o:src/util.c
	$(COMPILER) $(CFLAGS) src/util.c -o obj/util.o

obj/shell.o:src/shell.c
	$(COMPILER) $(CFLAGS) src/shell.c -o obj/shell.o

obj/algo.o:src/algo.c
	$(COMPILER) $(CFLAGS) src/algo.c -o obj/algo.o

build:
	#sudo apt-get install xorriso
	rm CalOS/boot/grub/ -r -f
	mkdir CalOS/boot/grub/
	echo set default=0 >> CalOS/boot/grub/grub.cfg
	echo set timeout=0 >> CalOS/boot/grub/grub.cfg
	echo menuentry "CalOS" { >> CalOS/boot/grub/grub.cfg
	echo		set root='(hd96)' >> CalOS/boot/grub/grub.cfg
	echo		multiboot /boot/kernel.bin >> CalOS/boot/grub/grub.cfg
	echo } >> CalOS/boot/grub/grub.cfg
	
	grub-mkrescue -o CalOS.iso CalOS/

clear:
	rm -f -r obj/
	rm -f obj/*
	rm -r -f CalOS/
