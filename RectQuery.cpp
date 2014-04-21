#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef pair<int, int> pi;

bool operator<(pi a, pi b){
    if(a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    int n, q, k;
    set<pi> A[11];
    cin>>n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin>>k;
            A[k].insert(make_pair(i, j));
        }
    cin>>q;
    int x1, y1, x2, y2;
    pi l, r;
    set<pi>::iterator a, b;

    for(int i = 1; i <= 6; i++){
        for(a = A[i].begin(); a != A[i].end(); a++) cout<<"("<<a->first<<","<<a->second<<")"<<" ";
        cout<<endl;
    }

    while(q--){
        cin>>x1>>y1>>x2>>y2;
        k = 0;
        l = make_pair(x1, y1);
        r = make_pair(x2, y2);
        cout<<"("<<l.first<<","<<l.second<<")"<<" "<<"("<<r.first<<","<<r.second<<")"<<endl;
        for(int i = 1; i <= 10; i++){
            for(a = A[i].begin(); a != A[i].end() && l < *a; a++);
            for(b = a; b != A[i].end() && *b <= r; b++);
            if(a != b){
                k++;
                cout<<i<<": "<<a->first<<" "<<a->second<<" "<<b->first<<" "<<b->second<<endl;
            }
        }
        cout<<k<<endl;
    }
}
