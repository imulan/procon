#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using vi = vector<int>;
using pi = pair<int,int>;

vi merge(vi a, vi b){
    if(a.size() < b.size()) swap(a,b);
    for(int j:b) a.pb(j);
    return a;
}

int main(){
    int n;
    scanf(" %d", &n);

    vector<vi> ch(n);
    rep(i,n){
        int c;
        scanf(" %d", &c);
        vi v(c);
        rep(j,c) {
            scanf(" %d", &v[j]);
            --v[j];
        }
        sort(all(v));

        ch[i] = v;
    }

    vector<pi> a(n);
    rep(i,n) a[i] = {ch[i].size(), i};
    sort(all(a));

    vector<bool> ave(n);
    int idx = 0;
    while(idx<n && a[idx].fi==0){
        ave[ a[idx].se ] = true;
        ++idx;
    }

    vector<pi> ans;
    for(int i=idx; i<n; ++i){
        int v = a[i].se;

        vector<int> children;
        for(int j:ch[v]){
            if(ave[j]) children.pb(j);
        }

        vector<int> nc;
        for(int j:children){
            ave[j] = false;
            ans.pb({v,j});

            nc = merge(nc,ch[j]);
            nc.pb(j);
        }
        sort(all(nc));

//        printf(" %d :: v %d\n",i,v);
//        printf(" nc");
//        for(int j:nc) printf(" %d",j);
//        printf("\n");

        if(ch[v] != nc){
            printf("NO\n");
            return 0;
        }

        ave[v] = true;
    }

    if((int)ans.size() != n-1){
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for(const auto &e:ans) printf("%d %d\n", e.fi+1, e.se+1);
    return 0;
}