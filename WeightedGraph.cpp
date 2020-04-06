#include "WeightedGraph.h"



WeightedGraph::WeightedGraph()
{
}


WeightedGraph::~WeightedGraph()
{
}

void WeightedGraph::addNode(string value)
{
	nodes.push_back(new Node(value));
}

void WeightedGraph::addWeightedEdge(Node* first, Node* second, int weight)
{
	first->insertEdge(second,weight);
}

void WeightedGraph::removeWeightedEdge(Node* first, Node* second)
{
	first->removeEdge(second);
}

set<Node> WeightedGraph::getAllNodes()
{
	set<Node> result;
	for (auto const& n : nodes)
		result.insert(*n);
	return result;
}

vector<Node*> WeightedGraph::getListNodes()
{
	return nodes;
}