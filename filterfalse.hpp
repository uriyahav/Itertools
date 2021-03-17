#pragma once
#include <iostream>
#include <vector>

namespace itertools{
    template<typename FUNTION, typename CONTAINER>
    class filterfalse {
        CONTAINER con;
        FUNTION fun;
        typedef typename CONTAINER::value_type value_type;

    public:
        filterfalse(FUNTION func, CONTAINER cont): fun(func), con(cont){}

        class iterator{
            typename CONTAINER::iterator start;
            typename CONTAINER::iterator end;
            FUNTION fun;
        public:
            explicit iterator(typename CONTAINER::iterator it, typename CONTAINER::iterator it2, FUNTION f) : 
            start(it), end(it2), fun(f){
             //go through the parameters start->end
                while (start != end && fun(*start))
                   ++start;
            }
            iterator(const iterator& other) = default;

            iterator& operator=(const iterator& a){
                if(this != &a) {
                    this->start = a.start;
                    this->end = a.end;
                    this->fun = a.fun;
                }
                return *this;
            };
               bool operator ==(const iterator& other) {
                return (start == other.start);
            }
            bool operator !=(const iterator& other) {
                return (start != other.start);
                //maybe (start != other.start);
            }
            iterator& operator ++(){
                do {
                    ++start;
                } while (start != end && fun(*start));
                return *this;
            }
            iterator operator ++(int){
                iterator temp = *this;
                ++(*this);
                return temp;
            }
            value_type operator *(){
                return *start;
            }

        };
        iterator begin(){
            return iterator(con.begin(), con.end(), fun);
        }
        iterator end(){
            return iterator(con.end(), con.end(), fun);
        }
    };
}