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

void leftView(node *root)
{
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

void rightView(node *root)
{
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

void topView(node *root)
{
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

void bottomView(node *root)
{
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

int main()
{
    vector<int> t = {1, 2, 3, 4, -1, -1, 5, -1, -1, 6, -1, -1, 7, -1, 8, 9, -1, -1, 10, -1, -1};
    int i = 0;
    node *root = createTree(t, i);
    leftView(root);
    cout << "\n";
    rightView(root);
    cout << "\n";
    topView(root);
    cout << "\n";
    bottomView(root);
    cout << "\n";

}