/*
Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
/*
思路很简单，又是哈希。将数组里的元素全部映射到hash表之后
遍历数组，检查该元素左右两边的数字是否存在，存在则说明当前序列连续，更新左边和右边的leftLen, rightLen
每轮循环停止时，判断一下这个连续序列的长度是否大于前一个序列的长度，大于则更新maxlen 
*/

#include <iostream>
#include <vector>
//#include <unordered_set>  // dev-c包含头文件出错，暂时用set代替，但是set的复杂度是log级别的，而unordered_set内部实现是散列表 
#include <set>
using namespace std; 

int longestConsecutive(vector<int> &num) {
	//unordered_set<int> flag;  // 只有使用unordered_set才能实现o(n)复杂度 ，leetcode上显示的是60ms 
	set<int> flag; // 实际上这个log(n)的复杂度在oj上也能过，104ms过；这也说明了即使是使用排序法那也可以过的 
	// 初始化哈希表，将数组个元素插入哈希表 
	for (int i = 0; i < num.size(); i++){
		flag.insert(num[i]);
	}
	int maxLen = 0;
	for (int i = 0; i < num.size(); i++) {
		int leftLen = 0;
		int currentVal = num[i] - 1;
		while ( flag.find(currentVal) != flag.end() ) {
			leftLen += 1;
			flag.erase(currentVal); // 这一步非常关键，是优化时间复杂度的关键点 
			currentVal --;
		}
		
		int rightLen = 0;
		currentVal = num[i] + 1;
		while( flag.find(currentVal) != flag.end() ) {
			rightLen += 1;
			flag.erase(currentVal); // 这一步非常关键，是优化时间复杂度的关键点 
			currentVal ++;
		} 
		
		flag.erase(num[i]);  // 这一步非常关键，是优化时间复杂度的关键点 
		if ( (leftLen + rightLen + 1) > maxLen) {
			maxLen = leftLen + rightLen + 1 ; 
		}
	} 
	
	return maxLen;
}

int main()
{
	vector<int> vector;
	vector.push_back(100);
	vector.push_back(4);
	vector.push_back(200);
	vector.push_back(1);
	vector.push_back(3);
	vector.push_back(2);
	
	cout << longestConsecutive(vector) << endl;  
	
	return 0;
	
}
