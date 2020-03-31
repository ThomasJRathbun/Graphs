#include "graph.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GraphSearch.h"
#include <ctime>

using namespace std;

vector<node> BFSLinkedList(graph g) {
	GraphSearch search;
	search.g = g;

	return search.BFSIterative("1676", "9989");
}

graph createRandomUnweightedGraphIter(int n) {
	graph result;

	for (int i = 0; i < n; i++) {
		result.addNode(to_string(i));
	}
	
	vector<node> nodes;
	for (auto const& pair : result.edgeList) {
		nodes.push_back(pair.first);
	}
	
	int max_edges = (n * (n - 1)) / 2;
	int edges = rand() % max_edges + 1;
	//int edges = 5;
	//cout << "edges: " << edges << endl;
	for (int i = 0; i < edges ; i++) {
		int f;
		int s;
		do {
			f = rand() % nodes.size();
			s = rand() % nodes.size();
		} while (f == s);
		//cout << "f: " << nodes[f].key << " s: " << nodes[s].key << endl;
		result.addUndirectedEdge(nodes[f], nodes[s]);

	}

	return result;
}

graph createLinkedList(int n) {
	
	graph result;
	for (int i = 0; i < n; i++) {
		result.addNode(to_string(i));
	}

	vector<node> nodes;
	for (auto const& pair : result.edgeList) {
		nodes.push_back(pair.first);
	}
	for (int i = 0; i < nodes.size() - 1; i++) {
		cout << "i: " << i << endl;
		result.addUndirectedEdge(nodes[i], nodes[i + 1]);
	}

	return result;

}



int main() {
	srand(time(NULL));

	GraphSearch search;
	clock_t start = clock();
	search.g = createRandomUnweightedGraphIter(10);
	//search.g = createRandomUnweightedGraphIter(100);
	//search.g = createRandomUnweightedGraphIter(500);
	//search.g = createRandomUnweightedGraphIter(1000);
	//search.g = createRandomUnweightedGraphIter(5000);
	//search.g = createRandomUnweightedGraphIter(10000);
	clock_t end = clock();
	double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
	cout << "TIME TO BUILD Graph: " << elapsed_secs << endl;

	cout << "***********\n";
	for (auto const& pair : search.g.edgeList) {
		cout << "[" << pair.first.key << ": ";
		for (auto const& a : pair.second) {
			cout << a.key << ",";
		}
		cout << "]" << endl;
	}




	start = clock();
	vector<node> res = search.BFS("1", "9");
	end = clock();

	elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
	/*
	for (auto const& pair : search.g.edgeList) {
		cout << "[" << pair.first.key << ": ";
		for (auto const& a : pair.second) {
			cout << a.key << ",";
		}
		cout << "]" << endl;
	}
	*/



	cout << "TIME TO COMPUTE PATH: " << elapsed_secs << endl;
	cout << "Nodes in Solution: " << res.size() << endl;
	cout << "DFS" << endl;
	if (res.empty()) {
		cout << "No Valid Path Exists\n";
	}
	else {
		for (auto const& n : res) {
			cout << n.key << endl;
		}
		cout << "DFS -- END\n";

	}/*
	g.addNode("tom");
	g.addNode("eric");
	g.addNode("scott");
	g.addNode("pirate");
	g.addNode("jake");
	g.addNode("steph");
	g.addNode("fahb");
	g.addNode("riya");
	
	vector<node> nodes;
	for (auto const& pair : g.edgeList) {
		nodes.push_back(pair.first);
	}

	for (int i = 0; i < nodes.size()-1; i++) {
		g.addUndirectedEdge(nodes[i], nodes[i + 1]);
	}

	*/


	/*
	for (int i = 0; i < nodes.size() - 1; i++) {
		g.removeUndirectedEdge(nodes[i], nodes[i + 1]);
	}

	*/


	
	return 0;
}