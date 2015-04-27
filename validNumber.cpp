class Solution {
public:
    bool isNumber(string s) {
        int p = 0;
        skipSpace(s, &p);
        skipSign(s, &p);
        if(!hasNumber(s, &p)) return false;
        
        if(s[p]!= '\0' && (s[p] == 'e' || s[p] == 'E')){
            p++;
            skipSign(s, &p);
            if(!hasInteger(s, &p)) return false;
        }
        skipSpace(s, &p);
        return (s[p] == '\0');
    }
private:
    void skipSpace(string s, int *p){
        while(s[*p]!='\0' && s[*p] == ' ') (*p)++;
    }
    void skipSign(string s, int *p){
        while(s[*p] != '\0' && (s[*p] == '+' || s[*p] == '-')) (*p)++;
    }
    bool hasInteger(string s, int *p){
        int len = 0;
        while(s[*p] != '\0' && isdigit(s[*p])) {(*p)++; len++;}
        return len!=0;
    }
    bool hasNumber(string s, int *p){
        int len = 0;
        while(s[*p] != '\0' && isdigit(s[*p])) {(*p)++; len++;}
        if (s[*p] != '\0' && s[*p]=='.') (*p)++;
        while(s[*p] != '\0' && isdigit(s[*p])) {(*p)++; len++;}
        return len!=0;
    }
    
};
