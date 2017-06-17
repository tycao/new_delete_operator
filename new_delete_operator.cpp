#include <new>
#include <cstdlib>
#include <iostream>
using namespace std;

void* operator new(size_t size)
{
    if (void* mem = malloc(size))
    {
        cout << "operator new....." << endl;
        return mem;
    }
    else
        throw std::bad_alloc();
}

void operator delete(void *mem) noexcept
{
    cout << "operator delete....." << endl;
    free(mem);
}

int main()
{
    int* ptr = new int;
    delete ptr;
    return 0;
}
