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

using pi = pair<int,int>;

bool on_segment(int x, int y, int w, int h)
{
    return (x==0 || x==w || y==0 || y==h);
}

int val(int x, int y, int w, int h)
{
    if(y==0) return x;
    if(x==w) return w+y;
    if(y==h) return w+h+(w-x);
    return w+h+w+h-y;
}

string solve()
{
    int W,H,n;
    cin >>W >>H >>n;

    vector<pi> e;
    rep(i,n)
    {
        int px,py,qx,qy;
        cin >>px >>py >>qx >>qy;
        if(on_segment(px,py,W,H) && on_segment(qx,qy,W,H))
        {
            e.pb({val(px,py,W,H),i});
            e.pb({val(qx,qy,W,H),i});
        }
    }
    sort(all(e));

    stack<int> st;
    vector<bool> vis(n);
    rep(i,e.size())
    {
        int id = e[i].se;
        if(vis[id])
        {
            if(st.empty() || st.top()!=id) return "NO";
            st.pop();
        }
        else
        {
            st.push(id);
            vis[id]=true;
        }
    }

    return "YES";
}

int main()
{
    cout << solve() << endl;
    return 0;
}
