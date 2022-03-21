/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:19:38 by misaev            #+#    #+#             */
/*   Updated: 2022/03/18 14:43:52 by misaev           ###   ########.fr       */
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

Fixed::Fixed(Fixed const &p)
{
    std::cout << "Copy constructor called\n";
    this->fix = p.fix;
}

Fixed::Fixed(int const a)
{
    std::cout << "Int constructor called\n";
    this->fix = a << this->nbr_bit;
}

Fixed::Fixed(float const b)
{
    std::cout << "Float constructor called\n";
    this->fix = (round(b * (1 << this->nbr_bit)));
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

int Fixed::toInt(void) const
{
    return this->fix >> this->nbr_bit;
}

float Fixed::toFloat(void) const
{
    return ((float)this->fix / (float)(1 << this->nbr_bit));
}


void Fixed::operator=(const Fixed &p)
{
    std::cout << "Copy assignment operator called\n";
    this->fix = p.fix;
    this->nbr_bit = p.nbr_bit;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
    return;
}

std::ostream &operator<<(std::ostream &b, Fixed const &c)
{
    b << c.toFloat();
    return b;
}