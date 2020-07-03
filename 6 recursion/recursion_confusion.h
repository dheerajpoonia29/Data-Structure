int usingMyRecursion(int arr[], int k, int n){
		// base case 
			if(k>=n-1)
				return 0;

		psep1();
		for(int i=0; i<=k; i++)
			cout<<i<<" ";
		cout<<" : ";
		for(int j=k+1; j<n; j++)
			cout<<j<<" ";
		psep2();

		// recursive case
			return usingMyRecursion(arr, k+1, n);
	}

	int usingSirRecursion(int arr[], int i, int j){
		// base case 
			if(i>j)
				return 0;

		psep1();
		for(int k=i; k<j; k++)
			cout<<k<<" ";
		psep2();
		
		// recursive case 
			int temp = INT_MAX;
			for(int k=i; k<j; k++){
				temp = min(temp, usingSirRecursion(arr, i, k) + usingSirRecursion(arr, i+1, j));
			}
		
			return temp;
	}


// both code tend to print 
/*
arr = [0,1,2,3] n = 4

_________________________ 
0  : 1 2 3 ------------------------- 

_________________________ 
0 1  : 2 3 ------------------------- 

_________________________ 
0 1 2  : 3 ------------------------- 

1st correct 
2nd not printing correct
*/