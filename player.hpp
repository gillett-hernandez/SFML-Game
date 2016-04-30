#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(int x, int y, sf::Sprite& sprite);
    ~Player();
    void setPosition(int x, int y);
    int* getPosition();
    void updateSprite();

    int pos[2];
    sf::Sprite sprite;
};
// PLAYER_H
#endif
