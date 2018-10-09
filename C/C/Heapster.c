// Marian Nguyen
// October 11, 2018
// CECS 424
// Lab 2: Original Heapster

#include "stdafx.h"
#include <stdio.h>

// represents allocation block
struct Block {
	int block_size;					// number of bytes in the data section
	struct Block *next_block;		// pointer to next allocation block
};

const int OVERHEAD_SIZE = sizeof(struct Block);		// 8
const int VOID_SIZE = sizeof(void*);				// 4

// always points to the first free block in the free list
struct Block *free_head;

void my_initialize_heap(int size) {
	free_head = (struct Block*) malloc(size);
	free_head->block_size = size - OVERHEAD_SIZE;
	free_head->next_block = NULL;

	printf("Size for initial allocation: %d\n", size);
	printf("Block size: %d\n", free_head->block_size);
	printf("Address of next: %p\n", free_head->next_block);
	// %p used to print pointer addresses

}

int main() {
	my_initialize_heap(1000);

	printf("\n");		// formatting
	return 0;
};