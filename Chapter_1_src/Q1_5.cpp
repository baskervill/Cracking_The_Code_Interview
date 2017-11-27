#include <iostream>
#include <cstring>
using namespace std;
//if the old array's space is not enough , create a new array 
char* replace1(char *s){
    if(s == NULL) return NULL;
    int len = strlen(s);
    if(len == 0) return NULL;
    int count = 0;
    for(int i = 0; s[i] != '\0';i++){
        if(s[i] == ' '){
            count++;
        }
    }
    char *ss = new char[len + 2 * count + 1];
    int p = 0;
    for(int i = 0;i < len;i++){
        if(s[i] == ' '){
            ss[p] = '%';
            ss[p + 1] = '2';
            ss[p + 2] = '0';
            p += 3;
        }
        else{
            ss[p++] = s[i]; 
        }
    }
    return ss;
}
//if the old array is enough , from back to front to fill the old one, no need a spare array
char *replace2(char *s){
    if(s == NULL) return NULL;
    int len = strlen(s);
    if(len == 0) return NULL;
    int count = 0;
    int p = 0;
    for(int i = 0;i < len;i++){
        if(s[i] == ' '){
            count++;
        }
    }
    p = len + 2 * count;
    s[p--] = '\0';
    for(int i = len - 1;i > 0;i--){
        if(s[i] == ' '){
            s[p] = '0';
            s[p - 1] = '2';
            s[p - 2] = '%';
            p -= 3;
        }
        else{
            s[p--] = s[i];
        }
    }

    

}
int main(){
    char s[] = "I am a stronger";
    char *ss = replace1(s);
    cout<<ss<<endl;
    return 0;
}