#include "graph.h"
#include "node.h"

graph::graph()
{
}


graph::~graph()
{
}


void graph::printNodes()
{
	for (auto const& pair : edgeList) {
		cout << pair.first.key << endl;
	}
}

void graph::addNode(string key)
{
	edgeList.insert(make_pair(node(key), vector<node>()));
}

void graph::addUndirectedEdge(node first, node second)
{
	if (first == second) {
		return;
	}
	bool found = false;
	for (auto const& v : edgeList[first]) {
		if (v == second)
			return;
	}
	edgeList[first].push_back(second);
	edgeList[second].push_back(first);
}

void graph::removeUndirectedEdge(node first, node second)
{
	edgeList[first].erase(remove(edgeList[first].begin(), edgeList[first].end(), second), edgeList[first].end());
	edgeList[second].erase(remove(edgeList[second].begin(), edgeList[second].end(), first), edgeList[second].end());
}

node graph::getNode(string key)
{
	for (auto const& pair : edgeList) {
		if (pair.first.key == key)
			return pair.first;			
	}
	return node("");
}

unordered_map<node,vector<node>> graph::getAllNodes()
{
	return edgeList;
}
