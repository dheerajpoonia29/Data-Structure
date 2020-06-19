#include "macro.h"
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




int main()
{
	
	vector<int> a{ 1};
	vector<int> b{ 1};

	vector<int> res;
    
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

		pv(a);
		pv(b);
    
		int i=0, j;
    while(i<a.size() && res.size()<a.size()){
				j=0;
        while(j<=b.size()/2 && res.size()<b.size()){
                res.push_back(a[i]+b[j]);
								j+=1;
				}
				i+=1;
    }
    
    res.erase(res.begin()+a.size(), res.end());

	pv(res);

	return 0;
}