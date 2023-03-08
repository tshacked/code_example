// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//-----------------------------
void Reverse(char s[])
{
	int len = strlen(s);
	// T a m a r
	char tmp;
	for (int i = 0; i < len / 2; i++) {
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}
}
//-----------------------------
//0,1,1,2,3,5,8
//get the nth Fibonacci number
int fib(int n)
{
	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}


//-----------------------------
// Tree
// struct Node {
// 	Node(int d):data(d), left(NULL), right(NULL){}
// 	int data;
// 	Node* left;
// 	Node* right;
// };
// 
// 
// Node* insert(Node* root, int data)
// {
// 	if (root == NULL) { //empty tree
// 		root = new Node(data);
// 		return root;
// 	}
// 
// 	if (data <= root->data) {
// 		root->left = insert(root->left, data);
// 	}
// 	else {
// 		root->right = insert(root->right, data);
// 	}
// 		
// 	return root;
// }
// 
// bool search(Node* root, int data) {
// 	if (root == NULL) return false;
// 	if (root->data == data) return true;
// 	if (data < root->data) {
// 		search(root->left, data);
// 	}		
// 	else {
// 		search(root->right, data);
// 	}
// }
// 
// //-----------------------------
// //Find height of a binary tree
// 
// int Findheight(Node* root) {
// 	
// 	if (root == NULL)
// 		return -1;
// 	int left = Findheight(root->left);
// 	int right= Findheight(root->right);
// 	return (left > right ? left : right) + 1;
// 	//return max(left, right) + 1;
// }

//-----------------------------
//List

struct Node{
	Node(int v):data(v), next(NULL) {}
	int data;
	Node* next;
};


Node* head = NULL;
void insert(int data) {
	Node* tmp = new Node(data);
	if (head != NULL) tmp->next = head;
	head = tmp;
}

//[1]->[4]->[7] ->[9]
void print(Node* p) {
	
	if (p == NULL) return;
	print(p->next);
	cout << p->data << endl;
}

#include <queue>
#include <memory>
//#include <pthread.h>

class Msg {
protected:
	enum MsgType {
		x,
		y,
		z
	};
	MsgType _type;
public:
	Msg(MsgType t): _type(t){};
	MsgType getType() {
		return _type;
	}

	virtual void print() { cout << "Im base MSG" << endl; }
};

class XMsg : public Msg {
public:
	XMsg():Msg(x){}
	void print() { cout << "Im X MSG" << endl; }
};

bool isPalindrome(int x) {
	int i = x, n = 0;
	while (i > 0)
	{
		//מקבל ספרת יחידות
		n = i % 10 + n * 10;
		i /= 10; 
		
	}
	return n == x;
}
bool is_prime(int n)
{
	bool is_prime = true;
	if (n == 0 || n == 1)
		return false;
	//2,3,5,7,11...
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0)
			return false;
	}

	return true;
}

#include <unordered_map>
#include <string>
//-------------------------------------------------------
// LRU cache
class LRUCache {
public:
	LRUCache(int capacity) : capacity(capacity) {}
	// Return the value of the key if the key exists, otherwise return -1
	int get(int key) {

		auto it = cache.find(key);
		if (it == cache.end()){
			cout << "Not Found Key: " << key << endl;
			return -1;
		}
		updateLRU(it);
		//update element to the start of the list

		return it->second.first;
	}
	//Update the value of the key if the key exists. 
	// Otherwise, add the key-value pair to the cache. 
	// If the number of keys exceeds the capacity from this operation, evict the least recently used key.
	void put(int key, int value) {
		auto it = cache.find(key);
		if (it != cache.end()) {
			updateLRU(it);
		}
		else {
			if (cache.size() == capacity) {
				cache.erase(lru.back()); //remove from cache
				lru.pop_back();			 // remove last element
			}
			//push to lru list the key
			lru.push_front(key);
		}
		//update the iterator
		cache[key] = { value, lru.begin() };
		
	}
	void updateLRU(unordered_map<int, pair<int, list<int>::iterator>>::iterator it) {
		int key = it->first;
		lru.erase(it->second.second); //erase using iterator
		lru.push_front(key);
		it->second.second = lru.begin();
	}
	


	int capacity;
	
	list<int> lru; // MRU ... LRU<key>
				// key - <value, iterator to lru location		
	unordered_map<int, pair<int, list<int>::iterator>> cache;
};






//-------------------------------------------------------
struct Entry
{
	int x;
};


#include <map>
int main()
{
	
	std::map<std::string, Entry> m;

	// "abc" -> Entry, x=123
	Entry e;
	e.x = 99;
	m.insert(std::pair<std::string, Entry>("Tamar", e));
	m.insert(std::pair<std::string, Entry>("Shira", e));
	m.insert(std::pair<std::string, Entry>("Eitan", e));
	for (auto i = m.begin();
		i != m.end();
		i++) {
		std::cout << i->first << " : " << i->second.x << endl;
	}

	// only if "abc" exists in m, ++x in the Entry

	auto it = m.find("Tamar");
	if (it != m.end()) {
		it->second.x = 100;
	}

	for (auto i = m.begin();
		i != m.end();
		i++) {
		std::cout << i->first << " : " << i->second.x << endl;
	}
	return 0;
	
	
	
	bool p = is_prime(5);
	cout << "5 is a prime number: " <<p<< endl;
	p=is_prime(8);;
	cout << "8 is a prime number: " << p << endl;
	return 0;

	bool b = isPalindrome(121);
	cout << "isPalindrome 121: " << b << endl;
	// Unordered map
	std::unordered_map<int, string> order;

	// Mapping values to keys
	order[292] = "Tamar";
	order[151] = "Alex";
	order[214] = "Shira";
	order[343] = "Eitan";

	// Iterating the map and 
	// printing unordered values
	for(auto i = order.begin(); 
			i != order.end();
		    i++) {
		std::cout << i->first << " : " << i->second << endl;
	}
	return 0;
}


// 	insert(10);
// 	insert(20);
// 	insert(30);
// 	print(head);
// 	
// 	
// 	
// 	Node* root = NULL;
// 	root = insert(root, 15);
// 	root = insert(root, 10);
// 	root = insert(root, 20);
// 	root = insert(root, 25);
// 	root = insert(root, 50);
// 
// 	if (search(root, 20))
// 		cout << "Found number 20" << endl;
// 
// 	cout << "Findheight = " << Findheight(root) <<endl;
	
// 	cout << "hi " << endl;
// 	int result = fib(6);
// 	cout << "fib(6): " << result << endl;
// 	char s[] = "Tamar";
// 	cout << "Reverse: " << s << endl;
// 	Reverse(s);
// 	cout << "Result: " << s << endl;




class user {
public:
	user(std::string u): name(u) {}
	bool login(std::string& username, std::string pswd);
protected:	
	std::string name;
	//std::string pswd;
	time_t failures[5] = { '\0' }; //epoc
	size_t idx;
	size_t counts;
	time_t block;
};

bool is_correct()
{
	return true;
}

//1, 4, (57, 58, 62, 70, 72)

// 1 3 4 8

//arr: 57, 58, 62, 70, 72, 
/*/
bool user::login(std::string& username, std::string pswd)
{
	time_t now = time(NULL);
	if (block) {
		if (now - block <= 300)
			return false;
		block = 0;
	}

	if (is_correct()) {
		counts = 0;
	} 
	else {
		//arr: 73, 58, 62, 70, 72,
		failures[idx%5] = now;
		idx++;
		counts++;
		
		if ((counts == 5) &&  now - failures[idx% 5] <= 300) {
			block = now + 300;
		} 

	}

}

int main() {
	user u1("tamar");
}*/