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

void BFSTraversal(node *root)
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
void BFSTraversal2(node *root)
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

int main()
{
    vector<int> t = {1, 2, 3, 4, -1, -1, 5, -1, -1, 6, -1, -1, 7, -1, 8, 9, -1, -1, 10, -1, -1};
    int i = 0;
    node *root = createTree(t, i);
    BFSTraversal(root);
    cout << "\n";
    BFSTraversal2(root);
}