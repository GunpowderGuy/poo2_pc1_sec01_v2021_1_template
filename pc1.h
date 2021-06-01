//
// Created by rudri on 5/31/2021.
//

#ifndef POO2_PC1_SEC01_PC1_H
#define POO2_PC1_SEC01_PC1_H

#include<vector>
#include<iterator>
#include<algorithm>
#include <initializer_list>

// Pregunta #1

class pagination_t {
    int current_page = 1;
    int page_size = 10;
    int* array {};
    int array_size = 0;
    
    public:

    pagination_t (std::initializer_list<int> lista): array_size(lista.size()) {
        array = new int[array_size];
        auto i = 0;

        for (auto it = begin(lista); it != end(lista); ++it) {
            array[i] = *it;
            i++;
        }
    }
    
    void set_page_size(int sz){
        page_size = sz;    
    }

    void next_page(){
        current_page++;
    }

    void previous_page(){
        current_page--;
    }

    void first_page(){
        current_page = 1;
    }

    void last_page(){
        current_page = page_size;
    }

};


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
    auto vec1 = std::vector(cont1.begin(),cont1.end()); //tiempo: O(N), espacio : O(N)
    auto vec2 = std::vector(cont2.begin(),cont2.end()); // tiempo : 0(N), espacio : 0(N)
    
    //n es tamanno contenedor
    std::sort(vec1.begin(),vec1.end()); // tiempo : O(N·log(N)), espacio : O(1) 
    std::sort(vec2.begin(),vec2.end()); // tiempo : O(N·log(N)), espacio : O(1) 

    return vec1 == vec2; // tiempo : O(N), espacio : O(1) 
} 
//complejidad tiempo
//O(1)+O(1)+O(N·log(N))+O(N·log(N))+O(1) = (1+1+N·log(N)+N·log(N)+1)
//=O(N·log(N))

//complejidad espacio
//O(N)+O(N)+O(1)+O(1)+O(1) = O(N+N+1+1+1)
//=O(N)

#endif //POO2_PC1_SEC01_PC1_H
