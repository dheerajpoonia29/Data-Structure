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
//#include "6 recursion/recursion_basic.h"
//#include "6 recursion/recursion_interview_ques.h"
#include "9 graph/graph_basic.h"

int main()
{
	vector<vector<int>> G{
		{0,1,1,0,0,0},
		{1,0,0,1,1,0},
		{1,0,0,0,1,0},
		{0,1,0,0,1,1},
		{0,1,1,1,0,1},
		{0,0,0,1,1,0}
	};
	//graphToAdjList(G);

	vector<int> path = bfs(G);
	pv(path);
	path = dfs(G);
	pv(path);

	return 0;
}