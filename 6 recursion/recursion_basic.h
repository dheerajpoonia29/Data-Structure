//Tail recursion, backtracking, and other core recursive concepts
#include "../macro.h"
int memo[100];

// TOP TO BOTTOM (5) 5->4->3->2->1
// TAIL RECURSIVE
void pattern1(int n){
	if(n==0)
		return;
	cout<<n<<" ";
	pattern1(n-1);
}

// BOTTOM TO TOP (5) 1->2->3->4->5
// NON TAIL RECURSIVE
void pattern2(int n){
	if(n==0)
		return;
	pattern2(n-1);
	cout<<n<<" ";
}

// WRONG BASE CONDITION, ANALYZE BY RECURSION TREE
void pattern3(int n){
	if(n==0)
		return;
	
	pattern3(n-1);
	pattern3(n+1);
}

// testing pending pattern4 & pattern5
int	pattern4(string a, string b, int n, int m){
		// base case 
		if(n==0 || m==0)
			return 0;

		pxy(a, b);

		// recursive case 			
		return max(pattern4(a, b, n-1, m) ,pattern4(a, b, n, m-1));
		}
}

int	pattern5(string a, string b, int n, int m){
		// base case 
		if(n==0 || m==0)
			return 0;
	
		pxy(a, b);

		// recursive case 			
		return pattern5(a, b, n-1, m);
		return pattern5(a, b, n, m-1);
		}
}

// FIND FACTORIAL
int findFactorial(int n) {
   // base case
   if (n == 0 || n == 1) return n;
 
   // Recursive step
   return n+findFactorial(n-1);
}


// FIND FIBONACCI : 1, 1, 2, 3, 5, 8
int findFibonacci(int n) {
  // base case
  if (n == 0 || n == 1) 
		return n;
  // Recursive step
  return findFibonacci(n-1) + findFibonacci(n-2);
}


// FIBONACCI WITH MEMOIZATION
// memset(memo, -1, sizeof(memo));  in calling function uncomment this function
int findFibonacciWithMemo(int n) {
	// base case
  if (n == 0 || n == 1) 
		return n;

	// if n already visited return n
	if(memo[n]!=-1)
		return memo[n];

	// Recursive step
	memo[n] = findFibonacciWithMemo(n-1) + findFibonacciWithMemo(n-2);
	return memo[n];
}

// FIND POWER TC(n)
int findExponentiationMethod1(int x, int n) {
	// base case
	if (n == 0)
		return 1;		

	// Recursive step
	else
		return (x*findExponentiationMethod1(x, n-1));
}


// FIND POWER TC(nlogn)
int findExponentiationMethod2(int x, int n) {
	// base case
	if (n == 0)
		return 1;		

	// Recursive step
	if(n%2==0){
		int y=findExponentiationMethod2(x, n/2);
		return y*y;
	}
	else
		return (x*findExponentiationMethod2(x, n-1));
}

// FIND MODULAR 
int findModularExponentiation(int x, int n, int m) {
	// base cases  
	if (x == 0)  
			return 0;  
	if (n == 0)  
			return 1;  

	// Recursive step
	// If n is even 
	if (n % 2 == 0) {  
			int y = findModularExponentiation(x, n / 2, m);  
			return (y * y) % m;  
	}  
	// If n is odd  
	else {  
			int y = x % m;  
			return (y * findModularExponentiation(x, n - 1, m) % m) % m;  
	}   
}


// REVERSE ARRAY/STRING USING RECURSION
template <class T>
void reverseArray(T &a, int low, int high){
	if(low>high){
		return;
	}
	pxy(low, high);
	// recursive case 
	reverse(a, low+1, high-1);
	swap(a[low], a[high]);
}


// INSERT USING RECURSION AT SORTED POSITION 
/*
given array insert ele at its sorted position 
arr = 0,1,5 ele = 2 
result = 0,1,2,5
*/
void insertInArrAtSortedPos(vi &arr, int ele){
	// base condition 
	if(arr.size()==0 || arr[arr.size()-1]<=ele){
		arr.push_back(ele);
		return;
	}

	// hypothesis step
	int val = arr[arr.size()-1];
	arr.pop_back();

	// recursive case / induction step
	insertInArrAtSortedPos(arr, ele);
		
	arr.push_back(val);
	return;
}


// SORT ARRAY BY RECUSRION 
//https://www.youtube.com/watch?v=AZ4jEY_JAVc&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=6
void sortArr(vi &arr){
	// base case 
	if(arr.size()==1)
		return; 
	
	// hypothesis 
	int temp = arr[arr.size()-1];
	arr.pop_back();

	// recursive case 
	sortArr(arr);

	// induction 
	insertInArrAtSortedPos(arr, temp);
	return;
}


// INSERT IN STACK USING RECUSION 
void insertInStackAtSortedPos(stack<int> &st, int ele){
	// base case 
	if(st.empty() || st.top()<=ele){
		st.push(ele);
		return;
	}

	// hypothesis 
	int temp = st.top();
	st.pop();

	// recursive / induction both mean same 
	insertInStackAtSortedPos(st, ele);

	st.push(temp);	
	return;
}


// SORT A STACK USING RECURSION 
void sortStack(stack<int> &st){
	// base case 
	if(st.empty()){
		return;
	}

	// hypothesis 
	int temp = st.top();
	st.pop();
	sortStack(st);

	// recursive / induction step 
	insertInStackAtSortedPos(st, temp);
	return;
}


// DELETE MIDDLE OF STACK 
void stackDeleteKthTopEle(stack<int> &st, int k){
	// base case  
	if(k==1){
		st.pop();
		return;
	}
	
	// hypothesis
	int temp = st.top();
	st.pop();

	// induction
	stackDeleteKthTopEle(st, k-1);
	st.push(temp);
}



// REVERSE STACK USING RECURSION : with using extra space 
stack<int> axstk;
void reverseStackUsingAuxi(stack<int> &st){
	if(st.empty())
		return;
	
	axstk.push(st.top());
	st.pop();
	
	reverseStackUsingAuxi(st);

	pstk(axstk);
}



// REVERSE STACK USING RECURSION : without using extra space 
void reverse(stack<int> &st, int ele){
	if(st.empty()){
		st.push(ele);
		return;
	}

	int temp = st.top();
	st.pop();

	reverse(st, ele);
	st.push(temp);
}

void reverseStack(stack<int> &st){
	if(st.empty()){
		return;
	}

	int temp = st.top();
	st.pop();

	reverseStack(st);
	reverse(st, temp);
}