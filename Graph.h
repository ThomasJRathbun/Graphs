#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>

using namespace std;

class Graph
{
private:
	vector<Node*> nodes;

public:
	Graph();
	~Graph();

	void addNode(string);
	void addUndirectedEdge(Node*, Node*);
	void removeUnidrectedEdge(Node*, Node*);
	vector<Node*> getListNodes();
};

