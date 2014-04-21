#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;

int main(){
	
	int i,j,k,l,s,t;
	cin>>n;
	while(n){
	int a[n];
	t = 0;
	for(l = 0;l < n;l++)
	scanf("%d",a+l);
	sort(a,a+n);
	for(i = 0;i < n-2;i++){
		for(j = i+1;j < n-1;j++){
		s = a[i] + a[j];
		k = j+1;
			while(k < n && s >= a[k])
				k++;
			t += n-k;
			}
	}
		printf("%d\n",t);
		scanf("%d",&n);
	}
}	
