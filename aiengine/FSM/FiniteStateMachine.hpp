#ifndef GAMEART_FSM_FINITESTATEMACHINE_INCLUDED
#define GAMEART_FSM_FINITESTATEMACHINE_INCLUDED

#include <boost/shared_ptr.hpp>

#include "../Message/Telegram.hpp"
#include "State.hpp"

namespace GameArt
{
  template<typename EntityType>
  class FiniteStateMachine
  {
  public:
    typedef boost::shared_ptr<EntityType> spe;
    typedef boost::shared_ptr<BaseState<EntityType> > sps;

    FiniteStateMachine(EntityType* owner):pOwner_(owner){}
    
    void Update(double elapsedTime)const
    {
      if(pGlobalState_ != 0)
	pGlobalState_->Update(pOwner_, elapsedTime);

      if(pCurrentState_ != 0)
	pCurrentState_->Update(pOwner_, elapsedTime);
    }

    void HandleMessage(const Telegram& msg)const
    {
      if(pCurrentState_ != 0)
	pCurrentState_->HandleMessage(pOwner_, msg);

      if(pGlobalState_ != 0)
	pGlobalState_->HandleMessage(pOwner_, msg);
    }

    void SetCurrentState(sps newState)
    {
      newState->Enter(pOwner_);
      pCurrentState_ = newState;
    }

    void SetGlobalState(sps newState)
    {
      newState->Enter(pOwner_);
      pGlobalState_ = newState;
    }

    void ChangeState(sps newState)
    {
      pPreviousState_ = pCurrentState_;
      if(pCurrentState_ != 0)
	pCurrentState_->Exit(pOwner_);
      newState->Enter(pOwner_);
      pCurrentState_ = newState;
    }

    void RevertToPreviousState()
    {
      ChangeState(pPreviousState_);
    }

    bool isInState(sps s)
    {
      return (typeid(*pCurrentState_) == typeid(*s));
    }

    sps CurrentState()const {return pCurrentState_;}
    sps GlobalState()const {return pGlobalState_;}
    sps PreviousState()const {return pPreviousState_;}

  private:
    spe pOwner_;
    sps pCurrentState_;
    sps pGlobalState_;
    sps pPreviousState_;
  };
}

#endif
