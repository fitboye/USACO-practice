//
//  main.cpp
//  priority queue
//
//  Created by Jerry Cheng on 12/19/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct student{
    int score;
    string name;
};

struct compare{
    bool operator()(const student &a, const student &b){
        return a.score < b.score;
    }
};

int main() {
    priority_queue<int> a;
    priority_queue<int, vector<int>, greater<int>> b;
    priority_queue<student, vector<student>, compare> c;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        student x;
        cin >> x.name >> x.score;
        c.push(x);
    }
    
    for (int i = 0; i < n; i++){
        cout << c.top().name << ' ' << c.top().score << endl;
        c.pop();
    }
    return 0;
}
