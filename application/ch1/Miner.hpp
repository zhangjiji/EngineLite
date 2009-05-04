#ifndef MINER_HEADER_INCLUDED
#define MINER_HEADER_INCLUDED

#include <iostream>

// #include "Game/BaseGameEntity.hpp"
// #include "Message/Telegram.hpp"
// #include "FSM/FiniteStateMachine.hpp"

class Miner //: public GameArt::BaseGameEntity
{
public:
  Miner();

  void DigGold()
  {
    std::cout<<"work work dig dig"<<std::endl;
    goldCarried_+=1;
    tired_+=1;
    thirsty_+=1;
  }
  void Sleep()
  {
    std::cout<<"zzzZZZ"<<std::endl;
    tired_=0;
  }
  void SaveMoney()
  {
    std::cout<<"save money"<<std::endl;
    goldCarried_=0;
  }
  void Drink()
  {
    std::cout<<"have a drink"<<std::endl;
    thirsty_=0;
  }

  void Update(double elapsedTime);

  void Render(double elapsedTime);

//   void HandleMessage(const GameArt::Telegram& msg);

//   GameArt::FiniteStateMachine<Miner>& GetFSM(){return fsm_;}

  int goldCarried_;
  int thirsty_;
  int tired_;
//   GameArt::FiniteStateMachine<Miner> fsm_;
};

#endif
