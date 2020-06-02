#include "../../macro.h"

//GIVEN INTIAL COORDINATE OF BURNING TREE IN FOREST, FIND HOW MANY TREE CATCH WITH THIS FIRE
//TREE CATCH FIRE IF ITS ADJACENT TO BURNING TREE IN ALL 8 DIRECTION

void dfs(vector<vector<char>> forest, vector<vector<int>>& count_burn_tree, int i, int j, int m, int n, int tree_count) {
	// if current location out of forest or on current location there is water then return back
	if (i < 0 || i >= m || j < 0 || j >= n || forest[i][j] == 'w') return;

	// if current located tree is burning previously it mean that it is counted earlier then it should > -1
	// and if it is included in count then current count is greater than count till current located tree
	if(count_burn_tree[i][j]!=-1 && tree_count>=count_burn_tree[i][j])
			return;
	
	// updating burn count till current located tree
	count_burn_tree[i][j] = tree_count;
	
	// visiting all 8 direction from current located tree , dfs code
	dfs(forest, count_burn_tree, i+1, j, m, n, tree_count+1);
	dfs(forest, count_burn_tree, i, j+1, m, n, tree_count+1);
	dfs(forest, count_burn_tree, i-1, j, m, n, tree_count+1);
	dfs(forest, count_burn_tree, i, j-1, m, n, tree_count+1);
	
	dfs(forest, count_burn_tree, i-1, j-1, m, n, tree_count+1);
	dfs(forest, count_burn_tree, i-1, j+1, m, n, tree_count+1);
	dfs(forest, count_burn_tree, i+1, j+1, m, n, tree_count+1);
	dfs(forest, count_burn_tree, i+1, j-1, m, n, tree_count+1);

}
 	
int countContinousBurnTreeInForest(vector<vector<char>> forest, int burn_tree_x, int burn_tree_y) {
  if (forest.empty()) return 0;

 	int r = forest.size();
 	int c = forest[0].size();

	// each cell of this matrix contain the count of burned tree till now included iteself
 	vector<vector<int>>count_burn_tree(r, vector<int>(c, -1));

	// traversing forest and updating count_burn_tree matrix 
  dfs(forest, count_burn_tree, burn_tree_x-1, burn_tree_y-1, r, c, 1);

 	int mx = 0;
 	
	// finding maximum burn count of tree using count_burn_tree matrix
 	for (int i = 0; i < r; i++) {
 		for (int j = 0; j < c; j++) {
 			if (count_burn_tree[i][j]>mx) 
 			{
 				mx = count_burn_tree[i][j];
 			}
 		}
 	}

 	return mx;
}

int main() {
    vector<vector<char>> forest{{'w','t','t'},{'t','w','w'},{'w','t','t'}};
		pm(forest);
    cout<<"count of maxi burn tree which is adjacent to one or more tree = "<<countContinousBurnTreeInForest(forest,1,3);
    return 0;

/*
forest=
forest[i]=w t t 
forest[i]=t w w 
forest[i]=w t t 

count of maxi burn tree which is adjacent to one or more tree = 5
*/
}