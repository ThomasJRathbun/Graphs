#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <queue>
#include <vector>
#include <math.h>

//Graphs
#include "Graph.h"
#include "DirectedGraph.h"
#include "WeightedGraph.h"
#include "GridGraph.h"

//Graph Algorithms
#include "GraphSearch.h"
#include "TopSort.h"

using namespace std;

//Unweighted Graph
Graph createRandomUnweightedGraphIter(int n) {
	Graph g;

	for (int i = 0; i < n; i++) {
		g.addNode(to_string(i));
	}

	int max_edges = (n * (n - 1)) / 2;
	int edges = rand() % max_edges + 1;
	vector<tuple<int, int>> pairs;
	for (int i = 0; i < edges; i++) {
		int f;
		int s;
		do {
			f = rand() % g.getListNodes().size();
			s = rand() % g.getListNodes().size();
			
		} while (f == s);
		if (find(pairs.begin(), pairs.end(), tuple<int, int>(f, s)) == pairs.end()) {
			pairs.push_back(tuple<int, int>(f, s));
			g.addUndirectedEdge(g.getListNodes()[f], g.getListNodes()[s]);
		}
		else
			i--;
	}

	return g;
}

Graph createUnweightedLinkedList(int n) {
	Graph g;
	for (int i = 0; i < n; i++) {
		g.addNode(to_string(i));
	}

	for (int i = 0; i < g.getListNodes().size() - 1; i++) {
		cout << "i: " << i << endl;
		g.addUndirectedEdge(g.getListNodes()[i], g.getListNodes()[i + 1]);
	}

	return g;
}


//Directed Graph Algorithms
DirectedGraph createRandomDAGIter(int n) {
	DirectedGraph g;

	for (int i = 0; i < n; i++) {
		g.addNode(to_string(i));
	}

	int count = 0;
	for (auto e : g.getListNodes()) {
		int edges = rand() % (n - count) + 1;

		for (int i = count+1; i < n; i++) {
			if (rand() % 2)
				g.addDirectedEdge(e, g.getListNodes()[i]);
		}
		count++;
	}
	return g;
}

//Weighted Graph Algorithms
WeightedGraph createRandomCompleteWeightedGraph(int n) {
	WeightedGraph g;
	for (int i = 0; i < n; i++) {
		g.addNode(to_string(i));
	}

	int count = 1;
	for (auto v : g.getListNodes()) {

		
		for (int i = count; i < n; i++) {
			int d = rand() % 10 + 1;
			g.addWeightedEdge(v, g.getListNodes()[i], d);
			d = rand() % 10 + 1;
			g.addWeightedEdge(g.getListNodes()[i], v, d);
		}
		count++;
	}

	return g;
}

WeightedGraph createLinkedList(int n) {
	WeightedGraph g;
	for (int i = 0; i < n; i++) {
		g.addNode(to_string(i));
	}
	vector<Node*>::iterator it = g.getListNodes().begin();
	for (auto v : g.getListNodes()) {
		it++;
		if(it != g.getListNodes().end())
			g.addWeightedEdge(v, *it, 1);
	}
	return g;
}

auto cmp = [](tuple<Node*, int> left, tuple<Node*, int>  right) {return (get<1>(left)) > (get<1>(right)); };

map<Node*, int> dijkstras(Node start) {
	map<Node*, int> result;
	map<Node*, Node*> prev;
	priority_queue<tuple<Node*, int>, vector<tuple<Node*, int>>, decltype(cmp)> q(cmp);

	result.insert(make_pair(&start, 0));
	q.push(make_tuple(&start, 0));
	for (auto v : start.getEdgeList()) {
		result.insert(make_pair(get<0>(v), get<1>(v)));
		prev.insert(make_pair(get<0>(v), &start));
	}
	
	for (auto v : start.getEdgeList()) {
		if (*get<0>(v) != start) {
			q.push(v);
		}
		while (!q.empty()) {
			tuple<Node*, int> t = q.top();
			q.pop();

			for (auto n : get<0>(t)->getEdgeList()) {
				int temp_dist = result[get<0>(t)] + get<1>(n);
				if (temp_dist < result[get<0>(n)]) {
					result[get<0>(n)] = temp_dist;
					prev[get<0>(n)] = get<0>(t);
				}
			}
		}
	}

	return result;
}

//GridGraph Algorithms
GridGraph createRandomGridGraph(int n) {
	GridGraph g;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			g.addGridNode(j, i, to_string(j) + "," + to_string(i));
	}
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
	int count = 0;
	for (auto e : g.getListNodes()) {
		cout << e->getValue() << endl;
		do {
			up = rand() % 2;
			down = rand() % 2;
			left = rand() % 2;
			right = rand() % 2;
			if (e->getY() == n-1)
				up = false;
			if (e->getY() == 0)
				down = false;
			if (e->getX() == 0)
				left = false;
			if (e->getX() == n -1)
				right = false;
		} while (!up && !down && !left && !right);
		
		if (up && e->getY() < n) {
			cout << "up\n";
			g.addUndirectedEdge(e, g.getListNodes()[count+n]);
		}
		if (down && e->getY() > 0) {
			cout << "down\n";
			g.addUndirectedEdge(e, g.getListNodes()[count - n]);
		}
		if (left && e->getX() > 0) {
			cout << "left\n";
			g.addUndirectedEdge(e, g.getListNodes()[count - 1]);
		}
		if (right && e->getX() < n) {
			cout << "right\n";
			g.addUndirectedEdge(e, g.getListNodes()[count + 1]);
		}
		

		for (auto f : e->getEdgeList()) {
			cout << "\t" << get<0>(f)->getValue() << endl;
		}
		count++;
	}
	return g;
}

double euclideanDistance(Node* source, Node* destination) {
	return sqrt( pow(destination->getX() - source->getX(),2) + pow(destination->getY() - source->getY(),2));
}
auto cmpD = [](tuple<Node*, int, double> left, tuple<Node*, int, double>  right) {return (get<1>(left)+get<2>(left)) > (get<1>(right) + get<2>(right)); };

vector<Node> astar(Node* source, Node* destination) {
	map<Node*, tuple<int, double>> h;
	vector<Node> result;
	priority_queue<tuple<Node*, int, double>, vector<tuple<Node*, int,double>>, decltype(cmpD)> q(cmpD);
	vector<Node*> closed;

	for (auto n : source->getEdgeList()) {
		h.insert(make_pair(get<0>(n), tuple<int, double>(INT_MAX, euclideanDistance(get<0>(n), destination))));
	}
	
	h[source] = make_tuple(0, euclideanDistance(source, destination));
	Node* curr = source;
	q.push(make_tuple(curr, get<0>(h[curr]), get<1>(h[curr])));
	while (!q.empty()) {
		curr = get<0>(q.top());
		closed.push_back(curr);
		q.pop();
		if (curr == destination) {
			break;//backtrack
		}
		for (auto n : curr->getEdgeList()) {
			
			q.push(make_tuple(get<0>(n),get<0>(h[get<0>(n)]), get<1>(h[get<0>(n)])));
		}
		for (auto e : curr->getEdgeList()) {
			int temp_dist = get<0>(h[curr]) + 1;
			if (temp_dist < get<0>(h[get<0>(e)])) {
				get<0>(h[get<0>(e)]) = temp_dist;
			}
		}
		curr = get<0>(q.top());
		q.pop();
	}
	cout << "RES\n";
	return result;

}

int main() {
	srand(time(NULL));

	clock_t start;
	clock_t end;
	double elapsed_secs;

	//Unweighted Graph
	Graph g = createRandomUnweightedGraphIter(10);

	//vector<Node> r = GraphSearch::DFSRec(g.getListNodes()[0], g.getListNodes()[9]);
	vector<Node> r = GraphSearch::BFTIter(g);

	cout << "GRAPH" << endl;
	for (auto j : g.getListNodes()) {
		cout << *j << endl;
	}

	cout << "PATH" << endl;
	for (auto a : r) {
		cout << a.getValue() << endl;
	}


	/*
	start = clock();
	//search.g = createRandomUnweightedGraphIter(10);
	//search.g = createRandomUnweightedGraphIter(100);
	//search.g = createRandomUnweightedGraphIter(500);
	//search.g = createRandomUnweightedGraphIter(1000);
	//search.g = createRandomUnweightedGraphIter(5000);
	//search.g = createRandomUnweightedGraphIter(10000);
	end = clock();
	double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
	cout << "TIME TO BUILD Graph: " << elapsed_secs << endl;
	*/



	//DirectedGraph
	/*
	DirectedGraph kGraph = createRandomDAGIter(1000);
	DirectedGraph mGraph = createRandomDAGIter(1000);

	//set<Node> a = kGraph.getAllNodes();
	set<Node> b = mGraph.getAllNodes();

	cout << "a " << kGraph.getListNodes().size() << endl;
	for (int i = 0; i < kGraph.getListNodes().size(); i++) {
		cout << kGraph.getListNodes()[i]->getValue() << endl;
		cout << "SIZE: " << kGraph.getListNodes()[i]->getEdgeList().size() << endl;
		for (auto a : kGraph.getListNodes()[i]->getEdgeList())
			cout << "\t" << get<0>(a)->getValue() << endl;

	}
	cout << "PATH:\n";
	vector<Node> path = TopSort::Kahns(kGraph);
	for (auto e : path) {
		cout << e.getValue() << endl;

	}

	

	cout << "b " << mGraph.getListNodes().size() << endl;
	for (int i = 0; i < mGraph.getListNodes().size(); i++) {
		cout << mGraph.getListNodes()[i]->getValue() << endl;
		cout << "SIZE: " << mGraph.getListNodes()[i]->getEdgeList().size() << endl;
		for (auto a : mGraph.getListNodes()[i]->getEdgeList())
			cout << "\t" << get<0>(a)->getValue() << endl;

	}


	cout << "PATH:\n";
	vector<Node> path = TopSort::mDFS(mGraph);
	for (auto e : path) {
		cout << e.getValue() << endl;

	}
	*/


	//WeightedGraph
	/*
	WeightedGraph w = createRandomCompleteWeightedGraph(1000);
	
	for (auto n : w.getListNodes()) {
		cout << n->getValue() << endl;
	}

	for (int i = 0; i < w.getListNodes().size(); i++) {
		cout << w.getListNodes()[i]->getValue() << endl;
		cout << "SIZE: " << w.getListNodes()[i]->getEdgeList().size() << endl;
		for (auto a : w.getListNodes()[i]->getEdgeList())
			cout << "\t" << get<0>(a)->getValue() << " :: " << get<1>(a) << endl;
	}

	map<Node*,int> r = dijkstras(*(w.getListNodes()[0]));

	cout << "FROM " << w.getListNodes()[0]->getValue() << endl;
	for (auto k : w.getListNodes()) {
		cout << "\t" << k->getValue() << " :: "<< r[k] << " " << endl;
	}
*/
	/*
	//GridGraph
	GridGraph m = createRandomGridGraph(3);

	for (auto n : m.getListNodes()) {
		cout << *n << endl;
	}


	/*
	vector<Node> r = astar(m.getListNodes()[0], m.getListNodes()[8]);

	cout << "PATH\n";
	for (auto j : r) {
		cout << j.getValue() << endl;
	}
	*/
	return 0;
}