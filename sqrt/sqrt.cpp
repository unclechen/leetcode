#include <iostream>

using namespace std;
/*
纯暴力法，已超时 
但是可以想办法做些优化 
*/ 
/* 
int sqrt(int x)
{
	for (int i = 0; i < x-1; i++ )
	{
		if (i*i <= x && (i+1)*(i+1) >= x)
		{
			if (x-i*i <= (i+1)*(i+1)-x )
			{
				return i;
			} 
			else
			{
				return i+1;
			}
		} 
	} 
}
*/
int sqrt(int x)
{
	long long left = 0;
	long long right = x/2 + 1;
	while (left <= right)
	{
		long long mid = (left + right)/2 ; 
		if (mid*mid == x)
		{
			return mid;
		}
		else if (mid*mid > x)
		{
			right = mid - 1; 
		}
		else if (mid*mid < x)
		{
			left = mid + 1;
		}
	} 
	return right;
} 
int main()
{
	int x = 15;
	cout << sqrt(x) << endl;
	
	return 0;
}
