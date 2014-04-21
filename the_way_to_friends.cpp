#include<iostream>
#include<cstdio>
#include<vector>
#include<iterator>
#include<algorithm>
#include<cmath>	
using namespace std;
struct point{
	double x;
	double y;
}; 
int n;
bool comp(const point &p1,const point &p2){
	return p1.x < p2.x || (p1.x == p2.x && p1.y > p2.y) ;
}

int main(){
	
	int i,j,test_cases;
	scanf("%d",&test_cases);
	for(i = 0;i < test_cases;i++){
		int n,t;
		scanf("%d",&n);
		vector<point> v(n);
		for(j = 0;j < n;j++)
		scanf("%lf%lf",&v[j].x,&v[j].y);
		sort(v.begin(),v.end(),comp);
		double d = 0.0;
		for(j = 0;j < n-1;j++)
		   d += sqrt((v[j+1].x -v[j].x)*(v[j+1].x -v[j].x) + (v[j+1].y -v[j].y)*(v[j+1].y -v[j].y));
		printf("%.2lf\n",d);		   	
	}
	
}
