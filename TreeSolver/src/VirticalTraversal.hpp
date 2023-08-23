#ifndef VIRTICAL
#define VIRTICAL

#include "CreateTree.hpp"


class virtical : virtual public Tree
{
    void VirticalTraversal(node *root);

public:
    void VirticalTraversal() { VirticalTraversal(root); }
};

void virtical::VirticalTraversal(node *root)
{
    map<int, map<int, multiset<int>>> m;   // (x, y, value)
    queue<pair<node *, pair<int, int>>> q; // (value, x, y)
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        m[t.second.first][t.second.second].insert(t.first->data);

        if (t.first->l)
            q.push({t.first->l, {t.second.first - 1, t.second.second + 1}});
        if (t.first->r)
            q.push({t.first->r, {t.second.first + 1, t.second.second + 1}});
    }

    // vector<vector<int>> ans;
    for (auto i : m)
    {
        // vector<int> v;
        for (auto j : i.second)
        {
            // v.insert(v.end(), j.second.begin(), j.second.end());
            for (auto k : j.second)
            {
                cout << "(" << i.first << ", " << j.first << ") :  " << k << " \n";
            }
        }
        // ans.push_back(v);
        cout << "\n";
    }
}

#endif