//
// Created by yirat on 08/06/2020.
//
#pragma once
#include <iostream>
#include <vector>
#include <iterator>
namespace itertools {

    template<typename T>
    class accumulate {
        const T& container;
    public:
        accumulate(const T& con): container(con){}
        class iterator{
            typename T::iterator iter;
            decltype(*(container.begin())) sum;

        public:
            iterator( typename T::iterator curr): iter(curr) {
                sum=*iter;
            }
            iterator& operator++(){  //++iter
                iter++;
                sum = sum+*iter;
                return *this;
            }

            const iterator operator++(int){ //iter++
                iterator temp = *this;
                iter++;
                sum = sum+*iter;
                return temp;
            }
            bool operator==(const iterator &it) const {
                return iter==it.iter;
            }

            bool operator!=(const iterator &it) const {
                return iter!=it.iter;

            }
            auto operator*(){
                return sum;
            }

        };

        iterator begin() {
            return iterator(container.begin());

        }
        iterator end() {
            return iterator(container.end());
        }
    };



}