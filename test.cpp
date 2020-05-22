#include "tree/fenwick_tree.h"

int main(){
	nothing_is hard
	/*
	PROBLEM 1: FIND SUM BETWEEN GIVEN RANGE L-R
	arr[] = {6, 2 ,8, 4, 1, 9, 7}
	*/
	vector<int> arr{6, 2 ,8, 4, 1, 9, 7};

	FENWICK_TREE_RANGE_SUM tree(arr);

	pv(tree.BIT)

	// sum(1:3) = 6+2+8 = 16
	sum = tree.query(1,3);
	px(sum)

	// sum(2:6) = 2+8+4+1+9 = 24
	sum = tree.query(2,6);
	px(sum)

	// sum(1:7) = 6+2+8+4+1+9+7 = 37
	sum = tree.query(1,7);
	px(sum)

	return 0;
}
