#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

//directed graph
vector<int> G[1000];
//hash
string name[1000];

void dfs(int now, int d)
{
    rep(i,d) printf(".");
    cout << name[now] << endl;

    rep(i,G[now].size()) dfs(G[now][i],d+1);
}

int main()
{
    int n;
    cin >>n;

    int k;
    string m;

    //make root
    cin >>k >>m;
    name[0]=m;

    //make tree
    rep(i,n-1)
    {
        cin >>k >>m;
        name[i+1]=m;
        G[k-1].pb(i+1);
    }

    //answer
    dfs(0,0);

    return 0;
}
