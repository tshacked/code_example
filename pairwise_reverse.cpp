// test.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include <queue>
#include <memory>

using namespace std;


struct List {
	// define this please 
	struct node {
		node* next;
	}

	node* head;
}

// input: n1 -> n2 -> n3 -> n4
// output: n2 -> n1 -> n4 -> n3


struct list
{
	struct Node {
		Node(int v) :data(v), next(NULL) {}
		int data;
		Node* next;
	};

	Node* head = nullptr;
};
void pairwise_reverse(List *list)
{
	
	
	if (list->head == nullptr || list->head->next == nullptr) //empty or one element
		return;

	 
	Node* prev = nullptr;			//prev
	Node* curr = list->head;	//1st
	Node* next = nullptr;
	list->head = curr->next;	//set new head
	//        c     n
	// input: n1 -> n2 -> n3 -> n4
	// output: n2 -> n1 -> n4 -> n3
	while (curr && curr->next) {

		next = curr->next;
		curr->next = next->next;
		next->next = curr;
		if (prev)
			prev->next = next;
		prev = curr;
		curr = curr->next;
	}
}


	int maxProfit(vector<int>& prices) {
		// prices = [7,1,5,3,6,4]
		//          [7,6,4,3,1]
		// day 5
		int maxProfit = 0;
		int minPrice = 10000;
		for (size_t i = 0; i < prices.size(); i++) {
			if (minPrice > prices[i]) {
				minPrice = prices[i];
			}
			else if (prices[i] - minPrice > maxProfit) {
				maxProfit = prices[i] - minPrice;
			}

		}
		return maxProfit;
	}
//-----------------------------
//1,2,3,4,5

//-----------------------------
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int prod = 1, zeroCnt = count(begin(nums), end(nums), 0);
		if (zeroCnt > 1) return vector<int>(size(nums));               // Case-1
		for (auto c : nums)
			if (c) prod *= c;         // calculate product of 
		for (auto& c : nums)
			if (zeroCnt)
				c = c ? 0 : prod;    // Case-2
			else
				c = prod / c;        // Case-3
		return nums;
	}
};
//-----------------------------
int main() {


}
