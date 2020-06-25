#include "../macro.h"
// source : https://medium.com/@codingfreak/graph-data-structure-interview-questions-and-practice-problems-22d5cd488855

// ADJANCEY LIST 
/*
graph to adjancey list conversion
*/
vector<pair<int, vector<int>>> graphToAdjList(vector<vector<int>> G){
	vector<pair<int, vector<int>>> adjList;

	for(int i=0; i<G.size(); i++){
		int vertex = i+1;
		vector<int> connected_edge;
		for(int j=0; j<G.size(); j++){
			if(G[i][j])
				connected_edge.pb(j+1);
		}
		adjList.pb(mp(vertex, connected_edge));
	}

	for(auto v: adjList){
		cout<<"\n"<<v.first<<": ";
		for(auto e: v.second)
			cout<<e<<" ";
	}

	return adjList;	
}

vector<int> bfs(vector<vector<int>> G){
	int u = 0;
	queue<int> q;
	vector<int> path;
	vector<int> visited(G.size()+1, false);

	q.push(u);
	visited[u] = true;

	while(!q.empty()){
		int u = q.front();
		path.pb(u+1);
		q.pop();

		for(int v=0; v<G.size(); v++){
			if(G[u][v] && visited[v]==false){
				q.push(v);
				visited[v] = true;
			}
		}
	}

	return path;
}


vector<int> dfs(vector<vector<int>> G){
	int u = 0;
	stack<int> s;
	vector<int> path;
	vector<int> visited(G.size()+1, false);

	s.push(u);
	visited[u] = true;

	while(!s.empty()){
		int u = s.top();
		path.pb(u+1);
		s.pop();

		for(int v=0; v<G.size(); v++){
			if(G[u][v] && visited[v]==false){
				s.push(v);
				visited[v] = true;
			}
		}
	}

	return path;
}
