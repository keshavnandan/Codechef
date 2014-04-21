#include <cstdio>
#include <set>
#include <utility>
using namespace std;
unsigned long long int A[10000001];
typedef pair<long long, long long> node; 
set<node> S;
unsigned long long int mypow(unsigned long long int x, unsigned long long int y){
 
	if(y == 0)
	return 1;
	if(y == 1)
	return x;
	unsigned long long int t = mypow(x, y/2);
	t %= 1000000007;
	if(y%2) return (x*t*t)%1000000007;
	return (t*t)%1000000007;
}	

int main(){

	unsigned long long int t1, t2, t3, t4;
	int test_cases, n;
	unsigned long long int d = 4;
	A[3] = 1; A[4] = 3;
	scanf("%d", &test_cases);
	while(test_cases--){
		scanf("%d", &n);
		if(n <= d)
     		printf("%lld\n", A[n]);
		else {
			while(d < 10000000 && d < n){
				d++;
				A[d] = (2*A[d-1]%1000000007 + mypow(2, d-4) - A[d-4]%1000000007)%1000000007;
				if(A[d] < 0)
				printf("--%lld %lld--\n",d, A[d]);
			}
			if(d < n){
				if(!S.empty()){
					node q(n, 1);
					set<node>::iterator it = S.lower_bound(q);
					if(it != S.begin()){
						node p = *(--it);
						int k = p.first;
							
					}	
					else if(it->first == n)
						printf("%lld\n", it->second);
					else{
							t1 = A[d];
							t2 = A[d-1];
							t3 = A[d-2];
							t4 = A[d-4];
							unsigned long long int x = d, t;
							while(x++ < n){
								t = (2*t1%1000000007 + mypow(2, x-4) - t4%1000000007)%1000000007;
								t2 = t1; t3 = t2; t4 = t3; t1 = t;
							}
							S.insert(make_pair(n, t));
							printf("%lld\n", t);
					}			
				}
			else{
					t1 = A[d];
					t2 = A[d-1];
					t3 = A[d-2];
					t4 = A[d-4];
					unsigned long long int x = d, t;
					while(x++ < n){
						t = (t1%1000000007 + mypow(2, x-4) - t4%1000000007)%1000000007;
						t2 = t1; t3 = t2; t4 = t3; t1 = t;
					}
					S.insert(make_pair(n, t));
					printf("%lld\n", t);
				}
			else 
				printf("%lld\n", A[n]);
		}			
	}
}	
