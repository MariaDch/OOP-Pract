#pragma once
#include "Deck.h"
#include <fstream>      //files

template <typename M, typename N>
class Player
{
private:
	char* nameOfPlayer;
	size_t wins;
	size_t loses;
	Deck<M> firstDeck;
	Deck<N> secondDeck;

	void copy(char* other_Name, size_t other_Wins, size_t other_loses);
	void erase();
public:
	Player();
	Player(char* other_Name, size_t other_Wins, size_t other_Loses);
	/*Player& operator=(char* other_Name, size_t other_Wins, size_t other_Loses)
	{
		if (this != &other_player)
		{
			this->erase();
			this->copy(other_Name, other_Wins, other_loses);
		}
		return *this;
	}*/
	~Player();

	void setNameOfPlayer(const char* _nameOfPlayer);
	void setWins(size_t _wins);
	void setLoses(size_t loses);
	void setFirstDeck(Deck<M> _firstDeck);
	void setSecondDeck(Deck<N> _secondDeck);

	const char* getNameOfPlayer() const;
	size_t getWins() const;
	size_t getLoses() const;
	Deck<M> getFirstDeck() const;
	Deck<N> getSecondDeck() const;

	void print()const;
	M drawCardFromFirstDeck();
	N drawCardnFromSecondDeck();
	void savePlayer(std::ofstream& out);
	void loadPlayer(std::ifstream& in);

	void winner();
	void loser();
};

