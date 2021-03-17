#pragma once
#include <iostream>
#include <vector>

namespace itertools{
    template<typename CONTAINER1, typename CONTAINER2>
    class compress {
        CONTAINER1 con;
        CONTAINER2 boolCon;
        typedef typename CONTAINER1::value_type value_type;

    public:
        compress(CONTAINER1 con1, CONTAINER2 boolCon1): con(con1), boolCon(boolCon1){}

        class iterator{
            typename CONTAINER1::iterator start;
            typename CONTAINER1::iterator end;
            typename CONTAINER2::iterator boolIter;
        public:
            explicit iterator(typename CONTAINER1::iterator start1, typename CONTAINER1::iterator end1, typename CONTAINER2::iterator boolIter1):
             start(start1), end(end1), boolIter(boolIter1){
                 //go through the parameters start->end
                while (start != end && !(*boolIter)){
                    ++start;
                    ++boolIter;
                    //maybe ++ first?
                }
            }
            iterator(const iterator& a) = default;

            iterator& operator=(const iterator& a){
                this->start = a.start;
                return *this;
            };
             bool operator ==(const iterator& a) {
                return (start == a.start);
            }
            bool operator !=(const iterator& a) {
                return (start != a.start);
                //maybe (start != other.start);
            }
            iterator& operator ++(){
                do{
                    ++start;
                    ++boolIter;
                  }
                 while (start != end && !(*boolIter));
                return *this;
            }
            iterator operator ++(int){
                iterator tmp = *this;
               ++(*this);
                return tmp;
            }
            value_type operator *(){
                return *start;
            }

        };
        iterator begin(){
            return iterator(con.begin(), con.end(), boolCon.begin());
        }
        iterator end(){
            return iterator(con.end(), con.end(), boolCon.end());
        }
    };
}

