#pragma once
class EarthCard
{
private:
	char* EarthCardName;
	size_t power;
	size_t bonusPower;
	int type = 3;

	void copy(const EarthCard& other_earthCard);
	void erase();
public:
	EarthCard();
	EarthCard(const EarthCard& other_earthCard);
	EarthCard& operator=(const EarthCard& other_earthCard);
	bool operator==(const EarthCard& other_earthCard);
	~EarthCard();

	void setEarthCardName(const char* _name);
	void setPower(size_t _power);
	void setBonusPower(size_t _bonusPower);

	const char* getName() const;
	size_t getPower() const;
	size_t getBonusPower() const;

	void printCard() const;
};

