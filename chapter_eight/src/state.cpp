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

State::State() {
	std::cout << "constructor called\n";
}

State::~State() {
	std::cout << "deconstruct called\n";
}

void State::printGrid()
{
	std::vector<std::vector<int> > state;

	state = _initialState;
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < state[i].size(); ++j)
			cout << state[i][j] << ' ';
		cout << endl;
	}
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

void State::getInitialState(string input)
{
	_initialState = getGrid(input);
}

void State::getGoalState(string input)
{
	_goalState = getGrid(input);
}

int main(int argc, char **argv)
{
	State state;

	if (argc != 2)
	{
		cout << "invalid argument\n";
		return 1;
	}
	state.getInitialState(argv[1]);
	state.getGoalState("goal_map1");
	state.printGrid();
}