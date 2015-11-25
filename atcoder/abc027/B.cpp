#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, a[100];
	int sum=0;
	
	//input
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		scanf(" %d", &a[i]);
		sum+=a[i];
	}
	
	int ans=0;
	if(sum==0) ans=0;
	else if(sum%n!=0) ans=-1;
	else{
		int t=sum/n; //1つの島にいるべき人数
		int num=0, p=0;
		
		for(int i=0; i<n; ++i){
			p+=a[i]; //人数を増やす
			num++; //つなぐべき島の数
			
			//printf("%d:: p=%d, num=%d\n", i, p, num);
			
			if(t*num==p){ //ここに橋は不要
				p=0;
				num=0;
				//printf("cut\n");
			}
			else ans++;
				
		}
	
	}
	
	printf("%d\n",ans);	
}