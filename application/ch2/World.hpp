#ifndef WORLD_HEADER_INCLUDED
#define WORLD_HEADER_INCLUDED

class World
{
public:
   static double fps;

   void Init();
   void Fini();

   void Update(double dTime);

};


#endif
