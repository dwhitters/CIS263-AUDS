#ifndef __H_AUDS__
#define __H_AUDS__

/**
 * This is the class for the Almost Useless Data Structure.
 * It holds any type of object through the use of a class template.
 *
 * @author David Whitters
 * @date 5/18/17
 */

#include "AUDS.h"
#include <stdlib.h>
#include <time.h>

/** The initial size of each data structure. */
const int INIT_SIZE = 100;

/**
    The multiplier applied to the structure size whenever creating a
    larger structure.
 */
const float SIZE_MULT = 1.5;

/**
    A class for holding any type of object through the use of a
    class template.
*/
template <typename T>
class AUDS
{
    public:

        /**
            Constructor, initializes a new data structure.
        */
        AUDS()
        {
            num_objects = 0;
            data_struct = new T[INIT_SIZE];
            struct_size = INIT_SIZE;
        }

        /**
            Constructor, loops through other's data and copies it into
            this data. If the passed in object's data structure is
            larger than the this object's initial data size,
            it creates new data structure.

            @param AUDS Constant reference to another instance of the
                        AUDS class.
       */
        AUDS(const AUDS &other)
        {
            struct_size = INIT_SIZE;
            num_objects = other->num_objects;

            /*
                Make the structure large enough to contain all elements
                stored in other, then copy them into the structure.
            */
            data_struct = resize(num_objects, other->data_struct);
        }

        /**
            Destructor, destroys all data on heap.
        */
        ~AUDS()
        {
            delete[] data_struct;
        }

        /**
            Performs the copy and swap to set one object equal to
            another. Also performs a deep copy.

            @param other Another instance of this object who's instance
                         variable values will be copied into this
                         object's instance variables.

            @return AUDS& A reference to this instance of an
                          AUDS object.
        */
        AUDS& operator=(AUDS other)
        {
            return *this;
        }

        /**
            Returns the current number of objects the structure
            is holding.

            @return int The number of objects the structure contains.
        */
        int size()
        {
            return num_objects;
        }

        /**
            Adds the generic element to the data structure.

            @param x The generic element to be added to the data
                     structure.
        */
        void push(T x)
        {
            if(num_objects >= struct_size)
            {
                data_struct = resize(num_objects + 1, data_struct);
            }

            data_struct[num_objects] = x;
            ++num_objects;
        }

        /**
            Removes a random item from the list. Moves the last item
            in the array to the spot that was occupied by the removed
            element.

            @return T A random generic object stored in the structure.
        */
        T pop()
        {
            --num_objects;

            /**
                Seed the pseudo-random number generator. Example use
                used from cplusplus.com.
            */
            srand(time(NULL));

            // Random number between 0 and number of objects in the structure.
            int rand_val = rand() % num_objects;

            T temp = data_struct[rand_val];

            // Set the random element to the previous last element in the structure.
            data_struct[rand_val] = data_struct[num_objects];

            return temp;
        }

    private:

        // Instance variables.
        int num_objects;
        int struct_size;
        T *data_struct;

        /**
            Increases the data structure size in 50% increments until
            the size of the structure is greater than the number of
            objects to be stored in it.

            @param new_num_objects The number of objects to be stored
                                   in the data structure.
            @param from_struct Pointer to the struct that is going
                               to be copied from.

            @return T* Pointer to the new larger struct.
        */
        T* resize(int new_num_objects, T* from_struct)
        {
            // Increase structure size by 50% as needed.
            while(new_num_objects > struct_size)
            {
                struct_size *= SIZE_MULT;
            }

            /*
                Used in the event that data_struct is the from_struct
                param. This way, it's not overwritten before copying.
            */
            T* to_struct = new T[this->struct_size];

            /*
                Copy all values into the structure held by this
                instance.
            */
            deepCopy(from_struct, to_struct, num_objects);

            // De-allocate the memory used by from_struct.
            delete[] from_struct;

            return to_struct;
        }

        /**
            Copies the contents of a data structure into the structure
            held by this instance. No bounds checking as this function
            is only called after resizing.

            @param from_struct Pointer to a data structure who's
                              contents will be copied into the
                              structure held by this instance.
            @param to_struct Pointer to a data structure that will
                             receive the contents of the from_struct.
            @param num_objects Number of objects to copy from the
                               from_struct and place in the to_struct.
        */
        void deepCopy(T * from_struct, T * to_struct, int num_objects)
        {
            for(int i = 0; i < num_objects; i++)
            {
                to_struct[i] = from_struct[i];
            }
        }

};

#endif // __H_AUDS__
