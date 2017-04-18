#include <iostream>
#include <cstdio>

int n, t[4];
int sum=0;
int ans=1000;

void dfs(int i, int s){
    if(i==n){
        if(s<sum-s){
            if(sum-s < ans) ans=sum-s;
        }
        else{
            if(s < ans) ans=s;
        }
    }
    else{
        dfs(i+1, s);
        dfs(i+1, s+t[i]);
    }
}

int main(){
    
    scanf("%d", &n);
    
    for(int i=0; i<n; ++i){
        scanf(" %d", &t[i]);
        sum += t[i];
    }
    
    if(n==1) printf("%d\n", t[0]);
    else{
        dfs(0,0);
        printf("%d\n", ans);
    }

    return 0;
}
