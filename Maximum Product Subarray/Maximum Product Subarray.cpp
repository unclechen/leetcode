// Maximum Product Subarray
// 其实就是最大连续子数组的：乘积。。
// 应该与最大连续子数组之和做一下比较，重视动态规划的数学推导过程。	 
#include <iostream>
#include <algorithm>
#include <cmath> 
 
using namespace std;

// 具体实现:、
// 1.注意处理数组元素全部为负数的情况
// 2.注意和最大连续子数组之和不同，两个负数之积是可以为正数的 
// 思路：动态规划，positive和negative分别保存正数最大值，负数最小值（绝对值最大）; 
// 每一轮更新的时候，当a[i]为正数（>=0）时，positive=positive*a[i], negative=negative*a[i];
// 否则将positive=negative*a[i], nagative=postive*a[i](此处是positive没有更新的positive);
int maxProduct(int A[], int n) {
	int pos = 1;
	int neg = 1;
	int max_pro = INT_MIN;
	for (int i = 0;  i < n; ++i) {
		if (A[i] >= 0) {
			pos = pos * A[i];
			neg = neg * A[i];
		}
		else {
			int temp = pos;
			pos = neg * A[i];
			neg = temp * A[i];
		}
		max_pro = max(max_pro, pos);
		if (pos < 1) pos = 1; // 此处应该是pos == 0,当pos为0时，应该将pos重新置为1 
		if (neg > -1) neg = 1; // 这里也该是neg == 0,但是假如输入的数组是double时，就应该是1.0f了。 
	}
	
	return max_pro;
}

int main() {
	int a[4] = {2, 3, -2, 4};
	cout << maxProduct(a, 4);
	
	return 0;
}
