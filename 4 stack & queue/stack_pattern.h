#include "../macro.h"

// NEAREST SMALLEST TO LEFT (NSL)
/*
{4,5,2,10,8} => {-1,4,-1,2,2}
*/
vector<int> findNSL(vector<int> arr) {
    stack<int> st;
    vector<int> nsl(arr.size(),0);
    
    for(int i=0; i<arr.size(); i++){
        while(!st.empty() && arr[st.top()]>=arr[i]) // chant to get actual vlaue instead of index 
				// while(!st.empty() && st.top()>=arr[i])
            st.pop();
            
        if(st.empty()){            
            nsl[i] = -1;
        }
        else{
            nsl[i] = st.top();
        }

				st.push(i); // change to get actual value instead of index 
				// st.push(arr[i])
    }

    return nsl;
}


// NEAREST SMALLEST TO RIGHT (NSR)
/*
{4,5,2,10,8} => {2,2,-1,8,-1}
*/
vector<int> findNSR(vector<int> arr) {
    stack<int> st;
    vector<int> nsr(arr.size(),0);
    
    for(int i=arr.size()-1; i>=0; i--){
        while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();
            
        if(st.empty()){            
            nsr[i] = -1;
        }
        else{
            nsr[i] = st.top();
        }

				st.push(i);
    }
    
    return nsr;
}


// NEAREST GREATER TO LEFT (NGL)
/*
{1,3,2,4} => {-1, -1, 3, -1}
*/
vector<int> findNGL(vector<int> arr) {
    stack<int> st;
    vector<int> ngl(arr.size(),0);
    for(int i=0; i<arr.size(); i++){
        while(!st.empty() && st.top()<=arr[i])
            st.pop();
            
        if(st.empty()){            
            ngl[i] = -1;
        }
        else{
            ngl[i] = st.top();
        }

				st.push(arr[i]);
    }

    return ngl;
}


// NEAREST GREATER TO RIGHT (NGR)
/*
{1,3,2,4} => {3,4,4,-1}
*/
vector<int> findNGR(vector<int> arr) {
    stack<int> st;
    vector<int> ngr(arr.size(),0);
    for(int i=arr.size()-1; i>=0; i--){
        while(!st.empty() && st.top()<=arr[i])
            st.pop();
            
        if(st.empty()){            
            ngr[i] = -1;
        }
        else{
            ngr[i] = st.top();
        }

				st.push(arr[i]);
    }
    
    return ngr;
}
