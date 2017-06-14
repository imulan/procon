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

int solve(int x)
{
    unordered_map<int,int> d;
    d[x]=0;
    queue<int> que;
    que.push(x);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();

        if(v==1) break;

        if(!d.count(v+1) || d[v+1]>d[v]+1)
        {
            d[v+1] = d[v]+1;
            que.push(v+1);
        }
        if(!d.count(v-1) || d[v-1]>d[v]+1)
        {
            d[v-1] = d[v]+1;
            que.push(v-1);
        }
        if(v%3==0)
        {
            if(!d.count(v/3) || d[v/3]>d[v]+1)
            {
                d[v/3] = d[v]+1;
                que.push(v/3);
            }
        }
    }

    return d[1];
}

int main()
{
    int x;
    cin >>x;
    cout << solve(x) << endl;
    return 0;
}
