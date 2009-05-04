#include "Miner.hpp"
// #include "MinerState.hpp"

Miner::Miner():/*BaseGameEntity(),*/goldCarried_(0),thirsty_(0),tired_(0)//,fsm_(this)
{
//   fsm_.SetCurrentState(GameArt::FiniteStateMachine<Miner>::sps(new WorkState));
}

void Miner::Update(double gameTime)
{
//   fsm_.Update(gameTime);
}

void Miner::Render(double gameTime)
{
}

// void Miner::HandleMessage(const GameArt::Telegram& msg)
// {
// }
