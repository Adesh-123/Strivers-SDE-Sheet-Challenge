bool isValidParenthesis(string expression)
{
    int n=expression.size();
    stack<int> st;
    for(int i=0;i<n;i++){
        if(expression[i]=='(' or expression[i]=='{' or expression[i]=='['){
            st.push(expression[i]);
        } else {
          if (st.empty())
            return false;
          else if (expression[i] == ')' and st.top() != '(')
            return false;
          else if (expression[i] == '}' and st.top() != '{') 
            return false;
          else if(expression[i]==']' and st.top()!='[') 
            return false;
          st.pop();  
        }
    }
    if(st.empty()) return true;
    return false;
}