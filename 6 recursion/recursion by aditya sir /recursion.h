//	HEIGHT OF BINARY TREE 


//	SORT ARRAY
class SORT_ARRAY{ 
	/*
		insertInArrAtSortedPos
			insert using recursion at sorted position 
			given array insert ele at its sorted position 
			arr = 0,1,5 ele = 2 
			result = 0,1,2,5
	*/
	public:

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

		void sortArr(vi &arr){
			// base case 
			if(arr.size()==1)
				return; 
			
			// hypothesis 
			int temp = arr[arr.size()-1];
			arr.pop_back();

			// recursive case / induction
			sortArr(arr);
			insertInArrAtSortedPos(arr, temp);
		}

};



// SORT STACK 
class SORT_STACK{
	public:
	
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

};


// DELETE kth/MIDDLE ELEMENT OF STACK 
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


// REVERSE STACK
class REVERSE{
	public: 

	void reverseUtil(stack<int> &st, int ele){
		if(st.empty()){
			st.push(ele);
			return;
		}

		int temp = st.top();
		st.pop();

		reverseUtil(st, ele);
		st.push(temp);
	}

	void reverseStack(stack<int> &st){
		if(st.empty()){
			return;
		}

		int temp = st.top();
		st.pop();

		reverseStack(st);
		reverseUtil(st, temp);
	}

};


// KTH SYMBOL IN GRAMMER 


// TOWER OF HANOI 


// PRINT SUBSET | POWER SET | SUB SEQUENCES 






