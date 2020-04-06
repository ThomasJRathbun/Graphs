#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>

using namespace std;

class GridGraph
{
private:
	vector<Node*> nodes;

public:
	GridGraph();
	~GridGraph();

	void addGridNode(int, int, string);
	void addUndirectedEdge(Node*, Node*);
	void removeUnidrectedEdge(Node*, Node*);
	set<Node> getAllNodes();
	vector<Node*> getListNodes();
};

