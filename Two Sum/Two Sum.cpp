#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*利用库函数进行快排，然后再用夹逼法来进行查找 
但是！！本地跑通，提交上去的时候居然是 RE 。。检查出来又是 j = num.size()越界了。。难到这个dev-c++检查不出来？？ 
*/
vector<int> twoSum(vector<int> &numbers, int target) 
{
	vector<int> result;
	vector<int> num = numbers;
	sort(num.begin(), num.end());
	int i = 0;
	int j = num.size()-1;
	while (i < j)
	{
		if ( (num[i] + num[j]) == target )
		{
			int left, right;
			for (int k = 0; k < numbers.size(); ++k)
			{
				if (numbers[k] == num[i])
				{
					left = k + 1;
				}
			}
			for (int k = 0; k < numbers.size(); ++k)
			{
				if (k == left-1)
					continue; 
				if (numbers[k] == num[j])
				{
					right = k + 1;
				}
			}
			if (left < right)
			{
				result.push_back(left);
				result.push_back(right);
			}
			else
			{
				result.push_back(right);
				result.push_back(left);
			}
			break; 
		}
		else if ( (num[i] + num[j]) > target )
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	return result; 
}

/*暴力法，提交检验已超时 
*/ 
/* 
vector<int> twoSum(vector<int> &numbers, int target) 
{
	vector<int> result;
	for (int i = 0; i < numbers.size(); ++i)
	{
		for (int j = i + 1; j < numbers.size(); ++j)
		{
			if ( (numbers[i] + numbers[j]) == target )
			{
				result.push_back(i+1);
				result.push_back(j+1);
				return result;
			}
		}
	}
	return result; 
}
*/
int main()
{
	vector<int> vec;
	int target = 0;
	vec.push_back(-3);
	vec.push_back(4);
	vec.push_back(3);
	vec.push_back(90);
	vector<int> result = twoSum(vec, target);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	
	return 0;
} 
