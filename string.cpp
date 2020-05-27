#include <bits/stdc++.h>
using namespace std;
// rolling hash for substring matching in  string
//problem link : https://www.codechef.com/submit/CHEFSHIP

#define MAX 100005

#define ll long long


int MOD = 1000000007;
ll p = 31; // prime value for lower case p = 53 if upper case + lower case
ll hashf[MAX], power[MAX];

void hsh(string str, int n){
    power[0]=1;
    for(int i=n-1; i>=0; i--){
        hashf[i] = ((hashf[i+1]*p)%MOD+(str[i]-'a'+1))%MOD;
        power[n-i] = (power[n-i-1]*p)%MOD;
    }
    power[n] = (power[n-1]*p)%MOD;
}

ll gethash(int l,int r){
    return (MOD-(hashf[r+1]*power[r-l+1])%MOD+hashf[l])%MOD;
}


int main(){
	int t; cin>>t;
	while(t--){
		string s;
		int cnt=0;
		cin>>s;
		int n = s.length();
		
		hsh(s, n);
		
		//cout<<s<<"\n";
		// LOGIC
		// given string a is it possible to make palindrome or not
		// if yes 
		for(int i=2; i<n; i+=2){
			ll t1 = gethash(0,i/2-1);
			ll t2 = gethash(i/2,i-1);
			ll t3 = gethash(i, (n+i)/2-1);
			ll t4 = gethash((i+n)/2,n-1);
			if(t1==t2 && t3==t4)
			cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}