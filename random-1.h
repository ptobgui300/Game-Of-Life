#ifndef RANDOM_H
#define RANDOM_H


class random
{
public:
    random();
    int GetNext(int lo, int hi);

private:
    //static member variable keeps the random number generator from being seeded everytime a
    // new Random object is instantiated.
    //Note the initialization of the static variable in the .cpp file.
    static int objectCount;

};

#endif // RANDOM_H
