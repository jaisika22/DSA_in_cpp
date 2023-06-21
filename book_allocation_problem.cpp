/* You are given an array ‘pages’ of integer numbers. In this array, the ‘pages[i]’ represents the number of pages in the ‘i-th’ book. There are ‘m’ number of students, and the task is to allocate all the books to the students. 

Allocate books in a way such that:

Each student gets at least one book.
Each book should be allocated to a student.
Book allocation should be in a contiguous manner.
 
You have to allocate the books to ‘m’ students such that the maximum number of pages assigned to a student is minimum.      */

#include <bits/stdc++.h> 
bool ispossible(int n, int m, vector<int> pages, int mid){
	int bookcount=1;
	int pagecount =0;
	for(int i=0;i<m;i++){
		if(pagecount+pages[i]<=mid){
		  pagecount+=pages[i];
		}
		else{
			bookcount++;
			if(bookcount>n || pages[i]> mid){
				return false;
			}
			pagecount=pages[i];
		}
	} return true;

}

long long bookallocation(int n, int m, vector<int> pages) 
{	
	int s=0;
	int sum=0;
	for(int i=0;i<m;i++){
		sum+=pages[i];
	}
	int e=sum;
	int mid;
	int ans=-1;

	while(s<=e){
		mid = s + (e-s)/2;
		if(ispossible(n,m,pages,mid)){
			ans=mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return ans;
}
