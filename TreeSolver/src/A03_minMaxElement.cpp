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

void printPre(node *t)
{
    if (!t)
        return;
    cout << t->data;
    printPre(t->l);
    printPre(t->r);
}

pair<int, int> minMaxEle(node *t)
{
    if (!t)
    {
        return {INT_MAX, INT_MIN};
    }
    auto a = minMaxEle(t->l);
    auto b = minMaxEle(t->r);
    int mini = min(min(a.first, b.first), t->data);
    int maxi = max(max(a.second, b.second), t->data);

    return {mini, maxi};
}

int miniEle(node *t)
{
    if (!t)
        return INT_MAX;
    return min(min(miniEle(t->l), miniEle(t->r)), t->data);
}
int maxEle(node *t)
{
    if (!t)
        return INT_MIN;
    return max(max(maxEle(t->l), maxEle(t->r)), t->data);
}

int main()
{
    vector<int> t = {1, 2, 3, 4, -1, -1, 5, -1, -1, 6, -1, -1, 7, -1, 8, 9, -1, -1, 10, -1, -1};
    int i = 0;
    node *root = createTree(t, i);

    printPre(root);
    cout << " \n";

    auto a = minMaxEle(root);
    cout << a.first << " " << a.second << "\n";
    cout << miniEle(root) << "\n";
    cout << maxEle(root) << "\n";
}