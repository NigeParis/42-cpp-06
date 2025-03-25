/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nige42 <nige42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:06:58 by nrobinso          #+#    #+#             */
/*   Updated: 2025/03/25 09:18:19 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ScalarConverter.hpp"

int main(int argc, char *argv[]) {

    try {
        if(argc != 2)
          throw std::runtime_error("missing or too many arguments");

        ScalarConverter test(argv[1]);
    }
    catch (std::exception &e) {
        
        std::cout << "Error: " << e.what() << std::endl;
    }    
    return (0);
}
