struct Node{
   Node* link[26];
   int cntEndWith=0;
   int cntPrefix=0;
    
   bool containsKey(char c){
       return (link[c-'a']!=NULL);
   }
   Node* get(char c){
       return link[c-'a'];
   } 
   void put(char c,Node* node){
       link[c-'a']=node;
   } 
   void increaseEnd(){
        cntEndWith++;
   } 
   void increasePrefix(){
     cntPrefix++;  
   } 
   void deleteEnd(){
      cntEndWith--; 
   } 
   void deletePrefix(){
       cntPrefix--;
   } 
   int getEnd(){
       return cntEndWith;
   } 
   int getPrefix(){
       return cntPrefix;
   } 
    
};
class Trie{
    private: Node* root;
    public:

    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
             node=node->get(word[i]);
             node->increasePrefix();
        }
              node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])) return 0;
              node=node->get(word[i]);
        }
           return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])) return 0;
             node=node->get(word[i]);
        }
           return node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                node->deletePrefix();
            }else return ;
        }
               node->deleteEnd();
    }
};
