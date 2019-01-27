#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>  

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int speed;
    int xboost=1; // 0 pas encore disponible
    // game loop
    while (1) {
        int x;
        int y;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDist; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        cin >> x >> y >> nextCheckpointX >> nextCheckpointY >> nextCheckpointDist >> nextCheckpointAngle; cin.ignore();
        
        
        int opponentX;
        int opponentY;
        cin >> opponentX >> opponentY; cin.ignore();
        double xx=opponentX-nextCheckpointX;
        double yy=opponentY-nextCheckpointY;
        double dist = sqrt(xx*xx+yy*yy);

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        speed = 100-abs(nextCheckpointAngle)*50/90;
        if(abs(nextCheckpointAngle)>90 && nextCheckpointDist<6000)
        {
            speed=20;
        }
        else if(nextCheckpointDist<2400 && (dist-nextCheckpointDist)>0)
            speed=speed/2;
        
        speed=max(speed,10);
        if(xboost==1)
        {
            if(nextCheckpointDist>5000 && nextCheckpointAngle>-5 && nextCheckpointAngle<5)
                xboost=-1;
        }
        
        if(nextCheckpointDist>4000 && (nextCheckpointAngle>135 || nextCheckpointAngle<-135))
        {
            if(dist>nextCheckpointDist && (dist-nextCheckpointDist)<900)
            {
                nextCheckpointX=opponentX;
                nextCheckpointY=opponentY;
            }
        }
        
        /*if(nextCheckpointDist<3000 && nextCheckpointDist>1000 && abs(nextCheckpointAngle)<5)
        {
            double xx=opponentX-nextCheckpointX;
            double yy=opponentY-nextCheckpointY;
            double dist = sqrt(xx*xx+yy*yy);
            if(dist>nextCheckpointDist && (dist-nextCheckpointDist)<1200 && (dist-nextCheckpointDist)>800)
            //if(dist>nextCheckpointDist && (dist-nextCheckpointDist)<1000)
                speed=0;
        }*/
        
        if(nextCheckpointDist<1200 && abs(nextCheckpointAngle)<10)
        {
            if(dist<nextCheckpointDist && (nextCheckpointDist-dist)<1000)
            {
                speed=100;
                nextCheckpointX=opponentX;
                nextCheckpointY=opponentY;
            }
        }
        
        if(xboost==-1)
        {
            cout << nextCheckpointX << " " << nextCheckpointY << " BOOST" << endl;
            xboost=-2;
        }
        else
            cout << nextCheckpointX << " " << nextCheckpointY << " " << speed << endl;
    }
}