/*
 test.c: Test program for CS1550 syscalls
 (c) Mohammad Hasanzadeh Mofrad, 2019
 (e) moh18@pitt.edu
*/

#include <sys/mman.h>
#include <linux/unistd.h>
#include <stdio.h>
#include "sem.h"

int main(int argc, char** argv) {
    //Allocate a shared memory region to store one semaphore
    struct cs1550_sem *sem = mmap(NULL,sizeof(struct cs1550_sem), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, 0, 0);
    //Initialize the semaphore to 0
    sem->value = 0;
    printf("Initial     semaphore value = %d\n", sem->value);
    sleep(5);
    cs1550_down(sem);
    printf("Decremented semaphore value = %d\n", sem->value);
    sleep(5);
    cs1550_up(sem);
    printf("Incremented semaphore value = %d\n", sem->value);
    return(0);
}