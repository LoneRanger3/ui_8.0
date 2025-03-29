/**
 * @ Author: Rui Xiong
 * @ Create Time: 2022-11-14 10:01:51
 * @ Modified by: Rui Xiong
 * @ Modified time: 2023-04-20 14:04:16
 * @ Description:
 */

#ifndef __DATA_MANAGER_H__
#define __DATA_MANAGER_H__

#include <stdint.h>
#include <string>
#include <map>
#include "Base/WebMsgBase.h"
#include "Server/WebSocket.h"
#include "Server/Httpd.h"
#include "Base/JsonInter.h"
using namespace std;

class DataManager
{
    public:
        static DataManager* getInstance(){
            if(m_Instance == nullptr) m_Instance = new DataManager();
            return m_Instance;
        }
        ~DataManager();

        int ReportGcodeFileNum(std::string path);
        int ReportWebControlPrint(int result);
        int ReportOtaInfo(UpgradeInfoList* infoList);
        int ControlVideoFilesResult(int ret);
        int PrintObjectResult(std::string objectInfo);
    private:
        DataManager();
        void sendMessageToWSClient(std::string message);
    private:
        static DataManager *m_Instance;
};

#endif
