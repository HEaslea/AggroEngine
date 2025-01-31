#pragma once
// Vector Library

#include <cstddef>
#include <array>
#include <initializer_list>
#include <cmath> 

template <typename T, std::size_t N> 
class Vector
{ 
    // using std::array see project log
    std::array<T, N> _data;

public: 

    using inner_type = T;

    Vector()
    { 
        _data.fill(T(0));
    }

    Vector(std::initializer_list<T> data)
    { 
        // could move? 
        // copying to member
        std::copy(data.begin(), data.end(), _data.begin());
    }

    // defer to std::array and T
    ~Vector() {}

    Vector(Vector const& other)
    { 
        _data = other._data;
    }
     
    Vector& operator=(Vector const& other)
    { 
        if(this != &other)
            _data = other._data;

        return *this;
    }

    Vector(Vector&& other) noexcept
    { 
        _data = std::move(other._data);
    }

    Vector& operator=(Vector&& other) noexcept 
    { 
        if(this != &other)       
            _data = std::move(other._data);

        return *this;   
    }

    // accessor 
    T& operator[](std::size_t i)
    { 
        return _data[i];
    }

    // const accessor
    const T& operator[](std::size_t i) const 
    { 
        return _data[i];
    }
    
    void scale(T s)
    { 
        for(T& val : _data)
        { 
            val *= s;
        }
    }

    // outside class for clarity (although doesn't seem so clear now)
    // BASE VECTOR OPERATIONS
    Vector operator*(T s) const; // const? 
    Vector operator+(Vector const& other) const;
    Vector operator+(T s);

    T dot(Vector const& other) const; 

    T magnitude() const;

    // want to represent that this is not in place
    Vector<float, N> getNormalized() const;

    // Reflection generate a vector
    std::vector<T> reflection() const;
     

    // General 
    template <std::size_t X = N>   
    std::enable_if_t<X != 2 && X != 3, void> 
    cross(Vector const& other) const;

    template <std::size_t X = N>   
    std::enable_if_t<X == 2, T> 
    cross(Vector const& other) const;

    template <std::size_t X = N> 
    std::enable_if_t<X == 3, Vector<T, 3>>
    cross(Vector const& other) const;


    // DEBUG LOG REMOVE LATER ON
    void log() const 
    { 
        std::cout << "Vector: LOG : ";
        for(int i = 0; i < N; ++i)
        { 
            std::cout << _data[i] << " : ";
        }
        std::cout << std::endl;
    }

};

/* 
    Lots of repetitive code here
    Another way is to have a helper function, taking in a functor
    including the operation that we need
    Both ways are fine with OCP 
*/

template <typename T, std::size_t N> 
Vector<T, N> Vector<T, N>::operator*(T s) const
{ 
    Vector temp;
    for(std::size_t i = 0; i < N; ++i)
    { 
        temp[i] = _data[i] * s;
    }

    return temp;
}

template <typename T, std::size_t N> 
Vector<T, N> Vector<T, N>::operator+(Vector<T, N> const& other) const 
{ 
    // lambda into a static helper function, might be too unreadable
    Vector temp;
    for(std::size_t i = 0; i < N; ++i)
    { 
        temp[i] = _data[i] + other[i];
    }

    return temp;
}

template <typename T, std::size_t N> 
Vector<T, N> Vector<T, N>::operator+(T s)  
{ 
    Vector temp;
    for(std::size_t i = 0; i < N; ++i)
    { 
        temp[i] = _data[i] + s;
    }

    return temp;
}
 
template <typename T, std::size_t N> 
T Vector<T, N>::dot(Vector const& other)  const
{ 
    T sum{};
    for(std::size_t i = 0; i < N; ++i)
    { 
        sum += _data[i] * other[i];
    }

    return sum;
}

template <typename T, std::size_t N> 
T Vector<T, N>::magnitude() const
{
    T sum{};
    for(std::size_t i = 0; i < N; ++i)
    { 
        sum += _data[i] * _data[i];
    }

    return std::sqrt(sum);
}

// REFLECTION
template <typename T, std::size_t N> 
std::vector<T> Vector<T, N>::reflection() const 
{ 
    std::vector<T> ret(N);
    for(std::size_t i = 0; i < N; ++i)
    { 
        ret[i] = _data[i];
    }

    return ret;
}
 
// or double (how much precision)
template <typename T, std::size_t N> 
Vector<float, N> Vector<T, N>::getNormalized() const
{ 
    float mag = magnitude(); 
    if(mag == T{})
        return {};

    Vector ret;

    for(std::size_t i = 0; i < N; ++i)
    { 
        ret[i] = _data[i] / mag;
    }

    return ret;
}

template <typename T, std::size_t N> // class template 
template <std::size_t X> // inner template && no defaults in definitions 
std::enable_if_t<X != 2 && X != 3, void>
Vector<T, N>::cross(Vector const& other) const 
{ 
    // Valid compile time error
    static_assert(X == 2 || X == 3, "No cross product for Dimensions < 2 or > 3");
}

template <typename T, std::size_t N> 
template <std::size_t X>
std::enable_if_t<X == 2, T> 
Vector<T, N>::cross(Vector<T, N> const& other) const 
{ 
    return _data[0] * other._data[1] - _data[1] * other._data[0];
}

template<typename T, std::size_t N> 
template <std::size_t X>
std::enable_if_t<X == 3, Vector<T, 3>>
Vector<T, N>::cross(Vector<T, N> const& other) const 
{
    Vector<T, 3> ret;
    ret._data[0] = _data[1] * other._data[2] - _data[2] * other._data[1];
    ret._data[1] = _data[2] * other._data[0] - _data[0] * other._data[2];
    ret._data[2] = _data[0] * other._data[1] - _data[1] * other._data[0];

    return ret;
}

// Cross for 2D Vector specialization
