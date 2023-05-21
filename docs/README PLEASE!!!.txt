this is a alpha version of kolaros asm edition!!
so dont expect a thing, the os is in development!!

build 21052023 (21 may 2023 build)
version 0.0.26

how to compile the os:

you first need to install the NASM compiler

Windows:

to compile the os just open the NASM compiler and run the "build-windows.bat" file that is located in the tools folder with this command
in the nasm compiler: call "C:\asmkolar\tools\build-windows.bat" x86
 
(you need to change the path of the command to where you have the src saved,
and you need to edit the 'build-windows.bat' file and you have to edit the paths to
where you have the src saved.)



Linux:


to compile the os just run the terminal and now go to the path to where you have the src saved and run the 'build-linux.sh' file that is in the tools folder
and thats it

(you need to edit the 'build-linux.bsh' file and you have to edit the paths to
where you have the src saved.)


(the 'kolar.bin' file works too, so if you want you can run it)

when the src is compiled, just run the 'run.bat' file to run the compiled iso in QEMU!

with love, GreenSoupDev.