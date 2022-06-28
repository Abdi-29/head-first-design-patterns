/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manhattan.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 18:36:02 by abba          #+#    #+#                 */
/*   Updated: 2022/06/28 18:36:02 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANHATTAN_HPP
#define MANHATTAN_HPP

#include "state.hpp"

class Manhattan: public State
{
public:
	Manhattan(vector<vector<int> >& grid) : State(grid) {}
	int heuristic(int x, int y)
	{
		return abs(_goalX - x) + abs(_goalY - y);
	}

	int manhattan(int x, int y)
	{
		for (size_t i = 0; i < _goalState.size(); ++i)
		{
			for (size_t j = 0; j < _goalState[i].size(); ++j)
			{
				if (_initialState[x][y] == _goalState[i][j])
				{
					return heuristic(x, y);
				}
			}
		}
	}

	int	distance(const vector<vector<int> > grid)
	{
		int	h = 0;
		for (size_t i = 0; i < _initialState.size(); ++i)
		{
			for (size_t j = 0; j < _initialState[i].size(); ++j)
			{
				_goalX = i;
				_goalY = j;
				h += manhattan(i, j);
			}
		}
		return h;
	}
private:
	int		_goalX;
	int		_goalY;
	size_t	_upScore;
	size_t	_downScore;
	size_t	_leftScore;
	size_t	_rightScore;
};

#endif
