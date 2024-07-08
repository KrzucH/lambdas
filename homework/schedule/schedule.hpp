#pragma once
#include <functional>
#include <thread>

void schedule(std::function<void()> func, std::chrono::seconds duration) {
    std::this_thread::sleep_for(duration);
    func();
}

void schedule(std::function<void(int)> func, std::chrono::seconds duration, int value) {
    std::this_thread::sleep_for(duration);
    func(value);
}

void schedule(std::function<void(std::string, double)> func, std::chrono::seconds duration, std::string text, double value) {
    std::this_thread::sleep_for(duration);
    func(text, value);
}

template <typename function, typename... args>
void schedule(function func, std::chrono::seconds duration, args... value) {
    std::this_thread::sleep_for(duration);
    func(value...);
}