#include "node.h"



string node::getKey()
{
	return key;
}

node::node(string in)
{
	key = in;
}


node::~node()
{
}
