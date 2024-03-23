class Solution {
public:
    bool isValid(string code) {
        int i=0;
        return validTag(code,i) and i==code.size();
    }

    bool validTag(string s,int &i){
        int j=i;
        string tag=parseTagName(s,j);
        if(tag.empty()){
            return 0;
        }
        if(validContent(s,j)==0){
            return 0;
        }
        int k=j+tag.size()+2;
        if(k>=s.size() || s.substr(j,k+1-j) != "</"+tag+">"){
            return 0;
        }
        i=k+1;
        return 1;
    }

    string parseTagName(string s,int &i){
        if(s[i] != '<') return "";
        int j=s.find('>',i);

        if(j==string::npos or j-i-1<1 or j-1-i>9){
            return "";
        }
        string tag=s.substr(i+1,j-1-i);
        for(char ch:tag){
            if(ch<'A' or ch>'Z'){
                return "";
            }
        }
        i=j+1;
        return tag;
    }

    bool validContent(string s,int &i){
        int j=i;
        while(j<s.size()){
            if(validText(s,j)==0 and validCData(s,j)==0 and validTag(s,j)==0){
                break;
            }
        }
        i=j;
        return 1;
    }

    bool validText(string s,int &i){
        int j=i;
        while(i<s.size() and s[i] != '<'){
            i++;
        }
        return i!=j;
    }

    bool validCData(string s,int &i){
        if(s.find("<![CDARA[",i) != i){
            return 0;
        }
        int j=s.find("]]>",i);
        if(j==string::npos){
            return 0;
        }
        i=j+3;
        return 1;
    }
};