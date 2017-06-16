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
    rep(i,1<<n)
    {
        int a;
        scanf(" %d", &a);
        que.push(a);
    }

    while(que.size()>1)
    {
        int x = que.front(); que.pop();
        int y = que.front(); que.pop();

        if(x==y) que.push(x);
        else que.push(abs(x-y));
    }

    printf("%d\n", que.front());
    return 0;
}
