#include <iostream>
#include <fstream>
#include "ListNode.h"

using namespace std;

void equivalence()
{
    ifstream inFile;
    inFile.open("D:\\GitHub\\DataStructure\\Lists\\EquivalenceClasses\\EquivalenceClasses\\equiv.in", ifstream::in);

    if (!inFile)
    {
        cout << "Can't open input file" << endl;
        return;
    }

    int i, j, n;
    inFile >> n;

    // Initialize seq and out
    ListNodePtr *seq = new ListNodePtr[n];
    bool *out = new bool[n];
    for (i = 0; i < n; i++)
    {
        seq[i] = 0;
        out[i] = false;
    }

    // Phase1: read equivalence pairs and set up linked list.
    inFile >> i >> j;
    while (inFile.good())
    {
        ListNode *x = new ListNode(j);
        x->pNext = seq[i];
        seq[i] = x;

        ListNode *y = new ListNode(i);
        y->pNext = seq[j];
        seq[j] = y;

        inFile >> i >> j;
    }

    // Phase2: output equivalence classes
    for (i = 0; i < n; i++)
    {
        if (out[i] == false)
        {
            cout << endl << "A new class:" << i;
            out[i] = true;

            ListNodePtr x, y, top = 0;
            x = seq[i];
            while (1)
            {
                while (x)
                {
                    j = x->data;
                    if (out[j] == false)
                    {
                        cout << ", " << x->data;
                        out[j] = true;

                        // push into stack
                        y = x->pNext;
                        x->pNext = top;
                        top = x;
                        x = y;
                    }
                    else
                    {
                        x = x->pNext;
                    }
                }

                if (top == NULL)
                {
                    break;
                }
                else
                {
                    x   = seq[top->data];
                    top = top->pNext;   // Pop stack
                }
            }
        }
    }

    // Free memory
    ListNodePtr p, q;
    for (i = 0; i < n; i++)
    {
        p = seq[i];
        while (p)
        {
            q = p->pNext;
            delete p;
            p = q;
        }
    }

    delete []seq;
    delete []out;
}

void main()
{
    equivalence();
}