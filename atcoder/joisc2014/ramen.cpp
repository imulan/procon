#include "ramen.h"
#include <bits/stdc++.h>
using namespace std;

void Ramen(int N)
{
    int low=N-1,high=N-1;
    for(int i=0; 2*i+1<N; ++i)
    {
        int tl=2*i, th=2*i+1;
        if(Compare(tl,th)==1) swap(tl,th);

        if(tl!=low)
        {
            if(Compare(low,tl)==1) low=tl;
        }
        if(th!=high)
        {
            if(Compare(th,high)==1) high=th;
        }
    }
    Answer(low,high);
}
