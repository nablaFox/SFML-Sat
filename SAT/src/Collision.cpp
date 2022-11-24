#include "Collision.hpp"

Collision Collision::Instance;

bool Collision::SATCollision(Box& boxA, Box& boxB)
{
   std::vector<Vector2f> perpendicularStack;

   for (int i = 0; i < 4; i++)
      perpendicularStack.push_back(Normal(boxA.edge(i)));

   for (int i = 0; i < 4; i++)
      perpendicularStack.push_back(Normal(boxB.edge(i)));

   float dot = 0;
   float amin, amax;
   float bmin, bmax;

   for (int i = 0; i < perpendicularStack.size(); i++)
   {
      amin = bmin = INF;
      amax = bmax = -INF;

      for (int j = 1; j < 5; j++)
      {
         dot = DotProduct(boxA.dot(j), perpendicularStack[i]);

         if (dot > amax)
            amax = dot;
         if (dot < amin)
            amin = dot;         
      }

      for (int j = 1; j < 5; j++)
      {
         dot = DotProduct(boxB.dot(j), perpendicularStack[i]);

         if (dot > bmax)
            bmax = dot;
         if (dot < bmin)
            bmin = dot;         
      }

      if ((amin < bmax && amin > bmin) || (bmin < amax && bmin > amin))
         continue;
      else
         return false;
   }
   
   return true;
}

void Collision::CollisionAction(Box& boxA, Box& boxB)
{
   if (Keyboard::isKeyPressed(Keyboard::Left))
      boxA.setTraslation(Vector2f(boxA.speed, 0));

   else if (Keyboard::isKeyPressed(Keyboard::Right))
      boxA.setTraslation(Vector2f(-boxA.speed, 0));

   else if (Keyboard::isKeyPressed(Keyboard::Up))
      boxA.setTraslation(Vector2f(0, boxA.speed));

   else if (Keyboard::isKeyPressed(Keyboard::Down))
      boxA.setTraslation(Vector2f(0, -boxA.speed));

   
   if (Keyboard::isKeyPressed(Keyboard::D))
   {

      for (int i = 1; i < 5; i++)
      {
         float xv = boxA.dot(i).x;
         float yv = boxA.dot(i).y;

         bool isTouch = true;

         for (int j = 1; j < 5; j++)
         {
            int k = j + 1;
            if (j == 4) k = 1;

            Vector2f b1 = boxB.dot(j);
            Vector2f b2 = boxB.dot(k);

            float D = (b2.x - b1.x) * (yv - b2.y) - (b2.y - b1.y) * (xv - b2.x);

            if (D >= 0) //il punto tocca
               continue;
            else
               isTouch = false;
         }

         if (isTouch)
         {
            std::cout << "w" << std::endl;
            boxA.setOrigin(Vector2f(xv, yv));
            break;
         }
         
      }
            
   }
      
   




}