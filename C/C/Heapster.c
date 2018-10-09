// Marian Nguyen
// October 11, 2018
// CECS 424
// Lab 2: Original Heapster

#include "stdafx.h"
#include <stdio.h>
#include <stdbool.h>

// represents allocation block
struct Block {
	int block_size;					// number of bytes in the data section
	struct Block *next_block;		// pointer to next allocation block
};

const int OVERHEAD_SIZE = sizeof(struct Block);		// 8
const int MINIMUM_SIZE = sizeof(void*);				// 4

// always points to the first free block in the free list
struct Block *free_head;

void my_initialize_heap(int size) {
	free_head = (struct Block*) malloc(size);
	free_head->block_size = size - OVERHEAD_SIZE;
	free_head->next_block = NULL;
}

// fills allocation request of 'size' bytes and
// returns a pointer to the data portion of block used
//
// pre-condition: size is any positive integer
void* my_alloc(int size) {
	// checks to see if data size to be allocated
	// is a multiple of MINIMUM_SIZE (void*)
	int remainder = size % MINIMUM_SIZE;
	if (remainder != 0) {
		size += (MINIMUM_SIZE - remainder);
	}

	// walks free list (starting at free_head), looking
	// for a block with large enough size to fit request
	struct Block* current = free_head;
	bool foundBlock = 0;		// '0' means false (NULL), '1' means true
	while (current != NULL) {
		if (current->block_size >= size) {
			foundBlock = 1;
			break;
		} else {
			// increments iterator
			current = current->next_block;
		}
	}

	// 4 cases
	if (foundBlock) {
		int leftOver = current->block_size - size;

		// split
		if (leftOver > (OVERHEAD_SIZE + MINIMUM_SIZE)) {
			// block is at head
			if (current == free_head) {
				printf("split, block at head.\n");
				struct Block* nextBlock = current + OVERHEAD_SIZE + size;

			} else { // block is not at head
				printf("split, block not at head.\n");
			}
		} else {
			// don't split
			if (current == free_head) {
				// block is at head
				printf("dont split, block at head.\n");
			} else { // block is not at head
				printf("dont split, block not at head.\n");
			}
		}
	} else {
		// did not find block large enough for allocation request
		return 0;
	}
}

int main() {
	my_initialize_heap(1000);
	//my_alloc(4);

	printf("\n");		// formatting
	return 0;
};