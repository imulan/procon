#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int main()
{
    int n;
    scanf(" %d", &n);

    queue<int> que;
    vector<int> d(n,19191919);
    rep(i,n)
    {
        int a;
        scanf(" %d", &a);
        if(a==0)
        {
            d[i] = 0;
            que.push(i);
        }
    }

    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(int i:vector<int>({-1,1}))
        {
            int nx = v+i;
            if(0<=nx && nx<n && d[nx]>d[v]+1)
            {
                d[nx] = d[v]+1;
                que.push(nx);
            }
        }
    }

    rep(i,n) printf("%d%c", d[i], " \n"[i==n-1]);
    return 0;
}
