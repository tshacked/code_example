// test.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include <queue>
#include <memory>

using namespace std;

class Storage {
public:
	void write(const char* token, void *buf, int len);
	void read(const char* token, void *buf, int len);

private:

	// Persistent Stuff
	hashmap<char*, PhysAddr> toknToaddrs;
	hashmap<uint64_t, char*> bufToToken;
	uint64_t HASH_FUNC(void *buf, int len);

	// above here

	typedef PhysAddr; // given
	PhysAddr PHYS_WRITE(void *buf, int len);
	void PHYS_READ(PhysAddr addr, void *buf, int len);
};

void Storage::read(const char* token, void *buf, int len) {
	// implement this
	// token --> PhysAddr
	PhysAddr addr = toknToaddrs.get(token);
	PHYS_READ(addr, buf, len);

	//put addr 
}

void Storage::write(const char* token, void *buf, int len) {
	// implement this
	// hash(buf)
	uint64_t hash = HASH_FUNC(buf, len);
    //did we store this data already?
	chat* token = bufToToken.get(hash);
	if (token) {
		PhysAddr addr = toknToaddrs.get(token);
	}
	else {
		PhysAddr new_addr = PHYS_WRITE(buf, len);
		toknToaddrs.set(token, new_addr);
		bufToToken.set(hash, token);
	}
	
}

//-----------------------------
int main() {


}
