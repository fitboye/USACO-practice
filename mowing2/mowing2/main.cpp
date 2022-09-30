//
//  main.cpp
//  mowing2
//
//  Created by Jerry Cheng on 5/11/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin ("mowing.in");
    ofstream fout ("mowing.out");
    int x = 100000000, n, c[100], time = 0, times[1001], d[1001], e[1001], last = 0;
    char b[100];
    fin >> n;
    for (int i = 0; i < n;i++){
        fin >> b[i] >> c[i];
    }
    
    d[0] = 0;
    e[0] = 0;
    for (int i = 0; i < n; i++){
        if (b[i] == 'N'){
            for (int j = last; j < last + c[i]; j++){
                //cout << d[j] << ' ' << e[j] << endl;
                d[j + 1] = d[j] + 1;
                e[j + 1] = e[j];
                times[time] = time;
                time++;
                //cout << time << ' ' << j << endl;
            }
        }else if (b[i] == 'S'){
            for (int j = last; j < last + c[i]; j++){
                //cout << d[j] << ' ' << e[j] << endl;
                d[j + 1] = d[j] - 1;
                e[j + 1] = e[j];
                times[time] = time;
                time++;
                //cout << time << ' ' << j << endl;
            }
        }else if (b[i] == 'E'){
            for (int j = last; j < last + c[i]; j++){
                //cout << d[j] << ' ' << e[j] << endl;
                d[j + 1] = d[j];
                e[j + 1] = e[j] - 1;
                times[time] = time;
                time++;
                //cout << time << ' ' << j << endl;
            }
        }else if (b[i] == 'W'){
            for (int j = last; j < last + c[i]; j++){
                //cout << d[j] << ' ' << e[j] << endl;
                d[j + 1] = d[j];
                e[j + 1] = e[j] + 1;
                times[time] = time;
                time++;
                //cout << time << ' ' << j << endl;
            }
        }
        //cout << time - c[i] << endl;
        for (int j = time - c[i]; j < time; j++){
            for (int k = 0; k < time - c[i]; k++){
                //cout << d[j] << ' ' << e[j] << ' ' << d[k] << ' ' << e[k] << endl;
                if ((d[j] == d[k]) && (e[j] == e[k])){
                    if ((j != k) && (times[k] != -1)){
                        if (times[j] - times[k] < x){
                            //cout << '^' << times[j] << ' ' << times[k] << endl;
                            x = times[j] - times[k];
                        }
                        times[k] = -1;
                    }
                }
            }
        }
        //cout << endl;
        last = last + c[i];
    }
    
    //cout << endl;
    
    for (int i = 0; i < 1000; i++){
        //cout << d[i] << ' ' << e[i] << ' ' << times[i] << endl;
    }
    
    if (x == 100000000){
        fout << -1 << endl;
    }else{
        fout << x << endl;
    }
    return 0;
}
