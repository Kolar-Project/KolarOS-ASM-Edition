setup:


build:
	nasm -f bin -o kolar.bin boot.asm

run: build
    nasm -f bin -o kolar.bin boot.asm
	copy /b kolar.bin kolar.flp
	copy kolar.flp c:\newkolar\cdiso
	mkisofs -no-emul-boot -boot-load-size 4 -o kolar.iso -b kolar.flp cdiso/
	qemu-system-i386 kolar.bin

debug: build
	qemu-system-i386 -no-reboot -monitor stdio -d int -no-shutdown boot.bin