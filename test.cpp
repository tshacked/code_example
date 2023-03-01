// test.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include <queue>
#include <memory>

using namespace std;

//-----------------------------

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

class YMsg : public Msg {
public:
	YMsg() :Msg(y) {}
	void print() { cout << "Im Y MSG" << endl; }
};

class SyncQueue {
public:
	SyncQueue() {
		cond = PTHREAD_COND_INITIALIZER;
		mutex = PTHREAD_MUTEX_INITIALIZER;
	}

	static void* start_producer(void * arg) { //arg is this
		SyncQueue* sq = (SyncQueue*)arg;
		sq->producer();
	}
	void * producer() {
		for (int i = 0; i < loops; i++) {
			pthread_mutex_lock(&mutex); // acquire the lock
			if (q.size() == max) { // check if the buffer is full
				cout << "producer: queue is full. waiting " << q.size() << endl;
				pthread_cond_wait(&cond, &mutex); // wait on the CV
				cout << "producer: woke from queue is full" << endl;
			}
			cout << "producer: pushing " <<i<< endl;
			q.push(i); // produce!
			pthread_cond_signal(&cond); // signal the CV
			pthread_mutex_unlock(&mutex); // release the lock
		}
	}

	static void* start_consumer(void * arg) { //arg is this
		SyncQueue* sq = (SyncQueue*)arg;
		sq->consumer();
	}
	void* consumer() {
		for (int i = 0; i < loops; i++) {
			pthread_mutex_lock(&mutex); // acquire the lock
			if (q.size() == 0) // check if the buffer is empty
			{
				cout << "consumer: queue is empty. waiting" << endl;
				pthread_cond_wait(&cond, &mutex); // wait on the CV
				cout << "consumer: wokeup. getting item" << endl;
			}
			int tmp = q.front(); // consume!
			q.pop();
			pthread_cond_signal(&cond); // signal the CV
			pthread_mutex_unlock(&mutex); // release the lock
			cout << "consumer: got item " << i << endl;
		}
	}

protected:
	queue<int> q;
	pthread_cond_t  cond;
	pthread_mutex_t mutex;
	size_t loops = 10;
	size_t max = 5;
};


//-----------------------------
int main() {

	SyncQueue queue;
	pthread_t producer, consumer;
	//pthread_create
	pthread_create(&producer, NULL, SyncQueue::start_producer, &queue);
	pthread_create(&consumer, NULL, SyncQueue::start_consumer, &queue);

	pthread_join(producer, NULL);
	pthread_join(consumer, NULL);

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
 	return 0;
}




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