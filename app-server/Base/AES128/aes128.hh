/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-08-31 14:17:24
 * @LastEditTime: 2023-09-05 20:00:27
 */
#ifndef __AES_128_H__
#define __AES_128_H__
#include <string>

std::string AppAesEncryptToBase64(std::string str);
std::string AppAesDecryptFromBase64(std::string str);

int AppAesEncryptToFile(std::string path, std::string str);
std::string AppAesDecryptFromFile(std::string str);

#endif