#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;
 
int main(){
	int n, a;
	unsigned long long k;
	int b[100001];
	
	//input	
	cin >> n >> a;
	cin >> k; //kの入力方法?
	for(int i=1; i<=n; ++i) scanf(" %d", &b[i]);
	
	//solve
	bool visit[100001];
	fill(visit, visit+n+1, false);
	//for(int i=0; i<=n+1; ++i) cout << visit[i] << endl;
	int place[100000]={0};
	
	unsigned long long step=0;
	int pt=a;
	
	visit[a]=true;
	place[0]=a;
	//find loop
	while(1){
		//printf("now here: %d\n", pt);
		if(step+1==k) break;
	
		pt=b[pt];
		place[++step]=pt;
		if(visit[pt]) break;
		visit[pt]=true;	
	}
	
	//printf("step=%d, pt=%d\n",step, pt);
	
	if(step+1==k) printf("%d\n", b[pt]);
	else{ //loop found
		//for(int i=0; i<=step; ++i) printf("place[%d]=%d\n", i, place[i]);
	
		int start=0;
		while(place[start]!=pt) start++;
		/*
		printf("find : start = %d\n", start);
		printf("->loop_size=%d\n", step-start);
		*/
		k-=start;
		//cout << "k= " << k <<endl;
		int r=k%(step-start);
		if(r==0) r=step-start;
		//printf("r=%d\n",r);
		
		printf("%d\n", place[r+start]);
	}
}