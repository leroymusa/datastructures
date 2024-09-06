#include "SegmentTree.h"
#include <algorithm>
#include <climits>

SegmentTree::SegmentTree(const std::vector<int> &data)
{
    n = data.size();
    tree.resize(4 * n);
    buildTree(data, 0, n - 1, 0);
}

void SegmentTree::buildTree(const std::vector<int> &data, int start, int end, int node)
{
    if (start == end)
    {
        tree[node] = data[start];
    }
    else
    {
        int mid = (start + end) / 2;
        buildTree(data, start, mid, 2 * node + 1);
        buildTree(data, mid + 1, end, 2 * node + 2);
        tree[node] = std::min(tree[2 * node + 1], tree[2 * node + 2]);
    }
}

int SegmentTree::queryTree(int start, int end, int l, int r, int node) const
{
    if (r < start || l > end)
    {
        return INT_MAX;
    }
    if (l <= start && r >= end)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int leftQuery = queryTree(start, mid, l, r, 2 * node + 1);
    int rightQuery = queryTree(mid + 1, end, l, r, 2 * node + 2);
    return std::min(leftQuery, rightQuery);
}

int SegmentTree::query(int left, int right) const
{
    return queryTree(0, n - 1, left, right, 0);
}

void SegmentTree::updateTree(int start, int end, int index, int value, int node)
{
    if (start == end)
    {
        tree[node] = value;
    }
    else
    {
        int mid = (start + end) / 2;
        if (index <= mid)
        {
            updateTree(start, mid, index, value, 2 * node + 1);
        }
        else
        {
            updateTree(mid + 1, end, index, value, 2 * node + 2);
        }
        tree[node] = std::min(tree[2 * node + 1], tree[2 * node + 2]);
    }
}

void SegmentTree::update(int index, int value)
{
    updateTree(0, n - 1, index, value, 0);
}
