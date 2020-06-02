#include "../macro.h"

char check1(){
	char c = 'a';
	return c;
	//cout<<check1(); // print: a
	//printf("%s", check1()); //	// warning: format ‘%s’ expects argument of type ‘char*’ - segmentation fault
	//printf("%c", check1()); // print: a
}

char[] check2(){
	char s[] = {'h', 'e', 'l', 'l', 'o', '\0'};
	// s[] = "hello" both are similar here it automatic add null char \0
	return s;
	// cout<<check2();	// print: hello
}

char[] check3(){
	char s[] = {'h', 'e', 'l', 'l', 'o'};
	return s;
	// cout<<check3();	// print: hello + with some garbage
}

string check4(){
	string s = "hello";
	return s;
	// cout<<check3(); // print: hello
	// printf("%s", check3()); //	warning: format ‘%s’ expects argument of type ‘char*’
	// printf("%c", check3()); // warning: format ‘%s’ expects argument of type ‘char*’
}
