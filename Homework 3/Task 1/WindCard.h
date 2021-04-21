#pragma once
class WindCard
{
private:
	char* WindCardName;
	size_t power;
	size_t bonusPower;
	int type = 4;

	void copy(const WindCard& other_windCard);
	void erase();
public:
	WindCard();
	WindCard(const WindCard& other_windCard);
	WindCard& operator=(const WindCard& other_windCard);
	bool operator==(const WindCard& other_windCard);
	~WindCard();

	void setWindCardName(const char* _name);
	void setPower(size_t _power);
	void setBonusPower(size_t _bonusPower);

	const char* getName() const;
	size_t getPower() const;
	size_t getBonusPower() const;

	void printCard() const;
};

