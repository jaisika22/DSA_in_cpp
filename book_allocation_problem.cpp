#include <bits/stdc++.h> 
bool ispossible(int n, int m, vector<int> time, int mid){
	int daycount=1;
	int timecount =0;
	for(int i=0;i<m;i++){
		if(timecount+time[i]<=mid){
			timecount+=time[i];
		}
		else{
			daycount++;
			if(daycount>n || time[i]> mid){
				return false;
			}
			timecount=time[i];
		}
	} return true;

}

long long bookallocation(int n, int m, vector<int> time) 
{	
	int s=0;
	int sum=0;
	for(int i=0;i<m;i++){
		sum+=time[i];
	}
	int e=sum;
	int mid;
	int ans=-1;

	while(s<=e){
		mid = s + (e-s)/2;
		if(ispossible(n,m,time,mid)){
			ans=mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return ans;
}
