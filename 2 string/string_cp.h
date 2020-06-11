#include "../macro.h"

// PROBLEM LINK :- https://www.codechef.com/submit/CHEFSHIP
/*_________________________________________________________
	GIVEN: string 
				 l,r of substring1 
				 l,r of substring2
				 over q quries
	FIND: 
		count how many times 
		substring1==substring2 
*/
class RollingHash{
public:	
	int MAX = 100005;
	int MOD = 1000000007;
	ll p = 31; // prime value for lower case p = 53 if upper case + lower case
	ll hashf[MAX], power[MAX];
	void makeHash(string str, int n){
    power[0]=1;
    for(int i=n-1; i>=0; i--){
        hashf[i] = ((hashf[i+1]*p)%MOD+(str[i]-'a'+1))%MOD;
        power[n-i] = (power[n-i-1]*p)%MOD;
    }
    power[n] = (power[n-1]*p)%MOD;
	}

	ll getHash(int l,int r){
		return (MOD-(hashf[r+1]*power[r-l+1])%MOD+hashf[l])%MOD;
	}

	string s;
	cin>>s;
	int n = s.length();
	
	makeHash(s, n);
	
	vector<vector<pair<int,int>>, vector<pair<int,int>>> queries{
		{	{1,3}, {5,7}},
		{	{4,8}, {6,10}},
	}

	for(auto q: queries){
		int s1l,s1r	& s2l,s2r 
		/* let say 
		if(substring(s1l,s1r)==substring(s2l,s2r))
			cnt++;
		note: this will take O(quries*(max(len(substring))))
		*/
		ll ss1 = getHash(s1l, s1r);
		ll ss2 = getHash(s2l, s2r);
		if(ss1==ss2)
			cnt++;
		// this will take O(quries time)+O(preprocessing time)
	}
}