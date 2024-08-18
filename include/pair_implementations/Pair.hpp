#ifndef PAIR_
#define PAIR_

template <typename T1, typename T2>
class Pair
{
private:
    T1 object_1;
    T2 object_2;

public:
    Pair(T1 object1, T2 object2) : object_1(object1), object_2(object2) {};

    T1 getFirst() { return object_1; };
    T2 getSecond() { return object_2; };

    void setFirst(const T1 &obj) { object_1 = obj; }
    void setSecond(const T2 &obj) { object_2 = obj; }

    bool operator<(const Pair<T1, T2> &other) const
    {
        if (object_1 < other.object_1)
        {
            return true;
        }
        else if (object_1 == other.object_1)
        {
            return object_2 < other.object_2;
        }
        else
        {
            return false;
        }
    }

    bool operator<=(const Pair<T1, T2> &other) const
    {
        if (object_1 <= other.object_1)
        {
            return true;
        }
        else if (object_1 == other.object_1)
        {
            return object_2 <= other.object_2;
        }
        else
        {
            return false;
        }
    }

    bool operator>(const Pair<T1, T2> &other) const
    {
        if (object_1 > other.object_1)
        {
            return true;
        }
        else if (object_1 == other.object_1)
        {
            return object_2 > other.object_2;
        }
        else
        {
            return false;
        }
    }

    bool operator>=(const Pair<T1, T2> &other) const
    {
        if (object_1 >= other.object_1)
        {
            return true;
        }
        else if (object_1 == other.object_1)
        {
            return object_2 >= other.object_2;
        }
        else
        {
            return false;
        }
    }
};

#endif