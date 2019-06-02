#include<iostream>
#include<vector>
#include"Sparse_Array.h"

using namespace std;

int main(){
	auto vec1 = initial_2d_array(10,10);
	print_2d_array(vec1);
	
  for(auto i = 0 ; i < 10 ; ++i){
		vec1[i][i] = i;
	}
	print_2d_array(vec1);
	
  auto vec2 = to_sparse_array(vec1);
	print_2d_array(vec2);
	
  auto vec3 = to_normal_array(vec2);
	print_2d_array(vec3);
}
