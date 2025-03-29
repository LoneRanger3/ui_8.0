/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-12-27 09:34:17
 * @LastEditTime: 2023-03-18 11:13:26
 */
/**
 * 十国语言顺序(对照UI从左至右 从上至下)
 * 
 * 汉语 英语 德语 西语
 * 法语 意语 葡语 俄语
 * 土语 日语
 * 
 * *****/
#ifndef __MULT_LANGUAGE_H_
#define __MULT_LANGUAGE_H_

#define MAX_LANGUAGE 11

void set_cur_language_index(unsigned short language_index);
unsigned short get_cur_language_index();

/*********************boot*****************************/
extern const char *Boot0Tips1[MAX_LANGUAGE];
// extern const char *Boot1Tips1[MAX_LANGUAGE];
// extern const char *Boot1Tips2[MAX_LANGUAGE];
extern const char *Boot1Tips3[MAX_LANGUAGE];
// extern const char *Boot2Tips1[MAX_LANGUAGE];
// extern const char *Boot2Tips2[MAX_LANGUAGE];
extern const char *Boot3Tips1[MAX_LANGUAGE];
extern const char *Boot3Tips2[MAX_LANGUAGE];
extern const char *Privacycontent[MAX_LANGUAGE];
extern const char *DeviceMachine[MAX_LANGUAGE];
extern const char *UploadErrorTips[MAX_LANGUAGE];
extern const char *Area[MAX_LANGUAGE];
extern const char *AreaChinese[MAX_LANGUAGE];
extern const char *AreaOthers[MAX_LANGUAGE];
extern const char *UploadErrorTips2[MAX_LANGUAGE];
extern const char *UploadErrorresult[MAX_LANGUAGE];
extern const char *UploadErrorTips3[MAX_LANGUAGE];
extern const char *UploadErrorTips4[MAX_LANGUAGE];
extern const char *DontCXYUserInfo[MAX_LANGUAGE];
extern const char *DontNetwork[MAX_LANGUAGE];
extern const char *UploadErrorTips5[MAX_LANGUAGE];
extern const char *WikiTips[MAX_LANGUAGE];
extern const char *FaqTips[MAX_LANGUAGE];
/*********************boot*****************************/

/**********************common *************************/
extern const char *HotendInputRangle[MAX_LANGUAGE];
extern const char *BedInputRangle[MAX_LANGUAGE];
extern const char *Confirm[MAX_LANGUAGE];  //确认
extern const char *ToChangeFilament[MAX_LANGUAGE];//去换料
extern const char *Stop[MAX_LANGUAGE];    //停止
extern const char *Pause[MAX_LANGUAGE];
extern const char *Resume[MAX_LANGUAGE];
extern const char *Print[MAX_LANGUAGE];    //打印
extern const char *Back[MAX_LANGUAGE];
extern const char *Cancel[MAX_LANGUAGE];   //取消
extern const char *KindTips[MAX_LANGUAGE];  //温馨提示
extern const char *FilamentTips[MAX_LANGUAGE];  //提示
extern const char *Warning[MAX_LANGUAGE];   //警告
extern const char *CopyProcess[MAX_LANGUAGE];
extern const char *CopyErrorResult[MAX_LANGUAGE];
extern const char *PrintCompleted[MAX_LANGUAGE];

extern const char *Local[MAX_LANGUAGE];
extern const char *DiskU[MAX_LANGUAGE];
extern const char *DiskIn[MAX_LANGUAGE];
extern const char *DiskOut[MAX_LANGUAGE];
extern const char *History[MAX_LANGUAGE];
extern const char *LastPageMsg[MAX_LANGUAGE];
extern const char *FirstPageMsg[MAX_LANGUAGE];
extern const char *Screening[MAX_LANGUAGE];
extern const char *SortBySize[MAX_LANGUAGE];
extern const char *SortByTime[MAX_LANGUAGE];
extern const char *SortByName[MAX_LANGUAGE];
extern const char *PrintingTips[MAX_LANGUAGE];
extern const char *PrintingTips_Pauseprint[MAX_LANGUAGE];
extern const char *PrintingTips_Resumeprint[MAX_LANGUAGE];
extern const char *PrintingTips_Stopprint[MAX_LANGUAGE];
extern const char *PrintingTips_Startprint[MAX_LANGUAGE];
extern const char *PrintingTips_CantPause[MAX_LANGUAGE];
extern const char *NoContentsMsg[MAX_LANGUAGE];
extern const char *CopyToUSB[MAX_LANGUAGE];
extern const char *CopyToLocal[MAX_LANGUAGE];
extern const char *Delete[MAX_LANGUAGE];
extern const char *FileNameArray[MAX_LANGUAGE];  //文件名称

extern const char *LanguageSelection[MAX_LANGUAGE];  //语言选择
extern const char *CameraArray[MAX_LANGUAGE];  //摄像头
extern const char *CameraSetting[MAX_LANGUAGE];//摄像头设置
extern const char *VedioList[MAX_LANGUAGE];    //视频列表
extern const char *EnableArray[MAX_LANGUAGE];  //启用
extern const char *ExportArray[MAX_LANGUAGE]; //导出
extern const char *UpLoadArray[MAX_LANGUAGE]; //上传
extern const char *NotForNow[MAX_LANGUAGE];   //暂时不要
extern const char *ExportTips[MAX_LANGUAGE];  //导出提示
extern const char *PrintTime[MAX_LANGUAGE];   //打印时长
extern const char *PrintDatetime[MAX_LANGUAGE]; //打印日期
extern const char *ShootPosArray[MAX_LANGUAGE];   //拍照位置
extern const char *RenderArray[MAX_LANGUAGE];     //渲染方式
extern const char *AboutDevice[MAX_LANGUAGE];     //关于本机
extern const char *AdvancedMode[MAX_LANGUAGE];    //专家模式
extern const char *Zoffset[MAX_LANGUAGE];
extern const char *Flow[MAX_LANGUAGE];
extern const char *BedMeshAdjust[MAX_LANGUAGE];
extern const char *NozzlePidDetect[MAX_LANGUAGE];
extern const char *PIDNozzleCheckPrepareTip[MAX_LANGUAGE];
extern const char *PIDNozzleCheckingTip[MAX_LANGUAGE];
extern const char *PIDNozzleCheckingTimeTip[MAX_LANGUAGE];
extern const char *PIDNozzleCheckedTip[MAX_LANGUAGE];
extern const char *PIDNozzleCheckedTip1[MAX_LANGUAGE];
extern const char *BedPidDetect[MAX_LANGUAGE];
extern const char *PIDBedCheckPrepareTip[MAX_LANGUAGE];
extern const char *PIDBedCheckingTip[MAX_LANGUAGE];
extern const char *PIDBedCheckingTimeTip[MAX_LANGUAGE];
extern const char *PIDBedCheckedTip[MAX_LANGUAGE];
extern const char *PIDBedCheckedTip1[MAX_LANGUAGE];
extern const char *LevelingMethod[MAX_LANGUAGE];
extern const char *Automatic[MAX_LANGUAGE];
extern const char *Manual[MAX_LANGUAGE];
extern const char *AutolevelTips[MAX_LANGUAGE];
extern const char *Start[MAX_LANGUAGE];
extern const char *ResetMachine[MAX_LANGUAGE];    //恢复出厂
extern const char *ResetMachineTips[MAX_LANGUAGE];//恢复出厂提示
extern const char *UpdataTips[MAX_LANGUAGE];      //升级后提示
extern const char *LogArray[MAX_LANGUAGE];        //日志
extern const char *BindDevice[MAX_LANGUAGE];      //设备绑定
extern const char *CurVersionArray[MAX_LANGUAGE]; //当前版本
extern const char *ExportLogArray[MAX_LANGUAGE];  //导出日志
extern const char *StartDetection[MAX_LANGUAGE];  //开始检测
extern const char *StartLevel[MAX_LANGUAGE];      //开始调平
extern const char *AutoLevel[MAX_LANGUAGE];       //自动调平
extern const char *AILIDAR[MAX_LANGUAGE];         //AI雷达
extern const char *PrinterAdjust[MAX_LANGUAGE];   //打印校准
extern const char *Checking[MAX_LANGUAGE];        //检测中

extern const char *PrevStep[MAX_LANGUAGE];        //上一步
extern const char *NextStep[MAX_LANGUAGE];        //下一步
extern const char *JumpOver[MAX_LANGUAGE];        //跳过

extern const char *ModelCoolFan[MAX_LANGUAGE];    //模型冷却风扇
extern const char *ThroatCoolFan[MAX_LANGUAGE];   //喉管散热风扇
extern const char *BoardCoolFan[MAX_LANGUAGE];   //喉管散热风扇

extern const char *AxisMove[MAX_LANGUAGE];        //轴移动
extern const char *ManualLevel[MAX_LANGUAGE];     //手动调平
extern const char *VibrationOptimization[MAX_LANGUAGE];  //振纹优化
extern const char *Error1[MAX_LANGUAGE];            //错误告警1
extern const char *Error2[MAX_LANGUAGE];            //错误告警2
extern const char *Error3[MAX_LANGUAGE];            //错误告警3
extern const char *Error4[MAX_LANGUAGE];            //错误告警4
extern const char *Error5[MAX_LANGUAGE];            //错误告警5
extern const char *Error6[MAX_LANGUAGE];            //错误告警6
extern const char *Error7[MAX_LANGUAGE];            //错误告警7
extern const char *Notyet[MAX_LANGUAGE];
extern const char *Restart[MAX_LANGUAGE];

extern const char *CalibrationTimeMsg[MAX_LANGUAGE];     //
extern const char *CalibrationUnusualMsg[MAX_LANGUAGE];  //
extern const char *OverRangleMsg[MAX_LANGUAGE];          //输入的数据超出范围,请重新输入
extern const char *CalibrationProccess[MAX_LANGUAGE];    //校准进行中,当前进度
extern const char *CalibrationFinished[MAX_LANGUAGE];    //校准已完成，请点击下一步
extern const char *FanNormalMsg[MAX_LANGUAGE];          //1.正常转动将进行下一步;
extern const char *CheckFanNormalMoveMsg[MAX_LANGUAGE]; //请查看风扇是否正常转动...
extern const char *NormalArray[MAX_LANGUAGE];           //正常
extern const char *AbnormalArray[MAX_LANGUAGE];         //不正常
extern const char *SelftestCompletedTips[MAX_LANGUAGE];
/**********************home normal*************************/



/**********************home printing*************************/
extern const char *PowerLossRecoverMsg[MAX_LANGUAGE];
extern const char *FilamentRunOutMsg[MAX_LANGUAGE];
extern const char *PrintActionTipTitle[MAX_LANGUAGE];
extern const char *ResumePrintTip1[MAX_LANGUAGE];
extern const char *ResumePrintTip2[MAX_LANGUAGE];

/**********************axis move*************************/
extern const char *MovePageTitle[MAX_LANGUAGE];
extern const char *MoveAxisTips[MAX_LANGUAGE];
extern const char *MoveAxisTips2[MAX_LANGUAGE];
extern const char *ModelFans[MAX_LANGUAGE];
extern const char *HomeMsg[MAX_LANGUAGE];
extern const char *HomeFailedMsg[MAX_LANGUAGE];
extern const char *ColdExtrudeMsg[MAX_LANGUAGE];
extern const char *NotHomedMsg[MAX_LANGUAGE];
extern const char *Extrude_Retract[MAX_LANGUAGE];
extern const char *Cooling[MAX_LANGUAGE];
extern const char *BackFan[MAX_LANGUAGE];
extern const char *CoolFan[MAX_LANGUAGE];
extern const char *ModelFan[MAX_LANGUAGE];
extern const char * HotendTemp[MAX_LANGUAGE];


/**********************adjustment*************************/
extern const char *Adjustment[MAX_LANGUAGE];
extern const char *NormalMode[MAX_LANGUAGE];
extern const char *SlicenMode[MAX_LANGUAGE];
extern const char *SprintSpeed[MAX_LANGUAGE];
extern const char * HotendTemp[MAX_LANGUAGE];
extern const char * HotendHeating[MAX_LANGUAGE];
extern const char * FilamentIn[MAX_LANGUAGE];
extern const char * FilamentEnd[MAX_LANGUAGE];
extern const char * FilamentIning[MAX_LANGUAGE];
extern const char * FilamentOutPrep[MAX_LANGUAGE];
extern const char * FilamentOuting[MAX_LANGUAGE];
extern const char * FilamentOutEnd[MAX_LANGUAGE];
extern const char * HotTips[MAX_LANGUAGE];
extern const char *FilamentOut[MAX_LANGUAGE];
extern const char *FilamentTempTips1[MAX_LANGUAGE];
extern const char *FilamentTempTips2[MAX_LANGUAGE];
/**********************file manager*************************/

/**********************sub dir*************************/
extern const char *FileCountTipsMsg[MAX_LANGUAGE];

/**********************print history*************************/
extern const char *NoRecords[MAX_LANGUAGE];
extern const char *RecordIndexTipsMsg[MAX_LANGUAGE];
extern const char *TotleTimeArray[MAX_LANGUAGE];
extern const char *StartTimeArray[MAX_LANGUAGE];
extern const char *StatusArray[MAX_LANGUAGE];
extern const char *Action[MAX_LANGUAGE];

/**********************preview*************************/
extern const char *OpenFileFailedMsg[MAX_LANGUAGE];
extern const char *OpeningFileMsg[MAX_LANGUAGE];
extern const char *FileIndexInvalid[MAX_LANGUAGE];

/**********************faq*************************/
extern const char *FaqArray[MAX_LANGUAGE];
extern const char *Errorhistory[MAX_LANGUAGE];
extern const char *FAQ[MAX_LANGUAGE];
extern const char *OnlineManual[MAX_LANGUAGE];
extern const char *UploadLog[MAX_LANGUAGE];
extern const char *UploadTips[MAX_LANGUAGE];

/***********************camera list****************************/
extern const char *NoVedioes[MAX_LANGUAGE];               //没有影像文件

/***********************camera setting****************************/
extern const char *EveryArray[MAX_LANGUAGE];              //每
extern const char *LayerStartPos[MAX_LANGUAGE];           //层开始位置
extern const char *HotendMoveAway[MAX_LANGUAGE];          //喷头移开时

/***********************vedio info****************************/
extern const char *VedioInformation[MAX_LANGUAGE];        //视频详情
extern const char *AIFunction[MAX_LANGUAGE];
extern const char *AIdetection[MAX_LANGUAGE];             //AI检测
extern const char *AIShareTips[MAX_LANGUAGE];             //分享照片生效中
extern const char *AIShareCheckboxContent[MAX_LANGUAGE];  //分享照片帮助提高打印错误检测率
extern const char *AISensitivity[MAX_LANGUAGE];           //AI灵敏度
extern const char *AINormalMode[MAX_LANGUAGE];            //常规模式
extern const char *AINormalModeTips[MAX_LANGUAGE];        //常规模式解释语
extern const char *AIProMode[MAX_LANGUAGE];               //专业模式
extern const char *AIProModeTips[MAX_LANGUAGE];           //专业模式解释语
extern const char *FirstLayerDetection[MAX_LANGUAGE];     //首层检测
extern const char *FlowCalibration[MAX_LANGUAGE];         //流量校准
extern const char *FlowCalibrationTips[MAX_LANGUAGE];         //流量校准提示
extern const char *AIDetectionTips[MAX_LANGUAGE];
extern const char *AIPausePrint[MAX_LANGUAGE];           //故障暂停打印
extern const char *ExcludeObjects[MAX_LANGUAGE];         //排除对象
extern const char *Layers[MAX_LANGUAGE];                 //层数
extern const char *Nocamera[MAX_LANGUAGE];               //无摄像头，请连接摄像头
extern const char *NoLaser[MAX_LANGUAGE];                //无激光雷达

/***********************about device****************************/
extern const char *DeviceNameArray[MAX_LANGUAGE];         //设备名称
extern const char *DeviceModelArray[MAX_LANGUAGE];        //设备型号
extern const char *SerialNumber[MAX_LANGUAGE];            //SN
extern const char *FirmwareVersion[MAX_LANGUAGE];         //固件版本
extern const char *MacAddrArray[MAX_LANGUAGE];            //Mac地址
extern const char *CumulativeTime[MAX_LANGUAGE];          //累计打印
extern const char *StorageArray[MAX_LANGUAGE];            //存储空间


/*************************reset machine*************************/
extern const char *ResetArray[MAX_LANGUAGE];              //恢复
extern const char *RecordsArray[MAX_LANGUAGE];            //记录
extern const char *FileArray[MAX_LANGUAGE];               //文件
extern const char *CleanItemArray[MAX_LANGUAGE];          //清除选项
extern const char *DelayPhotographVedioes[MAX_LANGUAGE];  //延迟摄影视频

/*************************device binding***********************/
extern const char *DeviceBindTipsMsg[MAX_LANGUAGE];

/*************************touch tone***********************/
// extern const char *VolumeArray[MAX_LANGUAGE];             //音量
// extern const char *SoundEffect[MAX_LANGUAGE];             //音效
// extern const char *Technology[MAX_LANGUAGE];              //科技
// extern const char *Agile[MAX_LANGUAGE];                   //灵动
// extern const char *Brief[MAX_LANGUAGE];                   //简短
// extern const char *Crisp[MAX_LANGUAGE];                   //清脆

/*************************settings***********************/
extern const char *SystemArray[MAX_LANGUAGE];             //系统
extern const char *NetworkArray[MAX_LANGUAGE];            //网络
extern const char *ScreenBrightnessArray[MAX_LANGUAGE];   //屏幕亮度
extern const char *ScreenOffArray[MAX_LANGUAGE];          //息屏
extern const char *MinuteArray[MAX_LANGUAGE];             //分钟
// extern const char *FullScreenArray[MAX_LANGUAGE];         //全屏模式
extern const char *TimeZoneArray[MAX_LANGUAGE];           //时区设置
extern const char *TopicArray[MAX_LANGUAGE];              //主题
extern const char *VersionArray[MAX_LANGUAGE];            //版本
extern const char *DeviceSelfTestArray[MAX_LANGUAGE];     //设备自检
extern const char *Account[MAX_LANGUAGE];                 //账号
extern const char *PassWord[MAX_LANGUAGE];                //密码
extern const char *RootInfoTips[MAX_LANGUAGE];            //root信息提示
extern const char *UpdateReminder[MAX_LANGUAGE];          //更新提醒
extern const char *RootPolicyContent[MAX_LANGUAGE];       //root政策内容
extern const char *UnConnectedArray[MAX_LANGUAGE];        //未连接
extern const char *ConnectedArray[MAX_LANGUAGE];          //已连接
extern const char *PasswordTooShort[MAX_LANGUAGE];        //密码过短
extern const char *PasswordTooLong[MAX_LANGUAGE];         //密码过长
extern const char *PasswordError[MAX_LANGUAGE];           //密码错误
extern const char *Wifiname[MAX_LANGUAGE];                //wifi名称
extern const char *InputPasswordMsg[MAX_LANGUAGE];        //请输入密码消息
extern const char *NetworkConnect[MAX_LANGUAGE];          //网络连接
extern const char *ConnectOptArray[MAX_LANGUAGE];         //连接操作
extern const char *DisconnectOptArray[MAX_LANGUAGE];      //断开操作
extern const char *OtherNetwork[MAX_LANGUAGE];            //其他...
extern const char *ForgetPasswordArray[MAX_LANGUAGE];     //忘记密码
extern const char *NotSetArray[MAX_LANGUAGE];             //不设置
extern const char *LocalNetworkArray[MAX_LANGUAGE];       //本地网络
extern const char *UserName[MAX_LANGUAGE];
extern const char *LogOut[MAX_LANGUAGE];
extern const char *BindingTips[MAX_LANGUAGE];
extern const char *IOTTips[MAX_LANGUAGE];
/*************************update version***********************/
extern const char *NewVersionArray[MAX_LANGUAGE];         //新版本
extern const char *LastVersionArray[MAX_LANGUAGE];        //最新版本
extern const char *UpgradeArray[MAX_LANGUAGE];            //升级
extern const char *Download[MAX_LANGUAGE];                //下载
extern const char *Downloading[MAX_LANGUAGE];             //下载中
extern const char *DownloadSuccess[MAX_LANGUAGE];         //下载完成
extern const char *DownloadFailed[MAX_LANGUAGE];          //下载失败
extern const char *Unpacking[MAX_LANGUAGE];               //解压中
extern const char *UnpackSuccess[MAX_LANGUAGE];           //解压成功
extern const char *UnpackFailed[MAX_LANGUAGE];            //解压失败
extern const char *Installing[MAX_LANGUAGE];              //安装中
extern const char *InstallSuccess[MAX_LANGUAGE];           //安装成功
extern const char *InstallFailed[MAX_LANGUAGE];            //安装失败
extern const char *CurVersionIsLastest[MAX_LANGUAGE];     //当前已是最新版本! 
extern const char *DiscoverNewVersionArray[MAX_LANGUAGE]; //发现新版本   

/*************************export log***********************/
extern const char *LogExportingMsg[MAX_LANGUAGE];      //日志导出中...
extern const char *LogExporCompressing[MAX_LANGUAGE];  //压缩中
extern const char *LogExportSuccessMsg[MAX_LANGUAGE];  //日志导出成功
extern const char *LogExportFailedMsg[MAX_LANGUAGE];   //日志导出失败
extern const char *DiskUMsg[MAX_LANGUAGE];             //U盘不存在

extern const char *LogUploadingMsg[MAX_LANGUAGE];      //日志上传中...
extern const char *LogUploadSuccessMsg[MAX_LANGUAGE];  //日志上传成功
extern const char *LogUploadFailedMsg[MAX_LANGUAGE];   //日志上传失败

extern const char *VideoExportingMsg[MAX_LANGUAGE];     //视频导出中
extern const char *VideoExportSuccessMsg[MAX_LANGUAGE]; //视频导出成功
extern const char *VideoExportFailedMsg[MAX_LANGUAGE];  //视频导出失败

extern const char *VideoUploadingMsg[MAX_LANGUAGE];      //视频上传中...
extern const char *VideoUploadSuccessMsg[MAX_LANGUAGE];  //视频上传成功
extern const char *VideoUploadFailedMsg[MAX_LANGUAGE];   //视频上传失败
/*************************manual test***********************/
extern const char *VibrationCompensation[MAX_LANGUAGE];  //振动补偿
extern const char *SelfTestTipsMsg[MAX_LANGUAGE];        //
extern const char *SelectAll[MAX_LANGUAGE];              //全选
extern const char *NotSelectAll[MAX_LANGUAGE];           //全不选
extern const char *DetectionItemArray[MAX_LANGUAGE];     //检测选项

/*************************network info***********************/
extern const char *IPAddrArray[MAX_LANGUAGE];            //IP地址
extern const char *DNSServerArray[MAX_LANGUAGE];         //DNS服务器
extern const char *SubNetMaskArray[MAX_LANGUAGE];        //子网掩码
extern const char *GatewayArray[MAX_LANGUAGE];           //网关
extern const char *NetworkInfoArray[MAX_LANGUAGE];       //网络详情


/*************************self test tips***********************/
extern const char *PrinterSelfTest[MAX_LANGUAGE];        //打印机自检
extern const char *WelcomeSelfTest[MAX_LANGUAGE];        //欢迎来到自检流程
extern const char *HeaterPurifyingTip[MAX_LANGUAGE];     //加热器清洁提示
extern const char *SelfTestTimeTip[MAX_LANGUAGE];        //自检过程时长提示

/*************************self test network***********************/
extern const char *PleaseSetNetwork[MAX_LANGUAGE];      //请设置您的网络

/*************************self test Privacy Policy***********************/
extern const char *PrivacyPolicy[MAX_LANGUAGE];         //隐私政策
extern const char *ForewordArray[MAX_LANGUAGE];         //前言
extern const char *AgreePrivacyPolicy[MAX_LANGUAGE];    //我已阅读并同意该隐私政策
extern const char *AgreeRootPolicy[MAX_LANGUAGE];       //我已阅读且理解root登录风险
extern const char *PrivacyPolicyTips[MAX_LANGUAGE];     //我已阅读并同意该隐私政策
extern const char *Agree[MAX_LANGUAGE];                 //同意
extern const char *NotAgree[MAX_LANGUAGE];              //再想想
/*************************self test  result***********************/
extern const char *FinishedArray[MAX_LANGUAGE];          //完成

/*************************auto level***********************/
extern const char *LevelProccessTimeMsg[MAX_LANGUAGE];   //调平耗时信息
extern const char *LevelingTipsMsg[MAX_LANGUAGE];        //正在进行自动调平，请勿触碰机器
extern const char *LevelFinishedMsg[MAX_LANGUAGE];       //调平完成信息
extern const char *SaveArray[MAX_LANGUAGE];              //保存
extern const char *SaveLevelDataMsg[MAX_LANGUAGE];       //是否保存调平数据
extern const char *LevelAgainArray[MAX_LANGUAGE];         //重新调平
extern const char *NotSave[MAX_LANGUAGE];                //不保存

/*********************auto home***************************/
extern const char *HomePosArray[MAX_LANGUAGE];           //原点位置
extern const char *CheckAxisHomeStatusMsg[MAX_LANGUAGE]; //5S后请观察设备xyz轴是否回归到原点
extern const char *AxisHomedNormalTipMsg[MAX_LANGUAGE];  //归零正常提示信息
extern const char *AxisHomedUnusualTipMsg[MAX_LANGUAGE]; //归零异常提示信息
extern const char *XYZHomedUnusualTipMsg[MAX_LANGUAGE];  //归零异常提示信息
extern const char *HomeSuccessGuideMsg[MAX_LANGUAGE];    //归零成功信息
extern const char *HomeFailedGuideMsg[MAX_LANGUAGE];     //归零失败信息
extern const char *HomingProccessMsg[MAX_LANGUAGE];      //归零中信息

/*********************auto bed pid calibration***************************/
extern const char *PidCalibrationMsg[MAX_LANGUAGE];      //请进行热床PID检测及校准
extern const char *SaveCalibrationData[MAX_LANGUAGE];    //是否保存热床PID数据

/*********************auto hotend pid calibration***************************/
extern const char *SaveHotendPIDData[MAX_LANGUAGE];     //是否保存喷头PID数据
extern const char *ResetUserData[MAX_LANGUAGE];         //是否要恢复出厂设置
extern const char *LogOutTips[MAX_LANGUAGE];

/*********************manual level***************************/
extern const char *AxisHomingMsg[MAX_LANGUAGE];         //XYZ轴正在复位中...
extern const char *OptTipMsg[MAX_LANGUAGE];             //请在如图所示位置进行操作
extern const char *HotendPositionMsg[MAX_LANGUAGE];     //2.请点击图中数字进行喷头定位;
extern const char *WaitMoveMsg[MAX_LANGUAGE];           //3.等待喷头移动到相应位置;
extern const char *AdjustmentLevel[MAX_LANGUAGE];       //4.调整调平按钮。
extern const char *ManualLevelFinishMsg[MAX_LANGUAGE];  //已完成手动调平请点击下一步

/*********************model fan***************************/
extern const char *PositionArray[MAX_LANGUAGE];         //位置
extern const char *ModelFanCheckMsg[MAX_LANGUAGE];      //5S后请查看模型冷却风扇是否正常转动
extern const char *FanNotDetectMsg[MAX_LANGUAGE];       //3.如不需要检测可以选择跳过.
extern const char *ModelFanMoveMsg[MAX_LANGUAGE];       //模型冷却风扇已启动
extern const char *NozzleHeating[MAX_LANGUAGE];         //喷头加热
extern const char *BedHeating[MAX_LANGUAGE];            //热床加热

/*********************hot fan***************************/
extern const char *HotFanCheckMsg[MAX_LANGUAGE];        //5S后请查看喉管散热风扇是否正常转动
extern const char *HotFanMoveMsg[MAX_LANGUAGE];         //喉管散热风扇已启动
extern const char *HeatingCheckHotFanMsg[MAX_LANGUAGE]; //喷头加热中,请观察风扇稍后是否转动

/*********************ringing***************************/
extern const char *RingingTipMsg[MAX_LANGUAGE];         //检测中请勿触碰打印机
extern const char *SensorStatusMsg[MAX_LANGUAGE];       //传感器状态正常
extern const char *RingingUsefulTipMsg[MAX_LANGUAGE];   //振纹优化可以更好使打印机发挥性能
extern const char *RingingTimeMsg[MAX_LANGUAGE];        //整个过程预计需要5分钟
extern const char *RingingDetectingMsg[MAX_LANGUAGE];   //检测中,请耐心等待
extern const char *RingDetectSuccessMsg[MAX_LANGUAGE];  //检测成功
extern const char *RingDetectFailedMsg[MAX_LANGUAGE];   //检测失败,请检查设备
extern const char *SaveRingDetectData[MAX_LANGUAGE];    //是否保存振纹数据

/*********************select level points***************************/
extern const char *SelectLevelPoints[MAX_LANGUAGE];     //请选择您需要的调平点数

/*********************Runout sensor***************************/
extern const char *LongTimeRunoutMsg[MAX_LANGUAGE];     //长时间未检测到耗材，请检查传感器
extern const char *DetectFilamentTipMsg[MAX_LANGUAGE];  //已检测到耗材，请拔出耗材
extern const char *NotDetectFilaTipMsg[MAX_LANGUAGE];   //未检测到耗材，请插入耗材
extern const char *CanStartDetectTipMsg[MAX_LANGUAGE];  //点击开始检测按钮，进行断料检测
extern const char *InsertFilaDetectMsg[MAX_LANGUAGE];   //耗材已插入,检测功能正常.
extern const char *PullOutFilaDetectMsg[MAX_LANGUAGE];  //耗材已拔出,检测功能正常.
extern const char *FinishOptBaseDiagram[MAX_LANGUAGE];  //1.请按示意图完成相关操作


/*********************set time***************************/

extern const char *FOREIGN_BODY[MAX_LANGUAGE];
extern const char *ROUGH_G28[MAX_LANGUAGE];
extern const char *NOZZLE_CLEAR[MAX_LANGUAGE];
extern const char *ACCURATE_G28[MAX_LANGUAGE];
extern const char *LEVEL_DELECT[MAX_LANGUAGE];
extern const char *LASER_CALIBRATION[MAX_LANGUAGE];
extern const char *SCAN_TABLE[MAX_LANGUAGE];
extern const char *PRINT_LINE[MAX_LANGUAGE];
extern const char *COOL_DOWN[MAX_LANGUAGE];
extern const char *SCAN_MODEL[MAX_LANGUAGE];
extern const char *FLOOR_SCAN_TABLE[MAX_LANGUAGE];
extern const char *FLOOR_PRINT_LINE[MAX_LANGUAGE];
extern const char *FLOOR_COOL_DOWN[MAX_LANGUAGE];
extern const char *FLOOR_SCAN_MODEL[MAX_LANGUAGE];
extern const char *FLOOR_AI_CALCULATE[MAX_LANGUAGE];
extern const char *FLOOR_HEAT_UP[MAX_LANGUAGE];

extern const char *ErrorCode[MAX_LANGUAGE];
extern const char *ErrorTime[MAX_LANGUAGE];
extern const char *ErrorBtnInfo[MAX_LANGUAGE];          //错误详情按钮
extern const char *ErrorBtnConfirm[MAX_LANGUAGE];       //错误确定按钮
extern const char *ErrorBtnFileManagement[MAX_LANGUAGE];//错误确定按钮
extern const char *ErrorBtnFileIgnore[MAX_LANGUAGE];    //错误忽略按钮
extern const char *ErrorBtnStopPrint[MAX_LANGUAGE];     //停止打印
extern const char *ErrorBtnContinuePrint[MAX_LANGUAGE]; //继续打印
extern const char *MaterialSeneorTips[MAX_LANGUAGE];
extern const char *ErrorTitile1[MAX_LANGUAGE];        //错误码1标题
extern const char *ErrorTitile2[MAX_LANGUAGE];        //错误码1标题
extern const char *ErrorTitile3[MAX_LANGUAGE];          //AI检测标题
extern const char *ErrorTitile4[MAX_LANGUAGE];          //提示
extern const char *Error001Content[MAX_LANGUAGE];       //错误码1详情
extern const char *Error002Content[MAX_LANGUAGE];       //错误码2详情
extern const char *Error003Content[MAX_LANGUAGE];       //错误码3详情
extern const char *Error004Content[MAX_LANGUAGE];       //错误码4详情
extern const char *Error005Content[MAX_LANGUAGE];       //错误码5详情
extern const char *Error006Content[MAX_LANGUAGE];       //错误码6详情
extern const char *Error007Content[MAX_LANGUAGE];       //错误码7详情
extern const char *Error008Content[MAX_LANGUAGE];       //错误码8详情
extern const char *Error008_103Content[MAX_LANGUAGE];   //错误码AI打印暂停
extern const char *Error008_104Content[MAX_LANGUAGE];   //错误码AI异物检测暂停
extern const char *Error200Content[MAX_LANGUAGE];       //错误码200详情
extern const char *Error201Content[MAX_LANGUAGE];       //错误码201详情
extern const char *Error204Content[MAX_LANGUAGE];       //错误码204详情
extern const char *Error205Content[MAX_LANGUAGE];       //错误码205详情
extern const char *Error206Content[MAX_LANGUAGE];       //错误码206详情
extern const char *Error207Content[MAX_LANGUAGE];       //错误码207详情
extern const char *Error208Content[MAX_LANGUAGE];       //错误码208详情
extern const char *Error210Content[MAX_LANGUAGE];       //错误码208详情
extern const char *Error500Content[MAX_LANGUAGE];       //错误码500详情
extern const char *Error800Content[MAX_LANGUAGE];       //错误码800详情
extern const char *Error800_2242_Content[MAX_LANGUAGE]; //错误码800_2242详情
extern const char *Error800_2211_Content[MAX_LANGUAGE]; //错误码800_2211详情
extern const char *Error801Content[MAX_LANGUAGE];       //错误码801详情
extern const char *Error009Content[MAX_LANGUAGE];       //错误码9详情

extern const char *Key000Content[MAX_LANGUAGE];         //key0或key1错误码内容
extern const char *Key101Content[MAX_LANGUAGE];         //key101
extern const char *Key103Content[MAX_LANGUAGE];         //key103
extern const char *Key104Content[MAX_LANGUAGE];         //key104
extern const char *Key109Content[MAX_LANGUAGE];         //key109

extern const char *Key500Content[MAX_LANGUAGE];         //key104
extern const char *Key501Content[MAX_LANGUAGE];         //key501
extern const char *Key502Content[MAX_LANGUAGE];         //key502
extern const char *Key503Content[MAX_LANGUAGE];         //key503
extern const char *Key504Content[MAX_LANGUAGE];         //key504
extern const char *Key505Content[MAX_LANGUAGE];         //key505
extern const char *Key506Content[MAX_LANGUAGE];         //key506
extern const char *Key507Content[MAX_LANGUAGE];         //key507
extern const char *Key508Content[MAX_LANGUAGE];         //key508

extern const char *Key2520Content[MAX_LANGUAGE];        //key2520
extern const char *Key2521Content[MAX_LANGUAGE];        //key2521
extern const char *Key2522Content[MAX_LANGUAGE];        //key2522
extern const char *Key2523Content[MAX_LANGUAGE];        //key2523
extern const char *Key2524Content[MAX_LANGUAGE];        //key2524
extern const char *Key2525Content[MAX_LANGUAGE];        //key2525
extern const char *Key2526Content[MAX_LANGUAGE];        //key2526
extern const char *Key2527Content[MAX_LANGUAGE];        //key2527
extern const char *Key2528Content[MAX_LANGUAGE];        //key2528
extern const char *Key2529Content[MAX_LANGUAGE];        //key2529
extern const char *Key2530Content[MAX_LANGUAGE];        //key2530
extern const char *Key2531Content[MAX_LANGUAGE];        //key2531
extern const char *Key2532Content[MAX_LANGUAGE];        //key2532
extern const char *Key2533Content[MAX_LANGUAGE];        //key2533
extern const char *Key2534Content[MAX_LANGUAGE];        //key2534
extern const char *Key2535Content[MAX_LANGUAGE];        //key2535
extern const char *Key2560Content[MAX_LANGUAGE];        //key2560
extern const char *Key2561Content[MAX_LANGUAGE];        //key2561
extern const char *Key2562Content[MAX_LANGUAGE];        //key2562
extern const char *Key2563Content[MAX_LANGUAGE];        //key2563
extern const char *Key2564Content[MAX_LANGUAGE];        //key2564
extern const char *Key2565Content[MAX_LANGUAGE];        //key2565

extern const char *Speed[MAX_LANGUAGE];                 //速度
#endif /* EVENT_CB_H_ */
