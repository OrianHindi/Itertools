//
// Created by yirat on 08/06/2020.
//
#pragma once
#include <iostream>
#include <vector>
namespace itertools {

    template<class T> class accumulate {
        const T& container;

    public:
        accumulate(const T& con): container(con){}

        template<class E> class iterator{
            int sum=0;
            const E& current;
        public:
            iterator(const E& it) :current(it){
                sum=*it;
            }

            iterator& operator++(){
                ++current;
                sum+=*current;
                return *this;
            }

            const iterator operator++(int){
                iterator temp = *this;
                ++current;
                sum+=*current;
                return temp;
            }
            bool operator==(const iterator &it) const {
                return current == it.current;
            }

            bool operator!=(const iterator &it) const {
                return current != it.current;
            }
            auto operator*(){
                return sum;
            }

        };



        iterator<T> begin() {
            return iterator<T>(container.begin());
        }
        iterator<T> end() {
            return iterator<T>(container.end());
        }
    };




}