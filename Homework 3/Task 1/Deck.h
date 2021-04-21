#pragma once
#include "EarthCard.h"
#include "WaterCard.h"
#include "FireCard.h"
#include "WindCard.h"

template <typename T>
class Deck
{
private:
	size_t size;
	T Cards[30];

	void copy(const Deck& other_deck);
public:
	Deck();
	Deck(const Deck& other_deck);
	Deck& operator=(const Deck& other_deck);
	friend Deck<T> operator+(const Deck& deck, T card)
	{
		deck.addCard(card);
		return deck;
	}
	Deck& operator+=(T card);

	bool duplicatedCards(T& _card);
	void shuffle();
	void drawCard();
	void addCard(T new_card);
};

