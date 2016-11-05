#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct MaxSegTree{
    int n; vector<int> dat;
    //初期化
    MaxSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<int>(2*n-1,-1);
    }
    //k番目(0-indexed)の値をaに更新
    void update(int k, int a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[2*k+1],dat[2*k+2]);
        }
    }
    //k番目(0-indexed)の値にaを加える
    void add(int k, int a){
        k+=n-1;
        dat[k]+=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[2*k+1],dat[2*k+2]);
        }
    }
    int get(int k){
        return dat[k+n-1];
    }
    //内部的に投げられるクエリ
    int _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return -1;

        if(a<=l && r<=b) return dat[k];
        else{
            int vl=_query(a,b,2*k+1,l,(l+r)/2);
            int vr=_query(a,b,2*k+2,(l+r)/2,r);
            return max(vl,vr);
        }
    }
    //[a,b)の最大値を求める
    int query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main()
{
    int n,d;
    while(cin >>n >>d,n)
    {
        MaxSegTree st(n);
        vector<int> m(n);
        vector<vector<int>> c(n);
        rep(i,n)
        {
            scanf(" %d", &m[i]);
            c[i]=vector<int>(m[i]);

            int sum=0;
            rep(j,m[i])
            {
                scanf(" %d", &c[i][j]);
                sum+=c[i][j];
            }
            st.update(i,sum);
        }

        int total=0;
        rep(i,n) total+=m[i];

        bool valid=true;
        rep(T,total)
        {
            bool update=false;
            rep(i,n)
            {
                if(m[i]==0) continue;

                int others_max=max(st.query(0,i),st.query(i+1,n));
                int focus=st.get(i);

                if(others_max-(focus-c[i][m[i]-1])<=d)
                {
                    st.add(i,-c[i][m[i]-1]);
                    --m[i];
                    update=true;
                    break;
                }
            }

            if(!update)
            {
                valid=false;
                break;
            }
        }

        string ans="No";
        if(valid) ans="Yes";
        cout << ans << endl;
    }
    return 0;
}
