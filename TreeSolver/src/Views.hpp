#ifndef VIEWS
#define VIEWS

#include "CreateTree.hpp"

class Views : virtual public Tree
{
    void leftView(node *root);
    void rightView(node *root);
    void topView(node *root);
    void bottomView(node *root);

public:
    void leftView() { leftView(root); };
    void rightView() { rightView(root); };
    void topView() { topView(root); };
    void bottomView() { bottomView(root); };
};

void Views::leftView(node *root)
{
    if(!root) return;

    auto t = root;
    while (t)
    {
        cout << t->data << " ";
        if (t->l)
            t = t->l;
        else
            t = t->r;
    }
}

void Views::rightView(node *root)
{
    if(!root) return;

    auto t = root;
    while (t)
    {
        cout << t->data << " ";
        if (t->r)
            t = t->r;
        else
            t = t->l;
    }
}

void Views::topView(node *root)
{
    if(!root) return;

    map<int, int> m;
    queue<pair<int, node *>> q;
    q.push({0, root});

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();

        if (m.find(t.first) == m.end())
            m[t.first] = t.second->data;

        if (t.second->l)
            q.push({t.first - 1, t.second->l});
        if (t.second->r)
            q.push({t.first + 1, t.second->r});
    }
    for (auto i : m)
    {
        // cout << i.first << " : " << i.second << "\n";
        cout << i.second << " ";
    }
}

void Views::bottomView(node *root)
{
    if(!root) return;

    map<int, int> m;
    queue<pair<int, node *>> q;
    q.push({0, root});

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();

        m[t.first] = t.second->data;

        if (t.second->l)
            q.push({t.first - 1, t.second->l});
        if (t.second->r)
            q.push({t.first + 1, t.second->r});
    }
    for (auto i : m)
    {
        // cout << i.first << " : " << i.second << "\n";
        cout << i.second << " ";
    }
}

#endif