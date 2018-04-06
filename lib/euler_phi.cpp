int euler_phi(int n){
    if(n==0) return 0;
    int ret = n;
    for(int i=2; i*i<=n; ++i){
        if(n%i==0){
            ret -= ret/i;
            while(n%i==0) n/=i;
        }
    }
    if(n!=1) ret -= ret/n;
    return ret;
}
