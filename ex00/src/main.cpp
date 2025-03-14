/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nige42 <nige42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:06:58 by nrobinso          #+#    #+#             */
/*   Updated: 2025/03/13 21:44:07 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ScalarConverter.hpp"


int main(int argc, char *argv[]) {

    (void) argc;

    try {
        if(argc != 2)
          throw std::runtime_error("missing or too many arguments");

        ScalarConverter test(argv[1]);


        // // Example 1: Generating NaN using division
        // double nanValue1 = 0.0 / 0.0;

        // // Example 2: Using the predefined constant NAN
        // float nanValue2 = NAN;

        // // Example 3: Using operations that result in NaN
        // double nanValue3 = sqrt(-1.0);

        // // Example 4: Creating a float version (nanf)
        // float nanValueFloat = std::sqrt(-1.0f); // NaN using invalid operation

        // // Display the results
        // std::cout << "NaN (0.0 / 0.0): " << nanValue1 << std::endl;
        // std::cout << "NAN constant: " << nanValue2 << std::endl;
        // std::cout << "NaN (sqrt(-1.0)): " << nanValue3 << std::endl;
        // std::cout << "Quiet NaN (float): " << nanValueFloat << std::endl;

    }
    catch (std::exception &e) {
        
        std::cout << "Error: " << e.what() << std::endl;
    }



    
    return (0);
}
