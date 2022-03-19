#include <iostream>
#include <windows.h>
#include <cstdio>
#include <conio.h>
#include <algorithm>
#include "graph.cpp"

using namespace std;

void includeboth(int **Nodes[[]], short A, short B, short nodes);
void includeone(int **Nodes[[]], short A, short B, short nodes);
void replace(int **Nodes[[]], short colA, short colB);
void output(short A, short B);
double selection(int A[], int elements);
void kruskal(int **Nodes[[]], size_t i, short weight, short nodes);

int main()
{
    short MIN_LINKS;
    size_t links;
    try
    {
        cout << "Enter number of graph nodes: ";
        cin >> nodes;
        if (cin.fail())
            throw 1;
        if (nodes > MAX_NODES)
            throw 2;
        
        int **Nodes = new int *[nodes];
        for (i = 0; i < nodes; i++)
            Nodes[i] = new int[nodes];
        fillgraph(Nodes);
        for (i = 0; i < nodes; i++)
            Nodes[0][i] = i + 1;

        MIN_LINKS = nodes - 1;
        cout << "Enter number of links: ";
        cin >> links;
        if (cin.fail())
            throw 1;
        if (links < MIN_LINKS)
            throw 3;
        int *Links = new int[links];
        for (i = 0; i < links; i++)
        {
            cout << "Enter weight of link " << i + 1 << ": ";
            cin >> Links[i];
            if (cin.fail())
            throw 1;
        }
        
        selection(Links, links);   // сортировка массива функцией из лр 1
        for (i = 0; i < nodes; i++)
            cout << " " << Links[i];

        for (i = 0; i < nodes; i++)
        {
            if (Nodes[nodes - 1][0] != 0)
                break;
            else
                kruskal(Nodes, i + 1, Links[i], nodes);
        }
    }

    catch (int e)
    {
        if (e == 1)
            cout << "Wrong input!" << endl;
        if (e == 2)
            cout << "Too much nodes!" << endl;
        if (e == 3)
            cout << "Too few links!" << endl;
        exit(e);
    }

    cout << "Graph base structure: " << endl
         << endl
         << Output << endl
         << "Total weight sum: " << sum;
    return 0;
}

void kruskal(int **Nodes[[]], size_t i, short weight, short nodes)
{
    short min, found;
    points point;
    try
    {
        cout << "Link " << i << " with weight " << weight << "\nEnter point A (A--b): ";
        cin >> point.A;
        if (cin.fail())
            throw 1;
        cout << "Enter point B (a--B): ";
        cin >> point.B;
        if (cin.fail())
            throw 1;
    }
    catch (int e)
    {
        if (e == 1)
            cout << "Wrong input!" << endl;
        exit(e);
    }
    found = 0;
    for (j = 0; j < nodes; j++)
        if (Nodes[0][j] == point.A || Nodes[0][j] == point.B)
            found += 1;
    switch (found)
    {
    case 2:
        includeboth(Nodes, point.A, point.B, nodes);
        sum += weight;
        output(point.A, point.B);
        break;
    case 1:
        includeone(Nodes, point.A, point.B, nodes);
        sum += weight;
        output(point.A, point.B);
        break;
    case 0:
        break;
    default:
        cout << "Error! Found = " << found << "A and B are: " << point.A << " " << point.B << endl;
        exit(2);
        break;
    }
}

void includeboth(int **Nodes[[]], short A, short B, short nodes)
{
    short Positions[2];
    for (j = 0; j < nodes; j++)
    {
        if (Nodes[0][j] == A)
            Positions[0] = j;
        if (Nodes[0][j] == B)
            Positions[1] = j;
    }
    replace(Nodes, Positions[0], Positions[1]);
}

void includeone(int **Nodes[[]], short A, short B, short nodes)
{
    short found, tobefound;
    for (j = 0; j < nodes; j++)
    {
        if (Nodes[0][j] == A)
        {
            found = j;
            for (k = 0; k < nodes; k++)
                for (m = 0; m < nodes; m++)
                    if (Nodes[k][m] == B)
                        tobefound = m;
        }
        else if (Nodes[0][j] == B)
        {
            found = j;
            for (k = 0; k < nodes; k++)
                for (m = 0; m < nodes; m++)
                    if (Nodes[k][m] == A)
                        tobefound = m;
        }
    }
    if (tobefound != found)
        replace(Nodes, tobefound, found);
}

void replace(int **Nodes[[]], short colA, short colB)
{
    short a = 0, b = 0;
    do
    {
        a++;
    } while (Nodes[a][colA] != 0);

    //cout << endl << a << " " << colA << endl << b << " " << colB << endl;
    while (Nodes[b][colB] != 0)
    {
        Nodes[a][colA] = Nodes[b][colB];
        Nodes[b][colB] = 0;
        a++;
        b++;
    }
}