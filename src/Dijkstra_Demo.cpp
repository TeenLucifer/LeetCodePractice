//
// Created by t-rex on 22-10-11.
//

#include "Dijkstra_Demo.h"

Dijkstra_Demo::Dijkstra_Demo()
{
    //createUDN(G);
    setUDG();
    for(int i = 0; i < G.vexNum; ++i)
    {
        final[i] = false;
        distance[i] = G.arcs[V0][i];
        pathArc[i] = V0;
    }
    distance[V0] = 0;
    final[V0] = true;

    cout << endl;
    printGraph(G);
}

int Dijkstra_Demo::locateVex(MGraph &G, int v)
{
    for(int i = 0; i < G.vexNum; ++i)
    {
        if(G.vexs[i] == v)
        {
            return i;
        }
    }
    cout << "no such vertex." << endl;
    return -1;
}

void Dijkstra_Demo::createUDN(MGraph &G)
{
    int v;
    int a;

    REINPUT1:
    cout << "please input the number of vertexes" << endl;
    cin >> v;
    if(v > MAX_VERTEX_NUM || v <= 0)
    {
        cout << "the number of vertexes is out of range, please input again" << endl;
        goto REINPUT1;
    }

    REINPUT2:
    cout << "please input the number of arcs" << endl;
    cin >> a;
    if(a > (v * (v - 1) / 2) || a <= 0)
    {
        cout << "the number of arcs is out of range, please input again" << endl;
        goto REINPUT2;
    }

    G.vexNum = v;
    G.arcNum = a;

    int vex;
    for(int i = 0; i < G.vexNum; ++i)
    {
        cout << "please input the element of this vertex" << endl;
        cin >> vex;
        G.vexs[i] = vex;
    }
    for (int i = 0; i < G.vexNum; i++) //初始化矩阵，给矩阵赋值
    {
        for (int j = 0; j < G.vexNum; j++)
        {
            G.arcs[i][j] = INFINITE;//先把矩阵的每个元初始化为无穷
        }
    }

    for (int i = 0; i < G.arcNum; i++) //创建顶点之间的连接关系，更新矩阵
    {
        VertexType v1, v2;
        VRType w;
        cout << "please input two vertex elements to build relation" << endl;
        cin >> v1;
        cin >> v2;
        cout << "please the weights between these two vertexes" << endl;
        cin >> w;

        int n = locateVex(G, v1);
        int m = locateVex(G, v2); //确定顶点位置
        if (m == -1 || n == -1)
        {
            cout << "no this vertex." << endl;//输入的两个顶点至少有一个不存在
            return;
        }

        G.arcs[n][m] = w;//权值赋值
        G.arcs[m][n] = w;//矩阵对称
    }

    for (int i = 0; i < G.vexNum; i++)
    {
        for (int j = 0; j < G.vexNum; j++)
        {
            if (i == j) //对角线上的元置0
            {
                G.arcs[i][j] = 0;
            }
        }
    }
}

void Dijkstra_Demo::setUDG()
{
    G.vexNum = 6;
    G.arcNum = 8;

    G.vexs[0] = 1;
    G.vexs[1] = 2;
    G.vexs[2] = 3;
    G.vexs[3] = 4;
    G.vexs[4] = 5;
    G.vexs[5] = 6;

    for (int i = 0; i < G.vexNum; i++) //初始化矩阵，给矩阵赋值
    {
        for (int j = 0; j < G.vexNum; j++)
        {
            G.arcs[i][j] = INFINITE;//先把矩阵的每个元初始化为无穷
        }
    }

    G.arcs[locateVex(G, 1)][locateVex(G, 3)] = 10;
    G.arcs[locateVex(G, 1)][locateVex(G, 5)] = 30;
    G.arcs[locateVex(G, 1)][locateVex(G, 6)] = 100;
    G.arcs[locateVex(G, 2)][locateVex(G, 3)] = 5;
    G.arcs[locateVex(G, 3)][locateVex(G, 1)] = 10;
    G.arcs[locateVex(G, 3)][locateVex(G, 2)] = 5;
    G.arcs[locateVex(G, 3)][locateVex(G, 4)] = 50;
    G.arcs[locateVex(G, 4)][locateVex(G, 3)] = 50;
    G.arcs[locateVex(G, 4)][locateVex(G, 5)] = 20;
    G.arcs[locateVex(G, 4)][locateVex(G, 6)] = 10;
    G.arcs[locateVex(G, 5)][locateVex(G, 1)] = 30;
    G.arcs[locateVex(G, 5)][locateVex(G, 4)] = 20;
    G.arcs[locateVex(G, 5)][locateVex(G, 6)] = 60;
    G.arcs[locateVex(G, 6)][locateVex(G, 1)] = 100;
    G.arcs[locateVex(G, 6)][locateVex(G, 4)] = 10;
    G.arcs[locateVex(G, 6)][locateVex(G, 5)] = 60;

    for (int i = 0; i < G.vexNum; i++)
    {
        for (int j = 0; j < G.vexNum; j++)
        {
            if (i == j) //对角线上的元置0
            {
                G.arcs[i][j] = 0;
            }
        }
    }
}

void Dijkstra_Demo::printGraph(MGraph G) //打印整个图
{
    cout << "图的邻接矩阵是：" << endl;
    for (int i = 0; i < G.vexNum; i++)
    {
        for (int j = 0; j < G.vexNum; j++)
        {
            cout << G.arcs[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

void Dijkstra_Demo::shortestPath_Dijkstra()
{
    for (int i = 1; i < G.vexNum; i++)//v从1开始，因为V0已经确定了，不再考虑；//遍历邻接矩阵的每一列
    {
        min = INFINITE;//先让min=无穷，先和无穷比，比无穷小说明有连线，否则没有连线；
        for (int j = 0; j < G.vexNum; j++)//遍历邻接矩阵的每一行
        {
            if (!final[j] && distance[j] < min)//如果w这个顶点还没有确认最短路径，并且现有的权值之和小于min
            {
                k = j;//更新下标
                min = distance[j];//更新min
            }
            //到这里为止只是更新了两个临时变量，还没有更新三个数组的内容
        }
        final[k] = true;//将目前找到的顶点置为ture，也就是k这个顶点已经找到最短路径 //final数组被更新

        for (int j = 0; j < G.vexNum; j++)//还是遍历每一行，更新当前最短路径前驱顶点和路径值
        {
            if (!final[j])//如果w这个顶点还没有确认最短路径，
            {
                if (min + G.arcs[k][j] < distance[j])//并且经过k顶点到达j顶点的路径总和，要小于不经过k顶点、直接到达j顶点的路径；
                {
                    distance[j] = min + G.arcs[k][j];//就把最短路径的值更新为经过k顶点的路径总和，也就是选更小的权值和；//Distance数组被更新
                    pathArc[j] = k;//前驱顶点下标更新为k //Patharc数组被更新
                }
            }
        }
    }
    cout << endl;

    /*for (auto i : Patharc)
    {
        cout << i << " ";
    }
    cout << endl;*/ //调试用

    //打印
    cout << "Dijkstra算法求出的最短路径是：" << endl;
    for (int i = 0; i < G.vexNum; i++)
    {
        if (i != 0 && distance[i] != INFINITE)
        {
            cout << "从顶点" << G.vexs[V0] << "到顶点" << G.vexs[i] << "，" << "最短路径权值是：" << distance[i] << "，最短路径为：";

            int m = i;
            while (m != 0)
            {
                path.push(G.vexs[m]);//入栈
                m = pathArc[m];//m更新为m的前驱
            }
            path.push(G.vexs[V0]);

            while (!path.empty())
            {
                if (path.size() == 1)
                {
                    cout << path.top();//打印最后一个栈元素
                }
                else
                {
                    cout << path.top() << "->";//打印栈顶
                }
                path.pop();//出栈
            }
            cout << endl;
        }
    }
    cout << endl;
}

void Dijkstra_Demo::computePath()
{
    //将所有节点分为两个集合：s，u
    //s为所有已知最短路径的节点
    //u为其它节点
    //算法思路：
    //1.从u中选取距离起点路径最短的点k，加入s中，从u中删除
    //2.更新u中各顶点到起点的距离，因为k是已经确定最短路径的节点
    //3.重复1、2直至所有节点搜索完毕
    for(int i = 1; i < G.vexNum; ++i)
    {
        min = INFINITE;
        for(int j = 0; j < G.vexNum; ++j)
        {
            if(!final[j] && distance[j] < min)
            {
                k = j;
                min = distance[j];//这一步是从U中寻找距离V0最短的节点k
            }
        }
        final[k] = true;//加入S中，从U中删除

        for(int j = 0; j < G.vexNum; ++j)
        {
            if(!final[j])
            {
                if(min + G.arcs[k][j] < distance[j])
                {
                    distance[j] = min +G.arcs[k][j];
                    pathArc[j] = k;
                    //更新U中各顶点到起点的距离
                }
            }
        }
    }


}

void Dijkstra_Demo::computePath2()
{
    /*
    将所有节点分为两个集合：S，U
        s为所有已知最短路径的节点
        u为其它节点
    算法思路：
        1.从u中选取距离起点路径最短的点k，加入s中，从u中删除
        2.更新u中各顶点到起点的距离，因为k是已经确定最短路径的节点
        3.重复1、2直至所有节点搜索完毕
     */
    vector<int> S;
    vector<int> U;
    vector<int> dis;//各节点距离V0最短的距离

    int s = G.vexs[V0];
    S.push_back(s);
    for(int i = 0; i < G.vexNum; ++i)
    {
        dis.push_back(G.arcs[V0][i]);
    }
    for(int i = 0; i < G.vexNum; ++i)
    {
        if(G.vexs[i] != s)
        {
            U.push_back(G.vexs[i]);
        }
    }
    int min = INFINITE;
    int k = -1;
    for(int i = 1; i < G.vexNum; ++i)
    {
        for(int j = 0; j < U.size(); ++j)
        {
            if((dis[U[j] - 1] < min) && (std::find(S.begin(), S.end(), U[j]) == S.end()))
            {
                min = dis[U[j] - 1];
                k = U[j];//从U中选取距离V0最短的节点k
            }
        }
        S.push_back(k);//加入S
        /*
        这里将节点k的最短路径确定下来，有一种归纳的思想
        假设起点s到前驱结点k-1是最短路径，那么按照贪心策略，k-1->k应该选择边最短的那条arc_min
            若有另一条路径arc_other < arc_min经过中间结点t使得k-1->k最短
            k-1->t的边长arc > arc_min，因此假设（存在arc_other）不成立，即arc_min最短
        而归纳到起点s的时候，s作为前驱结点，到相邻距离最近的节点的距离必定是最短的，因此归纳成立
         */
        std::remove(U.begin(), U.end(),k);//从U中删除
        for(int j = 0; j < U.size(); ++j)
        {
            if(std::find(S.begin(), S.end(), U[j]) == S.end())
            {
                if(min + G.arcs[k][U[j]] < dis[U[j]])
                {
                    dis[U[j]] = min + G.arcs[k][U[j]];//更新U中各顶点到V0的距离
                    pathArc[U[j]] = k;
                }
            }
        }
    }

    cout << "Dijkstra算法求出的最短路径是：" << endl;
    for (int i = 0; i < G.vexNum; i++)
    {
        if (i != 0 && dis[i] != INFINITE)
        {
            cout << "从顶点" << G.vexs[V0] << "到顶点" << G.vexs[i] << "，" << "最短路径权值是：" << dis[i] << "，最短路径为：";

            int m = i;
            while (m != 0)
            {
                path.push(G.vexs[m]);//入栈
                m = pathArc[m];//m更新为m的前驱
            }
            path.push(G.vexs[V0]);

            while (!path.empty())
            {
                if (path.size() == 1)
                {
                    cout << path.top();//打印最后一个栈元素
                }
                else
                {
                    cout << path.top() << "->";//打印栈顶
                }
                path.pop();//出栈
            }
            cout << endl;
        }
    }
    cout << endl;
}