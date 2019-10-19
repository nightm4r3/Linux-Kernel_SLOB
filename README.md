# Description
Kernel Development<br/>
Changing Linux kernel memory allocation algorithm from first-fit to best-fit.
The algorithms c files can be found in /sys/kernel/mm/

## Conclusion:
Best-fit memory allocation algorithms was more effecient in using memory 4k, as oppose to first-fit which leaves more memory space empty in the 4k pages. However, best-fit algorithm was significantly slower. This explains why best-fit memory allocation algorithm is advised when memory is a scarce resource. 

## Background 
(background on the subject: what is memory allocation, what is the algorihtms? what are the other variables in the algoirhtms?)

The SLOB (Simple list of blocks) allocator is one of three available memory allocators in the Linux kernel. (The other two are SLAB and SLUB.) The SLOB allocator is designed to require little memory for the implementation and housekeeping, for use in small systems such as embedded systems. Unfortunately, a major limitation of the SLOB allocator is that it suffers greatly from internal fragmentation.

SLOB currently uses a first-fit algorithm, which uses the first available space for memory. In 2008, a reply from Linus Torvalds on a Linux mailing list[1] was made where he suggested the use of a best-fit algorithm, which tries to find a memory block which suits needs best. Best fit finds the smallest space which fits the required amount available, avoiding loss of performance, both by fragmentation and consolidation of memory.

## Algorithms 
### First-Fit
First fit: There may be many holes in the memory, so the operating system, to reduce the amount of time it spends analyzing the available spaces, begins at the start of primary memory and allocates memory from the first hole it encounters large enough to satisfy the request. Using the same example as above, first fit will allocate 12KB of the 14KB block to the process.
### Best-Fit 
Best fit: The allocator places a process in the smallest block of unallocated memory in which it will fit. For example, suppose a process requests 12KB of memory and the memory manager currently has a list of unallocated blocks of 6KB, 14KB, 19KB, 11KB, and 13KB blocks. The best-fit strategy will allocate 12KB of the 13KB block to the process.


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

