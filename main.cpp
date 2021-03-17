#include "alg.h"
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/** Zvi Mints - Matala 2 // May 2020 **/
int total_tests = 0;

template <typename U, typename T>
void assert_equals(U res, T expected, bool debug, string name) {
    total_tests ++ ;
    if(debug) cout << "Running [test] " << name << std::endl;
    reverse(expected.begin(), expected.end());
    auto current = expected.begin();
    while(current != expected.end())
    {
        if(debug) {
            std::cout << "comparing" << "(" << *res << "," << *current << ")" << std::endl;
        }
        assert(*res == *current); 

        -- res;
        ++ current;
    }
    if(debug) { std::cout << "[test] " << name << " - passed" << std::endl; }
}


void testAddN() {
    int ia[] = {1,2,3,4,5,6,7,8,9};
    int* res = Add_n(begin(ia), end(ia), 3);
    vector<int> expected = {6,15,24,4};
    assert_equals(res, expected, false, "testAddN - 1");
    
    int ia2[] = {5 ,7 ,1 ,3 ,40 ,10 ,30 ,20 ,50};
    int* res2 = Add_n(begin(ia2), end(ia2), 4);
    vector<int> expected2 = {16, 100 ,50, 3};
    assert_equals(res2, expected2, true, "testAddN - 2");
}

void testTranspose() {
    int ia[] = {1,2,3,4,5,6,7,8,9};
    int* res = Transpose(begin(ia), end(ia));

    vector<int> expected = {2,1,4,3,6,5,8,7,9};
    assert_equals(res, expected, false, "testTranspose"); 
}   

void testTransform() {
    // First Check - Odd
    int odd[11] = {};
    vector<int> vec1(100);  
    decltype(vec1.begin()) res1 = Transform(begin(odd), end(odd), vec1.begin(),
    [](const int x, const int y){return x + y;});

    assert(res1 == vec1.begin());
    
    // Second Check - Valid Check
    
    int ia[] = {1,2,3,10,8,6};
    vector<int> vec2(8); 

    decltype(vec2.begin()) res2 = Transform(begin(ia), end(ia), vec2.begin(),
    [](const int x, const int y){return x + y;});

    vector<int> expected2 = {3,13,14,0};
    assert_equals(res2, expected2, false, "testTranform - 2");
}
 
int main() {
    
    // Add_n
    testAddN();
    
    // Transpose 
    testTranspose();

    // Transform
    testTransform();

    cout << "total " << total_tests << " passed" << endl;
    
}
