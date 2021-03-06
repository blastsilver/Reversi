//#pragma once
//
//struct vec2 { float x, y; };
//struct vec4 { float x, y, z, w; };
//
//float worldToScreen(int n)
//{
//    float halfSize = (float(SIZE) - 1.0) / 2.0f;
//    return (float(n) / halfSize) - 1.0f;
//}
//void fillTopFlatTriangle(CGraphics * graphics, vec2 & v1, vec2 & v2, vec2 & v3)
//{
//    float invslope1 = (v3.x - v1.x) / (v3.y - v1.y);
//    float invslope2 = (v3.x - v2.x) / (v3.y - v2.y);
//
//    float curx1 = v3.x;
//    float curx2 = v3.x;
//
//    for (int scanlineY = v3.y; scanlineY > v1.y; scanlineY--)
//    {
//        graphics->colour(worldToScreen(curx1) / 2.0f + 1.0f, worldToScreen(scanlineY) / 2.0f + 1.0f, 0);
//        graphics->vertex(worldToScreen(curx1), -worldToScreen(scanlineY));
//
//        graphics->colour(worldToScreen(curx2) / 2.0f + 1.0f, worldToScreen(scanlineY) / 2.0f + 1.0f, 0);
//        graphics->vertex(worldToScreen(curx2), -worldToScreen(scanlineY));
//        curx1 -= invslope1;
//        curx2 -= invslope2;
//    }
//}
//void fillBottomFlatTriangle(CGraphics * graphics, vec2 & v1, vec2 & v2, vec2 & v3)
//{
//    float invslope1 = (v2.x - v1.x) / (v2.y - v1.y);
//    float invslope2 = (v3.x - v1.x) / (v3.y - v1.y);
//
//    float curx1 = v1.x;
//    float curx2 = v1.x;
//
//    for (int scanlineY = v1.y; scanlineY <= v2.y; scanlineY++)
//    {
//        graphics->colour(worldToScreen(curx1) / 2.0f + 1.0f, worldToScreen(scanlineY) / 2.0f + 1.0f, 0);
//        graphics->vertex(worldToScreen(curx1), -worldToScreen(scanlineY));
//
//        graphics->colour(worldToScreen(curx2) / 2.0f + 1.0f, worldToScreen(scanlineY) / 2.0f + 1.0f, 0);
//        graphics->vertex(worldToScreen(curx2), -worldToScreen(scanlineY));
//        curx1 += invslope1;
//        curx2 += invslope2;
//    }
//}
//void swapVertices(vec2 * v1, vec2 * v2)
//{
//    vec2 temp = { v1->x, v1->y };
//    v1->x = v2->x;
//    v1->y = v2->y;
//    v2->x = temp.x;
//    v2->y = temp.y;
//}
//void sortVerticesAscendingByY(vec2 * v1, vec2 * v2, vec2 * v3)
//{
//    if (v1->y < v2->y) swapVertices(v1, v2);
//    if (v1->y < v3->y) swapVertices(v1, v3);
//    if (v2->y < v3->y) swapVertices(v2, v3);
//    if (v3->y < v1->y) swapVertices(v3, v1);
//}
//void drawTriangle(CGraphics * graphics, vec2 & v1, vec2 & v2, vec2 & v3)
//{
//    /* at first sort the three vertices by y-coordinate ascending so v1 is the topmost vertice */
//    sortVerticesAscendingByY(&v1, &v2, &v3);
//
//    /* here we know that v1.y <= v2.y <= v3.y */
//    /* check for trivial case of bottom-flat triangle */
//    if (v2.y == v3.y)
//    {
//        fillBottomFlatTriangle(graphics, v1, v2, v3);
//    }
//    /* check for trivial case of top-flat triangle */
//    else if (v1.y == v2.y)
//    {
//        fillTopFlatTriangle(graphics, v1, v2, v3);
//    }
//    else
//    {
//        vec2 v4;
//        v4.y = v2.y;
//        v4.x = (v1.x + ((float)(v2.y - v1.y) / (float)(v3.y - v1.y)) * (v3.x - v1.x));
//        /* general case - split the triangle in a topflat and bottom-flat one */
//        fillBottomFlatTriangle(graphics, v1, v2, v4);
//        fillTopFlatTriangle(graphics, v2, v4, v3);
//    }
//}