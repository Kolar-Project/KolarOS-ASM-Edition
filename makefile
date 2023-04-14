setup:


build:
	nasm -f bin -o boot.bin boot.asm

run: build
	qemu-system-i386 boot.bin
debug: build
	qemu-system-i386 -no-reboot -monitor stdio -d int -no-shutdown boot.bin