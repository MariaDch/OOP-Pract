#include "Deck.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>      //rand

template <typename T>
void Deck<T>::copy(const Deck& other_deck)
{
	Cards = new T[30];
	size = other_deck.size;

	for (size_t i = 0; i < size; i++)
	{
		Cards[i] = other_deck.Cards[i];
	}
}

template <typename T>
Deck<T>::Deck()
{
	size = 0;
}

template <typename T>
Deck<T>::Deck(const Deck& other_deck)
{
	this->copy(other_deck);
}

template <typename T>
Deck <T>& Deck<T>::operator=(const Deck& other_deck)
{
	if (this != &other_deck)
	{
		delete[] Cards;
		this->copy(other_deck);
	}
	return*this;
}
template <typename T>
bool Deck<T>::duplicatedCards(T& _card)
{
	for (int i = 0; i < size; i++)
	{
		if (Cards[i].getName() == _card.getName())
		{
			return true;
		}
	}
	return false;
}

template <typename T>
void Deck<T>::shuffle()              //נאבמעט לאי ;ה
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

template <typename T>
void Deck<T>::drawCard()      //נאבמעט לאיי 
{
	Cards[0].printCard();

	T temp[1] = 0;
	temp[0] = Cards[0];
	for (size_t i = 0; i < size; i++)
	{
		Cards[i] = Cards[i + 1];
	}
	Cards[size] = temp[0];
}


template <typename T>
void Deck<T>::addCard(T new_card)
{
	size++;
	if (size <= 30 && duplicatedCards(new_card) == false)
	{
		Cards[size] = new_card;
	}
	else
		std::cout << "Not enough space for new card.You already have 30 cards in your Deck";
}

template <typename T>
Deck<T>& Deck<T>::operator+=(T card)
{
	addCard(card);
	return Cards;
}