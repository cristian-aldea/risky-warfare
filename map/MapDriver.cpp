#include <iostream>
#include <string>
#include <vector>

#include "Map.h"
#include "../player/Player.h"

using std::cout;

int main()
{
    // TODO: Valid map

    // TODO: Invalid map: Map not graph

    // TODO: Invalid map: Continent not subgraph

    // TODO: Invalid map: Continent missing for one territory.
    Map newMap = Map("newMap");

    Player *player1 = new Player("player1");
    Player *player2 = new Player("player2");

    Continent *cont1 = new Continent("cont1", 1);
    Continent *cont2 = new Continent("cont2", 1);

    newMap.addTerritory(1, "t1", cont1, player1, 1);
    newMap.addTerritory(2, "t2", cont1, player1, 1);
    newMap.addTerritory(3, "t3", cont2, player2, 1);
    newMap.addTerritory(4, "t4", cont2, player2, 1);

    vector<Territory *> territories(newMap.getTerritories().begin(), newMap.getTerritories().end());

    newMap.addConnection(territories.at(0)->getId(), territories.at(1)->getId());
    newMap.addConnection(territories.at(0)->getId(), territories.at(2)->getId());
    newMap.addConnection(territories.at(0)->getId(), territories.at(3)->getId());
    newMap.addConnection(territories.at(2)->getId(), territories.at(3)->getId());

    cout << newMap;

    return 0;
}