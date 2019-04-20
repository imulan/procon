#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const vector<int> NG(1,-1);

vector<int> solve(){
    int b,p;
    scanf(" %d %d", &b, &p);

    vector<int> d(p);
    rep(i,p) scanf(" %d", &d[i]);

    int k;
    scanf(" %d", &k);

    vector<int> a(k),v(k);
    rep(i,k){
        scanf(" %d %d", &a[i], &v[i]);
        --v[i];
    }

    vector<queue<int>> q(k-1);
    rep(i,k-1){
        int j=i+1;
        queue<int> ord;

        int pi = v[i], pj = v[j];
        while(pj<p-1){
            while(pj<p-1 && d[pj+1]<=d[pi]+b){
                ++pj;
                ord.push(j);
            }
            if(pj == p-1) break;

            while(pi<pj && d[pj]-d[pi+1]>=max(a[i],a[j])){
                ++pi;
                ord.push(i);
            }
        }

        if(pj != p-1) return NG;
        while(pi < p-1){
            ++pi;
            ord.push(i);
        }

        q[i] = ord;

        printf(" -- %d\n",i);
        while(!ord.empty()){
            printf(" %d", ord.front());
            ord.pop();
        }
        printf("\n");
    }


    return vector<int>(1,1);
}

int main(){
    vector<int> v = solve();
    int n = v.size();
    if(v[0]==-1) printf("impossible\n");
    else rep(i,n) printf("%d%c", v[i], " \n"[i==n-1]);
    return 0;
}