# IdleGame

- **Pure Virtual Functions:** 
    In C++, when you declare a function with '=0' at the end, it means that the function is a pure virtual function. A pure virtual function is a virtual function that has no implementation in the base class and must be overriden by any derived class.
    ```
    virtual void GetsAttacked() = 0;
    ```

    Virtual destructor for proper cleanup 
    ```
    virtual ~WeaponBase() = default;  // Virtual destructor for proper cleanup
    ```


- there is a difference between \n and endl in cpp. in a nutshell when endl used it flushes the output buffer and then accepts new output values to the buffer on the other hand \n does not. performance difference may not be so clear in smaller programs but in large programs it causes big performance decreases.