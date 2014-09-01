/*
** Longest Common Prefix
^
*/ 
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
	if (strs.size() == 0) return "";  // 这里不返回NULL，应该返回空字符串 "" 
	// 首先获得最大的前缀长度，即找出最短的一个字符串，这样便可以防止越界 
	int minLen = strs[0].length();
	for (int i = 0; i < strs.size(); i++ ) {
		if (strs[i].length() < minLen) {
			minLen = strs[i].length();
		}
	}
	// cout << minLen << endl; 
	// 比较每一列的字符，复杂度n平方 
	int i;
	for (i = 0; i < minLen; i++) {
		int j;
		for (j = 0; j < strs.size()-1; j++) {
			if (strs[j][i] != strs[j+1][i]) {
				break;
			}
		}
		if (j != strs.size()-1 ) {
			break;
		}
	} 
	// i便是公共前缀的长度
	return strs[0].substr(0, i); 
}

int main(){
	vector<string> vec;
	vec.push_back("a");
	vec.push_back("abce");
	vec.push_back("abcd");
	vec.push_back("abce");
	
	cout << longestCommonPrefix(vec) << endl;
	/*
	for (int i = 0; i < vec.size(); i++) {
		for(int j = 0; j < vec[i].length(); j++) {
			cout << vec[i][j] << " ";
		}
		cout<< endl;
	}*/
	return 0;  
} 
