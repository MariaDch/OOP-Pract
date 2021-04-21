#include "Player.h"
#include <iostream>
#include <cstring>

/*template<typename M, typename N>
void Player<M, N>::copy(char* other_Name, size_t other_Wins, size_t other_Loses)
{
	nameOfPlayer = new char[strlen(other_Name) + 1];
	strcpy_s(nameOfPlayer, strlen(other_Name) + 1, other_Name);
	wins = other_Wins;
	loses = other_Loses;
}*/

/*template<typename M, typename N>
void Player<M, N> ::erase()
{
	delete[] nameOfPlayer;
}*/

/*template<typename M, typename N>
Player<M, N>::Player()
{
	nameOfPlayer = new char[6];
	strcpy_s(nameOfPlayer, 6, "Empty");
	wins = 0;
	loses = 0;
}*/

/*template<typename M, typename N>
Player<M, N>::Player(char* other_Name, size_t other_Wins, size_t other_Loses)
{
	this->copy(other_Name, other_Wins, other_Loses);
}

template<typename M, typename N>
Player<M, N>::~Player()
{
	this->erase();
}

template<typename M, typename N>
void Player<M, N>::setNameOfPlayer(const char* _nameOfPlayer)
{
	delete[]nameOfPlayer;
	nameOfPlayer = new char[strlen(_nameOfPlayer) + 1];
	strcpy_s(nameOfPlayer, strlen(_nameOfPlayer) + 1, _nameOfPlayer);
}

template<typename M, typename N>
void Player<M, N>::setWins(size_t _wins)
{
	wins = _wins;
}

template<typename M, typename N>
void Player<M, N>::setLoses(size_t _loses)
{
	loses = _loses;
}

template<typename M, typename N>
void Player<M, N>::setFirstDeck(Deck<M> _firstDeck)
{
	for (int i = 0; i < strlen(_firstDeck); i++)
	{
		firstDeck[i] = _firstDeck[i];
	}
}

template<typename M, typename N>
void Player<M, N>::setSecondDeck(Deck<N> _secondDeck)
{
	for (int i = 0; i < strlen(_secondDeck); i++)
	{
		secondDeck[i] = _secondDeck[i];
	}
}

template<typename M, typename N>
const char* Player<M, N>::getNameOfPlayer() const
{
	return nameOfPlayer;
}

template<typename M, typename N>
size_t Player<M, N>::getWins() const
{
	return wins;
}

template<typename M, typename N>
size_t Player<M, N>::getLoses() const
{
	return loses;
}

template<typename M, typename N>
Deck<M> Player<M, N>::getFirstDeck() const
{
	return Deck<M>(firstDeck);
}

template<typename M, typename N>
Deck<N> Player<M, N>::getSecondDeck() const
{
	return Deck<N>(secondDeck);
}

template<typename M, typename N>
void Player<M, N>::print() const
{
	std::cout << nameOfPlayer;
	std::cout << std::endl;
	std::cout << wins;
	std::cout << std::endl;
	std::cout << loses;
	std::cout << std::endl;
	std::cout << firstDeck.print();
	std::cout << std::endl;
	std::cout << secondDeck.print();
}

template<typename M, typename N>
M Player<M, N>::drawCardFromFirstDeck()
{
	return firstDeck.drawCard();
}

template <typename M, typename N>
N Player<M, N>::drawCardnFromSecondDeck()
{
	return secondDeck.drawCard();
}
template<typename M, typename N>
void Player<M, N>::savePlayer(std::ofstream& out)
{
	out.open();
	if (out.is_open)
	{
		out << nameOfPlayer << '\n';
		out << wins << '\n';
		out << loses << '\n';
	}
	out.close();
}

template <typename M, typename N>
void Player<M, N>::loadPlayer(std::ifstream& in)
{
	char arr[256];
	int index = 0;
	if (in.is_open())
	{
		Player player;
		while (in.getline(arr, 255))
		{
			if (index == 0)
			{
				player.setNameOfPlayer(arr);
			}
			if (index == 1)
			{
				player.setWins(arr);
			}
			if (index == 2)
			{
				player.setLoses(arr);
			}
			index++;
		}
	}
	in.close();
}

template<typename M, typename N>
void Player<M, N>::winner()
{
	wins++;
}

template<typename M, typename N>
void Player<M, N>::loser()
{
	loses++;
}*/
