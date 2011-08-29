#ifndef		_VM_FILE_REMAP_
#define		_VM_FILE_REMAP_

#include "vmsys.h"
#include "vmio.h"

#define REMAP_FILENAME_MAX_LEN 260
//#define REMAP_FILENAME_MAX_LEN 48


#define VM_PERMISSION_SYS_DRV  1
#define VM_PERMISSION_USR_DRV  2

/**
 * 打开应用本地文件。
 *
 * @param filename		以UCS2格式编码的文件路径。
 * @param mode			文件打开模式，读（MODE_READ），写（MODE_WRITE），
 *						无论文件存在与否总是创建之（MODE_CREATE_ALWAYS_WRITE）。
 * @param binary		TRUE表示以二进制格式打开文件，FALSE表示以ASCII方式打开文件。
 *
 * @return				成功打开则返回非负数句柄，如果为负数则表示失败。
 */
VMFILE vm_file_open_remap(const VMWSTR filename, VMUINT mode, VMUINT binary);


/**
 * 删除应用本地文件。
 * 
 * @param filename		以UCS2编码格式的文件路径。
 *
 * @return				返回0表示成功，否则为失败。
 */
VMINT vm_file_delete_remap(const VMWSTR filename);


/**
 * 应用本地文件重命名。
 * 
 * @param filename		以UCS2格式编码的原始文件路径。
 * @param newname		以UCS2格式编码的目标文件路径。
 *
 * @return				返回0表示成功，否则为失败。
 */
VMINT vm_file_rename_remap(const VMWSTR filename, const VMWSTR newname);


/**
 * 在应用本地查找给定目录下的文件，可以使用*通配符。
 *
 * @param pathname			查找路径。
 * @param info				找到的文件信息。
 *
 * @return					返回负数表示失败，否则返回大于或等于0的一个查找句柄。
 */
VMINT vm_find_first_remap(VMWSTR pathname, struct vm_fileinfo_t* info);


/**
 * 创建应用本地目录。
 *
 * @param dirname		以UCS2格式编码的路径名。
 *
 * @return				返回0表示成功，否则为失败。
 */
VMINT vm_file_mkdir_remap(const VMWSTR dirname);


/**
 * 删除应用本地目录。
 *
 * @param dirname		以UCS2格式编码的被删除路径名。
 *
 * @return				返回0表示成功，否则为失败。
 */
VMINT vm_file_rmdir_remap(const VMWSTR dirname);

/**
 * 查找给定目录下的文件，可以使用*通配符。
 *
 * @param pathname			查找路径。
 * @param direntry				找到的文件的目录信息。
 *
 * @return					返回负数表示失败，否则返回大于或等于0的一个查找句柄。
 */
VMINT vm_find_first_remap_ext(VMWSTR pathname,  vm_fileinfo_ext * direntry);

/**
 * 设置文件属性。
 * 设置的值不能包含VM_FS_ATTR_VOLUME，VM_FS_ATTR_DIR，VM_FS_LONGNAME_ATTR
 * 文件属性的值为或运算的组合值，具体值请参考文件属性的宏定义。
 *
 * @param filename   文件名(带全路径)。
 * @param attributes  文件属性。
 *
 * @return       返回0表示成功，负数为失败。
 */
VMINT vm_file_set_attributes_remap(const VMWSTR filename, VMBYTE attributes);

/**
 * 获取文件属性。
 * 文件属性的值为或运算的组合值，具体值请参考文件属性的宏定义。
 *
 * @param filename  文件名(带全路径)。
 *
 * @return 返回文件属性，负数为失败。
 */
VMINT vm_file_get_attributes_remap(const VMWSTR filename);

#endif
