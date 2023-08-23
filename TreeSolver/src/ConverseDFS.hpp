#ifndef CONDFS
#define CONDFS

#include "CreateTree.hpp"


class conDFS : virtual public Tree
{
    void conDFSPre(node *t);
    void conDFSIn(node *t);
    void conDFSPost(node *t);
    void conDFSLoopPre(node *t);
    void conDFStLoopPost(node *t);
    void conDFSLoopIn(node *root);

public:
    void conDFSPre() { conDFSPre(root); };
    void conDFSIn() { conDFSIn(root); };
    void conDFSPost() { conDFSPost(root); };
    void conDFSLoopPre() { conDFSLoopPre(root); };
    void conDFStLoopPost() { conDFStLoopPost(root); };
    void conDFSLoopIn() { conDFSLoopIn(root); };
};

void conDFS::conDFSPre(node *t)
{
    if (!t)
        return;
    cout << t->data << " ";
    conDFSPre(t->r);
    conDFSPre(t->l);
}

void conDFS::conDFSIn(node *t)
{
    if (!t)
        return;
    conDFSIn(t->r);
    cout << t->data << " ";
    conDFSIn(t->l);
}

void conDFS::conDFSPost(node *t)
{
    if (!t)
        return;
    conDFSPost(t->r);
    conDFSPost(t->l);
    cout << t->data << " ";
}

void conDFS::conDFSLoopPre(node *t)
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

void conDFS::conDFStLoopPost(node *t)
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

void conDFS::conDFSLoopIn(node *root)
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

#endif