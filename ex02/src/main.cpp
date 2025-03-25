/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nige42 <nige42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:06:58 by nrobinso          #+#    #+#             */
/*   Updated: 2025/03/25 09:05:39 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "./include/A.hpp"
#include "./include/B.hpp"
#include "./include/C.hpp"

Base *generate(void) {

    int result  = rand() % 3;
    Base *basePtr;

    switch(result) {
        case 0:
            basePtr = new A;
            return (basePtr);
        case 1:
            basePtr = new B;
            return (basePtr);
        case 2:
            basePtr = new C;
            return (basePtr); 
    }
    return (NULL);
};

void identify(Base* ptr) {

    if (dynamic_cast<A*>(ptr)) {
        std::cout << "A" << std::endl; 
        return ;
    }
    if (dynamic_cast<B*>(ptr)) {
        std::cout << "B" << std::endl; 
        return ;
    }
    if (dynamic_cast<C*>(ptr)) {
        std::cout << "C" << std::endl; 
        return ;
    }
};


void identify(Base& ptr) {
    try {
        A &a = dynamic_cast<A&>(ptr);
        (void) a;
        std::cout << "A" << std::endl;
    }
    catch(std::bad_cast &exception) {}
    try {
        B &b = dynamic_cast<B&>(ptr);
        (void) b;
        std::cout << "B" << std::endl;
    }
    catch(std::bad_cast &exception) {}
    try {
        C &c = dynamic_cast<C&>(ptr);
        (void) c;
        std::cout << "C" << std::endl;
    }
    catch(std::bad_cast &exception) {}
}

int main(void) {
    {
        srand(time(0));
        Base *test;
        std::cout << "------------------------- test: 1 generate() -------------------------" << std::endl;
        test = generate();
        if (test)
            std::cout << "test genrated address: " << test << std::endl;
        delete test;
    }
    {
        Base *test2;
        test2 = generate();
        std::cout << "------------------------- test: 2 identity(*p) -----------------------" << std::endl;
        std::cout << "test 2 generated the identity: "; 
        identify(test2);        
        delete test2;
    }
    {
        Base *test3;
        test3 = generate();
        std::cout << "------------------------- test: 3 identity(&p) -----------------------" << std::endl;
        std::cout << "test 3 generated the identity: "; 
        identify(*test3);        
        delete test3;
    }
    return (0);
}
