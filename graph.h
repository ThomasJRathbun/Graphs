#pragma once
#include "node.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map> 

using namespace std;

class graph
{
private:
	

public:
	unordered_map<node, vector<node>> edgeList;

	graph();
	~graph();

	void printNodes();
	void addNode(string key);
	void addUndirectedEdge(node first, node second);
	void removeUndirectedEdge(node first, node second);
	node getNode(string);
	unordered_map<node, vector<node>> getAllNodes();
	
};

