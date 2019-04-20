#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N = 1000010;
vector<int> m[N];

int main(){
    int n;
    scanf(" %d", &n);

    rep(i,n){
        int p;
        scanf(" %d", &p);
        m[p].pb(i+1);
    }

    if(m[1].size()>=2){
        printf("%d %d\n", m[1][0], m[1][1]);
        return 0;
    }

    int x = 1, y = 1;
    bool t = false;
    while(x<N && y<N){
        if(t) x += y;
        else y += x;
        t = !t;

//        printf(" %d %d\n", x, y);
        if(!m[x].empty() && !m[y].empty()){
            int a = m[x][0], b = m[y][0];
            if(x > y) swap(a,b);
            printf("%d %d\n", a, b);
            return 0;
        }
    }

    printf("impossible\n");
    return 0;
}

