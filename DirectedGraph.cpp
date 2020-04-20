#include "DirectedGraph.h"

DirectedGraph::DirectedGraph()
{
}


DirectedGraph::~DirectedGraph()
{
}


void DirectedGraph::addNode(string value)
{	
	//Node temp = Node(value);
	nodes.push_back(new Node(value));
}

void DirectedGraph::addDirectedEdge(Node* first, Node* second)
{
	first->insertEdge(second);
}

void DirectedGraph::removeDirectedEdge(Node* first, Node* second)
{
	first->removeEdge(second);

}


vector<Node*> DirectedGraph::getListNodes()
{
	return nodes;
}
