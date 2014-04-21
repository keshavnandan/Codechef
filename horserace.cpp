#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){

    int t, n;
    int S[5000];
    int i = 0, min;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i = 0; i < n; i++)
            scanf("%d",S+i);
        sort(S, S+n);
        min = 1000000000;
//        for(i = 0; i < n; i++)
//            printf("%d\n",S[i]);
        i = 1;
        while(i < n){
            if((S[i] - S[i-1]) < min)
                min = (S[i] - S[i-1]);
            i++;
//            printf("%d\n",min);
        }
        printf("%d\n",min);
    }
}
