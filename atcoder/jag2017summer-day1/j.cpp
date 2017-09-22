#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)n; ++i)

int s(int x)
{
    int r = 0;
    for(int i=1; i<=x; ++i)
    {
        if(x%i==0) r+=i;
    }
    return r;
}

int main()
{
    vector<int> a;
    for(int i=2; i<=98; ++i)
    {
        if(s(i)==98) a.push_back(i);
    }

    int A = a.size();
    rep(i,A) printf("%d%c", a[i],(i==A-1)?'\n':' ');
    return 0;
}
