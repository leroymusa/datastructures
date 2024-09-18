#include "DancingLinks.h"
#include <gtest/gtest.h>

TEST(DancingLinksTest, SimpleTest)
{
    DancingLinks dlx(7, 7);

    dlx.addNode(1, 0);
    dlx.addNode(1, 3);
    dlx.addNode(1, 6);
    dlx.addNode(2, 0);
    dlx.addNode(2, 3);
    dlx.addNode(3, 3);
    dlx.addNode(3, 4);
    dlx.addNode(3, 6);
    dlx.addNode(4, 2);
    dlx.addNode(4, 4);
    dlx.addNode(4, 5);
    dlx.addNode(5, 1);
    dlx.addNode(5, 2);
    dlx.addNode(5, 5);
    dlx.addNode(5, 6);
    dlx.addNode(6, 1);
    dlx.addNode(6, 6);
    dlx.addNode(7, 0);
    dlx.addNode(7, 3);

    dlx.solve();
}
