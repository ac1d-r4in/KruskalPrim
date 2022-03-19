#include <iostream>
#include <fstream>
#include "lab1aisd.cpp"

#define MAX_NODES 30
#define MAX_LINKS 30
#define nodes 11

using namespace std;

char Output[100];
//size_t nodes;// i, j, k ,m;
int sum = 0;
struct points
{
    short A, B;
};
double selection(short *A);
void printarray(int **A[[]], int elements);

void fillgraph(int **D[[]])
{
    for (size_t i = 0; i < nodes; i++)
        D[i] = new int[nodes];
    for (size_t i = 0; i < nodes; i++)
        for (size_t j = 0; j < nodes; j++)
            D[i][j] = 0;
}

void output(short A, short B)
{
    char BuffA[10] = "", BuffB[10] = "";
    itoa(A, BuffA, 10);
    itoa(B, BuffB, 10);
    strcat(BuffA, "--");
    strcat(BuffB, "\n");
    strcat(BuffA, BuffB);
    strcat(Output, BuffA);
}

void output2(short A)
{
    char BuffA[10] = "";
    itoa(A, BuffA, 10);
    strcat(BuffA, " < ");
    strcat(Output, BuffA);
}

void readgraph(int **A[[]])
{
    char a[10];
    ifstream f("graph.txt");
    if (!f)
        return;
    A[0][0] = 0;
    for (size_t i = 1; i < nodes; i++)
    {
        A[0][i] = i;
        A[i][0] = i;
    }
    for (size_t i = 1; i < nodes; i++)
        for (size_t j = 1; j < nodes; j++)
        {
            f >> a;
            A[i][j] = atoi(a);
        }

    printarray(A, nodes);
}

void printarray(int **A[[]], int elements)
{
    for (size_t i = 0; i < elements; i++)
    {
        for (size_t j = 0; j < elements; j++)
            cout << " " << A[i][j];
        cout << endl;
    }
}