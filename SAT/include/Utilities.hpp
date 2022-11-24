#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace sf;

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 800;

template <typename T> 
inline float DotProduct(Vector2<T> v0, Vector2<T> v1) {
    return (v0.x * v1.x) + (v0.y * v1.y);
}

template <typename T> 
inline float Distance(Vector2<T> v0, Vector2<T> v1) {
    return sqrtf((v0 - v1).x * (v0 - v1).x + (v0 - v1).y + (v0 - v1).y);
}

template <typename T>
inline float Length(sf::Vector2<T> v) {
	return sqrtf(v.x * v.x + v.y * v.y);
}

template <typename T> 
inline Vector2<T> VectSum(Vector2<T> v0, Vector2<T> v1) {
    return Vector2<T>(v1.x + v0.x, v1.y + v0.y);
}

template <typename T> 
inline Vector2<T> VectDiff(Vector2<T> v0, Vector2<T> v1) {
    return Vector2<T>(v0.x - v1.x, v1.y - v0.y);
}

template <typename T> 
inline Vector2<T> Normal(Vector2<T> v) {
    return Vector2<T>(-v.y, v.x);
}

template <typename T> 
inline Vector2<T> Normalize(Vector2<T> v) {
    float length = Length(v);

    return v / length;
}

#define _USE_MATH_DEFINES
