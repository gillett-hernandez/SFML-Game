#pragma once

class Player
{
public:
    Player(int x, int y, sf::Sprite* sprite);
    ~Player();
    int pos[2];
    sf::Sprite* sprite;
};
