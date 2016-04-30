#include <cstdio>
#include <iostream>
using namespace std;

const long N=100001;

typedef struct{
	long parent;
	long left; //1番めの子
	long right_sib; //すぐ右の兄弟(これにより一般的な根付き木を実現)
}Node;

long n, d[N];
Node t[N];

void print(long a){
	printf("node %ld: parent = %ld, depth = %ld, ", a, t[a].parent, d[a]);
	
	if(t[a].parent==-1) printf("root, ");
	else if(t[a].left==-1) printf("leaf, ");
	else printf("internal node, ");
	
	long c=t[a].left;
	printf("[");
	if(c!=-1){
		while(true){
			if(t[c].right_sib==-1){
				printf("%ld", c);
				break;	
			}
			printf("%ld, ", c);	
			c=t[c].right_sib;
		}
	}
	printf("]\n");
}

void setDepth(long u, long a){
	d[u]=a;
	if(t[u].right_sib != -1) setDepth(t[u].right_sib, a);
	if(t[u].left != -1) setDepth(t[u].left, a+1);
}

int main(){
	scanf(" %ld", &n);
	
	for(long i=0; i<n; ++i) 
	t[i].parent=t[i].left=t[i].right_sib=-1;
	
	for(long i=0; i<n; ++i){
		long x, k;
		scanf(" %ld %ld", &x, &k);
		
		long now;
		for(long j=0; j<k; ++j){
			long y;
			scanf(" %ld", &y);
			
			if(j==0) t[x].left=y;
			else t[now].right_sib=y;	
			
			t[y].parent=x;
			now=y;
		}	
		
	}
	
	long root;
	for(long i=0; i<n; ++i){
		if(t[i].parent==-1) root=i;
	}
	
	setDepth(root, 0);
	
	for(long i=0; i<n; ++i) print(i);
}