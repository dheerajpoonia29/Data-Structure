#include "..\cp_contest\my_macros.h"

// THIS HEADER FILE CONTAIN GOOD PROBLEM FUNCTION BASED ON HEAP
// STL > HEAP

buildHeap(vector<int> &v, string ch){
		if(ch.compare("max")==0){
				make_heap(v.begin(), v.end());
				/*
				or
				priority_queue<int> maxHeap();    push, pop, empty, top
				*/
		}
		else{
				make_heap(v.begin(), v.end(), greater<>{});
				/*
				or
				priority_queue<int, vector<int>, greater<int>()> minHeap; push, pop, empty, top
				*/
		}
}

void insertInHeap(vector<int> &v, int ele){
		v.pb(ele);
		push_heap(v.begin(), v.end());
}

int heapMaxMinEle(vector<int> v, int n){
		if(n<1)
				return -1;
		return v[0];
}

void removeInHeap(vector<int> &v){
		pop_heap(v.begin(), v.end());
		v.pop_back();
}

void deleteHeap(vector<int> &v){
		sort_heap(v.begin(), v.end());
}

bool isHeap(vector<int> v){
		return is_heap(v.begin(), v.end());
		/*----------------------------------------------
		// using is_heap_until() to check position
		// till which container is heap
		auto it = is_heap_until(v1.begin(), v1.end());
		-----------------------------------------------*/
}

int kThMaxHeap(vector<int> v, int k, int n){
		if(n<1){
				return -1;
		}
		k-=1;
		vector<int> temp = v;
		while(k--){
				rmMaxMin(temp);
				n--;
		}
		return heapMaxMinEle(temp, n);
}


