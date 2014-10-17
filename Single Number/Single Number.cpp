// Single Number
/*
关于模2的问题可以直接采用异或^，因此将所有的元素异或下来，最后剩下的那个元素就是结果了。（剑指offer原题） 
*/
#include <iostream>
using namespace std;

int singleNumber(int A[], int n) {
	if (0 == n) return 0;
	if (1 == n) return A[0];
	int ret = A[0];
	for (int i = 1; i < n; ++i) {
		ret ^= A[i];
	}
	
	return ret;
}

int main() {
	int a[10] = {1, 1, 2, 2, 3, 4, 4};
	cout << singleNumber(a, 7) << endl;
	
	return 0;
}
