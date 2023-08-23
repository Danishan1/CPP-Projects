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

int count(node *t)
{
    if (t == NULL)
        return 0;
    return count(t->l) + count(t->r) + 1;
}

void printPre(node *t)
{
    if (t == NULL)
        return;
    cout << t->data << " ";
    printPre(t->l);
    printPre(t->r);
}

int main()
{
    vector<int> t = {1, 2, 3, 4, -1, -1, 5, -1, -1, 6, -1, -1, 7, -1, 8, 9, -1, -1, 10, -1, -1};
    node *root = new node();
    int i = 0;
    root = createTree(t, i);
    cout << count(root);
    cout << "\n";
    printPre(root);
}