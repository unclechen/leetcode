// Valid Parentheses
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
	stack<char> ss;
	int len = s.length();
	if (0 == len) return true;
	for (int i = 0; i < len; ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			ss.push(s[i]);
		}
		else {
			if (s[i] == ')') {
				if (!ss.empty() && ss.top() == '(') {
					ss.pop();
				}
				else return false;
			} 
			if (s[i] == ']') {
				if (!ss.empty() && ss.top() == '[') {
					ss.pop();
				}
				else return false;
			}
			if (s[i] == '}') {
				if (!ss.empty() && ss.top() == '{') {
					ss.pop();
				}
				else return false;
			}
		}
	} 
	if (ss.empty()) {
		return true;
	}
	else {
		return false;
	}
}

int main () {
	string s = "([])";
	if (isValid(s)) {
		cout << "true" <<endl;
	}
	else {
		cout << "false" << endl;
	}
	
	return 0;
}
