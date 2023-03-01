// test.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include <queue>
#include <memory>

using namespace std;

// struct circular{
// 	uint8_t* buffer;
// 	size_t head;
// 	size_t tail;
// 	const size_t max; //of the buffer
// 	//bool full;
// };



struct circular {
	uint8_t buffer[8];
	size_t head = 0;
	size_t tail = 0;
	size_t max = 8; //of the buffer
	bool full = false;
};


circular XX;
int push(uint8_t data)
{
	int next = XX.head + 1;  // next is where head will point to after this write.
	if (next >= c->max)
		next = 0;

	if (next == XX.tail)  // if the head + 1 == tail, circular buffer is full
		return -1;

	XX.buffer[c->head] = data;  // Load data and then move
	XX.head = next;             // head to next data offset.
	return 0;  // return success to indicate successful push.
}
//-----------------------------
int main() {


}
