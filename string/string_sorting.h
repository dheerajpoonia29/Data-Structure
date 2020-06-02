/*
tc(nlogn)	sc(logn)
*/
void sortString(string &str) 
{ 
   sort(str.begin(), str.end()); 
   cout << str; 
} 

/*
tc(n)	 sc(1)
*/
void sortString(string &str) 
{ 
		int MAX_CHAR = 26;

    // Hash array to keep count of characters. 
    // Initially count of all charters is  
    // initialized to zero. 
    int charCount[MAX_CHAR] = {0}; 
      
    // Traverse string and increment  
    // count of characters 
    for (int i=0; i<str.length(); i++) 
  
        // 'a'-'a' will be 0, 'b'-'a' will be 1, 
        // so for location of character in count  
        // array we wil do str[i]-'a'. 
        charCount[str[i]-'a']++;     
      
    // Traverse the hash array and print  
    // characters 
    for (int i=0;i<MAX_CHAR;i++) 
        for (int j=0;j<charCount[i];j++) 
            cout << (char)('a'+i); 
} 