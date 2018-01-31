// nの約数におけるメビウス関数の値 O(sqrt(n))
map<int,int> moebius(int n){
    vector<int> primes;
    // nの素因数を列挙
    for(int i=2; i*i<=n; ++i){
        if(n%i==0) primes.push_back(i);
        while(n%i==0) n/=i;
    }
    if(n>1) primes.push_back(n);

    map<int,int> ret;
    int SZ = primes.size();
    // 2^SZ通りを試す(nの約数の個数よりは少ない)
    rep(i,1<<SZ){
        int mu = 1, d = 1;
        rep(j,SZ){
            if(i>>j&1){
                mu *= -1;
                d *= primes[j];
            }
        }
        ret[d] = mu;
    }
    return ret;
}
