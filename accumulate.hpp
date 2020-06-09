//
// Created by yirat on 08/06/2020.
//
#pragma once

namespace itertools{
    template <typename T> class accumulate{
        T& iterable;
    public:
        accumulate(T& it): iterable(it){}

        class iterator{
             T::iterator current; //if iterable=string<vector>  --->current = iterator vecrot<string>
        public:
            iterator( current1): current(current1){}


            iterator &operator++() {
               current=current++;
               for()

            }



        };


        iterator begin(){
            return iterator(iterable.begin());
        }

        iterator end(){
            return iterator(iterable.end());
        }



    };

}

5,6,7,8,


