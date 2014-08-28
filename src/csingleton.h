#ifndef CSINGLETON_H
#define CSINGLETON_H


// http://www.daniweb.com/software-development/cpp/threads/251676/singleton-template-class-magic


#include <iostream>
template <typename T> class CSingleton
{
private:
    CSingleton(const CSingleton<T>&){};

protected:
    static T* _instance;
    CSingleton() {}

public:

    static T* instance()
    {
        if(_instance == NULL)
            _instance = new T();
        return _instance;
    }
};
template <typename T> T* CSingleton<T>::_instance;



#endif

