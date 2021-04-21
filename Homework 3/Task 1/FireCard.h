#pragma once
class FireCard
{
private:
	char* FireCardName;
	size_t power;
	size_t bonusPower;
	int type = 2;

	void copy(const FireCard& other_fireCard);
	void erase();
public:
	FireCard();
	FireCard(const FireCard& other_fireCard);
	FireCard& operator=(const FireCard& other_fireCard);
	bool operator==(const FireCard& other_fireCard);
	~FireCard();

	void setFireCardName(const char* other_fireCardName);
	void setpower(size_t other_power);
	void setBonusPower(size_t other_bonusPower);

	const char* getFireCardName() const;
	size_t getPower() const;
	size_t getBonusPower() const;

	void printCard() const;
};


