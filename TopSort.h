#pragma once
#include "Node.h"
#include "DirectedGraph.h"
#include <queue>
#include <stack>
#include <map>

class TopSort
{	
public:
	//Good Code
	static map<Node, int> inDegree(DirectedGraph);
	static vector<Node> Kahns(DirectedGraph);
	static vector<Node> mDFS(DirectedGraph);
};