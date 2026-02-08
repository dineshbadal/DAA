// leetcode easy 392 
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.size()==0 && s.size()==0) return 1;
        if(t.size()==0) return false ;
        if(s.size()==0) return true ;
        int i=0 ;
        for( auto it: t){
            if( i < s.size() && it==s[i]){
              i=i+1;
               }
        }
        return i==(s.size());
    }
};
