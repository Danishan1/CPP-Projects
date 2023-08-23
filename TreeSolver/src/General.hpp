#ifndef GENERAL
#define GENERAL

#include "CreateTree.hpp"
#include "Views.hpp"

class General : virtual public Tree, public Views
{
    int height(node *t);
    pair<int, int> daiHeight(node *t);
    int count(node *t);
    int miniEle(node *t);
    int maxEle(node *t);

public:
    int height() { return height(root); };
    pair<int, int> daiHeight() { return daiHeight(root); };
    int count() { return count(root); }
    int miniEle() { return miniEle(root); };
    int maxEle() { return maxEle(root); }
};

int General::height(node *t)
{
    if (!t)
        return 0;
    return max(height(t->l), height(t->r)) + 1;
}
pair<int, int> General::daiHeight(node *t)
{
    if (!t)
        return {0, 0};
    auto a = daiHeight(t->l);
    auto b = daiHeight(t->r);
    int hei = max(a.first, b.first) + 1;
    int dia = a.first + b.first + 1;
    return {hei, dia};
}

int General::count(node *t)
{
    if (t == NULL)
        return 0;
    return count(t->l) + count(t->r) + 1;
}

int General::miniEle(node *t)
{
    if (!t)
        return INT_MAX;
    return min(min(miniEle(t->l), miniEle(t->r)), t->data);
}

int General::maxEle(node *t)
{
    if (!t)
        return INT_MIN;
    return max(max(maxEle(t->l), maxEle(t->r)), t->data);
}

#endif