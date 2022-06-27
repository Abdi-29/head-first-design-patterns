/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/27 15:38:59 by abba          #+#    #+#                 */
/*   Updated: 2022/06/27 15:38:59 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class State
{
public:
	State();
	~State();

	void printGrid(std::vector< std::vector<int> > state);
private:
//	int _hScore;
//	int _gScore;
//	int _fScore;
};

#endif