#include "Graph.h"

Graph::Graph()
{
}


Graph::~Graph()
{
}


void Graph::addNode(string value)
{
	nodes.push_back(new Node(value));
}

void Graph::addUndirectedEdge(Node* first, Node* second)
{
	first->insertEdge(second);
	second->insertEdge(first);
}

void Graph::removeUnidrectedEdge(Node* first, Node* second)
{
	first->removeEdge(second);
	second->removeEdge(first);
}

set<Node> Graph::getAllNodes()
{
	set<Node> result;
	for (auto const& n : nodes)
		result.insert(*n);
	return result;
}

vector<Node*>  Graph::getListNodes() {
	return nodes;
}