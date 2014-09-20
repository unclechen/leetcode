#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int n) {
	vector<int> temp;
	vector<vector<int> > ret;
	if (0 == n) return ret;
	// 初始化一个二维vector数组 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			temp.push_back(0);	
		}
		ret.push_back(temp);
		temp.erase(temp.begin(),temp.end());
	}
	// 实际上还是和第一道旋转数组题目的思路是一样的 
	int beginX = 0;
	int endX = n-1;
	int beginY = 0;
	int endY = n-1;
	int c = 1;
	while(true) {
		for(int i = beginX; i <= endX; ++i) {
			ret[beginY][i] = c++;
		}
		if (++beginY > endY) break;
		for (int i = beginY; i <= endY; ++i) {
			ret[i][endX] = c++;
		}
		if (--endX < beginX) break;
		for (int i = endX; i >= beginX; i--) {
			ret[endY][i] = c++;
		}
		if (--endY < beginY) break;
		for (int i = endY; i >= beginY; i--) {
			ret[i][beginX] = c++;
		}
		if (++beginX > endX) break;
	}
	
	return ret;
}
int main(){
	int n = 4;
	vector<vector<int> > vec = generateMatrix(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j){
			cout << vec[i][j] << "\t";
		}
		cout << endl;
	} 
	
	return 0;
} 
