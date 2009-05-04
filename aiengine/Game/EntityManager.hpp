#ifndef GAMEART_GAME_ENTITYMANAGER_INCLUDED
#define GAMEART_GAME_ENTITYMANAGER_INCLUDED

#include <map>
#include <boost/utility.hpp>
#include <boost/shared_ptr.hpp>

#include "Game/BaseGameEntity.hpp"

namespace GameArt
{
  class EntityManager : private boost::noncopyable
  {
  public:
    typedef boost::shared_ptr<BaseGameEntity> value_type;
    typedef std::map<int, value_type> container_type;

    static EntityManager& Instance();

    void RegisterEntity(value_type bge);
    void RemoveEntity(value_type bge);
    void RemoveEntity(int entityID);

    void Update(double dTime);

    template<typename T>
    T* GetEntityFromID(int entityID)const;

    void Reset(){entityMap_.clear();}

  private:
    EntityManager():nextValidID_(0){}

    entityid_type nextValidID_;

    container_type entityMap_;
  };

  template<typename T>
  T* EntityManager::GetEntityFromID(int entityID)const
  {
    container_type::const_iterator cit = entityMap_.find(entityID);
    if(cit!=entityMap_.end())
      return dynamic_cast<T*>((*cit).second.get());
    else
      return 0;
  }
}
#endif
