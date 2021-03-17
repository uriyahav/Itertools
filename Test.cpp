
#include "doctest.h"
#include <iostream>
#include <vector>
#include <limits>

#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"


using namespace itertools;
using namespace std;

TEST_CASE("range"){
    //All numbers from -20 to 20
    int j = -20;
    for(int i : range(-20,20)){
        CHECK(i == j++);
    }
}
TEST_CASE("accumulate of string vector"){
    //"Hello world"
    vector<string> str = {"H", "e", "l", "l", "o", " ", "w", "o" ,"r" ,"l" , "d"};
    string ans[] = {"H", "He", "Hel", "Hell", "Hello","Hello ", "Hello w", "Hello wo", "Hello wor","Hello worl", "Hello world"};
    int j = 0;
    for(auto i : accumulate(str)){
        CHECK(i == ans[j++]);
    }
}

TEST_CASE("accumulate of range "){
    //1+2+3+4+5+6+7+8+9+10+11+12+13+14+15
    vector<int> sum = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120};
    int j = 0;
    for(int i : accumulate(range(1,16))){
        CHECK(i == sum.at(j++));
    }
}

TEST_CASE("accumulate of binary operator") {
    //1*2*3*4*5*6*7
    int j=0;
    vector<int> sum = {1, 2, 6, 24, 120, 720, 5040};
    for (int i: accumulate(range(1,8), [](int x, int y){return x*y;})){
            CHECK(i == sum[j++]);
    }
}

TEST_CASE("filter false of prime numbers") {
    //filter out all the not prime numbers
    struct prime{
        bool operator()(int i) const { return (i==2 || i==3 || i==5 || i==7 || i==11 || i==13); }
    };
    for (auto i : filterfalse(prime{}, range(1,14))) {
            CHECK(((i != 2) && (i != 3) && (i!=5) && (i!=7)  && (i!=11) && (i!=13)));
    }
}

 
TEST_CASE("filter false of strings") {
    //filter out all the string that is less than 2
    typedef struct {
        bool operator()(string s) const {
            return (s.size() < 2);
        }
    }length;
    length l;
    vector<string> v = {"shoval", "tayro", "uriya", "havshush", "one","two","three","four", "five", "six","seven", "eight", "nine", "ten",
                        "string", "integer", "char", "double", "short", "long", "float", "max", "min",
                        "java", "python", "c", "cpp", "csharp", "html", "javascript", "oop", "cpmuter", "seince",
                        "ariel", "ok","linux", "windows", "hi","bye", "include"};
    for (auto i : filterfalse(l, v)) {
        CHECK(l(i) == false);
    }
}


TEST_CASE("compress a range"){
    //only odd numbers;
    vector<bool> b = {true,false,true,false,true,false,true,false,true,false,
                    true,false,true,false,true,false,true,false,true,false};
     for (auto i: compress(range(0,20), b) ){
        CHECK(i%2 == 0);
     }
}

TEST_CASE("compress a string"){
    //compress only "assignment"
    vector<char> ans = {'a', 's', 's', 'i', 'g', 'n', 'm', 'e', 'n', 't'};
    vector<bool> b = {true,false,true,true,false,true,true,false,true,true,true,false,true,true};
    int j = 0;
    for (auto i: compress(string("absscigdnmexnt"), b)){
        CHECK(i == ans.at(j++));
    }

     //compress only "itertools"
    vector<char> ans2 = {'i', 't', 'e', 'r', 't', 'o', 'o', 'l', 's'};
    vector<bool> b2 = {true,true,true,false,true,true,false,true,true,false,true,true};
    j = 0;
    for (auto i: compress(string("itexrtaooqls"), b2)){
        CHECK(i == ans2.at(j++));
    }

}