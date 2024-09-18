#include "DancingLinks.h"
#include <iostream>

Node::Node(int row, int col) : rowID(row), colID(col), nodeCount(0), left(this), right(this), up(this), down(this), column(nullptr) {}

DancingLinks::DancingLinks(int rows, int cols) : nRow(rows), nCol(cols)
{
    header = new Node();
    rowNodes.resize(rows, std::vector<Node *>(cols, nullptr));

    for (int i = 0; i < cols; ++i)
    {
        Node *colNode = new Node(0, i);
        if (i == 0)
        {
            header->right = colNode;
            colNode->left = header;
        }
        else
        {
            header->left->right = colNode;
            colNode->left = header->left;
        }
        header->left = colNode;
        colNode->right = header;
    }
}

void DancingLinks::addNode(int row, int col)
{
    if (row >= rowNodes.size())
    {
        rowNodes.resize(row + 1);
    }

    Node *newNode = new Node(row, col);
    rowNodes[row].push_back(newNode);

    if (rowNodes[row].size() > 1)
    {
        Node *prev = rowNodes[row][rowNodes[row].size() - 2];
        prev->right = newNode;
        newNode->left = prev;
    }
    else
    {
        newNode->left = newNode;
    }

    if (col >= colNodes.size())
    {
        colNodes.resize(col + 1);
    }

    if (!colNodes[col].empty())
    {
        Node *above = colNodes[col].back();
        above->down = newNode;
        newNode->up = above;
    }
    colNodes[col].push_back(newNode);

    newNode->down = newNode;
    newNode->up = newNode;
}

void DancingLinks::cover(Node *targetNode)
{
    Node *colNode = targetNode->column;
    colNode->right->left = colNode->left;
    colNode->left->right = colNode->right;

    for (Node *row = colNode->down; row != colNode; row = row->down)
    {
        for (Node *rightNode = row->right; rightNode != row; rightNode = rightNode->right)
        {
            rightNode->up->down = rightNode->down;
            rightNode->down->up = rightNode->up;
            rightNode->column->nodeCount--;
        }
    }
}

void DancingLinks::uncover(Node *targetNode)
{
    Node *colNode = targetNode->column;
    for (Node *row = colNode->up; row != colNode; row = row->up)
    {
        for (Node *leftNode = row->left; leftNode != row; leftNode = leftNode->left)
        {
            leftNode->up->down = leftNode;
            leftNode->down->up = leftNode;
            leftNode->column->nodeCount++;
        }
    }
    colNode->right->left = colNode;
    colNode->left->right = colNode;
}

Node *DancingLinks::getMinColumn()
{
    Node *col = header->right;
    Node *minCol = col;
    while (col != header)
    {
        if (col->nodeCount < minCol->nodeCount)
        {
            minCol = col;
        }
        col = col->right;
    }
    return minCol;
}

void DancingLinks::search(int k)
{
    if (header->right == header)
    {
        printSolutions();
        return;
    }
    Node *col = getMinColumn();
    cover(col);

    for (Node *row = col->down; row != col; row = row->down)
    {
        solutions.push_back(row);
        for (Node *rightNode = row->right; rightNode != row; rightNode = rightNode->right)
        {
            cover(rightNode);
        }
        search(k + 1);
        row = solutions.back();
        solutions.pop_back();
        col = row->column;
        for (Node *leftNode = row->left; leftNode != row; leftNode = leftNode->left)
        {
            uncover(leftNode);
        }
    }
    uncover(col);
}

void DancingLinks::printSolutions()
{
    std::cout << "Solutions: ";
    for (auto *node : solutions)
    {
        std::cout << node->rowID << " ";
    }
    std::cout << std::endl;
}

void DancingLinks::solve()
{
    search(0);
}
