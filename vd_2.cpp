// test.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include <queue>
#include <memory>

using namespace std;



int GetDigit(std::string s) {
		
		std::string input;
		char c;
		int i = 0, j = 0;
		size_t len = s.size();
		std::vector v(s.size(), -1);
	    while (i < s.size()) {
			
			c = Net::get();
			if (s[i] == c)
				i++;
			else {
				if (v[i] != -1)
					i = v[i];
				else {
					j = offset(s,i);
					v[i] = j;
					i = j;
				}
				if (s[i] == c)
					i++;
			}
		}
		
		char n = Net::get();
		return atoi(n);
	
}
//-----------------------------
int main() {


}
