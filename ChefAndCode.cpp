#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;
struct node{
    int key;
    int val;
};
bool key_sort(const node &a, const node &b){ return a.key < b.key; }
bool val_sort(const node &a, const node &b){ return a.val < b.val; }

int main(){
        int tc;
        string line;
        getline(cin, line);
        stringstream ss(line);
        ss>>tc;
        string s, t;
        while(tc--){
            getline(cin, s);
            getline(cin, t);
//            cout<<t<<endl;
            int freq[26];
            node cfreq[26];
            for(int i = 0; i < 26; i++){ freq[s[i]-'a'] = i; cfreq[i].key = i; cfreq[i].val = 0; }
            for(int i = 0; i < t.size(); i++){
                if(islower(t[i])) cfreq[t[i]-'a'].val++;
                else if (isupper(t[i])) cfreq[t[i]-'A'].val++;
            }
            sort(cfreq, cfreq+26, val_sort);
/*            for(int i = 0; i < 26; i++) cout<<cfreq[i].val<<" ";
            cout<<endl;
*/
            int i = 0, j = 1;
            while(i < 26){
                while(j < 26 && cfreq[i].val == cfreq[j].val) j++;
                sort(cfreq+i, cfreq+j, key_sort);
                i=j;
            }
/*
            for(int i = 0; i < 26; i++) cout<<i<<" "<<char('a'+cfreq[i].key)<<endl;
                cout<<endl;
*/
            int nfreq[26];
            for(int i = 0; i < 26; i++) nfreq[cfreq[i].key] = i;
//            for(int i = 0; i < 26; i++) cout<<nfreq[i]<<" ";
//            cout<<endl;
            for(int i = 0; i < t.size(); i++){
                if(isupper(t[i])) t[i] = toupper(s[nfreq[t[i]-'A']]);
                else if (islower(t[i])) t[i] = s[nfreq[t[i]-'a']];
            }
            cout<<t<<endl;
        }
}
