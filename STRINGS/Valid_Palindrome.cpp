class Solution {
public:
    bool isPalindrome(string s) {
        string t=""; 
        
        for(int i=0;i<s.size(); i++){
            if( s[i] >= 'a' and s[i] <= 'z' || s[i]>='A' and s[i]<='Z' || (s[i]>='0' && s[i]<='9')){
                if(s[i]>='A' and s[i]<='Z'){
                    t.push_back(s[i]+32); 
                }
                else{
                    t.push_back(s[i]); 
                }
            }
        }
        cout<<t<<endl; 
        int lo = 0, hi = t.size()-1;
        while(lo<=hi){
            if(t[lo] != t[hi]){
                return false;
            }
            lo++;
            hi--;
        }
        return true; 
    }
};
