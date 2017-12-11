//
// Created by 전준호 on 2017. 11. 7..
//
#include <utility>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cstdio>
#include <string>
#include <assert.h>

using namespace std;

void swap(int a, int b)
{

    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {
    int value = 2, list[5] = {1, 3, 5, 7, 9};

    swap(value, list[0]);

    cout << value << "   " << list[0] << endl;

    swap(list[0], list[1]);

    cout << list[0] << "   " << list[1] << endl;

    swap(value, list[value]);

    cout << value << "   " << list[value] << endl;


    for(int i = 0; i < 5; i++)
        cout << list[i] << " ";
}