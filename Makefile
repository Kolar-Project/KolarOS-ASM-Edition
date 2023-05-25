all:
# builds the kernel
	nasm -f bin -o bin/kolar.bin src/boot.asm
# copies the kernel
	cp bin/kolar.bin bin/kolar.flp
#makes an ISO
	grub-mkrescue /usr/lib/grub/i386-pc -o bin/kolar.iso ./bin

run: all
	qemu-system-x86_64 -cdrom bin/kolar.iso  -device sb16
# runs using qemu

debug: all
	qemu-system-x86_64 -no-reboot -d int -no-shutdown -cdrom os.iso -device sb16 -drive file=hdd.img,if=ide,index=0,media=disk,format=raw -boot order=d

# standard qemu debug
debugr: all
	qemu-system-x86_64 -s -S -no-reboot -monitor stdio -d int -no-shutdown -cdrom os.iso -device sb16 -drive file=hdd.img,if=ide,index=0,media=disk,format=raw -boot order=d

#remote debug using GDB
clean:
# JUST DELETES JUNK LIKE OBJECT FILES - fuck capslock
	-rm -rf kernel/*/*.o kernel/boot/*.o kernel/util/*.o kernel/drivers/*.o kernel/gdt/*.o kernel/interrupts/*.o kernel/memory/*.o kernel/render/*.o kernel/*.o os.iso .vscode/ kernel/kernel.bin iso/boot/kernel.bin
