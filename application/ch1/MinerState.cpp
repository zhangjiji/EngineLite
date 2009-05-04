#include "Message/MessageDispatcher.hpp"

#include "MinerState.hpp"
#include "Miner.hpp"

void WorkState::Update(spm pm, double elapsedTime)
{
  pm->DigGold();
  if(pm->goldCarried_ >= 3)
    pm->GetFSM().ChangeState(GameArt::FiniteStateMachine<Miner>::sps(new SaveMoneyState));
  else if(pm->tired_ >= 5)
    {
      GameArt::MessageDispatcher::Instance().DispatchMessage(boost::posix_time::seconds(0),pm->id(), 1, 0);
      pm->GetFSM().ChangeState(GameArt::FiniteStateMachine<Miner>::sps(new SleepState));
    }
  else if(pm->thirsty_ >= 7)
    pm->GetFSM().ChangeState(GameArt::FiniteStateMachine<Miner>::sps(new DrinkState));
}

void SleepState::Update(spm pm, double elapsedTime)
{
  pm->Sleep();
  pm->GetFSM().ChangeState(GameArt::FiniteStateMachine<Miner>::sps(new WorkState));
}

void SaveMoneyState::Update(spm pm, double elapsedTime)
{
  pm->SaveMoney();
  pm->GetFSM().ChangeState(GameArt::FiniteStateMachine<Miner>::sps(new WorkState));
}

void DrinkState::Update(spm pm, double elapsedTime)
{
  pm->Drink();
  pm->GetFSM().ChangeState(GameArt::FiniteStateMachine<Miner>::sps(new WorkState));
}

