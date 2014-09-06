#include <iostream>
#include <vector>

using namespace std;
/**
* 暴力法，超时。。 
**/
/* 
int maxArea(vector<int> &height) {
	int size = height.size();
	int max = 0;
	for (int i = 0; i < size; i++ ) {
		for (int j = i+1; j < size; j++ ) {
			int area = ( j - i ) * ( height[i] < height[j] ? height[i] : height[j] );
			if (area > max ) {
				max = area;
			}
		}
	}
	return max;
}
*/
/**
* 从两头向中间靠拢，同时更新候选值；在收缩区间的时候优先从  x, y中较小的边开始收缩；
* 假设两头的两个点组成的最大，那么收缩时，只有当收缩到的那个点的高度大于当前的高度时，才可能使得面积增加
* 收缩时，单向收缩，选择两头中较矮的那一点开始收缩 
* 这道题其实和那个夹逼法特别像 
**/ 
int maxArea(vector<int> &height) {
	int size = height.size();
	if (size == 0) return 0; 
	int left = 0;
	int right = size - 1;
	int max = (size-1) * (height[left] < height[right] ? height[left] : height[right]);
	while(left < right) {
		if(height[left] < height[right]) {
			int i = left + 1;
			while (height[i] < height[left]) {
				i++;
			}
			left = i;
			int area = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
			if (area > max) max = area; 
		}
		else {
			int i = right - 1;
			while(height[i] < height[right]) {
				i--;
			}
			right = i;
			int area = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
			if (area > max) max = area; 
		}
	}
	
	return max;
}

int main() {
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(4);
	
	cout << maxArea(vec) << endl;
	
	return 0; 
}
