/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:33:09 by misaev            #+#    #+#             */
/*   Updated: 2022/03/18 10:29:21 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(int const a);
        Fixed(float const b);
        Fixed(const Fixed &p);
        float toFloat( void ) const;
        int toInt( void ) const;
        void operator=(const Fixed &p);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        ~Fixed();
    private:
        int fix;
        int static nbr_bit;
};