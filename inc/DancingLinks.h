#ifndef DANCING_LINKS_H
#define DANCING_LINKS_H

#include <vector>

class Node
{
public:
    Node *left, *right, *up, *down, *column;
    int rowID, colID, nodeCount;

    Node(int row = 0, int col = 0);
};

class DancingLinks
{
public:
    DancingLinks(int rows, int cols);
    void solve();
    void addNode(int row, int col);
    void search(int k);
    void printSolutions();

private:
    Node *header;
    std::vector<Node *> solutions;
    std::vector<std::vector<Node *>> rowNodes;
    int nRow, nCol;

    void cover(Node *targetNode);
    void uncover(Node *targetNode);
    Node *getMinColumn();
};

#endif /* DANCING_LINKS_H */
