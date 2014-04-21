#include<cstdio>
using namespace std;
 
int main(){
int n,k,beg,end;
int p;
scanf("%d%d",&n,&k);
bool *v = new bool[n];
for(int i=0;i<k;i++){
scanf("%d%d%d",&p,&beg,&end);
if(p==0)
for(int j=beg;j<=end;j++)
v[j]^=(v[j]);
else{
int count = 0 ;
for(int j = beg;j<=end;j++)
if(v[j]==true)
count++;
printf("%d",count);
}
}
}
