#ifndef DFSTRAVERSAL
#define DFSTRAVERSAL

#include "CreateTree.hpp"

class DFS : virtual public Tree
{
    void dfsPre(node *t);
    void dfsIn(node *t);
    void dfsPost(node *t);
    void dfsLoopPre(node *t);
    void dfsLoopPost(node *t);
    void dfsLoopIn(node *root);

public:
    void dfsPre() { dfsPre(root); }
    void dfsIn() { dfsIn(root); };
    void dfsPost() { dfsPost(root); };
    void dfsLoopPre() { dfsLoopPre(root); };
    void dfsLoopPost() { dfsLoopPost(root); };
    void dfsLoopIn() { dfsLoopIn(root); };
};

void DFS::dfsPre(node *t)
{
    if (!t)
        return;
    cout << t->data << " ";
    dfsPre(t->l);
    dfsPre(t->r);
}

void DFS::dfsIn(node *t)
{
    if (!t)
        return;
    dfsIn(t->l);
    cout << t->data << " ";
    dfsIn(t->r);
}

void DFS::dfsPost(node *t)
{
    if (!t)
        return;
    dfsPost(t->l);
    dfsPost(t->r);
    cout << t->data << " ";
}

void DFS::dfsLoopPre(node *t)
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
        if (t1->r)
            st.push(t1->r);
        if (t1->l)
            st.push(t1->l);
    }
}

void DFS::dfsLoopPost(node *t)
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
        if (t1->l)
            st.push(t1->l);
        if (t1->r)
            st.push(t1->r);
    }
    for (auto i = v.end() - 1; i >= v.begin(); i--)
    {
        cout << *i << " ";
    }
}

void DFS::dfsLoopIn(node *root)
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
            st.push(t->r);
        }
        else
            st.push(t->l);
    }
}

#endif