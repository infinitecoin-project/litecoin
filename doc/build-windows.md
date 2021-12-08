## The windows version uses cross compilation.

```
cd depends
make HOST=x86_64-w64-mingw32
cd ..
./autogen.sh 
CONFIG_SITE=$PWD/depends/x86_64-w64-mingw32/share/config.site ./configure --prefix=/$(pwd)/depends/x86_64-w64-mingw32
make
```

I only cross-compile successfully in ubuntu system, I don't know about other systems.
