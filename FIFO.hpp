//
//  FIFO.hpp
//  HW_04.0_Template
//
//  Created by Yuen-Wen Lee on 7/2/23.
//

#ifndef FIFO_hpp
#define FIFO_hpp

#include <cstdio>
#include <cstdint>


template <class T>
class FIFO {
private:
    const char *name;
    uint32_t    fifo_size;
    T         **fifo;
    uint32_t    indx_out;   // The 1st slot for FIFO output.
    uint32_t    indx_in;    // Next available slot for FIFO input.
    uint32_t    length;     // The FIFO length, it is the distance between
                            // indx_out and indx_in.
                            // The length will be 0 ~ (fifo_size - 1).
public:
    FIFO() {
        name = "no name";
        fifo_size = 0;
        fifo = nullptr;
        indx_out = indx_in = 0;
        length = 0;
    }
    FIFO(const char *name, uint32_t size) {
        this->name = name;
        fifo_size = size + 1;
        fifo = new T* [fifo_size];
        indx_out = indx_in = 0;
        length = 0;
    }

    bool config(const char *name, uint32_t size);

    bool input(T *item_p);
    T *output(void);
    
    uint32_t get_length(void);
    void dump(const char *prfx);
};


template<class T>
bool FIFO<T>::config(const char *name, uint32_t size)
{
    if (length != 0) {
        printf("Error, resize FIFO \'%s\', but it\'s not empty!\n", name);
        return false;
    }

    if (size == 0) {
        if (fifo != nullptr) {
            delete [] fifo;
            fifo = nullptr;
        }
        fifo_size = 0;
        this->name = "no name";

    } else {
        size++;
        if (fifo_size != size) {
            if (fifo != nullptr) {
                delete [] fifo;
            }

            fifo_size = size;
            if (size > 0) {
                fifo = new T* [size];
            }
            indx_in = indx_out = 0;
        }

        this->name = name;
    }

    return true;
}

template<class T>
bool FIFO<T>::input(T *item_p)
{
    if (fifo_size == 0) {
        printf("Error, input failed, FIFO \'%s\' is not configured!\n", name);
        return false;

    } else if (length < (fifo_size - 1)) {
        length++;
        fifo[indx_in] = item_p;
        if (indx_in == (fifo_size - 1)) {
            indx_in = 0;
        } else {
            indx_in++;
        }
        return true;

    } else {
        printf("Error, input failed, FIFO \'%s\' is full!\n", name);
        return false;
    }
}

template<class T>
T *FIFO<T>::output()
{
    if (length > 0) {
        T *item_p = fifo[indx_out];
        length--;
        if (indx_out == (fifo_size - 1)) {
            indx_out = 0;
        } else {
            indx_out++;
        }
        return item_p;

    } else {
        printf("Warning, output from empty FIFO \'%s\'!\n", name);
        return nullptr;
    }
}

template<class T>
uint32_t FIFO<T>::get_length(void)
{
    return length;
}

template<class T>
void FIFO<T>::dump(const char *prfx)
{
    printf("%sFIFO \'%s\' - ", prfx, name);
    if (fifo_size == 0) {
        printf("Not Configured !!!\n");
        return;
    } else if (length > (fifo_size - 1)) {
        printf("Error (%d > %d)\n", length, (fifo_size - 1));
    } else if (length == (fifo_size - 1)) {
        printf("FULL !!!\n");
    } else {
        printf("\n");
    }
    printf("%s  length: %d (size: %d)\n", prfx, length, (fifo_size - 1));
    printf("%s  indx_out: %d, indx_in: %d\n", prfx, indx_out, indx_in);
}

#endif /* FIFO_hpp */
