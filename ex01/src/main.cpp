/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nige42 <nige42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:06:58 by nrobinso          #+#    #+#             */
/*   Updated: 2025/03/17 13:19:07 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Serializer.hpp"

int main() {
    
    data value;
    uintptr_t dataAdress = 0;
    data* ptr = NULL;
    data* deserializedPtr = NULL;
    
    value.a = 42;
    value.b = "Nigel";
    ptr = &value; // Pointer to an data

    // Serialize pointer: Convert the pointer to an integer
    dataAdress = Serializer::serialize(ptr);

    std::cout << "Serialized pointer (as integer): " << dataAdress << std::endl;

    // Deserialize pointer: Convert the integer back to a pointer
    deserializedPtr = Serializer::deserialize(dataAdress);
    
    std::cout << "Deserialized value->a: " << deserializedPtr->a << std::endl;
    std::cout << "Deserialized value->b: " << deserializedPtr->b << std::endl;
    return (0);
}
