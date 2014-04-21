#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main(){
	
		int n, w;
        scanf("%d%d",&n, &w);
        int *A = new int[n];
        
        for(int i = 0; i < n; i++)
            scanf("%d", A+i);
        int count = 0;
        set<int> S(A, A+w);
            int min = *(S.begin());
            int max = *(S.rbegin());

        for(int i = 0; i <= (n-w); i++){
            int t = A[i+w-1];
            S.insert(t);
            if(t > max) max = t;
            else if (t < min) min = t;
            if(max - min == w - 1)
            count++;
            t = A[i];
            S.erase(t);
            if(t == min) min = *(S.begin());
            else if (t == max) max = *(S.rbegin());
        }
        delete A;
        printf("%d\n",count);
}
