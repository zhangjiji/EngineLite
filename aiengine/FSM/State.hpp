#ifndef GAMEART_FSM_STATE_INCLUDED
#define GAMEART_FSM_STATE_INCLUDED

#include <boost/shared_ptr.hpp>

class Telegram;

namespace GameArt
{
  template<typename EntityType>
  class BaseState
  {
  public:
    typedef boost::shared_ptr<EntityType> spe;

    virtual ~BaseState(){}
    virtual void Enter(spe)=0;
    virtual void Update(spe, double)=0;
    virtual void HandleMessage(spe, const Telegram&)=0;
    virtual void Exit(spe)=0;
  };
}
#endif
