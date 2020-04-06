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

vector<Node> BFTRecLinkedList(Graph g) {
	vector<Node> r = GraphSearch::BFTRec(g);
	return r;
}

vector<Node> BFTIterLinkedList(Graph g) {
	vector<Node> r = GraphSearch::BFTIter(g);
	return r;
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
			g.addUndirectedEdge(e, g.getListNodes()[count+n]);
		}
		if (down && e->getY() > 0) {
			g.addUndirectedEdge(e, g.getListNodes()[count - n]);
		}
		if (left && e->getX() > 0) {
			g.addUndirectedEdge(e, g.getListNodes()[count - 1]);
		}
		if (right && e->getX() < n) {
			g.addUndirectedEdge(e, g.getListNodes()[count + 1]);
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

void printResult(vector<Node> r) {
	for (auto a : r) {
		cout << a.getValue() << endl;
	}
}

int main() {
	srand(time(NULL));

	//clock_t start;
	//clock_t end;
	//double elapsed_secs;
	//start = clock();
	//Code
	//end = clock();
	//double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;

	//Unweighted Graph
	Graph g = createUnweightedLinkedList(10000);
	//printResult(BFTIterLinkedList(g));
	//printResult(BFTRecLinkedList(g));

	//DAG
	DirectedGraph dg = createRandomDAGIter(1000);
	//printResult(TopSort::Kahns(dg));
	cout << "mDFS\n";
	printResult(TopSort::mDFS(dg)); // I think this will always give a list in chronological order because of how I made my DAG. I will be rewriting my DAG generation code. 


	return 0;
}