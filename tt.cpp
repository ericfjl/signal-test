#include <iostream>

#include "/home/wire/signal/linux-sgx/linux/installer/bin/sgxsdk/include/sgx_capable.h"

using namespace std;

int main(int argc, char *argv[])
{
    sgx_device_status_t status;
    int isc = 1;
    sgx_status_t ret = sgx_is_capable(&isc);
    cout << "is_capable = " << ret << endl;
/*      SGX_ENABLED,
      SGX_DISABLED_REBOOT_REQUIRED,
      SGX_DISABLED_LEGACY_OS, 
      SGX_DISABLED, 
      SGX_DISABLED_SCI_AVAILABLE,
      SGX_DISABLED_MANUAL_ENABLE, 
      SGX_DISABLED_HYPERV_ENABLED, 
      SGX_DISABLED_UNSUPPORTED_CPU
    */
    ret = sgx_cap_get_status(&status);
    cout << "cap_get_status = " << ret << endl;    
    switch (status) {
    case SGX_ENABLED:
        cout << "SGX_ENABLED\n";
        break;
    case SGX_DISABLED_REBOOT_REQUIRED:
        cout << "1\n";        
        break;
    case SGX_DISABLED_LEGACY_OS:
        cout << "2\n";                
        break;            
    case SGX_DISABLED:
        cout << "3\n";                
        break;        
    case SGX_DISABLED_SCI_AVAILABLE:
        cout << "4\n";                
        break;        
    case SGX_DISABLED_MANUAL_ENABLE:
        cout << "5\n";                
        break;        
    case SGX_DISABLED_HYPERV_ENABLED:
        cout << "6\n";                
        break;        
    case SGX_DISABLED_UNSUPPORTED_CPU:
        cout << "7\n";                
        break;        
    default:
        cout << "nnnn\n";
        break;
    }

    sgx_device_status_t st2 = SGX_ENABLED;
    ret = sgx_cap_enable_device(&st2);
    cout << "cap_enable_status = " << ret << endl;
    
    ret = sgx_cap_get_status(&status);
    cout << "cap_get_status = " << ret << endl;   
    switch (status) {
    case SGX_ENABLED:
        cout << "SGX_ENABLED\n";
        break;
    case SGX_DISABLED_REBOOT_REQUIRED:
        cout << "1\n";        
        break;
    case SGX_DISABLED_LEGACY_OS:
        cout << "2\n";                
        break;            
    case SGX_DISABLED:
        cout << "3\n";                
        break;        
    case SGX_DISABLED_SCI_AVAILABLE:
        cout << "4\n";                
        break;        
    case SGX_DISABLED_MANUAL_ENABLE:
        cout << "5\n";                
        break;        
    case SGX_DISABLED_HYPERV_ENABLED:
        cout << "6\n";                
        break;        
    case SGX_DISABLED_UNSUPPORTED_CPU:
        cout << "7\n";                
        break;        
    default:
        cout << "nnnn\n";
        break;
    }

    return 0;
}
