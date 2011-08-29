/*****************************************************************************
 *
 * 程序资源管理工具。VRE应用程序的资源根据执行文件格式不同而存放在不同的位置，对于
 * ELF格式的可执行文件，资源（如图像、声音）存放在一个特定的SECTION内（.vmres）。
 * 对于PE格式的WIN32执行文件，资源文件被打包在执行文件的尾部。打包器的实现细节由
 * 系统实现，应用侧只需要调用相应接口函数就可以完成资源打包和读出任务。
 *
 * WIN32 PE格式文件打包格式：
 *
 *   +-----------------------------+
 *   | PE Executable File(.exe)    |
 *   +-----------------------------+
 *   | VRE Resource Section.       |
 *   +-----------------------------+
 *   | Resource Head.              |
 *   +-----------------------------+
 *
 *   Resource Head是一个结构体，定长，每个成员变量都是4字节对齐。
 *     struct vm_pe_res_head_t {
 *         char sign[6];		// "VMRES\xF9"
 *         int  offset;			// 插入的资源块在文件中的偏移量——从头开始，字节单位。
 *         int  size;           // 插入的资源块大小，字节单位。
 *         char reserved[8];	// 保留字段，全部填0。
 *     };
 *
 * ARM ELF格式文件打包格式：
 *
 *   +-----------------------------+
 *   | ELF Executable File(.axf)   |
 *   +-----------------------------+
 *   | VRE Resource Section.       |
 *   | Inserted as .VM_RES         |
 *   +-----------------------------+
 *
 *   在ELF格式中资源以section的形式插入文件，因此不需要附加的资源头。
 *
 * 资源区不区分平台都是一个格式：
 *
 *   +-----------------------------+
 *   | Resource Descriptor Array   |
 *   +-----------------------------+
 *   | Resource Body.              |
 *   +-----------------------------+
 *
 *   Resource descriptor array是一个结构数组，成员变量都是4字节对齐。
 *     struct _vm_res_desc_t {
 *         char* name;			// 资源名称。
 *         int   offset;        // 资源从文件头开始的偏移量，字节单位。
 *         int   size;          // 资源大小，字节单位。
 *     };
 *     数组以一个size等于0的结构体结束，也就是说resource descriptor array
 *     的个数总比资源文件个数大一。
 *
 * $Author: guangyu.tang $
 * $Date: 2009/03/06 01:38:48 $
 *
 ****************************************************************************/

#ifndef VMRES_H
#define VMRES_H

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 把资源写入可执行文件中，目前系统可以识别的文件后缀名有.axf(ELF)、.exe(WIN32 PE)。
 * 
 * @param filename		要写入资源的可执行文件名，必须是完整路径。
 * @param res_fns		要打包的资源文件名列表，必须是完整路径。
 * @param fn_count		资源文件的数量。
 *
 * @return				返回0表示打包成功，否则返回错误码。
 */
VMINT vm_pack_resource(VMWSTR filename, VMWSTR *res_fns, VMINT fn_count);

/**
 * 从文件中读入资源，系统根据资源的长度自动为其分配内存，然后从文件读入到内存之中，
 * 程序员在使用完资源后必须调用vm_free()将其释放掉。
 *
 * @param res_name		资源名称，系统在打包时把资源文件名作为资源名称保存到
 *						目标文件中，因此这个参数就是对应的资源文件名，路径部分
 *						不需要给出。比如图像资源文件是"c:\\projects\\game\\1.gif"，
 *						其资源名称就是"1.gif"。
 * @param res_size		被读入的资源长度，字节单位。
 *
 * @return				返回资源数据。
 */
VMUINT8* vm_load_resource(char* res_name, VMINT* res_size);

/**
 * 从指定名称的文件中读入资源，系统根据资源的长度自动为其分配内存，然后从文件读入到内存之中，
 * 程序员在使用完资源后必须调用vm_free()将其释放掉。
 * 
 * @param filename		指定的文件名称，必须是完整的路径。
 * @param res_name		资源名称，系统在打包时把资源文件名作为资源名称保存到
 *						目标文件中，因此这个参数就是对应的资源文件名，路径部分
 *						不需要给出。比如图像资源文件是"c:\\projects\\game\\1.gif"，
 *						其资源名称就是"1.gif"。
 * @param res_size		被读入的资源长度，字节单位。
 *
 * @return				返回资源数据。
 */
VMUINT8* vm_load_resource_from_file(VMWSTR filename, char *res_name, VMINT *res_size);

#ifdef __cplusplus
}
#endif

#endif
