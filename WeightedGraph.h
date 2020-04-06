#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>
#include<tuple>

using namespace std;
class WeightedGraph
{
private:
	vector<Node*> nodes;

public:
	WeightedGraph();
	~WeightedGraph();

	void addNode(string);
	void addWeightedEdge(Node*, Node*, int);
	void removeWeightedEdge(Node*, Node*);
	set<Node> getAllNodes();
	vector<Node*> getListNodes();
};


