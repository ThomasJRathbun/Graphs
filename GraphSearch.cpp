#include "GraphSearch.h"

//DFS
vector<Node> GraphSearch::DFSRec(Node* source, Node* destination)
{
	vector<Node> visited;
	vector<Node> path;
	visited = DFSRecUtil(source, destination, visited, path);
	reverse(visited.begin(), visited.end());
	return visited;
}

vector<Node> GraphSearch::DFSRecUtil(Node* source, Node* destination, vector<Node>& visited, vector<Node> path)
{
	vector<Node> newPath;
	vector<Node> empty;
	visited.push_back(*source);
	if (source == destination) {
		path.push_back(*source);
		path.push_back(visited[0]);
		return path;
	}

	for (auto const& n : source->getEdgeList()) {
		//Check if n is in visited
		if (find(visited.begin(), visited.end(), *get<0>(n)) == visited.end()) {
			//if n is not in visited 
			newPath = DFSRecUtil(get<0>(n), destination, visited, path);
			if (!newPath.empty()) {
				if (newPath[0] == *destination) {
					if (get<0>(n) != destination) {
						Node f = newPath.back();
						newPath.pop_back();
						newPath.push_back(*get<0>(n));
						newPath.push_back(f);
					}
					return newPath;
				}
			}
		}
		else {
			continue;
		}
	}
	return newPath;
}

vector<Node> GraphSearch::DFSIter(Node* source, Node* destination)
{
	stack<Node*> s;
	vector<Node> visited;

	s.push(source);
	while (!s.empty()) {
		Node* t = s.top();
		s.pop();

		if (t == destination) {
			visited.push_back(*destination);
			return visited;
		}

		if (find(visited.begin(), visited.end(), *t) == visited.end()) {
			visited.push_back(*t);
			for (auto e : t->getEdgeList()) {
				s.push(get<0>(e));
			}
		}
	}

	return vector<Node>();
}


//BFS
vector<Node> GraphSearch::BFTIter(Graph g)
{
	map<Node,bool> visited;
	queue<Node*> q;
	vector<Node> r;
	
	for (auto a : g.getListNodes()) {
		visited.insert(make_pair(*a, false));
	}


	for (auto j : g.getListNodes()) {
		if (visited[*j] == false) {
			q.push(j);
			visited[*j] = true;
		}
		while (!q.empty()) {
			Node* t = q.front();
			r.push_back(*t);
			q.pop();
			for (auto e : t->getEdgeList()) {
				if (visited[*get<0>(e)] == false) {
					visited[*get<0>(e)] = true;
					q.push(get<0>(e));
				}
			}
		}
	}
	return r;
}





//Not Working
vector<Node> GraphSearch::BFTRec(Graph g)
{

	return vector<Node>();
} 

vector<Node> GraphSearch::BFTRecUtil(Graph g, vector<Node> visited)
{



	return vector<Node>();
}
