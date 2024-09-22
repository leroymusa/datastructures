#ifndef VEB_TREE_H
#define VEB_TREE_H

class vEBTree
{
public:
    vEBTree(int universeSize);

    void insert(int x);
    void remove(int x);
    bool member(int x);
    int minimum();
    int maximum();
    int successor(int x);
    int predecessor(int x);

private:
    int u;
    int min, max;
    vEBTree *summary;
    vEBTree **clusters;

    int high(int x);
    int low(int x);
    int index(int high, int low);
};

#endif /* VEB_TREE_H */
