//
//  main.cpp
//  nocow
//
//  Created by Jerry Cheng on 8/29/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

bool compare(string a, string b){
    return a < b;
}

int attributenum;
vector<string> attributes[30];
string generateDescription(int combinations, int k){
    string out;
    for (int i = 0; i < attributenum; i++){
        //a = size of each part with attribute
        int a = combinations / attributes[i].size();
        int x;
        if (a == 0){
            x = 0;
            combinations = 0;
            k = 0;
        }else{
            x = k / a;
            combinations = combinations / attributes[i].size();
            k = k % a;
        }
        if (i == 0){
            out+= attributes[i][x];
        }else{
            out+= " ";
            out+= attributes[i][x];
        }
        //cout << attributes[i][x] << ' ';
    }
    return out;
}

int main() {
    ifstream fin("nocow.in");
    ofstream fout("nocow.out");
    int n, k;
    fin >> n >> k;
    string inputs[100];
    for (int i = 0; i < n; i++){
        string s;
        for (int j = 0; j < 4; j++){
            fin >> s;
        }
        int j = 0;
        while(true){
            fin >> s;
            if (s == "cow."){
                break;
            }
            if (j == 0){
                inputs[i] = s;
            }else{
                inputs[i]+= " ";
                inputs[i]+= s;
            }
            
            bool newattribute = true;
            for (int l = 0; l < attributes[j].size(); l++){
                if (attributes[j][l] == s){
                    newattribute = false;
                }
            }
            if (newattribute){
                attributes[j].push_back(s);
            }
            j++;
        }
        attributenum = j;
    }
    sort(inputs, inputs + n, compare);
    for (int i = 0; i < attributenum; i++){
        string a[100];
        int size = attributes[i].size();
        for (int j = 0; j < attributes[i].size(); j++){
            a[j] = attributes[i][j];
        }
        sort(a, a + size, compare);
        attributes[i].clear();
        for (int j = 0; j < size; j++){
            //cout << a[j] << ' ';
            attributes[i].push_back(a[j]);
        }
        //cout << endl;
    }
    
    int combinations = 1;
    for (int i = 0; i < attributenum; i++){
        combinations = combinations * attributes[i].size();
    }
    
    int smaller = 0;
    k = k - 1;
    while (k + smaller < combinations - 1 && generateDescription(combinations, k + smaller) >= inputs[smaller]){
        smaller++;
    }
     
    //cout << combinations << ' ' << smaller << endl;
    for (int i = 0; i < combinations; i++){
        //cout << generateDescription(combinations, i) << endl;
    }
    fout << generateDescription(combinations, k + smaller) << endl;
    return 0;
}
