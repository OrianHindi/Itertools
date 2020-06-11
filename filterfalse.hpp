//
// Created by yirat on 08/06/2020.
//
#pragma once

namespace itertools{
    template<typename FUNC,typename T>
    class filterfalse{
        T& container;
        const FUNC& function;
    public:
        filterfalse(const FUNC& func,T& con):function(func),container(con){}

        class iterator{
            typename T::iterator iter;
           // const FUNC& func;
           const filterfalse& filter;
        public:
            iterator(typename T::iterator it , const filterfalse& f):iter(it) , filter(f){}

            iterator& operator++(){
                ++iter;
                return *this;
            }

            const iterator operator++(int){
                iterator temp = *this;
                ++iter;
                return temp;
            }

            bool operator==(const iterator it) const{
                return iter==it.iter;
            }

            bool operator!=(const iterator it) const{
                return iter!=it.iter;
            }

            auto operator*(){
                std::cout<<"before the while: "<<*iter<<std::endl;
                while(filter.function(*iter) && *this!=filter.end()){
                std::cout<<"im in while, *iter="<<*iter<<std::endl;
                ++(*this);
            }
                return *iter;
            }
        };

        iterator begin()const{
            return iterator(container.begin(), *this);
        }

        iterator end()const{
            return iterator(container.end(),*this);
        }

    };
}
