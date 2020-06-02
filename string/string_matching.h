#include "../macro.h"

/*

	px(matchUsingNaive("ababbaabaaab", "abaa"));
	px(matchUsingRobinKarp("ababbaabaaab", "abaa"));
	KMP obj;
	px(obj.matchUsingKMP("ababbaabaaab", "abaa"));

*/

// NAIVE ALGORITHM
/*
	preprocessing: none
	t.c: O(n.m)
	s.c: O(1)
*/
int matchUsingNaive(string txt, string pat){
	
	int idx = -1, ws, n, m;

	if(txt.size()<pat.size())
		return idx;

	// INTIALIZING WINDOW SIZE
	ws = pat.size();
	
	for(n=0; n<=txt.size()-pat.size(); n++){
		m=0;
		for(m; m<ws; m++){
			if(pat[m]!=txt[n+m]){
				break;
			}
		}

		// CHECKING IF PATTERN IS MATCH IN TEXT 
		if(m==ws)
			idx = n;
	}

	return idx;
}


// RABIN KARP ALGORITHM
/*
	preprocessing: O(m)
	t.c: average_case O(n+m);		worst_case O(n.m);
	s.c: O(m)
*/
int matchUsingRobinKarp(string txt, string pat) {
	int N = txt.size();
	int M = pat.size();

	int i, j; 
	int p = 0; // hash value for pattern 
	int t = 0; // hash value for txt 
	int h = 1; 
	int d = 256;
	int q = 101;
	int idx=-1;

	// The value of h would be "pow(d, M-1)%q" 
	for (i = 0; i < M - 1; i++) 
		h = (h * d) % q; 

	// Calculate the hash value of pattern and first 
	// window of text 
	for (i = 0; i < M; i++) 
	{ 
		p = (d * p + pat[i]) % q; 
		t = (d * t + txt[i]) % q; 
	} 

	// Slide the pattern over text one by one 
	for (i = 0; i <= N - M; i++) 
	{ 

		// Check the hash values of current window of text 
		// and pattern. If the hash values match then only 
		// check for characters on by one 
		if ( p == t ) 
		{ 
			/* Check for characters one by one */
			for (j = 0; j < M; j++) 
			{ 
				if (txt[i+j] != pat[j]) 
					break; 
			} 

			// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
			if (j == M) 
				idx = i;
		} 

		// Calculate hash value for next window of text: Remove 
		// leading digit, add trailing digit 
		if ( i < N-M ) 
		{ 
			t = (d*(t - txt[i]*h) + txt[i+M])%q; 

			// We might get negative value of t, converting it 
			// to positive 
			if (t < 0) 
			t = (t + q); 
		} 
	}

	return idx; 
}


// KNUTH MORRIS PATTERN
/*
	preprocessing: O(m)
	t.c: O(n+m)
	s.c: O(m)
*/
class KMP{
public:
	vector<size_t> preProcessing(const string & pat)
	{
			vector<size_t> table(pat.size() + 1, -1);
			for(size_t i = 1; i <= pat.size(); i++)
			{
					size_t position = table[i - 1];
					
					while(position != -1 && pat[position] != pat[i - 1])
							position = table[position];

					table[i] = position + 1;
			}

			return table;
	}

	size_t matchUsingKMP(const string & txt, const string & pat)
	{
			size_t idx = -1;
			
			const vector<size_t> table = preProcessing(pat);

			size_t txti = 0;
			size_t pati = 0;

			size_t txtSize = txt.size();
			size_t patSize = pat.size();

			while(txti < txtSize)
			{
					while(pati != -1 && (pati == patSize || pat[pati] != txt[txti]))
							pati = table[pati];

					pati++;
					txti++;

					if(pati == patSize)
							idx = txti - patSize;
			}
	
			return idx;
	}
};


// BOYER MOORE ALGORITHM
/*
	preprocessing: O(m+|Σ|)
	t.c: average_case O(n/m);		worst_case O(n);
	s.c: O(1)
*/
int boyerMooreAlgorithm(string txt, string pat){

}



