struct Node{
    Node *link[26];
    bool flag=false;
    
    bool containsKey(char c){
        return (link[c-'a']!=NULL);
    }
    
    void put(char c,Node* node){
         link[c-'a']=node;
    }
    Node* get(char c){
        return  link[c-'a'];
    }
    bool getFlag(){
        return flag;
    }
    void setFlag(){
        flag=true;
    }    
};
void insert(string s,Node* root){
     Node* node=root;
    for(int i=0;i<s.size();i++){
        if(!node->containsKey(s[i])){
            node->put(s[i],new Node());
        }
        node=node->get(s[i]);
    }
    node->setFlag();
}
bool isPossible(string s,Node* root){
    Node* node=root;
    for(int i=0;i<s.size();i++){
        if(!node->containsKey(s[i])) return false;
        node=node->get(s[i]);
        if(!node->getFlag()) return false;
    }
    return true;
}

string completeString(int n, vector<string> &s){
    Node* root;
    root=new Node();
    for(int i=0;i<n;i++){
        insert(s[i],root);
    }
    int len=0;
    string ans="";
    sort(s.begin(),s.end());
    for(int i=0;i<n;i++){
        if(isPossible(s[i],root)){
            if(len<s[i].size()){
                len=s[i].size();
                ans=s[i];
            }
        }
    }
    if(ans=="") return "None";
    return ans;
}