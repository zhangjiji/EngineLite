#ifndef MINERSTATE_HEADER_INCLUDED
#define MINERSTATE_HEADER_INCLUDED


#include <iostream>
#include "FSM/FiniteStateMachine.hpp"

class Miner;

class WorkState:public GameArt::BaseState<Miner>
{
public:
  typedef boost::shared_ptr<Miner> spm;

  void Enter(spm pm){std::cout<<"go to mine.\n";}
  void Update(spm pm, double elapsedTime);
  void HandleMessage(spm pm, const GameArt::Telegram& msg){}
  void Exit(spm pm){std::cout<<"leave mine.\n";}
};

class SleepState:public GameArt::BaseState<Miner>
{
public:
  typedef boost::shared_ptr<Miner> spm;

  void Enter(spm pm){std::cout<<"go home.\n";}
  void Update(spm pm, double elapsedTime);
  void HandleMessage(spm pm, const GameArt::Telegram& msg){}
  void Exit(spm pm){std::cout<<"leave home.\n";}
};

class SaveMoneyState:public GameArt::BaseState<Miner>
{
public:
  typedef boost::shared_ptr<Miner> spm;

  void Enter(spm pm){std::cout<<"go to bank.\n";}
  void Update(spm pm, double elapsedTime);
  void HandleMessage(spm pm, const GameArt::Telegram& msg){}
  void Exit(spm pm){std::cout<<"leave bank.\n";}
};

class DrinkState:public GameArt::BaseState<Miner>
{
public:
  typedef boost::shared_ptr<Miner> spm;

  void Enter(spm pm){std::cout<<"go to club.\n";}
  void Update(spm pm, double elapsedTime);
  void HandleMessage(spm pm, const GameArt::Telegram& msg){}
  void Exit(spm pm){std::cout<<"leave club.\n";}
};

#endif
