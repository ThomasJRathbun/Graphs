#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>
#include "Graph.h"

using namespace std;

class DirectedGraph : public Graph
{
private:
	vector<Node*> nodes;

public:
	DirectedGraph();
	~DirectedGraph();

	void addNode(string);
	void addDirectedEdge(Node*, Node*);
	void removeDirectedEdge(Node*, Node*);
	vector<Node*> getListNodes();
};