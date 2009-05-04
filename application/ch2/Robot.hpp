#ifndef ROBOT_HEADER_INCLUDED
#define ROBOT_HEADER_INCLUDED

#include <iostream>
#include "BaseGameEntity.hpp"

class Robot : public GameArt::BaseGameEntity
{
public:
  void Update(double gameTime);
  void Render(double gameTime);
  void HandleMessage(const GameArt::Telegram& msg);

};


#endif
