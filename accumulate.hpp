////
//// Created by yirat on 08/06/2020.
////
#pragma once
#include <iostream>
#include <vector>
#include <iterator>


typedef struct {
    template <typename T>
    auto operator()(T& x , T& y) const{
        return x+y;
    }

} add;

namespace itertools {

    template<class T,class FUNC = add>
    class accumulate {
         T& container;
        const FUNC& function;
    public:

        accumulate(T& con, const FUNC& f= add() ) : container(con),function(f){}

        class iterator{
            typename T::iterator iter;
            decltype(*(container.begin())) sum;
           const  FUNC& func;

        public:
            iterator(typename T::iterator curr,const FUNC& f): iter(curr),sum(*iter),func(f) {}

            iterator& operator++(){  //++iter
                sum=func(sum,*(++iter));
                return *this;
            }

            const iterator operator++(int){ //iter++
                iterator temp = *this;
                sum=func(sum,*(iter++));
                return temp;
            }

            bool operator==(const iterator &it) const {
                return iter==it.iter;
            }

            bool operator!=(const iterator &it) const {
                return !(iter==it.iter);
            }

            auto operator*(){
                return sum;
            }

            iterator& operator=(const iterator &temp_iter)
            {
                return *this;
            }

        };

        iterator begin() const {
            return iterator(container.begin(),function);

        }
        iterator end() const {
            return iterator(container.end(),function);
        }
    };

}