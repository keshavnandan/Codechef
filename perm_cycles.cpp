#include<cstdio>
#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>	
using namespace std;
struct node{
	bool visited;
	int pos;
	int next;
};
int n;

int main(){
	
	vector<vector<int> > v;
	scanf("%d",&n);
	node arr[n+1];
	int i,j,cycles = 0;
	for(i = 1;i <= n;i++){
	arr[i].visited = false;
	arr[i].next = i%n + 1;
	scanf("%d",&arr[i].pos);
	}
	
	int next = 1,init = 1,pos = 1;
	bool done = false;
	while(!done){	
		
		pos = next;
		if(arr[pos].pos == pos){
		 cycles++;
		 vector<int> t(2,pos);
		 v.push_back(t);
		 arr[pos].visited = true;
		 if(pos == n) done = true;
		else{	
		 for(i = pos+1;i < n && arr[i].visited;i++);
		    next = i;
		 if(next == n && arr[n].visited) done = true;		
		 }
		}
		else {
			vector<int> t;
			init = pos;
			t.push_back(pos);
			while(arr[pos].pos != init){ 
			arr[pos].visited = true;
			t.push_back(arr[pos].pos);
			pos = arr[pos].pos; 
			}
			arr[pos].visited = true;
			t.push_back(arr[pos].pos);
			cycles++;
			v.push_back(t);
			if(init < n){
			for(i = init+1;i < n && arr[i].visited;i++);
			next = i;
	         	 if(next == n && arr[n].visited) done = true;		
			}
			else done = true;
		}		 
	}
		printf("%d\n",cycles);
		for(i = 0;i < cycles;i++){
		copy(v[i].begin(),v[i].end(),ostream_iterator<int>(cout," "));
		printf("\n");
		}		
}
