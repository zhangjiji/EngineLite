#include "MessageDispatcher.hpp"
#include "EntityManager.hpp"

#include "World.hpp"
#include "Robot.hpp"


double World::fps = 30.0;

void World::Init()
{
  boost::shared_ptr<Robot> pr(new Robot());
  GameArt::EntityManager::Instance().RegisterEntity(pr);
}

void World::Fini()
{
}

void World::Update(double dTime)
{
  GameArt::MessageDispatcher::Instance().DispatchDelayedMessage();
  GameArt::EntityManager::Instance().Update(dTime);
}
