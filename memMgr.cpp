// test.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include <queue>
#include <memory>

using namespace std;

struct Chunk {
	/**
	* When a chunk is free, the `next` contains the
	* address of the next chunk in a list.
	*
	* When it's allocated, this space is used by
	* the user.
	*/
	Chunk *next;
};

/**
* The allocator class.
*
* Features:
*
*   - Parametrized by number of chunks per block
*   - Keeps track of the allocation pointer
*   - Bump-allocates chunks
*   - Requests a new larger block when needed
*
*/
class Pool {
public:
	Pool(size_t chunksPerBlock)
		: mChunksPerBlock(chunksPerBlock) 
	{
		allocateBlock();
	}

	void *alloc();				//size_t size
	void free(void *ptr);		//, size_t size

private:
	/**
	* Number of chunks per larger block.
	*/
	size_t mChunksPerBlock;

	/**
	* Allocation pointer.
	*/
	Chunk *mHead = nullptr;

	/**
	* Allocates a larger block (pool) for chunks.
	*/
	Chunk *allocateBlock(size_t chunkSize = 1024);
};

/**
* Allocates a new block from OS.
*
* Returns a Chunk pointer set to the beginning of the block.
*/
Chunk*	Pool::allocateBlock(size_t chunkSize) {
	cout << "\nAllocating block (" << mChunksPerBlock << " chunks):\n\n";

	size_t blockSize = mChunksPerBlock * chunkSize;

	// The first chunk of the new block.
	Chunk*	mHead = reinterpret_cast<Chunk *>(mHead(blockSize));

	// Once the block is allocated, we need to chain all
	// the chunks in this block:

	Chunk *chunk = blockBegin;

	for (int i = 0; i < mChunksPerBlock - 1; ++i) {
		chunk->next =
			reinterpret_cast<Chunk *>(reinterpret_cast<char *>(chunk) + chunkSize);
		chunk = chunk->next;
	}

	chunk->next = nullptr;

	return blockBegin;
}

/**
* Returns the first free chunk in the block.
*
* If there are no chunks left in the block,
* allocates a new block.
*/
void*	PoolAllocator::alloc() {

	// No chunks left in the current block, or no any block
	// exists yet. Allocate a new one, passing the chunk size:

	if (mHead == nullptr) {
		cout << "no space left " << endl;
		return NULL;
	}

	// The return value is the current position of
	// the allocation pointer:

	Chunk*	freeChunk = mHead;
	mHead = mHead->next;
	return freeChunk;
}

void PoolAllocator::free(void *chunk) {

	// The freed chunk's next pointer points to the
	// current allocation pointer:

	Chunk* ptr = (Chunk*)chunk;
	ptr->next = mHead;
	mHead = ptr;
}
//-----------------------------
int main() {


}
