#include <cstdio>
#include <cmath>
using namespace std;

unsigned long long int mypow(unsigned long long int y){

		unsigned long long int x = 1;
 		if(y < ((sizeof(unsigned long long int)*8)))
 		return (x<<y)%1000000007;
 		unsigned long long int t = mypow(y/2);
 		t %= 1000000007;
 		if(y%2)
 		return (t*t*2)%1000000007;
 		return (t*t)%1000000007;
}	


int main(){
	
	int t;
	unsigned long long n;
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		printf("%lld\n",((3+n%2)*mypow(n/2)%1000000007) - 2) ;
	}
	return 0;	
}
