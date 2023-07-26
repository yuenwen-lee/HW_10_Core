//
//  Stack.hpp
//  HW_04.0_Template
//
//  Created by Yuen-Wen Lee on 6/27/23.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <cstdio>
#include <cassert>


template <class T>
class Stack {
private:
    const char *s_name;
    T         **stack;
    int32_t     s_size;
    int32_t     indx;

public:
    Stack() {
        s_name = "no name";
        s_size = 0;
        stack = nullptr;
        indx = -1;
    }

    void        config(const char *name, uint32_t size);
    T          *top(void);
    T          *pop(void);
    bool        push(T *item_p);

    uint32_t    size(void);
    uint32_t    available(void);
    const char *name(void);
    void        dump(const char *prfx);
};


template <class T>
void Stack<T>::config(const char *name, uint32_t size)
{
    if (indx != -1) {
        printf("Error, resize stack \'%s\', but it is not empty!\n", name);
        return;
    }

    this->s_name = name;
    if (this->s_size != size) {
        if (stack != nullptr) {
            delete *stack;
        }

        assert(size >= 0);
        this->s_size = size;
        if (size > 0) {
            stack = new T* [size];
        }
    }
}

template <class T>
T *Stack<T>::top(void)
{
    if (indx < 0) {
        return nullptr;
    } else {
        return stack[indx];
    }
}

template <class T>
T *Stack<T>::pop(void)
{
    if (indx < 0) {
        return nullptr;

    } else {
        T *item_p = stack[indx];
        indx--;
        return item_p;
    }
}

template <class T>
bool Stack<T>::push(T *item_p)
{
    if (indx == (s_size - 1)) {
        return false;

    } else {
        indx++;
        stack[indx] = item_p;
        return true;
    }
}

template <class T>
uint32_t Stack<T>::size(void)
{
    return s_size;
}

template <class T>
uint32_t Stack<T>::available(void)
{
    return (uint32_t) (s_size - 1 - indx);
}

template <class T>
const char *Stack<T>::name(void)
{
    return s_name;
}

template<class T>
void Stack<T>::dump(const char *prfx)
{
    printf("%sStack \'%s\' - depth: %d (size: %d)\n",
           prfx, s_name, (indx + 1), s_size);
}

#endif /* Stack_hpp */
