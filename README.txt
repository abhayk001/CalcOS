This is CalOS! Welcome!
To run this OS, you need to have the QEMU emulator installed. If you don't you can still get the ISO file.
For getting the ISO file, you need to install xorriso. You can go to the makefile and uncomment the xorriso installation command under "build" to install xorriso.
You also need the GCC compiler, GRUB bootloader and LD GNU linker.
The LD linker should be there by default.
To run this OS in QEMU, type "make" in the terminal after navigating to the OS folder.
To build the ISO file, type "make build". You can only do this after running "make" once atleast. You can't run this immediately after running "make clear".
To clear all changes, type "make clear".
