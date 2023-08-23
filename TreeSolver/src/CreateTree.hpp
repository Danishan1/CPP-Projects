#ifndef CREATETREE
#define CREATETREE

#include <bits/stdc++.h>
using namespace std;

class Tree
{

    bool checkValidStr(string str);
    vector<int> strToInt(string str);

public:
    struct node;
    node *root;
    Tree();
    node *createTree(vector<int> &v, int &i);
    void print();

protected:
};

struct Tree::node
{
    int data;
    node *l, *r;
    node() : l(NULL), r(NULL) {}
    node(int a) : l(NULL), r(NULL), data(a) {}
};

Tree::Tree()
{
    bool flag = true;
    string str;
    do
    {
        cout << "Enter valid sequence(values of nodes) of binary tree saparated by space and '-1' for NULL\nEnter : ";
        getline(cin, str);

        flag = checkValidStr(str);
        if (!flag)
        {
            cout << "\nEnter a valid Sequence.  \n";
        }

    } while (!flag);

    auto v = strToInt(str);
    int i = 0;
    root = createTree(v, i);
}

bool Tree::checkValidStr(string str)
{
    for (auto i : str)
    {
        if (isdigit(i) || i == ' ' || i == '+' || i == '-')
        {
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

vector<int> Tree::strToInt(string str)
{
    vector<int> v;
    int a = 0, b = 0;
    bool flag = 0, neg = 0;
    for (auto i : str)
    {
        if (isdigit(i))
        {
            b = i - '0';
            a = a * 10 + b;
            flag = true;
        }
        else if (i == ' ' && flag)
        {
            if (neg)
            {
                neg = 0;
                v.push_back(-a);
            }
            else
                v.push_back(a);
            a = 0;
            flag = 0;
        }
        if (i == '-')
        {
            if (flag)
            {
                if (neg)
                {
                    neg = 0;
                    v.push_back(-a);
                }
                else
                    v.push_back(a);
                a = 0;
                flag = 0;
            }
            neg = 1;
        }
    }
    if (flag)
    {
        if (neg)
        {
            neg = 0;
            v.push_back(-a);
        }
        else
            v.push_back(a);
        a = 0;
        flag = 0;
    }
    return v;
}

Tree::node *Tree::createTree(vector<int> &v, int &i)
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


#endif