/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nige42 <nige42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:00:38 by nige42            #+#    #+#             */
/*   Updated: 2025/03/25 10:06:46 by nige42           ###   ########.fr       */
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

unsigned long Serializer::serialize(Data* ptr) {

    unsigned long raw = reinterpret_cast<unsigned long>(ptr);
    return (raw);
};

Data* Serializer::deserialize(unsigned long raw) {

    data* deserializedPtr = reinterpret_cast<data*>(raw);
    return (deserializedPtr);
};
