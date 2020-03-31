#pragma once
#include <vector>
#include <iostream>
#include "graph.h"
#include <set>
#include "node.h"
#include <stdlib.h>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

class GraphSearch
{
public:
	graph g;
	vector<node> DFSIterative(string, string);
	vector<node> BFSIterative(string, string);
	vector<node> DFSRec(node, node, vector<node>&,vector<node>);
	vector<node> BFS(string, string);
	vector<node> BFSRec(node, queue<node>&, vector<node>&);
	vector<node> DFS(string, string);
	vector<node> DFSIter(node, node);
	vector<node> BFSIter(node, node);
	GraphSearch();
	~GraphSearch();
};

