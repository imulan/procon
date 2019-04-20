#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct P{
    int ID;
    int l[4];
    int z;

    void READ(int x){
        ID = x;
        rep(i,4) scanf(" %d", &l[i]);

        z = 0;
        rep(i,4) z += (l[i]==0);
    }

    void rotate(){
        int tmp = l[3];
        for(int i=3; i>0; --i) l[i] = l[i-1];
        l[0] = tmp;
    }
};

int main(){
    int n;
    scanf(" %d", &n);

    vector<P> p(n);
    rep(i,n) p[i].READ(i);

    int mz = 0;
    rep(i,n) mz = max(mz, p[i].z);

    if(mz == 4){
        if(n != 1){
            printf("impossible\n");
        }
        else{
            printf("1 1\n");
            printf("1\n");
        }
        return 0;
    }

    if(mz<2){
        printf("impossible\n");
        return 0;
    }

    vector<vector<int>> pid(3*n);
    rep(i,n){
        rep(j,4){
            int idx = p[i].l[j];
            if(idx != 0) pid[idx].pb(i);
        }
    }

    auto FIND = [&](int idx, int val){
        for(int i:pid[val]){
            if(idx != i) return i;
        }
        assert(false);
    };

//    first piece
    int now = -1;
    if(mz == 3){
        rep(i,n){
            if(p[i].z == mz) now = i;
        }
    }
    else{
        assert(mz == 2);
        rep(i,n){
            if(p[i].z == mz) now = i;
        }
    }
    assert(now != -1);

//    make first line
    rep(i,4){
        if( p[now].l[0]==0 && p[now].l[1]==0 && p[now].l[3]!=0 ) {
            break;
        }
        p[now].rotate();
    }

    if( !(p[now].l[0]==0 && p[now].l[1]==0 && p[now].l[3]!=0) ){
        printf("impossible\n");
        return 0;
    }

    vector<int> first_row;
    first_row.pb(now);
    while(1){
        int LEFT = p[now].l[3];
        if(LEFT == 0) break;

        int nx = FIND(now, LEFT);
        rep(i,4){
            if(p[nx].l[0]==0 && p[nx].l[1]==LEFT){
                break;
            }
            p[nx].rotate();
        }

        if(p[nx].l[0]==0 && p[nx].l[1]==LEFT){
            first_row.pb(nx);
            now = nx;
        }
        else{
            printf("impossible\n");
            return 0;
        }
    }

    int w = first_row.size();
    if(n%w != 0){
        printf("impossible\n");
        return 0;
    }

    int h = n/w;
    vector<vector<int>> ans;
    ans.pb(first_row);
    rep(i,h-1){
        vector<int> thisrow;
        int LEFT = 0;
        rep(j,w){
            int TOP = p[ans[i][j]].l[2];
            if(TOP == 0){
                printf("impossible\n");
                return 0;
            }
            if(j>0 && LEFT==0){
                printf("impossible\n");
                return 0;
            }

            int cur = FIND(ans[i][j], TOP);
            rep(rotate_time,4){
                if(p[cur].l[0]==TOP && p[cur].l[1]==LEFT) break;
                p[cur].rotate();
            }

            if(p[cur].l[0]==TOP && p[cur].l[1]==LEFT){
                thisrow.pb(cur);
                LEFT = p[cur].l[3];
            }
            else{
                printf("impossible\n");
                return 0;
            }
        }

        if(LEFT != 0){
            printf("impossible\n");
            return 0;
        }
        ans.pb(thisrow);
    }

    rep(i,w){
        int idx = ans[h-1][i];
        if(p[idx].l[2]!=0){
            printf("impossible\n");
            return 0;
        }
    }

    printf("%d %d\n", h, w);
    rep(i,h){
        rep(j,w)printf("%d%c", ans[i][j]+1, " \n"[j==w-1]);
    }
    return 0;
}

