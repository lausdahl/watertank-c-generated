# to profile run

```bash
# Generate makefile
cmake -DCMAKE_BUILD_TYPE=Debug .

# make and profile for leaks
make &&valgrind --tool=memcheck --leak-check=full ./wt2-standalone

# Profile for memory usage in the heap
(valgrind --tool=massif --time-unit=B --massif-out-file=massif.out ./wt2-standalone ) && ms_print massif.out | head -n 30

```



# Mic

```
Device: atmega1284p
Frequency: 8000000
Optimization: -O0

Do not pack structs (-fpack-struct)
```


## Inclides
```
-Ivdmlib
```

## Libraries
```
libm.a
```
