/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:19:38 by misaev            #+#    #+#             */
/*   Updated: 2022/03/21 17:36:03 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::nbr_bit = 8;

Fixed::Fixed()
{
    this->fix = 0;
    return;
}

Fixed::Fixed(int const a)
{
    this->fix = a << this->nbr_bit;
}

Fixed::Fixed(float const b)
{
    this->fix = (int)(round(b * (1 << this->nbr_bit)));
}

int Fixed::getRawBits(void) const
{
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

/* SURCHARGE OPERATEUR */
void Fixed::operator=(const Fixed &p)
{
    this->fix = p.fix;
    this->nbr_bit = p.nbr_bit;
}

Fixed Fixed::operator+(const Fixed &p) const
{
    return Fixed(this->fix + p.getRawBits());
}

Fixed Fixed::operator-(const Fixed &p) const
{
    return Fixed(this->fix - p.getRawBits());
}

Fixed Fixed::operator*(const Fixed &p) const
{
    return this->toFloat() * p.toFloat();
}

Fixed Fixed::operator/(const Fixed &p) const
{
    return this->toFloat() / p.toFloat();
}

bool Fixed::operator!=(const Fixed &p) const
{
    if (this->fix != p.getRawBits())
        return true;
    else return false;
}

bool Fixed::operator<=(const Fixed &p) const
{
    if (this->fix <= p.getRawBits())
        return true;
    else return false;
}

bool Fixed::operator<(const Fixed &p) const
{
    if (this->fix < p.getRawBits())
        return true;
    else return false;
}

bool Fixed::operator>=(const Fixed &p) const
{
    if (this->fix >= p.getRawBits())
        return true;
    else return false;
}

bool Fixed::operator>(const Fixed &p) const
{
    if (this->fix > p.getRawBits())
        return true;
    else return false;   
}

bool Fixed::operator==(const Fixed &p) const
{
    if (this->fix == p.getRawBits())
        return true;
    else return false;
}

Fixed &Fixed::operator++()
{
    this->fix++;
    return *this;
}

Fixed &Fixed::operator--()
{
    this->fix--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++*this;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    --*this;
    return tmp;
}

/* END */

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
   if (a < b)
        return a;
   else return b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a < b)
        return a;
    else return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    else return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a > b)
        return a;
    else return b;
}

Fixed::~Fixed()
{
    return;
}

std::ostream &operator<<(std::ostream &b, Fixed const &c)
{
    b << c.toFloat();
    return b;
}