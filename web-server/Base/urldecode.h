/**
 * @ Author: Rui Xiong
 * @ Create Time: 2023-03-09 16:11:22
 * @ Modified by: Rui Xiong
 * @ Modified time: 2023-03-09 16:28:57
 * @ Description:
 */

#ifndef URLENCODE_H
#define URLENCODE_H

/*
 * Function: urlDecode
 * Purpose:  Decodes a web-encoded URL. By default, +'s are converted to spaces.
 * Input:    const char* str - the URL to decode
 * Output:   char* - the decoded URL
 */
#ifdef  __cplusplus  
extern "C" {  
#endif

char *urlDecode(const char *str);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  
#endif
