#include "vector.h"
#include <iostream>
using namespace std;

int main(){
    myVector<int> vec1;
    for(int i = 0; i < 10; i++){
        vec1.push_back(i);
    }
    myVector<int>::iterator p;
    p = &vec1[1];

    vec1.print();
    cout << endl;
    cout << endl;
    vec1.erase(p);

    vec1.print();
    cout << endl;
    cout << endl;
    
    myVector<int> vec2(vec1);

    vec2.print();
    cout << endl;
    cout << endl;


    myVector<int> vec3;
    vec3 = vec2;

    vec3.print();
    cout << endl;
    cout << endl;
    

    return 0;
}