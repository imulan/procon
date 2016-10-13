#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <bitset>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=300;
const int INF=12345678;
int dist[N][N];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    vector< bitset<N> > c(n);

    rep(i,m)
    {
        int num;
        scanf(" %d", &num);

        bitset<N> bit;
        vector<int> a(num);
        rep(j,num)
        {
            scanf(" %d", &a[j]);
            --a[j];
            bit.set(a[j]);
        }

        rep(j,num) c[a[j]] |= bit;
    }

    rep(i,n)rep(j,n)
    {
        if(i==j) dist[i][j]=0;
        else
        {
            if(c[i][j]) dist[i][j]=1;
            else dist[i][j]=INF;
        }
    }

    rep(k,n)rep(i,n)rep(j,n) dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);

    int min_sum=INF;
    int ans=INF;
    rep(i,n)
    {
        int a=0;
        rep(j,n)
        {
            if(i==j) continue;
            a+=dist[i][j];
        }

        // printf("%d: %d\n", i,a);
        if(a<min_sum)
        {
            double tmp=a*100.0/(n-1);
            ans=tmp;
            min_sum=a;
        }
    }

    printf("%d\n", ans);
    return 0;
}
