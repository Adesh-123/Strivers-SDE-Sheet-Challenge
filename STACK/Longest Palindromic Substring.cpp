string longestPalinSubstring(string str)
{
    int len=1;
    int l=0;

    for(int i=1;i<str.size();i++){
        int low=i-1;
        int high=i;

        while(low>=0 && high<str.size() && str[low]==str[high]){
            if(high-low+1>len){
                l=low;
                len=high-low+1;
            }
            low--,high++;
        }

        low=i-1;
        high=i+1;
        while(low>=0 && high<str.size() && str[low]==str[high]){
            if(high-low+1>len){
                l=low;
                len=high-low+1;
            }
            low--,high++;
        }
    }
    if(len==1){
        string a="";
        a+=str[0];
        return a;
    }

    string ans="";
    for(int i=l;i<l+len;i++){
        ans+=str[i];
    }
    return ans;
}