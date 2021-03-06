//
// Created by Mengmeng Xu on 11/27/17.
//

#include "Player2WinState.h"
//
// Created by Mengmeng Xu on 11/27/17.
//

#include "Player1WinState.h"
#include "Utility.h"

Player2WinState::Player2WinState(StateStack& stack, Context context)
        : State(stack, context)
        , mBackgroundSprite()
        , mPausedText()
        , mInstructionText()
{
    //sf::Font& font = context.fonts->get(Fonts::Main);
    sf::Vector2f viewSize = context.window->getView().getSize();

    mFont.loadFromFile("../Media/GODOFWAR.TTF");

    mPausedText.setFont(mFont);
    mPausedText.setString("Left Player Wins!");
    mPausedText.setColor(sf::Color::Cyan);
    mPausedText.setCharacterSize(140);
    centerOrigin(mPausedText);
    mPausedText.setPosition(0.5f * viewSize.x, 0.4f * viewSize.y);

    mInstructionText.setFont(mFont);
    mInstructionText.setString("(Press Backspace or Escape to return to the main menu)");
    centerOrigin(mInstructionText);
    mInstructionText.setPosition(0.5f * viewSize.x, 0.6f * viewSize.y);
}

void Player2WinState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.setView(window.getDefaultView());





    sf::RectangleShape backgroundShape;
    backgroundShape.setFillColor(sf::Color(0, 0, 0, 150));
    backgroundShape.setSize(window.getView().getSize());

    window.draw(backgroundShape);
    window.draw(mPausedText);
    window.draw(mInstructionText);
}

bool Player2WinState::update(sf::Time)
{
    return false;
}

bool Player2WinState::handleEvent(const sf::Event& event)
{
    if (event.type != sf::Event::KeyPressed)
        return false;

    if (event.key.code == sf::Keyboard::Escape||event.key.code == sf::Keyboard::BackSpace)
    {
        // Escape pressed, remove itself to return to the game
        requestStateClear();
        //requestStackPop();
        requestStackPush(StatesID::Menu);
    }



    return false;
}