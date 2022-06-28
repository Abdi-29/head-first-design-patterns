/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/27 15:43:26 by abba          #+#    #+#                 */
/*   Updated: 2022/06/27 15:43:26 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.hpp"
#include "../include/manhattan.hpp"

State::State() {
	std::cout << "constructor called\n";
}

State::~State() {
	std::cout << "deconstruct called\n";
}

void State::printGrid(vector< vector<int> > state) const
{
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < state[i].size(); ++j)
			cout << state[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

vector<vector<int>> State::getGrid(string input)
{
	vector<int> row;
	std::string line;
	vector< vector<int> > grid;

	std::ifstream file(input);
	if (!file)
	{
		cout << "invalid file\n";
		exit(1);
	}
	while (getline(file, line))
	{
		remove(line.begin(), line.end(), ' ');
		for (int i = 0; i < 3; ++i)
		{
			row.push_back((int)line[i] - '0');
		}
		grid.push_back(row);
		row.clear();
	}
	return grid;
}

vector<vector<int> > State::getInitialState(string input)
{
	return getGrid(input);
}

void State::getGoalState(string input)
{
	_goalState = getGrid(input);
}

void State::misplacedTiles()
{
	_hScore = 0;
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < _initialState[i].size(); ++j)
		{
			if (_initialState[i][j] != _goalState[i][j])
				_hScore++;
		}
	}
}

void	State::findEmptyIndex()
{
	for (size_t i = 0; i < _initialState.size(); ++i)
	{
		for (size_t j = 0; j < _initialState[i].size(); ++j)
		{
			if (_initialState[i][j] == 0)
			{
				_x = i;
				_y = j;
			}
		}
	}
}

void	State::initVector()
{
	_up = _initialState;
	_down = _initialState;
	_left = _initialState;
	_right = _initialState;
}

void	State::test(const State &state)
{
	findEmptyIndex();
	if (_x > 0)
	{
		_up = _initialState;
		cout << "debugging " << _x << " " << _y << endl;
		swap(_up[_x][_y], _up[_x - 1][_y]);
	}
	if (_x < 2)
	{
		_down = _initialState;
		swap(_down[_x][_y], _down[_x + 1][_y]);
	}
	if (_y > 0)
	{
		cout << "im here\n";
		_left = _initialState;
		swap(_left[_x][_y], _left[_x][_y - 1]);
	}
	if (_y < 2)
	{
		_right = _initialState;
		swap(_right[_x][_y], _right[_x][_y + 1]);
	}
	state.printGrid(_initialState);
	state.printGrid(_up);
	state.printGrid(_down);
	if (_left.size())
		state.printGrid(_left);
	state.printGrid(_right);
}

int main(int argc, char **argv)
{
	State state;
	vector<vector<int> > grid;

	if (argc != 2)
	{
		cout << "invalid argument\n";
		return 1;
	}
	state.getInitialState(argv[1]);
	state.getGoalState("goal_map1");
	state.misplacedTiles();
	state.test(state);
//	state.printGrid();
}