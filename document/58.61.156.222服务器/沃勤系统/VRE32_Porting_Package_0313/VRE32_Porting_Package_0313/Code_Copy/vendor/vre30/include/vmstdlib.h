#ifndef VMSTDLIB_H_
#define VMSTDLIB_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

#define VM_CACHE_SIZE 4096

/**
 * 把块读写模式转换为流读写模式的缓存结构。
 */
struct vm_cache_t {
	VMINT eof;					/* 流结束标志。					*/
	VMINT avail;				/* 流中还有数据标志。			*/
	VMINT count;				/* 流剩余字节个数。				*/
	VMUINT8 buf[VM_CACHE_SIZE];	/* 缓冲区。						*/
};
typedef struct vm_cache_t vm_cache_t;

/**
 * 把数字格式字符串转换为整型数，如果字符串中出现a-f字符则
 * 执行十六进制格式数字转换，否则执行十进制格式数字转换。
 *
 * @param s			要转换的字符串。
 *
 * @return			返回-1表示转换失败，否则返回结果。
 */
int strtoi(char* s);

/**
 * 从完整文件路径中摘取出文件名称。
 *
 * @param path		完整路径名。
 * @param filename	文件名称。
 */
void vm_get_filename(VMWSTR path, VMWSTR filename);

/**
 * 从完整路径中截取路径部分，返回的路径包含结尾\字符。
 *
 * @param fullpath		包含文件名的完整路径。
 * @param path			返回的路径。
 * 
 * @return				返回0表示截取路径成功。
 */
VMINT vm_get_path(VMWSTR fullpath, VMWSTR path);

/**
 * 获得从2000年1月1日到今天为止的天数。
 *
 * @return			成功返回从2000年1月1日到今天为止的天数，错误返回-1。
 */
VMINT get_today_from_2000(void);

/**
 * 把源字符串中的小写字母转换为大写字母。
 *
 * @param dst			存放结果的目标字符串，程序员必须保证目标字符串长度
 *						大于等于源字符串长度。
 * @param src			被转换的源字符串。
 */
void vm_upper_case(char* dst, char* src);

/**
 * 把源字符串的大写字母转换为小写字母。
 *
 * @param dst			存放结果的目标字符串，程序员必须保证目标字符串长度
 *						大于等于源字符串长度。
 * @param src			被转换的源字符串。
 */
void vm_lower_case(char* dst, char* src);

/**
 * 比较两个字符串内容是否一致，字符串中的字母大小写不敏感。
 *
 * @param s1			字符串一。
 * @param s2			字符串二。
 *
 * @return				返回0表示两个字符串内容相同，否则返回-1。
 */
VMINT vm_string_equals_ignore_case(const char *s1, const char *s2);

/**
 * 向流缓存中写入数据。vm_write_cache()和vm_read_cache()函数为应用程序提供了
 * 流读写模式，SOCKET和C的文件读写函数都提供了块读写模式，没有提供流读写模式。
 * 系统通过这两个缓存读写函数把内存块转换为流，应用程序把数据写入缓冲后，
 * vm_read_cache()函数可以以流的方式向应用程序提供数据。vm_write_cache()
 * 用于向缓冲写入数据，如果写入的数据块长度大于缓存可用内存长度，系统只读取
 * 缓存能够容纳的字节数，多余部分会自动丢弃，程序员应当使用
 * vm_get_cache_free_space()函数获取缓存可用空间长度。
 *
 * @param cache			流缓存指针。
 * @param buf			要写入的数据块指针。
 * @param buf_len		要写入的数据块字节长度，小于0则表示没有更多数据可以
 *						写入，此时流缓冲的EOF标志位会被自动置起，vm_read_cache()
 *						将一直返回-1表示流管道已经关闭。
 *
 * @return				实际写入的字节数。
 */
VMINT vm_write_cache(vm_cache_t *cache, void *buf, VMINT buf_len);

/**
 * 从流缓冲中读入一定数量的字节。
 *
 * @param cache			流缓冲指针。
 * @param buf			读入数据的内存块指针。
 * @param buf_size		读入数据的内存块容量。
 * @param len			要读取的字节数。
 * 
 * @return				实际读入的字节数，返回0表示流管道已经关闭，缓冲之中没有
 *						更多数据可读。
 */
VMINT vm_read_cache(vm_cache_t *cache, void *buf, VMINT buf_size, VMINT len);

/**
 * 从流缓冲中读入一个字符。
 *
 * @param cache			流缓冲指针。
 * @param ch			要读入的字符指针。
 *
 * @return				返回0表示读成功，否则为错误码。
 */
VMINT vm_cache_read_char(vm_cache_t *cache, char *ch);

/**
 * 获得流缓冲可用空间长度。
 * 
 * @param cache			流缓冲指针。
 *
 * @return				返回流缓冲可用空间的字节数。
 */
VMINT vm_get_cache_free_space(vm_cache_t *cache);

/**
 * 从流缓冲中读入一行字符串，字符串以\r\n结尾。
 * 
 * @param line			要读入的字符串指针。
 * @param size			字符串容量。
 * @param cache			流缓冲指针。
 *
 * @return				返回0表示读字符串成功，否则为失败。
 */
VMINT vm_read_line(char* line, VMINT size, vm_cache_t* cache);

/**
 * 内存拷贝，类似于C库的memcpy函数。
 *
 * @param dst		目标地址。
 * @param src		源地址。
 * @param count		要拷贝的字节数。
 */
void vm_memcpy(void* dst, void* src, VMINT count);

/**
 * 动态数组。
 */
typedef struct _vm_dyn_array_t {
	/**
	 * 数组中每个结构体的长度。
	 */
	VMINT block_size;

	/**
	 * 初始数组长度。
	 */
	VMINT init_size;

	/**
	 * 每次增加的记录个数。
	 */
	VMINT inc_size;

	/**
	 * 数组中已有数据的下标个数。
	 */
	VMINT count;

	/**
	 * 数组中的下标个数。
	 */
	VMINT capacity;

	/**
	 * 动态数组的开始指针。
	 */
	void  *ptr;
} vm_dyn_array_t;

/**
 * 创建动态数组。动态数组是一个不定长的数组，当程序员向其加入新的记录时能够自动增长。
 * 动态数组在创建时会有一个初始化容量，在需要增加内存以存放新纪录时，动态数据会自动
 * 按照一个固定增长量扩大。动态数组是一个结构数组，程序员必须指明存放其中的结构体尺寸。
 *
 * @param init_size			动态数组的初始化长度。
 * @param inc_size			动态数组需要扩大以存放新纪录时的固定增长量。
 * @param block_size		存放在动态数组中的结构体长度。
 *
 * @return			返回NULL表示动态数组创建失败，否则返回动态数组指针。
 */
vm_dyn_array_t* vm_create_dyn_array(VMINT init_size, VMINT inc_size, VMINT block_size);

/**
 * 向动态数组增加新数据，新的数据被追加到数组的尾部。
 *
 * @param array				动态数组指针。
 * @param data				要增加的数据指针。
 *
 * @return			返回0表示增加成功，否则为错误码。
 */
VMINT vm_dyn_array_add(vm_dyn_array_t *array, void* data);

/**
 * 从动态数组中删除给定下标。
 *
 * @param array				动态数组指针。
 * @param idx				下标。
 *
 * @return					返回0表示成功。
 */
VMINT vm_dyn_array_del(vm_dyn_array_t *array, VMINT idx);

/**
 * 删除动态数组中所有的下标。
 *
 * @param array				动态数组指针。
 *
 * @return					返回0表示成功。
 */
VMINT vm_dyn_array_del_all(vm_dyn_array_t *array);

/**
 * 释放动态数组所占用的内存资源。
 *
 * @param array				动态数组指针。
 */
void vm_free_dyn_array(vm_dyn_array_t *array);

/**
 * 操作STACK成功。        
 */
#define STACK_OPERATE_SUCCESS				(0)

/**
 * 操作STACK参数错误。
 */
#define STACK_PARAM_ERROR					(-1)

/**
 * 操作STACK时没有足够的资源操作，操作失败。
 */
#define STACK_LEAK_RESOUCE					(-2)

/**
 * STACK满无法push操作。
 */
#define STACK_PUSH_OVERFLOW					(-3)

/**
 * 对空的STACK进行出栈操作。
 */
#define STACK_OPERATE_EMPTY_STACK			(-4)

/**
 * 错误STACK是传入STACK句柄错误。
 */
#define STACK_HANDLE_ERROR					(-5)

/**
 * 创建基于数组的栈结构，该栈的容量不能动态增长。在不使用堆栈的时候应该调用
 * vm_destory_stack销毁该堆栈，释放资源。
 * 
 * @param capability		栈的容量，基于数组的stack实现该容量是不会动态增加的。
 *							一旦创建了stack，那么该容量是不可变的，在入栈的元素
 *							已经达到了capability的值，再调用vm_push_stack将返回
 *							一个失败。
 * @param handle			指向客户程序的一个VMINT变量，如果返回STACK_OPERATE_SUCCESS
 *							那么函数内会对该指针指向的变量进行赋值。
 * @return					STACK_OPERATE_SUCCESS 创建栈成功。
 *							STACK_PARAM_ERROR实参小于等于0。
 *							STACK_LEAK_RESOUCE表示是缺少资源导致创建stack失败。
 *							这时候应用程序如果已经有创建了其它的stack，请调用
 *							vm_destory_statck函数，再调用本函数。
 */
VMINT vm_create_array_stack(VMINT capability, VMINT* handle);

/**
 * 创建一个基于链表的栈结构，该栈的容量是能够动态增加的。在不使用堆栈的时候应该调用
 * vm_destory_stack销毁该堆栈，释放资源。
 * 
 * 
 * @param capability	创建栈的时候初始容量。
 * @param handle			指向客户程序的一个VMINT变量，如果返回STACK_OPERATE_SUCCESS
 *										那么函数内会对该指针指向的变量进行赋值。
 * @return						STACK_OPERATE_SUCCESS创建栈成功。
 *										STACK_PARAM_ERROR实参小于等于0。
 *										STACK_LEAK_RESOUCE表示是缺少资源导致创建stack失败。
 *										这时候应用程序如果已经有创建了其它的stack，请调用
 *										vm_destory_statck函数，再调用本函数。
 */
VMINT vm_create_linked_stack(VMINT capability, VMINT* handle);

/**
 * 测试STACK是否为空，栈是否有元素。
 * 
 * @param					stackHandle	创建栈的时候得到句柄。			
 * @return					TRUE 表示该栈结构是空。
 *							FALSE 表示该栈结构为非空。
 */
VMINT vm_is_empty_stack(VMINT stackHandle);

/**
 * 元素入栈操作。
 * 
 * @return				STACK_OPERATE_SUCCESS表示入栈成功。
 *						STACK_PUSH_OVERFLOW表示入栈失败，堆栈已满了。
 *						对于基于的链表堆栈，如果返回本错误码
 *						表示系统留给堆栈的内存空间已经耗尽。
 *						STACK_HANDLE_ERROR错误的栈句柄。			
 */
VMINT vm_push_stack(VMINT stackHandle, void* ptr);

/**
 * 元素出栈操作。
 *
 * @return				STACK_OPERATE_SUCCESS 出栈操作成功。
 *						STACK_HANDLE_ERROR 错误的栈句柄。
 *						STACK_OPERATE_EMPTY_STACK 对空栈进行了出栈操作。
 */
VMINT vm_popup_stack(VMINT stackHandle, void** ptr);

/**
 * 得到堆栈下一个出栈的元素，但是该元素还在堆栈内。
 *
 * @return				STACK_OPERATE_SUCCESS 出栈操作成功。
 *						STACK_HANDLE_ERROR 错误的栈句柄。
 *						STACK_OPERATE_EMPTY_STACK 对空栈进行了peek操作。	
 */
VMINT vm_peek_stack(VMINT stackHandle, void** ptr);

/**
 * 清除现有堆栈内的所有内容，但是不销毁该堆栈。如果调用
 * 本函数后马上调用vm_peek_stack或vm_popup_stack将会得到
 * STACK_OPERATE_EMPTY_STACK的错误码。
 * 
 * @return				STACK_OPERATE_SUCCESS 操作成功。
 *						STACK_HANDLE_ERROR 错误的堆栈句柄。
 */
VMINT vm_reset_stack(VMINT stackHandle);

/**
 * 在堆栈里是否存在指定的元素。
 * 
 * @return				TRUE 表示存在。
 *						FALSE 表示不存在。
 */
VMINT vm_is_exist_stack(VMINT stackHandle, void* ptr);

/**
 * 销毁堆栈。释放堆栈占用的资源，如果堆栈里有元素，不会
 * 修改元素内容。对于不使用的堆栈都应该调用本函数来释放资源。
 * 如果在应用里创建了堆栈，在调用vm_exit_app退出出应用前都
 * 应该释放在应用程序里创建的堆栈来释放资源。
 *
 * @return				STACK_OPERATE_SUCCESS 操作成功。
 *						STACK_HANDLE_ERROR 错误的堆栈句柄。
 */
VMINT vm_destroy_stack(VMINT stackHandle);

/**
 * 判断字符串是否以给定字符串结尾。
 *
 * @param s1			被检查的字符串。
 * @param s2			结尾字符串。
 *
 * @return				如果s1以s2结尾则返回0，否则返回非0结果。
 */
VMINT vm_ends_with(const char *s1, const char *s2);

/**
 * vm_ends_with()的UCS2实现，接口语义一样，只是入口字符串换为UCS2格式。
 */
VMINT vm_wends_with(const VMWSTR s1, const VMWSTR s2);

/**
 * 产生临时文件名称，系统会保证临时文件名的唯一性。
 *
 * @param prefix		附加在临时文件名前的字符串，通常是路径。
 * @param filename		临时文件名，最长为128个字符，包括结尾的\0，
 *						程序员必须保证传入的字符数组有足够的空间
 *						来保存临时文件名。
 */
void vm_tmp_filename(char* prefix, char* filename);

/**
 * 安全UCS2字符串拷贝。这是wstrcpy的保护版本，当目标串没有足够空间存放源串
 * 内容时则自动裁剪多出部分。
 *
 * @param dest			目标字符串指针。
 * @param size			目标字符串的最大长度，以UCS2字符为单位。
 * @param src			源字符串指针。
 *
 * @return				实际拷贝的UCS2字符个数。
 */
VMINT vm_safe_wstrcpy(VMWSTR dest, VMINT size, VMWSTR src);

#define wstrlen			vm_wstrlen
/**
 * 计算以\0结尾的UCS2字符串长度。
 */
VMINT vm_wstrlen(VMWSTR s);

#define wstrcpy			vm_wstrcpy
/**
 * UCS2编码字符串拷贝。
 */
VMINT vm_wstrcpy(VMWSTR dst, const VMWSTR src);

#define wstrcat			vm_wstrcat
/**
 * UCS2编码字符串追加。
 */
VMINT vm_wstrcat(VMWSTR dst, const VMWSTR src);

#define wstrncpy		vm_wstrncpy
/**
 * 从源串拷贝n个字符到目标串，拷贝结束后自动在目标串尾部加上'\x0'，应用程序
 * 必须保证目标串有足够空间存放n+1个字符空间（包括尾部的'\x0'）。
 *
 * @param dst			目标串指针。
 * @param src			源串指针。
 * @param length		拷贝的字符个数。
 *
 * @return				拷贝的字符个数。
 */
VMINT vm_wstrncpy(VMWSTR dst, const VMWSTR src, VMINT length);

#define wstrcmp			vm_wstrcmp

/**
 * UCS2字符串比较。
 *
 * @param str_1			字符串1。
 * @param str_2			字符串2。
 *
 * @return				源字符串与目标字符串是否相等，相等
 *						返回0，不相等返回非0值。
 */
VMINT vm_wstrcmp(VMWSTR str_1, VMWSTR str_2);

/**
 * UCS2字符串的比较，忽略掉大写与小写的区别。
 * 
 * @param[in]			str_1 字符串1。
 * @param[in]			str_2 字符串2。
 * 
 */
VMINT vm_wstrcmp_ignore_case(VMWSTR str_1, VMWSTR str_2);

/**
 * 判断A串是否以B串开头。
 *
 * @param a				被检查字符串指针。
 * @param b				起始串指针。
 *
 * @return				如果A字符串开始部分与B串一致则返回0，比如"abcd"是
 *						以"ab"开始则返回0，否则返回非0结果。
 */
VMINT vm_wstarts_with(VMWSTR a, VMWSTR b);

#ifdef __cplusplus
}
#endif

#endif
