// Unique Binary Search Trees
#include <iostream>

using namespace std;

int numTrees(int n) {
	int dp[n+1];
	for (int i = 0; i < n+1; ++i) {
		dp[i] = 0;
	}
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < n+1; i++) {
		for (int j = 0; j < i; j ++) {
			dp[i] += dp[j]*dp[i-1-j];
		}
	}
	
	return dp[n];
}

int main() {
	int n = 3;
	cout << numTrees(n) << endl;
	
	return 0;
} 
