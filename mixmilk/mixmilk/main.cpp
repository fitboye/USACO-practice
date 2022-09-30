//
//  main.cpp
//  mixmilk
//
//  Created by Jerry Cheng on 12/15/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");
    int capacity[3], milk[3];
    fin >> capacity[0] >> milk[0];
    fin >> capacity[1] >> milk[1];
    fin >> capacity[2] >> milk[2];
    
    for (int i = 0; i < 100; i++){
        int totalmilk;
        if (i % 3 == 0){
            totalmilk = milk[0] + milk[1];
            if (totalmilk > capacity[1]){
                int overflow = totalmilk - capacity[1];
                milk[1] = capacity[1];
                milk[0] = overflow;
            }else{
                milk[1] = totalmilk;
                milk[0] = 0;
            }
        }else if (i % 3 == 1){
            totalmilk = milk[1] + milk[2];
            if (totalmilk > capacity[2]){
                int overflow = totalmilk - capacity[2];
                milk[2] = capacity[2];
                milk[1] = overflow;
            }else{
                milk[2] = totalmilk;
                milk[1] = 0;
            }
        }else{
            totalmilk = milk[2] + milk[0];
            if (totalmilk > capacity[0]){
                int overflow = totalmilk - capacity[0];
                milk[0] = capacity[0];
                milk[2] = overflow;
            }else{
                milk[0] = totalmilk;
                milk[2] = 0;
            }
        }
    }
    
    fout << milk[0] << endl << milk[1] << endl << milk[2] << endl;
    return 0;
}
