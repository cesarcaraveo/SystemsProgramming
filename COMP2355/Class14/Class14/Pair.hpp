//
//  Pair.hpp
//  Class14
//
//  Created by Cesar Caraveo on 2/16/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#ifndef Pair_hpp
#define Pair_hpp

#include <stdio.h>
#include <iostream>

template <typename K, typename V>
class Pair
{
public:
    Pair(K k, V v);
    Pair(Pair& source);
    Pair& operator=(Pair& source);
    K getkey();
    V getvalue();
    void setkey(K k);
    void setvalue(V v);
    void PrintPair();
    
    
private:
    K key;
    V value;
};

template <typename K, typename V>
Pair<K, V>::Pair(K k, V v):key(k), value(v){ }

template <typename K, typename V>
Pair<K, V>::Pair(Pair& source)
{
    key = source.key;
    value = source.value;
}

template <typename K, typename V>
Pair<K, V>& Pair<K, V>::operator=(Pair<K, V>& source)
{
    key = source.key;
    value = source.value;
    
    return *this;
}

template <typename K, typename V>
K Pair<K, V>::getkey()
{
    return key;
}

template <typename K, typename V>
V Pair<K, V>::getvalue()
{
    return value;
}

template <typename K, typename V>
void Pair<K, V>::setkey(K k)
{
    key = k;
}

template <typename K, typename V>
void Pair<K, V>::setvalue(V v)
{
    value = v;
}

template <typename K, typename V>
void Pair<K, V>::PrintPair()
{
    std::cout<<"("<<key<<": "<<value<<")"<<"\n";
}



#endif /* Pair_hpp */
