#pragma once
#include "Deck.h"
#include <fstream>      //files
#include <iostream>

template <typename M, typename N>
class Player
{
private:
	char* nameOfPlayer;
	size_t wins;
	size_t loses;
	Deck<M> firstDeck;
	Deck<N> secondDeck;

	void copy(char* other_Name, size_t other_Wins, size_t other_loses)
	{
		nameOfPlayer = new char[strlen(other_Name) + 1];
		strcpy_s(nameOfPlayer, strlen(other_Name) + 1, other_Name);
		wins = other_Wins;
		loses = other_loses;
	}

	void erase()
	{
		delete[] nameOfPlayer;
	}

public:
	Player()
	{
		nameOfPlayer = new char[6];
		strcpy_s(nameOfPlayer, 6, "Empty");
		wins = 0;
		loses = 0;
	}

	Player(char* other_Name, size_t other_Wins, size_t other_Loses)
	{
		this->copy(other_Name, other_Wins, other_Loses);
	}

	/*Player& operator=(char* other_Name, size_t other_Wins, size_t other_Loses)
	{
		if (this != &other_player)
		{
			this->erase();
			this->copy(other_Name, other_Wins, other_loses);
		}
		return *this;
	}*/

	~Player()
	{
		this->erase();
	}

	void setNameOfPlayer(const char* _nameOfPlayer)
	{
		delete[]nameOfPlayer;
		nameOfPlayer = new char[strlen(_nameOfPlayer) + 1];
		strcpy_s(nameOfPlayer, strlen(_nameOfPlayer) + 1, _nameOfPlayer);
	}

	void setWins(size_t _wins)
	{
		wins = _wins;
	}
	void setLoses(size_t _loses)
	{
		loses = _loses;
	}
	void setFirstDeck(Deck<M> _firstDeck)
	{
		for (int i = 0; i < strlen(_firstDeck); i++)
		{
			firstDeck[i] = _firstDeck[i];
		}
	}

	void setSecondDeck(Deck<N> _secondDeck)
	{
		for (int i = 0; i < strlen(_secondDeck); i++)
		{
			secondDeck[i] = _secondDeck[i];
		}
	}

	const char* getNameOfPlayer() const
	{
		return nameOfPlayer;
	}
	size_t getWins() const
	{
		return wins;
	}
	size_t getLoses() const
	{
		return loses;
	}
	Deck<M> getFirstDeck() const
	{
		return Deck<M>(firstDeck);
	}
	Deck<N> getSecondDeck() const
	{
		return secondDeck;
	}

	void print()const
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

	M drawCardFromFirstDeck()
	{
		return firstDeck.drawCard();
	}

	N drawCardnFromSecondDeck()
	{
		return secondDeck.drawCard();
	}
	void savePlayer(std::ofstream& out)
	{
			out << nameOfPlayer << '\n';
			out << wins << '\n';
			out << loses << '\n';

		out.close();
	}

	void loadPlayer(std::ifstream& in,Player player)
	{
		char arr[256];
		int index = 0;
		if (in.is_open())
		{
			while (in.getline(arr, 255))
			{
				if (index == 0)
				{
					player.setNameOfPlayer(arr);
				}
				if (index == 1)
				{
					in>>wins;
				}
				if (index == 2)
				{
					in>>loses;
				}
				index++;
			}
		}
		in.close();
	}

	void winner()
	{
		wins++;
	}
	void loser()
	{
		loses++;
	}
};

