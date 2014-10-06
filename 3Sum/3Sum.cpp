// 3Sum 
/*
类似于2Sum的夹逼思想，先定下一个元素val，问题就转化成了求另外两个元素之和为target=0-val。
就可以采用夹逼的思想来了。
实现：
1. 对原数组进行排序
2. 遍历排序后的数组，先定下第i个元素的值a[i]，然后在剩下的元素中采用夹逼法来找到两个元素的和为0-a[i]。 
具体操作时，将a[i]看做（left，mid，right）三元组中的left元素，那么mid和right的取值范围为（i+1，n-1） 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {
	vector<vector<int> > ret;
	if (3 > num.size()) return ret;
	sort(num.begin(), num.end());
	int size = num.size();
	vector<int> temp; 
	int current = num[0]; 
	for (int i = 0; i < size; ++i) {
		// 第一次去重，对三元组开头的元素去重 
		// 以每一个元素开头的三元组，在这个元素第一次作为三元组的left出现时，就已经全部找出来了。 
		if (i != 0 && num[i] == current) {  
			continue;
		}
		current = num[i];
		int target = 0 - num[i];
		int mid = i + 1;
		int right = size - 1;
		while (mid < right) { // O(n*n)的复杂度 
			if (num[mid] + num[right] == target) { // 找到一个三元组
				temp.push_back(num[i]);
				temp.push_back(num[mid]);
				temp.push_back(num[right]);
				// 第二次去重，对以某一个元素开头的三元组中，后面出现的三元组不能重复出现 
				// 三元组ret集合进行判重,因为是已经排好序的，所以联系加入ret中元素也是排好序的 
				// 所以只要和ret最后一个元素比较即可。 
				if (ret.size() == 0 || ret[ret.size()-1] != temp) 
					ret.push_back(temp);
				temp.clear();
				--right;
				++mid;
			}
			else if (num[mid] + num[right] > target) {
				--right;
			}
			else {
				++mid;
			}
		}
	} 
	
	return ret;
}

int main () {
	vector<int> vec;
	vec.push_back(-1);
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(-1);
	vec.push_back(-4);
	vec.push_back(-1);
	
	vector<vector<int> > ret = threeSum(vec);
	
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << "\t"; 
		}
		cout << endl;
	}
	
	return 0;
}
