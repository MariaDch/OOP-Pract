#include <iostream>
#include "Player.h"
#include "Deck.h"

void game(Player<FireCard, WaterCard> player1, Player<WindCard, EarthCard> player2)
{
    int player1Points = 0;
    int player2Points = 0;

    WaterCard watercard;
    EarthCard earthcard;
    FireCard firecard;
    WindCard windcard;

    while (player1Points != 5 || player2Points != 5)
    {
        int indexForFirstPlayer = rand() % 1;
        if (indexForFirstPlayer == 0)
        {
            firecard = player1.drawCardFromFirstDeck();
        }
        else
            watercard = player1.drawCardnFromSecondDeck();

        int indexForSecondPlayer = rand() % 1;
        if (indexForSecondPlayer == 0)
        {
            windcard = player2.drawCardFromFirstDeck();
        }
        else earthcard = player2.drawCardnFromSecondDeck();

        if (indexForFirstPlayer == 0 && indexForSecondPlayer == 0)
        {
            if (firecard.getPower() + firecard.getBonusPower() > windcard.getPower())
            {
                player1Points++;
            }

            if (firecard.getPower() + firecard.getBonusPower() < windcard.getPower())
            {
                player2Points++;
            }
        }
        if (indexForFirstPlayer == 1 && indexForSecondPlayer == 1)
        {
            if (earthcard.getPower() + earthcard.getBonusPower() > watercard.getPower())
            {
                player2Points++;
            }
            if (earthcard.getPower() + earthcard.getBonusPower() < watercard.getPower())
            {
                player1Points++;
            }
        }
        else
        {
            if (indexForFirstPlayer == 0 && indexForSecondPlayer == 1)
            {
                if (firecard.getPower() > earthcard.getPower())
                {
                    player1Points++;
                }
                if (firecard.getPower() < earthcard.getPower())
                {
                    player2Points++;
                }
            }
            if (indexForFirstPlayer == 1 && indexForSecondPlayer == 0)
            {
                if (watercard.getPower() > windcard.getPower())
                {
                    player1Points++;
                }
                if (watercard.getPower() < windcard.getPower())
                {
                    player2Points++;
                }
            }
        }
    }

    if (player1Points == 5)
    {
        std::ofstream FirstPlayer("Player1.txt");
        player1.winner();
        player1.savePlayer(FirstPlayer);
        std::ofstream SecondPlayer("Player2.txt");
        player2.loser();
        player2.savePlayer(SecondPlayer);
    }
    else
    {
        std::ofstream FirstPlayer("Player1.txt");
        player1.loser();
        player1.savePlayer(FirstPlayer);
        std::ofstream SecondPlayer("Player2.txt");
        player2.winner();
        player2.savePlayer(SecondPlayer);
    }
}

int main()
{
    //огън > вятър; вода > огън; земя > вода; вятър > земя;

    Player<FireCard, WaterCard> player1;
    std::ifstream FirstPlayer("Player1.txt"); 
    player1.loadPlayer(FirstPlayer, player1);

    Player<WindCard, EarthCard> player2;
    std::ifstream SecondPlayer("Player2.txt");
    player2.loadPlayer(SecondPlayer, player2);

    Deck<FireCard> fireDeck;

    FireCard FireCard1;
    FireCard1.setpower(15);
    FireCard1.setBonusPower(10);
    FireCard1.setFireCardName("FirstFireCard");
    FireCard FireCard2;
    FireCard2.setpower(16);
    FireCard2.setBonusPower(15);
    FireCard2.setFireCardName("SecondFireCard");
    FireCard FireCard3;
    FireCard3.setpower(19);
    FireCard3.setBonusPower(33);
    FireCard3.setFireCardName("ThirdFireCard");
    FireCard FireCard4;
    FireCard4.setpower(28);
    FireCard4.setBonusPower(42);
    FireCard4.setFireCardName("FourthFireCard");

    fireDeck.addCard(FireCard1);
    fireDeck.addCard(FireCard2);
    fireDeck.addCard(FireCard3);
    fireDeck.addCard(FireCard4);

    Deck<WaterCard> waterDeck;

    WaterCard WaterCard1;
    WaterCard1.setPower(21);
    WaterCard1.setBonusPower(12);
    WaterCard1.setWaterCardName("FirstWaterCard");
    WaterCard WaterCard2;
    WaterCard2.setPower(20);
    WaterCard2.setBonusPower(21);
    WaterCard2.setWaterCardName("SecondWaterCard");
    WaterCard WaterCard3;
    WaterCard3.setPower(50);
    WaterCard3.setBonusPower(50);
    WaterCard3.setWaterCardName("ThirdWaterCard");
    WaterCard WaterCard4;
    WaterCard4.setPower(50);
    WaterCard4.setBonusPower(49);
    WaterCard4.setWaterCardName("FourthWaterCard");

    waterDeck.addCard(WaterCard1);
    waterDeck.addCard(WaterCard2);
    waterDeck.addCard(WaterCard3);
    waterDeck.addCard(WaterCard4);
    
    Deck<WindCard> windDeck;

    WindCard WindCard1;
    WindCard1.setPower(18);
    WindCard1.setBonusPower(15);
    WindCard1.setWindCardName("FirstWindCard");
    WindCard WindCard2;
    WindCard2.setPower(25);
    WindCard2.setBonusPower(36);
    WindCard2.setWindCardName("SecondWindCard");
    WindCard WindCard3;
    WindCard3.setPower(96);
    WindCard3.setBonusPower(69);
    WindCard3.setWindCardName("ThirdWindCard");
    WindCard WindCard4;
    WindCard4.setPower(25);
    WindCard4.setBonusPower(36);
    WindCard4.setWindCardName("FourthWindCard");

    windDeck.addCard(WindCard1);
    windDeck.addCard(WindCard2);
    windDeck.addCard(WindCard3);
    windDeck.addCard(WindCard4);
    
    Deck<EarthCard> earthDeck;

    EarthCard earthCard1;
    earthCard1.setPower(69);
    earthCard1.setBonusPower(96);
    earthCard1.setEarthCardName("FirstWindCard");
    EarthCard earthCard2;
    earthCard2.setPower(12);
    earthCard2.setBonusPower(54);
    earthCard2.setEarthCardName("SecondWindCard");
    EarthCard earthCard3;
    earthCard3.setPower(18);
    earthCard3.setBonusPower(29);
    earthCard3.setEarthCardName("ThirdWindCard");
    EarthCard earthCard4;
    earthCard4.setPower(27);
    earthCard4.setBonusPower(76);
    earthCard4.setEarthCardName("FourthWindCard");

    earthDeck.addCard(earthCard1);
    earthDeck.addCard(earthCard2);
    earthDeck.addCard(earthCard3);
    earthDeck.addCard(earthCard4);


    WaterCard1.printCard();
    std::cout << std::endl;
    WaterCard2.printCard();
    std::cout << std::endl;
    WaterCard3.printCard();
    std::cout << std::endl;
    WaterCard4.printCard();
    std::cout << std::endl;

    game(player1, player2);
}