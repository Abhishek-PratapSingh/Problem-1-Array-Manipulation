#include<bits/stdc++.h>
using namespace std;

//brute force O(n^3)
int getMaxSum1(int n, vector<int>&arr){
    
     if(n==0) return 0;
     
     int maxSum = INT_MIN;
     for(int start=0; start<n; start++){
         for(int end=start; end<n; end++){
             int currSum = 0;
             for(int ptr=start; ptr<=end; ptr++){
                 currSum += arr[ptr];
             }
             maxSum = max(maxSum, currSum);
         }
     }
    
    return maxSum;
}

//brute force O(n^2)
int getMaxSum2(int n, vector<int>&arr){
    
     if(n==0) return 0;
    
     int maxSum = INT_MIN;
     for(int start=0; start<n; start++){
         int currSum = 0; 
         for(int end=start; end<n; end++){
            currSum += arr[end];
            maxSum = max(maxSum, currSum); 
         }
     }
    return maxSum;
}

//optimised O(nlogn)

int maxWholeSubarraySum(int low, int mid, int high, vector<int>&arr){
     
    int sum = 0;
    int first = INT_MIN;
    for(int i=low; i<=mid; i++){
        sum+= arr[i];
        first=max(first, sum);
    }
    
    sum=0;
    int second = INT_MIN;
    for(int i=mid; i<=high; i++){
        sum+= arr[i];
        second=max(second, sum);
    }
    
    return max(first + second -arr[mid], max(first, second));
}

int maxSumWithDivideConquer(int low, int high, vector<int>&arr){
    
    if(low>high) return INT_MIN;
    if(low == high) return arr[high];
    
    int mid = (low + (high-low)/2);
    
    int temp1 = maxSumWithDivideConquer(low, mid-1, arr);
    int temp2 = maxSumWithDivideConquer(mid+1, high, arr);
    int temp3 = maxWholeSubarraySum(low, mid, high, arr);
    
    return max(temp1, max(temp2, temp3));
}

int getMaxSum3(int n, vector<int>&arr){
    
     if(n==0) return 0;
    
     return maxSumWithDivideConquer(0, n-1, arr);
}

//optimised O(n)
int getMaxSum4(int n, vector<int>&arr){
    
     if(n==0) return 0;
    
     int maxSum = INT_MIN;
     int currSum = 0;
     for(int ptr=0; ptr<n; ptr++){
         currSum += arr[ptr];
         if(currSum < arr[ptr]){  // since the current sum is less than the current value
             currSum = arr[ptr];
         }
         maxSum = max(maxSum, currSum);
     }
    
    return maxSum;
}

int main() {

    int n;
    cin>> n;  
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans1 = getMaxSum1(n, arr);
    int ans2 = getMaxSum2(n, arr);
    int ans3 = getMaxSum3(n, arr);
    int ans4 = getMaxSum4(n, arr);
    
    cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<endl;
}
