/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nige42 <nige42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:00:38 by nige42            #+#    #+#             */
/*   Updated: 2025/03/17 13:18:26 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Serializer.hpp"

Serializer::Serializer(void) {
    //std::cout << "default constructor" << std::endl; 
};

Serializer &Serializer::operator=(Serializer&) {
    //std::cout << "copy assignement operator" << std::endl; 
        return (*this);
};

Serializer::Serializer(Serializer& ) {
    //std::cout << "copy constructor" << std::endl; 
};

Serializer::~Serializer(void) {
    //std::cout << "default destructor" << std::endl; 
};

uintptr_t Serializer::serialize(Data* ptr) {

    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
};

Data* Serializer::deserialize(uintptr_t raw) {

    data* deserializedPtr = reinterpret_cast<data*>(raw);
  
    return (deserializedPtr);
};
