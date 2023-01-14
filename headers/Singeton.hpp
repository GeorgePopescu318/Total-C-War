//
// Created by George on 1/13/2023.
//

#ifndef MAIN_CPP_SINGETON_HPP
#define MAIN_CPP_SINGETON_HPP

template<typename T>
class Singleton {
private:
    static T *instance;

protected:
    Singleton() {}

public:
    static T *getInstance() {
        if (!instance)
            instance = new T;

        return instance;
    }
};

template<typename T>
T *Singleton<T>::instance = nullptr;
#endif //MAIN_CPP_SINGETON_HPP
