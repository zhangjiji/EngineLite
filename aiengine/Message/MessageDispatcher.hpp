#include <queue>
#include <boost/utility.hpp>
#include <boost/any.hpp>

#include "Message/Telegram.hpp"
#include "Game/BaseGameEntity.hpp"

namespace GameArt
{
  class MessageDispatcher : private boost::noncopyable
  {
  public:
    static MessageDispatcher& Instance();

    void DispatchMessage(boost::posix_time::time_duration delay
			 ,int senderID, int receiverID, int type, boost::any data=0);
    void DispatchDelayedMessage();
    

  private:
    MessageDispatcher(){}

    void Discharge(BaseGameEntity* receiver, const Telegram& msg);

    std::priority_queue<Telegram> msgQ_;
  };
}
