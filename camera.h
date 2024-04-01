#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "vec3.h"
#include "ray.h"

namespace Scene
{
    class camera
    {

    public:
        // Default constructor (initializes eyePoint to 0,0,0)
        camera(){

            //simple.xml
            eyePoint.x = 0;
            eyePoint.y = 0;
            eyePoint.z = 0;

            gaze.x =0;
            gaze.y =0;
            gaze.z =-1;
            
            up.x=0;
            up.y=1;
            up.z=0;

            left =-1;
            right = 1;
            bottom = -1;
            top = 1;
            distance = 1;
            nx = 1920;
            ny = 1080;



        }
        camera(Vector3f::point3f cameraPos, Vector3f::Vec3f _v, Vector3f::Vec3f _gaze, float _nx, float _ny,
        float _left, float _right, float _top, float _bottom, float _distance)
         : eyePoint(cameraPos), up(_v), gaze(_gaze), nx(_nx), ny(_ny), left(_left), right(_right), 
         top(_top), bottom(_bottom), distance(_distance) {}

        // Getter and setter for eyePoint
        const Vector3f::point3f &getEyePoint() const { return eyePoint; }
        void setEyePoint(const Vector3f::point3f &newEyePoint) { eyePoint = newEyePoint; }

        // Getter and setter for gaze
        const Vector3f::Vec3f &getGaze() const { return gaze; }
        void setGaze(const Vector3f::Vec3f &newGaze) { gaze = newGaze; }

        // Getter and setter for up
        const Vector3f::Vec3f &getUp() const { return up; }
        void setUp(const Vector3f::Vec3f &newUp) { up = newUp; }

        // Getter and setter for w (assuming w is already calculated in the constructor or elsewhere)
        const Vector3f::Vec3f &getW() const { return -gaze; }

        // Getter and setter for near plane values (left, right, bottom, top)
        float getLeft() const { return left; }
        void setLeft(float newLeft) { left = newLeft; }

        float getRight() const { return right; }
        void setRight(float newRight) { right = newRight; }

        float getBottom() const { return bottom; }
        void setBottom(float newBottom) { bottom = newBottom; }

        float getTop() const { return top; }
        void setTop(float newTop) { top = newTop; }

        // Getter and setter for near distance
        float getDistance() const { return distance; }
        void setDistance(float newDistance) { distance = newDistance; }

        // image with
        size_t getNx() const { return nx; }
        void setNx(float newNx) { nx = newNx; }
        // image height
        size_t getNy() const { return ny; }
        void setNy(float newNy) { ny = newNy; }

    private:
        Vector3f::point3f eyePoint; //<position>x y z</position>
        Vector3f::Vec3f gaze;       //<gaze>x y z</gaze>
        Vector3f::Vec3f up;         //<up>x y z</up>
        // Vector3f::Vec3f w;          // w = upXgaze (cross product)
        // near planes:
        float left, right, bottom, top;
        // neardistance:
        float distance;
        // image resolutions:
        size_t nx, ny; // nx: width, ny height
    };
} // namespace Scene

#endif
