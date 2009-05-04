#ifndef GAMEART_GAME_MOVINGENTITY_INCLUDED
#define GAMEART_GAME_MOVINGENTITY_INCLUDED

#include "Game/BaseGameEntity.hpp"
#include "Math/Vector.hpp"

namespace GameArt
{

  class MovingEntity: public BaseGameEntity
  {
  public:
    MovingEntity():BaseGameEntity(),position_(0,0),velocity_(0,0),heading_(0,1),side_(-1,0)
		  ,mass_(1.0),maxSpeed_(20),maxForce_(50),maxTurnRate_(1.57),boundingRadius_(1){}
    virtual ~MovingEntity(){}

    virtual void Update(double gameTime)
    {
      position_ += velocity_ * gameTime;
      if(velocity_.Magnitude() != 0)
	{
	  heading_ = velocity_;
	  heading_.Normalize();
	  side_ = heading_.Perpendicular();
	}
    }

    Vector2D<float> position()const {return position_;}
    void position(const Vector2D<float>& value){position_ = value;}

    Vector2D<float> velocity()const {return velocity_;}
    void velocity(const Vector2D<float>& value){velocity_ = value;}

    Vector2D<float> heading()const {return heading_;}
    void heading(const Vector2D<float>& value){heading_ = value;}

    Vector2D<float> side()const {return side_;}
    void side(const Vector2D<float>& value){side_ = value;}

    float mass()const {return mass_;}
    void mass(float value) {mass_ = value;}

    float maxSpeed()const {return maxSpeed_;}
    void maxSpeed(float value){maxSpeed_ = value;}

    float maxForce()const {return maxForce_;}
    void maxForce(float value){maxForce_ = value;}

    float maxTurnRate()const {return maxTurnRate_;}
    void maxTurnRate(float value){maxTurnRate_ = value;}

    float boundingRadius()const {return boundingRadius_;}
    void boundingRadius(float value){boundingRadius_ = value;}
    
  private:
    Vector2D<float> position_;
    Vector2D<float> velocity_;
    Vector2D<float> heading_;
    Vector2D<float> side_;
    
    float mass_;
    float maxSpeed_;
    float maxForce_;
    float maxTurnRate_;
    float boundingRadius_;
  };

}
#endif
