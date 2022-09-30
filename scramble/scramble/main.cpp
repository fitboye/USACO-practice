//
//  main.cpp
//  scramble
//
//  Created by Jerry Cheng on 11/9/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct word{
    string word;
    int loc;
};

bool c (char a, char b){
    return a > b;
}


bool compare (word a, word b){
    return a.word < b.word;
}

int main() {
    ifstream fin("scramble.in");
    ofstream fout("scramble.out");
    int n;
    word a[2][50000];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[0][i].word;
        a[1][i] = a[0][i];
        char b[20];
        for (int j = 0; j < a[0][i].word.length(); j++){
            b[j] = a[0][i].word[j];
        }
        
        sort(b, b + a[0][i].word.length());
        for (int j = 0; j < a[0][i].word.length(); j++){
            a[0][i].word[j] = b[j];
        }
        a[0][i].loc = i;
        
        sort(b, b + a[0][i].word.length(), c);
        for (int j = 0; j < a[0][i].word.length(); j++){
            a[1][i].word[j] = b[j];
        }
        a[1][i].loc = i;
    }
    sort(a[0], a[0] + n, compare);
    sort(a[1], a[1] + n, compare);
    
    for (int i = 0; i < n; i++){
        //cout << a[0][i].word << endl;
    }
    for (int i = 0; i < n; i++){
        //cout << a[1][i].word << endl;
    }
    
    int ans[2][50000];
    for (int i = 0; i < n; i++){
        int l = 0, r = n - 1, m;
        while (r - l >= 0){
            //cout << l << ' ' << r << endl;
            m = (l + r) / 2;
            //cout << a[0][i].word << ' ' << a[1][m].word << endl;
            if (a[0][i].word == a[1][m].word){
                l = m;
                break;
            }else if (a[0][i].word < a[1][m].word){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        //cout << l << endl;
        ans[0][a[0][i].loc] = l + 1;
    }
    
    for (int i = 0; i < n; i++){
        int l = 0, r = n - 1, m;
        while (r - l >= 0){
            //cout << l << ' ' << r << endl;
            m = (l + r) / 2;
            //cout << a[1][i].word << ' ' << a[0][m].word << endl;
            if (a[1][i].word == a[0][m].word){
                l = m + 1;
                break;
            }else if (a[1][i].word < a[0][m].word){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        //cout << l << endl;
        ans[1][a[1][i].loc] = l;
    }
    
    for (int i = 0; i < n; i++){
        fout << ans[0][i] << ' ' << ans[1][i] << endl;
    }
    return 0;
}









