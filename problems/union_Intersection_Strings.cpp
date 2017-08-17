// This program calculates n(A ^ B)/n( A U B)

#include<bits/stdc++.h>

using namespace std;

int calcRatio ( string A[], string B[], int sizeA, int sizeB)
{
    set<string> a(A, A+sizeA), b(B, B+sizeB);


    int nIntersection=0, nUnion=0;

    //Calculating n(A^B) and n(AUB) simultaneously

    set<string>::iterator i;
    set<string>::iterator tmp;
    for(i=a.begin(); i!=a.end(); i++)
    {
        if((tmp=b.find(*i)) != b.end())
        {
            nIntersection++;
            nUnion++;
            a.erase(i);
            b.erase(tmp);
        }

        else
        {
            a.erase(i);
            nUnion++;
        }
    }
    //Intersection has been calculated

    //Now Calculating union for any elements left in set B in above loop
    for(i=b.begin(); i!=b.end(); i++)
    {
        b.erase(i);
        nUnion++;
    }

    cout<<"nUnion = "<<nUnion<<"\n";
    cout<<"nIntersection = "<<nIntersection<<"\n";

    if(nUnion)
        return nIntersection/nUnion;
    else
        return -1;
}

int main()
{
    string A[] = {"shashank", "mohit", "ram", "sita", "gita"};
    string B[] = {"shashank", "mohit", "john"};

    calcRatio(A, B, 5, 3);
}


















