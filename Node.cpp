#include "Node.h"


Node::Node(string value)
{
	this->value = value;
}


Node::Node(string value, int x, int y)
{
	this->value = value;
	this->x = x;
	this->y = y;
	
}


Node::~Node()
{
}

Node Node::makeNode(string value, int x, int y)
{
	Node temp = Node(value,x,y);
	return temp;
}

void Node::insertEdge(Node* in)
{
	if (find(edgeList.begin(), edgeList.end(), tuple<Node*, int>(in, 0)) == edgeList.end()) 
		this->edgeList.push_back(make_tuple(in, 0));
}

void Node::insertEdge(Node* in, int weight)
{
	this->edgeList.push_back(tuple<Node*, int>(in, weight));

}

void Node::removeEdge(Node* out)
{
	edgeList.erase(remove(edgeList.begin(), edgeList.end(), tuple<Node*,int>(out,0)), edgeList.end());
}

vector<tuple<Node*,int>> Node::getEdgeList()
{
	return edgeList;
}

string Node::getValue()
{
	return value;
}

int Node::getX()
{
	return x;
}

int Node::getY()
{
	return y;
}

tuple<int,int> Node::getCoord()
{
	return tuple<int, int>(x, y);
}