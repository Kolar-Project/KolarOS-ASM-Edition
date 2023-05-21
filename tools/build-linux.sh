if test "`whoami`" != "root" ; then
	echo "You must be logged in as root to build (for loopback mounting)"
	echo "Enter 'su' or 'sudo bash' to switch to root"
	exit
fi





echo ">>> Assembling kernel..."

nasm -O0 -w+orphan-labels -f bin -o bin/kolar.bin src/boot.asm

if [ ! -e bin/kolar.flp ]
then
	echo ">>> Creating new KolarOS floppy image..."
	mkdosfs -C bin/kolar.flp 1440
         
fi

echo ">>> Assembling ISO image..."

rm -f bin/kolar.iso
C:/asmkolar/mkisofs.exe -quiet -V 'KOLAROS' -input-charset iso8859-1 -o bin/kolar.iso -b kolar.flp bin/

echo '>>> Done!'

