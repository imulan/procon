#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const long X=10000000000; //10^10 とりえない数

int main(){
	while(1){
		int n;
		scanf(" %d", &n);
		if(n==0) break;
		
		long sig[1000]={0}; //signals
		
		for(int i=0; i<n; ++i){
			string s;
			cin >> s;
			if(s=="x") sig[i]=X;
			else{
				istringstream iss(s);
				iss >> sig[i];	
			}
		}
		
		//for(int i=0; i<n; ++i) printf("sig[%d]= %d\n", i, sig[i]);
		
		//smallより大きく，bigより小さくなければならない
		long big=2000000000, small=-2000000000;
		bool noans=false;
		
		for(int i=0; i<n-1; ++i){
			if(sig[i]==X && sig[i+1]==X) noans=true;	
		}
		
		if(noans) printf("none\n");
		else{
			for(int i=0; i<n; ++i){	
				if(sig[i]==X){
					if(i%2==0){ //奇数番目の位置, bigを更新
						long tmp=2000000000;
						
						if(i-1>=0) tmp=min(tmp, sig[i-1]);
						if(i+1<n) tmp=min(tmp, sig[i+1]);
						
						big=min(big,tmp);
					}
					else{ //偶数番目の位置，smallを更新
						long tmp=-2000000000;
						
						if(i-1>=0) tmp=max(tmp, sig[i-1]);
						if(i+1<n) tmp=max(tmp, sig[i+1]);
						
						small=max(small,tmp);
					}	
				}
				else{
					if(i%2==0){ //奇数番目の位置, 確認
						if(i-1>=0 && sig[i-1]!=X && sig[i-1]<sig[i]) noans=true;	
						if(i+1<n && sig[i+1]!=X && sig[i+1]<sig[i]) noans=true;
					}
					else{ //偶数番目の位置，確認
						if(i-1>=0 && sig[i-1]!=X && sig[i-1]>sig[i]) noans=true;	
						if(i+1<n && sig[i+1]!=X && sig[i+1]>sig[i]) noans=true;
					}						
				}
				
				if(noans) break;
			}
			
			//printf("big=%d, small=%d\n", big, small);
			
			if(noans || big-small<=1) printf("none\n");
			else if(big-small==2) printf("%d\n", big-1);
			else printf("ambiguous\n");
		}		
	}
}