#ifndef PLANNERLIB_H
#define PLANNERLIB_H

#include <ros/ros.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Twist.h>
#include <wiimote/State.h>
#include <std_msgs/Int16MultiArray.h>
#include <std_msgs/Int16.h>

#define COST_OUTSIDE    50      // Sets the cost out of the Costmap to 50
#define CAR_WIDTH       0.45    // Car Width in Meter
#define CAR_LENGTH      0.70    // Car Length in Meter

class plannerLib
{
public:
    plannerLib();

    ros::NodeHandle nh;
    ros::Subscriber costmap_Sub;




private:
    float carWidth;             // In Pixel !!!
    float carLength;


    void handleNewCostmap(std::vector<> data);

    // This Function creates the points of the corners of the car, at a certain point, with a certai angle
    void createBox(float positionX, float positionY, float angle,                           // INPUT:  Position X, Position Y, Angle
                   std::vector<float> &xPoints, std::vector<float> &yPoints);               // OUTPUT: XCoordinates of the Points, YCoordinates of the Points

    // This Function returns all Points whcih are used to calculate the cost of a Path
    void createCalcPoints(std::vector<float> coordinatsX, std::vector<float> coordinatsY,   // INPUT: VectorPosition of Path X, VectorPosition of Path Y
                   std::vector<float> &xPoints, std::vector<float> &yPoints);               // OUTPUT: XCoordinates of the Points, YCoordinates of the Points

    // This Function calculates the Costs to the Points out of CREATE CALC POINTS
    float calcCost(std::vector<float> xPoints, std::vector<float> yPoints,                  // INPUT: VectorPoints of Path X, VectorPoints of Path y
                   std::vector<int> costMap, int width, int hight);                         // INPUT: Vector of Costmap, width of costmap, hight of costmap

    // Calculates the Index for Vector of Costmap to given x and y points
    int getIndex(int x, int y, int width, int hight);

};

#endif
