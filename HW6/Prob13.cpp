template<typename T>
T put(T a, T b[], int index)
{
    T old = b[index];
    b[index] = a;
    return old;
}