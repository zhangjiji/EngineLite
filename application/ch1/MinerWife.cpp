#include "MinerWife.hpp"
#include "MinerWifeState.hpp"

MinerWife::MinerWife():BaseGameEntity(), fsm_(this)
{
  fsm_.SetCurrentState(GameArt::FiniteStateMachine<MinerWife>::sps(new CleanState));
}

void MinerWife::Update(double gameTime)
{
  fsm_.Update(gameTime);
}

void MinerWife::Render(double gameTime)
{
}

void MinerWife::HandleMessage(const GameArt::Telegram& msg)
{
  fsm_.HandleMessage(msg);
}
