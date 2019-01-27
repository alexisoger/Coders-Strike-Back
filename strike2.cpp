#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int xfirst = 0;
    int second=0;
    int xboost=0;
    int distmax=0;
    int xmax=0;
    // game loop
    while (1) {
        int x;
        int y;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDist; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        cin >> x >> y >> nextCheckpointX >> nextCheckpointY >> nextCheckpointDist >> nextCheckpointAngle; cin.ignore();
        if(xfirst==0)
            xfirst=nextCheckpointX;
        if(xfirst!=nextCheckpointX)//premier checkpoint atteint
            second=1;
        if(second==1 && xfirst==nextCheckpointX)//un tour fini
            xboost=1;
        if(xboost==0)//premier tour
        {
            if(nextCheckpointDist>distmax)
            {
                distmax=nextCheckpointDist;
                xmax=nextCheckpointX;
            }
        }
            
        int opponentX;
        int opponentY;
        cin >> opponentX >> opponentY; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
        if(nextCheckpointDist<800)
            cout << nextCheckpointX << " " << nextCheckpointY << " 10" << endl;
        else if(xboost<=0)
        {
            int speed = 0;
            if(nextCheckpointAngle<90 && nextCheckpointAngle>-90)
                speed = 100;
            cout << nextCheckpointX << " " << nextCheckpointY << " " << speed << endl; 
        }
        else
        {
            if(nextCheckpointX==xmax && nextCheckpointAngle>-5 && nextCheckpointAngle<5)
            {
                cout << nextCheckpointX << " " << nextCheckpointY << " BOOST" << endl;
                xboost=-1;
            }
            else
            {
                int speed = 0;
                if(nextCheckpointAngle<90 && nextCheckpointAngle>-90)
                    speed = 100;
                cout << nextCheckpointX << " " << nextCheckpointY << " " << speed << endl; 
            }
        }
    }
}