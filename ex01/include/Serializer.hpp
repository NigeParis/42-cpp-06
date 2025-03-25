/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nige42 <nige42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:14:31 by nige42            #+#    #+#             */
/*   Updated: 2025/03/25 10:09:47 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "./include/Data.hpp"     // structure to hold data

class Serializer {

    public:
    
        static unsigned long serialize(Data* ptr);
        static Data* deserialize(unsigned long raw);
    
    private:
    
        Serializer(void);
        Serializer &operator=(Serializer&);
        Serializer (Serializer &serializer);
        ~Serializer(void);
 
};
