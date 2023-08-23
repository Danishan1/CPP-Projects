#ifndef BOUNDRY
#define BOUNDRY

#include "CreateTree.hpp"

class BoundryTra : virtual public Tree
{
    bool isLeaf(node *t);
    deque<int> leafs(node *root);
    deque<int> left(node *root);
    deque<int> right(node *root);
    vector<deque<int>> requiredNodes(node *root);
    void BoundryClock(node *root);
    void BoundryAntiClock(node *root);

public:
    void BoundryClock() { BoundryClock(root); }
    void BoundryAntiClock() { BoundryAntiClock(root); }
};

bool BoundryTra::isLeaf(node *t)
{
    if (!t->l && !t->r)
        return true;
    return false;
}

deque<int> BoundryTra::leafs(node *root)
{
    deque<int> dq;
    stack<node *> s;
    s.push(root);
    while (!s.empty())
    {
        auto t = s.top();
        s.pop();
        if (isLeaf(t))
        {
            dq.push_back(t->data);
        }
        else
        {
            if (t->r)
                s.push(t->r);
            if (t->l)
                s.push(t->l);
        }
    }
    return dq;
}

deque<int> BoundryTra::left(node *root)
{
    deque<int> dq;
    auto t = root;

    while (t)
    {
        if (!isLeaf(t))
            dq.push_back(t->data);

        if (t->l)
            t = t->l;
        else
            t = t->r;
    }
    return dq;
}

deque<int> BoundryTra::right(node *root)
{
    deque<int> dq;
    auto t = root;

    while (t)
    {
        if (!isLeaf(t))
            dq.push_back(t->data);

        if (t->r)
            t = t->r;
        else
            t = t->l;
    }
    return dq;
}

vector<deque<int>> BoundryTra::requiredNodes(node *root)
{
    queue<node *> q;
    vector<deque<int>> v(3);
    int level = 0;

    if (!root)
        return {};
    q.push(root);
    q.push(NULL);
    v[1].push_back(root->data);

    while (1)
    {
        auto t = q.front();
        q.pop();
        if (!t)
        {
            if (q.empty())
                break;
            q.push(NULL);
            t = q.front();
            v[1].push_back(t->data);
        }
        else
        {
            auto t1 = q.front();
            if (!t1)
            {
                v[2].push_back(t->data);
            }
            if (isLeaf(t))
            {
                v[0].push_back(t->data);
            }

            cout << t->data << " ";
            if (t->l)
                q.push(t->l);
            if (t->r)
                q.push(t->r);
        }
    }
    return v;
}

void BoundryTra::BoundryClock(node *root)
{
    auto dq1 = leafs(root);
    auto dq2 = left(root);
    auto dq3 = right(root);

    for (auto i : dq3)
    {
        cout << i << " ";
    }
    for (auto i = dq1.end() - 1; i >= dq1.begin(); i--)
    {
        cout << *i << " ";
    }
    for (auto i = dq2.end() - 1; i > dq2.begin(); i--)
    {
        cout << *i << " ";
    }
}

void BoundryTra::BoundryAntiClock(node *root)
{
    auto dq1 = leafs(root);
    auto dq2 = left(root);
    auto dq3 = right(root);

    for (auto i : dq2)
    {
        cout << i << " ";
    }
    for (auto i : dq1)
    {
        cout << i << " ";
    }

    for (auto i = dq3.end() - 1; i > dq3.begin(); i--)
    {
        cout << *i << " ";
    }
}

#endif