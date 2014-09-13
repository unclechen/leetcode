#include <iostream>
#include <vector>

using namespace std;
/**
* 通过找规律的方法来做的，但是我的方法没有用到matrix[i][j]来找规律，用的是value值的规律
* 正确的思路应该是用下标值的规律来做 
**/
/* 
vector<int> spiralOrder(vector<vector<int> > &matrix) {
	vector<int> ret;
	vector<int> res;
	int s = matrix.size();
	if (s == 0) return res;
	int t = matrix[0].size();
	int m = s;
	int n = t;
	int j = 0;
	while(m > 0 && n > 0) {
		int i = 0;
		// cout << matrix[j][j] << endl;
		ret.push_back(matrix[j][j]);
		i++;
		while (i < n) {  //4, ret[0],[1],[2],[3]
			ret.push_back(ret[i-1] + 1);
			i++;
		}
		while (i < n+m-1) { //6, ret[4], [5]
			ret.push_back(ret[i-1] + t);
			i++;
		}
		while (i < n+m+n-2) {//9, ret[6], [7], [8]
			ret.push_back(ret[i-1] - 1);
			i++;
		}
		while (i < n+m+n+m-4) { //10, ret[9]
			ret.push_back(ret[i-1] - t);
			i++;
		}
		for (int x = 0; x < ret.size(); x++) {
			res.push_back(ret[x]);
			// cout << ret[x] << "  " ;
		}
		//cout << endl;
		j += 1;
		m -= 2;
		n -= 2;
		ret.erase(ret.begin(),ret.end());
	}
	for (int i = 0; i < s*t; i++)   // 没搞明白为啥会多一位，但是我这种方法 
	{
		ret.push_back(res[i]);
	}
	return ret;
} 
*/
vector<int> spiralOrder(vector<vector<int> > &matrix) {
	int m = matrix.size();
	vector<int> ret;
	if (0 == m) return ret; 
	int n = matrix[0].size();
	int beginX = 0;
	int endX = n-1;
	int beginY = 0;
	int endY = m-1;
	while (true) {
		for (int i = beginX; i <= endX; ++i) {
			ret.push_back(matrix[beginY][i]);
		}
		if (++beginY > endY) {
			break;
		}
		for (int i = beginY; i <= endY; ++i) {
			ret.push_back(matrix[i][endX]);
		}
		if (--endX < beginX) {
			break;
		}
		for (int i = endX; i >= beginX; i--) {
			ret.push_back(matrix[endY][i]);
		}
		if (--endY < beginY) {
			break; 
		} 
		for (int i = endY; i >= beginY; i--) {
			ret.push_back(matrix[i][beginX]);
		}
		if (++beginX > endX) {
			break;
		}
	}
	
	return ret;
} 
int main(){
	vector<vector<int> > matrix;
	vector<int> temp;
	int k = 1;
	for(int i = 0; i != 4; i++){
		for(int j = 0; j != 4; j++){
			temp.push_back(k++);
		}
		matrix.push_back(temp);
		temp.erase(temp.begin(), temp.end());
	}
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
	
	vector<vector<int> > matrix2;
	temp.push_back(3);
	matrix2.push_back(temp);
	temp.erase(temp.begin(),temp.end());
	temp.push_back(2);
	matrix2.push_back(temp);
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 1; j++){
			cout << matrix2[i][j] << "  ";
		}
		cout << endl;
	}
	
	vector<int> ret = spiralOrder(matrix2);
	for (int i = 0; i != ret.size(); i++){
		cout << ret[i] << " ";
	}
	
	return 0;
}
