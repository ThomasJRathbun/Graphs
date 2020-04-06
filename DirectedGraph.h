#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>

using namespace std;

class DirectedGraph
{
private:
	vector<Node*> nodes;

public:
	DirectedGraph();
	~DirectedGraph();

	void addNode(string);
	void addDirectedEdge(Node*, Node*);
	void removeDirectedEdge(Node*, Node*);
	set<Node> getAllNodes();
	vector<Node*> getListNodes();
};