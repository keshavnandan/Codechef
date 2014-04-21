#include<iostream>
#include<cstdio>
#include <cstring>
#include <set>
using namespace std;

int main(){
    int n, t, k;
    int A[1000005];
    scanf("%d%d", &n, &t);
    scanf("%d", &A[0]);
    for(int i = 1; i < n; i++){
        scanf("%d", &k);
        A[i] = A[i-1]+k;
    }
//    for(int i = 1; i < n; i++) A[i] += A[i-1];
    set<int> G, T;
    int GA[50005], TA[50005];
    char s[2];
    int x, y;
    long long sum = 0LL;
    for(int i = 0; i < t; i++){
        scanf("%s%d%d", s, &x, &y);
        if(strcmp(s, "G") == 0){
            G.insert(x);
            GA[x] = y;
        }
        else if(strcmp(s, "T") == 0){
            T.insert(x);
            TA[x] = y;
        }
        else{
            sum = A[y];
            if(x > 0) sum -= A[x-1];
            set<int>::iterator l, r;
            l = G.lower_bound(x); r = G.upper_bound(y);
            while(l != r){
                sum += GA[*l];
                l++;
            }
            l = T.lower_bound(x); r = T.upper_bound(y);
            while(l != r){
                sum -= TA[*l];
                l++;
            }
            cout<<sum<<endl;
        }
    }
}
