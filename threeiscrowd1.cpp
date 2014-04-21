#include <cstdio>
#include <set>
#include <utility>
using namespace std;

unsigned long long A[10000001];

struct info{
	info(const unsigned long long b[3]){
		a[0] = b[0]; a[1] = b[1]; a[2] = b[2];
	}
	info(const info &r){
		a[0] = r.a[0]; a[1] = r.a[1]; a[2] = r.a[2];
	}				
	unsigned long long a[3];
};

bool operator< (const info &l, const info &r){
	return l.a[0] < r.a[0];
}	

typedef pair<unsigned long long, info> node;
set<node> S;

unsigned long long mypow(unsigned long long x, unsigned long long y){
 
	if(y == 0)
	return 1;
	if(y == 1)
	return x;
	unsigned long long t = mypow(x, y/2);
	t %= 1000000007;
	if(y%2) return (x*t*t)%1000000007;
	return (t*t)%1000000007;
}	

int main(){

	unsigned long long t1, t2, t3, t0;
	unsigned long long n;
	int test_cases ;
	A[3] = 1; A[4] = 3;
	
	for(int i = 5; i <= 1000000; i++){
		A[i] = (A[i-1] + A[i-2] + A[i-3] + mypow(2, i-3))%1000000007;	
	}
	
	unsigned long long temp[3];
	temp[1] = A[1000000];
	temp[2] = A[1000000 - 1];
	temp[0] = (temp[1] + temp[2] + A[1000000 - 2] + mypow(2, 1000000 - 2))%1000000007;
	S.insert(make_pair((unsigned long long)1000000+1, info(temp)));			

	scanf("%d", &test_cases);
	while(test_cases--){
		scanf("%lld", &n);
		if(n <= 1000000)
     		printf("%lld\n", A[n]);
		else {
			unsigned long long t[3];
			t[0] = 100000007;
			node p = make_pair(n, info(t));
			node &u = p;
			node &v = u;
			set<node>::iterator it = S.upper_bound(p);
			v = *(--it);
			it++;
			if(it == S.end() || (it->first-3 - u.first) > (u.first - v.first)){
				t1	= v.second.a[0]; t2 = v.second.a[1]; t3 = v.second.a[2];
				long long k = v.first;
				while(++k <= n){
					t0 = (t1 + t2 + t3 + mypow(2, k-3))%1000000007;
					t2 = t1;
					t3 = t2;
					t1 = t0;			
				}
				t[0] = t1;
				t[1] = t2;
				t[2] = t3;
				S.insert(make_pair(n, info(t)));	
				printf("%lld\n", t1);	
			}	
			else{
				v = *it;
				long long k = v.first;
				if(k-n < 3)
					printf("%lld\n", v.second.a[k-n]);
				else{
					t1	= v.second.a[0]; t2 = v.second.a[1]; t3 = v.second.a[2];
					k = v.first - 2;
					while(--k >= n-2){
						t0 = (t1 - t2 - t3 + mypow(2, k))%1000000007;
						t1 = t2;
						t2 = t3;
						t3 = t0;
					}
					t[0] = t1;
					t[1] = t2;
					t[2] = t3;
					S.insert(make_pair(n, info(t)));	
					printf("%lld\n", t1);	
				}	
			}
		}
	}	
}	
