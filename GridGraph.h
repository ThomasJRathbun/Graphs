#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>
#include "Graph.h"

using namespace std;

class GridGraph : public Graph
{
private:
	vector<Node*> nodes;

public:
	GridGraph();
	~GridGraph();

	void addGridNode(int, int, string);
	void addUndirectedEdge(Node*, Node*);
	void removeUnidrectedEdge(Node*, Node*);
	vector<Node*> getListNodes();
};

