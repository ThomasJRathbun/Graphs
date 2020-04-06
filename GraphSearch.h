#pragma once
#include <vector>
#include <iostream>
#include "graph.h"
#include <set>
#include "Node.h"
#include <stdlib.h>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

class GraphSearch
{
public:
	//Good Code
	static vector<Node> DFSIter(Node* source, Node* destination);
	static vector<Node> DFSRec(Node*, Node*);
	static vector<Node> DFSRecUtil(Node* source, Node* destination, vector<Node>& visited, vector<Node> path);
	static vector<Node> BFTIter(Graph);

	//In Progress
	static vector<Node> BFTRec(Graph);
	static vector<Node> BFTRecUtil(Graph, vector<Node>);

};

