////
//// Created by yirat on 08/06/2020.
////
#pragma once
#include <iostream>
#include <vector>
#include <iterator>



namespace itertools {

    template<class T>
    class accumulate {
        T& container;
    public:

        accumulate( T& con) : container(con){}

        class iterator{
             typename T::iterator iter;
            decltype(*(container.begin())) sum;

        public:
            explicit iterator(typename T::iterator curr): iter(curr),sum(*iter) {}


            iterator& operator++(){  //++iter
                sum+=*(++iter);
                return *this;
            }

            const iterator operator++(int){ //iter++
                iterator temp = *this;
                sum +=*(iter++);
                return temp;
            }

            bool operator==(const iterator &it) const {
                return iter==it.iter;
            }

            bool operator!=(const iterator &it) const {
                return !(iter==it.iter);
            }

            auto operator*(){
                return this->sum;
            }

            iterator& operator=(const iterator &temp_iter)
            {
                return *this;
            }

        };

        iterator begin() const {
            return iterator(container.begin());

        }
        iterator end() const {
            return iterator(container.end());
        }
    };

}