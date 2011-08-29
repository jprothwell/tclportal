#ifndef VMUA_H_
#define VMUA_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * VREÏµÍ³µÄUSER AGENT¡£
 */
#ifndef __VRE_CIPHER_UA__
#define VRE_CHAR                -  
#define _VM_STR(x)              #x
#define VM_STR(x)               _VM_STR(x)
#define _VM_GET_UA_ID(x,y,z)    VM_STR(x##y##z)
#define VM_GET_UA_ID(x,y,z)     _VM_GET_UA_ID(x,y,z)
#define VRE_SYS_USER_AGENT      VM_GET_UA_ID(VRE_USER_AGENT_COMPANY,VRE_CHAR,VRE_USER_AGENT_PROJECT)
#endif

VMUINT vm_get_useragent(VMCHAR* value, VMUINT len);
VMUINT vm_get_host_version(VMCHAR* value, VMUINT len);

#ifdef __cplusplus
}
#endif 

#endif 