#include <iostream>
#include <cstdio>
using namespace std;

// for 1 GB memory , only need 0.5GB memory, use bit map is enough
int main(){
    // freopen("12.3.in", "w", stdout);
    // int miss = 12345;
    // for(int i=0; i<20000; ++i){
    //     if(i == miss) continue;
    //     cout<<i<<endl;
    // }
    // fclose(stdout);
    
    freopen("12.3.in", "r", stdin);
    
    int int_len = sizeof(int) * 8;
    int bit_len = 0xFFFFFFFF / int_len;
    int* bit = new int[bit_len];
    int v;
    while(scanf("%d", &v) != EOF){
        bit[v/int_len] |= 1<<(v%int_len);
    }
    bool found = false;
    for(int i=0; i<bit_len; ++i){
        for(int j=0; j<int_len; ++j){
            if((bit[i] & (1<<j)) == 0){
                cout<<i*int_len + j<<endl;
                found = true;
                break;
            }
                
        }
        if(found) break;
    }
    
    delete[] bit;
    fclose(stdin);
    return 0;
}

//for 10MB memory , use block and bit map
//not memory all the data, just need a counter
int main1(){
    freopen("12.3.in", "r", stdin);// 20000 number
    int int_len = sizeof(int) * 8;
    int totalnum = 20000;
    int blocksize = 2000;
    int blocknum = totalnum / blocksize;
    int* block = new int[blocknum];
    int* bit = new int[blocksize/int_len+1];
    int v;
    while(scanf("%d", &v) != EOF){
        ++block[v/blocksize];
    }
    fclose(stdin);
    int start;
    for(int i=0; i<blocknum; ++i){
        if(block[i] < blocksize){
            start = i * blocksize;
            break;
        }
    }
    freopen("12.3.in", "r", stdin);
    while(scanf("%d", &v) != EOF){
        if(v>=start && v<start+blocksize){
            v -= start; // make v in [0, blocksize)
            bit[v/int_len] |= 1<<(v%int_len);
        }
    }

    bool found = false;
    for(int i=0; i<blocksize/int_len+1; ++i){
        for(int j=0; j<int_len; ++j){
            if((bit[i] & (1<<j)) == 0){
                cout<<i*int_len+j+start<<endl;
                found = true;
                break;
            }
        }
        if(found) break;
    }

    delete[] block;
    delete[] bit;
    fclose(stdin);
    return 0;
}