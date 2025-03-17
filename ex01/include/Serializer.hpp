/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nige42 <nige42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:14:31 by nige42            #+#    #+#             */
/*   Updated: 2025/03/17 13:17:07 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstdint>                // For uintptr_t
#include "./include/Data.hpp"     // structure to hold data

class Serializer {

    public:
    
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    
    private:
    
        Serializer(void);
        Serializer &operator=(Serializer&);
        Serializer (Serializer &serializer);
        ~Serializer(void);
 
};
