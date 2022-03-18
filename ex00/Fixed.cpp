/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:19:38 by misaev            #+#    #+#             */
/*   Updated: 2022/03/18 12:01:48 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::nbr_bit = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    this->fix = 0;
    return;
}

Fixed::Fixed(const Fixed &p)
{
    std::cout << "Copy constructor called\n";
    this->fix = p.fix;
    this->nbr_bit = p.nbr_bit;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return this->fix;   
}

void Fixed::setRawBits(int const raw)
{
    this->fix = raw;
}

void Fixed::operator=(const Fixed &p)
{
    std::cout << "Copy assignment operator called\n";
    this->fix = p.getRawBits();
    this->nbr_bit = p.nbr_bit;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
    return;
}