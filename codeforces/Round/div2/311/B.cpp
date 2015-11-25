#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const double eps=1e-8;
long a[200000];

void merge(long low,long mid,long high){
 long h,i,j,b[200000],k;
 h=low;
 i=low;
 j=mid+1;

 while((h<=mid)&&(j<=high)){
  if(a[h]<=a[j]){
   b[i]=a[h];
   h++;
  }
  else{
   b[i]=a[j];
   j++;
  }
  i++;
 }
 
 if(h>mid){
  for(k=j;k<=high;k++){
   b[i]=a[k];
   i++;
  }
 }
 else{
  for(k=h;k<=mid;k++){
   b[i]=a[k];
   i++;
  }
 }
 for(k=low;k<=high;k++) a[k]=b[k];
}

void merge_sort(long low,long high){
 long mid;
 if(low<high){
  mid = low + (high-low)/2; //This avoids overflow when low, high are too large
  merge_sort(low,mid);
  merge_sort(mid+1,high);
  merge(low,mid,high);
 }
}


int main(){
	long n, w;
	
	scanf(" %ld %ld", &n, &w);
	for(long i=0; i<2*n; ++i) scanf(" %ld", &a[i]);
	
	merge_sort(0,2*n-1);
	//for(long i=0; i<2*n; ++i) printf(" %ld\n", a[i]);
	
	double girlmin=(double)a[0];
	double boymin=(double)a[n];
	//printf("g=%lf\nb=%lf\n", girlmin, boymin);
	
	if(girlmin*2.0 <= boymin) boymin=girlmin*2; //girlを基準
	else girlmin=boymin/2.0; //girlを基準
	
	double sum=girlmin*n*3.0;
	double ans=0;
	
	//多すぎ
	if(sum-(double)w>eps) ans=w;
	else ans=sum;
	
	printf("%.8lf\n", ans);
}