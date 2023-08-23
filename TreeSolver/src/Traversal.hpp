#ifndef TRAVERSAL
#define TRAVERSAL

#include "DFSTraversal.hpp"
#include "ConverseDFS.hpp"
#include "BFSTraversal.hpp"
#include "BoundryTraversal.hpp"
#include "VirticalTraversal.hpp"

class Traversal : public DFS, public conDFS, public BSF, public BoundryTra, public virtical
{
};

#endif