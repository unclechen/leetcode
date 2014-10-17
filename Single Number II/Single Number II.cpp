// Single Number II 
/* Author：@Dasiy
对int型的各个元素做不进位的加法（相加然后模2），32位都加完之后，得到得32位就是只出现一次那个数的32位。
*/
#include <iostream>
using namespace std;

int singleNumber(int A[], int n) {
	int c[32];
	for (int i = 0; i < 32; ++i) {
		c[i] = 0;
	}
    for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 32; ++j) {  // 为int 32位 每一位的值
            c[j] += (A[i] >> j) & 1; // A[i]右移32次，得到每一位对应的值，和1相与，得到需要的最后一位数
            c[j] = c[j] % 3;
		} // 为数组的每个值
    }
    // 最后得到c就是多出来的那个数，对应的二进制码，只需转化为int数就行
    int result = 0;
    for(int i = 0; i < 32; ++i) {
        result |= (c[i] << i); // 将result各bit的值置为c[i]各位的值 
        // result = result * 2 + c[i]; // why error? 
    }
    
    return result;
}
    
    
int main() {
	int a[10] = {1, 1, 1, 2, 2, 2, 3, 4, 4, 4};
	cout << singleNumber(a, 10) << endl;
	
	return 0;
}
