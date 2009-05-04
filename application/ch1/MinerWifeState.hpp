#ifndef MINERWIFESTATE_HEADER_INCLUDED
#define MINERWIFESTATE_HEADER_INCLUDED


#include <iostream>
#include "FSM/FiniteStateMachine.hpp"

class MinerWife;

class CleanState:public GameArt::BaseState<MinerWife>
{
public:
  typedef boost::shared_ptr<MinerWife> spm;

  void Enter(spm pm){}
  void Update(spm pm, double elapsedTime);
  void HandleMessage(spm pm, const GameArt::Telegram& msg);
  void Exit(spm pm){}
};

class CookingState:public GameArt::BaseState<MinerWife>
{
public:
  typedef boost::shared_ptr<MinerWife> spm;

  void Enter(spm pm){std::cout<<"My husband is going home.\n";}
  void Update(spm pm, double elapsedTime);
  void HandleMessage(spm pm, const GameArt::Telegram& msg){}
  void Exit(spm pm){std::cout<<"Food OK.\n";}
};

#endif
