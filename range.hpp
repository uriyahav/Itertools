#pragma once
namespace itertools{

    //template <typename T>
    class range{
        int _first;
        int _last;

        public:
        range (int start, int end): _first(start), _last(end) {} 
        
        class iterator{
            
            public:
            int value;

            explicit iterator(int v) : value(v){}
            iterator(const iterator& it) = default;

            int operator*(){
                return value;
            }

            iterator& operator++(){
               ++value;
               return  *this;
            } 
            iterator operator++ (int){
                iterator temp=(*this);
                ++value;
                return temp;
            } 

            iterator& operator= (const iterator& a){
                if(this != &a) this->value = a.value;
                return *this;
            }

            bool operator ==(const iterator& other) {
                return (value == other.value);
            }
            bool operator!=(iterator const &diff) const{
                return (value != (diff.value));
            }           
        };
    
        iterator begin() {return iterator(_first); }  
        iterator end() {return iterator(_last); } 

        typedef int value_type;
    };
}

