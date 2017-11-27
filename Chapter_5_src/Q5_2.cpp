#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 0.00001;
string print_binary(string s){
    //if(s.find('-') == string::npos)
    int pos = s.find('.', 0);
    int intpart = atoi(s.substr(0, pos).c_str());
    double decpart = atof(s.substr(pos, s.length() - pos).c_str());
    string intstr = "", decstr = "";
    while(intpart > 0){
        if(intpart & 1) intstr = "1" + intstr;
        else intstr = "0" + intstr;
        intpart >>= 1;
    }
    while((decpart - 0.0) > eps){
        if(decstr.length() > 32) return "ERROR";
        decpart *= 2;
        if(decpart >= 1){
            decstr += "1";
            decpart -= 1;
        }
        else
            decstr += "0";
    }
    return intstr + "." + decstr;
}
int main(){
    string s = "19.125";
    string s1 = print_binary(s);
    cout<<s1<<endl;
    return 0;
}





