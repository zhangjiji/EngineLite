#ifndef GAMEART_GAME_BASEGAMEENTITY_INCLUDED
#define GAMEART_GAME_BASEGAMEENTITY_INCLUDED

#include <boost/shared_ptr.hpp>

#include "Message/Telegram.hpp"

namespace GameArt
{
  typedef unsigned int entityid_type;

  class BaseGameEntity
  {
  public:
    BaseGameEntity():id_(-1), type_(-1){}

    virtual ~BaseGameEntity(){};

    virtual void Update(double gameTime)=0;
    virtual void Render(double gameTime)=0;
    virtual void HandleMessage(const Telegram& msg)=0;

    entityid_type id() const {return id_;}
    void id(entityid_type id) {id_ = id;}

    int type() const {return type_;}
    void type(int type) {type_ = type;}

  private:
    entityid_type id_;
    int type_;
  };

  typedef boost::shared_ptr<GameArt::BaseGameEntity> spbge_type;

}
#endif
