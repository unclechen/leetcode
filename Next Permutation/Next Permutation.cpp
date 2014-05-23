#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void reverse(vector<int> &num, int l, int r)
{
	while (l < r) 
	{
		int temp = num[l];
		num[l] = num[r];
		num[r] = temp;
		l++;
		r--;
	}
}
void nextPermutation(vector<int> &num) {
	int pos1 = -1;
	int size = num.size();
	for (int i = size - 1; i >= 1; --i)
	{
		if (num[i-1] < num[i])
		{
			pos1 = i-1;
			break;
		}
	}
	if (pos1 == -1)
	{
		reverse(num, 0, size-1);
		return;
	}
	//cout << "pos1:" << pos1 << endl;
	int pos2 = -1;
	for (int i = size - 1; i >= pos1+1; --i)
	{
		if (num[i] > num[pos1] )
		{
			pos2 = i;
			break;
		}
	}
	//cout << "pos2:" << pos2 << endl;
	int temp = num[pos1];
	num[pos1] = num[pos2];
	num[pos2] = temp;
	reverse(num, pos1+1, size-1);
}

void prevPermutation(vector<int> &num) {
	int pos1 = -1;
	int size = num.size();
	for (int i = size - 1; i >= 1; --i)
	{
		if (num[i-1] > num[i])
		{
			pos1 = i-1;
			break;
		}
	}
	if (pos1 == -1)
	{
		reverse(num, 0, size-1);
		return;
	}
	//cout << "pos1:" << pos1 << endl;
	int pos2 = -1;
	for (int i = size - 1; i >= pos1+1; --i)
	{
		if (num[i] < num[pos1] )
		{
			pos2 = i;
			break;
		}
	}
	//cout << "pos2:" << pos2 << endl;
	int temp = num[pos1];
	num[pos1] = num[pos2];
	num[pos2] = temp;
	reverse(num, pos1+1, size-1);	
} 



int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(3);
	//reverse(vec, 0, vec.size()-1);
	nextPermutation(vec);
	for(int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	prevPermutation(vec);
	for(int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	
	//试试stl库函数。。。但是要求的是，原始数组是非降序排列的才能使用。。。 
	cout << endl << "stl" << endl;
	
	next_permutation(vec.begin(), vec.end());
	for(int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	
	return 0;
	
}
