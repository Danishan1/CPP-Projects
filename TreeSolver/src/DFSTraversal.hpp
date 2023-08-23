#ifndef DFSTRAVERSAL
#define DFSTRAVERSAL

#include "CreateTree.hpp"

struct node
{
    int data;
    node *l, *r;
    node() : l(NULL), r(NULL) {}
    node(int a) : l(NULL), r(NULL), data(a) {}
};

class DFSTraversal : public Tree
{
    void printPre1(node *t);
    void printIn1(node *t);
    void printPost1(node *t);
    void printLoopPre1(node *t);
    void printLoopPost1(node *t);
    void printLoopIn1(node *root);

public:
    DFSTraversal()
    {
        
        
    }
    void printPre() { printLoopPre1(root); }
    void printIn() { printIn1(root); };
    void printPost() { printPost1(root); };
    void printLoopPre() { printLoopPre1(root); };
    void printLoopPost() { printLoopPost1(root); };
    void printLoopIn() { printLoopIn1(root); };
};

// node *createTree(vector<int> &v, int &i)
// {
//     if (v[i] == -1)
//     {
//         i++;
//         return NULL;
//     }
//     node *t = new node(v[i++]);
//     t->l = createTree(v, i);
//     t->r = createTree(v, i);
//     return t;
// }

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

// int main()
// {
//     vector<int> t = {1, 2, 3, 4, -1, -1, 5, -1, -1, 6, -1, -1, 7, -1, 8, 9, -1, -1, 10, -1, -1};
//     int i = 0;
//     node *root = createTree(t, i);

//     printPre1(root);
//     cout << "\n";
//     printLoopPre1(root);
//     cout << "\n";

//     printIn1(root);
//     cout << "\n";
//     printLoopIn1(root);
//     cout << "\n";

//     printPost1(root);
//     cout << "\n";
//     printLoopPost1(root);
//     cout << "\n";
// }

#endif