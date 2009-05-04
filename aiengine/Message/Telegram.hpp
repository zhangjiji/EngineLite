#ifndef GAMEART_MESSAGE_TELEGRAM_INCLUDED
#define GAMEART_MESSAGE_TELEGRAM_INCLUDED

#include <boost/any.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_duration.hpp>

namespace GameArt
{

  class Telegram
  {
  public:
    Telegram():dispatchTime_(boost::posix_time::microsec_clock::local_time())
	      ,senderID_(-1),receiverID_(-1),msgType_(-1),extraInfo_(0){}
    Telegram(boost::posix_time::ptime time
	     ,int senderID, int receiverID, int msgType, boost::any extraInfo = 0):
      dispatchTime_(time),senderID_(senderID),receiverID_(receiverID)
      ,msgType_(msgType),extraInfo_(extraInfo){}

    bool operator==(const Telegram& rhs)const
    {
      return (dispatchTime_ == rhs.dispatchTime_)
	&& (senderID_ == rhs.senderID_)
	&& (receiverID_ == rhs.receiverID_)
	&& (msgType_ == rhs.msgType_);
    }

    bool operator<(const Telegram& rhs)const{return dispatchTime_ < rhs.dispatchTime_;}

    boost::posix_time::ptime dispatchTime_;
    int senderID_;
    int receiverID_;
    int msgType_;
    boost::any extraInfo_;
  };

}
#endif
