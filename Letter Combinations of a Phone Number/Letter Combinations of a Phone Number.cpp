// Letter Combinations of a Phone Number
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generateLetters(string digits, int index, string temp, vector<string>& ret ) {
	string dic[10] = {"abc","def","ghi","jkl","mno","qprs","tuv","wxyz"};
	if (index == digits.length()) {
		ret.push_back(temp);
		return;
	} 
	int id = digits[index] - '2';
	for (int i = 0; i < dic[id].size(); ++i) {
		// temp += dic[id][i];
		// generateLetters(digits, index + 1, temp + dic[id][i], ret);
		// cout << "temp: " << temp + dic[id][i] << endl;
		generateLetters(digits, index + 1, temp + dic[id][i], ret);
	}
	
}

vector<string> letterCombinations(string digits) {
	vector<string> ret;
	int len = digits.length();
	if (len <= 0) {
		ret.push_back(""); 
		return ret;
	} 
	generateLetters(digits, 0, "", ret);
	
	return ret;
}

int main () {
	string s = "23"; 
	vector<string> ret = letterCombinations(s);
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << endl;
	}
	cout << endl;
	
	return 0;
}
