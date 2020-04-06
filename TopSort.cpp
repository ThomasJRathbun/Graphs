#include "TopSort.h"

using namespace std;

map<Node,int> TopSort::inDegree(DirectedGraph g)
{
	map<Node,int> in;
	for (auto n : g.getAllNodes()) {
		in.insert(make_pair<Node,int>(Node(n.getValue()), 0));
		//cout << n.getValue() << " :: " << in[n] << endl;
	}

	for (auto n : g.getAllNodes()) {
		//cout << n.getValue() << ": \n";
		for (auto  e : n.getEdgeList()) {
			//cout << "\t" << get<0>(e).getValue() << " :: " << in[get<0>(e)] << endl;
			in[*get<0>(e)]++;
		}
	}
	return in;
}

vector<Node> TopSort::Kahns(DirectedGraph g)
{
	vector<Node> result;
	queue<Node*> q;
	map<Node, int> nDegree = inDegree(g);

	for (auto const& z : g.getListNodes()) {
		//cout << z.getValue() << " :: " << nDegree[z] << endl;
		if (nDegree[*z] == 0)
			q.push(z);
	}
	while (!q.empty()) {
		Node* t = q.front();
		cout << "TOP: " << t->getValue() << endl;
		result.push_back(*t);

		for (auto const& e : (t)->getEdgeList()) {
			nDegree[*get<0>(e)] -= 1;
		}
		nDegree[*t] = -1;

		for (auto const& e : (t)->getEdgeList()) {
			if (nDegree[*get<0>(e)] == 0)
				q.push(get<0>(e));

		}
		cout << "Pop: " << q.front()->getValue() << endl;
		q.pop();
	}

	return result;
}

vector<Node> TopSort::mDFS(DirectedGraph g)
{
	stack<Node*> s;
	vector<Node> visited;


	for (auto n : g.getListNodes()) {
		s.push(n);
		while (!s.empty()) {
			Node* t = s.top();
			if (s.top()->getEdgeList().empty()) {
				visited.push_back(*s.top());
				s.pop();
				continue;
			}
			for (auto const& e : s.top()->getEdgeList()) {
				if(find(visited.begin(),visited.end(),e) != visited.end())
					s.push(get<0>(e));
			}
			if (s.top() == t) {
				visited.push_back(*t);
				s.pop();
			}
		}
	}
	return visited;

}