# [accumulate](https://cplusplus.com/reference/numeric/accumulate/)

* Returns the result of accumulating all the values in the range [first,last) to init.
* The default operation is to add the elements up, but a different operation can be specified as binary_op.
  
* Working:

    ```cpp
    template <class InputIterator, class T>
    T accumulate (InputIterator first, InputIterator last, T init)
    {
    while (first!=last) {
        init = init + *first;  // or: init=binary_op(init,*first) for the binary_op version
        ++first;
    }
    return init;
    }
    ```

## Examples

*  ```cpp
    int myFunc(int x, int y) { return x + 2 * y;}

    int main () {
    int init = 100;
    int numbers[] = {10,20,30};

    int sum_result = accumulate(numbers, numbers + 3, init); //160

    int minus_result = accumulate(numbers, numbers + 3, init, minus<>()); //40
    
    int custom_result = accumulate(numbers, numbers + 3, init, myFunc); //220
    /*
        100 + 10 * 2 = 120
        120 + 20 * 2 = 160
        160 + 30 * 2 = 220
    */
    }
    ```

