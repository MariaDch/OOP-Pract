#pragma once
class WaterCard
{
private:
	char* WaterCardName;
	size_t power;
	size_t bonusPower;
	int type = 1;

	void copy(const WaterCard& other_waterCard);
	void erase();
public:
	WaterCard();
	WaterCard(const WaterCard& other_waterCard);
	WaterCard& operator=(const WaterCard& other_waterCard);
	bool operator==(const WaterCard& other_waterCard);
	~WaterCard();

	void setWaterCardName(const char* _waterCardName);
	void setPower(size_t _power);
	void setBonusPower(size_t _bonusPower);

	const char* getName() const;
	size_t getPower() const;
	size_t getBonusPowe() const;

	void printCard() const;
};

