# Description
Linux Kernel Memory Allocation Experiment<br/>
Changing Linux kernel memory allocation algorithm from first-fit to best-fit.

## Experiment Conclusion:
Best-fit memory allocation algorithms was more effecient in using memory 4k, as oppose to first-fit which leaves more memory space empty in the 4k pages. However, best-fit algorithm was significantly slower. This explains why best-fit memory allocation algorithm is advised when memory is a scarce resource. 

## Background 
The SLOB (Simple list of blocks) allocator is one of three available memory allocators in the Linux kernel. (The other two are SLAB and SLUB.)<br/> 

The SLOB allocator is designed to require little memory for the implementation and housekeeping, for use in small systems such as embedded systems. Unfortunately, a major limitation of the SLOB allocator is that it suffers greatly from internal fragmentation.

SLOB currently uses a first-fit algorithm, which uses the first available space for memory. In 2008, a reply from Linus Torvalds on a Linux mailing list[1] was made where he suggested the use of a best-fit algorithm, which tries to find a memory block which suits needs best. Best fit finds the smallest space which fits the required amount available, avoiding loss of performance, both by fragmentation and consolidation of memory.

## Algorithms 
### First-Fit
First fit: There may be many holes in the memory, so the operating system, to reduce the amount of time it spends analyzing the available spaces, begins at the start of primary memory and allocates memory from the first hole it encounters large enough to satisfy the request. Using the same example as above, first fit will allocate 12KB of the 14KB block to the process.
### Best-Fit 
Best fit: The allocator places a process in the smallest block of unallocated memory in which it will fit. For example, suppose a process requests 12KB of memory and the memory manager currently has a list of unallocated blocks of 6KB, 14KB, 19KB, 11KB, and 13KB blocks. The best-fit strategy will allocate 12KB of the 13KB block to the process.


# INSTRUCTIONS
## Prepare a virtual kernel environment: 
1.For this experiment, I used qemu based [yocto](https://www.yoctoproject.org/) environment:
```git clone "git://git.yoctoproject.org/linux-yocto-3.14"```
```cd linux-yocto-3.14```
```git checkout v3.14.26```

1.Source the environment and compile:
```source /scratch/opt/environment-setup-i586-poky-linux```

1. Copy and make the menuconfig
```cp /scratch/spring2017/files/config-3.14.26-yocto-qemu ./.config```
```make menuconfig```

1.Setting the menuconfig
go to the "General setup"</br>
press / and type LOCALVERSION</br>
Rename the Kernel Configuration to <insert-name-here>
Save and Exit

1. Make the kernel
Using 16 threads: ```make -j16 all``` 
If you don't want to exhaust your memory, you can use: ```make -j$(noproc) all``` 

1. Run gdb
open another terminal
```source /scratch/opt/environment-setup-i586-poky-linux```
```gdb ./vmlinux```
```(gdb) target remote tcp:127.0.0.1:5725```

1.Login to the VM:
```qemux86 login: root```
```root@qemux86: uname -a```
```root@qemux86: reboot```

1. Run ```make menuconfig```

1. Build the kernel with qemu:
```qemu-system-i386 -gdb tcp::5725 -S -nographic -kernel linux-yocto-3.14/arch/x86/boot/bzImage -drive file=core-image-lsb-sdk-qemux86.ext3,if=virtio -enable-kvm -net none -usb -localtime --no-reboot --append "root=/dev/vda rw console=ttyS0 debug```

1. Insure that it is running with gdb
```(gdb) target remote :5725```

## Patch the kernel
1. Compile and replace the slob.c found in ```/sys/kernel/mm/``` with either ```slob_bestfit.c``` or ```slob_firstfit.c```.

1. Replace the kernel's ```syscall_32.tbl``` and ```syscalls.h``` with the ones supplied in this repository, since it references the memory allocation function calls from the ```slob.c``` file for the kernel to use them.

1. patch the system, using either [fakeroot](https://wiki.debian.org/FakeRoot) or [yocto](https://www.yoctoproject.org/)

1. Run ```simple_test.c``` and observe the differences in speed and memory allocation.
