/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nige42 <nige42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:06:58 by nrobinso          #+#    #+#             */
/*   Updated: 2025/03/14 12:24:43 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h> // For uintptr_t

typedef struct Data {
    int a;
    int b;
} data;



int main() {
    
    data value;

    value.a = 42;
    value.b = 21;
    
    data* ptr = &value; // Pointer to an integer

    // Serialize pointer: Convert the pointer to an integer
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    std::cout << "Serialized pointer (as integer): " << raw << std::endl;

    // Deserialize pointer: Convert the integer back to a pointer
    data* deserializedPtr = reinterpret_cast<data*>(raw);
    std::cout << "Deserialized value->a: " << deserializedPtr->a << std::endl;
    std::cout << "Deserialized value->b: " << deserializedPtr->b << std::endl;
    return 0;
}
