#include<vector>
#include<iostream>

using namespace std;

vector<vector<int>> init_2_array(const int& row, const int& line){	//initial function 4 2d array
	vector<vector<int>> vv(row, vector<int>(line, 0));
	return vv;
}

void print_2_array(const vector<vector<int>>& vv){	//print function 4 2d array
	for(auto i :vv){
		for(auto j : i)
			cout<<j<<"\t";
		cout<<endl;
	}
}
int main(){
	auto vv = init_2_array(11,11);
	vv[1][1] = 1;
	vv[2][2] = 2;
	
	//sparse array
	int sum = 0;
	for(auto i : vv){
		for(auto j : i){
			if(j != 0)
				++sum;
		}
	}
	
	auto sparse_array = init_2_array(sum + 1, 3);
	sparse_array[0][0] = sparse_array[0][1] = 11;
	sparse_array[0][2] = sum;
	
	cout<<sum<<endl;
	
	int pos = 1;
	for(auto i = 0; i <= vv.size(); ++i){
		for(auto j = 0; j <= vv[i].size(); ++j){
			if(vv[i][j] != 0){
				sparse_array[pos][0] = i;
				sparse_array[pos][1] = j;
				sparse_array[pos][2] = vv[i][j];
				++pos;
			}
		}
	} 
} 
