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
#include <algorithm>

using namespace std;

class State
{
public:
	State();
	State(vector<vector<int> >& grid) : _initialState(grid) {}
	~State();

	void					printGrid(vector< vector<int> > state) const;
	vector< vector<int> >	getInitialState(string input);
	void					getGoalState(string input);
	vector< vector<int> >	getGrid(string input);
	void					misplacedTiles();
	void					findEmptyIndex();
	void					test(const State &state);
	vector< State>			move() const;
	void					initVector();

protected:
	int _hScore;
	size_t _x;
	size_t _y;
	vector< vector<int> > _initialState;
	vector< vector<int> > _goalState;
	vector< vector<int> > _up;
	vector< vector<int> > _down;
	vector< vector<int> > _left;
	vector< vector<int> > _right;
};

#endif