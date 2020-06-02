#include "../macro.h"

//NOTE: n = s.size()

// Q1: REVERSE STRING INPLACE
/*___________________________
my approach: 
	1. two pointer technique: tc(n/2), sc(1)
better approach: 
	same
*/
string q1(string s){
	size_t i=0, j=s.size()-1;

	while(i<j){
		swap(s[i], s[j]);
		i++; j--;
	}

	return s;
}

// Q2: PRITING DUPLICATION CHAR IN STRING
/*______________________________________
my approach: 
	1. hash table: tc(n), sc(n)
	2. sorting: tc(nlogn),	sc(1)
better approach: 
	1. TO-DO: tc(nlogn),	sc(1)
*/
char q2(string s){
	size_t i=0;
	int arr[27] = {0};   
	// similar to hashing tech but hashing is costly

	for(auto ch: s){
		if(arr[ch-'a'])
			return ch;
		arr[ch-'a']=1;
	}
	return '0';
}


// Q3: CHECK IF TWO STRING ARE ANAGRAM
/*____________________________________
my approach: 
	1. hash table: tc(n+26), sc(2*n)
			a. storing char of both string in there seperate hshtbl 
			b. iterate over 1 to 26 char size hshtbl1 & hshtbl2 if one is set and other is unset return false
			c. if hshtbl1==hshtbl2 return true
	2. sorting: tc(nlogn),	sc(logn)
	3. better sorting: tc(n),	sc(1)
better approach: 
	1. TO-DO: tc(nlogn),	sc(1)
*/
bool q3(string s1, string s2){
	// ex: Silent is anagram of Listen 
	// ex: Army and Mary are an anagram
	if(s1.size()==s2.size()){
		sort(s1.begin(), s1.begin());
		sort(s2.begin(), s2.begin());
		pxy(s1,s2);
		for(int i=0; i<s1.size(); i++){
			if(s1[i]!=s2[i])
				return false;
		}
		return true;
	}
	else 
		return false;
}

