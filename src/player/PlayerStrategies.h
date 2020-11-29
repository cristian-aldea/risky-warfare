#pragma once

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::ostream;

class Player;
class Map;
class Territory;
class Deck;

class PlayerStrategy {
private:
    Player *player;
public:
    PlayerStrategy(Player *player);
    friend ostream &operator<<(ostream &out, const PlayerStrategy &obj);

    virtual void issueOrder(Map *map,
                            Deck *deck,
                            vector<Player *> activePlayers) = 0;
    virtual vector<Territory *> toAttack(Map *map) = 0;
    virtual vector<Territory *> toDefend(Map *map) = 0;
    virtual PlayerStrategy *clone() = 0;
    virtual ostream &print(ostream &out) const = 0;

    virtual ~PlayerStrategy();
};

class HumanPlayerStrategy : public PlayerStrategy {
public:
    HumanPlayerStrategy(Player *player);

    void issueOrder(Map *map,
                    Deck *deck,
                    vector<Player *> activePlayers) override;
    vector<Territory *> toAttack(Map *map) override;
    vector<Territory *> toDefend(Map *map) override;
    PlayerStrategy *clone() override;
    ostream &print(ostream &out) const override;
};

class AggressivePlayerStrategy : public PlayerStrategy {
public:
    AggressivePlayerStrategy(Player *player);

    void issueOrder(Map *map,
                    Deck *deck,
                    vector<Player *> activePlayers) override;
    vector<Territory *> toAttack(Map *map) override;
    vector<Territory *> toDefend(Map *map) override;
    PlayerStrategy *clone() override;
    ostream &print(ostream &out) const override;
};

class BenevolentPlayerStrategy : public PlayerStrategy {
public:
    BenevolentPlayerStrategy(Player *player);

    void issueOrder(Map *map,
                    Deck *deck,
                    vector<Player *> activePlayers) override;
    vector<Territory *> toAttack(Map *map) override;
    vector<Territory *> toDefend(Map *map) override;
    PlayerStrategy *clone() override;
    ostream &print(ostream &out) const override;
};

class NeutralPlayerStrategy : public PlayerStrategy {
public:
    NeutralPlayerStrategy(Player *player);

    void issueOrder(Map *map,
                    Deck *deck,
                    vector<Player *> activePlayers) override;
    vector<Territory *> toAttack(Map *map) override;
    vector<Territory *> toDefend(Map *map) override;
    PlayerStrategy *clone() override;
    ostream &print(ostream &out) const override;
};
