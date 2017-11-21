#include <stdio.h>
#include <stdlib.h>
#include <linux/unistd.h>

#define __total_memory 353
#define __free_memory 354
#define __slob_largest_free_block_size 355

long get_total();
long get_free();
long get_largest_free();
int main (void)
{
        long total_mem = get_total();
        long free_mem = get_free();
        long largest_unused_block = get_largest_free();
	    float fragmentation = 0.0;
	    fragmentation = (float) (free_mem - largest_unused_block) / free_mem;
	    long frag_percent = (long) ( fragmentation * 100.0 );
        printf("Total Slob Memory: %u\n", total_mem);
        printf("Free Slob Memory: %u\n", free_mem);
        printf("Fragmentation: %u\n", frag_percent);
        printf("largest_unused_block: %u\n", largest_unused_block);
  return 0;
}

long get_total(){
        return syscall(__total_memory);
}

long get_free(){
        return syscall(__free_memory);
}

long get_largest_free(){
        return syscall(__slob_largest_free_block_size);
}
