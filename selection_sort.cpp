#include<bits/stdc++.h>
using namespace std;

//recursivly
 void selectionsort(vector<int>& nums, int n, int i){

        if(i==n-1){
            return;
        }
        int minindex=i;
        for(int j=i+1; j<n; j++){
            
            if(nums[minindex]>nums[j]){
                minindex=j;
            }
        }
        swap(nums[minindex],nums[i]);
        
         selectionsort(nums,n,i+1);
    }
void printarr(vector<int> & nums){
    for(int i=0; i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

// ilteratively
void selectionsort(vector<int> &nums, int n) 
{
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1; j<n; j++){
            if(nums[j]<nums[min]){
                min=j;
            }
        }
        swap(nums[min],nums[i]);
    }

}

int main()
{
    vector<int> nums{10,2,306,74,45,60};
    printarr(nums);
    selectionsort(nums,nums.size(),0);
    printarr(nums);
    
    return 0;
}

