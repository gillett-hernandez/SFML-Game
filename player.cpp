#include <SFML/Graphics.hpp>
#include "player.hpp"

Player::Player(int x, int y, sf::Sprite& sprite) {
    this->pos[0] = x;
    this->pos[1] = y;
    this->sprite = sprite;
    this->updateSprite();
}

void Player::setPosition(int x, int y){
    this->pos[0] = x;
    this->pos[1] = y;
    this->updateSprite();
}
int* Player::getPosition(){
    return this->pos;
}

void Player::updateSprite() {
    this->sprite.setPosition(this->pos[0], this->pos[1]);
}
