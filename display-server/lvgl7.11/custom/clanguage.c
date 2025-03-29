/*
 * language.c
 *
 *  Created on: December 10, 2021
 *      Author: liuxinchao
 */

 #include "clanguage.h"

 char *home[MAX_LANGUAGE] = { \
    "主页", \
    "Home", \
    "Startseite", \
    "Inicio", \
    "Accueil", \
    "Home", \
    "Início", \
    "Домашняя", \
    "Anasayfa"
};

char *print[MAX_LANGUAGE] = { \
    "打印", \
    "Print", \
    "Drucken", \
    "Imprimir", \
    "Imprimer", \
    "Stampa", \
    "Imprimir", \
    "Печать", \
    "Yazdır"
};

char *prepare[MAX_LANGUAGE] = { \
    "准备", \
    "Ready", \
    "Listo", \
    "Prêt", \
    "Pronto", \
    "Preparar", \
    "Imprimir", \
    "Готово", \
    "Hazır"
};

char *setting[MAX_LANGUAGE] = { \
    "设置", \
    "Settings", \
    "Ein.", \
    "Ajustes", \
    "Paramètres", \
    "Impostazioni", \
    "Config.", \
    "Настройки", \
    "Ayarlar"
};

char *language[MAX_LANGUAGE] = { \
    "语言选择", \
    "Language", \
    "Sprache", \
    "Idioma", \
    "Langue", \
    "Selezione della lingua", \
    "Idioma", \
    "Язык", \
    "Dil"
};

char *move_axis[MAX_LANGUAGE] = { \
    "移动轴", \
    "Axis move", \
    "Achse bewegen", \
    "Mov. eje", \
    "Déplacer l'axe", \
    "Spostamento dell'asse", \
    "Mover", \
    "Перемещ. oси", \
    "Eks. hareketi"
};

char *in_out_material[MAX_LANGUAGE] = { \
    "进/退料", \
    "In/out", \
    "Ein/Aus", \
    "Den./Fuera", \
    "Entrée /Sortie", \
    "In/out", \
    "Alimentar/Retrair", \
    "Вход/выход", \
    "Giriş/çıkış"
};

char *manual_temp[MAX_LANGUAGE] = { \
    "手动设温", \
    "Manual", \
    "Manuell", \
    "Manual", \
    "Manuel", \
    "Manuale", \
    "Manual", \
    "Рук-во по эксплуат.", \
    "Manuel"
};

char *device[MAX_LANGUAGE] = { \
    "设备", \
    "Device", \
    "Gerät", \
    "Disposit.", \
    "Appareil", \
    "Dispositivo", \
    "Dispositivo", \
    "Устройство", \
    "Cihaz"
};

char *adv_setting[MAX_LANGUAGE] = { \
    "高级设置", \
    "ADV. SET.", \
    "ERW. EIN.", \
    "AJUS.AVAN.", \
    "PARAM. AVANCES", \
    "Impostazioni avanzate", \
    "Cinfig. avançada", \
    "РАСШ.НАСТР.", \
    "ADV. AYAR."
};


char *about[MAX_LANGUAGE] = { \
    "关于本机", \
    "About", \
    "Über", \
    "Acerca", \
    "Concernant", \
    "Al riguardo", \
    "Sobre", \
    "О", \
    "Hakkında"
};

char *meterial_in[MAX_LANGUAGE] = { \
    "进料", \
    "In", \
    "Ein", \
    "Alimenta", \
    "Entrée", \
    "IN", \
    "Alimentar", \
    "В", \
    "Giriş"
};

char *meterial_out[MAX_LANGUAGE] = { \
    "退料", \
    "Out", \
    "Aus", \
    "Retorna", \
    "Sortie", \
    "OUT", \
    "Retrair", \
    "Вне", \
    "Çıkış"
};

char *hotend_temp[MAX_LANGUAGE] = { \
    "喷嘴温度", \
    "Nozzle temp.", \
    "Düsentemp.", \
    "Temp boquilla", \
    "Temp. de buse", \
    "Temp. ugello", \
    "Temp. Bico", \
    "Темп. Сопла", \
    "Nozül sıcakl."
};

char *bed_temp[MAX_LANGUAGE] = { \
    "热床温度", \
    "H&B temp", \
    "H&B-Temp.", \
    "Temp H&B", \
    "Temp. L&C", \
    "H&B temp", \
    "Temp. Mesa", \
    "H&B темп", \
    "H&B sıcakl."
};

char *preheat_pla[MAX_LANGUAGE] = { \
    "预热PLA", \
    "Preheat PLA", \
    "Vorheizen PLA", \
    "Precal. PLA", \
    "Préchauffage PLA", \
    "Preriscaldamento PLA", \
    "Pré-aquecer PLA", \
    "Разогреть PLA", \
    "PLA'yı Isıt"
};

char *preheat_abs[MAX_LANGUAGE] = { \
    "预热ABS", \
    "Preheat ABS", \
    "Vorheizen ABS", \
    "Precal. ABS", \
    "Préchauffage ABS", \
    "Preriscaldamento ABS", \
    "Pré-aquecer ABS", \
    "Разогреть АБС", \
    "ABS'yi Isıt"
};

char *cooling[MAX_LANGUAGE] = { \
    "一键冷却", \
    "Cooling", \
    "Kühlen", \
    "Enfriam.", \
    "Réfrigération", \
    "Raffreddamento one-touch", \
    "Refrigerar", \
    "Охлаждение", \
    "Soğutma"
};

char *fan_control[MAX_LANGUAGE] = { \
    "风扇控制", \
    "Fan control", \
    "Lüftersteu.", \
    "Contr. vent", \
    "Contrôle  ventilateur", \
    "Controllo della ventola", \
    "Controle de Ventoinha", \
    "Управление вент.", \
    "Fan kontrolü"
};

char *pla_setting[MAX_LANGUAGE] = { \
    "PLA预热设置", \
    "PLA settings", \
    "PLA-Ein.", \
    "Ajustes PLA", \
    "Param. PLA", \
    "Preriscaldamento delle impostazioni PLA", \
    "Config. PLA", \
    "Настройки PLA", \
    "PLA ayarları"
};


char *abs_setting[MAX_LANGUAGE] = { \
    "ABS预热设置", \
    "ABS settings", \
    "ABS-Ein.", \
    "Ajustes ABS", \
    "Param. ABS", \
    "Impostazioni di preriscaldamento ABS", \
    "Config. ABS", \
    "Настройки АБС", \
    "ABS ayarları"
};

char *level[MAX_LANGUAGE] = { \
    "调平", \
    "Level", \
    "Pegel", \
    "Nivel", \
    "Niveau", \
    "Livello", \
    "Nivelamento", \
    "Уровень", \
    "Seviye"
};

char *poweroff[MAX_LANGUAGE] = { \
    "一键关机", \
    "OFF", \
    "AUS", \
    "APAGADO", \
    "ARRET", \
    "Spegnimento con un click", \
    "Desligar", \
    "ВЫКЛ", \
    "KAPALI"
};

char *light_control[MAX_LANGUAGE] = { \
    "照明控制", \
    "LC", \
    "LS", \
    "CL", \
    "LC", \
    "LC", \
    "LCD", \
    "LC", \
    "LC"
};

char *aux_level[MAX_LANGUAGE] = { \
    "辅助调平", \
    "AUX. LVL.", \
    "HIL. NIV.", \
    "NIV. AUX.", \
    "AUX. LVL.", \
    "Livellamento ausiliario", \
    "Nivelamento Aux.", \
    "AUX. LVL.", \
    "AUX. SVY."
};

char *auto_level[MAX_LANGUAGE] = { \
    "自动调平", \
    "AUTO. LVL.", \
    "AUTO. NIV.", \
    "NIV. AUTO", \
    "NIVELAGE AUTO.", \
    "Livellamento automatico", \
    "Auto Nivelamento", \
    "АВТО. LVL.", \
    "OTO. SVY."
};

char *start[MAX_LANGUAGE] = { \
    "启动", \
    "Start", \
    "Start", \
    "Inicio", \
    "Lancer", \
    "Inizia", \
    "Iniciar", \
    "Начать", \
    "Başlat"
};

char *leveling[MAX_LANGUAGE] = { \
    "正在自动调平", \
    "Auto-leveling in process", \
    "Auto-Nvellierung in Bearbeitung", \
    "Nivelación automática", \
    "En cours de nivellement automatique", \
    "Autolivellamento in corso", \
    "Auto-Nvellierung in Bearbeitung", \
    "Автоматическая калибровка платформы", \
    "Otomatik tabla ayarı yapılıyor"
};

char *waiting[MAX_LANGUAGE] = { \
    "请耐心等待...", \
    "please be patient...", \
    "bitte haben Sie etwas Geduld...", \
    "paciencia...", \
    "patientez...", \
    "attendere prego...", \
    "bitte haben Sie etwas Geduld...", \
    "подождите пожалуйста...", \
    "lütfen bekleyin..."
};

char *machine_type[MAX_LANGUAGE] = { \
    "机器型号", \
    "Model", \
    "Modell", \
    "Modelo", \
    "Modèle :", \
    "Modello", \
    "Modelo", \
    "Модель", \
    "Model"
};

char *fireware_ver[MAX_LANGUAGE] = { \
    "固件版本", \
    "F/W VER", \
    "F/W VER", \
    "F/W VER", \
    "VER  F/W", \
    "VER. F/W", \
    "Versão de firmware", \
    "F/W ВЕР", \
    "F/W VER."
};

char *screen_ver[MAX_LANGUAGE] = { \
    "屏幕版本", \
    "Screen Ver.", \
    "Anzeigen-Ver.", \
    "Ver. pantalla", \
    "Ver. écran", \
    "Ver. schermo", \
    "Versão de Tela", \
    "Верс.экрана", \
    "Ekran Sür."
};

char *hardware_ver[MAX_LANGUAGE] = { \
    "硬件版本", \
    "H/W VER", \
    "H/W VER", \
    "H/W VER", \
    "VER. H/W", \
    "H/W VER", \
    "Versão de hardware", \
    "H/W ВЕР", \
    "H/W VER"
};

char *print_size[MAX_LANGUAGE] = { \
    "打印尺寸", \
    "Print size", \
    "Druckgröße", \
    "Tamaño impr.", \
    "Taille d'impression", \
    "Dimensione della stampa", \
    "Tamanho de impresão", \
    "Размер печати", \
    "Baskı boyutu"
};

char *company_web[MAX_LANGUAGE] = { \
    "官方网站", \
    "Website", \
    "Website", \
    "Website", \
    "Site web", \
    "Sito web", \
    "Site oficial", \
    "Вебсайт", \
    "Websitesi"
};

char *restore_network[MAX_LANGUAGE] = { \
    "恢复网络", \
    "Restore network", \
    "Netz wieder.", \
    "Restaurar red", \
    "Restaurer le réseau", \
    "Ripristina rete", \
    "Redefinir rede", \
    "Восстановить сеть", \
    "Ağı geri yükle"
};

char *restore_factory[MAX_LANGUAGE] = { \
    "恢复出厂", \
    "Restore All Set.", \
    "Alle Ein. Wieder.", \
    "Rest. Ajustes", \
    "Rétablir tous param.", \
    "Ripristino di fabbrica", \
    "Restaurar à fabrica", \
    "Восстанов. все настр.", \
    "Tüm Ayarl. Geri Yükle"
};

char *motion[MAX_LANGUAGE] = { \
    "运动", \
    "Movement", \
    "Bewegung", \
    "Movimiento", \
    "Mouvement", \
    "Mouvement", \
    "Movimento", \
    "Движение", \
    "Hareket"
};

char *motion_setting[MAX_LANGUAGE] = { \
    "运动设置", \
    "Motion Settings", \
    "Bewegung Einstellungen", \
    "Ajustes Movimiento", \
    "Réglages du mouvement", \
    "Impostazioni di movimento", \
    "Config. de Movimento", \
    "Настройки движения", \
    "Hareket Ayarları"
};

char *steps_setting[MAX_LANGUAGE] = { \
    "步进设置", \
    "Steps set", \
    "Üv eingestellt", \
    "Ajus. tasa transm.", \
    "Régl. ratio trans.", \
    "TX Rto set", \
    "Config. Passos/mm", \
    "Набор TX Rto", \
    "TX Rto ayar"
};

char *steps[MAX_LANGUAGE] = { \
    "步进值", \
    "Steps", \
    "Üv", \
    "Tasa transm.", \
    "Ratio trans.", \
    "TX Rto", \
    "Passos/mm", \
    "TX Rto", \
    "TX Rto"
};

char *macc_setting[MAX_LANGUAGE] = { \
    "最大加速度", \
    "Max. ACC", \
    "Max. BES", \
    "Max. Acel.", \
    "Accél. max.", \
    "Max. ACC", \
    "Aceleração máx.", \
    "Макс. ACC", \
    "Maks. ACC"
};

char *mconcor_setting[MAX_LANGUAGE] = { \
    "最大拐角速度", \
    "Max. corner SP", \
    "Max. Ecken-SP", \
    "Max. vel. esquina", \
    "Vitesse ang. Max.", \
    "Angolo massimo SP", \
    "Vel. Aresta máx.", \
    "Макс. угол SP", \
    "Maks.köşe SP"
};

char *mspeed_setting[MAX_LANGUAGE] = { \
    "最大速度", \
    "Max. speed", \
    "Max. Gesch.", \
    "Max. velocidad", \
    "Vitesse max.", \
    "Velocità massima", \
    "Vel. máx.", \
    "Макс. скорость", \
    "Maks. hız"
};

char *temp_pid[MAX_LANGUAGE] = { \
    "温度PID", \
    "Temp. PID", \
    "PID Temp.", \
    "Temp.PID", \
    "Temp. PID", \
    "Temp. PID", \
    "Temp.PID", \
    "Темп. PID", \
    "Sıcakl. PID"
};

char *temp_pid_setting[MAX_LANGUAGE] = { \
    "温度PID设置", \
    "Temp. PID set", \
    "PID -Temp. eingestellt", \
    "Temp. PID", \
    "Régl. Tempér. PID", \
    "Temp. PID impostato", \
    "Config. temp. PID", \
    "Набор темп. PID", \
    "Sıcakl. PID ayarı"
};

char *noz_p_value[MAX_LANGUAGE] = { \
    "喷嘴P值", \
    "noz. P val.", \
    "Düse P-Wert", \
    "Val. P de Boq.", \
    "Bus. val. P", \
    "Val. P uge.", \
    "Val. Bic. P", \
    "знач. соп. P", \
    "nozul P değ."
};

char *noz_i_value[MAX_LANGUAGE] = { \
    "喷嘴I值", \
    "noz. I val.", \
    "Düse I-Wert", \
    "Val. I de Boq.", \
    "Bus. val. I", \
    "Val. I uge.", \
    "Val. Bic. I", \
    "знач. соп. I", \
    "nozul I değ."
};

char *noz_d_value[MAX_LANGUAGE] = { \
    "喷嘴D值", \
    "noz. D val.", \
    "Düse D-Wert", \
    "Val. D de Boq.", \
    "Bus. val. D", \
    "Val. D uge.", \
    "Val. Bic. D", \
    "знач. соп. D", \
    "nozul D değ."
};

char *bed_p_value[MAX_LANGUAGE] = { \
    "热床P值", \
    "H&B P val.", \
    "H&B P-Wert", \
    "Val. P de H&B", \
    "H&B val. P", \
    "Val. P H&B", \
    "Val. H&B P", \
    "знач. H&B P", \
    "H&B P değ."
};

char *bed_i_value[MAX_LANGUAGE] = { \
    "热床I值", \
    "H&B I val.", \
    "H&B I-Wert", \
    "Val. I de H&B", \
    "H&B val. I", \
    "Val. I H&B", \
    "Val. H&B I", \
    "знач. H&B I", \
    "H&B I değ."
};

char *bed_d_value[MAX_LANGUAGE] = { \
    "热床D值", \
    "H&B D val.", \
    "H&B D-Wert", \
    "Val. D de H&B", \
    "H&B val. D", \
    "Val. D H&B", \
    "Val. H&B D", \
    "знач. H&B D", \
    "H&B D değ."
};

char *confirm[MAX_LANGUAGE] = { \
    "确定", \
    "Yes", \
    "Ja", \
    "Sí.", \
    "Oui", \
    "Sì", \
    "Sim", \
    "Да", \
    "Evet"
};

char *cancel[MAX_LANGUAGE] = { \
    "取消", \
    "No", \
    "Nein", \
    "No.", \
    "Non", \
    "No", \
    "Cancelar", \
    "Нет", \
    "Hayır"
};

char *tips[MAX_LANGUAGE] = { \
    "温馨提示", \
    "Tips", \
    "Tipps", \
    "Consejos", \
    "Conseils", \
    "Suggerimenti", \
    "Dicas", \
    "Советы", \
    "İpuçları"
};

char *pause_print[MAX_LANGUAGE] = { \
    "暂停打印？", \
    "Pause Printing？", \
    "Drucken pausieren？", \
    "Pausar impresión？", \
    "Pause de l'impression？", \
    "Stampa in pausa？", \
    "Pausar impressão？", \
    "Приостановить печать？", \
    "Yazdırmayı Duraklat？"
};

char *stop_print[MAX_LANGUAGE] = { \
    "停止打印？", \
    "Stop Printing？", \
    "Drucken stoppen？", \
    "Detener impresión？", \
    "Arrêter l'impression？", \
    "Stop stampa？", \
    "Parar de impressão？", \
    "Остановить печать？", \
    "Yazdırmayı Durdur？"
};

char *resume_print[MAX_LANGUAGE] = { \
    "继续打印？", \
    "Continue？", \
    "Fortsetzen？", \
    "Continuar？", \
    "Continuer？", \
    "Continua？", \
    "Continuar？", \
    "Продолжить？", \
    "Devam et？"
};

char *print_file[MAX_LANGUAGE] = { \
    "打印文件？", \
    "Print？", \
    "Drucken？", \
    "Imprimir？", \
    "Imprimer？", \
    "Stampa？", \
    "Imprimir？", \
    "Печать？", \
    "Yazdır？"
};

char *printing_set[MAX_LANGUAGE] = { \
    "打印期间参数设置", \
    "Parameter settings", \
    "Parameter-Ein.", \
    "Ajustes parámetros", \
    "Régl. des paramètres", \
    "Impostazioni dei parametri", \
    "Config. de parâmetros", \
    "Настройки параметра", \
    "Parametre ayarları"
};

char *print_speed[MAX_LANGUAGE] = { \
    "打印速度", \
    "Print speed", \
    "Druckgeschw.", \
    "Veloc. impr.", \
    "Vitesse d'impression", \
    "Velocità di stampa", \
    "Vel. de impressão", \
    "Скорость печати", \
    "Baskı hızı"
};

char *auto_power_off[MAX_LANGUAGE] = { \
    "自动关机", \
    "Auto OFF", \
    "Auto AUS", \
    "Apag. Auto.", \
    "Auto OFF", \
    "Auto OFF", \
    "Auto Desligamento ", \
    "Авто выкл.", \
    "Oto KAPALI"
};

char *z_offset[MAX_LANGUAGE] = { \
    "Z轴补偿", \
    "Z-axis Comp.", \
    "Z-Achse Komp.", \
    "Comp. eje Z", \
    "Comp. Axe Z", \
    "Comp. asse Z", \
    "Compensação Eixo-Z", \
    "Ось Z комп.", \
    "Z eks. Komp."
};

char *auto_level_finish[MAX_LANGUAGE] = { \
    "自动调平完成", \
    "Auto leveling completed", \
    "Automatic leveling completed", \
    "Automatic leveling completed", \
    "Automatic leveling completed", \
    "Automatic leveling completed", \
    "Automatic leveling completed", \
    "Automatic leveling completed", \
    "Automatic leveling completed"
};

//请选择打印文件
