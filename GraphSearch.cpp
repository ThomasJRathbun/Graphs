#include "GraphSearch.h"

vector<node> GraphSearch::DFSIterative(string source, string destination) {
	node s = g.getNode(source);
	node d = g.getNode(destination);

	return DFSIter(s, d);
}

vector<node> GraphSearch::BFSIterative(string source, string destination) {
	node s = g.getNode(source);
	node d = g.getNode(destination);

	return BFSIter(s, d);
}

vector<node> GraphSearch::DFSRec(node source, node destination, vector<node>& visited, vector<node> path)
{
	vector<node> newPath;
	cout << "TOP OF FUNCTION CALL\n";
	for (auto const& el : visited) {
		cout << "element: " << el.key << "\n";
	}
	cout << "************************\n";
	
	
	vector<node> empty;
	visited.push_back(source);
	if (source == destination ) {
		path.push_back(source);
		path.push_back(visited[0]);
		return path;
	}

	for (auto const& n : g.edgeList[source]) {
		bool seen = false;

		//Check if n is in visited
		cout << "VISITED:\n";
		for (auto const& j : visited) {
			cout << j.key << endl;
			if (n == j) {
				cout << n.key << " has been Visited\n";
				seen = true;
				break;
			}
		}
		cout << "seen: " << seen << endl;
		//if n is not in visited 
		//Recur on n
		if (!seen) {
			//visited.push_back(n);
			cout << "NODE: " << n.key << " not SEEN\n";
			newPath = DFSRec(n, destination, visited, path);
			if (!newPath.empty()) {
				cout << "FRONT OF NEW PATH: " << newPath[0].key << endl;
				if (newPath[0] == destination) {
					if (n != destination) {
						node f = newPath.back();
						newPath.pop_back();
						newPath.push_back(n);
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
	if (!newPath.empty())
	{
		cout << "LAST CHECK\n";
		return newPath;
	}

	else
		return empty;
}

vector<node> GraphSearch::BFS(string source, string destination)
{
	node s = g.getNode(source);
	node d = g.getNode(destination);

	queue<node> q;
	q.push(s);
	vector<node> visited;
	vector<node> path;
	path = BFSRec(d, q, visited);
	if (!path.empty()) {
		path.push_back(s);
		reverse(path.begin(), path.end());
	}
	return path;
}

vector<node> GraphSearch::BFSRec(node destination, queue<node>& q, vector<node>& visited)
{
	vector<node> empty;
	vector<node> path;
	if (q.empty())
	{
		return empty;
	}

	node v = q.front();
	q.pop();
	cout << v.key << " ";

	for (auto const& u : g.edgeList[v]) {
		if (u == destination) {
			path.push_back(u);
			return path;
		}
		if (!path.empty()) {
			path.push_back(u);
			return path;
		}
		bool seen = false;
		for (auto const& a : visited) {
			if (a == u) {
				seen = true;
				break;
			}
		}
		if (!seen) {
			visited.push_back(u);
			q.push(u);
		}
	}
	BFSRec(destination, q, visited);
}




//for each node in adjacent
//path = dfs (node destination)
//if goal in path add node and return

vector<node> GraphSearch::DFS(string source, string destination)
{
	node s = g.getNode(source);
	node d = g.getNode(destination);

	vector<node> visited;
	vector<node> path;
	path = DFSRec(source, destination, visited, path);
	reverse(path.begin(), path.end());
	return path;
}

vector<node> GraphSearch::DFSIter(node source, node destination)
{
	stack<node> s;
	vector<node> visited;
	bool found = false;
	bool seen = false;
	vector<node> empty;
	s.push(source);
	if (g.edgeList[source].empty() && source != destination)
		return empty;
	if (source == destination) {
		visited.push_back(source);
		return visited;
	}

	while (!s.empty()) {
	
		node v = s.top();						//set v to top of stack
		visited.push_back(v);					//set v as visited

		if (v == destination) {				//if v is the destination push it and return stack
			found = true;
			break;
		}
		for (auto const& n : g.edgeList[v]) {	//check for next unseen node
			seen = false;
			for (auto const& a : visited) {		//if node has been seen check next node
				if (n == a) {
					seen = true;
					break;
				}
			}//end for

			if (!seen) {						//if node hasn't been seen add it to stack
				s.push(n);
				break;
			}
		}//end for

		if (seen) {
			s.pop();
		}
	}


	if (!found)
		return empty;
	else {
		//Return Result
		vector<node> result;
		int size = s.size();
		for (int i = 0; i < size; i++) {
			result.push_back(s.top());
			s.pop();
		}
		reverse(result.begin(), result.end());
		return result;
	}
}

vector<node> GraphSearch::BFSIter(node source, node destination)
{
	vector<node> empty;
	queue<vector<node>> q;
	vector<node> start;
	start.push_back(source);
	q.push(start);
	if (g.edgeList[source].empty()) {
		return empty;
	}
	if (source == destination)
	{
		empty.push_back(source);
		return empty;
	}
	while (!q.empty()) {
		vector<node> path;
		
		for (auto const& n : q.front()) {
			path.push_back(n);
		}
		q.pop();
		node n = path.back();
		for (auto const& k : path) {
			cout << k.key << ", ";
		}
		cout << endl;
		if (n == destination)
			return path;

		for (auto const& v : g.edgeList[n]) {
			vector<node> newPath;
			for (auto const& j : path) {
				//cout << j.key << ", ";
				newPath.push_back(j);
			}
			//cout << endl;
			newPath.push_back(v);
			q.push(newPath);
		}
	}
	return empty;
}

GraphSearch::GraphSearch()
{
}


GraphSearch::~GraphSearch()
{
}


