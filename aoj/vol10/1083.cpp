#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back

struct SegTree{
    int n;
    vector<int> dat;
    //初期化
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<int>(2*n-1,0);
    }

    //k番目(0-indexed)の値をaに変更
    void update(int k, int a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]= dat[2*k+1]+dat[2*k+2];
        }
    }

    int find(int x){
        int now = 0;
        while(now<n-1){
            if(dat[2*now+1] < x){
                x -= dat[2*now+1];
                now = 2*now + 2;
            }
            else{
                now = 2*now + 1;
            }
        }
        return now - (n-1);
    }
};

int main(){
    int q,lim;
    while(scanf(" %d %d", &q, &lim),q){
        SegTree st(q);
        int idx = 0, num = 0;
        unordered_map<int,int> id2idx;
        vector<int> a;

        auto DEL = [&](int p){
            st.update(p,0);
            --num;
        };

        rep(i,q){
            int t,x;
            scanf(" %d %d", &t, &x);

            if(t==0){
                id2idx[x] = idx;
                st.update(idx,1);
                a.pb(x);
                ++idx;
                ++num;

                if(num == lim+1) DEL(st.find(1));
            }
            else if(t==1) DEL(st.find(x));
            else if(t==2) printf("%d\n",a[st.find(x)]);
            else DEL(id2idx[x]);
        }
        printf("end\n");
    }
    return 0;
}
