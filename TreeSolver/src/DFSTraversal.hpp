#ifndef DFSTRAVERSAL
#define DFSTRAVERSAL

#include "CreateTree.hpp"


class DFSTraversal : virtual public Tree
{
    void printPre1(node *t);
    void printIn1(node *t);
    void printPost1(node *t);
    void printLoopPre1(node *t);
    void printLoopPost1(node *t);
    void printLoopIn1(node *root);

public:
    
    void printPre() { printLoopPre1(root); }
    void printIn() { printIn1(root); };
    void printPost() { printPost1(root); };
    void printLoopPre() { printLoopPre1(root); };
    void printLoopPost() { printLoopPost1(root); };
    void printLoopIn() { printLoopIn1(root); };
};


void DFSTraversal::printPre1(node *t)
{
    if (!t)
        return;
    cout << t->data << " ";
    printPre1(t->l);
    printPre1(t->r);
}

void DFSTraversal::printIn1(node *t)
{
    if (!t)
        return;
    printIn1(t->l);
    cout << t->data << " ";
    printIn1(t->r);
}

void DFSTraversal::printPost1(node *t)
{
    if (!t)
        return;
    printPost1(t->l);
    printPost1(t->r);
    cout << t->data << " ";
}

void DFSTraversal::printLoopPre1(node *t)
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

void DFSTraversal::printLoopPost1(node *t)
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

void DFSTraversal::printLoopIn1(node *root)
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