#ifndef BSFTRAVERSAL
#define BSFTRAVERSAL

#include "CreateTree.hpp"

class BSF : virtual public Tree
{
    void BFSTraversal(node *root);
    void BFSTraversalN(node *root);

public:
    void BFS() { BFSTraversal(root); }
    void BFSn() { BFSTraversalN(root); }
};

void BSF::BFSTraversal(node *root)
{
    queue<node *> q;
    if (!root)
        return;
    q.push(root);
    while (!q.empty())
    {
        auto t = q.front();
        cout << t->data << " ";
        q.pop();
        if (t->l)
            q.push(t->l);
        if (t->r)
            q.push(t->r);
    }
}

void BSF::BFSTraversalN(node *root)
{
    queue<node *> q;
    if (!root)
        return;
    q.push(root);
    q.push(NULL);
    while (1)
    {
        auto t = q.front();
        q.pop();
        if (!t)
        {
            if (q.empty())
                break;
            else
            {
                q.push(NULL);
                cout << "\n";
            }
        }
        else
        {
            cout << t->data << " ";
            if (t->l)
                q.push(t->l);
            if (t->r)
                q.push(t->r);
        }
    }
}

// int main()
// {
//     vector<int> t = {1, 2, 3, 4, -1, -1, 5, -1, -1, 6, -1, -1, 7, -1, 8, 9, -1, -1, 10, -1, -1};
//     int i = 0;
//     node *root = createTree(t, i);
//     BFSTraversal(root);
//     cout << "\n";
//     BFSTraversal2(root);
// }

#endif