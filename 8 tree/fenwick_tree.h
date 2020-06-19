#include "../macro.h"


// PROBLEM 1: FINDING SUM BETWEEN GIVEN RANGE [L-R]

class FENWICK_TREE_RANGE_SUM{
public:
	vector<int> BIT;
	int n;

	FENWICK(vector<int> arr){
		this->n = arr.size();
		
		BIT.assign(n,0);

		for(size_t i=1; i<=n; i++){
			update(i, arr[i-1]);
		}	
	}

	void update(int x, int delta)    // index, value
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

	int query(int l, int r) {
		return query(r) - query(l - 1);
	}

};

/*

	int main(){
			nothing_is hard
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
*/


// PROBLEM 2: NO OF ELEMENT IN ARRAY GREATER THAN EQUAL TO K IN GIVEN RANGE [L-R]

class FENWICK_TREE_K_COUNT{
public:
	vector<int> BIT;
	int n;

	FENWICK(vector<int> arr){
		this->n = arr.size();
		
		BIT.assign(n,0);

		for(size_t i=1; i<=n; i++){
			update(i, arr[i-1]);
		}	
	}

	void update(int x, int delta)    // index, value
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

	int query(int l, int r) {
		return query(r) - query(l - 1);
	}

};