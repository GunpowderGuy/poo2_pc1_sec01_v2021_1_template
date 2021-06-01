//
// Created by rudri on 5/31/2021.
//

#ifndef POO2_PC1_SEC01_PC1_H
#define POO2_PC1_SEC01_PC1_H

#include<vector>
#include<iterator>
#include<algorithm>

// Pregunta #1
/*
template<int len>
class pagination_t {
    int page_size;
    std::array<int, len>;
    
    public:

    pagination_t(std::initializer_list<int> lis) array(lis){}
};
*/

// Pregunta #2 funcione para vector, dequee y list
template<typename Cnt>
Cnt padding(const Cnt cnt, const int elem,const int new_size){
    auto result = cnt;

    for(int i = 0; i < new_size - cnt.size(); ++i){
        cnt.push_back(elem);    
    }

    return result;
}

template<typename Cnt>
std::vector<Cnt> generate_triangle(Cnt cnt,int triangulo_base){
    std::vector<Cnt> result;

    Cnt temp;
    auto cnt2 = padding(cnt,0,triangulo_base);
    auto comienzo = cnt2.begin();
    
    for(int i = 0; i < triangulo_base; ++i ){
        comienzo = std::advance(comienzo,i);
        auto final = std::advance(comienzo,i);

        temp = Cnt(comienzo,final);

        result.push_back(temp);
    }
    return result;
}

// Pregunta #3 y Pregunta #4

template<typename Cnt1,typename Cn2>
bool contain_same_values(const Cnt1 cont1,const Cnt1 cont2){
    auto vec1 = std::vector(cont1.begin(),cont1.end());
    auto vec2 = std::vector(cont2.begin(),cont2.end());
 
    std::sort(vec1.begin(),vec1.end());
    std::sort(vec2.begin(),vec2.end());

    return vec1 == vec2;
}

#endif //POO2_PC1_SEC01_PC1_H
