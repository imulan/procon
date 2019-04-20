#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define pb push_back

struct MinSegTree{
    int n;
    vector<int> dat;

    MinSegTree(){}
    MinSegTree(int _n){
        n = 1;
        while(n<_n) n*=2;
        dat = vector<int>(2*n-1,INT_MAX);
    }
    void update(int k, int val){
        k += n-1;
        dat[k] = val;
        while(k>0){
            k = (k-1)/2;
            dat[k] = min(dat[2*k+1],dat[2*k+2]);
        }
    }
    int _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return INT_MAX;
        if(a<=l && r<=b) return dat[k];

        int vl = _query(a,b,2*k+1,l,(l+r)/2);
        int vr = _query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
    int query(int a, int b){
        return _query(a,b,0,0,n);
    }
    int get(int k)
    {
        k += n-1;
        return dat[k];
    }
};


int main()
{
    int n;
    scanf(" %d", &n);

    MinSegTree st[2];
    rep(j,2)
    {
        st[j] = MinSegTree(n);
        rep(i,n)
        {
            int v;
            scanf(" %d", &v);
            st[j].update(i,v);
        }
    }

    int Q;
    scanf(" %d", &Q);

    set<int> u;
    rep(i,n) u.insert(i);

    while(Q--)
    {
        int x,y,z;
        scanf(" %d %d %d", &x, &y, &z);

        --y;

        if(x==1 || x==2)
        {
            st[x-1].update(y,z);
            u.insert(y);
        }
        else if(x==3 || x==4)
        {
            printf("%d\n", st[x-3].query(y,z));
        }
        else
        {
            int focus = !(x-5);
            // printf(" x= %d focus %d\n", x,focus);
            for(int idx:u)
            {
                // st[x-5].update(idx, st[focus].query(idx,idx+1));
                st[x-5].update(idx, st[focus].get(idx));
            }
            u.clear();
        }

        // printf(" --- Q %d \n", Q);
        // printf(" A:");
        // rep(i,n) printf(" %d", st[0].get(i));
        // printf("\n");
        // printf(" B:");
        // rep(i,n) printf(" %d", st[1].get(i));
        // printf("\n");
    }

    return 0;
}
