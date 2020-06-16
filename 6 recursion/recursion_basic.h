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

// FIND FACTORIAL
int findFactorial(int n) {
   // base case
   if (n == 0 || n == 1) return n;
 
   // Recursive step
   return n+findFactorial(n-1);
}


// FIND FIBONACCI
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