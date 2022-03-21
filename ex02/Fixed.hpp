/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:33:09 by misaev            #+#    #+#             */
/*   Updated: 2022/03/21 17:30:22 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(int const a);
        Fixed(float const b);
        float toFloat( void ) const;
        int toInt( void ) const;
        void operator=(const Fixed &p);
        Fixed &min(Fixed &a, Fixed &b);
        static Fixed const &min(Fixed const &a, Fixed const &b);
        Fixed &max(Fixed &a, Fixed &b);
        static Fixed const &max(Fixed const &a, Fixed const &b);
        Fixed &operator++();
        Fixed &operator--();
        Fixed operator++(int);
        Fixed operator--(int);
        Fixed operator/(const Fixed &p) const;
        Fixed operator-(const Fixed &p) const;
        Fixed operator+(const Fixed &p) const;
        Fixed operator*(const Fixed &p) const;
        bool operator>(const Fixed &p) const;
        bool operator<(const Fixed &p) const;
        bool operator>=(const Fixed &p) const;
        bool operator<=(const Fixed &p) const;
        bool operator==(const Fixed &p) const;
        bool operator!=(const Fixed &p) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
        ~Fixed();
    private:
        int fix;
        int static nbr_bit;
};

std::ostream &operator<<(std::ostream &b, Fixed const &c);