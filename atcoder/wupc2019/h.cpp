#include <bits/stdc++.h>
using namespace std;

const long mod = 1e9+7;

int main(){
    int n;
    scanf(" %d", &n);

    vector<int> k(n);
    vector<vector<long>> a(n);
    for(int i=0; i<n; ++i){
        scanf(" %d", &k[i]);
        a[i] = vector<long>(k[i]);
        for(int j=0; j<k[i]; ++j) scanf(" %ld", &a[i][j]);
    }

    // 前計算
    // k[i] のdistinctな要素を列挙
    vector<int> uk(k);
    sort(uk.begin(), uk.end());
    uk.erase(unique(uk.begin(), uk.end()), uk.end());
    int UK = uk.size();

    // 各数列 a[i] について、自分以下の周期の和を前計算
    vector<vector<vector<long>>> sum(n, vector<vector<long>>(UK));
    for(int i=0; i<n; ++i){
        for(int j=0; j<UK; ++j){
            int L = uk[j];
            if(L > k[i]) break;

            sum[i][j] = vector<long>(L);
            for(int l=0; l<k[i]; ++l){
                sum[i][j][l%L] += a[i][l];
                sum[i][j][l%L] %= mod;
            }
        }
    }

    // クエリ処理
    int Q;
    scanf(" %d", &Q);

    map<pair<int,int>, long> memo;
    while(Q--){
        int x,y;
        scanf(" %d %d", &x, &y);

        pair<int,int> p(min(x,y), max(x,y));
        long ans = 0;
        if(memo.count(p)) ans = memo[p];
        else{
            if(k[x] > k[y]) swap(x,y);
            int uk_idx = lower_bound(uk.begin(), uk.end(), k[x]) - uk.begin();
            for(int i=0; i<k[x]; ++i){
                ans += a[x][i] * sum[y][uk_idx][i];
                ans %= mod;
            }
            memo[p] = ans;
        }
        printf("%ld\n", ans);
    }
    return 0;
}
