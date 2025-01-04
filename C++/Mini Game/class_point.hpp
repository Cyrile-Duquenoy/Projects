#pragma once
#include<iostream>

template<typename T>
class Point{
    private:
        T x_;
        T y_;

    public:

        // Constructors
        Point() : x_(0), y_(0) {}; // Default constructor
        Point(T x, T y):x_(x),y_(y){} // Constructor #2
        Point(const Point<T>& p):x_(p.x_),y_(p.y_){} // Copy Constructor
        
        ~Point(){} // Destructor

        void print(); // Print Point

        T get_x(){return x_;};
        T get_y(){return y_;};

        // Overloading Operators
        Point<T> operator+(const Point<T>& p) const;
        Point<T> operator-(const Point<T>& p) const;
        Point<T>& operator+=(const Point<T>& p);
        Point<T>& operator-=(const Point<T>& p);
        
};

template<typename T>
void Point<T>::print(){
    std::cout << "(" << x_ << ", " << y_ << ")" << std::endl;
}

// Overloading Operators
template<typename T>
Point<T> Point<T>::operator+(const Point<T>& p) const{
    return Point<T>(x_ + p.x_, y_ + p.y_);
}

template<typename T>
Point<T> Point<T>::operator-(const Point<T>& p) const{
    return Point<T>(x_ - p.x_, y_ - p.y_);
}

template<typename T>
Point<T>& Point<T>::operator+=(const Point<T>& p){
    x_ += p.x_;
    y_ += p.y_;
    return *this;
}

template<typename T>
Point<T>& Point<T>::operator-=(const Point<T>& p){
    x_ -= p.x_;
    y_ -= p.y_;
    return *this;
}