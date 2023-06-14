#include<map>
struct Node{
    Node* link[26];
    bool flag=false;
    
    bool containsKey(char c){
        return (link[c-'a']!=NULL);
    }
    void put(char c,Node* node){
        link[c-'a']=node; 
    }
    Node* get(char c){
        return link[c-'a'];
    } 
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};

int distinctSubstring(string &word) {
    Node* root=new Node();
    int count=0;
    for(int i=0;i<word.size();i++){
        Node* node=root;
        for(int j=i;j<word.size();j++){
            if(!node->containsKey(word[j])){
                node->put(word[j],new Node());
            }
            node=node->get(word[j]);    
            if(!node->isEnd()){
                count++;
                node->setEnd();
            }
        }
    }
    return count;
}
