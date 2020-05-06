#include "../cp_contest/my_macros.h"
//#include "binary_search_tree.h"
#include "heap.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    vector<int> v{4,2,6,1,3,5,7};
    int n = v.size();
    i=0;

    buildHeap(v,"max");

    DBx(kThMax(v,n, 3))


    return 0;
}
