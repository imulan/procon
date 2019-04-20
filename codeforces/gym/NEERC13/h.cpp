#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
int INF=(ll)(1LL<<31)-1LL;

struct segtree{
    static const int N=1<<17;
    int dp[1<<18];

    void update(int k,int v){
        k+=N-1;
        dp[k]+=v;
        while(k>0){
            k=(k-1)/2;
            dp[k]=dp[k*2+1]&dp[k*2+2];
        }
    }
    int query(int a,int b,int k=0,int l=0,int r=N){
        if(b<=l || r<=a)return INF;
        if(a<=l && r<=b)return dp[k];
        int mid=(l+r)/2;
        int vl=query(a,b,k*2+1,l,mid);
        int vr=query(a,b,k*2+2,mid,r);
        return vl&vr;
    }
};

int n;
int a[100005];
int sum[100005];
vector<int> nobit[32];
segtree seg;
map<int,int> id;
vector<int> xors[100001];

ll calc(int val,int f,int t){
    //printf("%d %d %d\n",val,f,t);
    if(id.find(val)==id.end())return 0LL;
    int v=id[val];
    int l1=lower_bound(xors[v].begin(),xors[v].end(),f)-xors[v].begin();
    int r1=lower_bound(xors[v].begin(),xors[v].end(),t)-xors[v].begin();
    //printf("%d %d %d %d\n",val,f,t,r1-l1);
    return r1-l1;
}

void solve(istream &fin, ostream &fout){
    fin >> n;
    for(int i=0;i<n;i++){
        fin >> a[i];
        sum[i+1]+=sum[i];
        sum[i+1]^=a[i];
        seg.update(i,a[i]);
        for(int j=0;j<32;j++){
            if(!((a[i]>>j) &1)){
                nobit[j].push_back(i);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(id.find(sum[i])==id.end()){
            int tmp=id.size();
            id[sum[i]]=tmp;
        }
        xors[id[sum[i]]].push_back(i-1);
    }
    for(int i=0;i<32;i++){
        nobit[i].push_back(n);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        int ord[32];
        for(int j=0;j<32;j++){
            ord[j]=lower_bound(nobit[j].begin(),nobit[j].end(),i)-nobit[j].begin();
            ord[j]=nobit[j][ord[j]];
        }
        sort(ord,ord+32);
        int prvs=i;
        for(int j=0;j<32;j++){
            if(prvs!=ord[j]){
                ans+=calc(seg.query(i,ord[j])^sum[i],prvs,ord[j]);
            }
            prvs=ord[j];
        }
        if(prvs!=n){
            ans+=calc(seg.query(i,n)^sum[i],prvs,n);
        }
    }
    fout << ans << endl;
}

int main(){
#ifdef ONLINE_JUDGE
    ifstream ifs("hack.in");
    ofstream ofs("hack.out");
    solve(ifs, ofs);
    ifs.close();
    ofs.close();
#else
    solve(cin, cout);
#endif
    return 0;
}