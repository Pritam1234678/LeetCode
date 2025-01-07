class Solution {
public:
    string reverseWords(string s) {
        
       istringstream stream(s);
       string str;
       vector<string>v;
       while(stream>>str){
        v.push_back(str);
       }
       reverse(v.begin(),v.end());
       str ="";

       for(int i=0;i<v.size();i++){
        str+=v[i];
      if(i!=v.size()-1)
      str+=" ";
       }
       return str;

    }
};
