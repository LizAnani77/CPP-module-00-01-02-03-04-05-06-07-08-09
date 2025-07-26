/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:38:37 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 15:10:34 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main()
{
    Harl harl;
    
    std::cout << "[ DEBUG ]" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    
    std::cout << "[ INFO ]" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    
    std::cout << "[ WARNING ]" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    
    std::cout << "[ ERROR ]" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    
    std::cout << "[ INVALID ]" << std::endl;
    harl.complain("INVALID");
    
    return 0;
}

// int main(int argc, char **argv)
// {
//     Harl harl;
    
//     if (argc == 2)
//     {
//         std::cout << "[ " << argv[1] << " ]" << std::endl;
//         harl.complain(argv[1]);
//     }
//     else
//     {
//         std::cout << "[ DEBUG ]" << std::endl;
//         harl.complain("DEBUG");
//         std::cout << std::endl;
        
//         std::cout << "[ INFO ]" << std::endl;
//         harl.complain("INFO");
//         std::cout << std::endl;
        
//         std::cout << "[ WARNING ]" << std::endl;
//         harl.complain("WARNING");
//         std::cout << std::endl;
        
//         std::cout << "[ ERROR ]" << std::endl;
//         harl.complain("ERROR");
//         std::cout << std::endl;
//     }
//     return 0;
// }