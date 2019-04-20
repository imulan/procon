#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back

#define X first
#define Y second

using P = pair<ll,ll>;
using L = pair<P,P>;

L read_L(){
    ll x1,y1,x2,y2;
    cin >>x1 >>y1 >>x2 >>y2;
    return {{x1,y1},{x2,y2}};
}


ll dot(P a, P b) {
  return a.X*b.X + a.Y*b.Y;
}

ll cross(P a, P b) {
  return a.X*b.Y - a.Y*b.X;
}

ll norm(P a) {
  return a.X*a.X + a.Y*a.Y;
}

int ccw(P a, P b, P c) {
    b.X -= a.X;
    b.Y -= a.Y;
    c.X -= a.X;
    c.Y -= a.Y;
//   b -= a;  c -= a;
  if (cross(b,c) >  0) return +1;  // counter clockwise
  if (cross(b,c) <  0) return -1;  // clockwise
  if (dot(b,c)   <  0) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}


int main(){
    int n;
    cin >>n;

    vector<int> a;
    a.

    vector<L> l(n);
    rep(i,n) l[i]= read_L();

    vector<vector<int>> g(n);

    auto isec = [&](L a, L b){
        P a1 = a.first, a2 = a.second;
        P b1 = b.first, b2 = b.second;
        return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 && ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
    };

    ll cp = 0;
    rep(i,n)rep(j,i){
        if(isec(l[i],l[j])){
            ++cp;
            g[i].pb(j);
            g[j].pb(i);
        }
    }

    ll cc = 0;
    vector<bool> vis(n);
    rep(i,n)if(!vis[i]){
        ++cc;
        queue<int> que;
        que.push(i);
        vis[i] = true;
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:g[v]){
                if(!vis[e]){
                    que.push(e);
                    vis[e] = true;
                }
            }
        }
    }

    cout << cc - n + cp << endl;
    return 0;
}
