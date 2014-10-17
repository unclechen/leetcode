// Remove Duplicates from Sorted Array
/*
这道题目还得把数组的内容改变，不光要返回元素的个数
因此还需要改变A[ret++]的值，看leecode上应该是要求将ret个所有不重复的元素放在前面数组的0->ret-1个位置上 

题目要求不能开辟新的数字来保存结果，那么要巧用原数组，也就是说元组被遍历过的位置，可以用来存放最终的结果
我们使用ret来标记存放的结果的下标，ret本来就是和新数组的元素的个数对应的 
*/
#include <iostream>
using namespace std;

int removeDuplicates(int A[], int n) {
	if (0 == n) return 0;
	if (1 == n) return 1;
	int temp = A[0];
	int repeat = 0;
	int ret = 0; // 不重复的元素个数 
	// int ans = 0; // 重复的元素个数 
	for (int i = 1; i < n; ++i) {
		if (temp == A[i]) {
			if (0 == repeat) {
				A[ret] = temp; // 很危险的操作，这得ret是从0开始算的，而i从1开始算，但这里不会有错，因为只允许出现一次 
				++ret; // 从0变为1时
			} 
			repeat = 1;
		}
		else {
			if (0 == repeat) {
				A[ret] = temp;
				++ret; // 出现不重复元素时 
			}
			temp = A[i];
			repeat = 0; 
		}
	}
	if (0 == repeat) {
		A[ret] = temp;
		++ret;
	}
	
	return ret;
}

int main() {
	int a[] = {1, 1, 2, 3, 3, 3, 4, 4, 5};
	
	cout << removeDuplicates(a, 9) << endl;
	
	return 0;
}
