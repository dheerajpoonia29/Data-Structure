#include "macro.h"

void update(int, int);
int query(int);

/*
THEORY
1. 
	we can maintain an array BIT[] such that, at any index we can store sum of some numbers of the given array. This can also be called a partial sum tree.

	BIT[]={0} is an array of size = 1 + the size of the given array a[] on which we need to perform operations.

2.
                  {         a[x],                  if x is odd
	BIT[x] =                  a[1] + ... + a[x],     if x is power of 2
               		}
	every index i in the BIT[] array stores the cumulative sum from the index i to i - (1<<r) + 1 (both inclusive), where r represents the last set bit in the index i

3. 
	we call update() operation for each element of given array to construct the Binary Indexed Tree
	note: update for loop have syntax "x += x&-x"
	it is isolate (seperating) last bit of x and additing to current bit basically it is moving forward and udpating upcoming index ele value to to the current sum till x
	because each upcoming ele value have added with previous ele sum 

	void update(int x, int delta)    // O(log2(n))  or  no of bit in x
		for(; x <= 5; x += x&-x)        
			BIT[x] += delta;      
		x(1) -> 1,2,4      x(4) -> 4
		x(2) -> 2,4        x(5) -> 5
		x(3) -> 3,4

4.
	query() 
	int query(int x)      // O(log2(n))
		int sum = 0;
    	for(; x > 0; x -= x&-x)
        sum += BIT[x];
	example : call query(14)
						sum = BIT[14] = (a[14] + a[13])		
									isolate bit x=14 : 14(1110) is 2(10)   then x = 14-2=12
						sum = BIT[14] + BIT[12] = (a[14] + a[13]) + (a[12] + … + a[9])    
									isolate bit x=12 : 12(1100) is 4(100) thus x = 12 – 4 = 8
						sum = BIT[14] + BIT[2] + BIT[8] = (a[14] + a[13]) + (a[12] + … + a[9]) + (a[8] + … + a[1])
									last set bit in 8(1000) is 8(1000), thus x = 8 – 8 = 0				
*/


/*
PROBLEM 1: FIND SUM BETWEEN GIVEN RANGE L-R
arr[] = {6, 2 ,8, 4, 1, 9, 7}
sum(1:3) = 6+2+8 = 16
sum(2:6) = 2+8+4+1+9 = 24
*/
int arr[] = {6, 2 ,8, 4, 1, 9, 7};
int n=sizeof(arr)/sizeof(arr[0]);


/*
FENWICK TREE
main logic
*/
int BIT[n];
void update(int x, int delta)
{
  for(; x <= n; x += x&-x)
  	BIT[x] += delta;
}

int query(int x)
{
	int sum = 0;
  for(; x > 0; x -= x&-x)
  	sum += BIT[x];
  return sum;
}



