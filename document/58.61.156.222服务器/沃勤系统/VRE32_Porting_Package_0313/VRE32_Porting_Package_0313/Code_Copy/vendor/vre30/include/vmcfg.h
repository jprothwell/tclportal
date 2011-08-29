/*****************************************************************************
 * 
 * 配置文件管理模块。系统使用WIN32 INI FILE类似的配置文件格式，即基于文本的以区分隔
 * 的配置格式，下面是一个配置文件样本。
 *
 *   #
 *   # This is global configuration section.
 *   #
 *   [global]
 *   live time=50
 * 
 *   [locale]
 *   country=zh
 *   language=CN
 *
 * 每对方括号内是区名，每个区下有多个配置项目，配置文件不限制大小，实际能够读入的配置
 * 项目数量取决于内存的大小。配置项每行为一条记录，#开头表示这是注释行。配置项的名称
 * 和值之间用"="分隔，等号前后的空格会被自动忽略，配置名称前导空格和配置值尾部的空格
 * 会被保留。配置名称的最大长度是32个字符（包括\0），配置值的最大长度是128个字符
 * （包括\0）。
 *
 * $Author: guangyu.tang $
 * $Date: 2008/03/26 03:59:12 $
 *
 ****************************************************************************/

#ifndef VMCFG_H
#define VMCFG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmstdlib.h"

typedef struct _vm_cfg_handle_t {
	VMWCHAR filename[128];
	VMFILE	file;
	vm_dyn_array_t *sections;
} vm_cfg_handle_t;

typedef struct _vm_cfg_section_t {
	char name[32];
	vm_dyn_array_t *items;
} vm_cfg_section_t;

typedef struct _vm_cfg_item_t {
	char name[32];
	char value[128];
} vm_cfg_item_t;

/**
 * 打开配置文件。
 *
 * @param filename		配置文件名。
 *
 * @return				返回配置文件句柄指针如果打开成功，否则返回NULL。
 */
vm_cfg_handle_t* vm_open_config(VMWSTR filename);

/**
 * 保存配置到文件。
 *
 * @param handle		配置文件句柄指针。
 *
 * @return				返回0表示保存成功，否则为失败。
 */
VMINT vm_save_config(vm_cfg_handle_t* handle);

/**
 * 关闭配置文件。
 *
 * @param handle		配置文件句柄指针。
 */
void vm_close_config(vm_cfg_handle_t* handle);

/**
 * 读配置项，配置项的值以字符串形式返回。
 *
 * @param handle		配置文件句柄指针。
 * @param section		区名，如果是NULL则表示不区分区名，需要遍历整个配置表。
 * @param name			配置项名称。
 * @param value			配置项的值。
 * @param def			当配置项没有配置时返回的默认值。
 *
 * @return				返回0表示读取配置成功，否则返回错误码。
 */
VMINT vm_get_cfg_str(vm_cfg_handle_t* handle, char* section, char* name, 
	 char* value, char* def);

/**
 * 设置字符串格式的配置项目。
 *
 * @param handle		配置文件句柄指针。
 * @param section		区名，如果是NULL则表示不区分区名，需要遍历整个配置表。
 * @param name			配置项名称。
 * @param value			配置项的值。
 *
 * @return				返回0表示更新成功，否则返回错误码。
 */
VMINT vm_set_cfg_str(vm_cfg_handle_t* handle, char* section, char* name,
	 char* value);

/**
 * 读配置项，配置项的值以整形数形式返回。
 *
 * @param handle		配置文件句柄指针。
 * @param section		区名，如果是NULL则表示不区分区名，需要遍历整个配置表。
 * @param name			配置项名称。
 * @param value			配置项的值。
 * @param def			当配置项没有配置时返回的默认值。
 *
 * @return				返回0表示读取配置成功，否则返回错误码。
 */
VMINT vm_get_cfg_int(vm_cfg_handle_t* handle, char* section, char* name, 
	 int* value, int def);

/**
 * 设置整形数格式的配置项目。
 *
 * @param handle		配置文件句柄指针。
 * @param section		区名，如果是NULL则表示不区分区名，需要遍历整个配置表。
 * @param name			配置项名称。
 * @param value			配置项的值。
 *
 * @return				返回0表示更新成功，否则返回错误码。
 */
VMINT vm_set_cfg_int(vm_cfg_handle_t* handle, char* section, char* name,
	 int value);

#ifdef __cplusplus
}
#endif

#endif
