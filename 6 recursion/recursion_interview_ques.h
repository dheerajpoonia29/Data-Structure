#include "../macro.h"
int memo[100];

// pattern wise ques: https://www.byte-by-byte.com/recursion/#section7
// 12 imp ques: https://www.byte-by-byte.com/12-recursion-questions/
// https://www.byte-by-byte.com/tag/recursion/

// Q1: RECURSIVE STAICASE PROBLEM
/*
https://www.youtube.com/watch?v=7k1g-Cxb4WM
find total no of ways you can climb the stair 
1,2 possible move at a time
mm: tc(golden_raitio^n) sc(stack)
		* return q1(n, m+1)+q1(n, m+2);
		* base case when m==n return 1 else return 0
		* gives tle tc is exponential
		* golden_ratio = 1.6
ba: 
		* recursion with memoization
oa: tc(n) sc(stac)
		* dp
memset(memo, -1, sizeof(memo));  in calling function uncomment this function
*/
int q1(int n, int m){
	// base case 
	if(m==n)
			return 1;
	if(m>n)
			return 0;
	
	// recursion condition
	if(memo[m]==-1){
			memo[m] = q1(n, m+1)+q1(n, m+2);
			return memo[m];
	}
	else{
			return memo[m];
	}
}


// Q2: TOTAL PATH FROM A TO B IN N*M GRID
/*
allowed move is either right or bottom
given: dx-destination x-axis, dy-destination y-axis
mm: tc(2^n) sc(stack)
		* idea: recursion 
		* moving downward to upward 
		* note: tle occur, exponential time complexity
		* overlap count many times
bm: tc(n^2) sc(dp array)
		* idea: dp
*/
int q2(int dx, int dy){
	// base case
		// reach to starting cell: possible way = 0
		if(dx==0 && dy==0)
				return 0;
		// valid path
		if(dx==0 || dy==0)
				return 1;
		// invalid path 
		if(dx<0 || dy<0)
				return 0;
		
	// recursive condition
		return q2(dx-1, dy)+q2(dx, dy-1);
}


// Q3: GENERATE SUBARRAY USING RECURSION 
void q3(){

}


// Q4: GENERATE SUBARRAY USING RECURSION
void q4(){

}


// Q5: GENERATE SUBSEQUENCE USING RECURSION 
void q5(){ 
    
}