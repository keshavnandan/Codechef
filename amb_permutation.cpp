#include<cstdio>
using namespace std;

int n;

int main(){
	
	n = 1;
	int i;
	while(n){
	scanf("%d",&n);
	if(n){
	 bool p = true;	
	 int a[n];
	 for(i = 0;i < n;i++)
	 scanf("%d",&a[i]);
	 for(i = 1;i <= n && a[a[i-1]-1] == i;i++);
	 if(i <= n)
         p = false;
	  if(p) printf("ambiguous\n");
	  else printf("not ambiguous\n");	 	 
	  }	
      }

}	
