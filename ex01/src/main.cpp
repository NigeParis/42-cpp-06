/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nige42 <nige42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:06:58 by nrobinso          #+#    #+#             */
/*   Updated: 2025/03/14 12:08:32 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h> // For uintptr_t

int main() {
    int value = 42;
    int* ptr = &value; // Pointer to an integer

    // Serialize pointer: Convert the pointer to an integer
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    std::cout << "Serialized pointer (as integer): " << raw << std::endl;

    // Deserialize pointer: Convert the integer back to a pointer
    int* deserializedPtr = reinterpret_cast<int*>(raw);
    std::cout << "Deserialized value: " << *deserializedPtr << std::endl;

    return 0;
}
