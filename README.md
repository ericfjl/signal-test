# signal-test
## when to use
enable sgx-driver by c++ coding
when the service is cloud and can't control the bios,this is only way to enable the sgx driver

## how to use
`````
$ cp  libsgx_capable.so  /usr/local/lib/
$ sudo ldconfig
$ g++ sgx.cpp -lsgx_capable -I$SGX_SDK/include
$ ./a.out
`````
