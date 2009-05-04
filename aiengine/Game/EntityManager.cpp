#include "Game/EntityManager.hpp"

namespace GameArt
{

  EntityManager& EntityManager::Instance()
  {
    static EntityManager em;
    return em;
  }

  void EntityManager::RegisterEntity(value_type bge)
  {
    (*bge).id(nextValidID_);
    ++nextValidID_;
    bge->Update(0.0);
    entityMap_.insert(std::make_pair((*bge).id() ,bge));
  }

  void EntityManager::RemoveEntity(value_type bge)
  {
    RemoveEntity((*bge).id());
  }

  void EntityManager::RemoveEntity(int entityID)
  {
    entityMap_.erase(entityMap_.find(entityID));
  }

  void EntityManager::Update(double dTime)
  {
    for(container_type::iterator it = entityMap_.begin();it != entityMap_.end(); ++it)
      {
	(*it).second->Update(dTime);
      }
  }
}
