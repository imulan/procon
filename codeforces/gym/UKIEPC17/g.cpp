#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

struct P{
    int x[3];
    void print(){
        printf("(%d %d %d)", x[0], x[1], x[2]);
    }
};

bool EQ(P a, P b){
    rep(i,3)if(a.x[i] != b.x[i]) return false;
    return true;
}

void OUT(P a, P b){
    a.print();
    printf(" ");
    b.print();
    printf("\n");
}

P READ(){
    P ret;
    rep(i,3) scanf(" %d", &ret.x[i]);
    return ret;
}

int main(){
    P a = READ(), ag = READ();
    P b = READ(), bg = READ();

    OUT(a,b);

    int idx = -1;
    rep(i,3){
        if(ag.x[i] != bg.x[i]) idx = i;
    }
    assert(idx != -1);

    pi aa = {a.x[(idx+1)%3], a.x[(idx+2)%3]};
    pi bb = {b.x[(idx+1)%3], b.x[(idx+2)%3]};

    bool flg = false;
    if(aa==bb) flg = true;

    if(flg){
        a.x[(idx+1)%3]++;
        OUT(a,b);
    }

//    MOVE idx direction
    while(a.x[idx]!=ag.x[idx] || b.x[idx]!=bg.x[idx]){
        if(a.x[idx] < ag.x[idx]) a.x[idx]++;
        else if(a.x[idx] > ag.x[idx]) a.x[idx]--;

        if(b.x[idx] < bg.x[idx]) b.x[idx]++;
        else if(b.x[idx] > bg.x[idx]) b.x[idx]--;

        OUT(a,b);
    }

    if(flg){
        a.x[(idx+1)%3]--;
        OUT(a,b);
    }

//    printf(" MOVE idx %d END\n",idx);

    int d1 = (idx+1)%3, d2 = (idx+2)%3;
    while(!EQ(a,ag) || !EQ(b,bg)){
        if(a.x[d1] < ag.x[d1]) a.x[d1]++;
        else if(a.x[d1] > ag.x[d1]) a.x[d1]--;
        else{
            if(a.x[d2] < ag.x[d2]) a.x[d2]++;
            else if(a.x[d2] > ag.x[d2]) a.x[d2]--;
        }

        if(b.x[d1] < bg.x[d1]) b.x[d1]++;
        else if(b.x[d1] > bg.x[d1]) b.x[d1]--;
        else{
            if(b.x[d2] < bg.x[d2]) b.x[d2]++;
            else if(b.x[d2] > bg.x[d2]) b.x[d2]--;
        }

        OUT(a,b);
    }

    return 0;
}