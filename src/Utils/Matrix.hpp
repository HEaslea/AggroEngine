#pragma once


#include <cmath> 
#include <vector>
#include <algorithm>
#include <initializer_list>

#define PI 3.14159265358979323846

/* 
    Shaders in OpenGL expect 32 bit floating point matrices
    Therefore, will need a conversion if the user wants to use something else like int, double
    And also with dimensions: where OpenGL expects 4x4
*/

/* 
    See Strassen's algorithm for matrix multiplication
    O(n^3) -> O(n^2.81)
*/

template <typename T, std::size_t M, std::size_t N> 
struct AgMatix 
{ 
    std::array<std::array<T, N>, M> _data;
};

template <typename T> 
class DynMatrix 
{ 
public:
    std::vector<std::vector<T>> _data;
};

/* 
template <typename T, std::size_t M, std::size_t N> 
class Matrix
{ 
    std::array<std::array<T, N>, M> _data;    

public: 

    Matrix() 
    { 
        static_assert(M == N, "Default / Identify Construction of Matrix only defined for square matrices");
        for(std::size_t out = 0; out < M; ++out)
        { 
            for(std::size_t in = 0; in < N; ++in)
            { 
                if(out == in)
                    _data[out][in] = static_cast<T>(1);
                else 
                    _data[out][in] = static_cast<T>(0);
            }
        }
        std::cout << "Debug Out" << std::endl;
    }
     
    void log() 
    { 
        std::cout << "Matrix : LOG : ";
        std::for_each(_data.begin(), _data.end(), 
            [](auto& in){
                std::for_each(in.begin(), in.end(),
                [](T i)
                { 
                    std::cout << i << " : ";
                }
                );
            std::cout << std::endl;
        }
        );
    }
};
 */

/// \class Mat4
/// \brief A generic type class that for Matrices of size 4x4
template <typename T>
class Mat4
{ 
public: 
    // for [] operator which i need to implement
    T _data[4][4]; ///< Matrix Data

    /// @brief Mat4 Default constructor
    Mat4()
    { 
        for(std::size_t i = 0; i < 4; ++i)
        { 
            for(std::size_t j = 0; j < 4; ++j)
            { 
                _data[i][j] = (i == j) ? 1 : 0;
            }
        }
    }


    void log() const
    { 
        std::cout << "Mat4 : LOG : " << std::endl; 
        for(std::size_t i = 0; i < 4; ++i)
        { 
            for(std::size_t j = 0; j < 4; ++j)
            { 
                std::cout << _data[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    }
     
    Mat4 operator*(Mat4 const& other)
    { 
        Mat4 rMat;

        for(int i = 0; i < 4; ++i)
        { 
            for(int j = 0; j < 4; ++j)
            { 
                rMat._data[i][j] = 0;
                for(int k = 0; k < 4; ++k)
                { 
                    rMat._data[i][j] += _data[i][k] * other._data[k][j];
                }
            }
        }

        return rMat;
    }

};
 
namespace Matrix 
{ 
    /// @brief Generates a 4x4 scale matrix from an intializer list of 3 values.
    /// @tparam T The type of the scaling values - castable to float
    /// @param scale An initializer list, 3 values corresponding to x, y, z of scaling vector
    /// @return Mat4<float> scaling matrix
    template <typename T>
    Mat4<float> getScaleMatrix(std::initializer_list<T> scale)
    { 
        Mat4<float> rMat;
        // check if scale is size of 3
        if(scale.size() != 3)
        { 
            throw std::invalid_argument("Scale must contain 3 values only");
        }

        auto sIt = scale.begin();
        rMat._data[0][0] = static_cast<float>(*sIt++);
        rMat._data[1][1] = static_cast<float>(*sIt++);
        rMat._data[2][2] = static_cast<float>(*sIt);

        return rMat;
    } 

    /// @brief  Generates a 4x4 scale matrix fron 3 T values
    /// @tparam T The type of the scaling values - castable to float
    /// @param x x scale component
    /// @param y y scale component
    /// @param z z scale component
    /// @return Mat4<float> scaling matrix
    template <typename T> 
    Mat4<float> getScaleMatrix(T x, T y, T z)
    { 
        Mat4<float> rMat;
        rMat._data[0][0] = static_cast<float>(x);
        rMat._data[1][1] = static_cast<float>(y);
        rMat._data[2][2] = static_cast<float>(z);

        return rMat;
    }
     
    /// @brief Generates a 4x4 transform matrix from an intializer list of 3 values.
    /// @tparam T The type of the scaling values - castable to float
    /// @param scale An initializer list, 3 values corresponding to x, y, z of scaling vector
    /// @return Mat4<float> transform matrix
    template <typename T>
    Mat4<float> getTransMatrix(std::initializer_list<T> transform)
    {  
        Mat4<float> rMat;

        auto it = transform.begin();

        rMat._data[0][3] = static_cast<float>(*it++);
        rMat._data[1][3] = static_cast<float>(*it++);
        rMat._data[2][3] = static_cast<float>(*it);

        return rMat;
    }
     
    /// @brief  Generates a 4x4 transform matrix fron 3 T values
    /// @tparam T The type of the scaling values - castable to float
    /// @param x x transform component
    /// @param y y transform component
    /// @param z z transform component
    /// @return Mat4<float> transform matrix
    template <typename T> 
    Mat4<float> getTransMatrix(T x, T y, T z)
    { 
        Mat4<float> rMat;
        rMat._data[0][3] = static_cast<float>(x);
        rMat._data[1][3] = static_cast<float>(y);
        rMat._data[2][3] = static_cast<float>(z);

        return rMat;
    }
}
