# Description
Altering Linux kernel memory allocation algorithm from first-fit to best-fit.

## Background 
(background on the subject: what is memory allocation, what is the algorihtms? what are the other variables in the algoirhtms?)

## Algorithms 
### First-Fit
The default linux kernel (since kernel date?) configurations for memory pages allocation is First-Fist.
### Best-Fit 
(Explain best-fit algorithm)

/sys/kernel/mm/
make menuconfig

# INSTRUCTIONS
1. (Make file?)
1. compile slob_bestfit
```
gcc slob_bestfit.c
```
1.Patch they system using $ (?)
Build the kernel, using eithere fakeroot(link) or yocto kernel

1. Run simple test to verify that its working?




------------


syscall_32.tbl is replaced with the kernel's "syscall_32.tbl", since it references the commands in the c files to be called correctly.  

The system needs to be patched with the c files for changes to take effect.

The program was tested on virtual debian-based Operating systems powered by qemu. 

