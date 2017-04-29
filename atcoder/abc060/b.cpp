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
    int a,b,c;
    cin >>a >>b >>c;

    vector<bool> vis(b,false);

    int now=a%b;
    vis[now]=true;
    while(1)
    {
        (now+=a)%=b;
        if(vis[now]) break;
        vis[now]=true;
    }

    cout << (vis[c]?"YES":"NO") << endl;
    return 0;
}
