// 4Sum
/*
和3Sum一样，先排序，再确定两个元素，转化成为2Sum问题，夹逼法解决。关键点在于去重 
但是由于我们确定两个元素就需要O(n*n)的复杂度，所以这种思路的整体复杂度是O(n*n*n) 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target) {
	int size = num.size();
	vector<vector<int> > ret;
	if (size < 4) return ret;
	sort(num.begin(), num.end());
	for (int i = 0; i < size; ++i) {
		if (i != 0 && num[i] == num[i-1]) continue; // 第一次去重 
		for (int j = i + 1; j < size; ++j) {
			if (j != i+1 && num[j] == num[j-1]) continue; // 第二次去重
			int left  = j + 1;
			int right = size - 1;
			while (left < right) {
				int sum = num[i] + num[j] + num[left] + num[right]; 
				if (target == sum) {
					vector<int> temp;
					temp.push_back(num[i]);
					temp.push_back(num[j]);
					temp.push_back(num[left]);
					temp.push_back(num[right]);
					// 第三次去重，经过两次去重之后，找到新四元组只可能是和ret中的最后一个四元组重复 
					if (ret.size() == 0 || ret[ret.size()-1] != temp) {  
						ret.push_back(temp);
					}
					++left;
					--right; 
				}
				else if (sum > target) {
					--right;
				} 
				else {
					++left;
				}
			}  
			
		}
	}  
	
	return ret;
} 

int main () {
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(0);
	vec.push_back(-1);
	vec.push_back(0);
	vec.push_back(-2);
	vec.push_back(2);
	
	vector<vector<int> > ret = fourSum(vec, 0);
	
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << "\t"; 
		}
		cout << endl;
	}
	
	return 0;
}
