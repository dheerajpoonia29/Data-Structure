//#include "macro.h"
//#include "string/string_matching.h"
//#include "string/string_sorting.h"
//#include "string/string_top_20.h"
//#include "3 linked list/ll_basic.h"
//#include "3 linked list/ll_top20.h"
//#include "3 linked list/ll_other.h"
//#include "4 stack & queue/stack_basic.h"
//#include "4 stack & queue/queue_basic.h"
//#include "4 stack & queue/stack_pattern.h"
//#include "5 hashing/hashing_ib.h"
#include "6 recursion/recursion_basic.h"
//#include "6 recursion/recursion_interview_ques.h"
//#include "9 graph/graph_basic.h"

int main()
{
	
	int res=0;
	string a="babqprcdn", b="cabqprzcdn";
	res = lcs(a,b, a.size(), b.size(), res);
	px(res);
	
	return 0;	
}