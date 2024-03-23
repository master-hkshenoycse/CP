#include<bits/stdc++.h>
using namespace std;

//main idea that every tag/CDATA starts with < and based on this position can be found */

class Solution {
public:
    // Function to check if the input XML code is valid

    bool validateTag(string tag){
        int sz=tag.size();
        if(sz<1 or sz>9){
            return false;
        }

        for(auto ch:tag){
            if(ch<'A' or ch>'Z'){
                return 0;
            }
        }

        return 1;

    }
    bool isValid(string code) {

        int sz=code.size();

        if(sz==0){
            return 0;
        }

        if(code[0] != '<' or code[sz-1]!='>'){
            return 0;
        }

        stack<string> tagStack;
        int i=0;

        while(i<sz){
            char ch=code[i];

            if(ch=='<'){
                char nx_ch=code[i+1];
                if(nx_ch =='!'){

                    if(tagStack.size()==0){
                        return 0;
                    }
                

                    auto cDataIndex=code.find("[CDATA[",i);

                    //<![CDATA[,it begins 2 positions after <
                    if(cDataIndex==string::npos || cDataIndex!=i+2){
                        return 0;
                    }

                    //find the end of cdata segment and move the pointer
                    cDataIndex=code.find("]]>",i);
                    if(cDataIndex==string::npos){
                        return 0;
                    }

                    i=cDataIndex+3;
                }else if(nx_ch == '/'){

                    if(tagStack.size()==0){
                        return 0;
                    }

                    auto endTagIndex=code.find(">",i);
                    if(endTagIndex == string::npos){
                        return 0;
                    }
                    string tag=code.substr(i+2,endTagIndex-i-2);
                    if(validateTag(tag)==0){
                        return 0;
                    }

                    i=endTagIndex+1;

                    //this shoudl match with top of tag
                    if(tagStack.top()==tag){
                        tagStack.pop();
                        if(tagStack.size()==0){
                            if(i<sz){
                                return 0;
                            }
                        }
                    }else{
                        return 0;
                    }

            }else{
                auto endTagIndex=code.find(">",i);
                if(endTagIndex==string::npos){
                    return 0;
                }

                string tag=code.substr(i+1,endTagIndex-i-1);
                if(validateTag(tag)==0){
                    return 0;
                }

                i=endTagIndex+1;
                tagStack.push(tag);
            }

            }else{
                i++;
            }

        }

        if(tagStack.size()!=0){
            return 0;
        }
        return 1;
    }
};
