/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:18:07 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/16 23:38:34 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    // Vérifie le nombre d'arguments
	{
        std::cout << "Usage: ./harlFilter <level>" << std::endl;
        return 1;
    }

    Harl harl;
    harl.filterComplain(argv[1]);
    // Crée une instance de Harl et applique le filtre

    return 0;
}