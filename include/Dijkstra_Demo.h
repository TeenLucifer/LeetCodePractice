//
// Created by t-rex on 22-10-11.
//

#ifndef DATASTRUCTURE_DIJKSTRA_DEMO_H
#define DATASTRUCTURE_DIJKSTRA_DEMO_H

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_VERTEX_NUM 20
#define INFINITE 9999
#define VRType int
#define VertexType int

class MGraph
{
public:
    VertexType vexs[MAX_VERTEX_NUM];
    VRType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexNum;
    int arcNum;
};

class Dijkstra_Demo{
public:
    Dijkstra_Demo();
    ~Dijkstra_Demo();
    int locateVex(MGraph &G, VertexType v);
    void createUDN(MGraph &G);
    void printGraph(MGraph G);
    void shortestPath_Dijkstra();
    void computePath();
    void computePath2();
    void setUDG();

    MGraph G;
    int V0 = 0;
    int pathArc[MAX_VERTEX_NUM];
    int distance[MAX_VERTEX_NUM];
    bool final[MAX_VERTEX_NUM];
    int k;
    int min;
    stack<int> path;
};


#endif //DATASTRUCTURE_DIJKSTRA_DEMO_H
