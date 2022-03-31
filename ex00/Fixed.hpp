/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:33:09 by misaev            #+#    #+#             */
/*   Updated: 2022/03/31 13:04:36 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &p);
        Fixed &operator=(const Fixed &p);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        ~Fixed();
    private:
        int fix;
        int static nbr_bit;
};