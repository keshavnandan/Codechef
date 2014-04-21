#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	int t;
    string s;
    scanf("%d", &t);

	while(t--){
		long long n;
		char *s;
        scanf("%lld", &n);
        scanf("%[^\n]", s);
		cout<<(n*(n-1))/2<<endl;
	}
}
