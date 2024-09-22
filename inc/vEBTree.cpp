#include "vEBTree.h"
#include <cmath>
#include <limits.h>

vEBTree::vEBTree(int universeSize) : u(universeSize), min(-1), max(-1)
{
    if (u > 2)
    {
        int upperSqrt = std::sqrt(u);
        summary = new vEBTree(upperSqrt);
        clusters = new vEBTree *[upperSqrt];
        for (int i = 0; i < upperSqrt; ++i)
        {
            clusters[i] = new vEBTree(upperSqrt);
        }
    }
    else
    {
        summary = nullptr;
        clusters = nullptr;
    }
}

void vEBTree::insert(int x)
{
    if (min == -1)
    {
        min = max = x;
    }
    else
    {
        if (x < min)
            std::swap(x, min);
        if (u > 2)
        {
            int h = high(x);
            int l = low(x);
            if (clusters[h]->min == -1)
            {
                summary->insert(h);
                clusters[h]->insert(l);
            }
            else
            {
                clusters[h]->insert(l);
            }
        }
        if (x > max)
            max = x;
    }
}

void vEBTree::remove(int x)
{
    if (min == max)
    {
        min = max = -1;
    }
    else if (u == 2)
    {
        if (x == 0)
            min = 1;
        else
            min = 0;
        max = min;
    }
    else
    {
        if (x == min)
        {
            int firstCluster = summary->minimum();
            x = index(firstCluster, clusters[firstCluster]->minimum());
            min = x;
        }
        int h = high(x);
        int l = low(x);
        clusters[h]->remove(l);
        if (clusters[h]->min == -1)
        {
            summary->remove(h);
        }
        if (x == max)
        {
            if (summary->min == -1)
            {
                max = min;
            }
            else
            {
                int lastCluster = summary->maximum();
                max = index(lastCluster, clusters[lastCluster]->maximum());
            }
        }
    }
}

bool vEBTree::member(int x)
{
    if (x == min || x == max)
        return true;
    if (u == 2)
        return false;
    int h = high(x);
    int l = low(x);
    return clusters[h]->member(l);
}

int vEBTree::minimum()
{
    return min;
}

int vEBTree::maximum()
{
    return max;
}

int vEBTree::successor(int x)
{
    if (u == 2)
    {
        if (x == 0 && max == 1)
            return 1;
        else
            return -1;
    }
    else if (min != -1 && x < min)
    {
        return min;
    }
    else
    {
        int h = high(x);
        int l = low(x);
        int maxLow = clusters[h]->maximum();
        if (maxLow != -1 && l < maxLow)
        {
            int offset = clusters[h]->successor(l);
            return index(h, offset);
        }
        else
        {
            int succCluster = summary->successor(h);
            if (succCluster == -1)
                return -1;
            else
            {
                int offset = clusters[succCluster]->minimum();
                return index(succCluster, offset);
            }
        }
    }
}

int vEBTree::predecessor(int x)
{
    if (u == 2)
    {
        if (x == 1 && min == 0)
            return 0;
        else
            return -1;
    }
    else if (max != -1 && x > max)
    {
        return max;
    }
    else
    {
        int h = high(x);
        int l = low(x);
        int minLow = clusters[h]->minimum();
        if (minLow != -1 && l > minLow)
        {
            int offset = clusters[h]->predecessor(l);
            return index(h, offset);
        }
        else
        {
            int predCluster = summary->predecessor(h);
            if (predCluster == -1)
            {
                if (min != -1 && x > min)
                    return min;
                else
                    return -1;
            }
            else
            {
                int offset = clusters[predCluster]->maximum();
                return index(predCluster, offset);
            }
        }
    }
}

int vEBTree::high(int x)
{
    int upperSqrt = std::sqrt(u);
    return x / upperSqrt;
}

int vEBTree::low(int x)
{
    int upperSqrt = std::sqrt(u);
    return x % upperSqrt;
}

int vEBTree::index(int high, int low)
{
    int upperSqrt = std::sqrt(u);
    return high * upperSqrt + low;
}
