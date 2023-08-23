#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *l, *r;
    node() : l(NULL), r(NULL) {}
    node(int a) : l(NULL), r(NULL), data(a) {}
};

node *createTree(vector<int> &v, int &i)
{
    if (v[i] == -1)
    {
        i++;
        return NULL;
    }
    node *t = new node(v[i++]);
    t->l = createTree(v, i);
    t->r = createTree(v, i);
    return t;
}

void VirticalTraversal(node *root)
{
    map<int, map<int, multiset<int>>> m; // (x, y, value)
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
                cout <<"("<<i.first <<", "<<j.first<<") :  " << k << " \n";
            }
        }
        // ans.push_back(v);
        cout << "\n";
    }
}

int main()
{
    vector<int> t = {1, 2, 3, 4, -1, -1, 5, -1, -1, 6, -1, -1, 7, -1, 8, 9, -1, -1, 10, -1, -1};
    int i = 0;
    node *root = createTree(t, i);
    VirticalTraversal(root);
}