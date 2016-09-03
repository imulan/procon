#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool eq(string s, int a){
	char tmp[10];
	int p=a;
	int size=0;
	
	while(p!=0){
		p/=10;
		size++;	
	}	
	p=a;
	tmp[size]='\0';
	while(p!=0){
		tmp[size-1]=(p%10)+'0';
		size--;
		p/=10;	
	}
	
	string z;
	z=tmp;
	int ret=z.compare(s);

	return (ret==0);
}

int main(){
	int n, a;
	string k;	
	int b[100001];
	
	//input	
	cin >> n >> a;
	cin >> k;
	for(int i=1; i<=n; ++i) scanf(" %d", &b[i]);

	//solve
	bool visit[100001];
	fill(visit, visit+n+1, false);
	//for(int i=0; i<=n+1; ++i) cout << visit[i] << endl;
	int place[100000]={0};
	
	int step=0;
	int pt=a;
	
	visit[a]=true;
	place[0]=a;
	//find loop
	while(1){
		//printf("now here: %d\n", pt);
		if(eq(k,step+1)) break;
	
		pt=b[pt];
		place[++step]=pt;
		if(visit[pt]) break;
		visit[pt]=true;	
	}
	
	//printf("step=%d, pt=%d\n",step, pt);
	
	if(eq(k,step+1)) printf("%d\n", b[pt]);
	else{ //loop found
		//for(int i=0; i<=step; ++i) printf("place[%d]=%d\n", i, place[i]);
	
		int start=0;
		while(place[start]!=pt) start++;
		
		//printf("find : start = %d\n", start);
	  //printf("->loop_size=%d\n", step-start);
		int C=step-start;
		int k_mod_C=0;
		for(int i=0; i<k.size(); ++i){
			k_mod_C = (k_mod_C*10+k[i]-'0')%C;	
		}
		
		int ad=0;
		while(ad<n) ad+=C;
		k_mod_C = (k_mod_C+ad-start)%C;
		
		//printf("k_mod_C = %d\n", k_mod_C);
		
		printf("%d\n", place[start+k_mod_C]);
	}
	
}