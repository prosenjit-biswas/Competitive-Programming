//CR7_G.O.A.T
#include<bits/stdc++.h>
using namespace std;

long long range(long long n){
  
  return (n*(n+1))/2;

}

void kamehameha(){

    long long n,k; cin>>n>>k;
    vector<int>arr(n);
    
    long long sum=0;

    for(int i=0;i<n;i++){cin>>arr[i];}

    vector<long long>lis;
    lis.push_back(arr[0]);
    
    sum+=arr[0];
    long long len=lis.size();

    if(lis.back()>=len)cout<<sum+(k*len)<<" ";
    else cout<<sum+(range(k+len-1)-range(len-1))<<" ";

    for(int i=1;i<n;i++){
       
       sum+=arr[i];
       if(lis.back()<arr[i])lis.push_back(arr[i]);
       else {
           
           auto it=lower_bound(lis.begin(),lis.end(),arr[i]);
           *it=arr[i];
       }

       len=lis.size();
 
       if(lis.back()>=len)cout<<sum+(k*len)<<" ";
       else cout<<sum+(range(k+len-1)-range(len-1))<<" ";
    }

    cout<<'\n';

}

int main(){

     ios_base::sync_with_stdio(false);
     cin.tie(NULL);  
     cout.tie(NULL);


     int t=1;
     cin>>t;
     for(int i=0;i<t;i++){

       // cout<<"Case "<<i+1<<": ";

        kamehameha();

     }


}


///Problem_Link- https://codeforces.com/gym/106619/problem/L
///Requirment - LIS(Longest Increasing Subsequence) in O( N*log(N) ).