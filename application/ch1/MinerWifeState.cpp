#include "MinerWife.hpp"
#include "MinerWifeState.hpp"

void CleanState::Update(spm pm, double elapsedTime)
{
  pm->Clean();
}

void CleanState::HandleMessage(spm pm, const GameArt::Telegram& msg)
{
  if(msg.msgType_ == 0)
    pm->GetFSM().ChangeState(GameArt::FiniteStateMachine<MinerWife>::sps(new CookingState));    
}

void CookingState::Update(spm pm, double elapsedTime)
{
  pm->Cook();
  pm->GetFSM().ChangeState(GameArt::FiniteStateMachine<MinerWife>::sps(new CleanState));
}

