#include <iostream>
#include <cstdlib>
using namespace std;
int Rand7(){//from 1 to 7
    return rand() % 7 + 1;
}
int Rand5(){//from 1 to 5
    int x = ~(1 << 31);
    while(x > 5)
        x = Rand7();
    return x;
}
//to many redundant
int Rand7_1(){//from 1 to 7
    int x = ~(1 << 31);
    while(x > 7)
        x = 5 * (Rand5() - 1) + Rand5();
    return x;
}
//this is the same to 25 and 7
int Rand7_2(){
    int x = ~(1 << 31);
    while(x > 21)
        x = 5 * (Rand5() - 1) + Rand5();
    return x % 7 + 1;
}

int main(){
    srand(0);
    for(int i = 0;i < 20;i++){
        cout<<Rand7_2()<<endl;
    }

    return 0;
}

