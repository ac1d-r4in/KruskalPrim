#include "graph.cpp"
#include <iostream>
#include <cstring>

void prim(short number, int **Graph[[]], int Result[]);

int main()
{
    size_t links;
    short num;
    try
    {
        cout << "Enter number of graph nodes: ";
        cin >> nodes;
        nodes += 1;
        if (cin.fail())
            throw 1;
        if (nodes > MAX_NODES)
            throw 2;

        int **Graph = new int *[nodes];
        for (i = 0; i < nodes; i++)
            Graph[i] = new int[nodes];
        fillgraph(Graph);

        for (i = 1; i < nodes; i++)
        {
            Graph[0][i] = i;
            Graph[i][0] = i;
        }

        for (i = 1; i < nodes; i++)
            for (j = 1; j < nodes; j++)
            {
                if (i < j)
                {
                    cout << "Enter weight of link between nodes " << Graph[i][0] << " and " << Graph[0][j] << " or 0 if they haven't any: ";
                    cin >> Graph[i][j];
                    Graph[j][i] = Graph[i][j];
                    if (cin.fail())
                    throw 1;
                }
            }

        int *Result = new int[nodes - 1];
        for (i = 0; i < nodes - 1; i++)
            Result[i] = 0;
        
        // cout << "Enter starting node: ";
        // cin >> num;
        // if (cin.fail())
        //     throw 1;
        num = 1;
        Result[0] = num;
        prim(num, Graph, Result);
    }
    catch (int e)
    {
        if (e == 1)
            cout << "Wrong input!" << endl;
        if (e == 2)
            cout << "Too much nodes!" << endl;
        exit(e);
    }

    cout << "Graph base structure: " << endl
         << endl
         << Output << endl
         << "Total weight sum: " << sum;
    return 0;
}

void prim(short number, int **Graph[[]], int Result[])
{
    if (Result[nodes-2] != 0)
        return;

    short min = 0, pointA, pointB;
    for (i = 1; i < number + 1; i++)
    {
        if (min != 0) break;
        for (j = 1; j < nodes; j++)
            if (Graph[i][j] != 0)
            {
                min = Graph[i][j];
                pointA = i;
                pointB = j;
                break;
            }
    }
    i = 0;
    while (Result[i] != 0)
    {
        j = Result[i];
        for (k = 1; k < nodes; k++)
            if (Graph[j][k] != 0 && Graph[j][k] < min)
            {
                min = Graph[j][k];
                pointA = j;
                pointB = k;
            }
        i++;
    }
    for (m = 1; m < nodes; m++)
        Graph[m][pointB] = 0;
    Graph[pointB][pointA] = 0;
    sum += min;
    output(pointA, pointB);
    Result[i] = pointB;
    prim(pointB, Graph, Result);
}