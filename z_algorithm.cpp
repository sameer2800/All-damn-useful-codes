#include <bits/stdc++.h>
#define ll long long

using namespace std;
 
ll z[100010];

void compute_z(string s){
   

   ll  sum=0;

   int n = s.length();
   
   long long L = 0, R = 0;
   for (ll i = 1; i < n; i++) {
      if (i > R) {
         L = R = i;
         while (R < n && s[R-L] == s[R]) R++;
         z[i] = R-L; R--;
      } 
      else {
 
         int k = i-L;
         if (z[k] < R-i+1) z[i] = z[k];
         else {
            L = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
         }
      }
      sum+=z[i];
   }

   
}
 
int main() {
  int t; 
  string s; 
  long long sum;
  
  cin>>t;
  
  while(t--){
     
     cin >> s; 

     compute_z(s) ;
  }


  return 0;
}
