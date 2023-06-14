 #include<bits/stdc++.h>

 int largestRectangle(vector < int > & heights) {
   int n=heights.size();
   vector<int> suffix(n);
   vector<int> prefix(n);

   stack<int> st;

   for(int i=0;i<n;i++){
     while(!st.empty() && heights[st.top()]>=heights[i]){
       st.pop();
     }
     if(st.empty()) prefix[i]=-1;
     else prefix[i]=st.top();
     st.push(i);
   }
   
   while(!st.empty()) st.pop();

   for(int i=n-1;i>=0;i--){
     while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
     if(st.empty()) suffix[i]=n;
     else suffix[i]=st.top();
     st.push(i);
   }

   int maxi=0;
   for(int i=0;i<n;i++){
     maxi=max(maxi,(suffix[i]-prefix[i]-1)*heights[i]);
   }
   return maxi;
 }