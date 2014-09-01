/*
* Longest Valid Parentheses ：最长有效圆括号 
* 1、开始以为思路很简单：就是个括号匹配的问题，一个栈即可实现。 
* 2、后来发现()(()要求输出2而不是4。这个要求是严格的两对括号紧紧挨着，不能够拆开，所以条件会比原来用栈做的那个更严格
* 修改以后直接遍历就可以了，不需要栈，pre和current比较，为一对括号时，len+2 
* 3、还是不对，发现()(())要求输出长度为6，而不是4。需要仔细斟酌一下。。 所以写出了第二个函数里的left==right条件 
* 4、依旧不对，最后上网看了下，这道题还是要用栈来做，但是要巧用栈的作用。 
*/ 

/*
int longestValidParentheses(string s) {
	stack<char> stack; 
	int maxLen = 0;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] == '(') {
			stack.push(s[i]);
		}
		else
		{
			if (!stack.empty() && stack.top() == '(') {
				maxLen += 2;
				stack.pop();
			}
		}
	} 
	return maxLen;
}*/
/*
int longestValidParentheses(string s) {
	int maxLen = 0;
	int len = s.length();
	int left = 0;
	int right = 0; 
	for (int i = 0; i < len-1; i++) {
		if (s[i]=='(') {
			if (s[i+1] == ')') {
				if (left == 0) {
					maxLen += 2;
					i++;  // 紧紧连着的两个括号，且不是一个连续的左括号 
				} 
			}
			else 
			{
				left += 1; // 连续出现左括号的数次 
			}
		} 
		else
		{
			if (s[i+1]== '(') {
				// 默认不用理 
			}
			else
			{
				right += 1; // 连续出现右括号的次数 
			}
		} 
	} 
	//cout << "  left: " << left << endl;
	//cout << " right: " << right << endl;
	//cout << "maxLen: " << maxLen << endl;
	if (left != 0) {
		if (left == right) {
			maxLen = maxLen + (left+1)*2;
		}
		else
		{
			maxLen = 2*( (right < left ? right : left) + 1 ) ;
		}
	}
	return maxLen;
}*/ 

/* 正解： 
** 思路一：一个数组标记所有匹配到的括号，然后找出数组最大的连续的被标记的下标，复杂度o(n)。 
** 思路二：一个栈来记录失配时的左括号的位置，当匹配时可以直接从失配的左括号的下一个字符开始算长度。 
** 思路三：一维动态规划思想，length[]数组。 http://blog.csdn.net/pickless/article/details/9190961
** 补充：还是要看看印象笔记，动态规划太重要了！ 
*/ 
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int longestValidParentheses(string s) {
	vector<int> flag(s.length(), 0);
	stack<int> stack;
	int maxLen = 0;
	for (int i = 0; i < s.length(); i++) {
		if(s[i] == '('){
			stack.push(i);
		}
		else
		{
			if(!stack.empty()) {
				flag[stack.top()] = 1;
				flag[i] = 1;
				stack.pop();
			}
		}
	}
	
	int left = 0;
	int right = 0;
	for (int i = 0; i < flag.size(); i++) {
		if(flag[i] == 1)
		{
			left = i;
			while (i < flag.size() && flag[i] == 1 ){
				i++;
			}
			right = i-1;
			if (right-left+1 > maxLen) {
				maxLen = right-left+1;
			}
		}
	}
	
	
	return maxLen;
} 

int main(){
	//string s = "()(())";
	string s = "(()"; // "(()()"还是不对。。唉，所有的思路全部错误了。。 
	cout << longestValidParentheses(s) << endl;
	
	return 0;
}
