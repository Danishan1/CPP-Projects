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
    cout << t->data << " ";
    printPre(t->r);
    printPre(t->l);
}
void printIn(node *t)
{
    if (!t)
        return;
    printIn(t->r);
    cout << t->data << " ";
    printIn(t->l);
}
void printPost(node *t)
{
    if (!t)
        return;
    printPost(t->r);
    printPost(t->l);
    cout << t->data << " ";
}

void printLoopPre(node *t)
{
    stack<node *> st;
    if (!t)
        return;
    st.push(t);
    while (!st.empty())
    {
        auto t1 = st.top();
        cout << t1->data << " ";
        st.pop();
        if (t1->l)
            st.push(t1->l);
        if (t1->r)
            st.push(t1->r);
    }
}

void printLoopPost(node *t)
{
    stack<node *> st;
    vector<int> v;
    if (!t)
        return;
    st.push(t);
    while (!st.empty())
    {
        auto t1 = st.top();
        v.push_back(t1->data);
        st.pop();
        if (t1->r)
            st.push(t1->r);
        if (t1->l)
            st.push(t1->l);
    }
    for (auto i = v.end() - 1; i >= v.begin(); i--)
    {
        cout << *i << " ";
    }
}
void printLoopIn(node *root)
{
    stack<node *> st;
    if (!root)
        return;
    st.push(root);
    while (1)
    {
        auto t = st.top();

        if (!t)
        {
            st.pop();
            if (st.empty())
                break;
            t = st.top();
            st.pop();
            cout << t->data << " ";
            st.push(t->l);
        }
        else
            st.push(t->r);
    }
}

int main()
{
    vector<int> t = {1, 2, 3, 4, -1, -1, 5, -1, -1, 6, -1, -1, 7, -1, 8, 9, -1, -1, 10, -1, -1};
    int i = 0;
    node *root = createTree(t, i);

    printPre(root);
    cout << "\n";
    printLoopPre(root);
    cout << "\n";

    printIn(root);
    cout << "\n";
    printLoopIn(root);
    cout << "\n";

    printPost(root);
    cout << "\n";
    printLoopPost(root);
    cout << "\n";
}