#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class Node
{
private:
	string value;
	vector <tuple<Node*, int>> edgeList;
	int x;
	int y;

public:
	Node(string);
	Node(string, int, int);
	Node(const Node& n2) { value = n2.value; x = n2.x; y = n2.y; edgeList = n2.edgeList; }
	~Node();
	static Node makeNode(string, int = 0, int = 0);
	void insertEdge(Node*);
	void insertEdge(Node*, int);
	void removeEdge(Node*);
	vector<tuple<Node*, int>> getEdgeList();
	string getValue();
	int  getX();
	int getY();
	tuple<int, int> getCoord();


	//Overloaded Operators
	Node& operator=(Node other) {
		swap(value, other.value);
		swap(edgeList, other.edgeList);
		swap(x, other.x);
		swap(y, other.y);
		return *this;
	}
	bool operator==(const Node &other) const {
		if (value.compare(other.value) == 0)
			return true;
		else
			return false;
	};
	bool operator==(const tuple<Node*, int> &other) const {
		if ( value.compare(get<0>(other)->value) == 0)
		return true;
		else
			return false;
	};
	bool operator!=(const Node &other) const {
		return (value != other.value);
	};
	friend bool operator<(const Node& rhs, const Node& lhs) {
		return rhs.value < lhs.value;
	}
	friend bool operator==(const tuple<Node*, int>& rhs, const tuple<Node*, int>& lhs) {
		return get<0>(rhs)->value == get<0>(lhs)->value;
	}
	
	friend ostream &operator << (ostream &out, Node& a) {
		out << "Node: " << a.getValue() << endl;
		out << "X:" << a.getX() << "\tY:" << a.getY() << endl;
		out << "Index\tNode\tWeight\n";
		int i = 0;
		for(auto e : a.getEdgeList()){
			out <<"[ "<< i << "\t" << get<0>(e)->getValue() << "\t   " << get<1>(e) << " ]\n";
			i++;
		}
		cout << "----------------------\n";
		return out;
	}
};
