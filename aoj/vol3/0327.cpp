#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    vector<int> x(9);
    rep(i,9) cin >>x[i];

    vector<int> p(9);
    iota(all(p),1);

    int ans=0;
    do {
        bool go=true;
        rep(i,9)if(x[i]!=-1)
        {
            if(p[i]!=x[i]) go=false;
        }
        if(!go) continue;

        int a = p[0]+p[2]+p[5];
        if(a%10!=p[8]) continue;
        int X = a/10;

        a = p[1]+p[4]+X;
        if(a%10!=p[7]) continue;
        X = a/10;

        a = p[3]+X;
        if(a%10!=p[6]) continue;
        X = a/10;
        if(X!=0) continue;

        ++ans;
    } while(next_permutation(all(p)));

    cout << ans << endl;
    return 0;
}
