/*
Here's a complete explanation and working C example showing how to use:

dlopen() — load a shared library at runtime

dlsym() — get function pointer from the library

dlerror() — get error messages from dl*() functions

dlclose() — unload the library


-: Note -:
    To achieve dynami runtime linking without function pointer not possible.
*/
#include <stdio.h>

void hello() {
    printf("Hello from shared library!\n");
}

int add(int a, int b) {
    return a + b;
}

/*
🔧 Compile to .so:
===================
gcc -fPIC -c mylib.c -o mylib.o
gcc -shared -o libmylib.so mylib.o

✅ 2. Write the Main Program Using dlopen()
============================================
*/

#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    void (*hello_func)();
    int (*add_func)(int, int);
    char *error;

    // 1. Open the shared library
    handle = dlopen("./libmylib.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    // 2. Clear existing errors
    dlerror();

    // 3. Get function pointer to hello()
    hello_func = (void (*)()) dlsym(handle, "hello");
    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "Error finding hello: %s\n", error);
        dlclose(handle);
        return 1;
    }

    // 4. Get function pointer to add()
    add_func = (int (*)(int, int)) dlsym(handle, "add");
    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "Error finding add: %s\n", error);
        dlclose(handle);
        return 1;
    }

    // 5. Call the functions
    hello_func();
    printf("add(5, 3) = %d\n", add_func(5, 3));

    // 6. Close the library
    dlclose(handle);
    return 0;
}
/*
🔧 Compile and Run
===================
gcc -o main main.c -ldl
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
./main

✅ Output:
Hello from shared library!
add(5, 3) = 8

📘 Summary of Functions
-----------------------------------------------------
| Function    | Description                         |
| ----------- | ----------------------------------- |
| `dlopen()`  | Load the shared library             |
| `dlsym()`   | Lookup a symbol (function/variable) |
| `dlerror()` | Get error if above two fail         |
| `dlclose()` | Unload the library                  |


===================================================================================================
*/
