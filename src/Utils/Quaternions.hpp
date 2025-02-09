#pragma once

#include <cmath>

#define Q_PI 3.14159265358979323846



namespace Quaternions
{ 

    /// @brief Rotates a vector/point, using a quaternion, derived from provided args
    /// @tparam T Vector/Point 
    /// @param vector The vector type
    /// @param deg Amount of rotation in degrees
    /// @param x 
    /// @param y 
    /// @param z 
    template<typename T>
    void rotateVector(T& vector, float deg, T rotationVec)
    { 
        // Convert point to be rotated into a quaterion
        float vqw = 0.0f;
        float vqx = vector.getX();
        float vqy = vector.getY();
        float vqz = vector.getZ();

        // normalize rotation vector
        rotationVec.normalize();

        // convert rotation vec into a quaternion
        // 1. convert degrees into radians
        float rad = deg * (Q_PI / 180.0f);
        float halfRad = rad / 2.0f;
        float sinHalfRad = std::sin(halfRad);


        // 2. get Quat for rotationVec
        float rqw = std::cos(halfRad);
        float rqx = rotationVec.getX() * sinHalfRad;
        float rqy = rotationVec.getY() * sinHalfRad;
        float rqz = rotationVec.getZ() * sinHalfRad;
        std::cout << "QUATERNION : ROTAT QUAT: " << rqw << " : " << rqx << " : " << rqy << " : " << rqz << std::endl;

        // 3. Get Inverse of this quaternion
        float iqw = rqw; 
        float iqx = -rqx;
        float iqy = -rqy;
        float iqz = -rqz;
        std::cout << "QUATERNION : INVERSE QUAT: " << iqw << " : " << iqx << " : " << iqy << " : " << iqz << std::endl;

        // using Quaternion Multiplication rqw . vqw . iqw
        // get intermediary of q{-1} * v
        float nqw = iqw * vqw - iqx * vqx - iqy * vqy - iqz * vqz;
        float nqx = iqw * vqx + iqx * vqw + iqy * vqz - iqz * vqy;
        float nqy = iqw * vqy + iqx * vqz + iqy * vqw - iqz * vqx;
        float nqz = iqw * vqz - iqx * vqy + iqy * vqx + iqz * vqw;

        std::cout << "QUAT LOG : INTERMEDIARY: " << nqw << " : " << nqx << " : " << nqy << " : " << nqz << std::endl;; 

        // now nqw * iqw : v * q
        float retw = nqw * rqw - nqx * rqx - nqy * rqy - nqz * rqz;
        float retx = nqw * rqx + nqx * rqw - nqy * rqz + nqz * rqy;
        float rety = nqw * rqy + nqx * rqz + nqy * rqw - nqz * rqx;
        float retz = nqw * rqz - nqx * rqy + nqy * rqx + nqz * rqw;
        std::cout << "QUAT LOG : END : " << retw << " : " << retx << " : " << rety << " : " << retz << std::endl;
         

        vector.setX(std::abs(retx) < 1e-6 ? 0.0f : retx); 
        vector.setY(std::abs(rety) < 1e-6 ? 0.0f : rety); 
        vector.setZ(std::abs(retz) < 1e-6 ? 0.0f : retz); 
    }
}