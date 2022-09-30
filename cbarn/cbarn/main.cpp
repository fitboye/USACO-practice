 //
//  main.cpp
//  cbarn
//
//  Created by Jerry Cheng on 8/22/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int main() {
    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");
    int n;
    fin >> n;
    int a[1000];
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    
    int min = 1000000000;
    for (int i = 0; i < n; i++){
        if (a[i] > 0){
            int rooms[1000], total = 0, endpos[1000];
            for (int j = 0; j < n; j++){
                rooms[j] = a[j];
                endpos[j] = -1;
            }
            queue<int> currentcows;
            bool works = true;
            for (int j = i; j < i + n; j++){
                int x = j % n;
                while (rooms[x] > 0){
                    currentcows.push(x);
                    rooms[x]--;
                }
                if (currentcows.empty()){
                    works = false;
                    break;
                }else{
                    rooms[x]++;
                    endpos[x] = currentcows.front();
                    currentcows.pop();
                }
            }
            
            for (int j = 0; j < n; j++){
                if (endpos[j] == -1){
                    works = false;
                    break;
                }
                int x;
                if (j >= endpos[j]){
                    x = j - endpos[j];
                }else{
                    x = n - endpos[j] + j;
                }
                //cout << x << endl;
                total = total + x*x;
            }
            if (works && total < min){
                min = total;
            }
            /*
            for (int j = 0; j < n; j++){
                cout << rooms[j] << ' ';
            }
            cout << endl;
            for (int j = 0; j < n; j++){
                cout << endpos[j] << ' ';
            }
            cout << endl << endl;
             */
        }
    }
    fout << min << endl;
    return 0;
}
