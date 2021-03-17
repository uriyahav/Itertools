#ifndef ALG_H
#define ALG_H

#include <iostream>
using namespace std;

bool debug = false;

template <typename T>
T Add_n(T begin, T end, unsigned int n) {
    // Not so good code but compiles for 100 via online compiler

    int times = 0;
    T start = begin; 
    while(begin != end && times <= (end - begin) / n) {
        unsigned int sum = 0;
        unsigned int steps = 0;
        T current = start + times * n;
        while(current < end && steps != n) {
            sum += * current;
            steps ++; 
            current ++;
        }
        if(debug) cout << *begin << " now equals to " << sum << endl;
        * begin = sum;
        times ++;
        begin ++;
    }

    // Sum the last elements
    if( (end - start) % n != 0 && times <= (end - start) / n ) { 
        T _begin = end - (end-start) % n;
         if(debug) cout << *begin << " now equals to ";
        * begin = 0;
        while (_begin != end) {
            * begin += * _begin;
            _begin ++;
        }
        if(debug) cout << *begin << endl;
        begin ++;
    } else if(debug) cout << "not in sum_the_last_elements" << endl;
    return begin;
}

template <typename T>
T Transpose(T start, T end) {
    T current = start;
    T _end = end;
    if( (end - start) % 2 != 0 ) 
        _end = end - 1; 

     while(current != _end) {
        iter_swap(current, current + 1);
        current += 2;
    }
    return _end;
}

template <typename T, typename U, typename F>
U Transform(T start, T end, U second_start, F f) {
    if( (end - start) % 2 != 0 || (end - start) == 0 )  { 
        return second_start;
    }
    while(start != end) {
        auto ans = f(*start , *(start + 1));
        * second_start = ans;

        start += 2;
        ++ second_start;
    }
    
    return second_start;
}


#endif