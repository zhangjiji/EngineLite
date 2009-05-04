#ifndef GAMEART_VECTOR_INCLUDED
#define GAMEART_VECTOR_INCLUDED

#include <cmath>
#include <iosfwd>
#include <boost/operators.hpp>

namespace GameArt
{
  template<typename T = float>
  class Vector2D : private boost::equality_comparable<Vector2D<T> >
    ,private boost::addable<Vector2D<T>
	    ,boost::subtractable<Vector2D<T> 
      	    ,boost::multipliable<Vector2D<T>,T
	    ,boost::dividable<Vector2D<T>,T> > > >
  {
  public:
    typedef T value_type;
    
    //constructor
    Vector2D(value_type x,value_type y):x_(x),y_(y){}

    //copy functions
    Vector2D(const Vector2D& rhs):x_(rhs.x_),y_(rhs.y_){}
    Vector2D& operator=(const Vector2D& rhs){x_=rhs.x_;y_=rhs.y_;return *this;}

    //access functions
    value_type x()const {return x_;}
    value_type y()const {return y_;}

    //compare functions
    bool operator==(const Vector2D& rhs) const {return x_==rhs.x_ && y_==rhs.y_;}

    //arithm functions
    const Vector2D& operator+=(const Vector2D& rhs)
    {
      x_+=rhs.x_;
      y_+=rhs.y_;
      return *this;
    }

    const Vector2D& operator-=(const Vector2D& rhs)
    {
      x_-=rhs.x_;
      y_-=rhs.y_;
      return *this;
    }

    const Vector2D& operator*=(value_type f)
    {
      x_*=f;
      y_*=f;
      return *this;
    }

    const Vector2D& operator/=(value_type f)
    {
      x_/=f;
      y_/=f;
      return *this;
    }

    value_type operator*(const Vector2D& rhs)
    {
      return value_type(x_*rhs.x_+y_*rhs.y_);
    }

    value_type inner_product(const Vector2D& rhs)
    {
      return *this * rhs;
    }

    value_type Magnitude() const {return std::sqrt(x_*x_+y_*y_);}
    value_type MagnitudeSq() const {return x_*x_+y_*y_;}

    Vector2D Normalize()
    {
      value_type len=Magnitude();
      x_/=len;
      y_/=len;
      return Vector2D(x_,y_);
    }

    Vector2D Truncate(value_type length)
    {
      value_type len = Magnitude();
      if(length < len)
	return Normalize()*length;
      else
	return *this;
    }

    Vector2D Perpendicular() const {return Vector2D(-y_,x_);}

    static const Vector2D Zero;

  private:
    value_type x_;
    value_type y_;
  };

  typedef Vector2D<float> Vector2f;

  template<typename T>
  const Vector2D<T> Vector2D<T>::Zero=Vector2D<T>(0,0);

  template<typename T>
  std::ostream& operator<<(std::ostream& os,const Vector2D<T>& rhs)
  {
    os<<"("<<rhs.x()<<","<<rhs.y()<<")";
  }



  template<typename T>
  class Vector3D
  {
  public:
    typedef T value_type;
    
    Vector3D(value_type x,value_type y,value_type z):x_(x),y_(y),z_(z){}
    value_type Length() const {return std::sqrt(x_*x_+y_*y_+z_*z_);}

  private:
    value_type x_;
    value_type y_;
    value_type z_;
  };


}

#endif
