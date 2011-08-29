#ifndef VMINIFILE_H
#define VMINIFILE_H

#ifdef __cplusplus
extern "C"
{

#endif

/*支持的ini文件大小*/	
#define MAX_FILE_SIZE 1024
	
/*section左开始符号*/
#define INI_SECTION_LEFT_BRACE '['
/*section右结束符号*/
#define INI_SECTION_RIGHT_BRACE ']'

/**
 * 从ini文件读一个字符串值
 * 不存在时取默认值
 * 
 * @param section	读取section
 * @param key	读取key
 * @param value	读取值
 * @param size	读取长度
 * @param default_value	默认值
 * @param file 文件名
 * 
 * @return 1成功，0失败
 */
int vm_read_profile_string( char *section, char *key,char *value, int size,char *default_value, char *file);

/**
 * 从ini文件读取一个整数值
 * 不存在时取默认值
 * 
 * @param section	读取section
 * @param key	读取key
 * @param default_value	默认值
 * @param file	文件名
 * 
 * @return 读取值
 */
int vm_read_profile_int( char *section, char *key,int default_value, char *file);

/**
 * 往ini文件写入一个字符串值
 * 文件不存在时创建一个新文件，section不存在时添加一个section，key不存在时添加一个key，key存在时更新value
 * 目前版本限制文件大小为1k
 * 
 * @param section	写入section
 * @param key	写入key
 * @param value	写入值
 * @param file	文件名
 * 
 * @return	1成功，0失败 
 */
int vm_write_profile_string( char *section, char *key,char *value, char *file);

#ifdef __cplusplus
}; //end of extern "C" {
#endif

#endif //end of INI_FILE_H_

