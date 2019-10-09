# Description
Altered the operating system memory allocation algorithm from first-fit, which the Linux current defauly, to best-fit, and vice versa.

As file name suggests, slob_firstfit.c changes the system's memory handling algorithm to first-fit, while slob_bestfit.c changes system's memory handling algorithms to best-fit.

syscall_32.tbl is replaced with the kernel's "syscall_32.tbl", since it references the commands in the c files to be called correctly.  

The system needs to be patched with the c files for changes to take effect.

The program was tested on virtual debian-based Operating systems powered by qemu. 

## Warning
The program permanently change the Operating System memory allocation algorithms and memory handling, allocation, and memory retrieval.
