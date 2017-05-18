/**
 * This is the interface fiile for the Almost Useless Data Structure.
 * It holds any type of object through the use of a class template.
 *
 * @author David Whitters
 * @date 5/18/17
 */

/**
    A class for holding any type of object through the use of a
    class template.
*/
template <typename T>
class AUDS
{
    public:

        /**
            Constructor, initializes new data structure.
        */
        AUDS();

        /**
           Loop through other data and copy it into this data.
           If larger than current data size, create new data structure.
        */
        AUDS(const AUDS &other);

        /**
           Performs the copy and swap to set one object equal to another.
           Also performs a deep copy.
        */
        AUDS& operator=(AUDS other);

        /**
            Destructor, destroys all data on heap.
        */
        ~AUDS();

        /**
            Returns the current number of objects the structure is holding.
        */
        int size();

        /**
            Adds the generic element to the data structure.
        */
        void push(T x);

        /**
            Removes a random item from the list. Moves the last item
            in the array to the spot that was occupied by the removed
            element.
        */
        T pop();

    private:

        int num_objects;
};
