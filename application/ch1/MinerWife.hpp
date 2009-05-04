#ifndef MINERWIFE_HEADER_INCLUDED
#define MINERWIFE_HEADER_INCLUDED

#include <iostream>

#include "Game/BaseGameEntity.hpp"
#include "Message/Telegram.hpp"
#include "FSM/FiniteStateMachine.hpp"

class MinerWife : public GameArt::BaseGameEntity
{
public:
  MinerWife();

  void Clean(){std::cout<<"clean clean"<<std::endl;}

  void Cook(){std::cout<<"cook cook"<<std::endl;}

  void Update(double elapsedTime);

  void Render(double elapsedTime);

  void HandleMessage(const GameArt::Telegram& msg);

  GameArt::FiniteStateMachine<MinerWife>& GetFSM(){return fsm_;}

private:
  GameArt::FiniteStateMachine<MinerWife> fsm_;
};

#endif
