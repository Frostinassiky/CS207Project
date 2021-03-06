//
// Created by Yang on 15/11/2017.
//

#include <iostream>
#include "GameState.h"
#include "Player.h"

GameState::GameState(StateStack& stack, Context context)
        : State(stack, context)
        , mWorld(*context.window)
        , mPlayer(*context.player)
{
}

void GameState::draw()
{
    mWorld.draw();
}

bool GameState::update(sf::Time dt)
{
    mWorld.update(dt);
    switch (mWorld.winner())
    {
        case 0 :
            break;
        case 1 :
        std::cout<<mWorld.winner()<<std::endl;
            requestStackPush(StatesID::Player1Win);
            mWorld.reset();
            break;
        case 2:
        std::cout<<mWorld.winner()<<std::endl;
            requestStackPush(StatesID::Player2Win);
            mWorld.reset();
            break;
    }
    //if (mWorld.winner()!=0){
    //    std::cout << mWorld.winner() << std::endl;
    //    requestStackPush(StatesID::TODO);
    //}
    CommandQ& commands = mWorld.getCommandQ();
    mPlayer.handleRealtimeInput(commands);
    return true;
}

bool GameState::handleEvent(const sf::Event& event)
{
    // Game input handling
    CommandQ& commands = mWorld.getCommandQ();
    mPlayer.handleEvent(event,commands);

    // Escape pressed, trigger the pause screen
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        requestStackPush(StatesID::Pause);

    return true;
}