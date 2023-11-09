#include <bits/stdc++.h>
using namespace std;

void subSequence(int arr[] , vector<int>&v , int n , int index){
    if(index >= n){
        for(auto it:v){
            cout<<it;
        }
        cout<<endl;
        return;
    }
    
    
    
    v.push_back(arr[index]);
    
    //when we are including the particula index
    subSequence(arr , v , n , index+1);
    v.pop_back();
    
    //case when we are not including the particular index
    subSequence(arr , v , n , index+1);
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>v;
    
    subSequence(arr , v , n , 0);
}
