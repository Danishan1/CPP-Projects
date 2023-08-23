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
    cout << t->data <<" "; 
    printPre(t->l);
    printPre(t->r);
}

int height(node *t)
{
    if (!t)
        return 0;
    return max(height(t->l), height(t->r)) + 1;
}
pair<int, int> daiHeight(node *t)
{
    if (!t)
        return {0, 0};
    auto a = daiHeight(t->l);
    auto b = daiHeight(t->r);
    int hei = max(a.first, b.first) + 1;
    int dia = a.first + b.first + 1;
    return {hei, dia};
}

int main()
{
    vector<int> t = {1, 2, 3, 4, -1, -1, 5, -1, -1, 6, -1, -1, 7, -1, 8, 9, -1, -1, 10, -1, -1};
    int i = 0;
    node *root = createTree(t, i);

    printPre(root);
    cout << " \n";
    cout << height(root);
    cout << " \n";
    auto a = daiHeight(root);
    cout << a.first << " " << a.second;
}