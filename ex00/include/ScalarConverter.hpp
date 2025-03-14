/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nige42 <nige42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:14:43 by nrobinso          #+#    #+#             */
/*   Updated: 2025/03/14 10:46:02 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip> // for std::setprecision
#include <cmath> // For HUGE_VALF and isnan/isinf
#include <limits> // For numeric_limits

#define DECIMALS 1
#define FDECIMALS 4

class ScalarConverter {

    public:
    
        ScalarConverter(const std::string);
        ~ScalarConverter(void);
        static void convert(const std::string&);
        
    private:
        
        ScalarConverter(void);
        ScalarConverter &operator=(const std::string);
        ScalarConverter(ScalarConverter const &convert);
};