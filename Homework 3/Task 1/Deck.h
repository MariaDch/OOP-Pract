#pragma once
#include <iostream>
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

	void copy(const Deck& other_deck)
	{
		size = other_deck.size;

		for (size_t i = 0; i < size; i++)
		{
			Cards[i] = other_deck.Cards[i];
		}
	}

public:
	Deck()
	{
		size = 0;
	}

	Deck(const Deck& other_deck)
	{
		copy(other_deck);
	}

	~Deck()
	{
		delete[] Cards;
	}

	Deck& operator=(const Deck& other_deck)
	{
		if (this != &other_deck)
		{
			delete[] Cards;
			this->copy(other_deck);
		}
		return*this;
	}

	friend Deck<T> operator+(const Deck& deck, T card)
	{
		deck.addCard(card);
		return deck;
	}

	Deck& operator+=(T card)
	{
		addCard(card);
		return Cards;
	}

	/*bool duplicatedCards(T& _card)
	{
		for (int i = 0; i < size; i++)
		{
			if (Cards[i].getName() == _card[i].getName())
			{
				return true;
			}
		}
		return false;
	}
	*/
	void shuffle()
	{
		size_t index = 0;
		for (size_t i = 0; i < size; i++)
		{
			index = rand() % size - 1;
			T temporary = Cards[i];
			Cards[i] = Cards[index];
			Cards[index] = temporary;
		}
	}

	T drawCard()
	{
		Cards[0].printCard();
		T help = Cards[0];
		T temp = Cards[0];
		for (size_t i = 0; i < size; i++)
		{
			Cards[i] = Cards[i + 1];
		}

		Cards[size] = temp;
		return help;
	}

	void addCard(T new_card)
	{
		size++;
		if (size <= 30 )
		{
			Cards[size] = new_card;
		}
		else
			std::cout << "Not enough space for new card.You already have 30 cards in your Deck";
	}
};