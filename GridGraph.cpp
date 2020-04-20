#include "GridGraph.h"

GridGraph::GridGraph()
{
}


GridGraph::~GridGraph()
{
}

void GridGraph::addGridNode(int x, int y, string value)
{
	nodes.push_back(new Node(value, x, y));
}

void GridGraph::addUndirectedEdge(Node* first, Node* second)
{
	if ((first->getX() == second->getX() && (first->getY() == second->getY() + 1 || first->getY() == second->getY() - 1)) ||
		(first->getY() == second->getY() && (first->getX() == second->getX() + 1 || first->getX() == second->getX() - 1))) {
		first->insertEdge(second);
		second->insertEdge(first);
	}
}

void GridGraph::removeUnidrectedEdge(Node* first, Node* second)
{
	first->removeEdge(second);
	second->removeEdge(first);
}

vector<Node*> GridGraph::getListNodes() {
	return nodes;
}
