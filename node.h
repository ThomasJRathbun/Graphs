#pragma once
#include <string>

using namespace std;
class node
{

public:
	string key;
	string getKey();
	/*friend bool operator==(const node &rhs, const node &lhs) {
		return (rhs.key == lhs.key);
	}

	*/
	bool operator==(const node &other) const {
		return (key == other.key);
	};
	bool operator!=(const node &other) const {
		return (key != other.key);
	};
	friend bool operator<(const node& rhs, const node& lhs)  {
		return rhs.key < lhs.key;
	}
	node(string key);
	~node();
};

namespace std {

	template <>
	struct hash<node>
	{
		std::size_t operator()(const node& k) const
		{
			using std::size_t;
			using std::hash;
			using std::string;

			// Compute individual hash values for first,
			// second and third and combine them using XOR
			// and bit shifting:

			return (hash<string>()(k.key));
		}
	};

}