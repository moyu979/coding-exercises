class Solution {
public:
    bool isValid(string s) {
        stack<char> c;
        int n=s.length();
        for(int i=0;i<n;i++){
            switch (s[i]){
                case '(':
                c.push('(');
                break;
            case '[':
                c.push('[');
                break;
            case '{':
                c.push('{');
                break;
            case ')':
                if(c.empty())
                    return false;
                if(c.top()!='(')
                    return false;
                c.pop();
                break;
            case ']':
                if(c.empty())
                    return false;
                if(c.top()!='[')
                    return false;
                c.pop();
                break;
            case '}':
                if(c.empty())
                    return false;
                if(c.top()!='{')
                    return false;
                c.pop();
                break;
            default:
                ;
            }
            
        }
        if (c.empty()){
            return true;
        }else{
            return false;
        }
        
    }
};