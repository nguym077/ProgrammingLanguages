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

// points to block right before current when scanning free_list
struct Block *previous;

void my_initialize_heap(int size) {
	free_head = (struct Block*) malloc(size);
	free_head->block_size = size - OVERHEAD_SIZE;
	free_head->next_block = NULL;

	previous = NULL;
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
	bool foundBlock = false;		// '0' means false (NULL), '1' means true
	while (current != NULL) {
		if (current->block_size >= size) {
			foundBlock = true;
			break;
		} else {
			previous = current;				// keeps track of previous block in free_list
			current = current->next_block;	// increments iterator
		}
	}

	// 4 cases
	if (foundBlock) {
		int leftOver = current->block_size - size;

		// split
		if (leftOver >= (OVERHEAD_SIZE + MINIMUM_SIZE)) {
			if (current == free_head) {		// block is at head
				printf("split. at head.\n");
				// treats current as 1 byte and updates pointer accordingly
				struct Block* nextBlock = (struct Block*)((char*)current + OVERHEAD_SIZE + size);
				nextBlock->block_size = leftOver - OVERHEAD_SIZE;
				nextBlock->next_block = current->next_block;
				free_head = nextBlock;

				// allocates
				current->block_size = size;
				current->next_block = NULL;
			} else { // block is not at head
				printf("split. NOT at head.\n");
				// treats current as 1 byte and updates pointer accordingly
				struct Block* nextBlock = (struct Block*)((char*)current + OVERHEAD_SIZE + size);
				nextBlock->block_size = leftOver - OVERHEAD_SIZE;
				nextBlock->next_block = current->next_block;

				// points the previous block's (in free_list)
				// next_block to the node that was split off
				previous->next_block = nextBlock;

				// allocates
				current->block_size = size;
				current->next_block = NULL;
			}
		} else {
			// don't split
			if (current == free_head) {		// block is at head
				printf("DONT split. at head.\n");
				// updates freelist to next available block
				free_head = current->next_block;

				// allocates
				current->block_size = size;
				current->next_block = NULL;
			} else { // block is not at head
				printf("DONT split. NOT at head.\n");
				previous->next_block = current->next_block;

				// allocates
				current->block_size = size;
				current->next_block = NULL;
			}
		}

		return (void*) ((char*)current + OVERHEAD_SIZE);	// returns 'data' portion of block
	} else {
		// did not find block large enough for allocation request
		return 0;
	}
}

// deallocates a value that was allocated on the heap
void my_free(void *data) {
	// points current to front of block being deallocated
	struct Block* current = (struct Block*)((char*)data - OVERHEAD_SIZE);
	
	// links current to free list
	current->next_block = free_head;
	free_head = current;
}

int main() {
	my_initialize_heap(1000);

	void* a;
	void* b;
	void* c;
	void* d;
	void* e;
	
	int testNumber = 3;
	switch (testNumber) {
		case 1:		// test case #1
			printf("Test Case #1\n");
			a = my_alloc(sizeof(int));
			printf("Address of 'a': %p\n", a);

			my_free(a);

			b = my_alloc(sizeof(int));
			printf("Address of 'b': %p", b);
			// address of a and b should be the same
			break;
		case 2:		// test case #2
			printf("Test Case #2\n");
			a = my_alloc(sizeof(int));
			b = my_alloc(sizeof(int));

			printf("Address of 'a': %p\n", a);
			printf("Address of 'b': %p", b);
			break;
		case 3:		// test case #3
			printf("Test Case #3\n\n");

			a = my_alloc(sizeof(int));
			printf("allocated 'a'.\n\n");
			b = my_alloc(sizeof(int));
			printf("allocated 'b'.\n\n");
			c = my_alloc(sizeof(int));
			printf("allocated 'c'.\n\n");

			printf("Address of 'a': %p\n", a);
			printf("Address of 'b': %p\n", b);
			printf("Address of 'c': %p\n\n", c);

			my_free(b);
			printf("deallocated 'b'.\n\n");

			d = my_alloc(2 * sizeof(double));
			printf("allocated 'd'.\n");
			printf("\Address of 'd': %p\n\n", d);

			e = my_alloc(sizeof(int));
			printf("allocated 'f'.\n");
			printf("Address of 'e': %p", e);
			break;
		case 4:		// test case #4
			printf("Test Case #4\n");
			a = my_alloc(sizeof(char));
			b = my_alloc(sizeof(int));

			printf("Address of 'a': %p\n", a);
			printf("Address of 'b': %p", b);
			break;
		case 5:		// test case #5
			printf("Test Case #5\n");
			a = my_alloc(80 * sizeof(int));
			b = my_alloc(sizeof(int));

			printf("Address of 'a': %p\n", a);
			printf("Address of 'b': %p", b);

			my_free(a);

			printf("\nAddress of 'b': %p", b);
			break;
		default:
			printf("\n");
	}

	printf("\n");		// formatting
	return 0;
};