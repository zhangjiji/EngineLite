#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_duration.hpp>

#include "Message/MessageDispatcher.hpp"
#include "Game/EntityManager.hpp"

namespace GameArt
{
  MessageDispatcher& MessageDispatcher::Instance()
  {
    static MessageDispatcher instance;
    return instance;
  }

  void MessageDispatcher::DispatchMessage(boost::posix_time::time_duration delay
					  ,int senderID, int receiverID, int type, boost::any data)
  {
    BaseGameEntity* pSender = EntityManager::Instance().GetEntityFromID<BaseGameEntity>(senderID);
    BaseGameEntity* pReceiver = EntityManager::Instance().GetEntityFromID<BaseGameEntity>(receiverID);
    if(pSender==0 || pReceiver==0)
      return;

    if(delay <= boost::posix_time::milliseconds(33))
      {
	Telegram msg(boost::posix_time::microsec_clock::local_time(),senderID,receiverID,type,data);
	Discharge(pReceiver, msg);
      }
    else
      {
	boost::posix_time::ptime t(boost::posix_time::microsec_clock::local_time());
	Telegram msg(t+delay, senderID, receiverID, type, data);
	msgQ_.push(msg);
      }
  }

  void MessageDispatcher::DispatchDelayedMessage()
  {
    boost::posix_time::ptime curTime(boost::posix_time::microsec_clock::local_time());
    while(!msgQ_.empty() && msgQ_.top().dispatchTime_ <= curTime)
      {
	Telegram msg = msgQ_.top();
	msgQ_.pop();
	BaseGameEntity* pReceiver = EntityManager::Instance().GetEntityFromID<BaseGameEntity>(msg.receiverID_);
	Discharge(pReceiver, msg);
      }
  }

  void MessageDispatcher::Discharge(BaseGameEntity* receiver, const Telegram& msg)
  {
    receiver->HandleMessage(msg);
  }
}
