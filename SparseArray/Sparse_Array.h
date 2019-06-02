#ifndef SPARSE_ARRAY_H
#define SPARSE_ARRAY_H

#include<vector>
#include<iostream>

using std::vector;
using std::cout;
using std::endl;
using vv = vector<vector<int>>;

vv initial_2d_array(const int& row, const int& line){	
	vv vvec(row, vector<int>(line, 0));
	return vvec;
}

void print_2d_array(const vv& vvec){	
	for(auto i :vvec){
		for(auto j : i)
			cout<<j<<"\t";
		cout<<endl;
	}
	cout<<endl;
}

vv to_sparse_array(const vv& vvec){	
	int sum = 0;
	for(auto i : vvec){
		for(auto j : i){
			if(j != 0)
				++sum;
		}
	}
	auto sparse_array = initial_2d_array(sum + 1, 3);
	sparse_array[0][0] = vvec.size();
	sparse_array[0][1] = vvec[1].size();
	sparse_array[0][2] = sum;
	int pos = 1;
	for(auto i = 0; i < vvec.size(); ++i){
		for(auto j = 0; j < vvec[i].size(); ++j){
			if(vvec[i][j] != 0){
				sparse_array[pos][0] = i;
				sparse_array[pos][1] = j;
				sparse_array[pos][2] = vvec[i][j];
				++pos;
			}
		}
	}
	return sparse_array;
}

vv to_normal_array(const vv& sp_arr){	//change a sparse array 2 a normal array
	auto norm_arr = initial_2d_array(sp_arr[0][0], sp_arr[0][1]);
	int summ = sp_arr[0][2];
	
	for(auto i = 1; i <= summ; ++i)
		norm_arr[sp_arr[i][0]][sp_arr[i][1]] = sp_arr[i][2];
	return norm_arr;
}

#endif
