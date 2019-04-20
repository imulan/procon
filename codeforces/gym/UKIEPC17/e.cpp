#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;
using P = pair<pi,int>;

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<pi> dep(n);
    rep(i,n){
        scanf(" %d", &dep[i].fi);
        dep[i].se = i;
    }
    sort(all(dep));
    reverse(all(dep));

    vector<int> p(m),r(m);
    rep(i,m) scanf(" %d", &p[i]);
    rep(i,m) scanf(" %d", &r[i]);

    vector<P> bu(m);
    rep(i,m) bu[i] = {{p[i],r[i]},i};
    sort(all(bu));
    reverse(all(bu));

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int bidx = 0;
    vector<int> v(n);
    rep(i,n){
        int stu = dep[i].fi;
        int ID = dep[i].se;

        while(bidx<m && bu[bidx].fi.fi >= stu){
//            printf(" ADD %d CAP %d\n", bu[bidx].se, bu[bidx].fi.fi);
            pq.push({bu[bidx].fi.se, bu[bidx].se});
            ++bidx;
        }

        if(pq.empty()){
            printf("impossible\n");
            return 0;
        }

        pi cur = pq.top();
//        printf(" stu %d ID %d :: cost %d\n", stu,ID, cur.fi);
        pq.pop();
        v[ID] = cur.se+1;
    }

    rep(i,n) printf("%d%c", v[i], " \n"[i==n-1]);
    return 0;
}