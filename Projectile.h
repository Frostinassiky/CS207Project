//
// Created by Mengmeng Xu on 11/18/17.
//

#ifndef TANKCRAFT_PROJECTILE_H
#define TANKCRAFT_PROJECTILE_H

#include <iostream>
#include "Entity.h"
#include "Tank.h"
class Projectile : public Entity {

private:
    Tank::Type mType;
    sf::Sprite mSprite;
    sf::Vector2f mTargetDir;
    sf::Texture mTexture;

private:
    virtual void updateCurrent(sf::Time dt) {
        Entity::updateCurrent(dt);
        // std::cout << "move~ " << this->getVelocity().y ;
    }

    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    Projectile(Tank::Type type);
    float getMaxSpeed() const { return 200.f; };
    virtual sf::FloatRect getBoundingRect() const;
    bool obstacleTest(std::list<SceneNode*> obstacles);
};


#endif //TANKCRAFT_PROJECTILE_H
