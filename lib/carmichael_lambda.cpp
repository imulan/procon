// カーマイケルのλ関数
// nと互いに素なaに対して a^{λ(n)} == 1 (mod n) が成り立つ最小の整数を返す
// (オイラーのφ関数の精密化)
int carmichael_lambda(int n){
    int ret = 1;
    if(n%8==0) n /= 2;
    for(int i=2; i<=n; ++i){
        if(n%i!=0) continue;
        int sub = i-1;
        n /= i;
        while(n%i==0){
            n /= i;
            sub *= i;
        }
        ret = lcm(ret, sub);
    }
    return ret;
}

