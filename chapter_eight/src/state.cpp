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

void State::printGrid(std::vector<std::vector<int> > state)
{
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < state[i].size(); ++j)
			cout << state[i][j] << ' ';
		cout << endl;
	}
}

int main(int argc, char **argv)
{
	State state;
	std::string line;
	vector< vector<int> > initialState;
	vector< vector<int> > goalState;
	vector<int> row;

	if (argc != 2)
	{
		cout << "invalid argument\n";
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file)
	{
		cout << "invalid file\n";
		return 2;
	}
	while (getline(file, line))
	{
		remove(line.begin(), line.end(), ' ');
		for (int i = 0; i < 3; ++i)
		{
			row.push_back((int)line[i] - '0');
		}
		initialState.push_back(row);
		row.clear();
	}
	state.printGrid(initialState);
}