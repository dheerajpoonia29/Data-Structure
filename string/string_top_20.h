#include "../macro.h"

// Q1: REVERSE STRING INPLACE
/*___________________________
MY APPROACH: 
	1. two pointer technique: tc(n/2), sc(1)
BETTER APPROACH: 
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
MY APPROACH: 
	1. hash table: tc(n), sc(n)
	2. sorting: tc(nlogn),	sc(1)
BETTER APPROACH: 
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
MY APPROACH: 
	1. hash table: tc(n+26), sc(2*n)
			a. storing char of both string in there seperate hshtbl 
			b. iterate over 1 to 26 char size hshtbl1 & hshtbl2 if one is set and other is unset return false
			c. if hshtbl1==hshtbl2 return true
	2. sorting: tc(nlogn),	sc(logn)
	3. better string sorting: tc(n),	sc(1)
BETTER APPROACH: 
	1. TO-DO: tc(nlogn),	sc(1)
*/
bool q3(string s1, string s2){
	// ex: Silent is anagram of Listen 
	// ex: Army and Mary are an anagram
	
	if(s1.size()==s2.size()){
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		for(int i=0; i<s1.size(); i++){
			if(s1[i]!=s2[i])
				return false;
		}
		return true;
	}
	else 
		return false;
}


// Q4: PERMUTATION OF STRING
/*__________________________ 
MY APPROACH: 
	1. loop: tc(n^r), sc(1)
		 * r=2 so we use 2 nested loop similar 3, 4 
		 * Note: but we don't create dynamic nested loop 
		 * therefore we need recursion
	2. next_permutation stl: tc(n*n!)
	3. recursion+backtracking: tc(n*n!)
		 n*n! = O(time to compute 1 factorial(which is equal to length of string)* total perumtation)

BETTER APPROACH: 
	2 & 3
*/
class Q4{
public:

	void permute(string s, int l, int r, vector<string> &p) 
	{ 
		int i; 
		if (l == r) 
			p.pb(s);
		else
		{ 
			for (i = l; i <= r; i++) 
			{ 
				swap(s[l], s[i]); // combination
				permute(s, l+1, r, p);  // recursion 
				swap(s[l], s[i]); //backtrack (restore for the next round)
			} 
		} 
	} 

	// N: TOTAL OBJ 
	// R: OUT OF TOTAL N, R WE HAVE TO CHOSEN OBJECT

	vector<string> findPermutation(string str){	
		vector<string> p; // STORING PERMUTATION
		permute(str,0,2,p);
		return p;
	}

};


// Q5: REVERSE STRING USING RECURSION 
/*__________________________ 
MY APPROACH: 

BETTER APPROACH: 
*/
void q5(string &s, int i, int j){
	if(i>j)
		return;
	q5(s, i+1, j-1);
	swap(s[i], s[j]);
}


// Q6: CHECK STRING CONTAIN ONLY DIGIT
/*__________________________ 
MY APPROACH: 
	1. inbuld function isdigit 
	2. (*s-'0')>=48  &&  (*s-'0')<=57
		 * 0-48
		 * 9-57
BETTER APPROACH: 
*/
bool q6(string s){
	for(auto ch: s)
		if(isdigit(ch)==0)
			return false;
	return true;
}

// Q7: SIMILAR TO Q2 

// Q8: COUNT VOWEL AND CONSONENT
/*
MY APPROACH:
	1. char[26] vowel = [1,0,0,0,1,...]
								 (a,b,c,d,e,...)
			if vowel[s[i]-'a'-1] == 1 then s[i] is vowel other wise consonent
	2. switch case-> vowel; defaul-> consonent;
*/

// Q9: COUNT OCCURENCE OF GIVEN CHAR OF STRING
/*
MY APPROACH:
	1. char[26] occurrence = [1,0,0,0,1,...]
			for i in range(n)
				occurrence[s[i]-'a'-1]++
*/

// Q10: PRINT FIRST NON REPEATED CHARACTER 
/*________________________________________ 
MY APPROACH: 
	1. char array: tc(128*n) sc(n) 
		 * int charArr[128] = {0}; 
		 * charArr[(int)(ch)]++;  where: s[0]<=ch<=s[n]
		 * if(charArr[i]==1) then non_repeat_char = (char)(i);  where: 0<=i<128
		 note: it is fail aabbcczZ -> z but approach 1st return Z 
		 becuse z(122) Z(90) so Z comes first in ascii but in actual string it comes after
		 
		 but we correct it at every time charArr[i]==1 then instead of break run it complete and ans_idx = min(ans_idx, j);  where j in index of charArr[i] char in string
	
	2. dictionary: tc(n) sc(n)
		 key = s[i], value = dic[key]++
		 sort dictionary based on key; note: sorting must be stable sort
		 return key where value==1

	3. queue & charArr: tc(n) sc(n+n)
		 
BETTER APPROACH: 
*/
char q10(string s){
	int charArr[128] = {0}; 
	vector<char> q;
	q.pb('_');
	for(auto ch: s){
		if(charArr[(int)(ch)]==1){
			if(q.size()>=2 && q[1]==ch){
				vector<char>::iterator it = q.begin();
				q.erase(it+1);
			}
		} 
		else{
			q.pb(ch);
			charArr[(int)(ch)]=1;
		}
	}
	if(q.size()>1)
		return q[1];
	
	// all are repated 
	return q[0];
}

// Q11: IMPLEMENT ATOI (STRING TO INTEGER CONVERSION)
/*________________________________________ 
MY APPROACH: 
	1. tc(n) sc(1)
		 * iterate over ch 
		 * if(isdigit(ch)) continue
		 * else return ch index 
BETTER APPROACH: 
*/

// Q12: REVERSE WORD IN GIVEN SENTENCE WITHOUT USING EXTRA LIBRARY
/*
MY APPROACH: 
	1. O(n + m/2)
		* find match
		* reverse using two pointer 
BETTER APPROACH: 
*/

// Q13: CHECK TWO STRING ARE ROTATION OF EACH OTHER
/*
MY APPROACH: 
	1. generate all ROTATION
		 then match 
BETTER APPROACH:
  1. concatenate and check
			(IndiaVsEngland, EnglandIndiaVs)
			concatenate = IndiaVsEnglandIndiaVsEngland
			so EnglandIndiaVs present in concatenate string then return yes 

			(IndiaVsAustralia, AustraliaVsIndia)
			concatenate = IndiaVsAustraliaIndiaVsAustralia
			AustraliaVsIndia not in concatenate string return false
		
		check 
			concatenate.indexof(rotated_string)!=-1
				return true 
			return false 
*/

// Q14: CHECK STRING IS PALINDROME OR NOT
/*
MY APPROACH: 
	1. tc(log2n or n/2) sc(1)
BETTER APPROACH:
*/


// Q15: LENGTH LONGEST SUBSTRING WITHOUT REPEATING CHARACTER
/*
MY APPROACH: 
	1. tc(n^2) sc(128)
	   * use chararr while2(i to j) until chararr(char)==1
		 * else starting from i+=1
	2. 
BETTER APPROACH:
	1. use queue tc(n*sizeofqueue) not clear; sc(n);
		 * if q.front()==s[i] then remove q.front and s.push(s[i])
		 * else q.push(s[i])
*/
string q15(string s){
	// px(q15("aabcddyxdxydcapadcmnapaz");  //a_a, abcd_d, dxy_d, xydcap_a, dcmnap_a, az => 8
	// px(q15("aabcdddcapaz");  //a_a, abcd_d, d_d, dcap_a, paz => 4
	int charArr[128] = {0};
	int i=0, ms=1, mssf=0;
	string res="";

	queue<char> q;
	while(charArr[(int)(s[i])]==0 && i<s.size()){
		q.push(s[i]);
		charArr[(int)(s[i++])]=1;
		res+=s[i];
	}
	
	charArr[128] = {0};

	mssf = i;
		
	while(i<s.size()){
		
		while(charArr[(int)(s[i])]==1 && !q.empty()){
			charArr[(int)(q.front())] = 0;
			q.pop();			
		}

		q.push(s[i]);
		charArr[(int)(s[i])] = 1;
		
		i+=1;
		
		if(q.size()>mssf){
			mssf = q.size();
			res = "";
			queue<char> temp = q;
			while(!temp.empty()){
				res+=temp.front();
				temp.pop();
			}
		}
	}

	return res;
}


// Q16: LONGEST PALINDROMIC SUBSTRING IN STRING *(TO-DO)
/*
MY APPROACH =: 
	1.tc(n^3)
		* geneate window O(n^2)
		* check palindrome (n/2 or log2n) overall 
	2.tc(n^2)
		* dynamic programming
	3.tc(n)
		* manacher's algorithm
		* https://www.youtube.com/watch?v=V-sEwsca1ak
BETTER APPROACH =:	
*/
string q16(string s){
	//px(q16("aadcddyddcxyyxcdd"));  // aa_d dcd_d ddydd_c ddcxyyxcdd =: 10 ddcxyyxcdd
	//px(q16("aadcdddyddcxcddcxddcxcddz"));  // aa_d dcd_d ddd_y ddydd_c cxc_d xcddcx ddcxcdd_z =: 7 ddcxcdd
	string res="";

	//https://github.com/mission-peace/interview/blob/master/src/com/interview/string/LongestPalindromeSubstring.java

	return res;
}


// Q17: CONVERT BYTE ARRAY TO STRING
/*
unalbe to understand


// Q18: REMOVE DUPLICATE CHARACTER FROM STRING
/*
MY APPROACH =: 
	1.tc(n)
		* using charArr[128]
		* if charArr[i] == 1 then remove s[i]
BETTER APPROACH =:


// Q19: MAXIMUM OCCURRING CHARACTER IN STRING 
MY APPROACH =: 
	1.tc(logn)  sc(n)
		* using priority queue 
		* priority queue maxi property depend upon the maxi occurrence  
		* return top of priority queue which is over maxi occurring char
BETTER APPROACH =:


// Q20: REMOVE CHAR FROM STRING 
MY APPROACH =: 
	1.tc(n)
		* if s[i] == delete_char
			* shift char rightmost to current i
BETTER APPROACH =:


//https://hackernoon.com/20-string-coding-interview-questions-for-programmers-6b6735b6d31c