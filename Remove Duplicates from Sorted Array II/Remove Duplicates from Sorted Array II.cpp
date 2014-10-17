// Remove Duplicates from Sorted Array II 
/*
little tricky，重复元素要出现两次。 思路还是和第一题一样的。 
*/
#include <iostream>
using namespace std;

int removeDuplicates(int A[], int n) {
	if (0 == n) return 0;
	if (1 == n) return 1;
	int temp = A[0];
	int repeat = 0; // 某一个元素重复的次数
	int count = 0;
	for (int i = 1; i < n; ++i) {
		if (temp == A[i]) {
			if (0 == repeat) {
				A[count++] = temp;
				A[count++] = temp;
			}
			++repeat;
		} 
		else {
			if (0 == repeat) { 
				A[count++] = temp;
			}
			temp = A[i];
			repeat = 0;
		}
	} 
	if (repeat == 0) {
		A[count++] = temp;
	}
	
	return count;
}

int main() {
	int a[] = {1, 1, 2, 3, 3, 3, 4, 4, 5};
	
	cout << removeDuplicates(a, 9) << endl;
	
	for (int i = 0; i < 9; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	
	return 0;
}

