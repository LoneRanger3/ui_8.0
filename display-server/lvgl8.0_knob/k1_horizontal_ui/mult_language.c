/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-12-27 09:34:07
 * @LastEditTime: 2023-10-30 04:15:52
 */
#include "mult_language.h"

static unsigned short CurLanguageIndex = 0;

void set_cur_language_index(unsigned short language_index)
{
    if ( language_index >= (MAX_LANGUAGE) )
        language_index = MAX_LANGUAGE - 1;
    
    CurLanguageIndex = language_index;
}

unsigned short get_cur_language_index()
{
    return CurLanguageIndex;
}
/*********************boot*****************************/
const char *Boot0Tips1[MAX_LANGUAGE] = { \
    "请按照黄色箭头所指位置,将a、b、c三个螺丝拆下来。", \
    "Remove three screws a, b and c according to the location of the yellow arrow.", \
    "Die drei Schrauben a, b und c in der durch den gelben Pfeil angezeigten Richtung entfernen.", \
    "Retire los tres tornillos a, b y c según la posición que indica la flecha amarilla.", \
    "Retirez les trois vis a, b et c selon la position indiquée par la flèche jaune.", \
    "Rimuovere le tre viti a, b e c secondo la posizione indicata dalla freccia gialla.", \
    "Retire os três parafusos, a, b e c, de acordo com a posição indicada pela seta amarela.", \
    "Согласно положению, указанному желтой стрелкой снимите три винта a, b и c.", \
    "Sarı ok ile gösterilen pozisyona göre a, b ve c olmak üzere üç vidayı çıkarın.", \
    "黄色い矢印で示された位置にある3つのネジa、b、cを取り外します。"
};

const char *Boot1Tips1[MAX_LANGUAGE] = { \
    "请点击“确定”使打印平台自动升起", \
    "Please click OK to raise the printing platform automatically", \
    "Bitte klicken Sie auf „Ja‟, um die Druckplattform automatisch anzuheben", \
    "Haga clic en \"Sí\" para subir automáticamente la plataforma de impresión", \
    "Cliquez sur « Oui » pour faire monter la plate-forme d'impression automatiquement", \
    "Fare clic su \"Sì\" per sollevare automaticamente la piattaforma di stampa", \
    "Clique em “Sim” para levantar automaticamente a plataforma de impressão", \
    "Нажмите «Да» для автоподъема печатной платформы", \
    "Yazdırma platformunu otomatik olarak kaldırmak için lütfen \"Evet\" tuşuna tıklayın", \
    "プリント台を自動で上げるため、「確認」をクリックしてください"
};

const char *Boot1Tips2[MAX_LANGUAGE] = { \
    "平台升起后可取出底部泡棉", \
    "Remove the bottom foam when the platform is raised", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *Boot1Tips3[MAX_LANGUAGE] = { \
    "确定", \
    "Ok", \
    "Ja",\
    "Sí",\
    "Oui",\
    "Sì",\
    "Sim",\
    "Да",\
    "Evet",\
    "確認"
};

const char *Boot2Tips1[MAX_LANGUAGE] = { \
    "请将剩余泡棉取出", \
    "Please remove the remaining foam", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *Boot2Tips2[MAX_LANGUAGE] = { \
    "取出泡棉后点击“确定”进行下一步", \
    "Remove the foam and click \"OK\" to proceed to the next step", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *Boot3Tips1[MAX_LANGUAGE] = { \
    "欢迎使用创想三维打印机", \
    "Welcome to Creality 3D Printer", \
    "Willkommen beim Creality 3D-Drucker", \
    "Bienvenidos a la Impresora 3D de Creality", \
    "Bienvenue sur l'imprimante 3D Creality", \
    "Benvenuti alla stampante Creality 3D", \
    "Bem-vindo à Impressora 3D da Creality", \
    "Добро пожаловать в 3D-принтер Creality!", \
    "Creality 3D Yazıcıya hoş geldiniz", \
    "クリエイティブ3Dプリンターへようこそ"
};

const char *Boot3Tips2[MAX_LANGUAGE] = { \
    "请保持图中蓝色立方范围内无杂物后点击“确定”", \
    "Please keep the blue cube in the diagram clear of debris and click \"OK\".", \
    "Bitte halten Sie den blauen Würfel im Diagramm von Schmutz entfernt und klicken Sie auf „Ja‟.", \
    "Mantenga el cubo azul del diagrama libre de resiudos y haga clic en \"Sí\".", \
    "Veillez à ce que le cube bleu du diagramme ne soit pas encombré de débris et cliquez sur « Oui ».", \
    "Assicurati che il cubo blu del diagramma sia libero da detriti e clicca su \"Sì\".", \
    "Mantenha o cubo azul no diagrama sem detritos e clique em “Sim”.", \
    "Убедитесь в чистоте синего куба на схеме и нажмите «Да».", \
    "Lütfen diyagramdaki mavi kübü kalıntılardan uzak tutun ve \"Evet\" tuşuna tıklayın.", \
    "写真の青い立方体にゴミが入らないようにして、「確認」をクリックしてください。"
};

const char *PrivacycontentPreview[MAX_LANGUAGE] = { \
    "深圳市创想三维科技股份有限公司庄严承诺保护使用Creality产品和服务（以下统称“Creality服务”）之用户（以下统称“用户”或“您”）的隐私。您在使用Creality服务时，我们可能会收集和使用您的相关信\n息。请注意我们会不时地检查我们的政策，因此有关的",\
    "Thank you for choosing Creality products.\nShenzhen Creality 3D Technology Co., Ltd. (“Creality 3D”, “we”, “us”, or “our”) solemnly commits to protecting the privacy of these users (hereinafter",\
    "Vielen Dank, dass Sie sich für die Produkte von Creality entschieden haben.\n\nShenzhen Creality 3D Technology Co., Ltd. („Creality 3D“, „wir“, „uns“ oder „unser“) verpflichtet sich",\
    "Gracias por elegir los productos de Creality.\n\nShenzhen Creality 3D Technology Co., Ltd. (\"Creality 3D\", \"nosotros\", \"nosotros\" o \"nuestro\") se compromete a proteger la privacidad",\
    "Nous vous remercions d'avoir opté pour les produits Creality.\n\nShenzhen Creality 3D Technology Co., Ltd (« Creality 3D », « nous », « notre » ou « nos ») tient à protéger la",\
    "Grazie per aver scelto i prodotti Creality.\n\nShenzhen Creality 3D Technology Co., Ltd. (\"Creality 3D\", \"noi\", \"ci\" o \"nostro\") si impegna solennemente a proteggere la privacy degli utenti (di seguito",\
    "Obrigado por escolher os produtos Creality.\n\nA Shenzhen Creality 3D Technology Co., Ltd. (\"Creality 3D\", \"nós\", \"nossa\" ou \"nosso\") compromete-se solenemente a proteger a",\
    "Спасибо за выбор продукции Creality.\n\nКомпания Shenzhen Creality 3D Technology Co., Ltd.(далее — «Creality 3D», «мы», «нас» или «наш») торжественно обязуется охранять",\
    "Creality ürünlerini tercih ettiğiniz için teşekkür ederiz.\n\nShenzhen Creality 3D Technology Co., Ltd. (\"Creality 3D\", \"biz\", \"bize\", veya \"bizim\") Creality ürün ve hizmetlerini (bundan böyle \"Creality hizmetleri\"",\
    "Crealityの製品を購買し使用して頂き、ありがとうございます！\n\nShenzhen Creality 3D Technology Co., Ltd.は、Creality製品"
};

const char *Privacycontent[MAX_LANGUAGE] = { \
    "深圳市创想三维科技股份有限公司庄严承诺保护使用Creality产品和服务（以下统称“Creality服务”）之用户（以下统称“用户”或“您”）的隐私。您在使用Creality服务时，我们可能会收集和使用您的相关信\n息。请注意我们会不时地检查我们的政策，因此有关的措施会随之变化。我们恳请您定期光顾本页面，以确保对我们《隐私政策》最新版本始终保持了解。在阅读完本政策之后，如您对本《隐私政策》或与本《隐私政\n策》相关的事宜有任何问题，请与cs@creality.com联系。\n一、我们可能收集的信息\n\t（一）与个人身份无关的信息：当您使用Creality服务时，我们可能收集和汇总诸如用户的来源途径、访问顺序等信息，例如记录使用Creality服务的每个用户的来源途径等。\n\t（二）有关个人身份的信息：当您使用Creality服务时，我们可能收集和汇总或要求您提供个人电话号码；网络身份标识信息（包括系统账号、IP地址、电子邮箱地址及与前述有关的密码、口令、口令保护答案等）。\n\t\t（1）个人上网记录和日志信息（包括网站浏览记录、软件使用记录、点击记录、操作日志等）；\n\t\t（2）设备信息（包括设备型号、设备MAC地址、操作系统类型、设备设置）；软件列表唯一设备识别码（如IMEI/android ID/IDFA/OPENUDID/GUID、SIM卡IMSI信息等在内的描述个人常用设备基本情况的信息）。我们收集您的信息主要是为了您和其他用户能够更容易和更满意地使用Creality服务。创想云的目标是向所有的互联网用户提供安全、有趣及有教益的上网经历。而这些信息有助于我们实现这一目标。二、我们如何收集和使用信息（一）我们将通过以下途径收集和获得您的信息，例如：（1）您在注册Creality服务的帐号或使用Creality服务时，向我们提供的信息；（2）您通过Creality服务向其他方提供的共享信息，以及您使用Creality服务时所储存的信息；（3）我们获取的您的信息。您在使用Creality服务时，我们收集、汇总、记录的信息，例如日志信息、设备信息等。（二）COOKIES、日志档案我们或我们的第三方合作伙伴可能通过COOKIES获取和使用您的信息，并将该等信息储存为日志信息。通过使用COOKIES，我们向用户提供简单易行并富个性化的网络体验。一个COOKIES是少量的数据，它们从一个网络服务器送至您的浏览器并存在计算机硬盘上。我们使用COOKIES是为了让其用户可以受益。COOKIES使得我们能更好、更快地为您服务，并且使您在Creality服务上的经历更富个性化。然而，您应该能够控制COOKIES是否以及怎样被你的浏览器接受。请查阅您的浏览器附带的文件以获得更多这方面的信息。（三）我们可能通过COOKIE收集和使用您的信息，并将该等信息储存（1）记住您的身份。例如：COOKIES有助于我们辨认您作为我们的注册用户的身份，或保存您向我们提供有关您的喜好或其他信息；（2）分析您使用我们服务的情况。我们可利用COOKIES来了解您使用Creality服务进行什么活动、或哪些服务或服务最受欢迎；（3）广告优化。COOKIES有助于我们根据您的信息，向您提供与您相关的广告而非进行普遍的广告投放。Creality服务上可能会有广告商和其他合作方放置的COOKIES。这些COOKIES可能会收集与您相关的非个人身份信息，以用于分析用户如何使用该等服务、向您发送您可能感兴趣的广告，或用于评估广告服务的效果。这些第三方COOKIES收集和使用该等信息不受本《隐私政策》约束，而是受到其自身的个人信息保护声明约束，我们不对第三方的COOKIES承担责任。您可以通过浏览器或用户选择机制拒绝或管理COOKIES。但请您注意，如果您停用COOKIES，我们有可能无法为您提供最佳的服务体验，某些服务也可能无法正常使用。（四）我们会出于以下目的，收集和使用您的信息：1. 向您推送消息为您展示和推送商品或服务。经过您的同意，我们可能使用您的设备信息，通过电子邮件、短信或其他方式向您发送营销信息，提供或推广我们或第三方的如下商品和服务：我们的商品和服务，包括但不限于：网上媒体服务、社交网络服务、互联网搜索服务、位置和地图服务、应用软件和服务、数据管理软件和服务、积分和奖励计划、设备商品、3D打印周边商品；以及我们认为可能与您相关的其他商品和服务。您可以随时通过联系我们的客服撤回您的同意。2. 改进我们的服务我们可能将通过某一项Creality服务所收集的信息，用于我们的其他服务。例如，在您使用某一项Creality服务时所收集的您的信息，可能在另一项Creality服务中用于向您提供特定内容或向您展示与您相关的、而非普遍推送的信息；我们可能让您参与有关Creality服务的调查，帮助我们改善现有服务或设计新服务；同时，我们可能将您的信息用于软件更新。您了解并同意，在收集您的信息后，我们将通过技术手段对数据进行去标识化处理，去标识化处理的信息将无法识别您的身份，在此情况下我们有权使用已经去标识化的信息，对用户数据库进行分析并予以商业化的利用。如果我们将您的信息用于本《隐私政策》中未载明的其他用途，会事先征求您同意。3. 征得授权同意的例外，根据相关法律法规规定，以下情形中收集您的信息无需征得您的授权同意：（1）与国家安全、国防安全有关的；（2）与公共安全、公共卫生、重大公共利益有关的；（3）与犯罪侦查、起诉、审判和判决执行等有关的；（4）出于维护信息主体或其他个人的生命、财产等重大合法权益但又很难得到您本人同意的；（5）所收集的信息是您自行向社会公众公开的；（6）从合法公开披露的信息中收集信息的，如合法的新闻报道、政府信息公开等渠道；（7）根据您的要求签订合同所必需的；（8）用于维护Creality服务的安全稳定运行所必需的，例如发现、处置产品或服务的故障；（9）为合法的新闻报道所必需的；（10）学术研究机构基于公共利益开展统计或学术研究所必要，且对外提供学术研究或描述的结果时，对结果中所包含的信息进行去标识化处理的；（11）法律法规规定的其他情形。三、我们如何保留、储存和保护信息我们仅在本《隐私政策》所述目的所必需期间和法律法规要求的时限内保留您的信息。1. 法律法规有明确规定；2. 获得您的授权同意；3. 您使用的产品、服务涉及跨境，创想云需要向境外提供您的个人信息的。针对以上情形，我们会确保依据本政策及国家法律法规要求对您的个人信息提供足够的保护。我们将采取以下手段保护您的信息：（一）数据安全技术措施我们会采用符合业界标准的安全防护措施，包括建立合理的制度规范、安全技术来防止您的信息遭到未经授权的访问使用、修改,避免数据的损坏或丢失。网络服务采取了多种加密技术，例如在某些服务中，我们将利用加密技术（例如SSL）来保护您的信息，采取加密技术对您的信息进行加密保存，并通过隔离技术进行隔离。在信息使用时，例如信息展示、信息关联计算，我们会采用多种数据脱敏技术增强信息在使用中安全性。采用严格的数据访问权限控制和多重身份认证技术保护信息，避免数据被违规使用。（二）我们为保护信息采取的其他安全措施我们通过建立数据分类分级制度、数据安全管理规范、数据安全开发规范来管理规范信息的存储和使用。我们通过信息接触者保密协议、监控和审计机制来对数据进行全面安全控制。加强安全意识。我们还会举办安全和隐私保护培训课程，加强员工对于保护信息重要性的认识。（三）我们仅允许有必要知晓这些信息的创想三维员工访问您的信息，并为此设置了严格的访问权限控制和监控机制。我们同时要求可能接触到您的信息的所有人员履行相应的保密义务。如果未能履行这些义务，可能会被追究法律责任或被中止与创想三维的合作关系。（四）我们会采取一切合理可行的措施，确保未收集无关的信息。（五）互联网并非绝对安全的环境，而且电子邮件、即时通讯、社交软件或其他服务软件等与其他用户的交流方式无法确定是否完全加密，我们建议您使用此类工具时请使用复杂密码，并注意保护您的信息安全。（六）互联网环境并非百分之百安全，我们将尽力确保或担保您发送给我们的任何信息的安全性。如果我们的物理、技术、或管理防护设施遭到破坏，导致信息被非授权访问、公开披露、篡改、或毁坏，导致您的合法权益受损，我们将承担相应的法律责任。（七）安全事件处置（1）在通过Creality服务与第三方进行沟通或购买商品及服务时，您不可避免的要向交易对方或潜在的交易对方披露自己的信息，如联络方式或者邮政地址等。请您妥善保护自己的信息，仅在必要的情形下向他人提供。（2）为应对信息泄露、损毁和丢失等可能出现的风险，我们制定了多项制度，明确安全事件、安全漏洞的分类分级标准及相应的处理流程。我们也为安全事件建立了专门的应急响应团队，按照安全事件处置规范要求，针对不同安全事件启动安全预案，进行止损、分析、定位、制定补救措施、联合相关部门进行溯源和打击。在不幸发生信息安全事件后，我们将按照法律法规的要求，及时向您告知：安全事件的基本情况和可能的影响、我们已采取或将要采取的处置措施、您可自主防范和降低风险的建议、对您的补救措施等。我们同时将及时将事件相关情况以邮件、信函、电话、推送通知等方式告知您，难以逐一告知信息主体时，我们会采取合理、有效的方式发布公告。同时，我们还将按照监管部门要求，主动上报信息安全事件的处置情况。(3)云储存服务：为给您提供云端储存服务(您上传至创想云的图片、音视频内容会储存在云端以及有关场景)，第三方服务商可能会收集您的设备信息、网络相关信息、运营商信息。以上如您有任何疑问，您可以随时访问www.crealitycloud.cn/以取得我们或我们合作的第三方所收集并处理的您的信息。四、您对您的个人信息享有的权利（一）数据删除根据您所适用的国家或地区法律法规，您有权要求访问、更正、删除我们持有的与您相关的任何个人信息（以下简称请求）。这些权利将受适用法律规定的特定排除和例外情况的限制。您的任何问题可以通过 cs@creality.com 邮箱联系我们。如您不同意隐私政策，设备将不会提供网络功能。如您对本隐私保护政策有任何疑问或建议，可以通过官方邮箱 cs@creality.com 联系我们。\n\n\n",\
    "Thank you for choosing Creality products.\nShenzhen Creality 3D Technology Co., Ltd. (“Creality 3D”, “we”, “us”, or “our”) solemnly commits to protecting the privacy of these users (hereinafter referred to as \"users\" or \"you\") who use Creality products and services (hereinafter referred to as \"Creality services\"). We may collect and use the information about you when you are using such Creality services. It should be noted that we will review our policies from time to time, therefore such relevant measures may change accordingly. We kindly request that you visit this page regularly to ensure that you are always aware of the latest version of our Privacy Policy. Upon reading this Privacy Policy, please feel free to contact us via cs@creality.com if you have any doubts about this Privacy Policy or the matters related to it.\n1. WHAT INFORMATION DO WE COLLECT?\n (I) Information unrelated to personal identity:\nWhen you are using Creality services, we may collect and summarize information such as user origin and access order, including recording the origin of each user using Creality services.\n (II) Information about personal identity:\nWhen you are using Creality services, we may collect and summarize or ask for your personal phone number, and network identity information (including system account number, IP address, e-mail address and related passphrases, passwords and password protection answers, etc.).\n (1) Personal Internet-surfing records and log information (including website browsing history, software use records, click records, operation logs, etc.);\n (2) Device information (including device model, device MAC address, operating system type and device settings), and software list unique device identification code (such as IMEI/android ID/IDFA/OPENUDID/GUID, SIM card IMSI information and other information describing the basic status of commonly used personal devices).\nWe collect information about you primarily to make it easier and more satisfying for you and other users to use Creality services. The purpose of Creality Cloud is to provide all Internet users with safe, interesting and instructive Internet-surfing experiences, while such information will help us achieve such purpose.\nII. HOW DO WE COLLECT AND USE INFORMATION\n (I) We will collect and obtain your information through the following channels, for example:\n (1) The information you provide to us when registering for or using Creality services;\n (2) The shared information you provide to other parties through Creality services and the information you store when using Creality services; and\n (3) The information we obtain about you. When you are using Creality services, we collect, summarize and record the involved information, for example: log information, device information and so on.\n (II) COOKIES and log files\nWe or our third party partners may obtain and use your information via COOKIES and store it as log information. Via COOKIES, we provide users with an easy-to-use and personalized network experience. COOKIES represent a small amount of data that are sent from a network server to your browser and stored on your computer's hard disk. We use COOKIES so that its users can benefit.\nCOOKIES make it possible for us to serve you better and faster, and to personalize your experience with Creality services. However, you should be able to control whether and how COOKIES are accepted by your browser. Please refer to the files that come with your browser for more information in this regard.\n (III) We may collect and use your information via COOKIE and store it accordingly\n (1) Remember who you are. For example: COOKIES assist us in identifying you as our registered user or saving the information you provide us about your preferences or other aspects;\n (2) Analyze your use of our services. We may apply COOKIES to find out what activities you are doing with Creality services, or which services or service are the most popular;\n (3) Conduct advertising optimization. COOKIES assist us in offering you with the advertisements related to you based on your information, rather than conducting general advertising campaigns.\nCreality services may contain COOKIES placed by advertisers and other partners. Such COOKIES may collect non-personally identifiable information about you for the purpose of analyzing how users use such services, sending you the advertisements in which you may be interested, or evaluating the effectiveness of advertising services. The collection and use of such information by such third party via COOKIES is not subject to this Privacy Policy, but to their own personal information protection statements; and we do not assume responsibility for the COOKIES of third parties.\nYou may deny or manage COOKIES through a browser or the user selection mechanism. However, it should be noted that if you disable COOKIES, we may not be able to offer you the best service experience, and even some services may not be used normally.\n (IV) We will collect and use your information for the following purposes:\n1. Pushing messages to you\nShow and push goods or services to you. Upon your consent, we may rely on your device information to send you marketing information via email, SMS or other means, so as to provide or promote the following goods and services of us or third parties:\nOur goods and services include but are not limited to online media services, social networking services, Internet search services, location and map services, application software and services, data management software and services, points and reward programs, device products, 3D printing peripheral products, as well as other goods and services that we believe may be related to you.\n2. Improving our services\nWe may apply the information gathered through certain Creality services to other services of us. For example, your information as collected when you are using certain Creativity services may be used in another Creativity services to provide you with specific contents or show information related to you rather than being generally pushed; we may involve you in surveys related to Creativity services to help us improve existing services or design new ones; and meanwhile, we may use your information for software updates.\nYou understand and agree that after your information is collected, we may de-identify the data by technical means, and the de-identified information will not help identify your identity, in which case we are entitled to use the de-identified information to analyze the user database and make commercial use of the same. Your consent will be sought in advance if your information is used for other purposes not specified in this Privacy Policy.\n3. With the exception of obtaining authorization. Pursuant to relevant laws and regulations, your authorization is not required in collecting your information under the following circumstances:\n (1) It is related to national security and national defense security;\n (2) It is related to public safety, public health and major public interests;\n (3) It is related to criminal investigation, prosecution, trial and judgment execution;\n (4) It is for the purpose of safeguarding the significant legitimate rights and interests of the information subject or other individuals, such as life and property, but it is difficult to obtain your personal consent;\n (5) The collected information is disclosed to the public by yourself;\n (6) The information is collected from legally publicly disclosed information, such as legitimate news reports, government information disclosure and other channels;\n (7) It is necessary for signing contracts as required by you;\n (8) It is necessary for maintaining the safe and stable operations of Creality services, such as finding and handling product or service failures;\n (9) It is necessary for legitimate news reporting;\n (10) It is necessary for academic research institutions to conduct statistical or academic research out of the public interest, and to de-identify the information contained in the results when providing academic research or descriptive results to the public; and\n (11) Other circumstances stipulated by laws and regulations.\nIII. HOW DO WE RETAIN, STORE AND PROTECT INFORMATION\nWe will retain your information only for as long as necessary for the purposes described in this Privacy Policy and for as long as required by laws and regulations.\n1. There are clear provisions in laws and regulations;\n2. Your authorization and consent are obtained; and\n3. Creality Cloud needs to provide your personal information overseas at the time when the products and services you are using involve cross-border acts. In such cases, we will ensure that your personal information is adequately protected in accordance with this Policy and the requirements of national laws and regulations.\nWe will take the following measures to protect your information:\n (I) Technical measures for data security\nWe will adopt these security measures in line with industry standards, including establishing reasonable institutional norms and security technologies to prevent unauthorized access, use and modification of your information, and to avoid data damage or loss. Network services employ a variety of encryption technologies; for example, in certain services, we will adopt encryption technologies (e.g. SSL) to protect your information as well as encrypt and save it, and apply isolation technologies to isolate it.\nWe will adopt a variety of data desensitization technologies to enhance security of the information in use, such as information display and information association calculation. Strict data access control and multiple identity authentication technologies are adopted to protect information and avoid illegal use of data.\n (II) Other security measures we take to protect information include managing and standardizing the storage and use of information by establishing data classification and grading system, data security management norms and data security development norms.\nWe conduct comprehensive security control over data through information contact confidentiality agreement, and monitoring and auditing mechanism. We strengthen safety awareness. In addition, we hold security and privacy protection training courses to enhance employees' awareness of the importance of information protection.\n (III) We only allow these Creality 3D employees who need to know such information to get access to your information, and set up strict access control and monitoring mechanisms in this regard. Meanwhile, we require all the personnel who may have access to your information to fulfill the corresponding confidentiality obligations. Failure to fulfill such obligations may result in legal liability or suspension of the partnership with Creality 3D.\n (IV) We will take all reasonable and feasible steps to ensure that no irrelevant information is collected.\n (V) The Internet does not present an absolutely secure environment, and it is impossible to determine whether the communication methods with other users in e-mail, instant messaging, social networking software or other service software are completely encrypted, so we recommend that you set complex passwords when using such tools, and make every effort to guarantee information security.\n (VI) Since the Internet environment is not 100% secure, we will endeavor to ensure or guarantee the security of any information you send to us. In case our physical, technical or management protection facilities are damaged, resulting in unauthorized access to or public disclosure, tampering or destruction of your information, and further resulting in damage to your legitimate rights and interests, we will assume corresponding legal liabilities.\n (VII) Security incident handling\n (1) In the course of communicating with third parties or purchasing goods and services through Creality services, it is inevitable that you will disclose information about yourself, such as contact information or postal address, to counterparties or potential counterparties. Please get your information protected properly and provide it to others only when necessary.\n (2) In response to the potential risks of information leakage, damage and loss, we have developed multiple systems to clarify the classification and grading standards for security incidents and vulnerabilities, as well as the corresponding handling processes. Furthermore, we have set up a special emergency response team for security incidents, started security plans against different security incidents as required by the security incident handling norms, stopped losses, analyzed, located and developed remedial measures, as well as collaborated with relevant departments to trace and combat. In the event of any unfortunate information security incident, we will inform you in time as required by laws and regulations, including the basic situation and possible impact of the security incident, the disposal measures we have taken or will take, the suggestions for you to prevent and reduce risks independently, and the remedial measures for you. We will promptly inform you about the incident-related situation by mail, letter, telephone, push notification, etc.; and we will make an announcement in a reasonable and effective way when it is difficult to inform the information subject one by one. Meanwhile, we will proactively report the handling of information security incidents as required by regulatory authorities.\n (3) Cloud storage services: With a view to providing you with cloud storage services (the pictures and audio and video contents you upload to Creality Cloud will be stored in the cloud and related scenarios), third-party service providers may collect your device information, network-related information and operator information.\nIf you have any questions about the above, you can visit www.crealitycloud.com/ at any time to obtain your information as collected and processed by us or our cooperating third parties.\nIV. YOUR RIGHTS TO YOUR PERSONAL INFORMATION\nPursuant to the laws and regulations of your residing country or region, you are entitled to request access, correction and deletion of any personal information held by us related to you (hereinafter referred to as the \"request\"). But such rights will be subject to specific exclusions and exceptions under applicable laws. And any of your questions can be addressed via cs@creality.com to us.\nIf you disagree with this Privacy Policy, the device will not offer network functionality.\nIf you have any questions or suggestions about this Privacy Policy, please feel free to contact us via cs@creality.com, the official mailbox.\n",\
    "Vielen Dank, dass Sie sich für die Produkte von Creality entschieden haben.\n\nShenzhen Creality 3D Technology Co., Ltd. („Creality 3D“, „wir“, „uns“ oder „unser“) verpflichtet sich, die Privatsphäre der Benutzer (im Folgenden als „Benutzer“ oder „Sie“ bezeichnet) zu schützen, die die Produkte und Dienstleistungen von Creality (im Folgenden als „Creality-Dienstleistungen“ bezeichnet) nutzen. Wir können Informationen über Sie erheben und verwenden, wenn Sie solche Creality-Dienstleistungen nutzen. Wir weisen Sie darauf hin, dass wir unsere Datenschutzerklärung von Zeit zu Zeit überprüfen werden und dass sich diese Datenschutzerklärung entsprechend ändern kann. Wir bitten Sie, diese Seite regelmäßig zu besuchen, um sicherzustellen, dass Sie stets über die aktuelle Version unserer Datenschutzerklärung informiert sind. Nachdem Sie diese Datenschutzerklärung gelesen haben, zögern Sie bitte nicht, uns unter cs@creality.com zu kontaktieren, wenn Sie Fragen zu dieser Datenschutzerklärung oder damit zusammenhängenden Themen haben.\n\nI. WELCHE DATEN ERHEBEN WIR?\n(I) Daten, die nicht mit Ihrer persönlichen Identität in Verbindung gebracht werden können:\nWenn Sie die Creality-Dienstleistungen nutzen, können wir Daten wie die Herkunft des Nutzers und Ihre Bestellung erheben und zusammenfassen, einschließlich der Aufzeichnung der Herkunft jedes Nutzers, der die Creality-Dienstleistungen nutzt.\n(II) Personenbezogene Daten:\nWenn Sie Creality-Dienstleistungen nutzen, können wir Ihre persönliche Telefonnummer und Informationen zu Ihrer Netzwerkidentität (einschließlich Systemkontonummer, IP-Adresse, E-Mail-Adresse und zugehörige Passphrasen, Passwörter und Antworten auf den Passwortschutz usw.) erheben und zusammenfassen oder von Ihnen anfordern.\n(1) Personenbezogene Daten über das Surfen im Internet und Protokolldaten (einschließlich des Verlaufs des Surfens auf der Website, der Verwendung von Software, Klicks, Transaktionen usw.);\n(2) Geräteinformationen (einschließlich Gerätemodell, Geräte-MAC-Adresse, Betriebssystemtyp und Geräteeinstellungen) und Softwareliste mit eindeutigem Geräteidentifizierungscode (wie IMEI/Android-ID/IDFA/OPENUDID/GUID, SIM-Karten-IMSI-Informationen und andere Daten, die den grundlegenden Status allgemein verwendeter persönlicher Geräte beschreiben).\nWir erheben Daten über Sie in erster Linie, um die Nutzung der Creality-Dienstleistungen für Sie und andere Nutzer einfacher und zufriedenstellender zu gestalten. Der Zweck von Creality Cloud ist es, allen Benutzern ein sicheres, interessantes und lehrreiches Erlebnis beim Surfen im Internet zu bieten, und diese Daten helfen uns, diesen Zweck zu erreichen.\nII. WIE WIR DATEN ERHEBEN UND VERWENDEN\n(I) Wir erheben und erhalten Ihre Daten beispielsweise über die folgenden Kanäle:\n(1) Die Daten, die Sie uns zur Verfügung stellen, wenn Sie sich für Creality-Dienstleistungen registrieren oder diese nutzen;\n(2) Die Daten, die Sie anderen Parteien über Creality-Dienstleistungen zur Verfügung stellen und die Daten, die Sie bei der Nutzung von Creality-Dienstleistungen speichern; und\n(3) Daten, die wir von Ihnen erhalten. Wenn Sie Creality-Dienstleistungen nutzen, erheben, kondensieren und speichern wir die damit verbundenen Daten, z.B: Protokollinformationen, Geräteinformationen usw.\n(II) COOKIES und Log-Dateien\nWir oder Dritte, die unsere Partner sind, können Ihre Daten über COOKIES erhalten und verwenden und sie als Protokolldaten speichern. Wir verwenden COOKIES, um unseren Nutzern ein benutzerfreundliches und personalisiertes Netzwerk zur Verfügung zu stellen. COOKIES sind kleine Datenmengen, die von einem Netzwerkserver an Ihren Browser gesendet und auf der Festplatte Ihres Computers gespeichert werden. Wir setzen COOKIES ein, um unseren Nutzern einen Mehrwert zu bieten.\nCOOKIES ermöglichen es uns, Ihnen einen besseren und schnelleren Service zu bieten und Ihre Erfahrungen mit den Creality-Dienstleistungen zu personalisieren. Sie sollten jedoch in der Lage sein zu kontrollieren, ob und wie COOKIES von Ihrem Browser akzeptiert werden. Weitere Informationen hierzu finden Sie in den Dateien, die mit Ihrem Browser geliefert werden.\n(III) Wir können Ihre Daten über COOKIE entsprechend erheben, verwenden und speichern\n(1) Wir speichern, wer Sie sind. Zum Beispiel: COOKIES helfen uns, Sie als unseren registrierten Benutzer zu identifizieren oder die Informationen zu speichern, die Sie uns über Ihre Präferenzen oder andere Aspekte geben;\n(2) Ihre Nutzung unserer Dienste zu analysieren. Wir können COOKIES verwenden, um herauszufinden, welche Aktivitäten Sie mit den Creality-Dienstleistungen durchführen oder welche Dienste am beliebtesten sind;\n(3) Unsere Werbung zu optimieren. COOKIES helfen uns dabei, Ihnen auf der Grundlage der von Ihnen eingegebenen Informationen Werbung anzubieten, die auf Sie zugeschnitten ist, anstatt allgemeine Werbekampagnen durchzuführen.\nDie Creality-Dienstleistungen können COOKIES enthalten, die von Werbetreibenden und anderen Partnern gesetzt werden. Solche COOKIES können nicht-personenbezogene Daten über Sie erheben, um zu analysieren, wie Benutzer diese Dienste nutzen, um Ihnen Werbung zu senden, die für Sie von Interesse sein könnte, oder um die Wirksamkeit von Werbediensten zu bewerten. Die Erhebung und Nutzung solcher Daten durch Dritte mittels COOKIES unterliegt nicht dieser Datenschutzerklärung, sondern deren eigenen Datenschutzerklärungen; wir übernehmen keine Verantwortung für die COOKIES Dritter.\nSie können COOKIES ablehnen oder verwalten, indem Sie Ihren Browser oder den Benutzerauswahlmechanismus verwenden. Bitte beachten Sie jedoch, dass wir Ihnen möglicherweise nicht den bestmöglichen Service bieten können, wenn Sie COOKIES deaktivieren, und dass einige Dienste möglicherweise nicht wie gewohnt genutzt werden können.\n(IV) Wir erheben und verwenden Ihre Daten für folgende Zwecke:\n1. Nachrichten an Sie zu senden\nIhnen Waren oder Dienstleistungen anzuzeigen und zuzusenden. Mit Ihrer Zustimmung können wir die Daten Ihres Geräts verwenden, um Ihnen per E-Mail, SMS oder auf andere Weise Marketinginformationen zu senden, um Ihnen die folgenden Waren und Dienstleistungen von uns oder Dritten anzubieten oder zu bewerben:\nUnsere Waren und Dienstleistungen umfassen unter anderem Online-Mediendienste, soziale Netzwerkdienste, Internetsuchdienste, Standort- und Kartendienste, Anwendungssoftware und -dienste, Datenverwaltungssoftware und -dienste, Punkte- und Prämienprogramme, Geräteprodukte, 3D-Druck-Peripherieprodukte und andere Waren und Dienstleistungen, von denen wir glauben, dass sie für Sie von Interesse sein könnten.\n2. Verbesserung unserer Dienste\nWir können Daten, die wir über bestimmte Creality-Dienstleistungen erhoben haben, auf andere von uns angebotene Dienste anwenden. Zum Beispiel können die Daten, die wir erheben, wenn Sie bestimmte Kreativitätsdienste nutzen, in anderen Kreativitätsdienste verwendet werden, um Ihnen spezielle Inhalte oder Informationen anzuzeigen, die sich auf Sie beziehen, anstatt Sie allgemein zu bewerben; wir können Sie in Umfragen zu Kreativitätsdienste einbeziehen, die uns helfen, bestehende Dienste zu verbessern oder neue Dienste zu entwickeln; und in der Zwischenzeit können wir Ihre Daten für Software-Updates verwenden.\nIhnen ist bekannt und Sie erklären sich damit einverstanden, dass wir nach der Erhebung Ihrer Daten die Daten mit technischen Mitteln unkenntlich machen können und dass die unkenntlich gemachten Daten keine Rückschlüsse auf Ihre Identität zulassen. In diesem Fall sind wir berechtigt, die de-identifizierten Daten zu verwenden, um die Benutzerdatenbank zu analysieren und kommerziell zu nutzen. Sollten Ihre Daten für andere Zwecke verwendet werden, die nicht in dieser Datenschutzerklärung aufgeführt sind, werden wir Sie vorher um Ihre Zustimmung bitten.\n3. Ausgenommen hiervon ist die Einholung einer Einwilligung. Gemäß den geltenden Gesetzen und Vorschriften ist Ihre Zustimmung zur Erhebung Ihrer Daten unter folgenden Umständen nicht erforderlich:\n(1) Es geht um die nationale Sicherheit und die Sicherheit der Landesverteidigung;\n(2) Sie betrifft die öffentliche Sicherheit, die öffentliche Gesundheit und wichtige öffentliche Interessen;\n(3) Sie steht im Zusammenhang mit strafrechtlichen Ermittlungen, Strafverfolgungsmaßnahmen, Gerichtsverfahren oder der Vollstreckung von Urteilen;\n(4) Sie dient dem Schutz wichtiger legitimer Rechte und Interessen des betroffenen Probanden oder anderer Personen, wie z. B. Leben und Eigentum, und es ist schwierig, Ihre persönliche Einwilligung einzuholen;\n(5) Die erhobenen Daten werden von Ihnen selbst an die Öffentlichkeit weitergegeben;\n(6) Die Daten werden aus Informationen erhoben, die der Öffentlichkeit rechtmäßig zugänglich gemacht wurden, z. B. aus rechtmäßigen Nachrichtenberichten, der Offenlegung von Regierungsinformationen und anderen Kanälen;\n(7) Sie sind erforderlich, um die von Ihnen angeforderten Verträge zu unterzeichnen;\n(8) Zur Aufrechterhaltung eines sicheren und stabilen Betriebs der Creality-Dienstleistungen erforderlich sind, z. B. um Fehler in Produkten oder Diensten zu erkennen und zu beheben;\n(9) Sie sind für die rechtmäßige Berichterstattung über Neuigkeiten erforderlich;\n(10) Für akademische Forschungseinrichtungen erforderlich sind, um statistische oder akademische Forschung im öffentlichen Interesse durchzuführen und die in den Ergebnissen enthaltenen Daten zu anonymisieren, wenn sie der Öffentlichkeit akademische Forschung oder beschreibende Ergebnisse zur Verfügung stellen; und\n(11) Andere Umstände, die durch Gesetze und Vorschriften festgelegt sind.\nIII. WIE WIR DATEN SPEICHERN, AUFBEWAHREN UND SCHÜTZEN\nWir speichern Ihre Daten nur so lange, wie es für die in dieser Datenschutzerklärung beschriebenen Zwecke erforderlich ist, und so lange, wie es von Gesetzen und Vorschriften verlangt wird.\n1. Es gibt klare Bestimmungen in Gesetzen und Vorschriften;\n2. Ihre Erlaubnis und Zustimmung vorliegt; und\n3. Creality Cloud muss Ihre personenbezogenen Daten ins Ausland übermitteln, wenn die von Ihnen genutzten Produkte und Dienstleistungen grenzüberschreitende Aktivitäten beinhalten. In diesen Fällen werden wir sicherstellen, dass Ihre personenbezogenen Daten in Übereinstimmung mit dieser Datenschutzerklärung und den Anforderungen der nationalen Gesetze und Vorschriften angemessen geschützt werden.\nWir werden die folgenden Maßnahmen ergreifen, um Ihre Daten zu schützen:\n(I) Technische Sicherheitsmaßnahmen\nWir werden diese Sicherheitsmaßnahmen in Übereinstimmung mit den Industriestandards ergreifen, einschließlich der Schaffung angemessener institutioneller Standards und Sicherheitstechnologien, um den unbefugten Zugriff auf Ihre Daten, deren Verwendung und Änderung sowie deren Beschädigung oder Verlust zu verhindern. Die Netzwerkdienste verwenden verschiedene Verschlüsselungstechnologien. Beispielsweise verwenden wir bei bestimmten Diensten Verschlüsselungstechnologien (z. B. SSL), um Ihre Daten zu schützen, zu verschlüsseln und zu speichern, sowie Isolierungstechnologien, um Ihre Daten zu isolieren.\nWir verwenden verschiedene Technologien zur Desensibilisierung von Daten, um die Sicherheit der verwendeten Daten zu erhöhen, z.B. bei der Anzeige von Informationen und der Berechnung von Informationszusammenhängen. Zum Schutz der Daten und zur Verhinderung einer unrechtmäßigen Nutzung der Daten setzen wir strenge Datenzugriffskontrollen und Technologien zur mehrfachen Identitätsauthentifizierung ein.\n(II) Weitere Sicherheitsmaßnahmen, die wir zum Schutz der Daten ergreifen, umfassen die Verwaltung und Standardisierung der Speicherung und Nutzung von Daten durch die Einrichtung eines Systems zur Klassifizierung und Einstufung von Daten, Standards für das Datensicherheitsmanagement und Standards für die Entwicklung der Datensicherheit.\nWir führen eine umfassende Kontrolle der Datensicherheit durch, indem wir Vertraulichkeitsvereinbarungen für den Umgang mit Daten treffen und einen Überwachungs- und Prüfmechanismus einrichten. Wir fördern das Sicherheitsbewusstsein. Darüber hinaus führen wir Schulungen zur Datensicherheit und zum Datenschutz durch, um das Bewusstsein der Mitarbeiterinnen und Mitarbeiter für die Bedeutung des Datenschutzes zu schärfen.\n(III) Wir gewähren nur den Mitarbeitern von Creality 3D, die diese Daten kennen müssen, Zugang zu Ihren Daten und richten diesbezüglich strenge Zugangskontroll- und Überwachungsmechanismen ein. Gleichzeitig verlangen wir von allen Mitarbeitern, die Zugang zu Ihren Daten haben könnten, die Einhaltung entsprechender Vertraulichkeitsverpflichtungen. Die Nichteinhaltung dieser Verpflichtungen kann zu rechtlicher Haftung oder zur Beendigung der Geschäftsbeziehung mit Creality 3D führen.\n(IV) Wir werden alle angemessenen und durchführbaren Schritte unternehmen, um sicherzustellen, dass keine irrelevanten Daten erhoben werden.\n(V) Das Internet ist keine absolut sichere Umgebung und es ist unmöglich zu wissen, ob die Kommunikation mit anderen Nutzern über E-Mail, Instant Messaging, Social Networking Software oder andere Service-Software vollständig verschlüsselt ist. Wir empfehlen Ihnen daher, komplexe Passwörter zu verwenden, wenn Sie solche Tools verwenden, und alle Anstrengungen zu unternehmen, um die Sicherheit Ihrer Daten zu gewährleisten.\n(VI) Da die Internetumgebung nicht zu 100 % sicher ist, bemühen wir uns, die Sicherheit der von Ihnen an uns übermittelten Daten zu gewährleisten oder zu garantieren. Im Falle einer Verletzung unserer physischen, technischen oder verwaltungsmäßigen Einrichtungen, die zu einem unbefugten Zugriff auf Ihre Daten oder deren unbefugter Offenlegung, Manipulation oder Vernichtung führt und darüber hinaus Ihre berechtigten Rechte und Interessen verletzt, übernehmen wir die entsprechenden gesetzlichen Verpflichtungen.\n(VII) Behandlung von Sicherheitsvorfällen\n(1) Im Rahmen der Kommunikation mit Dritten oder des Erwerbs von Waren und Dienstleistungen über die Creality-Dienstleistungen ist es unvermeidlich, dass Sie Daten über sich, wie z. B. Kontaktdaten oder Postanschrift, an Gegenparteien oder potentielle Gegenparteien weitergeben. Bitte achten Sie darauf, dass Ihre Daten angemessen geschützt sind und geben Sie diese nur dann an Dritte weiter, wenn dies erforderlich ist.\n(2) Als Reaktion auf die potenziellen Risiken von Datenlecks, -schäden und -verlusten haben wir mehrere Systeme entwickelt, um die Klassifizierungs- und Einstufungsstandards für Sicherheitsvorfälle und Schwachstellen sowie die entsprechenden Managementprozesse zu klären. Darüber hinaus haben wir ein spezielles Notfallteam für Sicherheitsvorfälle eingerichtet, Sicherheitspläne für verschiedene Sicherheitsvorfälle gemäß den Anforderungen der Standards für die Behandlung von Sicherheitsvorfällen erstellt, Verluste gestoppt, analysiert, lokalisiert und Abhilfemaßnahmen entwickelt sowie mit den zuständigen Abteilungen zusammengearbeitet, um diese zu verfolgen und zu bekämpfen. Im Falle eines unglücklichen Ereignisses im Bereich der Datensicherheit informieren wir Sie rechtzeitig, wie von den Gesetzen und Vorschriften gefordert, über die grundlegende Situation und die möglichen Auswirkungen des Sicherheitsvorfalles, über die von uns ergriffenen oder zu ergreifenden Abhilfemaßnahmen, über die Vorschläge, die wir Ihnen unterbreiten, damit Sie selbst die Risiken vermeiden oder verringern können, sowie über die Abhilfemaßnahmen, die Sie ergreifen können. Wir werden Sie unverzüglich per E-Mail, Brief, Telefon, Push-Benachrichtigung usw. über den Vorfall informieren. Wenn es schwierig ist, einzelne Personen zu informieren, werden wir eine angemessene und effektive Ankündigung machen. In der Zwischenzeit werden wir, wie von den Aufsichtsbehörden gefordert, proaktiv über den Umgang mit Datensicherheitsvorfällen berichten.\n(3) Cloud-Speicherdienste: Um Ihnen Cloud-Speicherdienste anbieten zu können (die Bilder, Audio- und Videoinhalte, die Sie in die Creality Cloud hochladen, werden in der Cloud und den damit verbundenen Szenarien gespeichert), können Drittanbieter von Diensten Ihre Gerätedaten, netzwerkbezogenen Daten und Betreiberdaten erheben.\nWenn Sie Fragen zu den oben genannten Punkten haben, können Sie jederzeit www.crealitycloud.com/ besuchen, um zu erfahren, wie Ihre Daten von uns oder unseren kooperierenden Dritten erhoben und verarbeitet werden.\nIV. IHRE RECHTE IN BEZUG AUF IHRE PERSONENBEZOGENEN DATEN\nGemäß den Gesetzen und Vorschriften Ihres Wohnsitzlandes oder Ihrer Region haben Sie das Recht, Zugang zu Ihren personenbezogenen Daten zu verlangen, diese zu korrigieren oder zu löschen (im Folgenden als „Anfrage“ bezeichnet). Diese Rechte unterliegen jedoch bestimmten Ausschlüssen und Ausnahmen nach geltendem Recht. Wenn Sie Fragen haben, können Sie sich per E-Mail an uns wenden: cs@creality.com.\nWenn Sie mit dieser Datenschutzerklärung nicht einverstanden sind, können Sie die Netzwerkfunktionen nicht nutzen.\nWenn Sie Fragen oder Anregungen zu dieser Datenschutzerklärung haben, wenden Sie sich bitte an cs@creality.com, die offizielle Mailbox.\n\n",\
    "Gracias por elegir los productos de Creality.\n\nShenzhen Creality 3D Technology Co., Ltd. (\"Creality 3D\", \"nosotros\", \"nosotros\" o \"nuestro\") se compromete a proteger la privacidad de estos usuarios (en adelante, \"usuario\" o usted\") que usan los productos y servicios de Creality (en adelante, los \"servicios de Creality\"). Recolectaremos y usaremos su información cuando use los servicios de Creality. Tenga en cuenta que revisaremos nuestras políticas de forma ocasional, por lo tanto, tales medidas cambiarán de forma acorde. Le pedimos que visite esta página de forma regular para estar al tanto de la última versión de nuestra Política de Privacidad. Luego de leer esta Política de Privacidad, puede contactarnos en cs@creality.com para contarnos sus dudas sobre ella o cualquier otro asunto relacionado.\n\nI. ¿QUÉ INFORMACIÓN RECOLECTAMOS?\n(I) Información no relacionada a la identidad personal:\nCuando use los servicios de Creality, recolectaremos y resumiremos cierta información, como el origen del usuario y el orden de acceso, incluyendo el registro del origen de cada usuario que disfruta de los servicios de Creality.\n(II) Información sobre la identidad personal:\nCuando use los servicios de Creality, recolectaremos y resumiremos o le pediremos su número de teléfono personal, y la información de identificación de la red (incluyendo el número de la cuenta del sistema, la dirección IP, la dirección de correo, y las frases secretas, contraseñas, y las respuestas de protección de la contraseña, etc.)\n(1) Los registros personales de navegación en internet y la información de registro (incluyendo el historial de navegación, los registros de uso del software, los registros de clics hechos, los registros de operación, etc.);\n(2) La información del dispositivo (incluyendo el modelo del dispositivo, la dirección MAC, el tipo de sistema operativo, y las configuraciones del dispositivo), la lista de softwares, y el código único de identificación del dispositivo (como el IMEI/android ID/IDFA/OPENUDID/GUID, la información IMSI de la tarjeta SIM, y la información restante que describa el estado básico de los dispositivos personales usados comúnmente).\nRecolectamos su información principalmente para facilitarle a usted y a otros el uso y disfrute de los servicios de Creality. El fin de Creality Cloud es ofrecerle a todos sus usuarios una experiencia de navegación en internet segura, interesante, e instructiva; la recolección de esta información nos ayudará a lograr este fin.\nII. CÓMO RECOLECTAMOS Y USAMOS LA INFORMACIÓN\n(I) Recolectamos y obtenemos su información mediante los siguientes canales:\n(1) La información que nos provee cuando usa o se registra para usar los servicios de Creality;\n(2) La información compartida que usted provee a otras partes mediante los servicios de Creality, y la información que usted almacena cuando usa los servicios de Creality; y\n(3) La información que nosotros obtenemos sobre usted. Cuando use los servicios de Creality, recolectaremos, resumiremos y registraremos la información relacionada, por ejemplo, la información de registro, la información del dispositivo, etc.\n(II) COOKIES y archivos de registro\nNosotros, o nuestros socios terceros, obtendremos y usaremos, su información mediante las COOKIES, y la guardaremos como información de registro. Mediante el uso de las COOKIES, ofrecemos a los usuarios una experiencia de red fácil de usar y personalizada. Las COOKIES representan una cantidad pequeña de datos que se envían desde un servidor en la red a s buscador, y que se almacenan en el disco duro de su computadora. Usamos las COOKIES para el beneficio de nuestros usuarios.\nLas COOKIES nos permiten ofrecerle un servicio mejor y más rápido, y nos permite personalizar su experiencia con los servicios de Creality. Sin embargo, usted podrá controlar la manera en la que su buscador acepta las COOKIES. Consulte los archivos de su buscador para obtener más información sobre esto.\n(III) Recolectaremos y usaremos su información mediante las COOKIES, y la guardaremos.\n(1) Para recordar quién es usted. Por ejemplo: Las COOKIES nos ayudan a identificarlo como un usuario registro, y a guardar la información que nos provee sobre sus preferencias u otros aspectos;\n(2) Para analizar su uso de nuestros servicios. Usaremos las COOKIES para ver que hace con los servicios de Creality, o ver cuáles son los servicios más populares.\n(3) Para optimizar las publicidades. Las COOKIES nos ayudan a ofrecerle las publicidades relacionadas a usted según su información, evitando las campañas de publicidad generales.\nLos servicios de Creality pueden contener COOKIES colocadas por los anunciantes u otros socios. Tales COOKIES pueden recolectar la información personal no identificable sobre usted, para analizar el modo en el que los usuarios usan tales servicios, mostrarle publicidad que le podría interesar, o evaluar la efectividad de los servicios de publicidad. La recolección y el uso de tal información por medio de las COOKIES por parte de tal tercero, no están sujetos a esta Política de Privacidad, sino a sus declaraciones de protección de información personal; y nosotros no asumimos ninguna responsabilidad por las COOKIES de los terceros.\nUsted puede rechazar o gestionar las COOKIES en su buscador o por medio del mecanismo de selección. Sin embargo, debe tener en cuenta que si desactiva las COOKIES, no podremos ofrecerla la mejor experiencia del servicio. Incluso, algunos servicios podrían no funcionar normalmente.\n(IV) Recolectaremos y usaremos su información para los siguientes fines:\n1. Enviarle mensajes de notificación\nMostrarle y notificarle sobre bienes o servicios. Luego de recibir su consentimiento, dependeremos de la información de su dispositivo para enviarle la información del marketing por correo, SMS, u otros medios, para ofrecerle o promocionar nuestros bienes y servicios, o los de terceros:\nNuestros bienes y servicios incluyen, entre otros, los servicios de multimedia en línea, redes sociales, búsqueda en internet, ubicación y mapa, software de aplicaciones y sus servicios, software de gestión de datos y sus servicios, puntos y programas de recompensas, productos del dispositivo, productos periféricos de impresión 3D, y otros bienes y servicios que creamos relacionados a usted.\n2. Mejorar nuestros servicios\nAplicaremos la información reunida en ciertos servicios de Creality a otros servicios nuestros. Por ejemplo, su información recolectada cuando usa ciertos servicios de Creativity puede usarse in otros servicios de Creativity, para ofrecerle ciertos contenidos específicos, o mostrarle la información relacionada a usted y no la información general; lo invitaremos a que participe en encuestas sobre los servicios de Creativity para que nos ayude a mejorar nuestros servicios existentes o a diseños unos nuevos; y a su vez, usaremos su información para las actualizaciones del software. \nUsted acepta y entiende que después de que su información es recolectada, esta será anonimizada por medios técnicos. La información anonimizada no será útil para llegar a su identidad, por lo que tendremos el derecho de usarla para analizar la base de datos de los usuarios y hacer uso comercial con ella. Le pediremos su consentimiento por adelantado en caso de que se la use para otros fines no especificados en esta Política de Privacidad.\n3. Con la excepción de la obtención de la autorización. Conforme a las leyes y regulaciones relevantes, no necesitamos su autorización para recolectar su información en las circunstancias siguientes:\n(1) Cuando se requiera para la seguridad y la defensa nacionales;\n(2) Cuando se requiera para la seguridad pública, la salud pública, y los intereses públicos de gran importancia;\n(3) Cuando se requiera para la investigación criminal, el procesamiento, el enjuiciamiento, y la ejecución de la sentencia;\n(4) Cuando se requiere para proteger los derechos legítimos e intereses del titular de la información, o de otros individuos, como su vida y propiedad, pero resulta difícil obtener su consentimiento de forma personal;\n(5) Cuando su información recolectada ya haya sida hecha pública por su propia cuenta;\n(6) Cuando la información haya sido recolectada de un lugar público y de forma legal, como de una noticia legítima, de la divulgación hecha por el gobierno, y de otros canales;\n(7) Cuando sea necesaria para firmar contratos, según lo solicitado por usted;\n(8) Cuando sea necesaria para mantener la seguridad y la estabilidad de las operaciones de los servicios de Creality, como la detección y el tratamiento de las fallas del producto o el servicio;\n(9) Cuando sea necesario para el informe legítimo de las noticias;\n(10) Cuando sea necesario para que las instituciones de investigación académica realicen las investigaciones estadísticas o académicas por motivos de interés público, y para anonimizar la información contenida en los resultados al momento de ofrecer la investigación académica o los resultados descriptivos al público; y\n(11) Cuando sea necesario para otras circunstancias estipuladas por las leyes y las regulaciones.\nIII. CÓMO RETENEMOS, GUARDAMOS Y PROTEGEMOS LA INFORMACIÓN\nRetendremos su información por el tiempo que sea necesario para los fines descriptos en esta Política de Privacidad, y por el tiempo que lo requieran las leyes y las regulaciones.\n1. Las leyes y las regulaciones contienen estipulaciones claras;\n2. Nosotros obtenemos su autorización y consentimiento; y\n3. Creality Cloud necesita proveer su información personal al exterior cuando los productos y servicios que usa se ven involucrados en actos transfronterizos. En tales casos, nos aseguraremos de que su información personal sea protegida de forma adecuada, respetando esta Política y los requisitos de las leyes y regulaciones nacionales.\nTomaremos las siguientes medidas para proteger su información:\n(I) Medidas técnicas para la seguridad de los datos\nTomaremos estas medidas de seguridad, en línea con los estándares de la industria, y estableceremos las normas institucionales razonables y las tecnologías de seguridad, para prevenir el acceso, uso y modificación no autorizados de su información, con el fin de prevenir el daño o pérdida de sus datos. Los servicios de red adoptan una gran variedad de tecnologías de encriptación; por ejemplo, en ciertos servicios, adoptaremos las tecnologías de encriptación (por ejemplo, SSL) para proteger su información, encriptarla y guardarla, y aplicaremos las tecnologías de aislamiento para aislarla.\nAdoptaremos una gran variedad de tecnologías de anonimización de datos, para mejorar la seguridad de la información en uso, como la muestra de la información y los cálculos para su asociación. Adoptamos un control de acceso estrictos a los datos y múltiples tecnologías de autentificación de identidad para proteger la información y evitar su uso ilegal.\n(II) Las otras medidas de seguridad que adoptamos para proteger su información incluyen la gestión y la estandarización del almacenamiento y uso de la información, mediante el establecimiento de la clasificación de datos y el sistema de puntuación, las normas de gestión de seguridad de datos, y las normas de desarrollo de seguridad de datos.\nLlevamos a cabo un control de seguridad amplio de los datos, mediante el acuerdo de confidencialidad de contacto con la información, y el mecanismo de monitoreo y auditoría. Fortalecemos la conciencia sobre la seguridad. Además, organizamos cursos de protección de seguridad y privacidad para concientizar a nuestros empleados sobre la importancia de proteger la información.\n(III) Solo permitimos que a su información accedan estos empleados de Creality 3D, ya que necesitan conocerla, y establecemos un control estricto de acceso y mecanismos de monitoreo en ese sentido. A su vez, le solicitamos a todo el personal que tiene acceso a su información que cumplan con las obligaciones de confidencialidad correspondientes. El no cumplimiento de estas obligaciones puede dar lugar a una obligación legal o a la suspensión de la colaboración con Creality 3D.\n(IV) Tomaremos todas las medidas razonables y posibles para asegurarnos de no recolectar ninguna información irrelevante.\n(V) El internet no ofrece un ambiente completamente seguro, por lo que resulta imposible determinar que los métodos de comunicación con otros usuarios por correo, mensajería instantánea, software de redes sociales, u otros softwares de servicio, estén encriptados por completo; por esta razón, le recomendamos que establezca contraseñas complejas cuando use tales herramientas, y que se esfuerce en garantizar la seguridad de la información.\n(VI) Ya que el internet no es un ambiente 100 %, nos comprometemos a garantizar la seguridad de toda la información que nos envíe. En caso de que nuestras instalaciones físicas, técnicas o de protección de gestión resulten dañadas, y se cause el acceso no autorizado a la información, o su divulgación pública, manipulación o destrucción, causando daños a sus derechos e intereses legítimos, nosotros asumiremos todas las obligaciones legales correspondientes.\n(VII) Manejo de los accidentes de seguridad\n(1) Es inevitable que, durante la comunicación con terceros, o la compra de bienes y servicios por medio de los servicios de Creality, usted revele su información personal, como la información de contacto o la dirección postal, a otras contrapartes, o contrapartes potenciales. Le pedimos que proteja su información de forma apropiada y que solo la provea a otros cuando sea necesario.\n(2) Hemos desarrollado múltiples sistemas para aclarar los estándares de clasificación y puntuación para los incidentes de seguridad y las vulnerabilidades, como también los procesos de manejo correspondientes, como respuesta a los riesgos potenciales de filtración de su información, daños o pérdida. Además, hemos conformado un equipo especial de respuesta a emergencias para los accidentes de seguridad; hemos iniciado unos planes de seguridad contra los diferentes incidentes de seguridad, según lo requerido por las normas de manejo de los incidentes de seguridad; hemos detenido las pérdidas, analizado, ubicado y desarrollado las medidas de reparación, y colaborado con los departamentos relevantes para el rastreo y el combate. En el caso que sucediera algún accidente de seguridad con la información, le informaremos sobre la situación a tiempo, según lo requerido por las leyes y las regulaciones, lo que incluye la situación general y los posibles impactos del incidente de seguridad, las medidas que hemos tomado o que tomaremos, nuestras sugerencias para que usted prevenga o reduzca los riesgos de forma independiente, y las medidas de reparación para con usted. Le informaremos a la brevedad sobre la situación del incidente, por correo, correspondencia, teléfono, mensaje de notificación, etc.; y Cuando resulte difícil establecer la comunicación de manera individual, haremos un anuncio de forma razonable y efectiva. A su vez, informaremos de manera proactiva sobre el manejo de los incidentes a la seguridad de la información, según lo requerido por las autoridades regulatorias.\n(3) Servicios de almacenamiento en la nube: Con el fin de ofrecerle los servicios de almacenamiento en la nube (las imágenes, el audio y los videos que suba a Creality Cloud serán almacenados en la nube para las situaciones relacionadas), los terceros proveedores de servicios pueden recolectar la información de su dispositivo, la información de la red, y la información del operador.\nSi tiene alguna pregunta sobre esto, visite www.crealitycloud.com en cualquier momento para acceder a la información recolectada y procesada por nosotros o los terceros que cooperan con nosotros.\nIV. SUS DERECHOS A SU INFORMACIÓN PERSONAL\nDe acuerdo con las leyes y regulaciones de su país o región de residencia, usted tiene el derecho a acceder, corregir, y borrar la información personal que tengamos sobre usted (en adelante, la \"solicitud\"). Pero tales derechos estarán sujetos a ciertas exclusiones y excepciones, en virtud de las leyes aplicables. Puede hacernos sus preguntas en cs@creality.com.\nSi usted no está de acuerdo con esta Política de Privacidad, el dispositivo no ofrecerá la funcionalidad de red.\nSi tiene alguna pregunta o sugerencia sobre esta Política de Privacidad, contáctenos por medio de nuestro correo oficial en cs@creality.com.\n\n",\
    "Nous vous remercions d'avoir opté pour les produits Creality.\n\nShenzhen Creality 3D Technology Co., Ltd (« Creality 3D », « nous », « notre » ou « nos ») tient à protéger la vie privée des utilisateurs (ci-après dénommés « utilisateurs » ou « vous ») qui utilisent les produits et services de Creality (ci-après dénommés « services de Creality »). Nous sommes susceptibles de collecter et d'utiliser les informations vous concernant lorsque vous utilisez ces services de Creality. Il est à noter que nous révisons nos politiques de temps à autre et que les mesures pertinentes peuvent donc être modifiées en conséquence. Nous vous invitons à consulter régulièrement cette page afin de vous assurer que vous êtes toujours au courant de la dernière version de notre politique de confidentialité. Après avoir pris connaissance de cette politique de confidentialité, n'hésitez pas à nous contacter à l'adresse cs@creality.com si vous avez des doutes sur cette politique de confidentialité ou sur les questions qui s'y rapportent.\n\nI. QUE COLLECTONS-NOUS COMME INFORMATIONS ?\n(I) Informations non liées à l'identité personnelle :\nSi vous utilisez les services de Creality, il est possible que nous recueillions et résumions des informations telles que l'origine de l'utilisateur et l'ordre d'accès, y compris l'enregistrement de l'origine de chaque utilisateur utilisant les services de Creality.\n(II) Informations relatives à l'identité personnelle :\nSi vous utilisez les services de Creality, il se peut que nous collections et résumions ou demandions votre numéro de téléphone personnel, ainsi que des informations sur l'identité du réseau (y compris le numéro de compte du système, l'adresse IP, l'adresse électronique et les phrases de passe correspondantes, les mots de passe et les réponses à la protection par mot de passe, entre autres).\n(1) Les données personnelles de navigation sur Internet et les informations de journal (y compris l'historique de navigation sur les sites web, les données sur l'utilisation des logiciels, les données sur les clics, les données sur les opérations, et autres ;)\n(2) les informations relatives à l'appareil (y compris le modèle de l'appareil, l'adresse MAC de l'appareil, le type de système d'exploitation et les paramètres de l'appareil), et le code d'identification unique de l'appareil de la liste des logiciels (tel que IMEI/Android ID/IDFA/OPENUDID/GUID, les informations IMSI de la carte SIM et d'autres informations décrivant l'état de base des appareils personnels couramment utilisés).\nCes informations sont collectées principalement pour faciliter l'utilisation des services de Creality et la rendre plus satisfaisante pour vous et les autres utilisateurs. L'objectif de Creality Cloud étant de fournir à tous les utilisateurs d'Internet des expériences de navigation sûres, intéressantes et instructives, ces informations nous aideront à atteindre cet objectif.\nII. COMMENT RECUEILLONS-NOUS ET UTILISONS-NOUS LES INFORMATIONS ?\n(I) Nous collecterons et obtiendrons vos informations par le biais des canaux suivants, par exemple :\n(1) Les informations que vous nous fournissez lorsque vous vous inscrivez ou utilisez les services de Creality ;\n(2) Les informations partagées que vous fournissez à d'autres parties par le biais des services de Creality et les informations que vous stockez lorsque vous utilisez les services de Creality ; et\n(3) les informations que nous obtenons à votre sujet. En utilisant les services de Creality, nous collectons, résumons et enregistrons les informations concernées, par exemple : les informations du journal, les informations de l'appareil et ainsi de suite.\n(II) COOKIES et fichiers journaux\nIl se peut que nous ou nos partenaires tiers obtenions et utilisions vos informations par le biais de COOKIES et les stockions en tant qu'informations de journal. Les COOKIES nous permettent d'offrir aux utilisateurs une expérience conviviale et personnalisée du réseau. Les COOKIES sont de petites séries de données envoyées par un serveur de réseau à votre navigateur et stockées sur le disque dur de votre ordinateur. Nous nous servons des COOKIES pour que les utilisateurs puissent en bénéficier.\nLes COOKIES nous permettent de vous servir mieux et plus rapidement, et de personnaliser votre expérience des services de Creality. Vous devriez toutefois avoir la possibilité de contrôler si et comment les COOKIES sont acceptés par votre navigateur. Pour plus d'informations à ce sujet, veuillez vous référer aux fichiers fournis avec votre navigateur.\n(III) Nous sommes susceptibles de collecter et d'utiliser vos informations par le biais de COOKIE et de les stocker en conséquence\n(1) Se souvenir de votre identité. À titre d'exemple : Les COOKIES nous permettent de vous identifier comme utilisateur enregistré ou de sauvegarder les informations que vous nous fournissez sur vos préférences ou d'autres aspects ;\n(2) Analyser votre façon d'utiliser nos services. Les COOKIES peuvent être utilisés pour déterminer les activités que vous effectuez avec les services de Creality, ou quels services sont les plus populaires ;\n(3) Optimiser les publicités. Grâce aux COOKIES, nous pouvons vous proposer des publicités qui vous concernent en fonction de vos informations, plutôt que de mener des campagnes publicitaires générales.\nLes services de Creality contiennent parfois des COOKIES placés par des annonceurs et d'autres partenaires. De tels COOKIES permettent de collecter des informations non personnellement identifiables vous concernant dans le but d'analyser la manière dont les utilisateurs utilisent ces services, de vous envoyer des publicités susceptibles de vous intéresser ou d'évaluer l'efficacité des services de publicité. Les informations collectées et utilisées par ces tiers via les COOKIES ne sont pas soumises à la présente politique de confidentialité, mais à leurs propres déclarations de protection des informations personnelles ; nous n'assumons pas la responsabilité des COOKIES de ces tiers.\nIl vous est possible de refuser ou de gérer les COOKIES par l'intermédiaire d'un navigateur ou du mécanisme de sélection de l'utilisateur. Il convient toutefois de noter que si vous désactivez les COOKIES, il se peut que nous ne soyons pas en mesure de vous offrir la meilleure expérience de service, voire que certains services ne puissent pas être utilisés normalement.\n(IV) Les informations vous concernant seront collectées et utilisées aux fins suivantes :\n1. Vous envoyer des messages\nVous présenter et vous proposer des biens ou des services. Si vous y consentez, nous pouvons utiliser les informations relatives à votre appareil pour vous envoyer des informations commerciales par courrier électronique, SMS ou autre, afin de vous fournir ou de promouvoir les biens et services suivants de notre part ou de la part de tiers :\nNotre offre de biens et de services comprend, sans s'y limiter, des services de médias en ligne, des services de réseaux sociaux, des services de recherche sur Internet, des services de localisation et de cartographie, des logiciels et des services d'application, des logiciels et des services de gestion de données, des programmes de points et de récompenses, des produits d'appareils, des produits périphériques d'impression 3D, ainsi que d'autres biens et services que nous pensons pouvoir vous concerner.\n2. Amélioration de nos services\nIl se peut que nous appliquions les informations recueillies par le biais de certains services de Creality à d'autres de nos services. Ainsi, les informations recueillies dans le cadre de certains services offerts par Creativity peuvent être utilisées dans d'autres services de Creativity pour vous fournir des contenus spécifiques ou afficher des informations vous concernant plutôt que de les pousser de manière générale ; nous pouvons vous faire participer à des enquêtes liées aux services de Creativity pour nous aider à améliorer les services existants ou à en concevoir de nouveaux ; entre-temps, nous pouvons utiliser vos informations pour des mises à jour logicielles.\nVous comprenez et acceptez le fait qu'après la collecte de vos informations, nous sommes susceptibles de dépersonnaliser les données par des moyens techniques, et que les informations dépersonnalisées n'aideront pas à identifier votre identité, auquel cas nous sommes autorisés à utiliser les informations dépersonnalisées pour analyser la base de données des utilisateurs et faire un usage commercial de cette dernière. Nous vous demanderons votre consentement au préalable si vos informations sont utilisées à d'autres fins non spécifiées dans la présente politique de confidentialité.\n3. Sauf pour l'obtention d'une autorisation. En application des lois et règlements pertinents, votre autorisation n'est pas requise pour la collecte de vos informations dans les circonstances suivantes :\n(1) elles relèvent de la sécurité nationale et de la sécurité de la défense nationale\n(2) elles relèvent de la sécurité publique, de la santé publique et d'intérêts publics majeurs\n(3) elles relèvent de l'enquête criminelle, des poursuites judiciaires, du procès et de l'exécution du jugement\n(4) elles ont pour but de sauvegarder les droits et intérêts légitimes importants de la personne concernée ou d'autres personnes, tels que la vie et la propriété, mais il est difficile d'obtenir votre consentement personnel ;\n(5) les informations collectées sont rendues publiques par vous-même ;\n(6) les informations sont collectées dans le cadre d'informations légalement divulguées publiquement, telles que des rapports d'actualité légitimes, la divulgation d'informations par le gouvernement et d'autres canaux ;\n(7) elles sont nécessaires à la signature des contrats que vous avez demandés\n(8) ces informations sont nécessaires pour préserver la sécurité et la stabilité des opérations des services de Creality, telles que la recherche et la gestion des défaillances des produits ou des services ;\n(9) elles sont nécessaires à des fins légitimes de diffusion d'informations\n(10) elles sont nécessaires pour que les instituts de recherche universitaires puissent mener des recherches statistiques ou universitaires dans l'intérêt du public, et pour dépersonnaliser les informations contenues dans les résultats lorsqu'ils fournissent des recherches universitaires ou des résultats descriptifs au public ; et\n(11) d'autres circonstances stipulées par les lois et règlements.\nIII. MODALITÉS DE CONSERVATION, DE STOCKAGE ET DE PROTECTION DES INFORMATIONS\nLes informations que vous nous communiquez sont conservées aussi longtemps que nécessaire aux fins décrites dans la présente politique de confidentialitéet aussi longtemps que l'exigent les lois et les règlements.\n1. Des dispositions claires sont prévues par les lois et les règlements ;\n2. Nous avons obtenu votre autorisation et votre consentement ; et\n3. Creality Cloud a besoin de fournir vos informations personnelles à l'étranger lorsque les produits et services que vous utilisez impliquent des actes transfrontaliers. En pareils cas, nous nous assurerons que vos informations personnelles sont protégées de manière adéquate conformément à la présente Politique et aux exigences des lois et réglementations nationales.\nPour protéger vos informations, nous prendrons les mesures suivantes :\n(I) Mesures techniques pour la sécurité des données\nNous prendrons ces mesures de sécurité dans le respect des normes industrielles, notamment en établissant des normes institutionnelles et des technologies de sécurité raisonnables pour empêcher l'accès, l'utilisation et la modification non autorisés de vos informations, et pour éviter les dommages ou les pertes de données. Les services de réseau utilisent diverses technologies de cryptage ; dans certains services, par exemple, nous adopterons des technologies de cryptage (par exemple SSL) pour protéger vos informations, les crypter et les sauvegarder, et nous appliquerons des technologies d'isolation pour les isoler.\nPour renforcer la sécurité des informations utilisées, nous adopterons diverses technologies de désensibilisation des données, telles que l'affichage des informations et le calcul de l'association d'informations. Des technologies strictes de contrôle d'accès aux données et d'authentification d'identités multiples sont adoptées pour protéger les informations et éviter l'utilisation illégale des données.\n(II) Parmi les autres mesures de sécurité prises pour protéger les informations, citons la gestion et la normalisation du stockage et de l'utilisation des informations par la mise en place d'un système de classification des données, de normes de gestion de la sécurité des données et de normes de développement de la sécurité des données.\nNous procédons à un contrôle de sécurité complet des données par le biais d'un accord de confidentialité des contacts d'information et d'un mécanisme de contrôle et d'audit. La sensibilisation à la sécurité est renforcée. Nous proposons en outre des cours de formation à la sécurité et à la protection de la vie privée afin de sensibiliser les employés à l'importance de la protection des informations.\n(III) Seuls les employés de Creality 3D qui ont besoin de connaître ces informations peuvent y avoir accès, et nous mettons en place des mécanismes stricts de contrôle d'accès et de surveillance à cet égard. Entre-temps, nous exigeons de tout le personnel susceptible d'avoir accès à vos informations qu'il remplisse les obligations de confidentialité correspondantes. Tout manquement à ces obligations peut entraîner une responsabilité juridique ou la suspension du partenariat avec Creality 3D.\n(IV) Toutes les mesures raisonnables et réalisables seront prises pour s'assurer qu'aucune information non pertinente n'est collectée.\n(V) L'Internet est un environnement qui n'est pas absolument sûr et il est impossible de déterminer si les méthodes de communication avec d'autres utilisateurs par e-mail, messagerie instantanée, logiciel de réseau social ou autre logiciel de service sont complètement cryptées, c'est pourquoi nous vous recommandons de définir des mots de passe complexes lorsque vous utilisez de tels outils et de faire tout votre possible pour garantir la sécurité des informations.\n(VI) Dans la mesure où l'environnement Internet n'est pas sûr à 100 %, nous nous efforcerons d'assurer ou de garantir la sécurité de toute information que vous nous envoyez. Si nos installations physiques, techniques ou de gestion sont endommagées, ce qui entraîne un accès non autorisé à vos informations ou leur divulgation publique, leur falsification ou leur destruction, ainsi qu'une atteinte à vos droits et intérêts légitimes, nous assumerons les responsabilités légales correspondantes.\n(VII) Traitement des incidents de sécurité\n(1) En communiquant avec des tiers ou en achetant des biens et des services par l'intermédiaire des services de Creality, il est inévitable que vous divulguiez des informations vous concernant, telles que vos coordonnées ou votre adresse postale, à des contreparties ou à des contreparties potentielles. Veuillez faire en sorte que vos informations soient correctement protégées et ne les communiquez à d'autres que si cela s'avère nécessaire.\n(2) Pour faire face aux risques potentiels de fuite, de détérioration et de perte d'informations, nous avons mis au point plusieurs systèmes visant à clarifier les normes de classification et d'évaluation des incidents de sécurité et des vulnérabilités, ainsi que les procédures de traitement correspondantes. Nous avons également mis en place une équipe spéciale d'intervention d'urgence pour les incidents de sécurité, initié des plans de sécurité pour différents incidents de sécurité conformément aux normes de traitement des incidents de sécurité, stoppé les pertes, analysé, localisé et développé des mesures correctives, ainsi que collaboré avec les départements concernés pour tracer et combattre les incidents. Nous vous informerons notamment de la situation de base et de l'impact possible de l'incident de sécurité, des mesures d'élimination que nous avons prises ou que nous prendrons, des suggestions que nous vous ferons pour prévenir et réduire les risques de manière indépendante, ainsi que des mesures correctives que nous vous proposerons. Nous vous informerons sans délai de la situation liée à l'incident par courrier, lettre, téléphone, notification push, etc. et nous ferons une annonce de manière raisonnable et efficace lorsqu'il est difficile d'informer les personnes concernées une par une. En attendant, nous ferons un rapport proactif sur le traitement des incidents de sécurité de l'information, comme l'exigent les autorités de régulation.\n(3) Services de stockage sur le cloud : En vue de vous proposer des services de stockage dans le nuage (les images et les contenus audio et vidéo que vous téléchargez sur Creality Cloud seront stockés dans le nuage et les scénarios associés), les fournisseurs de services tiers peuvent collecter des informations sur votre appareil, des informations liées au réseau et des informations sur l'opérateur.\nPour toute question concernant ce qui précède, vous pouvez visiter www.crealitycloud.com/ à tout moment pour obtenir vos informations telles qu'elles sont collectées et traitées par nous ou par les tiers qui coopèrent avec nous.\nIV. VOS DROITS CONCERNANT VOS INFORMATIONS PERSONNELLES\nEn application des lois et réglementations de votre pays ou région de résidence, vous avez le droit de demander l'accès, la correction et la suppression de toute information personnelle que nous détenons à votre sujet (ci-après dénommée la « demande »). De tels droits sont toutefois soumis à des exclusions et exceptions spécifiques en vertu des lois applicables. Pour toute question, vous pouvez nous envoyer un courriel à l'adresse cs@creality.com.\nTout désaccord avec la présente politique de confidentialité entraînera l'impossibilité d'utiliser l'appareil pour les fonctions de réseau.\nPour toute question ou suggestion concernant cette politique de confidentialité, n'hésitez pas à nous contacter via cs@creality.com, la boîte aux lettres officielle.\n\n",\
    "Grazie per aver scelto i prodotti Creality.\n\nShenzhen Creality 3D Technology Co., Ltd. (\"Creality 3D\", \"noi\", \"ci\" o \"nostro\") si impegna solennemente a proteggere la privacy degli utenti (di seguito denominati \"utenti\" o \"tu\") che utilizzano prodotti e servizi Creality (di seguito denominati \"servizi Creality\"). Potremmo raccogliere e utilizzare le informazioni su di te quando utilizzi i servizi Creality. Si noti che rivedremo le nostre politiche di volta in volta, pertanto le misure pertinenti potrebbero cambiare di conseguenza. Ti invitiamo a visitare regolarmente questa pagina per assicurarti di essere sempre a conoscenza dell'ultima versione della nostra Informativa sulla privacy. Dopo aver letto questa Informativa sulla privacy, non esitare a contattarci tramite cs@creality.com in caso di dubbi sulla presente Informativa sulla privacy o su temi ad essa correlati.\n\nI. QUALI INFORMAZIONI RACCOGLIAMO?\n(I) Informazioni non correlate all'identità personale:\nQuando utilizzi i servizi Creality, potremmo raccogliere e riassumere informazioni come l'origine dell'utente e l'ordine di accesso, inclusa la registrazione dell'origine di ciascun utente che utilizza i servizi Creality.\n(II) Informazioni sull'identità personale:\nQuando utilizzi i servizi Creality, potremmo raccogliere e riassumere o chiedere il tuo numero di telefono personale e le informazioni sull'identità di rete (incluso il numero di account di sistema, l'indirizzo IP, l'indirizzo e-mail e le relative passphrase, le password e le risposte di protezione delle password, ecc.).\n(1) Registri personali di navigazione in Internet e informazioni di registro (tra cui la cronologia di navigazione dei siti web, i registri di utilizzo del software, i registri dei clic, i registri delle operazioni, ecc);\n(2) Le informazioni sul dispositivo (incluso il modello del dispositivo, l'indirizzo MAC del dispositivo, il tipo di sistema operativo e le impostazioni del dispositivo) e il codice di identificazione univoco del dispositivo dell'elenco del software (come IMEI/ID Android/IDFA/OPENUDID/GUID, informazioni IMSI della scheda SIM e altre informazioni che descrivono lo stato di base dei dispositivi personali comunemente usati).\nRaccogliamo informazioni su di te principalmente per rendere più facile e più soddisfacente per te e per gli altri utenti l'utilizzo dei servizi Creality. Lo scopo di Creality Cloud è quello di fornire a tutti gli utenti di Internet esperienze di navigazione sicure, interessanti e istruttive, e tali informazioni ci aiuteranno a raggiungere questo scopo.\nII. IN CHE MODO RACCOGLIAMO E UTILIZZIAMO LE INFORMAZIONI\n(I) Raccoglieremo e otterremo le tue informazioni attraverso i seguenti canali, ad esempio:\n(1) Le informazioni che ci fornisci al momento della registrazione o dell'utilizzo dei servizi Creality;\n(2) Le informazioni condivise fornite ad altre parti attraverso i servizi Creality e le informazioni memorizzate durante l'utilizzo dei servizi Creality; e\n(3) Le informazioni che otteniamo su di te. Quando utilizzi i servizi Creality, raccogliamo, riassumiamo e registriamo le informazioni relative, ad esempio: informazioni di registro, informazioni sul dispositivo e così via.\n(II) COOKIES e file di registro\nNoi o i nostri partner di terze parti possiamo ottenere e utilizzare le tue informazioni tramite I COOKIES e memorizzarle come informazioni di registro. Tramite i COOKIES, forniamo agli utenti un'esperienza di rete semplice e personalizzata. I COOKIES rappresentano una piccola quantità di dati che vengono inviati da un server di rete al browser e memorizzati sul disco rigido del computer. Utilizziamo I COOKIES in modo che gli utenti possano trarne vantaggio.\nI COOKIES ci consentono di servirti meglio e più velocemente e di personalizzare la tua esperienza con i servizi Creality. Tuttavia, dovresti essere in grado di controllare se e come I COOKIES vengono accettati dal tuo browser. Per maggiori informazioni al riguardo, consulta i file allegati al tuo browser.\n(III) Potremmo raccogliere e utilizzare le tue informazioni tramite COOKIE e memorizzarle di conseguenza al fine di:\n(1) Ricordare i tuoi dati. Ad esempio: I COOKIES ci aiutano a identificarti come nostro utente registrato o a salvare le informazioni che ci fornisci sulle tue preferenze o altri aspetti;\n(2) Analizzare l'utilizzo dei nostri servizi. Potremmo applicare dei COOKIES per scoprire quali attività stai svolgendo con i servizi di Creality o quali sono i servizi più popolari;\n(3) Ottimizzazione pubblicitaria. I COOKIES ci aiutano a offrirti gli annunci pubblicitari più adatti a te in base alle tue informazioni, piuttosto che a condurre campagne pubblicitarie generiche.\nI servizi Creality possono contenere COOKIES inseriti da inserzionisti e altri partner. Tali COOKIES possono raccogliere informazioni non identificabili personalmente su di te allo scopo di analizzare come gli utenti utilizzano tali servizi, inviarti annunci pubblicitari a cui potresti essere interessato o valutare l'efficacia dei servizi pubblicitari. La raccolta e l'utilizzo di tali informazioni da parte di tali terze parti tramite I COOKIES non è soggetta alla presente Informativa sulla privacy, ma alle loro dichiarazioni sulla protezione dei dati personali; pertanto non ci assumiamo alcuna responsabilità per i COOKIES di terze parti.\nPuoi rifiutare la raccolta o gestire i COOKIES attraverso un browser o un meccanismo di selezione dell'utente. Tuttavia, è bene notare che se disattivi i COOKIES, potremmo non essere in grado di offrirti la migliore esperienza in termini di servizi e alcuni servizi potrebbero non essere utilizzabili normalmente.\n(IV) Raccoglieremo e utilizzeremo le tue informazioni per i seguenti scopi:\n1. Inoltrarti i messaggi\nMostrarti e inviarti beni o servizi. Previo tuo consenso, potremo utilizzare i dati del tuo dispositivo per inviarti informazioni di marketing via e-mail, SMS o altri mezzi, al fine di fornire o promuovere i seguenti beni e servizi nostri o di terzi:\nI nostri beni e servizi includono, a titolo esemplificativo ma non esaustivo, servizi di media online, servizi di social networking, servizi di ricerca su Internet, servizi di localizzazione e mappe, software e servizi applicativi, software e servizi di gestione dei dati, programmi a punti e premi, prodotti per dispositivi, prodotti per periferiche di stampa 3D, nonché altri beni e servizi che riteniamo possano essere correlati all'utente.\n2. Migliorare i nostri servizi\nPossiamo applicare le informazioni raccolte attraverso alcuni servizi Creality ad altri nostri servizi. Ad esempio, i tuoi dati raccolti durante l'utilizzo di alcuni servizi di Creativity possono essere utilizzati in altri servizi di Creativity per fornirti contenuti specifici o per mostrarti informazioni relative all'utente piuttosto che per essere diffuse in generale; potremmo invitarti a partecipare a sondaggi relativi ai servizi di Creativity per aiutarci a migliorare i servizi esistenti o a progettarne di nuovi; inoltre, potremmo utilizzare i tuoi dati per gli aggiornamenti del software.\nL'utente è consapevole e accetta che, dopo la raccolta dei suoi dati, potremmo de-identificarli con mezzi tecnici e che le informazioni de-identificate non serviranno a risalire alla sua identità; in tal caso siamo autorizzati a utilizzare le informazioni de-identificate per analizzare il database degli utenti e farne un uso commerciale. Il tuo consenso sarà richiesto in anticipo se le tue informazioni vengono utilizzate per altri scopi non specificati nella presente Informativa sulla privacy.\n3. Eccezioni nell'ottenimento dell'autorizzazione. Ai sensi delle leggi e dei regolamenti pertinenti, la tua autorizzazione non è richiesta nella raccolta delle tue informazioni nelle seguenti circostanze:\n(1) Le informazioni sono correlate alla sicurezza nazionale e alla sicurezza della difesa nazionale;\n(2) Le informazioni sono correlate alla sicurezza pubblica, alla salute pubblica e ai principali interessi pubblici;\n(3) Le informazioni sono correlate a indagini penali, azioni penali, processi ed esecuzione di sentenze;\n(4) Le informazioni possiedono lo scopo di salvaguardare i diritti e gli interessi legittimi significativi dell'interessato o di altri individui, come la vita e la proprietà, ma è difficile ottenere il suo consenso personale;\n(5) Le informazioni raccolte sono divulgate al pubblico dall’utente stesso;\n(6) Le informazioni sono raccolte da informazioni legalmente divulgate pubblicamente, come notizie legittime, informazioni governative e altri canali;\n(7) Sono necessarie per la firma dei contratti come da tua richiesta;\n(8) Sono necessarie per mantenere le operazioni sicure e stabili dei servizi Creality, ad esempio per individuare e gestire i guasti dei prodotti o dei servizi;\n(9) Sono necessarie per la segnalazione di notizie legittime;\n(10) Sono necessarie per gli istituti di ricerca accademici per condurre ricerche statistiche o accademiche di interesse pubblico e per de-identificare le informazioni contenute nei risultati quando forniscono ricerche accademiche o risultati statistici al pubblico; e\n(11) Per altre circostanze previste da leggi e regolamenti.\nIII. IN CHE MODO CONSERVIAMO, ARCHIVIAMO E PROTEGGIAMO LE INFORMAZIONI\nConserveremo le tue informazioni solo per il tempo necessario agli scopi descritti nella presente Informativa sulla privacy e per il tempo richiesto da leggi e regolamenti.\n1. Esistono disposizioni chiare nelle leggi e nei regolamenti;\n2. Se la autorizzazione e il tuo consenso sono stati ottenuti e\n3. Creality Cloud ha bisogno di fornire i tuoi dati personali all'estero nel momento in cui i prodotti e i servizi che utilizzi comportano delle operazioni transfrontaliere, ci assicureremo che le tue informazioni personali siano adeguatamente protette in conformità con la presente Informativa e con i requisiti delle leggi e dei regolamenti nazionali.\nAdotteremo le seguenti misure per proteggere le tue informazioni:\n(I) Misure tecniche per la sicurezza dei dati\nAdotteremo queste misure di sicurezza in linea con gli standard del settore, tra cui la definizione di norme istituzionali ragionevoli e tecnologie di sicurezza per prevenire l'accesso non autorizzato, l'uso e la modifica delle informazioni e per evitare danni o perdite di dati. I servizi di rete utilizzano una serie di tecnologie di crittografia; ad esempio, in alcuni servizi, adotteremo tecnologie di crittografia (come SSL) per proteggere le tue informazioni, oltre a crittografarle e salvarle, e applicheremo tecnologie di isolamento per isolarle.\nAdotteremo una varietà di tecnologie di desensibilizzazione dei dati per migliorare la sicurezza delle informazioni in uso, come la visualizzazione delle informazioni e il calcolo dell'associazione delle informazioni. Per proteggere le informazioni ed evitare l'uso illegale dei dati vengono adottati un rigoroso controllo dell'accesso ai dati e tecnologie di autenticazione delle identità multiple.\n(II) Altre misure di sicurezza che adottiamo per proteggere le informazioni includono la gestione e la standardizzazione dell'archiviazione e dell'utilizzo delle informazioni attraverso l'istituzione di un sistema di classificazione dei dati, di norme di gestione della sicurezza dei dati e di norme di sviluppo della sicurezza dei dati.\nEseguiamo un controllo completo della sicurezza dei dati attraverso un accordo di riservatezza in materia di comunicazione delle informazioni e un meccanismo di monitoraggio e audit. Rafforziamo la consapevolezza della sicurezza. Inoltre, teniamo corsi di formazione sulla sicurezza e sulla protezione della privacy per migliorare la consapevolezza dei dipendenti sull'importanza della protezione delle informazioni.\n(III) Consentiamo l'accesso alle tue informazioni solo ai dipendenti di Creality 3D che devono conoscerle, e a tal proposito abbiamo istituito meccanismi di controllo e monitoraggio rigorosi. Nel frattempo, chiediamo a tutto il personale che può avere accesso alle tue informazioni di rispettare i relativi obblighi di riservatezza. Il mancato rispetto di tali obblighi può comportare responsabilità legali o la sospensione della partnership con Creality 3D.\n(IV) Adotteremo tutte le misure ragionevoli e fattibili per garantire che non vengano raccolte informazioni non pertinenti.\n(V) Internet non offre un ambiente assolutamente sicuro ed è impossibile stabilire se i metodi di comunicazione con gli altri utenti tramite e-mail, messaggistica istantanea, software di social network o altri servizi siano completamente criptati, pertanto ti consigliamo di impostare password complesse quando utilizzi tali strumenti e di fare ogni sforzo per garantire la sicurezza delle informazioni.\n(VI) Poiché l'ambiente Internet non è sicuro al 100%, ci sforzeremo di proteggere o garantire la sicurezza di qualsiasi informazione che ci invii. Nel caso in cui le nostre strutture di protezione fisica, tecnica o gestionale vengano danneggiate, con conseguente accesso non autorizzato o divulgazione pubblica, manomissione o distruzione delle tue informazioni e con ulteriore conseguente danno ai tuoi diritti e interessi legittimi, ci assumeremo le corrispondenti responsabilità legali.\n(VII) Gestione degli incidenti di sicurezza\n(1) Nel corso della comunicazione con terze parti o dell'acquisto di beni e servizi tramite i servizi Creality, è inevitabile la divulgazione di informazioni che ti riguardano, come informazioni di contatto o indirizzo postale, a controparti o potenziali controparti. Ti preghiamo di proteggere adeguatamente le tue informazioni e di fornirle ad altri solo se necessario.\n(2) In risposta ai potenziali rischi di fuga, violazione e perdita di informazioni, abbiamo sviluppato diversi sistemi per chiarire gli standard di classificazione e di valutazione degli incidenti di sicurezza e delle vulnerabilità, nonché i relativi processi di gestione. Inoltre, abbiamo istituito una squadra speciale di pronto intervento per gli incidenti di sicurezza, abbiamo avviato piani di sicurezza contro diversi incidenti di sicurezza come richiesto dalle norme di gestione degli incidenti di sicurezza, abbiamo bloccato le perdite, analizzato, localizzato e sviluppato misure correttive, oltre a collaborare con i dipartimenti competenti per la tracciabilità e la prevenzione. Nel caso in cui si verifichi un incidente di sicurezza delle informazioni, ti informeremo tempestivamente come richiesto dalle leggi e dai regolamenti, indicandoti la situazione di partenza e il possibile impatto dell'incidente di sicurezza, le misure di sicurezza che abbiamo adottato o adotteremo, i suggerimenti per prevenire e ridurre i rischi in modo autonomo e le misure correttive che dovrai adottare. Ti informeremo tempestivamente della situazione relativa all'incidente tramite posta, lettera, telefono, notifica push, ecc. e faremo un annuncio in modo ragionevole ed efficace qualora sia difficile informare i soggetti interessati uno per uno. Nel frattempo, segnaleremo in modo proattivo la gestione degli incidenti di sicurezza delle informazioni come richiesto dalle autorità di regolamentazione.\n(3) Servizi di cloud storage: Al fine di fornirti servizi di cloud storage (le immagini e i contenuti audio e video che carichi su Creality Cloud saranno archiviati nel cloud e negli scenari correlati), i fornitori di servizi di terze parti possono raccogliere le informazioni sul tuo dispositivo, le informazioni relative alla rete e le informazioni sull'operatore.\nSe hai domande su quanto sopra, puoi visitare il sito www.crealitycloud.com/ in qualsiasi momento per conoscere i dati che abbiamo raccolto ed elaborato personalmente o le terze parti che collaborano con noi.\nIV. I TUOI DIRITTI SULLE TUE INFORMAZIONI PERSONALI\nIn conformità alle leggi e ai regolamenti del tuo paese o della tua regione di residenza, hai il diritto di richiedere l'accesso, la correzione e la cancellazione di qualsiasi informazione personale in nostro possesso che ti riguardi (di seguito denominata \"richiesta\"). Tuttavia, tali diritti saranno soggetti a specifiche esclusioni ed eccezioni ai sensi delle leggi applicabili. Potrai rivolgerci qualsiasi domanda all'indirizzo cs@creality.com.\nSe non sei d'accordo con la presente Informativa sulla privacy, il dispositivo non potrà usufruire delle funzionalità di rete.\nIn caso di domande o suggerimenti sulla presente Informativa sulla privacy, non esitare a contattarci tramite l’indirizzo ufficiale: cs@creality.com.\n\n",\
    "Obrigado por escolher os produtos Creality.\n\nA Shenzhen Creality 3D Technology Co., Ltd. (\"Creality 3D\", \"nós\", \"nossa\" ou \"nosso\") compromete-se solenemente a proteger a privacidade dos usuários (doravante denominados de \"usuários\" ou \"você\") que usam produtos e serviços da Creality (doravante denominados \"serviços da Creality\"). Quando você usa determinados serviços da Creality, podemos coletar e utilizar informações sobre você. Deve-se observar que, como examinamos periodicamente nossas políticas, essas medidas pertinentes podem eventualmente sofrer alterações. A fim de garantir que você esteja sempre ciente da versão mais recente de nossa Política de Privacidade, pedimos que retorne a esta página com frequência. Após ler a presente Política de Privacidade, por favor, sinta-se à vontade para entrar em contato conosco pelo e-mail cs@creality.com caso tenha alguma dúvida sobre esta Política de Privacidade ou sobre os assuntos relacionados a ela.\n\nI. QUAIS INFORMAÇÕES COLETAMOS?\n(I) Informações não relacionadas à identidade pessoal:\nQuando você usa os serviços da Creality, podemos coletar e compilar dados sobre a origem do usuário, ordem de acesso, entre outros. Isso inclui manter o controle da origem de cada usuário que usa os serviços da Creality.\n(II) Informações sobre identidade pessoal:\nSeu número de telefone pessoal e informações de identificação de rede (como o número da sua conta do sistema, endereço IP, endereço de e-mail e quaisquer senhas associadas, senhas e respostas de proteção de senha, etc.) podem ser coletados e processados pela Creality quando você estiver usando nossos serviços da Creality.\n(1) Informações sobre padrões individuais de uso da Internet (tais como visitas anteriores ao site, padrões de uso de software, padrões de cliques e logs de operação);\n(2) Informações do dispositivo, como modelo, endereço MAC, tipo de sistema operacional e configurações do dispositivo, bem como lista de software códigos exclusivos de identificação do dispositivo (tais como IMEI/ID do Android/IDFA/OPENUDID/GUID, informações do cartão SIM IMSI , e outras informações que descrevem o status fundamental de dispositivos pessoais usados com frequência).\nColetamos informações sobre você apenas para facilitar e aprimorar o uso dos serviços da Creality por você e outros usuários. O objetivo da Creality Cloud é tornar o uso da Internet seguro, divertido e educativo para todos os usuários, e as informações que você enviar nos ajudarão a atingir esse objetivo.\nII. COMO COLETAMOS E USAMOS AS INFORMAÇÕES\n(I) Coletaremos e obteremos suas informações por meio dos seguintes canais, por exemplo:\n(1) As informações que você nos fornece ao se registrar ou usar os serviços da Creality;\n(2) As informações compartilhadas que você fornece a outras partes por meio dos serviços da Creality e as informações que você armazena ao usar os serviços da Creality; e\n(3) As informações que obtemos sobre você. Coletamos, compilamos e registramos as informações relevantes quando você usa os serviços da Creality, como informações de registro, informações do dispositivo e assim por diante.\n(II) COOKIES e arquivos de registro\nSuas informações podem ser obtidas e usadas por nós ou por nossos parceiros terceirizados por meio de COOKIES e podem ser salvas como dados de registro. Oferecemos aos consumidores uma experiência de rede simples e individualizada com COOKIES. Um servidor de rede envia COOKIES, que são uma pequena quantidade de dados, para o seu navegador, onde são salvos no disco rígido do seu computador. Usamos COOKIES para que seus usuários possam se beneficiar.\nOs COOKIES permitem-nos fornecer a você um serviço melhor e mais rápido e personalizar a sua utilização dos serviços da Creality. No entanto, você deve ser capaz de controlar se e como os COOKIES são aceitos pelo seu navegador. Por favor, consulte os arquivos que acompanham seu navegador para obter mais informações a esse respeito.\n(III) Podemos coletar e usar suas informações por meio de COOKIE e armazená-las adequadamente\n(1) Lembrar quem você é. Por exemplo: Os cookies nos permitem reconhecê-lo como um usuário registrado de nosso site e salvar as preferências e outros dados que você nos fornece;\n(2) Examinar como você está usando nossos serviços. Para determinar o que você faz com os serviços da Creality ou quais serviços ou serviços são os mais populares, podemos usar COOKIES para tal finalidade.\n(3) Realizar otimização de marketing. Em vez de executar campanhas publicitárias genéricas, os COOKIES nos permitem fornecer anúncios relevantes com base em suas informações.\nOs serviços da Creality podem ter COOKIES inseridos por parceiros e profissionais de marketing. Esses COOKIES podem coletar informações anônimas sobre você para analisar como os usuários usam os serviços, veicular anúncios que você pode achar interessantes ou avaliar o sucesso de campanhas publicitárias. Não nos responsabilizamos pelos COOKIES de terceiros, e a coleta e uso de tais informações por tais terceiros por meio de COOKIES não são regidos pela presente Política de Privacidade, mas sim por suas próprias políticas de privacidade.\nAtravés de um navegador ou do método de seleção do usuário, você pode controlar ou impedir que COOKIES sejam configurados. Deve-se notar que, se você desativar os COOKIES, podemos não ser capazes de fornecer o melhor serviço possível e alguns serviços podem não funcionar como pretendido.\n(IV) Coletaremos e usaremos suas informações para as seguintes finalidades:\n1. Enviar mensagens para você\nMostrar e enviar produtos ou serviços para você. Mediante seu consentimento, poderemos usar as informações do seu dispositivo para enviar informações de marketing por e-mail, SMS ou outros meios, a fim de fornecer ou promover os seguintes produtos e serviços nossos ou de terceiros:\nServiços de mídia online, serviços de redes sociais, serviços de pesquisa na Internet, serviços de localização e mapa, software e serviços de aplicativos, software e serviços de gerenciamento de dados, programas de pontos e recompensas, produtos de dispositivos, produtos periféricos de impressão 3D, bem como outros produtos e serviços que oferecemos acredita que possa ser do seu interesse, são apenas alguns dos produtos e serviços que oferecemos.\n2. Melhorar nossos serviços\nPodemos usar os dados coletados por meio de determinados serviços da Creality em nossos outros serviços. Por exemplo, outros serviços de criatividade podem utilizar os dados que adquiriram sobre você ao usar um de seus serviços de criatividade para oferecer a você material relevante para você, em vez de apenas enviar para você; a fim de desenvolver serviços de criatividade ou aprimorar os atuais, podemos solicitar sua opinião em pesquisas relacionadas aos serviços. Enquanto isso, podemos usar suas informações para atualizações de software.\nVocê reconhece e aceita que, após a coleta de suas informações, podemos usar meios técnicos para desidentificar os dados para que não possam ser usados para determinar sua identidade. Nesse caso, podemos usar os dados não identificados para analisar o banco de dados do usuário e para outros fins comerciais. Caso suas informações sejam utilizadas por qualquer motivo não contemplado nesta Política de Privacidade, sua autorização será solicitada com antecedência.\n3. Com exceção da obtenção de autorização. De acordo com as leis e regulamentações relevantes, sua autorização não é necessária para coletar suas informações nas seguintes circunstâncias:\n(1) Está relacionada à segurança nacional e à segurança da defesa nacional;\n(2) Está relacionada à segurança pública, à saúde pública e aos principais interesses públicos;\n(3) Está relacionada à investigação criminal, acusação, julgamento e execução de sentença;\n(4) É difícil obter sua permissão pessoal, mas é com o objetivo de proteger os importantes direitos e interesses legítimos do titular da informação ou de outras pessoas, como vida e propriedade.\n(5) As informações coletadas são divulgadas ao público por você;\n(6) Os dados são coletados de fontes de informação legalmente públicas, incluindo fontes de notícias respeitáveis, divulgação de informações do governo e outras fontes.\n(7) É necessário para assinar contratos conforme exigido por você;\n(8) É necessário para manter as operações seguras e estáveis dos serviços da Creality, como encontrar e lidar com falhas de produtos ou serviços;\n(9) É necessário para a divulgação de notícias legítimas;\n(10) É necessário que as instituições de pesquisa acadêmica realizem pesquisas estatísticas ou acadêmicas de interesse público e desidentifiquem as informações contidas nos resultados ao fornecer pesquisas acadêmicas ou resultados descritivos ao público; e\n(11) Outras circunstâncias estipuladas por leis e regulamentos.\nIII. COMO RETEMOS, ARMAZENAMOS E PROTEGEMOS AS INFORMAÇÕES\nReteremos suas informações somente pelo tempo necessário para os fins descritos nesta Política de Privacidade e pelo tempo exigido por leis e regulamentos.\n1. Existem disposições claras em leis e regulamentos;\n2. Sua autorização e consentimento forem obtidos; e\n3. Quando os produtos e serviços que você usa incluem transações internacionais, a Creality Cloud é obrigada a divulgar suas informações pessoais no exterior. Em tais circunstâncias, garantiremos que suas informações pessoais sejam devidamente protegidas de acordo com a presente Política e com as exigências das leis e regulamentos nacionais aplicáveis.\nTomaremos as seguintes medidas para proteger suas informações:\n(I) Medidas técnicas de segurança de dados\nTais medidas de segurança, que incluem o estabelecimento de normas institucionais adequadas e tecnologias de segurança, serão implementadas por nós de acordo com os padrões da indústria para evitar acesso não autorizado, uso e alteração de suas informações, bem como para evitar perda ou dano de dados. Os serviços de rede usam uma variedade de métodos de criptografia; por exemplo, com determinados serviços, usaremos tecnologias de criptografia (como SSL) para proteger suas informações, criptografá-las para armazenamento e isolá-las.\nPara melhorar a segurança das informações em uso, usaremos uma variedade de tecnologias de dessensibilização de dados, incluindo apresentação de informações e computação de associação de informações. Para salvaguardar os dados e impedir o seu uso não autorizado, são utilizados controlos rigorosos de acesso aos dados e vários métodos de autenticação de identidade.\n(II) O gerenciamento e padronização do armazenamento e uso de informações por meio do estabelecimento de um sistema de categorização e classificação de dados, padrões de gerenciamento de segurança de dados e normas de desenvolvimento de segurança de dados são medidas de segurança adicionais que adotamos para proteger as informações.\nPor meio de acordos de confidencialidade de contato de informações, monitoramento e mecanismos de auditoria, realizamos um controle de segurança completo sobre os dados. Aumentamos a conscientização das pessoas sobre segurança. Além disso, oferecemos sessões de treinamento sobre segurança e proteção de privacidade para aumentar o conhecimento da equipe sobre a importância da segurança de dados.\n(III) Aplicamos rigorosamente controles de acesso e procedimentos de monitoramento para garantir que apenas os funcionários da Creality 3D que precisam dessas informações tenham acesso às suas informações. Entretanto, exigimos que todos os funcionários que possam ter acesso às suas informações cumpram as responsabilidades de confidencialidade relevantes. O não cumprimento de tais obrigações pode resultar em responsabilidade legal ou suspensão da parceria com a Creality 3D.\n(IV) Faremos todos os esforços, dentro do razoável e da capacidade, para garantir que nenhum dado desnecessário seja coletado.\n(V) Como a Internet não oferece um ambiente totalmente seguro e como é impossível saber se os métodos de comunicação de outros usuários em e-mail, mensagens instantâneas, software de rede social ou outro software de serviço são totalmente criptografados, recomendamos que você use senhas complexas e tome outras precauções para garantir a segurança de seus dados pessoais ao usar essas ferramentas.\n(VI) Embora a 100% segurança de qualquer informação que você nos forneça através da Internet não possa ser garantida, faremos todos os esforços para fazê-lo. Assumiremos as obrigações legais associadas caso uma de nossas instalações físicas, técnicas ou de proteção de gerenciamento seja comprometida, resultando em acesso não autorizado ou divulgação pública, adulteração ou destruição de suas informações e resultando ainda em danos a seus direitos e interesses legítimos.\n(VII) Tratamento de incidentes de segurança\n(1) Durante a comunicação com terceiros ou a compra de bens e serviços por meio dos serviços da Creality, é inevitável que você divulgue informações sobre si mesmo, como informações de contato ou endereço postal, para contrapartes ou possíveis contrapartes. Proteja suas informações com cuidado e compartilhe-as apenas com outras pessoas conforme necessário.\n(2) Criamos muitos métodos para tornar claros os critérios de categorização e classificação para eventos e vulnerabilidades de segurança, bem como os procedimentos de gerenciamento associados, em resposta aos possíveis perigos de vazamento, dano e perda de informações. Além disso, estabelecemos uma equipe especial de resposta a emergências para incidentes de segurança, iniciamos planos de segurança contra vários incidentes de segurança de acordo com as normas de tratamento de incidentes de segurança, interrompemos perdas, analisamos, localizamos e desenvolvemos medidas corretivas, bem como trabalhamos com departamentos para rastrear e combater. No caso de um lamentável incidente de segurança da informação, iremos notificá-lo prontamente de acordo com as leis e regulamentos aplicáveis, fornecendo informações sobre a situação geral e os possíveis efeitos do incidente de segurança, as medidas de descarte que tomamos ou tomaremos, as recomendações para você deve tomar por conta própria para prevenir e reduzir riscos, e as ações corretivas para você. Por correio, carta, telefone, notificação de envio, etc., iremos informá-lo rapidamente sobre as circunstâncias relacionadas ao incidente. Quando for impossível notificar cada titular da informação individualmente, faremos um comunicado de forma justa e eficiente. Conforme exigido pelas autoridades reguladoras, devemos relatar proativamente como os eventos de segurança da informação são tratados nesse meio tempo.\n(3) Serviços de armazenamento em nuvem: Provedores de serviços terceirizados podem coletar informações do seu dispositivo, informações relacionadas à rede e informações da operadora para fornecer a você serviços de armazenamento em nuvem (as imagens, áudio e conteúdo de vídeo que você enviar para a Creality Cloud serão armazenados na nuvem e relacionados cenários).\nVocê pode acessar suas informações conforme coletadas e processadas por nós ou nossos terceiros colaboradores a qualquer momento, visitando www.crealitycloud.com se tiver alguma dúvida sobre o mencionado acima.\nIV. SEUS DIREITOS SOBRE SUAS INFORMAÇÕES PESSOAIS\nDe acordo com as leis e regulamentações do país ou região em que reside, você tem o direito de solicitar acesso, correção e exclusão de quaisquer informações pessoais mantidas por nós relacionadas a você (doravante denominada \"solicitação\"). Porém, de acordo com a legislação vigente, alguns limites e exceções se aplicam a tais direitos. Além disso, você pode entrar em contato conosco pelo e-mail cs@creality.com para esclarecer quaisquer dúvidas que possa ter.\nSe você discordar desta Política de Privacidade, o dispositivo não oferecerá funcionalidade de rede.\nSe tiver alguma dúvida ou sugestão sobre esta Política de Privacidade, entre em contato conosco pelo e-mail cs@creality.com, a caixa de correio oficial.\n\n",\
    "Спасибо за выбор продукции Creality.\n\nКомпания Shenzhen Creality 3D Technology Co., Ltd.(далее — «Creality 3D», «мы», «нас» или «наш») торжественно обязуется охранять конфиденциальность пользователей (далее — «пользователи» или «вы»), которые пользуются продуктами и услугами Creality (далее — «Услуги Creality»). Мы можем собирать и использовать информацию о вас при использовании вами услуг Creality. Следует отметить, что мы будем периодически пересматривать свои документы политики, следовательно такие меры могут изменяться соответствующим образом. Просим пользователей регулярно посещать эту страницу, чтобы всегда быть в курсе последней версии нашей Политики конфиденциальности. После ознакомления с Политикой конфиденциальности без колебаний обращайтесь к нам по адресу эл. почты cs@creality.com, если у вас возникнут какие-либо сомнения относительно этой Политики конфиденциальности или связанных с ней вопросов.\n\nI. КАКУЮ ИНФОРМАЦИЮ МЫ СОБИРАЕМ?\n(I) Информация, не связанная с установлением личности:\nПри использовании вами услуг Creality мы можем собирать и обобщать такую информацию, как происхождение пользователей и порядок доступа, включая запись происхождения каждого пользователя, который пользуется услугами Creality.\n(II) Личная информация пользователя:\nКогда вы используете услуги Creality, мы можем собирать и обобщать или запрашивать у вас личный номер телефона, идентификационную информацию в сети (включая номер учетной записи в системе, IP-адрес, адрес эл-почты и связанные с ним парольные фразы, пароли и ответы для защиты паролем и т. д.).\n(1) Личные записи о просмотре интернет-страниц, информация журнала (включая журнал браузера, записи об использовании программного обеспечения, записи о щелчках на страницах, операционные журналы и т. д.);\n(2) Информация об устройстве (включая модель устройства, MAC-адрес устройства, тип операционной системы и настройки устройства), а также уникальный идентификационный код устройства в списке программного обеспечения (например, IMEI/android ID/IDFA/OPENUDID/GUID, информация IMSI SIM-карты и прочая информация, описывающая основное состояние постоянно используемых личных устройств).\nМы собираем информацию о вас, прежде всего, чтобы сделать использование услуг Creality более легким и удовлетворительным как для вас, так и для других пользователей. Цель Creality Cloud заключается в том, чтобы обеспечить для всех пользователей интернета безопасный, интересный и поучительный просмотр интернет-страниц, а подобная информация помогает нам достигать этой цели.\nII. КАК МЫ СОБИРАЕМ И ИСПОЛЬЗУЕМ ИНФОРМАЦИЮ\n(I) Мы будем собирать и получать вашу информацию посредством следующих каналов, например:\n(1) Предоставляемая вами нам информация при регистрации в услугах Creality или использовании услуг Creality;\n(2) Информация с совместным доступом, которую вы передаете другим лицам посредством услуг Creality, а также информация, которую вы храните при использовании услуг Creality; и\n(3) Информация о вас, которую мы получаем. При использовании вами услуг Creality мы собираем, обобщаем и записываем соответствующую информацию, например: информацию журнала, информация об устройстве и т. д.\n(II) Файлы COOKIE и файлы журнала\nМы или наши сторонние партнеры можем получать и испольовать вашу информацию посредством файлов COOKIE, а затем хранить эту информацию, как записи журнала. Посредством файлов COOKIE мы обеспечиваем для пользователей легкое в использовании и персонализированное сетевое взаимодействие. Файлы COOKIE являются файлами с малым количеством данных, которые отсылаются сетевым сервером вашему браузеру и хранятся на жестком диске вашего компьютера. Мы используем файлы COOKIE для преимущества пользователей.\nФайлы COOKIE позволяют нам лучше и быстрее вас обслуживать, а также персонализировать взаимодействие с услугами Creality. Однако у вас должна быть возможность управлять тем, принимает ли браузер файлы COOKIE. Для этого, чтобы получить дополнительную информацию, см. файлы, которые прилагаются к браузеру.\n(III) Мы можем собирать и использовать вашу информацию посредством файлов COOKIE и хранить ее соответствующим образом.\n(1) Запоминать, кто вы. Например: Файлы COOKIE помогают нам опознавать вас как зарегистрированного пользователя или сохранять предоставленную вами информацию о своих предпочтениях или других аспектах.\n(2) Анализировать использование вами наших услуг. Мы можем применять файлы COOKIE, чтобы обнаруживать, какие действия вы выполняете с услугами Creality или чтобы узнавать, какие услуги или услуга наиболее популярны.\n(3) Оптимизировать рекламу. Файлы COOKIE помогают нам предлагать относящиеся к вам рекламные обновления на основании предоставленной вами информации, а не проводить общую рекламную кампанию.\nУслуги компании Creality могут содержать файлы COOKIE, размещенные рекламодателями и другими партнерами. Такие файлы COOKIE могут содержать информацию о вас, по которой нельзя установить личность, для проведения анализа того, как используются наши услуги пользователями, отправки вам рекламных объявлений, в которых вы можете быть заинтересованы, или оценки эффективности рекламных услуг. Сбор и использование такой информации третьим лицом посредством файлов COOKIE не регулируется этой Политикой конфиденциальности; И Эти вопросы регулируются собственными охранными заявлениями таких третьих лиц, при этом мы не несем ответственности за файлы COOKIE третьих лиц.\nВы можете отклонить файлы COOKIE или управлять ими при помощи браузера или пользовательского механизма выбора. Однако следует отметить, что если вы отключите файлы COOKIE, у нас может не быть возможности обеспечивать для вас наилучшее обслуживание, а некоторыми услугами нормально пользоваться будет нельзя.\n(IV) Мы будем собирать и использовать информацию в следующих целях:\n1. Предоставление вам push-сообщений\nОтправка вам данных о товарах или услугах. С вашего согласия мы можем, исходя из информации о вашем устройстве, отправлять вам маркетинговую информацию посредством эл. почты, SMS или другими средствами, чтобы предоставлять или рекламировать наши собственные товары и услуги или товары и услуги третьих лиц.\nНаши товары и услуги, в частности, включают медиа-услуги онлайн, социальные сети, услуги по поиску в интернете, услуги местоположения и карты, программное обеспечение и услуги приложений, программное обеспечение и услуги по управлению данными, программы присуждения очков и наград, продукты-устройства, периферийные продукты трехмерной печати, а также прочие товары и услуги, которые, как мы считаем, могут иметь к вам отношение.\n2. Улучшение наших услуг\nМы можем использовать информацию, собранную посредством услуг Creality, к другим своим услугам. Например, ваши данные, собранные при использовании вами определенных услуг Creality, могут использоваться в других услугах Creality, чтобы предоставлять вам конкретное содержимое или демонстрировать относящуюся к вам информацию, а не отправлять сообщения на общую тему. Мы можем привлекать вас к участию в опросах, связанных с услугами Creality, которые помогут нам улучшать существующие услуги или разрабатывать новые; И Мы также можем использовать вашу информацию для обновления программного обеспечения.\nВы понимаете и соглашаетесь, что после сбора вашей информации мы можем обезличивать данные техническим способом, при этом по обезличенной информации установить вашу личность будет невозможно. В этом случае мы будем иметь право использовать обезличенную информацию для анализа базы данных пользователей и ее коммерческого использования. Если ваша информация будет использоваться для иных целей, не указанных в этой Политике конфиденциальности, мы заблаговременно запросим ваше согласие.\n3. За исключением получения разрешения. В соответствии с применимым законодательством и нормативно-правовыми актами ваше разрешение не требуется при сборе вашей информации при следующих обстоятельствах:\n(1) это связано с национальной безопасностью и национальной обороной;\n(2) это связано с общественной безопасностью, общественным здоровьем и основными общественными интересами;\n(3) это связано с уголовным расследованием, судебным преследованием, судебным разбирательством и исполнением судебных решений;\n(4) это предназначено для охраны существенных законных прав и интересов субъекта информации или других физических лиц, таких как жизнь и имущество, при этом получение вашего личного согласия является затруднительным;\n(5) вы сами раскрыли общественности собранную информацию;\n(6) сведения собраны на основе информации, на законных основаниях раскрытой общественности, такой как законные новостные сводки, раскрытие правительственной информации и прочие каналы;\n(7) информация необходима для подписания требуемых вами договоров;\n(8) информация необходима для поддержания безопасной и стабильной работы услуг Creality, например, поиск и устранение неполадок продуктов или услуг;\n(9) информация необходима для законных новостных сводок;\n(10) информация необходима научно-исследовательским учреждениям для проведения статистических или научных исследований, исходя из общественных интересов, а также, чтобы обезличивать информацию, содержащуюся в результатах, когда результаты научных исследований или описательные результаты раскрываются общественности; и\n(11) прочие обстоятельства, предусмотренные законодательством и нормативно-правовыми актами.\nIII. КАК МЫ СОХРАНЯЕМ, ХРАНИМ И ЗАЩИЩАЕМ ИНФОРМАЦИЮ\nМы сохраняем информацию настолько долго, насколько необходимо для достижения целей, описанных в этой Политике конфиденциальности, а также настолько долго, насколько требует законодательство и нормативно-правовые акты.\n1. Законодательством и нормативно-правовыми актами предусмотрены четкие положения;\n2. Получены ваше разрешение и согласие; и\n3. Службе Creality Cloud необходимо предоставлять личную информацию за границу, когда используемые вами продукты и услуги предполагают трансграничные действия. В таких случаях мы будем обеспечивать адекватную защиту вашей личной информации в соответствии с этой Политикой конфиденциальности и требованиями национального законодательства и нормативно-правовых актов.\nДля защиты вашей информации мы будем принимать следующие меры:\n(I) технические меры по обеспечению безопасности данных\nМы будем принимать эти охранные меры в соответствии с отраслевыми стандартами, включая принятие обоснованных институциональных норм и внеднение охранных технологий, чтобы не допустить несанкционированный доступ, использование и изменение вашей информации, а также, чтобы избежать ее повреждения и утери. Сетевыми службами применяются разные технологии шифрования, например, в некоторых службах мы внедрим тенологии шифрования (например, SSL), чтобы защитить вашу информацию, а помимо этого зашифруем, сохраним ее и применим технологии изоляции, чтобы изолировать информацию.\nМы внедрим целый спектр технологий снижения чувствительности данных, чтобы повысить уровень безопасности используемой информации, например, речь идет об отображении и расчете ассоциаций информации. Чтобы защитить информацию и не допустить незаконное использование данных, применяются строгий контроль доступа к информации и технологии нескольких проверок личности.\n(II) Другие принимаемые нами меры безопасности включают управление хранением и использованием информации и стандартизацию хранения и использования информации посредством учреждения системы классификации и сортировки данных, норм управления безопасностью данных и норм разработки безопасности данных.\nМы осуществляем комплексный контроль безопасности данных при помощи соглашения о конфиденциальности контакта с информацией, а также механизма мониторинга и корректировки. Мы повышаем осведомленность о вопросах безопасности. Помимо этого, мы проводим подготовительные курсы по вопросам защиты безопасности и конфиденциальности, чтобы улучшить осознание сотрудниками значения защиты информации.\n(III) Только сотрудникам Creality 3D, у которых есть служебная необходимость знать такую информацию, мы разрешаем получить доступ к вашей информации. В этом отношении мы наладили жесткие механизмы контроля доступа и механизмы мониторинга. При этом от всех сотрудников, у которых может быть доступ к вашей информации, мы требуем соблюдать соответствующие обязательства по конфиденциальности. Не соблюдение этих обязательств может привести к возникновению юридической ответственности или приостановке партнерства с компанией Creality 3D.\n(IV) Мы будем принимать все обоснованные и возможные меры для обеспечения того, чтобы никакая неуместная информация не собиралась.\n(V) Интернет не является абсолютно безопасной средой. Невозможно обеспечить полное шифрование таких методов обмена данными с другими пользователями, как эл. почта, мгновенные сообщения, программное обеспечение социальных сетей или программное обеспечение других служб. Таким образом, при использовании подобных инструментов мы рекомендуем устанавливать сложные пароли и делать все возможное для обеспечения охраны информации.\n(VI) Поскольку интернет-среда не безопасна на 100%, мы будем стараться обеспечивать или гарантировать безопасность какой-либо информации, которую вы нам присылаете. В случае повреждения физических, технических или управленческих средств защиты, приведшего к несанкционированному доступу, разглашению, изменению или уничтожению вашей информации, что повлечет возникновение вреда для ваших законных прав и интересов, мы будем нести соответствующую юридическую ответственность.\n(VII) Обработка инцидента нарушения безопасности\n(1) В процессе обмена информацией с третьими лицами или покупки товаров и услуг посредством служб Creality неизбежным является раскрытие вами информации о себе, такой как контактная информация или почтовый адрес, контрагентам или потенциальным контрагентам. Обеспечьте надлежащую защиту своей информации и предоставляйте ее другим лицам только при необходимости.\n(2) В ответ на потенциальные риски утечки, повреждения и утраты информации мы разработали несколько систем для разъяснения системы классификации и сортировки инцидентов нарушения безопасности и инцидентов уязвимости, а также соответствующие процедуры обработки. Помимо этого, мы создали специальную группу реагирования на инциденты нарушения безопасности, учредили планы обеспечения безопасности для различных инцидентов безопасности, как требуется нормами обработки инцидентов безопасности, перестали нести потери, проанализировали, локализовали и разработали исправительные меры, а также сотрудничаем с различными департаментами по отслеживанию и преодолению этих угроз. В случае возникновения какого-либо инцидента безопасности мы своевременно сообщим вам о нем, как требуется законодательством и нормативно-правовыми актами, включая общую ситуацию и возможные последствия инцидента безопасности, меры по обезвреживанию, которые мы приняли или примем, рекомендации для вас по профилактике и независимому снижению рисков, и исправительные меры, которые вы можете принять. Мы безотлагательно сообщим вам о ситуации, связанной с инцидентом, по электронной почте, телефону, посредством push-уведомления и т. д.; И Помимо этого, мы сделаем объявление обоснованным образом, когда окажется затруднительным сообщать субъектам информации по-одному. При этом, как требуется контролирующими органами, мы будем активно сообщать об обработке инцидентов безопасности информации.\n(3) Службы облачного хранения: Чтобы предоставлять службы облачного хранения (изображения, аудио и видео, которые вы загружаете в Creality Cloud, будут храниться в облаке и подобным образом), сторонние поставщики услуг могут собирать информацию о вашем устройстве, информацию, связанную с сетью, и информацию об операторе сети.\nЕсли в связи с вышеизложенным у вас возникли какие-либо вопросы, посетите веб-сайт www.crealitycloud.com/ в любое время, чтобы получить свою информацию, собранную и обработанную нами или сотрудничающими с нами третьими лицами.\nIV. ВАШИ ПРАВА НА СВОЮ ЛИЧНУЮ ИНФОРМАЦИЮ\nВ соответствии с законами и нормативно-правовыми актами страны или региона своего проживания вы имеете право запрашивать доступ, исправление и удаление какой-либо личной информации, которая у нас хранится и связана с вами (далее — «запрос»). Однако такие права подлежат конкретным исключениям в соответствии с применимым законодательством. На любой свой вопрос вы можете получить ответ по адресу cs@creality.com.\nЕсли вы не согласны с Политикой конфиденциальности, устройство не обеспечит функцию сетевого подключения.\nЕсли у вас возникнут вопросы о Политике конфиденциальности, без колебаний обратитесь к нам по адресу cs@creality.com — это официальный почтовый ящик.\n\n",\
    "Creality ürünlerini tercih ettiğiniz için teşekkür ederiz.\n\nShenzhen Creality 3D Technology Co., Ltd. (\"Creality 3D\", \"biz\", \"bize\", veya \"bizim\") Creality ürün ve hizmetlerini (bundan böyle \"Creality hizmetleri\" olarak anılacaktır) kullanan bu kullanıcıların (bundan sonra \"kullanıcılar\" veya \"siz\" olarak anılacaktır) gizliliğini koruma konusunda samimi bir taahhütte bulunur. Söz konusu Creality hizmetlerini kullanırken, sizin hakkınızda bilgi toplayabilir ve bu bilgileri hizmetlerimizde kullanabiliriz. Önemli olan, politikalarımızın periyodik olarak gözden geçirileceğini ve dolayısıyla ilgili önlemlerin değişikliğe uğrayabileceğidir. Bu nedenle, en son mevcut Gizlilik Politikası sürümünü sürekli olarak takip etmek için lütfen bu sayfayı düzenli olarak ziyaret ettiğinizden emin olun. Bu Gizlilik Politikası'nı inceledikten sonra, lütfen bu Gizlilik Politikası veya bu konuyla ilgili sorularınız veya endişelerinizle ilgili olarak bizimle cs@creality.com adresinden iletişime geçmekten çekinmeyin.\n\nI. HANGİ BİLGİLERİ TOPLARIZ?\n(I) Kişisel tanımlamayla ilgili olmayan bilgiler:\nCreality'nin hizmetlerini kullandığınızda, kullanıcının kökeni ve hizmetlere erişim sırası gibi bilgileri toplayabilir ve özetleyebiliriz. Bu, Creality hizmetlerini kullanan her kullanıcının kökenini kaydetmek de dahil olmak üzere kullanıcı hakkında bilgi toplama işlemidir.\n(II) Kişisel kimlik bilgileri hakkındaki bilgiler:\nCreality hizmetlerini kullandığınızda, kişisel telefon numaranızı ve ağ kimlik bilgilerinizi (sistem hesap numaranız, IP adresi, e-posta adresi ve ilgili şifreler, parolalar ve şifre koruma cevapları vb.) toplayabilir ve özetleyebiliriz. Aksi takdirde, bu bilgileri kendimiz isteyebilir ve toplayabiliriz.\n(1) Kişisel internet gezinti kayıtları ve günlük bilgileri (web sitesi gezinme geçmişi, yazılım kullanım kayıtları, tıklama kayıtları, işlem günlükleri vb.);\n(2) Cihaz bilgileri (cihaz modeli, cihaz MAC adresi, işletim sistemi türü ve cihaz ayarları dahil) ve yazılım listesi benzersiz cihaz tanımlama kodu (IMEI / android ID / IDFA / OPENUDID / GUID, SIM kart IMSI bilgileri ve yaygın olarak kullanılan kişisel cihazların temel durumunu tanımlayan diğer bilgiler dahil).\nSizinle ilgili bilgi toplama nedenimiz, Creality'nin sağladığı hizmetleri siz ve tüm diğer kullanıcılarımız için daha basit ve daha keyifli hale getirmek içindir. Creality Cloud'un misyonu, her internet kullanıcısının tarama deneyimini daha güvenli, daha etkileyici ve daha eğitici hale getirerek geliştirmektir; sunduğunuz bilgiler, bu hedefi gerçekleştirmemize yardımcı olacaktır.\nII. BİLGİLERİ NASIL TOPLAR VE KULLANIRIZ\n(I) Bilgileriniz örneğin aşağıdaki yöntemler aracılığıyla bizim tarafımızdan toplanacak ve edinilecektir:\n(1) Creality tarafından sağlanan hizmetlere kaydolurken veya kullanırken bize verdiğiniz bilgiler;\n(2) Creality hizmetlerini kullanırken tuttuğunuz bilgiler ve Creality hizmetlerini kullanırken diğer taraflarla paylaştığınız bilgiler; ve\n(3) Sizinle ilgili edindiğimiz bilgiler. Creality hizmetlerini kullandığınızda, günlükler ve cihazlarla ilgili bilgiler gibi diğer bilgi türlerini de içeren bilgileri toplayacak, özetleyecek ve kaydedeceğiz.\n(II) ÇEREZLER ve sunucu erişim günlükleri\nBiz veya üçüncü taraf ortaklarımız, bilginizi günlük bilgisi olarak saklayarak ve ÇEREZLER aracılığıyla elde ederek erişebilir ve kullanabilir. ÇEREZLER kullanarak, ağ içinde tüketicilere akıllı ve kişiselleştirilmiş bir deneyim sunabiliyoruz. ÇEREZLER, bir ağ sunucusundan bilgisayarınızdaki tarayıcıya aktarılan ve ardından o makinenin sabit diskinde kaydedilen küçük bir veri parçasına atıfta bulunur. ÇEREZLER kullanarak, sitemizin kullanıcılarına faydalar sağlıyoruz.\nÇEREZLER kullanımı, size daha iyi ve daha hızlı hizmet sunmamızı, ayrıca Creality hizmetlerinizle deneyiminizi özelleştirmemizi sağlar. Öte yandan, kullanmakta olduğunuz tarayıcının ÇEREZLERİ kabul etme şekli ve koşullarını yönetebilmeniz gerektiğine dikkat etmelisiniz. Bu konuda ek bilgiye ihtiyacınız varsa, lütfen tarayıcınızla birlikte verilen dosyalara bakın.\n(III) Bize ÇEREZ aracılığıyla verdiğiniz bilgileri toplama, kullanma ve buna göre depolama hakkımızı saklı tutuyoruz.\n(1) Kim olduğunuzu unutmayın. Örneğin; ÇEREZLER bize web sitemize kayıt olan bir kullanıcı olarak sizi tanıma ve tercihleriniz ve deneyiminizin diğer yönleri hakkında bize sunduğunuz bilgileri kaydetme imkanı verir;\n(2) Hizmetlerimizi nasıl kullandığınız konusunda analiz ederiz. Creality'nin hangi hizmetlerinin en popüler olduğunu veya bu hizmetleri kullanırken hangi etkinliklere katıldığınızı belirlemek için ÇEREZLER kullanmamız mümkündür;\n(3) Reklam optimizasyonu yaparız. ÇEREZLER, genel reklam kampanyaları yerine sunduğunuz bilgilere dayanarak size daha ilgili reklamlar sunmamızı sağlar.\nCreality hizmetleri, reklamverenler ve diğer ortaklar tarafından yerleştirilen ÇEREZLER içerebilir. Bu ÇEREZLER, kullanıcıların bu tür hizmetleri nasıl kullandıklarını incelemek, ilgilenebileceğiniz reklamları size sunmak veya reklam hizmetlerinin etkililiğini değerlendirmek için kullanılamayacak kişisel olarak tanımlanamayan bilgileriniz hakkında bilgi toplayabilir. Bu Gizlilik Politikası, bu tür bilgilerin üçüncü taraf tarafından ÇEREZLER aracılığıyla toplanması ve kullanılması için geçerli değildir; bunun yerine, bu toplama ve kullanım, üçüncü tarafın kendi kişisel bilgi koruma politikalarına tabidir; ve üçüncü tarafların ÇEREZLER'inden sorumlu değiliz.\nKullanıcı tercihi mekanizması veya bir tarayıcı kullanarak ÇEREZLER'i devre dışı bırakma veya ayarlama yeteneğine sahipsiniz. Ancak, ÇEREZLER'i devre dışı bırakmayı seçerseniz, en iyi hizmet deneyimini sunamayabiliriz ve hatta bazı hizmetler normal olarak çalışmayabilir.\n(IV) Sizin hakkınızda topladığımız bilgileri aşağıdaki şekillerde kullanacağız:\n1. Size mesaj gönderilmesi\nSize ürün veya hizmetleri gönderir ve gösteririz. Cihazınızdan topladığımız bilgilere, izninizle, aşağıdaki ürün ve hizmetleri sağlamak veya tanıtmak amacıyla e-posta, SMS veya diğer araçlarla pazarlama bilgileri göndermek için güvenebiliriz, bunlar bizim veya üçüncü tarafların mal ve hizmetleri olabilir:\nÜrün ve hizmetlerimiz, çevrimiçi medya hizmetleri, sosyal ağ hizmetleri, internet arama hizmetleri, konum ve harita hizmetleri, uygulama yazılımı ve hizmetleri, veri yönetimi yazılımı ve hizmetleri, puan ve ödül programları, cihaz ürünleri, 3D baskı yan ürünleri ve size ilgili olabileceğimizi düşündüğümüz diğer ürün ve hizmetlerden oluşur.\n2. Hizmetlerimizin kalitesini artırmak\nBelirli Creality hizmetlerinden elde edilen bilgileri, sunduğumuz diğer hizmetlerle birlikte kullanabiliriz. Size, mevcut hizmetleri iyileştirmek veya yeni hizmetler tasarlamak için Creativity hizmetleriyle ilgili anketlerde yer almanızı isteyebiliriz; aynı zamanda, bilgilerinizi yazılım güncellemeleri için kullanabiliriz. Örneğin, belirli Creativity hizmetlerini kullanırken topladığınız bilgiler, size özel içerik sağlamak veya size genel olarak göstermek yerine sizi ilgilendiren bilgileri göstermek için başka bir Creativity hizmetinde kullanılabilir.\nBilgilerinizi topladıktan sonra, teknik yöntemlerle verileri tanımlanamaz hale getirebileceğimizi ve tanımlanamaz hale getirilmiş bilgilerin kimliğinizi tespit etmeye yardımcı olmayacağını anlıyor ve kabul ediyorsunuz. Bu durumda, tanımlanamayan bilgileri kullanarak kullanıcı veritabanını analiz etmeye ve bunu ticari amaçlarla kullanmaya hak kazanıyoruz. Bu Gizlilik Politikası'nda ayrıntılı olarak açıklanmayan herhangi bir nedenle bilgileriniz kullanılırsa, önceden bildirileceksiniz ve izniniz istenecektir.\n3. Yetkilendirilme istisnası ile. Geçerli kurallar ve yönetmeliklere uygun olarak, bilgilerinizi toplamadan önce izin almak, aşağıdaki durumlarda gerekli değildir:\n(1) Bu, ülkenin güvenliği ve savunması ile ilgili herhangi bir şeyle ilgilidir;\n(2) Hem güvenlik ve sağlık açısından halkın refahı ile hem de hayati kamu çıkarları ile bağlantılıdır;\n(3) Ceza soruşturmaları, kovuşturmaları, davaları ve cezaların infazı ile ilgilidir;\n(4) Bilgi toplama amaçları, bilgi konusu veya diğer kişilerin hayatı ve malı gibi önemli meşru hak ve çıkarlarını korumak amacıyla kişisel rızanızı almak mümkün değildir, ancak bilgi toplamak için yapılmaktadır;\n(5) Elde edilen bilgi, kendiniz tarafından genel kamuoyuna açık hale getirilmiştir;\n(6) Bilgi, yasal olarak kamuoyuna açık olabilen kaynaklardan elde edilmiştir, örneğin saygın haber raporları, hükümet tarafından yayınlanan bilgiler ve diğer kanallar;\n(7) Sizin gereksinimlerinize uygun sözleşmelerin imzalanması için önemlidir;\n(8) Creality'nin hizmetlerinin güvenli ve güvenilir şekilde devam ettirilmesi için önemlidir ve ortaya çıkabilecek herhangi bir ürün veya hizmet hatasının belirlenmesi ve çözülmesi için gereklidir;\n(9) Güvenilir haberlerin yayılması için önemlidir;\n(10) Kamu yararı için istatistiksel veya akademik araştırmalar yapmak akademik araştırma kurumları için önemlidir ve bu kurumlar, halka akademik araştırma veya tanımlayıcı veri sağladıklarında sonuçlarda yer alan bilgilerin kimliksizleştirilmesi gereklidir;\n(11) Kanun ve yönetmeliklere göre karşılanması gereken ek koşullar bulunmaktadır.\nIII. SAHİP OLDUĞUMUZ BİLGİLERİ NASIL KORUYOR, SAKLIYOR VE GÜVENLİĞİNİ SAĞLIYORUZ?\nSadece bu Gizlilik Politikasında belirtilen amaçları yerine getirmek için ve geçerli kanun ve yönetmelikler tarafından zorunlu kılınan en kısa süre boyunca bilgilerinizi saklayacağız.\n1. Kanun ve yönetmeliklerde belirtilen belirli gereksinimler bulunmaktadır;\n2. Şu anda hem izninize hem de onayınıza sahibiz; ve\n3. Uluslararası işlemleri içeren ürün veya hizmetleri kullandığınızda, Creality Cloud, kişisel olarak tanımlanabilir bilgilerinizi ikamet ettiğiniz ülke dışındaki bir yere göndermek zorundadır. Bu koşullarda, kişisel bilgilerin korunmasını bu Politika ve ilgili ulusal yasalara uygun olarak sağlamak için gerekli önlemleri alacağız.\nBilgilerinizin güvenliği için aşağıdaki önlemleri alacağız:\n(I) Veriler için uygun teknik koruma önlemleri uygulama\nBu güvenlik önlemlerini sektör için belirlenmiş standartlara uygun olarak uygulayacağız. Bu önlemler, bilginizin yasadışı erişim, kullanım ve değiştirilmesini önlemek ve veri hasarını veya kaybını önlemek amacıyla uygun kurumsal normlar ve güvenlik teknolojilerinin kurulmasını içerecektir. Ağ hizmetleri geniş bir şifreleme teknolojisi yelpazesinden yararlanır; örneğin, belirli hizmetlerde, bilginizi korumak, şifrelemek ve kaydetmek için şifreleme teknolojilerini (örneğin SSL gibi) kullanacağız ve izolasyon teknolojilerini uygulayacağız.\nKullanılan bilginin güvenliğini artırmak için bilgi sunumu ve bilgi ilişkilendirme hesaplaması gibi çeşitli veri hassasiyeti azaltma teknolojileri uygulayacağız. Verilerin izinsiz kullanımını önlemek ve bilgi bütünlüğünü korumak için sıkı veri erişim kontrolleri ve çoklu kimlik doğrulama teknolojileri uygulanmaktadır.\n(II) Bilgilerin depolanmasını ve kullanımını yönetmek ve standartlaştırmak için, veri kategorizasyonu ve sınıflandırma sistemi, veri güvenliği yönetim normları ve veri güvenliği geliştirme normları gibi önemli güvenlik önlemleri alıyoruz.\nVeri iletişim gizlilik sözleşmesi, izleme ve denetim mekanizması ile veri üzerinde kapsamlı bir güvenlik kontrolü gerçekleştiriyoruz.  Güvenlik konusunda farkındalığını artırmak için çalışıyoruz. Bunun yanı sıra, çalışanlarımıza güvenlik ve gizlilik koruması eğitimi vererek, bilgi koruma değerinin önemini anlamalarını sağlıyoruz.\n(III) Sadece bu bilgiye ihtiyaç duyan Creality 3D çalışanlarına bilginize erişim izni veriyor ve bu konuda sıkı erişim kontrolü ve izleme mekanizmaları kuruyoruz. Bu arada, bilgilerinize erişebilecek her personelin, ilgili görevleriyle birlikte gizlilik görevlerini yerine getirmesi gerektiği bir zorunluluk haline getirdik. Bu görevler yerine getirilmediği takdirde, Creality 3D ile olan ilişki sonlandırılabilir veya sorumlu kişiye karşı yasal işlem başlatılabilir.\n(IV) Her türlü önlemi alarak gereksiz bilgi toplamamanızı sağlayacağız.\n(V) E-posta, anlık mesajlaşma, sosyal ağ yazılımı veya diğer hizmet yazılımları ile diğer kullanıcılarla olan iletişim yöntemlerinin tamamen şifrelenip şifrelenmediği belirlenemez. Bu nedenle, bu araçları kullanırken karmaşık şifreler belirlemenizi ve bilgi güvenliğini garanti altına almak için her türlü çabayı göstermenizi öneririz. (V) İnternet tamamen güvenli bir ortam sunmamaktadır.\n(VI) İnternet ortamı tamamen güvenli olmadığından, bize verdiğiniz herhangi bir bilginin güvenliğini sağlamak veya garanti etmek için elimizden geleni yapacağız.  Fiziksel, teknik veya yönetim koruma tesislerimizin ihlal edilmesi sonucu yetkisiz erişim, açık bir şekilde ortaya çıkarma, oynama veya bilgilerinizin yok edilmesi ve daha da ileri giderek haklı haklarınız ve çıkarlarınıza zarar verilmesi durumunda, ihlalin derecesine orantılı olarak yasal sorumlulukları üstleneceğiz.\n(VII) Güvenlik olaylarının yönetimi\n(1) Creality hizmetlerini kullanarak üçüncü taraflarla iletişim kurarken veya ürün ve hizmetlerin satın alınması sürecinde karşı taraflara veya potansiyel karşı taraflara kendinizle ilgili bilgiler sunmanız kaçınılmaz olabilir. Bu bilgiler, örneğin iletişim bilgileri veya posta adresi içerebilir. Lütfen bilgilerinizi yeterince koruduğunuzdan emin olun ve sadece mutlaka gerekli olduğunda başkalarıyla paylaşın.\n(2) Bilgi sızıntısı, zarar görmesi veya kaybolması gibi potansiyel tehlikelere karşı yanıt olarak, güvenlik olayları ve zayıflıklar için sınıflandırma ve derecelendirme standartlarını açıklamak üzere birkaç sistem oluşturduk ve bunlarla birlikte işleme süreçlerini açıkladık. Bu, potansiyel tehditlerin etkilerini azaltmak amacıyla yapıldı. Ayrıca, güvenlik olaylarının yönetimini amaçlayan özel bir acil durum müdahale ekibi kurduk, güvenlik olaylarının yönetimine ilişkin normlara uygun olarak çeşitli güvenlik olaylarına yönelik güvenlik planları geliştirmeye başladık, kayıpları durdurduk, soruşturma yaptık, yerini tespit ettik ve düzeltici önlemler geliştirdik, ayrıca ilgili departmanlarla işbirliği yaparak sorunu takip ettik ve mücadele ettik. Olumsuz bir bilgi güvenliği olayı meydana gelirse, yasal düzenlemeler dahilinde gerekli şekilde size bilgi vereceğiz; güvenlik olayının temel durumu ve olası etkisi, aldığımız veya alacağımız önlemler, riskleri önlemek ve azaltmak için size öneriler ve size yönelik düzeltici önlemler de dahil olmak üzere. Olumsuz bir bilgi güvenliği olayı meydana gelirse, temel durum ve olası etkisi de dahil olmak üzere sizi zamanında bilgilendireceğiz. Olaya ilişkin durumu posta, mektup, telefon, push bildirimleri vb. yöntemlerden herhangi birini kullanarak size hızlı bir şekilde ileteceğiz; bilgi sahibini tek tek bilgilendirmek zor olduğunda, makul ve etkili bir yöntem kullanarak bir duyuru yapacağız. Bu arada, düzenleyici otoritelerin gereksinimleri doğrultusunda, herhangi bir bilgi güvenliği sorunu nasıl ele aldığımızı proaktif bir şekilde yayınlayacağız.\n(3) Bulut depolama hizmetleri: Üçüncü taraf hizmet sağlayıcıları, size bulut depolama hizmetleri sunmak için cihazınızla ilgili bilgileri, ağınızla ilgili bilgileri ve operatörünüzle ilgili bilgileri toplayabilirler (Creality Cloud'a yüklediğiniz fotoğraflar, ses ve video içerikleri bulutta saklanır ve ilgili senaryolara yönelik işlemler yapılır).\nİstediğiniz zaman www.crealitycloud.com/ adresine giderek, bizim veya iş birliği yaptığımız üçüncü taraflar tarafından toplanan ve işlenen bilgilerinizi alabilirsiniz. Yukarıda sunulan bilgilerle ilgili herhangi bir sorunuz varsa, buraya tıklayarak bize ulaşabilirsiniz.\nIV. KİŞİSEL BİLGİLERİNİZLE İLGİLİ HAKLARINIZ\nSizinle ilgili tuttuğumuz kişisel bilgilere ilişkin erişim, düzeltme veya silme talebinde bulunma hukuki hakkına sahipsiniz (bundan böyle \"talep\" olarak anılacaktır). Bu hak, bulunduğunuz ülke veya bölgenin yasaları ve düzenlemeleri tarafından size verilmiştir. Ancak, ilgili yasalara uygun olarak belirli sınırlamalar ve istisnalar olacaktır. Ayrıca, herhangi bir sorunuz varsa, cs@creality.com adresine gönderebilirsiniz.\nBu Gizlilik Politikası'nın şartlarını kabul etmezseniz, cihaz ağ işlevselliği sağlamayacaktır.\nBu Gizlilik Politikası ile ilgili herhangi bir sorunuz veya yorumunuz varsa, şirketin resmi posta kutusu olan cs@creality.com adresine e-posta göndermekten çekinmeyin.\n\n",\
    "Crealityの製品を購買し使用して頂き、ありがとうございます！\n\nShenzhen Creality 3D Technology Co., Ltd.は、Creality製品とサービス（これから「Crealityサービス」と総称する）を使用するユーザー（これから「ユーザー」又は「あなた」と総称する）のプライバシーを保護することを厳粛に承諾します。あなたがCrealityサービスを利用する際に、我々はユーザーの関連情報を収集・利用することがあります。我々が、我々のポリシーをたびたび確認するので、関連措置がそれに伴って変わることに注意してください。我々は、あなたに、当該ページに定期的にアクセスすることによって、我々の「プライバシーポリシー」の最新バージョンをずっと了解するように勧めます。本ポリシーを読んだ後、本ポリシー及び本ポリシー関連事項について如何なる質問を持つ場合、cs@creality.comに連絡してください。\n\n一、我々が収集する可能性がある情報\n（一）身分に無関係な情報：\nあなたが我々のサービスを使用する際に、我々は、ユーザーの源経路とアクセス順序等の情報を収集してまとめる可能性があります。例えば、Crealityサービスを使用する各ユーザーの源経路を記録すること等。\n（二）身分に係る情報：\nあなたが我々のサービスを使用する際に、我々は、あなたの電話番号を収集してまとめるか、又はあなたに電話番号を提供するように要求する可能性があります。それに加えて、ネットワーク識別情報システムアカウント、IPアドレス、電子メールアドレス及び前記関連パスワード、暗号と暗号保護答案等）も収集してまもめます。\n（1）個人のインターネット利用記録と日誌情報（webブラウジング記録、ソフトウェア使用記録、クリック記録と操作日誌等を含みます）。\n（2）設備情報（ 設備モデル、設備MACアドレス、オペレーティング システムのタイプと設備設定を含みます）。ソフトウェアリストのユニーク ID識別コード（例えば、IMEI/android ID/IDFA/OPENUDID/GUIDとSIMカードIMSI情報を含む、よく使われる個人設備の基本状況関連情報）。\n我々があなたの情報を収集する主な目的は、あなたとその他のユーザーが、Crealityサービスを一層容易に且つ満足的に使用する為です創想雲の目標は、すべてのインターネットユーザーに、安全的で面白いインターネット利用経歴及び有益な教えのあるインターネット利用経歴を提供することです。もう一方で、これらの情報は、我々によるこの目標の実現に役立ちます。\n二、我々が如何なる情報を収集・使用しますか？\n（一）我々は、下記の経路であなたの情報を収集・取得します。例えば、\n（1）あなたがCrealityサービスのアカウントに登録したり、又はCrealityサービスを使用する時に我々に提供する情報。\n（2）あなたがCrealityサービスを通じて第三者に提供する共有情報、及びあなたがCrealityサービスを使用する時に貯蔵する情報。\n（3）我々が取得するあなたの情報。（4）あなたがCrealityサービスを使用する時に、我々が収集し、まとめ、記録する情報、例えば、日誌情報と設備情報等。\n（二）COOKIESと日誌アーカイブ\n我々又は我々の第三者の協力パートナーは、COOKIESを通じてあなたの情報を取得して使用し、且つ、これらの情報を日誌情報に貯蔵します。COOKIESを使用することによって、我々は、ユーザーに、簡単で実行し易く、且つ、個性化に富むネットワーク体験を提供します。一つのCOOKIESが小量なデータであり、これらが、一つのネットワークサーバーから、あなたのブラウザーに送られた後、コンピューターのハードディスクに貯蔵されます。我々は、ユーザーに利益を受けらせる為に、COOKIESを使用します。\nCOOKIESを使用することによって、我々は、あなたに一層良く且つ一層速くサービスを提供し、且つ、COOKIESに関するあなたの経歴を一層個性化します。しかしながら，あなたは、COOKIESがあなたのブラウザーにより受けいられるかどうか、及びどのように受けられるか制御できなければなりません。あなたのブラウザーの添付文書を調べて、この面の一層多い情報を取得してください。\n（三）我々は、COOKIEを通じてあなたの情報を収集して使用し、且つ、これらの情報に貯蔵する可能性があります。\n（1）あなたの身分を覚えます。例えば、COOKIESは、我々が、我々の登録ユーザーの身分とするあなたの身分を認識するか、又はあなたが我々に提供するあなたの好み又はその他の情報を保存することに役立ちます。\n（2）あなたが我々のサービスを使用する状況を分析します。我々は、COOKIESを使用して、あなたがCrealityサービスを使用してどれらの活動を行うか、又はどんなサービスが一番人気を有するか了解することができます。\n（3）広告最適化。COOKIESは、我々があなたの情報によって、あなたに、普遍的な広告を投入する代わりに、あなたに係る広告を提供することに役立ちます。\nCrealityサービスに、広告代理店及びその他の協力側が投入したCOOKIESがある可能性があります。これらのCOOKIESは、あなたに係る非身分情報を収集することによって、ユーザーがこれらのサービスをどのように使用するか分析し、又はあなたに興味を持つ可能性がある広告を送り、又は広告サービスの効果を評価します。これらの第三者COOKIESによる当該情報の収集と使用は、本「プライバシーポリシー」により制約されません。その代わりに、自身の個人情報保護声明から約束を受けるので、我々は、第三者のCOOKIESに対して責任を負いません。\nあなたは、ブラウザー又はユーザー選択の仕組みを通じて、COOKIESを拒否したり、又は管理したりすることができます。但し、あなたは、COOKIESの使用を中止すると、我々はあなたに一番良いサービスを提供できず、且つ、一部のサービスを正常に使用できなくなる可能性があることに注意してください。\n（四）我々は、下記の目的の為に、あなたの情報を収集・使用する可能性があります。\n1、 あなたへのメッセージのプッシュ\nあなたに商品又はサービスを展示してプッシュすること。あなたから同意を得て、我々は、あなたの設備情報を使用して、電子メール、SMS（ショートメール・ショートメッセージ）又はその他の方式であなたにマーケッティング情報を送り、且つ、我々又は第三者の下記の商品又はサービスを提供したり、又は押し広めたりする可能性があります。\n我々の商品とサービスは、下記を含むが、これらに限りません。ネットワークメディア・サービス、社交ネットワーク・サービス、インターネット検索サービス、位置と地図サービス、アプリケーション・ソフトウェアとサービス、データ管理ソフトウェアとサービス、得点と奨励計画、設備商品、3D印刷周辺商品及び我々が、あなたに係ると考えるその他の商品とサービス。\n2、我々のサービスの改善。\n我々は、あるCrealityサービスで収集する情報を通じて、我々のその他のサービスに使用する可能性があります。例えば、あなたがあるCrealityサービスを使用する時に収集したあなたの情報を利用して、その他のCrealityサービスにおいて、普遍的な情報をプッシュする代わりに、あなたに特定な内容を提供するか、又はあなたに係る情報を提供する可能性があります。我々は、あなたに、Crealityサービスの調査に参加させて、我々に協力して現存サービスの改善又は新しいサービスの設計に役立つするようにする可能性があります。これと同時に、我々は、あなたの情報をソフトウェアの更新に使用する可能性があります。\nあなたが了解すべきなこととしては、あなたの情報を収集した後、我々が、技術手段を利用して標識除去処理を行い、且つ、標識除去処理後に、あなたの身分を識別できず、この状況の下で、我々が、標識除去処理済み情報を利用して、ユーザーのデータベースを分析し、且つ、商業的な利用を行う権利を持つことです。我々は、あなたの情報を、本「プライバシーポリシー」に記載されていないその他の用途に使用する場合、予めあなたから同意を求めます。\n3、権限付与と同意を取得することを除いて、関連法律法規に基づき、下記の状況の下で、あなたから権限付与と同意を取得せずにあなたの情報を収集することができます。\n（1）国家安全及び国外に係る場合。\n（2）公共安全、公共衛生及び重大な利益に係る場合。\n（3）犯罪探偵、起訴、裁判及び判決の執行に係る場合。\n（4）情報主体又はその他の個人の生命及び財産等の重大な合法的権益を維持する為にそう実施するが、あなた本人から同意を取得し難い場合。\n（5）収集する情報が、あなたが自分で社会公衆に公開したものである場合。\n（6）合法的なニュース報道と政府情報開会等のチャンネルを含む合法に且つ公開に開示された情報から情報を収集する場合。\n（7）あなたの要求によって契約を締結する為に必要である場合。\n（8）Crealityサービスの安全的且つ安定的な運行を維持する為に必要である場合（例えば、製品又はサービスの故障を発見して処置する場合）。\n（9）合法的なニュース報道に必要である場合。\n（10）学術研究機構が公共利益に基づいて統計又は学術研究を行う為に必要で、且つ、外部に学術研究又は説明結果を提供する時に、結果に含まれている情報に対して標識除去処理を行う場合。\n（7）法律と法規で規定されているその他の状況。\n三、我々は、情報をどのように保留し、貯蔵し保護しますか？\n我々は、「本ポリシー」の前記目的の必要な期間及び法律法規で要求される時限内にあなたの情報を保留します。\n1、法律法規で明確に規定されている場合。\n2、あなたから権限付与と同意を取得した場合。\n3、あなたが使用する製品とサービスが国際業務に係り、創想雲が、国外にあなたの個人情報を提供する必要がある場合。以上の状況に対して、我々は、本ポリシー及び国家法律法規要求に基づいて、あなたの個人情報を十分に保護することを確保します。\n我々は、下記の手段であなたの情報を保護します。\n（一）データの安全技術措置\n我々は、業界の標準的な安全保護措置を採用します。その中で、合理的な制度・規範と安全技術を作り上げてあなたの情報に対する未授権アクセスと使用及び修正を防止し、データの損壊と紛失を避けます。ネットワークサービスに多種の暗号化技術を採用します。例えば、一部のサービスにおいて、我々は、暗号化技術（例えば、SSL）を利用してあなたの情報を保護し、即ち、暗号化技術を採用してあなたの情報に対して暗号化保存を行い、且つ、隔離技術で隔離を行うこと。\n情報使用プロセス中において（例えば、情報展示と情報関連計算に置いて）、我々は、多種のデータ非特定化技術を使用して、使用中における情報の安全性を強化します。厳格なデータ・アクセス権限制御と多重身分認証技術を採用して情報を保護してデータの規則違反使用を避けること。\n（二）我々が情報を保護する為に講じるその他の安全措置我々は、データ分類等級制度、データ安全管理規範とデータ安全開発規範を作り上げて、規範情報の貯蔵と使用を管理すること。\n我々は、情報接触者の機密保持契約書、監視を行うこと。安全意識を強化すること。我々も、安全とプライバシー保護関連トレーニングコースを行うことによって、従業員の情報保護重要性に対する認識を強化すること。\n（三）我々は、これらの情報を了解する必要のあるCreality 3D従業員によるあなたの情報へのアクセスだけを許可し、且つ、この為に厳格なアクセス権限制御と監視の仕組みを設定すること。これと同時に、我々は、あなたの情報に接触する可能性のあるすべての人員に対して、相応な機密保持義務を履行するように要求すること。これらの義務を履行できない場合、法的責任を追及するか、又はCreality 3Dとの協力関係を中止するか可能性があります。\n（四）我々は、一切の合理的で実行可能な措置を講じることによって、無関係な情報を収集しないことを確保すること。\n（五）インターネットが絶対的に安全的な環境ではなく、且つ、電子メール、即時通信、社交ソフトウェア又はその他のサービスソフトウェア等を含む、その他のユーザーとの交流方式が完全に暗号化されているか確定できないので、我々は、このようなツールを使用するか時に複雑なパスワードを使用し、且つ、あなたの情報安全保護に注意するように勧めること。\n（六）インターネット環境が百パーセントの安全性を確保できないので、我々は力を尽くして、あなたが我々に送るすべての情報の安全性を確保・担保すること。我々の物理的、技術的、又は管理的な防護施設が破壊された為、情報の非授権アクセス、公開的な開示、改竄又は損壊が発生して、あなたの合法的な権益が損害された場合、我々は、相応な法的責任を負うこと。\n（七）安全事件の処置\n（1）Crealityサービスを通じて第三者とコミュニケーションを行うか、又は商品及びサービスを購入する時に、あなたは、不可避的に取引相手又は潜在的な取引相手に自分の情報を開示します（例えば、連絡方式又はポストアドレス等）。あなたは、自分の情報を妥当的に保護して、必要な状況だけで他人に提供すること。\n（2）情報漏洩、損壊及び紛失などの発生可能なリスクに応対する為に、多項目の制度を制定して、安全面事故とセキュリティーホールの分類・等級分け基準及び相応な処理フローを明確にすること。我々も安全面事件の為に専門的な応急処置チームを作り上げて、安全面事件処置規範の要求に基づいて、異なる安全面事件に対して、安全予備案を起動して、ストップロス、分析、位置決めと救済措置設定を行い、且つ、関連部門と協力して遡及及び打撃を行うこと。不幸で安全面事件が発生した後、我々は、法律法規の要求に基づいて、あなたに適時に下記事項を通知すること。安全面事件の基本状況及び可能な影響、我々が講じた又はすぐ講じる処置措置、あなたが自主的に安全警備を行ってリスクを低減する為の建議及びあなたに対する救済措置など。これと同時に、我々は、事件の関連状況を、電子メール、郵便物、電話とプッシュ通知等の方式であんたに通知を行います。情報主体に一つ一つ通知し難い場合、我々は、合理的且つ有効的な方式で公告を発布すること。これと同時に、我々は、監査部門の要求によって、情報の安全面事件の処置状況を積極的に報告すること。\n(3)クラウドストレージ・サービス：あなたにクラウドストレージ・サービスを提供する為に（あなたが創想雲にアップロードする写真とオーディオ ・ ビデオ内容がクラウド端末及び関連シナリオに貯蔵される可能性があります）、第三者サービス・プロバイダーは、あなたの設備情報、ネットワーク関連情報と運営業者情報を収集する可能性があります。\nあなたは、以上に対して如何なる質問を持つと、いつもwww.crealitycloud.com/にアクセスして、我々又は我々の第三者の協力パートナーが収集して処理しているあなたの情報を取得することができます。\n四、あなたが、あなたの個人情報に享有する権利\nあなたが適用する国家と地区の法律法規によって、あなたは、我々が保有しているあなた関連如何なる個人情報に対するアクセス、修正と削除（これから請求と略称する）を要求する権利を持つものとする。これらの権利は、適用法律法規に規定されている特定な排除と例外状況から制限を受けます。あなたの如何なる問題について、 cs@creality.com電子メールを通じて我々に連絡してください。\nあなたは、プライバシーポリシーに同意しない場合、設備はネットワーク機能を提供しません。\nあなたは、本プライバシー政策に対して、如何なる疑問又は建議を持つ場合、公式電子メール cs@creality.com電子メールを通じて我々に連絡してください。\n\n"
};

const char *Reconsider[MAX_LANGUAGE] = {
    "再想想",\
    "Reconsider",\
    "Überprüfen",\
    "Reconsiderar",\
    "Reconsidérez",\
    "Riconsiderare",\
    "Reconsiderar",\
    "Передумать",\
    "Yeniden değerlendir",\
    "考え直し",\
};

const char *LookOver[MAX_LANGUAGE] = {
    "查看",\
    "View",\
    "Anzeigen",\
    "Ver",\
    "Voir",\
    "Visualizza",\
    "Ver",\
    "Просмотр",\
    "Görüntüle",\
    "見る",\
};

const char *DeviceMachine[MAX_LANGUAGE] = { \
    "设备绑定",\
    "Creality Cloud binding",\
    "Creality Cloud-Bindung",\
    "Vinculación con Creality Cloud",\
    "Liaison Creality Cloud",\
    "Associazione Creality Cloud",\
    "Vinculação à Creality Cloud",\
    "Привязка Creality Cloud",\
    "Creality Cloud'a bağlama",\
    "デバイスのバインディング",\
};

const char *UploadErrorTips[MAX_LANGUAGE] = { \
    "请用创想云APP扫描", \
    "Please scan with the Creality Cloud App", \
    "Bitte scannen Sie mit der Creality Cloud", \
    "Escanéelo con la aplicación de Creality Cloud", \
    "Veuillez numériser avec l'application Creality Cloud", \
    "Effettua la scansione con l'app Creality Cloud", \
    "Escaneie com o Aplicativo Creality Cloud", \
    "Отканируйте с помощью приложения Creality Cloud", \
    "Lütfen Creality Cloud Uygulaması ile tarayın", \
    "Creality Cloudアプリでスキャンしてください"
};

const char *Area[MAX_LANGUAGE] = { \
    "区域", \
    "Area", \
    "Bereich", \
    "Zona", \
    "Zone d'activité", \
    "Area", \
    "Área", \
    "Область", \
    "Alan", \
    "地域",
};

const char *AreaChinese[MAX_LANGUAGE] = { \
    "中国大陆", \
    "Mainland China", \
    "Festland China", \
    "China continental", \
    "Chine continentale", \
    "Cina continentale", \
    "China Continental", \
    "Континентальный Китай", \
    "Çin Anakarası", \
    "中国大陸部"
};

const char *AreaOthers[MAX_LANGUAGE] = { \
    "国际", \
    "International", \
    "International", \
    "Internacional", \
    "International", \
    "Internazionale", \
    "Internacional", \
    "Международный", \
    "Uluslararası", \
    "国際"
};

const char *UploadErrorTips1[MAX_LANGUAGE] = { \
    "上报",\
    "Report",\
    "Bericht",\
    "Informe",\
    "Rapport",\
    "Rapporto",\
    "Relatório",\
    "Отчет",\
    "Rapor",\
    "レポート",
};

const char *UploadErrorTips2[MAX_LANGUAGE] = { \
    "故障上报",\
    "Fault reporting",\
    "Fehler melden",\
    "Informe de error",\
    "Rapport d'erreur",\
    "Segnalazione guasti",\
    "Relatório de erro",\
    "Отчет об ошибках",\
    "Arıza raporlama",\
    "故障の報告",\
};

const char *UploadErrorresult[MAX_LANGUAGE] = { \
    "故障上报成功！",\
    "Fault reported successfully!",\
    "Fehler erfolgreich gemeldet!",\
    "¡Se ha informado del error correctamente!",\
    "Défaut signalé avec succès !",\
    "Guasto segnalato correttamente!",\
    "Falha relatada com sucesso!",\
    "Сбой успешно зарегистрирован!",\
    "Arıza başarıyla raporlandı!",\
    "障害報告に成功しました",\
};

const char *UploadErrorTips3[MAX_LANGUAGE] = { \
    "请拍照留存", \
    "Please take photos for your records", \
    "Bitte machen Sie Fotos für Ihre Aufzeichnungen", \
    "Tome fotos para sus registros", \
    "Veuillez prendre des photos pour vos archives", \
    "Scatta foto per i tuoi record", \
    "Tire fotos para seus registros", \
    "Сделайте фото для Ваших записей", \
    "Lütfen kayıtlarınız için fotoğraf çekin", \
    "記録用に写真を撮ってください"
};

const char *UploadErrorTips4[MAX_LANGUAGE] = { \
    "工单号:", \
    "Work Order No:", \
    "Arbeitsauftrag Nr:", \
    "No. de orden de trabajo:", \
    "N° de l'ordre de travail", \
    "N. ordine di lavoro", \
    "Ordem de Serviço Nº", \
    "Рабочий заказ №", \
    "İş Sıra No.", \
    "ワークオーダー番号"
};

const char *UploadErrorTips5[MAX_LANGUAGE] = { \
    "客服邮箱:cs@creality.com", \
    "Support E-mail:cs@creality.com", \
    "Kundendienst E-Mail:cs@creality.com", \
    "Correo elecxtrónico de atención al cliente:cs@creality.com", \
    "E-mail du service clientèle:cs@creality.com", \
    "E-mail del Servizio clienti:cs@creality.com",\
    "E-mail do Atendimento ao Cliente:cs@creality.com", \
    "Эл. почта клиентской службы:cs@creality.com", \
    "Müşteri Hizmetleri E-maili:cs@creality.com", \
    "カスタマーサービスメール:cs@creality.com", 
};

const char *SelftestCompletedTips[MAX_LANGUAGE] = { \
    "自检已完成", \
    "Self-test completed", \
    "Die Selbstprüfung ist abgeschlossen", \
    "Autotesteo finalizado", \
    "Autocontrôle achevé", \
    "Auto-test completato", \
    "Autoteste concluído", \
    "Самопроверка выполнена", \
    "Kendiliğinden test tamamlandı", \
    "セルフチェツク完了済"
};

const char *WikiTips[MAX_LANGUAGE] = { \
    "请使用手机扫码查看在线说明书", \
    "Please use your smart phone to scan the code to view the online manual", \
    "Bitte verwenden Sie Ihr Smartphone, um den Code zu scannen und das Online-Handbuch anzuzeigen", \
    "Use el smartphone para escanear el código para ver el manual online", \
    "Veuillez utiliser votre smartphone pour scanner le code afin de consulter le manuel en ligne", \
    "Utilizzare il telefono cellulare per eseguire la scansione del codice e visualizzare il manuale online", \
    "Por favor, use seu smartphone para escanear o código para visualizar o manual online", \
    "Посредством смартфона сканируйте код, чтобы просмотреть онлайн-руководство", \
    "Çevrimiçi kılavuzu görüntülemek için lütfen akıllı telefonunuzu kullanarak kodu tarayın", \
    "携帯電話でコードをスキャンして、オンライン取扱説明書をご覧ください。"
};

const char *FaqTips[MAX_LANGUAGE] = { \
    "请使用手机扫码查询常见问题解答", \
    "Please use your smart phone to scan the code for FAQs", \
    "Bitte verwenden Sie Ihr Smartphone, um den Code für HÄUFIGE FRAGEN zu scannen", \
    "Use el smartphone para escanear el código para ver las preguntas frecuentes", \
    "Veuillez utiliser votre smartphone pour scanner le code pour les FAQs", \
    "Utilizzare il telefono cellulare per eseguire la scansione del codice e visualizzare le domande frequenti", \
    "Por favor, use seu smartphone para escanear o código para consultar o FAQ", \
    "Посредством смартфона сканируйте код, чтобы ознакомиться с часто задаваемыми вопросами", \
    "Sık Sorulan Sorular için lütfen akıllı telefonunuzu kullanarak kodu tarayın", \
    "携帯電話からFAQのコードを読み取ってください。"
};
/*********************boot*****************************/

/**********************common *************************/
const char *HotendInputRangle[MAX_LANGUAGE] = { \
    "可输入范围",\
    "Input range",\
    "Eingabebereich",\
    "Alcance de entrada",\
    "Plage d'entrée",\
    "Intervallo di ingresso",\
    "Intervalo de entrada",\
    "Диапазон ввода",\
    "Giriş aralığı",\
    "入力範囲",\
};
const char *BedInputRangle[MAX_LANGUAGE] = { \
    "可输入范围",\
    "Input range",\
    "Eingabebereich",\
    "Alcance de entrada",\
    "Plage d'entrée",\
    "Intervallo di ingresso",\
    "Intervalo de entrada",\
    "Диапазон ввода",\
    "Giriş aralığı",\
    "入力範囲",\
};

const char *Confirm[MAX_LANGUAGE] = {\
    "确定", \
    "OK", \
    "Ja", \
    "Sí", \
    "Oui", \
    "Sì", \
    "Sim", \
    "Да", \
    "Evet", \
    "確認"
};

const char *Stop[MAX_LANGUAGE] = {\
    "停止",\
    "Stop",\
    "Stop",\
    "Detener",\
    "Arrêtez",\
    "Stop",\
    "Parar",\
    "Стоп",\
    "Dur",\
    "印刷中止"
};

const char *Pause[MAX_LANGUAGE] = {\
    "暂停",\
    "Pause",\
    "Pause",\
    "Pausar",\
    "Pause",\
    "Pausa",\
    "Pausar",\
    "Пауза",\
    "Duraklat",\
    "一時停止"
};

const char *Resume[MAX_LANGUAGE] = { \
    "继续",\
    "Continue",\
    "Weiter",\
    "Continuar",\
    "Continuer",\
    "Continua",\
    "Continuar",\
    "Продолжить",\
    "Devam et",\
    "続き"
};

const char *Print[MAX_LANGUAGE] = { \
    "打印",\
    "Print",\
    "Drucken",\
    "Imprimir",\
    "Impression",\
    "Stampa",\
    "Imprimir",\
    "Печать",\
    "Yazdır",\
    "印刷"
};

const char *Back[MAX_LANGUAGE] = { \
    "返回",\
    "Back",\
    "Zurück",\
    "Regresar",\
    "Retour",\
    "Indietro",\
    "Voltar",\
    "Назад",\
    "Geri",\
    "戻る",
};

const char *Cancel[MAX_LANGUAGE] = { \
    "取消",\
    "No",\
    "Nein",\
    "No",\
    "Non",\
    "No",\
    "Cancelar",\
    "Нет",\
    "Hayır",\
    "取消"
};

const char *KindTips[MAX_LANGUAGE] = { \
    "温馨提示",\
    "Tips",\
    "Tipps",\
    "Consejo",\
    "Conseils",\
    "Suggerimenti",\
    "Dica",\
    "Советы",\
    "İpuçları",\
    "お知らせ"
};

const char *Warning[MAX_LANGUAGE] = { \
    "警告", \
    "Warning",\
    "Warnung",\
    "Advertencia",\
    "Avertissement",\
    "Avvertenza",\
    "Aviso",\
    "Предупреждение",\
    "Uyarı",\
    "シリアスエラー",
};

const char *Local[MAX_LANGUAGE] = { \
    "本地",\
    "Local",\
    "Lokal",\
    "Local",\
    "Local",\
    "Locale",\
    "Local",\
    "Локальная память",\
    "Yerel",\
    "ローカル"
};

const char *DiskU[MAX_LANGUAGE] = { \
    "U盘",\
    "USB drive",\
    "USB-Laufwerk",\
    "Unidad USB",\
    "Lecteur USB",\
    "Unità USB",\
    "Unidade USB",\
    "USB-накопитель",\
    "USB sürücü",\
    "USBメモリ"
};

const char *DiskIn[MAX_LANGUAGE] = { \
    "U盘插入", \
    "USB flash drive inserted", \
    "USB-Stick eingesteckt", \
    "Unidad USB colocada", \
    "Lecteur flash USB inséré", \
    "Unità flash USB inserita", \
    "Unidade USB inserida ", \
    "Флэш-накопитель USB вставлен", \
    "USB bellek takıldı", \
    "USBメモリ挿入"
};

const char *DiskOut[MAX_LANGUAGE] = { \
    "U盘弹出", \
    "USB drive pops up", \
    "USB-Stick ausgeworfen", \
    "Unidad USB retirada", \
    "Le disque flash USB est éjecté", \
    "Unità flash USB espulsa", \
    "Unidade USB ejetada", \
    "Флэш-накопитель USB извлечен", \
    "USB bellek çıkarıldı", \
    "USBメモリ抜去"
};

const char *History[MAX_LANGUAGE] = { \
    "打印历史",\
    "History",\
    "Verlauf",\
    "Historial",\
    "Historique",\
    "Cronologia",\
    "Histórico",\
    "История",\
    "Geçmiş",\
    "印刷履歴"
};

const char *LastPageMsg[MAX_LANGUAGE] = { \
    "已经是尾页", \
    "Already the last page", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *FirstPageMsg[MAX_LANGUAGE] = { \
    "已经是首页", \
    "Already the first page", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *PrintingTips[MAX_LANGUAGE] = { \
    "打印中，暂不允许操作", \
    "Printing, do not interrupt", \
    "Drucken, nicht unterbrechen", \
    "Imprimiendo, no interrumpir", \
    "Impression, n'interrompez pas", \
    "Stampa in corso, non interrompere", \
    "Imprimindo, não interrompa", \
    "Выполняется печать, не прерывать", \
    "Yazdırılıyor, lütfen işlemi kesmeyin", \
    "印刷中につき、当分操作不可"
};

const char *NoContentsMsg[MAX_LANGUAGE] = { \
    "空", \
    "No content available", \
    "Kein Inhalt verfügbar",\
    "No hay contenidos disponibles",\
    "Aucun contenu disponible",\
    "Nessun contenuto disponibile",\
    "Nenhum conteúdo disponível",\
    "Содержимое недоступно",\
    "İçerik mevcut değil",\
    "しばらく内容なし"
};

const char *CopyToUSB[MAX_LANGUAGE] = { \
    "复制到U盘",\
    "Copy to USB flash drive",\
    "Auf USB-Flash-Laufwerk kopieren",\
    "Copiar a unidad USB",\
    "Copier sur le lecteur flash USB",\
    "Copia su unità flash USB",\
    "Cópia USB pendrive",\
    "Копировать на флешку",\
    "USB flash belleğe kopyala",\
    "USBメモリにコピーする"
};

const char *CopyToLocal[MAX_LANGUAGE] = { \
    "复制到本地",\
    "Copy to local",\
    "Auf lokales Laufwerk kopieren",\
    "Copiar a local",\
    "Copier sur le disque local",\
    "Copia in locale",\
    "Cópia local",\
    "Копировать на локальную память",\
    "Yerele kopyala",\
    "ローカルにコピーする"
};

const char *Delete[MAX_LANGUAGE] = { \
    "删除",\
    "Delete",\
    "Löschen",\
    "Eliminar",\
    "Supprimer",\
    "Elimina",\
    "Excluir",\
    "Удалить",\
    "Sil",\
    "削除"

};

const char *FileNameArray[MAX_LANGUAGE] = { \
    "文件名称",\
    "File name",\
    "Dateiname",\
    "Nombre de archivo",\
    "Nom du fichier",\
    "Nome file",\
    "Nome do arquivo",\
    "Имя файла",\
    "Dosya adı",\
    "ファイル名"
};


const char *Control[MAX_LANGUAGE] = { \
    "控制",\
    "Control",\
    "Steuerung",\
    "Control",\
    "Contrôle",\
    "Impostazioni",\
    "Controle",\
    "Контроль",\
    "Kontrol",\
    "コントロール"
};

const char *File[MAX_LANGUAGE] = { \
    "文件",\
    "File",\
    "Datei",\
    "Archivo",\
    "Fichier",\
    "File",\
    "Arquivo",\
    "Файл",\
    "Dosya",\
    "ファイル"
};

const char *Setting[MAX_LANGUAGE] = { \
    "设置", \
    "Settings", \
    "Anpassen", \
    "Ajustar", \
    "Réglages", \
    "Imposta", \
    "Ajuste.", \
    "Настройка", \
    "Ayarla", \
    "設定"
};

const char *LanguageSelection[MAX_LANGUAGE] = { \
    "语言", \
    "Language", \
    "Sprache", \
    "Idioma", \
    "Langue", \
    "Lingua", \
    "Língua", \
    "Язык", \
    "Dil", \
    "言語"
};

const char *LanguageSelectionTips[MAX_LANGUAGE] = { \
    "暂不支持该语种", \
    "This language is currently not supported", \
    "This language is currently not supported", \
    "This language is currently not supported", \
    "This language is currently not supported", \
    "This language is currently not supported", \
    "This language is currently not supported", \
    "This language is currently not supported", \
    "This language is currently not supported", \
    "This language is currently not supported"
};

const char *CameraArray[MAX_LANGUAGE] = { \
    "摄像头",\
    "Camera",\
    "Kamera",\
    "Cámara",\
    "Caméra",\
    "Fotocamera",\
    "Câmera",\
    "Камера",\
    "Kamera",\
    "カメラ"
};

const char *CameraSetting[MAX_LANGUAGE] = { \
    "摄像头设置",\
    "Camera settings",\
    "Kamera-Einstellungen",\
    "Ajustes de la cámara",\
    "Paramètres de la caméra",\
    "Impostazioni della fotocamera",\
    "Configurações de câmera",\
    "Настройки камеры",\
    "Kamera ayarları",\
    "カメラ設定"
};

const char *SettingArray[MAX_LANGUAGE] = { \
    "设置", \
    " Setting", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *VedioList[MAX_LANGUAGE] = { \
    "视频列表",\
    "Video list",\
    "Video-Liste",\
    "Lista de vídeos",\
    "Liste des vidéos",\
    "Elenco video",\
    "Lista de vídeos",\
    "Список видео",\
    "Video listesi",\
    "動画一覧"
};

const char *EnableArray[MAX_LANGUAGE] = { \
    "启用延时摄影",\
    "Enable time-lapse photography",\
    "Aktivieren der Zeitrafferfotografie",\
    "Habilitar fotografía de time-lapse",\
    "Activer la photographie time-lapse",\
    "Abilita la fotografia time-lapse",\
    "Ativar fotografia temporizada",\
    "Включить покадровую фотосъемку",\
    "Hızlandırılmış fotoğrafı etkinleştir",\
    "タイムラプスを有効にする"
};

const char *DisableArray[MAX_LANGUAGE] = { \
    "未启用", \
    " Disabled", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *Detection[MAX_LANGUAGE] = { \
    "检测", \
    " Detection", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *ExportArray[MAX_LANGUAGE] = { \
    "导出",\
    "Export",\
    "Exportieren",\
    "Exportar",\
    "Exporter",\
    "Esporta",\
    "Exportar",\
    "Экспорт",\
    "Dışa aktar",\
    "輸出"
};

const char *ExportTips[MAX_LANGUAGE] = { \
    "请使用U盘进行日志导出", \
    "Please export logs on a USB flash drive", \
    "Bitte exportieren Sie die Protokolle auf einen USB-Stick", \
    "Exporte los registros en una memoria USB", \
    "Veuillez exporter et sauvegarder les journaux sur une clé USB", \
    "Esporta i registri su una chiavetta USB", \
    "Por favor, exporte os registros para uma unidade flash USB", \
    "Экспортируйте журналы на USB-устройство флэш-памяти", \
    "Lütfen günlüğü USB belleğe aktarın", \
    "USBメモリにログをエクスポートしてください",
};

const char *UpLoadArray[MAX_LANGUAGE] = { \
    "上传", \
    "UpLoad", \
    "Hochladen", \
    "Subir", \
    "Chargement", \
    "Carica", \
    "Enviar", \
    "Загрузить", \
    "Yükle", \
    "アップロード",
};

const char *NotForNow[MAX_LANGUAGE] = { \
    "暂时不要",\
    "Not for now",\
    "Derzeit nicht",\
    "Por ahora no",\
    "Pas pour l'instant",\
    "Non ora",\
    "Não agora",\
    "Не сейчас",\
    "Şimdi değil",\
    "未定"
};

const char *PrintTime[MAX_LANGUAGE] = { \
    "打印时长", \
    "Used Time", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *VedioTime[MAX_LANGUAGE] = { \
    "视频时长", \
    "Video length", \
    "Länge des Videos", \
    "Longitud del vídeo", \
    "Durée de la vidéo", \
    "Lunghezza video", \
    "Extensão do Vídeo", \
    "Длительность видео", \
    "Video uzunluğu", \
    "動画の長さ"
};

const char *PrintDatetime[MAX_LANGUAGE] = { \
    "打印日期",\
    "Printing date",\
    "Druckdatum",\
    "Fecha de impresión",\
    "Date d'impression",\
    "Data di stampa",\
    "Data de impressão",\
    "Дата печати",\
    "Baskı tarihi",\
    "印刷日"
};

const char *ShootPosArray[MAX_LANGUAGE] = { \
    "拍摄位置",\
    "Camera site",\
    "Standort der Kamera",\
    "Sitio de la cámara",\
    "Emplacement de la caméra",\
    "Sito della fotocamera",\
    "Local da câmera",\
    "Место съемки",\
    "Kamera sitesi",\
    "撮影位置"
};
const char *ShootFreqArray[MAX_LANGUAGE] = { \
    "拍照频率", \
    "Shoot Freq", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};
const char *RenderArray[MAX_LANGUAGE] = { \
    "渲染方式", \
    "Render", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *AboutDevice[MAX_LANGUAGE] = { \
    "关于本机",\
    "About",\
    "Über",\
    "Acerca",\
    "Concernant",\
    "Al riguardo",\
    "Sobre",\
    "О",\
    "Hakkında",\
    "本機について"
};

const char *ResetMachine[MAX_LANGUAGE] = { \
    "恢复出厂",\
    "Reset to default",\
    "Auf Standardwerte zurücksetzen",\
    "Reiniciar a ajustes predeterminados",\
    "Réinitialisation aux valeurs par défaut",\
    "Ripristina le impostazioni di fabbrica",\
    "Redefinir para o padrão",\
    "Сброс до настроек по умолчанию",\
    "Varsayılana sıfırla",\
    "初期化",
};

const char *ResetMachineTips[MAX_LANGUAGE] = { \
    "恢复出厂中，请勿断电...",\
    "Do not power down as it is under factory restoration…",\
    "Durante um reset de fábrica, não perca energia...",\
    "Verlieren Sie während eines Werksresets nicht die Stromversorgung...",\
    "Не выключайте питание, сброс настроек...",\
    "Durante un restablecimiento de fábrica, no pierda la energía...",\
    "Pendant une réinitialisation d'usine, ne perdez pas l'alimentation...",\
    "Fabrika ayarlarına sıfırlama sırasında gücü kesmeyin...",\
    "Durante un ripristino delle impostazioni di fabbrica, non perdere potenza...",\
    "出荷時設定を復元しています、電源を切らないでください..."
};

const char *UpdataTips[MAX_LANGUAGE] = { \
    "版本升级后，请重新调平后再开始打印任务",\
    "After the upgrade, please recalibrate before starting the printing task.",\
    "Nach dem Upgrade bitte neu kalibrieren, bevor Sie mit dem Druckauftrag beginnen.",\
    "Después de la actualización, por favor recalibre antes de iniciar la tarea de impresión.",\
    "Après la mise à niveau, veuillez recalibrer avant de commencer la tâche d'impression.",\
    "Dopo l'aggiornamento, si prega di ricalibrare prima di iniziare il compito di stampa.",\
    "Após a atualização, por favor, recalibre antes de iniciar a tarefa de impressão.",\
    "После обновления, пожалуйста, выполните повторную калибровку перед началом печати.",\
    "Güncelleme sonrası, yazdırma görevine başlamadan önce yeniden kalibre ediniz.",\
    "バージョンアップ後、印刷タスクを開始する前に再調整してください。"
};

const char *LogArray[MAX_LANGUAGE] = { \
    "日志",\
    "Logs",\
    "Protokolle",\
    "Registros",\
    "Journaux",\
    "Registri",\
    "Registros",\
    "Журналы",\
    "Günlükler",\
    "ログ"
};

const char *BindDevice[MAX_LANGUAGE] = { \
    "绑定创想云",\
    "Bind to the Creality Cloud",\
    "Verbinden mit der Creality Cloud",\
    "Vincular a Creality Cloud",\
    "Relier au Creality Cloud",\
    "Associa al Creality Cloud",\
    "Vinculação à Creality Cloud",\
    "Привязать к Creality Cloud",\
    "Creality Cloud'a bağla",\
    "Creality Cloudとの連携",\
};

const char *UserName[MAX_LANGUAGE] = { \
    "用户名", \
    "UserName", \
    "Benutzername", \
    "Nombre de usuario", \
    "Nom d'utilisateur", \
    "Nome dell'utente", \
    "Nome do usuário", \
    "Имя пользователя", \
    "Kullanıcı adı", \
    "ユーザー名"
};


const char *LogOut[MAX_LANGUAGE] = { \
    "登出",\
    "Log Out",\
    "Abmelden",\
    "Cerrar sesión",\
    "Se déconnecter",\
    "Esci",\
    "Sair",\
    "Выйти",\
    "Çıkış Yap",\
    "ログアウトする"
};

const char *BindingTips[MAX_LANGUAGE] = { \
    "已绑定创想云",\
    "Already bound to Creality Cloud",\
    "Bereits mit der Creality Cloud verbunden",\
    "Ya está vinculado a Creality Cloud",\
    "Déjà lié à Creality Cloud",\
    "Già associato a Creality Cloud",\
    "Já vinculado ao Creality Cloud",\
    "Уже привязано к Creality Cloud",\
    "Creality Cloud'a zaten bağlı",\
    "Creality Cloudバインド済"
};

const char *IOTTips[MAX_LANGUAGE] = { \
    "IOT初始化失败，检查服务器设置",\
    "IOT initialization failed, check server settings.",\
    "IOT-Initialisierung fehlgeschlagen, überprüfen Sie die Servereinstellungen.",\
    "Falló la inicialización del IOT, verifique la configuración del servidor.",\
    "L'initialisation de l'IOT a échoué, vérifiez les paramètres du serveur.",\
    "Inizializzazione IOT fallita, controllare le impostazioni del server.",\
    "Falha na inicialização do IOT, verifique as configurações do servidor.",\
    "Ошибка инициализации IOT, проверьте настройки сервера.",\
    "IOT başlatma başarısız, sunucu ayarlarını kontrol edin.",\
    "IOTの初期化に失敗しました。サーバーの設定を確認してください。",
};

const char *CurVersionArray[MAX_LANGUAGE] = { \
    "当前版本",\
    "Current Version",\
    "Aktuelle Version",\
    "Versión actual",\
    "Version actuelle",\
    "Versione corrente",\
    "Versão Atual",\
    "Текущая версия",\
    "Geçerli Versiyon",\
    "現在のバージョン"
};

const char *ExportLogArray[MAX_LANGUAGE] = { \
    "导出日志",\
    "Export log",\
    "Protokoll exportieren",\
    "Exportar registro",\
    "Exporter le journal",\
    "Esporta registro",\
    "Exportar registro",\
    "Экспорт журнала",\
    "Günlüğü Dışa Aktar",\
    "ログをエクスポートする"
};

const char *StartDetection[MAX_LANGUAGE] = { \
    "开始检测",\
    "Start detecting",\
    "Erkennung starten",\
    "Inicio de la detección",\
    "Démarrer la détection",\
    "Avviare il rilevamento",\
    "Iniciar detecção",\
    "Начать обнаружение",\
    "Tespiti başlat",\
    "検出を開始"
};   

const char *StartAdjust[MAX_LANGUAGE] = { \
    "开始校准", \
    "Start Adjust", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};  

const char *StartLevel[MAX_LANGUAGE] = { \
    "开始调平", \
    "Start Level", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *HotendArray[MAX_LANGUAGE] = { \
    "喷头", \
    "Hotend", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *BedArray[MAX_LANGUAGE] = { \
    "热床", \
    "Bed", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
}; 

const char *PIDAdjustment[MAX_LANGUAGE] = { \
    "PID校准", \
    " PID Adjust", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *AutoLevel[MAX_LANGUAGE] = { \
    "自动调平",\
    "Auto Leveling",\
    "Auto-Nivellierung",\
    "Nivelación automática",\
    "Mise à niveau automatique",\
    "Livellamento automatico",\
    "Autonivelamento",\
    "Автовыравнивание",\
    "Otomatik Düzleştirme",\
    "オートレベリング"
};

const char *AILIDAR[MAX_LANGUAGE] = { \
    "AI激光雷达", \
    "AI LiDAR", \
    "KI-Lidar", \
    "AI Lidar", \
    "AI Lidar", \
    "AI  Lidar", \
    "IA  Lidar", \
    "Лидар ИИ", \
    "Yapay Zeka Lidarı", \
    "AIレーザーレーダー",
};

const char *PrinterAdjust[MAX_LANGUAGE] = { \
    "打印校准",\
    "Calibration",\
    "Kalibrierung",\
    "Calibración",\
    "Calibrage",\
    "Calibrazione",\
    "Calibragem",\
    "Калибровка",\
    "Kalibrasyon",\
    "キャリブレーション"
};

const char *Checking[MAX_LANGUAGE] = { \
    "检测中",\
    "Detecting",\
    "Erkennung",\
    "Detectar",\
    "Détecter",\
    "Rilevamento",\
    "Detectando ",\
    "Обнаружение",\
    "Tespit",\
    "検出中"
};

const char *PrevStep[MAX_LANGUAGE] = { \
    "上一步",\
    "Previous",\
    "Vorheriger",\
    "Anterior",\
    "Précédente",\
    "Precedente",\
    "Anterior",\
    "Назад",\
    "Önceki",\
    "前へ"
};

const char *NextStep[MAX_LANGUAGE] = { \
    "下一步",\
    "Next",\
    "Weiter",\
    "Siguiente",\
    "Suivante",\
    "Avanti",\
    "Próximo",\
    "Далее",\
    "Sonraki",\
    "次へ"
};

const char *JumpOver[MAX_LANGUAGE] = { \
    "跳过",\
    "Skip",\
    "Überspringen",\
    "Saltar",\
    "Sauter",\
    "Salta",\
    "Pular",\
    "Пропустить",\
    "Atla",\
    "スキップ"
};

const char *ModelCoolFan[MAX_LANGUAGE] = { \
    "模型冷却风扇", \
    "Model Cool Fan", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};


    //
const char *ThroatCoolFan[MAX_LANGUAGE] = { \
    "喉管散热风扇",\
    "Heat break fan",\
    "Ventilator zur Wärmeunterbrechung",\
    "Ventilador de rotura de calor",\
    "Ventilateur",\
    "Ventola ad assorbimento del calore",\
    "Ventoinha de calor",\
    "Вентилятор с тепловым разрывом",\
    "Isı arası soğutma fanı",\
    "スロートファン"
};

const char *BoardCoolFan[MAX_LANGUAGE] = { \
    "主板散热风扇",\
    "Mainboard fan",\
    "Mainboard Lüfter",\
    "Ventilador de placa base",\
    "Ventilateur de la carte mère",\
    "Ventola della scheda madre",\
    "Ventilador da Placa-Mãe",\
    "Вентилятор материнской платы",\
    "Anakart Fanı",\
    "メインボードファン"
};
 
const char *X_AxisMove[MAX_LANGUAGE] = { \
    "X轴移动", \
    "Move X", \
    "Bewegen Sie X.", \
    "Mover X", \
    "Déplacement de l'axe X", \
    "Muovi X", \
    "Mover X", \
    "Переместить X", \
    "Taşı - X", \
    "X軸移動"
};
const char *Y_AxisMove[MAX_LANGUAGE] = { \
    "Y轴移动", \
    "Move Y", \
    "Bewegen Sie Y.", \
    "Mover Y", \
    "Déplacement de l'axe Y", \
    "Muovi Y", \
    "Mover Y", \
    "Переместить Y", \
    "Taşı - Y", \
    "Y軸移動"
};    
const char *Z_AxisMove[MAX_LANGUAGE] = { \
    "Z轴移动", \
    "Move Z", \
    "Bewegen Sie Z.", \
    "Mover Z", \
    "Déplacement de l'axe Z", \
    "Muovi Z", \
    "Mover Z", \
    "Переместить Z", \
    "Taşı - Z", \
    "Z軸移動"
};    
const char *ManualLevel[MAX_LANGUAGE] = { \
    "手动调平", \
    "Manual Level", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};   
const char *VibrationOptimization[MAX_LANGUAGE] = { \
    "振纹优化",\
    "Input Shaping",\
    "Eingang Formgebung",\
    "Introducir forma",\
    "Mise en forme de l'entrée",\
    "Modellamento dell'ingresso",\
    "Entrar Forma",\
    "Формирование ввода",\
    "Girdi Şekillendirme",\
    "振動パターンの最適化"
};  

const char *Error1[MAX_LANGUAGE] = { \
    "喷嘴加热异常!请按说明书检查", \
    "Abnormal nozzle! Please check according to the instructions", \
    "Düse defekt! Bitte überprüfen Sie die Anweisungen", \
    "La boquilla no funciona de manera adecuada Revisar según las instrucciones", \
    "Buse anormale ! Veuillez vérifier selon les instructions.", \
    "Ugello anomalo! Controllare in base alle istruzioni", \
    "Bico anormal! Verifique de acordo com as instruções", \
    "Нестандартное сопло! Проверьте по инструкции", \
    "Anormal ağızlık! Lütfen talimatlara göre kontrol edin", \
    "ノズル異常！取扱説明書に従ってチェックしてください"
}; 

const char *Error2[MAX_LANGUAGE] = { \
    "热床加热异常！请按说明书检查。",\
    "Hotbed heated Error! Please check according to the instructions.",\
    "Fehler beim Erwärmen des Heizbettes! Bitte prüfen Sie anhand der Anweisungen.",\
    "¡Error de calentamiento de cama! Compruébelo según las instrucciones.",\
    "Lit chauffant chauffé Erreur ! Veuillez vérifier selon les instructions.",\
    "Errore riscaldamento letto caldo! Controllare in base alle istruzioni.",\
    "Erro de aquecimento da mesa! Verifique de acordo com as instruções.",\
    "Ошибка нагрева очага! Проверьте, следуя инструкциям.",\
    "Sıcak yatak ısıtma hatası! Lütfen talimatlara göre kontrol edin.",\
    "ホットベッドの加熱異常を起こしています！ 取扱説明書に従ってご確認ください。"
};  

const char *Error3[MAX_LANGUAGE] = { \
    "喉管风扇异常!请按说明书检查", \
    "Abnormal heat break fan! Please check according to the instructions", \
    "Ventilator der Wärmeunterbrechung defekt! Bitte nach Anleitung prüfen", \
    "El ventilador de disipación no funciona de manera adecuada Revisar según las instrucciones", \
    "Ventilateur de rupture de chaleur anormal ! Veuillez vérifier selon les instructions.", \
    "Ventola di dissipazione termica anomala! Controllare in base alle istruzioni", \
    "Ventoinha de arrefecimento de calor anormal! Verifique de acordo com as instruções", \
    "Неисправность вентилятора теплового разрыва! Проверьте по инструкции", \
    "Anormal ısı kesme fanı! Lütfen talimatlara göre kontrol edin", \
    "ベンチュリ管異常！取扱説明書に従ってチェックしてください"
};  

const char *Error4[MAX_LANGUAGE] = { \
    "主板风扇异常!请按说明书检查", \
    "Abnormal mainboard fan! Please check according to the instructions", \
    "Platinenventilator defekt! Bitte nach Anleitung prüfen", \
    "El ventilador principal no funciona de manera adecuada. Revisar según las instrucciones", \
    "Ventilateur de la carte mère anormal ! Veuillez vérifier selon les instructions.", \
    "Ventola della scheda madre anomala! Controllare in base alle istruzioni", \
    "Ventoinha da placa principal anormal! Verifique de acordo com as instruções", \
    "Неисправность вентилятора на материнской плате! Проверьте по инструкции", \
    "Anormal anakart fanı! Lütfen talimatlara göre kontrol edin", \
    "マザーボードファン異常！取扱説明書に従ってチェックしてください"
};  

const char *Error5[MAX_LANGUAGE] = { \
    "振纹优化异常!请按说明书检查", \
    "Abnormal ringing optimization! Please check according to the instructions", \
    "Abnormale Welligkeitoptimierung! Bitte prüfen Sie gemäß den Anweisungen", \
    "¡Optimización de pitido anormal! Compruébelo conforme a las instrucciones", \
    "Optimisation de la sonnerie anormale ! Veuillez vérifier selon les instructions", \
    "Ottimizzazione suoneria anomala! Controllare in base alle istruzioni", \
    "Otimização anormal do toque! Por favor, verifique de acordo com as instruções", \
    "Ненормальная оптимизация звонка! Проверьте в соответствии с инструкцией", \
    "Anormal zil çalma optimizasyonu!Lütfen talimatlara göre kontrol edin", \
    "モアレ最適化エラー！ 取扱説明書に従ってチェックしてください"
};  

const char *Error6[MAX_LANGUAGE] = { \
    "自动调平异常!请按说明书检查", \
    "Abnormal auto leveling! Please check according to the instructions", \
    "Auto-Nivellierung defekt! Bitte nach Anleitung prüfen", \
    "La nivelación automática no funciona de manera adecuada. Revisar según las instrucciones", \
    "Nivellement automatique anormal ! Veuillez vérifier selon les instructions.", \
    "Livellamento automatico anomalo! Controllare in base alle istruzioni", \
    "Autonivelamento anormal! Verifique de acordo com as instruções", \
    "Неисправность автовыравнивания! Проверьте по инструкции", \
    "Anormal otomatik düzleştirme! Lütfen talimatlara göre kontrol edin", \
    "オートレベリング異常！ 取扱説明書に従ってチェックしてください"
};  

const char *Error7[MAX_LANGUAGE] = { \
    "AI激光雷达异常!请按说明书检查", \
    "Abnormal AI LiDAR! Please check according to the instructions", \
    "Abnormales KI LiDAR! Bitte überprüfen Sie gemäß den Anweisungen", \
    "AI LiDAR no funciona de manera correcta. Revísela según las instrucciones", \
    "Problème avec AI LiDAR ! À vérifier comme indiqué dans les instructions", \
    "Lidar AI anormale! Controlla seguendo le istruzioni", \
    "AI LiDAR anormal! Verifique de acordo com as instruções", \
    "Аномальный лидар ИИ! Проверьте в соответствии с инструкцией", \
    "Anormal AI Lidar! Lütfen talimatlara göre kontrol edin", \
    "AIレーザーレーダー異常！取扱説明書に従ってチェックしてください"
};  

const char *Error8[MAX_LANGUAGE] = { \
    "摄像头异常!请按说明书检查", \
    "Camera Error! Please check according to the instructions.", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};  

const char *PrintCompleted[MAX_LANGUAGE] = { \
    "已完成打印",\
    "Print complete",\
    "Druck abgeschlossen",\
    "Impresión completa",\
    "Impression terminée",\
    "Stampa completata",\
    "Impressão concluída",\
    "Печать завершена",\
    "Yazdırma tamamlandı",\
    "印刷が完了しました"
};  

const char *InsertUdisk[MAX_LANGUAGE] = { \
    "请插入U盘",\
    "Please insert the USB flash drive.",\
    "Bitte stecken Sie den USB-Stick ein.",\
    "Por favor, inserte la unidad USB. ",\
    "Veuillez insérer la clé USB. ",\
    "Veuillez insérer la clé USB. ",\
    "Por favor, insira o pen drive.",\
    "Пожалуйста, вставьте USB-накопитель. ",\
    "Lütfen USB belleği takın. ",\
    "USBフラッシュドライブを挿入してください。"
};  

const char *Notyet[MAX_LANGUAGE] = { \
    "暂时不要",\
    "Not for now",\
    "Derzeit nicht",\
    "Por ahora no",\
    "Pas pour l'instant",\
    "Non ora",\
    "Não agora",\
    "Не сейчас",\
    "Şimdi değil",\
    "未定"
};  
const char *Restart[MAX_LANGUAGE] = { \
    "重启", \
    "Restart", \
    "Neustart", \
    "Reiniciar", \
    "Redémarrer", \
    "Riavviare", \
    "Reiniciar", \
    "Перезапустить", \
    "Yeniden başlat", \
    "再起動"
};  

const char *OverRangleMsg[MAX_LANGUAGE] = { \
    "输入的数据超出范围,请重新输入.", \
    "The entered data is out of range, please re-enter.", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};  

const char *CalibrationProccess[MAX_LANGUAGE] = { \
    "校准进行中,当前进度", \
    "Calibration in progress, current progress ", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};    

const char *CalibrationFinished[MAX_LANGUAGE] = { \
    "校准已完成，请点击下一步", \
    "Calibration is complete, please click Next", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};   
/**********************home normal*************************/



/**********************home printing*************************/
const char *PowerLossRecoverMsg[MAX_LANGUAGE] = { \
    "检测到上次意外停止的文件",\
    "It looks like the last file was interrupted.",\
    "Druckdatei für versehentliches Anhalten erkannt",\
    "Se detectó un archivo de impresión detenido inesperadamente",\
    "Détecter un fichier d'impression arrêté de manière inattendu",\
    "Rilevato file di stampa interrotto inaspettatamente",\
    "Arquivo de Impressão detectado por parada acidental",\
    "Обнауржена аварийная остановка печати",\
    "Hatalı bir şekilde durdurulan baskı dosyası",\
    "印刷停止のファイルを検出しました"
};

const char *FilamentRunOutMsg[MAX_LANGUAGE] = { \
    "当前耗材用尽，请更换耗材，或停止本次打印",\
    "Run out the filament need to add new",\
    "Das Filament ist aufgebraucht, Sie müssen neues hinzufügen",\
    "Se ha gastado en filamento; se debe añadir uno nuevo",\
    "Il n'y a plus de filament, il faut en rajouter",\
    "Filamento esaurito, aggiungerne nuovo",\
    "Filamento esgotado, necessário adicionar mais",\
    "Нить закончилась. Добавьте новую",\
    "Filaman tükendi, yeni eklenmesi gerekiyor",\
    "インクが枯渇しているため、インクを交換するか、今回の印刷を中止してください"
};

const char *PrintActionTipTitle[MAX_LANGUAGE] = { \
    "请选择您的操作！", \
    "Please select your action.", \
    "Bitte wählen Sie Ihre Aktion aus.", \
    "Seleccione su acción.", \
    "Veuillez préciser votre action.", \
    "Si prega di selezionare la tua azione.", \
    "Selecione sua ação.", \
    "Выберите действие.", \
    "Lütfen işleminizi seçin.", \
    "操作を選択してください",
};


/**********************axis move*************************/
const char *MovePageTitle[MAX_LANGUAGE] = { \
    "轴移动/温度",\
    "Axis movement/Temp.",\
    "Achsenbewegung/Temp.",\
    "Movimiento del eje / Temperatura",\
    "Mouvement/Temp. de l'axe",\
    "Movimento asse/temp.",\
    "Movimento do eixo/Temp.",\
    "Движение оси/темп.",\
    "Eksen hareketi / Sıcaklık",\
    "シャフトの動き・温度"
};

const char *MoveAxisTips[MAX_LANGUAGE] = { \
    "已到最小值", \
    "Min. value reached", \
    "Der minimale Wert ist erreicht", \
    "Se alcanzó el valor mínimo", \
    "Valeur min. atteinte", \
    "Valore minimo raggiunto", \
    "Valor mín. atingido", \
    "Достигнуто минимальное значение", \
    "Min. değere ulaşıldı", \
    "もう最小値に達しました"
};

const char *MoveAxisTips2[MAX_LANGUAGE] = { \
    "已到最大值", \
    "Max. value reached", \
    "Der maximale Wert ist erreicht", \
    "Se alcanzó el valor máxima", \
    "Valeur max. atteinte", \
    "Valore massima raggiunto", \
    "Valor máx. atingido", \
    "Достигнуто максимальная значение", \
    "Maks. değere ulaşıldı", \
    "もう最大値に達しました"
};

const char *mult_language[MAX_LANGUAGE] = {
    "1汉语",
    "2英语",
    "3德语",
    "4西语",
    "5法语",
    "6意语",
    "7葡语",
    "8俄语",
    "9土语",
    "10日语"
};

const char *Fans[MAX_LANGUAGE] = { \
    "风扇",\
    "Fan",\
    "Ventilator",\
    "Ventilador",\
    "Ventilateur",\
    "Ventilatore",\
    "Ventilador",\
    "Вентилятор",\
    "Ventilatör",\
    "ファン"
};

const char *ModelFans[MAX_LANGUAGE] = { \
    "模型风扇",\
    "Model fan",\
    "Modell Ventilator",\
    "Ventilador modelo",\
    "Modèle de ventilateur",\
    "Modello ventilatore",\
    "Ventoinha do modelo",\
    "Модель вентилятора",\
    "Model fanı",\
    "モデルファン"
};

const char *HomeMsg[MAX_LANGUAGE] = { \
    "正在回零中，请稍后...",\
    "Returning to home position, please wait...",\
    "Zurück zur Startseite, bitte warten...",\
    "Volviendo a la posición de inicio, espere...",\
    "Retour à la position initiale, veuillez patienter....",\
    "Ritorno alla posizione iniziale, attendere prego...",\
    "Voltando à posição inicial, aguarde...",\
    "Возврат в исходное положение, подождите...",\
    "Ana pozisyona geri dönüyor, lütfen bekleyin…",\
    "ゼロに戻しています。しばらくお待ちください…"
};

const char *HomeFailedMsg[MAX_LANGUAGE] = { \
    "轴归零失败!", \
    "axis homing failed!", \
    "axis homing failed!", \
    "axis homing failed!", \
    "axis homing failed!", \
    "axis homing failed!", \
    "axis homing failed!", \
    "axis homing failed!", \
    "axis homing failed!", \
    "axis homing failed!"
};

const char *ColdExtrudeMsg[MAX_LANGUAGE] = { \
    "喷头温度低于最小挤出温度!", \
    "nozzle temper is below the min extrusion temper!", \
    "nozzle temper is below the min extrusion temper!", \
    "nozzle temper is below the min extrusion temper!", \
    "nozzle temper is below the min extrusion temper!", \
    "nozzle temper is below the min extrusion temper!", \
    "nozzle temper is below the min extrusion temper!", \
    "nozzle temper is below the min extrusion temper!", \
    "nozzle temper is below the min extrusion temper!", \
    "nozzle temper is below the min extrusion temper!",
};

const char *NotHomedMsg[MAX_LANGUAGE] = { \
    "轴未归零，无法进行移动操作", \
    " Axis is not homed, cannot perform move operation", \
    "Axis is not homed, cannot perform move operation", \
    "Axis is not homed, cannot perform move operation", \
    "Axis is not homed, cannot perform move operation", \
    "Axis is not homed, cannot perform move operation", \
    "Axis is not homed, cannot perform move operation", \
    "Axis is not homed, cannot perform move operation", \
    "Axis is not homed, cannot perform move operation", \
    "Axis is not homed, cannot perform move operation",
};

const char *Extrude_Retract[MAX_LANGUAGE] = {\
    "进退料",\
    "Extrude/Retract",\
    "Extrudieren/Rückziehen",\
    "Extruir/Retraer",\
    "Extrusion/Retrait",\
    "Estrusione/Ritrazione",\
    "Extrusão/Retração",\
    "Выдавить/втянуть",\
    "Çıkar/Geri Çek",\
    "イン/アウト",
};

const char *Cooling[MAX_LANGUAGE] = { \
    "冷却",\
    "Cooling",\
    "Kühlen",\
    "Refrigeración",\
    "Refroidissement",\
    "Raffreddamento",\
    "Resfriamento",\
    "Охлаждение",\
    "Soğutma",\
    "クーリング"
};

/**********************adjustment*************************/
const char *Adjustment[MAX_LANGUAGE] = { \
    "调整", \
    "Adjustment", \
    "Einstellen", \
    "Ajustar", \
    "Régler", \
    "Regola", \
    "Ajuste", \
    "Регулировать", \
    "Ayarla", \
    "調整",
};

const char *UnitSetting[MAX_LANGUAGE] = { \
    "单位设置", \
    "Unit Setting", \
    "Unit Setting", \
    "Unit Setting", \
    "Unit Setting", \
    "Unit Setting", \
    "Unit Setting", \
    "Unit Setting", \
    "Unit Setting", \
    "Unit Setting"
};

const char *FlowTipsMsg[MAX_LANGUAGE] = { \
    "未能获取最新的打印流量比", \
    "Failed to fetch latest print flow percent", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *SpeedTipsMsg[MAX_LANGUAGE] = { \
    "未能获取最新的打印速度比", \
    "Failed to fetch latest print speed percent", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *SprintSpeed[MAX_LANGUAGE] = { \
    "打印速度", \
    "Speed", \
    "Geschwindigkeit", \
    "Velocidad", \
    "Vitesse", \
    "Velocità", \
    "Velocidade", \
    "Скорость", \
    "Hız", \
    "印刷速度",
};

const char *NormalMode[MAX_LANGUAGE] = { \
    "常规模式", \
    "Normal Mode", \
    "Normaler Modus", \
    "Modo normal", \
    "Mode normal", \
    "Modalità normale", \
    "Modo Normal", \
    "Обычный режим", \
    "Normal Mod", \
    "ノーマルモード",
};

const char *SlicenMode[MAX_LANGUAGE] = { \
    "静音模式", \
    "Quiet Mode", \
    "Leiser Modus", \
    "Modo silencioso", \
    "Mode silencieux", \
    "Modalità silenziosa", \
    "Modo Silencioso", \
    "Бесшумный режим", \
    "Sessiz mod", \
    "サイレントモード",
};

const char *ModelFan[MAX_LANGUAGE] = { \
    "模型风扇",\
    "Model fan",\
    "Modell Ventilator",\
    "Ventilador modelo",\
    "Modèle de ventilateur",\
    "Modello ventilatore",\
    "Ventoinha do modelo",\
    "Модель вентилятора",\
    "Model fanı",\
    "モデルファン"
};

const char *CoolFan[MAX_LANGUAGE] = { \
    "辅助风扇",\
    "Side Fan",\
    "Seitlicher Ventilator",\
    "Ventilador lateral",\
    "Ventilateur latéral",\
    "Ventola laterale",\
    "Ventoinha lateral",\
    "Боковой вентилятор",\
    "Yan Fan",\
    "補助ファン"
};

const char * BackFan[MAX_LANGUAGE] = { \
    "机箱风扇",\
    "Back Fan",\
    "Hinterer Ventilator",\
    "Ventilador posterior",\
    "Ventilateur arrière",\
    "Ventola posteriore",\
    "Ventoinha traseira",\
    "Задний вентилятор",\
    "Arka Fan",\
    "ケースファン"
};

const char * HotendTemp[MAX_LANGUAGE] = { \
    "喷嘴温度",\
    "Nozzle temperature",\
    "Düsentemperatur",\
    "Temperatura de la boquilla",\
    "Température de la buse",\
    "Temperatura dell'ugello",\
    "Temperatura do bico",\
    "Температура сопла",\
    "Ağızlık sıcaklığı",\
    "ノズル温度"
};

const char *Bed_temp[MAX_LANGUAGE] = { \
    "热床温度", \
    "Bed Temperature", \
    "Betteinstellung", \
    "Ajustes de cama", \
    "Réglage du plateau", \
    "Imposta Hot-bed", \
    "Temp. da Base", \
    "Настроки стола", \
    "Sıcak Tabla Ayarı",\
    "ヒートベッド温度"
};

const char * Turn_off_the_motor[MAX_LANGUAGE] = { \
    "关闭电机",\
    "Disable stepper",\
    "Motorfreigabe",\
    "Liberar de motores",\
    "Désactivation moteurs",\
    "Disconnettere motore",\
    "Liberar motor",\
    "Откл. мотор",\
    "Motor Bırakma",\
    "モーター固定解除"
};

const char * FilamentIn[MAX_LANGUAGE] = { \
    "进料",\
    "Extrude",\
    "Extrudieren",\
    "Extruir",\
    "Extruder",\
    "Estrusione",\
    "Extrusão",\
    "Выдавить",\
    "Çıkar",\
    "インフィード"
};

const char * FilamentIning[MAX_LANGUAGE] = { \
    "进料中",\
    "Extrudting",\
    "Extrudieren",\
    "Extruyendo",\
    "Extrusion",\
    "Estrusione",\
    "Em extrusão",\
    "Выдавливание",\
    "Ekstrüzyon",\
    "給餌中"
};

const char * FilamentEnd[MAX_LANGUAGE] = { \
    "进料完成",\
    "Extrude done",\
    "Extrudieren erledigt",\
    "Extrusión finalizada",\
    "Extrusion effectuée",\
    "Estrusione eseguita",\
    "Extrusão concluída",\
    "Выдавливание выполнено",\
    "Çıkarma işlemi tamamlandı",\
    "アンローディング完了"
};

const char * FilamentOutPrep[MAX_LANGUAGE] = { \
    "退料准备",\
    "Prepare to retract",\
    "Vorbereiten zum Rückziehen",\
    "Preparartse para retraer",\
    "Préparation à la rétraction",\
    "Prepararsi alla ritrazione",\
    "Preparação para retrair",\
    "Подготовка к втягиванию",\
    "Geri çekme işlemi hazırlanıyor",\
    "巻き戻しの準備"
};

const char * FilamentOuting[MAX_LANGUAGE] = { \
    "退料中",\
    "Retracting",\
    "Rückziehen",\
    "Retrayendo",\
    "Rétractation",\
    "Ritrazione",\
    "Retraindo",\
    "Втягивание",\
    "Geri çekiliyor",\
    "アンローディング中"
};

const char * FilamentOutEnd[MAX_LANGUAGE] = { \
    "退料完成",\
    "Retract done",\
    "Rückziehen erledigt",\
    "Retracción finalizada",\
    "Retrait effectué",\
    "Ritrazione completata",\
    "Retração concluída",\
    "Втягивание выполнено",\
    "Geri çekme işlemi tamamlandı",\
    "給餌完了"
};

const char * HotendHeating[MAX_LANGUAGE] = { \
    "喷嘴加热",\
    "Nozzle heating",\
    "Erwärmung der Düse",\
    "Calentamiento de la boquilla",\
    "Chauffage des buses",\
    "Riscaldamento ugello",\
    "Aquecimento do bico",\
    "Нагрев сопла",\
    "Ağızlık ısıtma",\
    "ノズルヒーター"
};


const char * HotTips[MAX_LANGUAGE] = { \
    "进退料前温度将自动加热至%d℃", \
    "Temperature will heat up to %d°C before feed/retreat", \
    "Temperatur erwärmt sich bis zu %d °C vor dem Einziehen/Rückziehen", \
    "La temperatura llegará a los %d°C antes de la alimentación / retirada",\
    "La température atteindra %d°C avant l'alimentation/le retraitement.",\
    "La temperatura aumenta automaticamente fino a %d °C prima dell'alimentazione/ritrazione",\
    "A temperatura será aquecida até %d°C antes da alimentação/retrocesso",\
    "Перед выдавлтв/втянутв температура повысится до %d°C",\
    "Sıcaklık değeri besleme/geri çekme işleminden önce %d°C'ye ulaşacaktır",\
    "フィード/ディスチャージ前の温度は自動的に%d℃まで加熱されます"
};

const char *FilamentOut[MAX_LANGUAGE] = { \
    "退料",\
    "Retract",\
    "Rückziehen",\
    "Retraer",\
    "Rétracter",\
    "Ritrazione",\
    "Retração",\
    "Втянуть",\
    "Geri çek",\
    "解きほぐす"
};

const char *FilamentTempTips1[MAX_LANGUAGE] = { \
    "已到最大温度", \
    "Max. temperature reached", \
    "Die maximale Temperatur ist erreicht", \
    "Se alcanzó la temperatura máxima", \
    "Température max. atteinte", \
    "Temperatura massima raggiunta", \
    "Temperatura máx. atingida", \
    "Достигнута максимальная температура", \
    "Maks. sıcaklığa ulaşıldı", \
    "もう最大温度に達しました",
};

const char *FilamentTempTips2[MAX_LANGUAGE] = { \
    "已到最小温度", \
    "Min. temperature reached", \
    "Die minimale Temperatur ist erreicht", \
    "Se alcanzó la temperatura mínima", \
    "Température min. atteinte", \
    "Temperatura minima raggiunta", \
    "Temperatura mín. atingida", \
    "Достигнута минимальная температура", \
    "Min. sıcaklığa ulaşıldı", \
    "もう最小温度に達しました",
};

/**********************file manager*************************/



/**********************sub dir*************************/
const char *RootDirTipsMsg[MAX_LANGUAGE] = { \
    "父文件夹是根文件夹,即将进行切换", \
    "Parent is root dir and will switch to it", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *DirNameTipsMsg[MAX_LANGUAGE] = { \
    "文件夹名称为空", \
    "Dir name is empty", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *FileCountTipsMsg[MAX_LANGUAGE] = { \
    "当前文件夹没有文件", \
    "curdir has no files", \
    "curdir has no files", \
    "curdir has no files", \
    "curdir has no files", \
    "curdir has no files", \
    "curdir has no files", \
    "curdir has no files", \
    "curdir has no files", \
    "curdir has no files",
};

const char *DirIndexTipsMsg[MAX_LANGUAGE] = { \
    "文件夹的索引无效!", \
    "dir index is invalid!", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};


/**********************print history*************************/
const char *NoRecords[MAX_LANGUAGE] = { \
    "空", \
    "Empty", \
    "Leer",\
    "Vacío",\
    "Vider",\
    "Vuoto",\
    "Vazio",\
    "Пусто",\
    "Boş",\
    "空"
};

const char *RecordIndexTipsMsg[MAX_LANGUAGE] = { \
    "打印记录索引是无效的!", \
    "Record index is invalid!", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *PrintAgain[MAX_LANGUAGE] = { \
    "再次打印", \
    "Print Again", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *Page[MAX_LANGUAGE] = { \
    "页", \
    "page", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *Copy[MAX_LANGUAGE] = { \
    "拷贝", \
    "Copy", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};


const char *TotleTimeArray[MAX_LANGUAGE] = { \
    "总共耗时",\
    "Total time",\
    "Gesamtzeit",\
    "Tiempo total",\
    "Temps total",\
    "Tempo totale",\
    "Tempo total",\
    "Общее время",\
    "Toplam zaman",\
    "総撮影時間"
};

const char *StartTimeArray[MAX_LANGUAGE] = { \
    "开始时间",\
    "Start Time",\
    "Startzeit",\
    "Hora de inicio",\
    "Temps de démarrage",\
    "Ora di inizio",\
    "Tempo de Início",\
    "Время пуска",\
    "Başlangıç Zamanı",\
    "開始時間"
};

const char *StatusArray[MAX_LANGUAGE] = { \
    "状态",\
    "Status",\
    "Status",\
    "Estado",\
    "Statut de l'écran",\
    "Stato",\
    "Status",\
    "Статус",\
    "Durum",\
    "ステータス"
};

const char *Action[MAX_LANGUAGE] = { \
    "操作",\
    "Operate",\
    "Betätigen",\
    "Operar",\
    "Fonctionner",\
    "Azionare",\
    "Operar",\
    "Выполнить",\
    "Çalıştır",\
    "操作方法"
};

/**********************preview*************************/

const char *OpenFileFailedMsg[MAX_LANGUAGE] = { \
    "打开打印文件失败", \
    "Failed to open print file", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *OpeningFileMsg[MAX_LANGUAGE] = { \
    "正在打开即将打印的文件", \
    "Opening file for printing", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *FileIndexInvalid[MAX_LANGUAGE] = { \
    "文件索引是无效的!", \
    "The file index is invalid!", \
    "The file index is invalid!", \
    "The file index is invalid!", \
    "The file index is invalid!", \
    "The file index is invalid!", \
    "The file index is invalid!", \
    "The file index is invalid!", \
    "The file index is invalid!", \
    "The file index is invalid!",
};

const char *FileIndexUpdate[MAX_LANGUAGE] = { \
    "文件索引异常刷新中!", \
    "Refreshing because of abnormal file index!", \
    "Refreshing because of abnormal file index!", \
    "Refreshing because of abnormal file index!", \
    "Refreshing because of abnormal file index!", \
    "Refreshing because of abnormal file index!", \
    "Refreshing because of abnormal file index!", \
    "Refreshing because of abnormal file index!", \
    "Refreshing because of abnormal file index!", \
    "Refreshing because of abnormal file index!",
};

/**********************faq*************************/
const char *FaqArray[MAX_LANGUAGE] = { \
    "帮助",\
    "Help",\
    "Hilfe",\
    "Ayuda",\
    "Aide",\
    "Aiuto",\
    "Ajuda",\
    "Помощь",\
    "Yardım",\
    "ヘルプ"
};

const char *Errorhistory[MAX_LANGUAGE] = { \
    "错误历史",\
    "Error history",\
    "Fehlerverlauf",\
    "Historial de errores",\
    "Historique des erreurs",\
    "Cronologia degli errori",\
    "Histórico de erros",\
    "История ошибок",\
    "Hata geçmişi",\
    "エラー履歴"
};

const char *FAQ[MAX_LANGUAGE] = { \
    "FAQ",\
    "FAQ",\
    "HÄUFIGE FRAGEN",\
    "PREGUNTAS FRECUENTES",\
    "FAQ",\
    "Domande frequenti",\
    "Perguntas Frequentes",\
    "ЧЗВ",\
    "SSS",\
    "よくあるご質問"
};

const char *OnlineManual[MAX_LANGUAGE] = { \
    "在线说明书",\
    "Online Manual",\
    "Online Handbuch",\
    "Manual online",\
    "Manuel en ligne",\
    "Manuale online",\
    "Manual Online",\
    "Онлайн-руководство",\
    "Çevrimiçi kılavuz",\
    "オンライン取扱説明書"
};

const char *ExportUdisk[MAX_LANGUAGE] = { \
    "导出U盘",\
    "Export USB drive",\
    "Exportieren Sie den USB-Stick",\
    "Exportar unidad USB",\
    "Exporter la clé USB",\
    "Esporta la chiavetta USB",\
    "Exportar unidade USB",\
    "Экспорт USB-накопителя",\
    "USB sürücüsü dışa aktar",\
    "USBドライブをエクスポートする"
};

const char *UploadLog[MAX_LANGUAGE] = { \
    "上传日志",\
    "Upload Log",\
    "Protokoll hochladen",\
    "Cargar registro",\
    "Téléverser le journal",\
    "Carica registro",\
    "Enviar Registro",\
    "Загрузить журнал",\
    "Günlük Yükle",\
    "ログのアップロード"
};

const char *QrccodeTipsMsg[MAX_LANGUAGE] = { \
    "扫码进行意见反馈", \
    "Scan qrcode for feedback", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *UploadTips[MAX_LANGUAGE] = { \
    "请点击下面按钮进行日志上传",\
    "Please click the button below to upload your log",\
    "Bitte klicken Sie auf die nachfolgende Taste, um Ihr Protokoll hochzuladen",\
    "Haga clic en el botón de debajo para cargar el registro",\
    "Veuillez cliquer sur le bouton ci-dessous pour téléverser votre journal",\
    "Fare clic sul pulsante riportato di seguito per caricare il registro",\
    "Clique no botão abaixo para enviar seu registro",\
    "Нажмите кнопку ниже для загрузки журнала",\
    "Lütfen günlüğünüzü yüklemek için aşağıdaki düşmeye tıklayın",\
    "以下のボタンをクリックして、ログをアップロードしてください。"
};

/***********************camera list****************************/
const char *NoVedioes[MAX_LANGUAGE] = { \
    "空", \
    "No content available", \
    "Kein Inhalt verfügbar",\
    "No hay contenidos disponibles",\
    "Aucun contenu disponible",\
    "Nessun contenuto disponibile",\
    "Nenhum conteúdo disponível",\
    "Содержимое недоступно",\
    "İçerik mevcut değil",\
    "しばらく内容なし"
};


/****************************camera setting**********************/
const char *EveryArray[MAX_LANGUAGE] = { \
    "每", \
    "every", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};
const char *LayerArray[MAX_LANGUAGE] = { \
    "层", \
    "layer ", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};
const char *ShootMsg[MAX_LANGUAGE] = { \
    "拍摄一次", \
    "shoot once", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};
const char *LayerStartPos[MAX_LANGUAGE] = { \
    "每层启始位置",\
    "Start position of each layer",\
    "Startposition der einzelnen Flächen",\
    "Posición de inicio de cada nivel",\
    "Position de départ de chaque niveau",\
    "Posizione iniziale di ogni livello",\
    "Posição inicial de cada nível",\
    "Начальное положение каждого уровня",\
    "Her bir seviyenin başlangıç pozisyonu",\
    "レイヤーごとの開始位置"
};
const char *HotendMoveAway[MAX_LANGUAGE] = { \
    "喷头移开时",\
    "When the extruder is moved away",\
    "Wenn der Extruder wegbewegt wird",\
    "Cuando el extrusor se aleja",\
    "Lorsque l'extrudeuse est éloignée",\
    "Quando l'estrusore viene allontanato",\
    "Quando a extrusora for movida",\
    "Когда экструдер убран",\
    "Ekstrüder uzaklaştırıldığında",\
    "プリントヘッドが離れると"
};

// const char *DelayPhotograph[MAX_LANGUAGE] = { \
//     "延时摄影", \
//     " time-lapse photography", \
//     "3", \
//     "4", \
//     "5", \
//     "6", \
//     "7", \
//     "8", \
//     "9", \
//     ""
// };

/***********************vedio info****************************/
const char *VedioInformation[MAX_LANGUAGE] = { \
    "视频详情",\
    "Video details",\
    "Video",\
    "Detalles del vídeo",\
    "Détails de la vidéo",\
    "Dettagli video",\
    "Detalhes do vídeo",\
    "Детали видео",\
    "Video detayları",\
    "ビデオの詳細"
};

const char *MoveAwayArray[MAX_LANGUAGE] = { \
    "移开喷头", \
    "Hotend Moved Away", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *NoMoveAwayArray[MAX_LANGUAGE] = { \
    "不移开喷头", \
    "Hotend done not Move Away", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *AIFunction[MAX_LANGUAGE] = { \
    "AI功能",\
    "AI function",\
    "KI-Funktion",\
    "Función de IA",\
    "Fonction IA",\
    "Funzione AI",\
    "Função IA",\
    "Функция ИИ",\
    "Yapay zeka fonksiyonu",\
    "AI機能"
};

const char *AIdetection[MAX_LANGUAGE] = { \
    "#FFFFFF AI检测##FFD15B (功能优化中)#",\
    "#FFFFFF AI detection##FFD15B (In optimization)#",\
    "#FFFFFF KI-Erkennung##FFD15B (In Optimierung)#",\
    "#FFFFFF Detección de IA##FFD15B (En optimización)#",\
    "#FFFFFF Détection IA##FFD15B (Optimisation)#",\
    "#FFFFFF Rilevamento AI##FFD15B (Ottimizzazione)#",\
    "#FFFFFF Detecção IA##FFD15B (Em optimização)#",\
    "#FFFFFF Обнаружение ИИ##FFD15B (В оптимизации)#",\
    "#FFFFFF Yapay zeka tanısı##FFD15B (Optimizasyon)#",\
    "#FFFFFF AI検出##FFD15B (最適化において)#",
};

const char *AISensitivity[MAX_LANGUAGE] = { \
    "灵敏度",\
    "Sensitivity",\
    "Empfindlichkeit",\
    "Sensibilidad",\
    "Sensibilité",\
    "Sensibilità",\
    "Sensibilidade",\
    "Чувствительность",\
    "Hassasiyet",\
    "感度",
};

const char *AINormalMode[MAX_LANGUAGE] = { \
    "常规",\
    "Conventional",\
    "Konventionell",\
    "Convencional",\
    "Conventionnel",\
    "Convenzionale",\
    "Convencional",\
    "Обычный",\
    "Standart",\
    "通常",
};

const char *AIProMode[MAX_LANGUAGE] = { \
    "专业",\
    "Professional",\
    "Fach",\
    "Profesional",\
    "Professionnel",\
    "Professionale",\
    "Profissional",\
    "Профессиональный",\
    "Profesyonel",\
    "プロフェッショナル",
};

const char *FirstLayerDetection[MAX_LANGUAGE] = { \
    "首层检测",\
    "First layer detection",\
    "Erkennung der ersten Schicht",\
    "Detección de la primera capa",\
    "Détection de la première couche",\
    "Rilevamento del primo strato",\
    "Detecção de primeira camada",\
    "Обнаружение первого слоя",\
    "İlk katman tanısı",\
    "第1層検出"
};

const char *FlowCalibration[MAX_LANGUAGE] = { \
    "流量校准",\
    "Motion Advance",\
    "Bewegung Vorlauf",\
    "Avance de movimiento",\
    "Avance du mouvement",\
    "Avanzamento del movimento",\
    "Avanço de Movimento",\
    "Опережение движения",\
    "Hareket İlerleme",\
    "流量校正"
};

const char *FlowCalibrationTips[MAX_LANGUAGE] = { \
    "(仅支持Creality Print)",\
    "(Supports Creality Print only)",\
    "(Unterstützt nur Creality Print)",\
    "(Sólo compatible con Creality Print)",\
    "(Prise en charge de Creality Print uniquement)",\
    "(Supporta solo Creality Print)",\
    "(Suporta apenas Creality Print)",\
    "(Поддерживается только Creality Print)",\
    "(Yalnızca Creality Print'i destekler)",\
    "(Creality Printのみ対応)",
};

const char *AIDetectionTips[MAX_LANGUAGE] = { \
    "打印过程中可以通过AI检测打印中的异常情况。",\
    "Abnormalities in printing can be detected by AI during the printing process.",\
    "Anomalien beim Druck können von KI während des Druckvorgangs erkannt werden.",\
    "La IA puede detectar anormalidades de la impresión durante el proceso de impresión.",\
    "Les anomalies d'impression peuvent être détectées par l'IA pendant le processus d'impression.",\
    "Le anomalie nella stampa possono essere rilevate dall'AI durante il processo di stampa.",\
    "Anormalidades na impressão podem ser detectadas pela IA durante o processo de impressão.",\
    "Аномалии в печати могут обнаруживаться ИИ во время печати",\
    "Yazdırma sırasında karşılaşılan anormallikler yazdırma işlemi sırasında yapay zeka tarafından algılanabilir.",\
    "AIは、印刷中に印刷の異常を検出するために使用できます。"
};

const char *AIPausePrint[MAX_LANGUAGE] = { \
    "故障暂停打印",\
    "Printing paused due to faults",\
    "Druckvorgang aufgrund von Fehlern unterbrochen",\
    "Impresión suspendida debido a errores",\
    "Impression suspendue en raison de défauts",\
    "Stampa sospesa a causa di guasti",\
    "Impressão suspensa devido a falhas",\
    "Печать приостановлена из-за сбоев",\
    "Arızalar nedeniyle yazdırma işlemi askıya alındı",\
    "故障一時停止印刷"
};

const char *CopyProcess[MAX_LANGUAGE] = { \
    "正在复制文件", \
    "Copying", \
    "Kopieren", \
    "Copiando", \
    "Copier", \
    "Copiare", \
    "Copiando", \
    "Копирование", \
    "Kopyalanıyor", \
    "ファイルをコピー中"
};

const char *CopyErrorResult[MAX_LANGUAGE] = { \
    "失败", \
    "Failure", \
    "Störung", \
    "Error", \
    "Échec", \
    "Guasto", \
    "Falha", \
    "Сбой", \
    "Arıza", \
    "失敗例"
};

const char *Nocamera[MAX_LANGUAGE] = { \
    "未检测到摄像头", \
    "No camera detected", \
    "Keine Kamera erkannt", \
    "No se detectó ninguna cámara", \
    "Pas de caméra détectée", \
    "Nessuna videocamera rilevata", \
    "Nenhuma câmera detectada", \
    "Камера не обнаружена", \
    "Kamera algılanmadı", \
    "カメラ未検出"
};

const char *NoLaser[MAX_LANGUAGE] = { \
    "未检测到激光雷达", \
    "No Lidar detected", \
    "Kein Lidar entdeckt", \
    "No se detectó lídar", \
    "Pas de Lidar détecté", \
    "Nessun Lidar rilevato", \
    "Nenhum Lidar detectado", \
    "Лидар не обнаружен", \
    "Lidar tespit edilmedi", \
    "レーザーレーダー未検出"
};

/***********************about device****************************/
const char *DeviceNameArray[MAX_LANGUAGE] = { \
    "设备名称",\
    "Device Name",\
    "Gerätebezeichnung",\
    "Nombre",\
    "Nom",\
    "Nome dispositivo",\
    "Nome",\
    "Имя устройства",\
    "Cihaz Adı",\
    "デバイス名",
};

const char *DeviceModelArray[MAX_LANGUAGE] = { \
    "机器型号",\
    "Machine Model",\
    "Gerätemodell",\
    "Machine Model",\
    "Modèle de machine",\
    "Modello macchina",\
    "Modelo da Máquina",\
    "Модель машины",\
    "Makine Modeli",\
    "マシンモデル"
};

const char *Version[MAX_LANGUAGE] = { \
    "版本",\
    "version",\
    "Version",\
    "versión",\
    "version",\
    "versione",\
    "versão",\
    "версия",\
    "versiyon",\
    "バージョン"
};

const char *FirmwareVersion[MAX_LANGUAGE] = { \
    "固件版本",\
    "Firmware version",\
    "Firmware-version",\
    "Versión firmware",\
    "Version du firmware",\
    "Versione firmware",\
    "Versão de firmware",\
    "Версия прошивки",\
    "Yazılım sürümü",\
    "ファームウェアバージョン"
};

const char *SerialNumber[MAX_LANGUAGE] = { \
    "SN",\
    "SN",\
    "SN",\
    "SN",\
    "SN",\
    "SN",\
    "SN",\
    "SN",\
    "SN",\
    "SN",
};

const char *MacAddrArray[MAX_LANGUAGE] = { \
    "Mac",\
    "Mac",\
    "Mac",\
    "Mac",\
    "Mac",\
    "Mac",\
    "Mac",\
    "Mac",\
    "Mac",\
    "マック"
};

const char *CumulativeTime[MAX_LANGUAGE] = { \
    "累计打印",\
    "Total time",\
    "Gesamtzeit",\
    "Tiempo total",\
    "Temps total",\
    "Tempo totale",\
    "Tempo total",\
    "Общее время",\
    "Toplam zaman",\
    "総時間",
};

const char *StorageArray[MAX_LANGUAGE] = { \
    "存储空间",\
    "Storage space",\
    "Speicherplatz",\
    "Espacio de memoria",\
    "Espace mémoire",\
    "Spazio di memoria",\
    "Espaço de memória",\
    "Объем памяти",\
    "Bellek boyutu",\
    "収納スペース"
};

/*************************reset machine********************************/
const char *ResetArray[MAX_LANGUAGE] = { \
    "恢复",\
    "Restore",\
    "Wiederherstellen",\
    "Restaurar",\
    "Restaurer",\
    "Ripristina",\
    "Restaurar",\
    "Восстановить",\
    "Geri yükle",\
    "リカバリー"
};

const char *RecordsArray[MAX_LANGUAGE] = { \
    "打印记录",\
    "Print Log",\
    "Druckprotokoll",\
    "Imprimir registro",\
    "Journal d'impression",\
    "Stampa registro",\
    "Registro de Impressão",\
    "Журнал печати",\
    "Günlüğü Yazdır",\
    "ログを印刷する"
};

const char *FileArray[MAX_LANGUAGE] = { \
    "Gcode文件",\
    "Gcode files",\
    "Gcode-Dateien",\
    "Archivos Gcode",\
    "Fichiers Gcode",\
    "File Gcode",\
    "Arquivos Gcode",\
    "Файлы G-кода",\
    "Gcode dosyaları",\
    "Gcodeファイル"
};

const char *CleanItemArray[MAX_LANGUAGE] = { \
    "清除选项",\
    "Cleanup Option",\
    "Option Bereinigung",\
    "Opción de limpieza",\
    "Option de nettoyage",\
    "Opzione di pulizia",\
    "Opção de Limpeza",\
    "Вариант очистки",\
    "Temizleme Seçeneği",\
    "クリアオプション"
};

const char *DelayPhotographVedioes[MAX_LANGUAGE] = { \
    "延时摄影视频",\
    "Time-lapse video",\
    "Zeitraffer-Video",\
    "Vídeo de time-lapse",\
    "Vidéo Time-lapse",\
    "Video in time-lapse",\
    "Vídeo temporizado",\
    "Покадровое видео",\
    "Hızlandırılmış video",\
    "タイムラプス動画"
};

/*************************device binding*************************************/
const char *DeviceBindTipsMsg[MAX_LANGUAGE] = { \
    "请使用创想云APP扫码绑定设备",\
    "Please scan the code to bind your device using the Creality Cloud",\
    "Bitte scannen Sie den Code, um Ihr Gerät unter Verwendung der Creality Cloud zu binden",\
    "Escanee el código para vincular el dispositivo usando Creality Cloud",\
    "Veuillez scanner le code pour lier votre appareil à l'aide de Creality Cloud",\
    "Eseguire la scansione del codice per associare il dispositivo utilizzando Creality Cloud",\
    "Escaneie o código para vincular seu dispositivo usando a Creality Cloud",\
    "Отсканируйте код, чтобы привязать устройство с помощью Creality Cloud",\
    "Creality Cloud'u kullanarak cihazınızı bağlamak için lütfen kodu tarayın",\
    "Creality Cloudアプリでコードをスキャンしてデバイスをバインドしてください"
};

/*************************touch tone***********************/
const char *TouchToneArray[MAX_LANGUAGE] = { \
    "按键音", \
    "Touch tone", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};
const char *TouchToneSwitch[MAX_LANGUAGE] = { \
    "按键音开关", \
    "Touch tone switch", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *VolumeArray[MAX_LANGUAGE] = { \
    "音量", \
    "Volume", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};
const char *SoundEffect[MAX_LANGUAGE] = { \
    "音效", \
    "Sound effect", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};
const char *Technology[MAX_LANGUAGE] = { \
    "科技", \
    "Technology", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};
const char *Agile[MAX_LANGUAGE] = { \
    "灵动", \
    "Agile", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};
const char *Brief[MAX_LANGUAGE] = { \
    "简短", \
    "Brief", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *Crisp[MAX_LANGUAGE] = { \
    "清脆", \
    "Crisp", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};


/*************************settings***********************/
const char *SystemArray[MAX_LANGUAGE] = { \
    "系统",\
    "System",\
    "System",\
    "Sistema",\
    "Système",\
    "Sistema",\
    "Sistema",\
    "Система",\
    "Sistem",\
    "システム"
};

const char *NetworkArray[MAX_LANGUAGE] = { \
    "网络",\
    "Network",\
    "Netzwerk",\
    "Red",\
    "Réseau",\
    "Rete",\
    "Rede",\
    "Сеть",\
    "Ağ",\
    "ネットワーク"
};

const char *ScreenBrightnessArray[MAX_LANGUAGE] = { \
    "屏幕亮度",\
    "Screen Brightness",\
    "Bildschirm-Helligkeit",\
    "Brillo de la pantalla",\
    "Luminosité de l'écran",\
    "Luminosità schermo",\
    "Brilho da Tela",\
    "Яркость экрана",\
    "Ekran Parlaklığı",\
    "画面の明るさ"
};

const char *ScreenOffArray[MAX_LANGUAGE] = { \
    "息屏",\
    "Screen off",\
    "Bildschirm aus",\
    "Pantalla apagada",\
    "Écran éteint",\
    "Schermo spento",\
    "Tela desligada",\
    "Отключения экрана",\
    "Ekran kapalı",\
    "スクリーンスタンバイ"
};

const char *NoOptArray[MAX_LANGUAGE] = { \
    "无操作", \
    "No action", \
    "No action", \
    "No action", \
    "No action", \
    "No action", \
    "No action", \
    "8", \
    "No action", \
    "No action"
};

const char *MinuteArray[MAX_LANGUAGE] = { \
    "分钟",\
    " minutes",\
    " Minuten",\
    " minutos",\
    " minutes",\
    " minuti",\
    " minutos",\
    " минут",\
    " dakika",\
    "分"
};

const char *FullScreenArray[MAX_LANGUAGE] = { \
    "全屏模式", \
    "Full Screen", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *TimeZoneArray[MAX_LANGUAGE] = { \
    "时区设置",\
    "Time Zone Settings",\
    "Einstellungen für die Zeitzone",\
    "Configuración de zona horaria",\
    "Paramètres du fuseau horaire",\
    "Impostazioni fuso orario",\
    "Configurações de Fuso Horário",\
    "Настройки часового пояса",\
    "Zaman Dilimi Ayarları",\
    "タイムゾーン設定"
};

const char *TopicArray[MAX_LANGUAGE] = { \
    "主题", \
    "Topic", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

const char *VersionArray[MAX_LANGUAGE] = { \
    "版本检测",\
    "Version checking",\
    "Version prüfen",\
    "Comprobación de la versión",\
    "Vérification de la version",\
    "Controllo della versione",\
    "Verificação da versão",\
    "Проверка версии",\
    "Versiyon kontrolü",\
    "バージョン検出"
};

const char *DeviceSelfTestArray[MAX_LANGUAGE] = { \
    "设备自检",\
    "Self-check",\
    "Selbstprüfung",\
    "Auto inspección",\
    "Vérification automatique",\
    "Auto-ispezione",\
    "Auto-inspeção",\
    "Самопроверка",\
    "Kendiliğinden kontrol",\
    "機器セルフチェツク",
};

const char *UpdateReminder[MAX_LANGUAGE] = { \
    "更新提醒",\
    "Update reminder",\
    "Aktualisierungs-Erinnerung",\
    "Recordatorio de actualización",\
    "Rappel de mise à jour",\
    "Promemoria aggiornamento",\
    "Lembrete de atualização",\
    "Напоминание об обновлении",\
    "Güncelleme anımsatıcısı",\
    "アップデートリマインダー",
};

const char *UnConnectedArray[MAX_LANGUAGE] = { \
    "未连接",\
    "Not connected",\
    "Nicht verbunden",\
    "Not connected",\
    "Non connecté",\
    "Non connesso",\
    "Não conectado",\
    "Не подключено",\
    "Bağlı değil",\
    "接続されていない"
};

const char *ConnectedArray[MAX_LANGUAGE] = { \
    "已连接",\
    "Connected",\
    "Verbunden",\
    "Conectada",\
    "Connecté",\
    "Connesso",\
    "Conectado",\
    "Подключено",\
    "Bağlı",\
    "接続済み"
};

const char *Wifiname[MAX_LANGUAGE] = { \
    "WIFI名称",\
    "WIFI name",\
    "WLAN-Name",\
    "Nombre de la WIFI",\
    "Nom WIFI",\
    "Nome WIFI",\
    "Nome do Wi-Fi",\
    "Имя Wi-Fi",\
    "WIFI adı",\
    "WIFI名"
};

const char *InputPasswordMsg[MAX_LANGUAGE] = { \
    "请输入密码",\
    "Please enter your password",\
    "Bitte wechseln Sie Ihr Passwort",\
    "Escriba su contraseña",\
    "Veuillez saisir votre mot de passe",\
    "Inserisci la password",\
    "Digite sua senha",\
    "Введите пароль",\
    "Lütfen parolanızı girin",\
    "パスワードを入力してください"
};

const char *NetworkConnect[MAX_LANGUAGE] = { \
    "网络连接", \
    "Network connection", \
    "Netzwerkanschluss", \
    "Conexión a la red", \
    "Connexion réseau", \
    "Connessione di rete", \
    "Conexão de rede", \
    "Подключение к сети", \
    "Ağ bağlantısı", \
    "ネットワーク接続"
};

const char *ConnectOptArray[MAX_LANGUAGE] = { \
    "连接", \
    "Connect", \
    "Verbindung herstellen", \
    "Conectar", \
    "Connecter", \
    "Connetti", \
    "Conectar", \
    "Подключить", \
    "Bağlan", \
    "接続"
};

const char *DisconnectOptArray[MAX_LANGUAGE] = { \
    "断开", \
    "Disconnected", \
    "Getrennt", \
    "Desconectado", \
    "Déconnecté", \
    "Disconnesso", \
    "Desconectado", \
    "Отключено", \
    "Bağlantı kesildi", \
    "切断"
};

const char *PasswordError[MAX_LANGUAGE] = { \
    "密码错误", \
    "Password error", \
    "Passwortfehler", \
    "Error de la contraseña", \
    "Erreur de mot de passe", \
    "Errore password", \
    "Erro de palavra-passe", \
    "Ошибка пароля", \
    "Parola hatası", \
    "パスワードエラー"
};

const char *PasswordTooShort[MAX_LANGUAGE] = { \
    "密码长度过低", \
    "Password length too short", \
    "Passwortlänge zu kurz", \
    "Longitud de la contraseña demasiado corta", \
    "Longueur du mot de passe trop courte", \
    "Lunghezza password troppo corta", \
    "Comprimento da senha muito curto", \
    "Слишком короткий пароль", \
    "Şifre uzunluğu çok kısa", \
    "パスワード長が短すぎ"
};

const char *PasswordLenLimit[MAX_LANGUAGE] = { \
    "密码长度需在8~64位之间", \
    "Password length must be between 8 and 64 characters", \
    "Die Passwortlänge muss zwischen 8 und 64 Zeichen liegen", \
    "La longitud de la contraseña debe estar entre 8 y 64 caracteres", \
    "La longueur du mot de passe doit être comprise entre 8 et 64 caractères", \
    "La lunghezza della password deve essere tra 8 e 64 caratteri", \
    "O comprimento da senha deve estar entre 8 e 64 caracteres", \
    "Длина пароля должна быть от 8 до 64 символов", \
    "Şifre uzunluğu 8 ile 64 karakter arasında olmalıdır", \
    "パスワードの長さは8から64文字の間でなければなりません", 
};

const char *ForgetPasswordArray[MAX_LANGUAGE] = { \
    "忽略", \
    "Forget", \
    "Esquecer", \
    "Vergessen", \
    "Забыть", \
    "Olvidar", \
    "Oublier", \
    "Unutmak", \
    "Dimenticare", \
    "忘れる"
};

const char *OtherNetwork[MAX_LANGUAGE] = { \
    "其他...", \
    "Other...", \
    "Andere...", \
    "Otros...", \
    "Autre...", \
    "Altro...", \
    "Outros...", \
    "Другое...", \
    "Diğer...", \
    "その他...",\
    "기타...",\
};

const char *ToChangeFilament[MAX_LANGUAGE] = { \
    "去换料",\
    "Refill",\
    "Nachfüllen",\
    "Volver a llenar",\
    "Rechargez",\
    "Riempire",\
    "Recarga",\
    "Пополнить",\
    "Doldur",\
    "消耗品交換に行く"
};

const char *NotSetArray[MAX_LANGUAGE] = { \
    "不设置",\
    "No setting",\
    "Keine Einstellung",\
    "Sin configuración",\
    "Aucun paramétrage",\
    "Nessuna impostazione",\
    "Nenhuma configuração",\
    "Нет настройки",\
    "Ayar yok",\
    "未設定"
};

const char *LocalNetworkArray[MAX_LANGUAGE] = { \
    "本地网络",\
    "Ethernet",\
    "Ethernet",\
    "Ethernet",\
    "Ethernet",\
    "Ethernet",\
    "Ethernet",\
    "Ethernet",\
    "Ethernet",\
    "イーサネット"
};

/*************************update version***********************/
const char *NewVersionArray[MAX_LANGUAGE] = { \
    "新版本", \
    "New Version", \
    "Neue Version", \
    "Nueva versión", \
    "Nouvelle version", \
    "Nuova versione", \
    "Versão Nova", \
    "Новая версия", \
    "Yeni Versiyon", \
    "新版"
};
const char *LastVersionArray[MAX_LANGUAGE] = { \
    "最新版本", \
    "Latest Version", \
    "Neueste Version", \
    "Última versión", \
    "Dernière version", \
    "Ultima versione", \
    "Versão Mais Recente", \
    "Последняя версия", \
    "Güncel Versiyon", \
    "最新版"
};
const char *UpgradeArray[MAX_LANGUAGE] = { \
    "升级", \
    "Upgrade", \
    "Aufrüstung", \
    "Actualizar", \
    "Mise à jour", \
    "Aggiornamento", \
    "Atualizar", \
    "Обновление", \
    "Yükselt", \
    "アップデート"
};

const char *Download[MAX_LANGUAGE] = { \
    "下载",\
    "Download",\
    "Herunterladen",\
    "Descargar",\
    "Télécharger",\
    "Scarica",\
    "Baixar",\
    "Скачать",\
    "İndir",\
    "ダウンロード"
};

const char *Downloading[MAX_LANGUAGE] = { \
    "下载中", \
    "Downloading", \
    "Herunterladen", \
    "Descargando", \
    "Téléchargement", \
    "Download in corso", \
    "Baixando", \
    "Загрузка", \
    "İndiriliyor", \
    "ダウンロード中"
};

const char *DownloadSuccess[MAX_LANGUAGE] = { \
    "下载成功", \
    "Download successfully", \
    "Herunterladen erfolgreich", \
    "Descarga exitosa", \
    "Télécharger avec succès", \
    "Download riuscito", \
    "Transferido com sucesso", \
    "Успешно загружено", \
    "Başarıyla indirildi", \
    "ダウンロード成功"
};

const char *DownloadFailed[MAX_LANGUAGE] = { \
    "下载失败", \
    "Download failed", \
    "Herunterladen fehlgeschlagen", \
    "Descarga fallida", \
    "Échec du téléchargement", \
    "Download non riuscito", \
    "Falha de download", \
    "Сбой загрузки", \
    "İndirme başarısız", \
    "ダウンロード失敗"
};

const char *Unpacking[MAX_LANGUAGE] = { \
    "解压中", \
    "Decompressing", \
    "Dekomprimieren", \
    "Descompresión en progreso", \
    "Décompression", \
    "Decompressione in corso", \
    "Descomprimindo", \
    "Декомпрессия", \
    "Boşaltılıyor", \
    "解凍中"
};

const char *UnpackSuccess[MAX_LANGUAGE] = { \
    "解压完成", \
    "Decompression completed", \
    "Dekomprimierung abgeschlossen", \
    "Descompresión finalizada", \
    "Décompression achevée", \
    "Decompressione completata", \
    "Descompressão concluída", \
    "Декомпрессия выполнена", \
    "Boşaltma tamamlandı", \
    "解凍完了"
};

const char *UnpackFailed[MAX_LANGUAGE] = { \
    "解压失败", \
    "Decompression failed", \
    "Dekompression fehlgeschlagen", \
    "Descompresión fallida", \
    "La décompression a échoué", \
    "Decompressione non riuscita", \
    "Falha de descompressão", \
    "Сбой декомпрессии", \
    "Boşaltma başarısız", \
    "解凍失敗"
};

const char *Installing[MAX_LANGUAGE] = { \
    "安装中", \
    "Installing", \
    "Installation", \
    "Instalando", \
    "Installation", \
    "Installazione in corso", \
    "Instalando", \
    "Установка", \
    "Kuruluyor", \
    "インストール中"
};

const char *InstallSuccess[MAX_LANGUAGE] = { \
    "安装完成", \
    "Installation completed", \
    "Installation abgeschlossen", \
    "Instalación finalizada", \
    "Installation achevée", \
    "Installazione completata", \
    "Instalação concluída", \
    "Установка выполнена", \
    "Kurulum tamamlandı", \
};

const char *InstallFailed[MAX_LANGUAGE] = { \
    "安装失败", \
    "Installation failed", \
    "Installation fehlgeschlagen", \
    "Instalación fallida", \
    "Échec de l'installation", \
    "Installazione non riuscita", \
    "Falha de instalação", \
    "Сбой установки", \
    "Kurulum başarısız", \
    "インストール失敗"
};

const char *CurVersionIsLastest[MAX_LANGUAGE] = { \
    "当前已是最新版本",\
    "Currently the latest version",\
    "Derzeit die aktuellste Version",\
    "Currently the latest version",\
    "Dernière version en cours",\
    "Attualmente è la versione più recente",\
    "É a versão mais recente",\
    "Это последняя версия",\
    "Şu anda güncel versiyon yüklü",\
    "最新のバージョンが既にインストールされています。"
};

const char *DiscoverNewVersionArray[MAX_LANGUAGE] = { \
    "发现新版本", \
    "New version is found", \
    "Neue Version gefunden", \
    "Se encontró una nueva versión", \
    "Nouvelle version trouvée", \
    "È stata trovata una nuova versione", \
    "Nova versão encontrada", \
    "Найдена новая версия", \
    "Yeni versiyon bulundu", \
    "新版検出"
};


/*************************export log***********************/
const char *LogExportingMsg[MAX_LANGUAGE] = { \
    "日志导出中", \
    "Log export in progress", \
    "Log-Export läuft", \
    "Exportación de registro en progreso", \
    "Exportation de journal en cours", \
    "Esportazione registro in corso", \
    "Exportação do registro em andamento", \
    "Выполняется экспорт журнала", \
    "Günlük dışa aktarma devam ediyor", \
    "ログエクスポート中"
};

const char *LogExporCompressing[MAX_LANGUAGE] = { \
    "压缩中", \
    "Compressing", \
    "Komprimieren", \
    "Comprimiendo", \
    "Compression en cours", \
    "Compressione in corso", \
    "Comprimindo", \
    "Сжатие", \
    "Sıkıştırılıyor", \
    "圧縮中"
};

const char *LogExportSuccessMsg[MAX_LANGUAGE] = { \
    "日志导出成功", \
    "Logs export succeeded", \
    "Log-Export erfolgreich", \
    "Exportación de registros exitosa", \
    "L\'exportation du journal a réussi", \
    "Esportazione dei registri riuscita", \
    "Registros exportados com sucesso", \
    "Экспорт журналов выполнен", \
    "Günlük dışa aktarma başarılı", \
    "ログのエクスポートに成功しました"
};

const char *LogExportFailedMsg[MAX_LANGUAGE] = { \
    "日志导出失败", \
    "Log export failed", \
    "Log-Export fehlgeschlagen", \
    "Exportación de registro fallida", \
    "Échec de l'exportation du journal", \
    "Esportazione del registro non riuscita", \
    "Falha ao exportar registros", \
    "Сбой экспорта журнала", \
    "Günlük dışa aktarma başarısız", \
    "ログのエクスポートに失敗しました"
};

const char *DiskUMsg[MAX_LANGUAGE] = { \
    "U盘不存在!", \
    "USB flash drive does not exist!", \
    "USB-Stick existiert nicht!", \
    "No se encontró la unidad USB", \
    "Le disque flash USB n'est pas existant !", \
    "L'unità flash USB non esiste!", \
    "Não exite unidade USB!", \
    "Флэш-накопитель USB не существует!", \
    "USB bellek mevcut değil!", \
    "USBメモリが存在しません！"
}; 

const char *LogUploadingMsg[MAX_LANGUAGE] = { \
    "正在上传中",\
    "Uploads in progress",\
    "Hochladen in Bearbeitung",\
    "Cargas en curso",\
    "Téléversements en cours",\
    "Caricamenti in corso",\
    "Envios em andamento",\
    "Выполняется загрузка",\
    "Yüklemeler işleniyor",\
    "アップロード中"
}; 

const char *VideoExportingMsg[MAX_LANGUAGE] = { \
    "正在导出文件",\
    "Export succeeded",\
    "Export erfolgreich",\
    "Exportación correcta",\
    "Exportation effectuée avec succès",\
    "Esportazione riuscita",\
    "Exportação bem sucedida",\
    "Экспорт выполнен",\
    "Dışa aktarım başarılı",\
    "エクスポート成功"
};

const char *VideoExportSuccessMsg[MAX_LANGUAGE] = { \
    "导出成功",\
    "Export failed",\
    "Export fehlgeschlagen",\
    "Error en la exportación",\
    "Échec de l'exportation",\
    "Esportazione non riuscita",\
    "Falha ao exportar",\
    "Экспорт не выполнен",\
    "Dışa aktarım başarısız",\
    "エクスポート失敗"
}; 

const char *VideoExportFailedMsg[MAX_LANGUAGE] = { \
    "导出失败", \
    "Upload failed", \
    "Hochladen fehlgeschlagen", \
    "Error en la subida", \
    "Échec du téléversement", \
    "Caricamento non riuscito", \
    "Falha de envio", \
    "Не удалось загрузить", \
    "Yükleme başarısız", \
    "アップロードに失敗しました"
};

const char *LogUploadSuccessMsg[MAX_LANGUAGE] = { \
    "上传成功",\
    "Upload successful",\
    "Hochladen erfolgreich",\
    "Subida correcta",\
    "Téléversement effectué avec succès",\
    "Caricamento riuscito",\
    "Enviado com sucesso",\
    "Успешно загружено",\
    "Yükleme başarılı",\
    "アップロード成功"
}; 

const char *VideoUploadingMsg[MAX_LANGUAGE] = { \
    "正在上传中",\
    "Uploads in progress",\
    "Hochladen in Bearbeitung",\
    "Cargas en curso",\
    "Téléversements en cours",\
    "Caricamenti in corso",\
    "Envios em andamento",\
    "Выполняется загрузка",\
    "Yüklemeler işleniyor",\
    "アップロード中",
}; 

const char *VideoUploadSuccessMsg[MAX_LANGUAGE] = { \
    "上传成功",\
    "Upload successful",\
    "Hochladen erfolgreich",\
    "Subida correcta",\
    "Téléversement effectué avec succès",\
    "Caricamento riuscito",\
    "Enviado com sucesso",\
    "Успешно загружено",\
    "Yükleme başarılı",\
    "アップロード成功",
}; 

const char *VideoUploadFailedMsg[MAX_LANGUAGE] = { \
    "上传失败", \
    "Upload failed", \
    "Hochladen fehlgeschlagen", \
    "Error en la subida", \
    "Échec du téléversement", \
    "Caricamento non riuscito", \
    "Falha de envio", \
    "Не удалось загрузить", \
    "Yükleme başarısız", \
    "アップロードに失敗しました",
};

const char *DontCXYUserInfo[MAX_LANGUAGE] = { \
    "您需要先绑定创想云", \
    "You need to bind the Creality Cloud first", \
    "Sie müssen zuerst die Creality Cloud binden", \
    "Es necesario vincular primero a Creality Cloud", \
    "Vous devez d'abord lier le Creality Cloud", \
    "Devi prima associare Creality Cloud", \
    "Você precisa vincular a Creality Cloud primeiro", \
    "Сначала необходимо привязать Creality Cloud", \
    "Önce Creality Cloud'u bağlamanız gerekli", \
    "先ずCreality Cloudにバインドしてください"
}; 

const char *DontNetwork[MAX_LANGUAGE] = { \
    "您需要先联网", \
    "You need to connect to the internet first", \
    "Sie müssen zuerst eine Verbindung zum Internet herstellen", \
    "Es necesario conectarse primero a Internet", \
    "Vous devez d'abord vous connecter à l'internet", \
    "È necessario prima connettersi a Internet", \
    "Você precisa se conectar à Internet primeiro", \
    "Сначала необходимо подключиться к Интернету", \
    "Önce internete bağlanmanız gerekli", \
    "先ずネットワークに接続する必要があります"
}; 

const char *LogUploadFailedMsg[MAX_LANGUAGE] = { \
    "上传失败", \
    "Upload failed", \
    "Hochladen fehlgeschlagen", \
    "Error en la subida", \
    "Échec du téléversement", \
    "Caricamento non riuscito", \
    "Falha de envio", \
    "Не удалось загрузить", \
    "Yükleme başarısız", \
    "アップロードに失敗しました"
}; 

/*************************self test***********************/
const char *VibrationCompensation[MAX_LANGUAGE] = { \
    "振纹优化",\
    "Input Shaping",\
    "Eingang Formgebung",\
    "Introducir forma",\
    "Mise en forme de l'entrée",\
    "Modellamento dell'ingresso",\
    "Entrar Forma",\
    "Формирование ввода",\
    "Girdi Şekillendirme",\
    "振動パターンの最適化"
}; 

const char *TurnOnModelFan[MAX_LANGUAGE] = { \
    "开启模型冷却风扇", \
    "Turn on model cool fan", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
}; 

const char *TurnOnThroatFan[MAX_LANGUAGE] = { \
    "开启喉管散热风扇", \
    "Turn on throat cool fan", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
}; 

const char *SelfTestTipsMsg[MAX_LANGUAGE] = { \
    "自检过程预计需要 #42bdd8 15# 分钟左右", \
    "The self-check process is expected to take around #42bdd8 15# minute", \
    "Der Selbstprüfungsablauf wird voraussichtlich etwa #42bdd8 15# Minuten dauern", \
    "El proceso de la prueba automática se espera que tarde unos #42bdd8 15# minutos", \
    "Le processus d'auto-test devrait durer environ #42bdd8 15# minutes", \
    "Il processo di autotest richiede circa #42bdd8 15# minuti", \
    "Espera-se que o processo de autoteste leve cerca de #42bdd8 15# minutos", \
    "Процесс самопроверки займет около #42bdd8  15# минут", \
    "Otomatik test işleminin yaklaşık #42bdd8 15# dakika sürmesi bekleniyor", \
    "自己診断の所要時間は約 #42bdd8 15# 分程度を予定しています"
};  


const char *SelectAll[MAX_LANGUAGE] = { \
    "全选",\
    "Select All",\
    "Alles auswählen",\
    "Seleccionar todo",\
    "Sélectionner tout",\
    "Seleziona tutto",\
    "Selecionar Tudo",\
    "Выбрать все",\
    "Tümünü seç",\
    "すべて選択"
}; 

const char *NotSelectAll[MAX_LANGUAGE] = { \
    "全不选",\
    "Unselect All",\
    "Alle abwählen",\
    "Deseleccionar todo",\
    "Désélectionner tout",\
    "Deseleziona tutto",\
    "Desfazer Toda Seleção",\
    "Снять все",\
    "Tüm seçimleri kaldır",\
    "すべての選択を解除"
};  

const char *DetectionItemArray[MAX_LANGUAGE] = { \
    "检测选项",\
    "Detecting options",\
    "Optionen erkennen",\
    "Opciones de detección",\
    "Détection des options",\
    "Rilevamento delle opzioni",\
    "Detectando opções",\
    "Параметры обнаружения",\
    "Tespit seçenekleri",\
    "検出オプション"
}; 
const char *HomeArray[MAX_LANGUAGE] = { \
    "归位", \
    "Home", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};               //
const char *XY_HomeArray[MAX_LANGUAGE] = { \
    "XY轴归位", \
    "Return to XY axis", \
    "Zurück zur XY-Achse", \
    "Volver al eje XY", \
    "Retour à l'axe XY", \
    "Torna all'asse XY", \
    "Voltar para o eixo XY", \
    "Вернуться к оси XY", \
    "XY eksene dön", \
    "XY軸に戻る"
}; 
         
const char *Z_HomeArray[MAX_LANGUAGE] = { \
    "Z轴归位", \
    "Z-axis return", \
    "Z-Achse zurückkehren", \
    "Volver al eje Z", \
    "Retour à l'axe Z", \
    "Ritorno all'asse Z", \
    "Retorno ao eixo Z", \
    "Возврат на ось Z", \
    "Z ekseni geri dönüş", \
    "Z軸の復帰"
};             
const char *ProbeArray[MAX_LANGUAGE] = { \
    "探头", \
    "Probe", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};              //
const char *RunoutArray[MAX_LANGUAGE] = { \
    "断料", \
    "Runout", \
    "3", \
    "4", \
    "5", \
    "6", \
    "7", \
    "8", \
    "9", \
    ""
};

/*************************network info***********************/
const char *IPAddrArray[MAX_LANGUAGE] = { \
    "IP地址",\
    "IP address",\
    "IP-Adresse",\
    "Dirección IP",\
    "Adresse IP",\
    "Indirizzo IP",\
    "Endereço de IP",\
    "IP-адрес",\
    "IP adresi",\
    "IPアドレス"
};

const char *DNSServerArray[MAX_LANGUAGE] = { \
    "DNS服务器",\
    "DNS Server",\
    "DNS-Server",\
    "Servidor DNS",\
    "Serveur DNS",\
    "Server DNS",\
    "Servidor DNS",\
    "DNS-сервер",\
    "DNS Sunucu",\
    "DNSサーバー"
}; 

const char *SubNetMaskArray[MAX_LANGUAGE] = { \
    "子网掩码",\
    "Subnet mask",\
    "Subnetz-Maske",\
    "Máscara subred",\
    "Masque de sous-réseau",\
    "Maschera di sottorete",\
    "Máscara de subrede",\
    "Маска подсети",\
    "Alt ağ maskesi",\
    "サブネットマスク"
};

const char *GatewayArray[MAX_LANGUAGE] = { \
    "网关",\
    "Gateway",\
    "Gateway",\
    "Pasarela",\
    "Passerelle",\
    "Gateway",\
    "Gateway",\
    "Шлюз",\
    "Ağ geçidi",\
    "ゲートウェイ"
};

const char *NetworkInfoArray[MAX_LANGUAGE] = { \
    "网络详情", \
    "Network details", \
    "Netzwerk Details", \
    "Detalles de red", \
    "Détails du réseau", \
    "Dettagli della rete", \
    "Detalhes de rede", \
    "Сведения о сети", \
    "Ağ detayları", \
    "ネットワーク詳細"
};

/*************************self test tips***********************/
const char *PrinterSelfTest[MAX_LANGUAGE] = { \
    "设备自检",\
    "Self-inspection",\
    "Selbstprüfung",\
    "Auto inspección",\
    "Vérification automatique",\
    "Auto-ispezione",\
    "Auto-inspeção",\
    "Самопроверка",\
    "Kendiliğinden kontrol",\
    "デバイスのセルフテスト"
};
const char *WelcomeSelfTest[MAX_LANGUAGE] = { \
    "欢迎来到自检流程",\
    "Welcome to the self-check process",\
    "Willkommen zum Selbstprüfungsablauf",\
    "Bienvenido al proceso de prueba automática",\
    "Bienvenue dans le processus d'auto-test",\
    "Benvenuto nel processo di autotest",\
    "Bem-vindo ao processo de autoteste",\
    "Добро пожаловать в процесс самопроверки",\
    "Otomatik test işlemine hoş geldiniz",\
    "自己診断プロセスへようこそ"
}; 

const char *HeaterPurifyingTip[MAX_LANGUAGE] = { \
    "1.请放置好打印平台板；",\
    "1.Please place the printing platform",\
    "1.Bitte platzieren Sie die Druckplattform",\
    "1.Coloque la plataforma de impresión",\
    "1.Veuillez placer la plateforme d'impression",\
    "1.Posizionare la piattaforma di stampa",\
    "1.Coloque a plataforma de impressão",\
    "1.Разместите печатную платформу",\
    "1.Lütfen yazdırma platformunu yerleştirin",\
    "1.印刷用台紙を置いてください"
};

const char *SelfTestCleanTip[MAX_LANGUAGE] = { \
    "1.请保持热床和喷嘴清洁。",\
    "1.Please keep the heated bed and nozzle clean.",\
    "1.Bitte halten Sie das Heizbett und die Düse sauber.",\
    "1.Por favor, mantenga la cama caliente y la boquilla limpias.",\
    "1.Veuillez maintenir le lit chauffant et la buse propres.",\
    "1.Si prega di mantenere pulito il piano riscaldato e il nozzle.",\
    "1.Por favor, mantenha a cama aquecida e o bico limpos.",\
    "1.Пожалуйста, поддерживайте чистоту подогреваемой платформы и сопла.",\
    "1.Lütfen ısıtma yatağını ve nozu temiz tutun.",\
    "1.ヒートベッドとノズルを清潔に保ってください。"
};

const char *SelfTestTimeTip[MAX_LANGUAGE] = { \
    "2.自检过程预计需要15分钟左右",\
    "2.The self-check process is expected to take around 15 minutes",\
    "2.Der Selbstprüfungsablauf wird voraussichtlich etwa 15 Minuten dauern",\
    "2.El proceso de la prueba automática se espera que tarde unos 15 minutos",\
    "2.Le processus d'auto-test devrait durer environ 15 minutes",\
    "2.Il processo di autotest richiede circa 15 minuti",\
    "2.Espera-se que o processo de autoteste leve cerca de 15 minutos",\
    "2.Процесс самопроверки займет около 15 минут",\
    "2.Otomatik test işleminin yaklaşık 15 dakika sürmesi bekleniyor",\
    "2.自己診断の所要時間は約11分程度を予定しています"
}; 

/*************************self test network***********************/
const char *PleaseSetNetwork[MAX_LANGUAGE] = { \
    "请设置您的网络",\
    "Please set up your network",\
    "Bitte richten Sie Ihr Netzwerk ein",\
    "Configure la red",\
    "Veuillez configurer votre réseau",\
    "Configura la tua rete",\
    "Configure sua rede",\
    "Настройте сеть",\
    "Lütfen ağınızı kurun",\
    "ネットワークの設定をしてください"
}; 

const char *SettingNetwork[MAX_LANGUAGE] = { \
    "设置网络",\
    "Set up network",\
    "Netzwerk einrichten",\
    "Configurar red",\
    "Configurer le réseau",\
    "Configurare la rete",\
    "Configurar rede",\
    "Настройка сети",\
    "Ağı ayarla",\
    "ネットワークを設定する"
}; 


/*************************self test network***********************/
const char *PrivacyPolicy[MAX_LANGUAGE] = { \
    "隐私政策",\
    "Privacy Policy",\
    "Datenschutzerklärung",\
    "Política de privacidad",\
    "Politique de confidentialité",\
    "Informativa sulla privacy",\
    "Política de Privacidade",\
    "Политика конфиденциальности",\
    "Gizlilik Politikası",\
    "個人情報保護方針"
}; 

const char *ForewordArray[MAX_LANGUAGE] = { \
    "前言",\
    "Preface",\
    "Vorwort",\
    "Prefacio",\
    "Préface",\
    "Premessa",\
    "Prefácio",\
    "Введение",\
    "Giriş",\
    "序文"
};  

const char *AgreePrivacyPolicy[MAX_LANGUAGE] = { \
    "我已阅读并同意",\
    "I have read and agreed",\
    "Ich habe gelesen und zugestimmt",\
    "He leído y estoy de acuerdo",\
    "J'ai lu et accepté",\
    "Ho letto e accettato",\
    "Li e concordo",\
    "Я прочитал и согласен",\
    "Okudum ve kabul ettim",\
    "読みましたし同意します"
}; 

const char *PrivacyPolicyTips[MAX_LANGUAGE] = { \
    "需您同意#42BDD8 《隐私政策》#才能使\n用该服务",\
    "Your consent to the #42BDD8 Privacy# #42BDD8 Policy# is required to use the service",\
    "Um den Service verwenden zu können, müssen Sie der #42BDD8 Datenschutzerklärung # zustimmen.",\
    "Debe otorgar su consentimiento a la #42BDD8 Política de Privacidad # que se necesita para usar el servicio.",\
    "Votre consentement à la \n#42BDD8 Politique de confidentialité # est nécessaire pour utiliser le service.",\
    "Per utilizzare il servizio è necessario il consenso dell'utente #42BDD8 all'Informativa sulla privacy.",\
    "Seu consentimento com a \n#42BDD8 Política de Privacidade # é necessário para usar o serviço.",\
    "Для использования службы требуется предоставить согласие с \n#42BDD8 Политикой конфиденциальности.#",\
    "Servisi kullanmak için \n#42BDD8 Gizlilik Politikasını # kabul etmeniz gerekir.",\
    "あなたは、本 #42bdd8 「プライバシーポリシー」# に同意してから、始めて当該サービスを使用することができます。"
}; 
				
const char *Agree[MAX_LANGUAGE] = { \
    "同意",\
    "Agree",\
    "Zustimmen",\
    "Aceptar",\
    "Acceptez",\
    "D'accordo",\
    "Concordar",\
    "Согласиться",\
    "Kabul et",\
    "同意"
}; 
									
const char *NotAgree[MAX_LANGUAGE] = { \
    "再想想",\
    "Reconsider",\
    "Überprüfen",\
    "Reconsiderar",\
    "Reconsidérez",\
    "Riconsiderare",\
    "Reconsiderar",\
    "Передумать",\
    "Yeniden değerlendir",\
    "考え直し"
}; 

/*************************self test  result***********************/  
const char *FinishedArray[MAX_LANGUAGE] = { \
    "完成", \
    "Finish", \
    "Beenden", \
    "Terminar", \
    "Terminer", \
    "Finito", \
    "Terminar", \
    "Завершить", \
    "Bitir", \
    "完成",
};

/*************************auto level***********************/     
const char *SaveArray[MAX_LANGUAGE] = { \
    "保存", \
    "Save", \
    "Save", \
    "Save", \
    "Save", \
    "Save", \
    "Save", \
    "Save", \
    "Save", \
    "Save"
};              

/*********************auto bed pid calibration***************************/
const char *ResetUserData[MAX_LANGUAGE] = { \
    "确定要恢复出厂设置吗？",\
    "Reset All Set Or Not?",\
    "Alle Einstellungen zurücksetzen oder nicht?",\
    "Restaurar ajustes o no?",\
    "Réinitialisation d’usine ou non?",\
    "Resettare tutte le impostazioni o no?",\
    "Restaurar à fabrica",\
    "Сбросить весь набор или нет?",\
    "Tüm Ayarları Sıfırla veya Sıfırlama?",\
    "出荷時設定に復元しますか？",\
};

const char *LogOutTips[MAX_LANGUAGE] = { \
    "确定要登出吗？",\
    "Sure you want to log out?",\
    "Möchten Sie sich wirklich abmelden?",\
    "¿Confirma que desea cerrar sesión?",\
    "Vous êtes sûr de vouloir vous déconnecter ?",\
    "Sei sicuro di voler uscire?",\
    "Deseja sair?",\
    "Точно выйти?",\
    "Çıkış yapmak istediğinize emin misiniz?",\
    "本当にログアウトしますか？"
};

/*********************model fan***************************/
const char *NozzleHeating[MAX_LANGUAGE] = { \
    "喷嘴加热",\
    "Nozzle heating",\
    "Erwärmung der Düse",\
    "Calentamiento de la boquilla",\
    "Chauffage des buses",\
    "Riscaldamento ugello",\
    "Aquecimento do bico",\
    "Нагрев сопла",\
    "Ağızlık ısıtma",\
    "ノズルヒーター"
}; 

const char *BedHeating[MAX_LANGUAGE] = { \
    "热床加热", \
    "Hotbed heating", \
    "Heizbett Erwärmung", \
    "Calentamiento de la cama", \
    "Chauffage du lit chauffant", \
    "Riscaldamento del letto caldo", \
    "Aquecimento da mesa", \
    "Нагрев очага", \
    "Sıcak yatak ısıtma", \
    "ホットベッドヒーティング"
}; 
/*********************hot fan***************************/


/*********************ringing***************************/
const char *RingingTipMsg[MAX_LANGUAGE] = { \
    "检测中请勿触碰打印机",\
    "Do not touch the printer during the self-check",\
    "Berühren Sie den Drucker während der Prüfung nicht",\
    "No toque la impresora durante la prueba",\
    "Ne pas toucher l'imprimante pendant le test",\
    "Non toccare la stampante durante il test",\
    "Não toque na impressora durante o teste",\
    "Не прикасайтесь к принтеру во время проверки",\
    "Test sırasında yazıcıya dokunmayın",\
    "テスト中はプリンターに触れないようにしてください"
};  
/*********************select level points***************************/


/*********************set time***************************/
const char *UtcTime[MAX_LANGUAGE] = { \
    "UTC 时间 ", \
    "UTC Time", \
    "UTC Time", \
    "UTC Time", \
    "UTC Time", \
    "UTC Time", \
    "UTC Time", \
    "UTC Time", \
    "UTC Time", \
    "UTC Time"
};                //
const char *LocalTime[MAX_LANGUAGE] = { \
    "本地时间", \
    "Local Time", \
    "Local Time", \
    "Local Time", \
    "Local Time", \
    "Local Time", \
    "Local Time", \
    "Local Time", \
    "Local Time", \
    "Local Time"
};               


/*********************printing operation tip***************************/
const char *FOREIGN_BODY[MAX_LANGUAGE] = { \
    "异物检测中", \
    "Foreign object detection in progress", \
    "Erkennung eines Fremdkörpers läuft", \
    "Detección de objeto extraño en curso", \
    "Détection d\'un objet étranger en cours", \
    "Rilevamento di oggetti estranei in corso", \
    "Detecção de objetos estranhos em andamento", \
    "Выполняется обнаружение инородных предметов", \
    "Yabancı nesne algılama işlemi devam ediyor", \
    "異物検出中",
}; 

const char *ROUGH_G28[MAX_LANGUAGE] = { \
    "回零中", \
    "Homing...", \
    "Zur Startseite...", \
    "Iniciando...", \
    "Retour...", \
    "Ritorno alla posizione iniziale...", \
    "Retornando...", \
    "Возврат…", \
    "Sıfırlanıyor...", \
    "原点復帰中",
}; 

const char *NOZZLE_CLEAR[MAX_LANGUAGE] = { \
    "喷嘴清理中", \
    "Nozzle cleaning in progress", \
    "Reinigung der Düse läuft", \
    "Limpieza de la boquilla en curso", \
    "Nettoyage des buses en cours", \
    "Pulizia ugelli in corso", \
    "Limpeza do bocal em andamento", \
    "Выполняется очистка сопла", \
    "Nozul temizliği devam ediyor", \
    "ノズルクリーニング中",
}; 

const char *ACCURATE_G28[MAX_LANGUAGE] = { \
    "回零中", \
    "Homing...", \
    "Zur Startseite...", \
    "Iniciando...", \
    "Retour...", \
    "Ritorno alla posizione iniziale...", \
    "Retornando...", \
    "Возврат…", \
    "Sıfırlanıyor...", \
    "原点復帰中",
}; 
const char *LEVEL_DELECT[MAX_LANGUAGE] = { \
    "调平中", \
    "Leveling...", \
    "Nivellierung...", \
    "Nivelando...", \
    "Mise à niveau...", \
    "Livellamento in corso...", \
    "Nivelando...", \
    "Выравнивание…", \
    "Düzleştiriliyor...", \
    "レベリング中",
}; 

const char *LASER_CALIBRATION[MAX_LANGUAGE] = { \
    "激光标定中", \
    "Laser calibration in progress", \
    "Laserkalibrierung läuft", \
    "Calibración láser en curso", \
    "Calibrage du laser en cours", \
    "Calibrazione laser in corso", \
    "Calibração do laser em andamento", \
    "Выполняется калибровка лазера", \
    "Lazer kalibrasyonu devam ediyor", \
    "レーザ・キャリブレーション中",
}; 

const char *SCAN_TABLE[MAX_LANGUAGE] = { \
    "SCAN_TABLE", \
    "SCAN_TABLE", \
    "SCAN_TABLE", \
    "SCAN_TABLE", \
    "SCAN_TABLE", \
    "SCAN_TABLE", \
    "SCAN_TABLE", \
    "SCAN_TABLE", \
    "SCAN_TABLE", \
    "SCAN_TABLE",
}; 

const char *PRINT_LINE[MAX_LANGUAGE] = { \
    "流量校准图案打印中", \
    "Flow calibration pattern printing", \
    "Flusskalibrierung Musterdruck läuft", \
    "Impresión de modelo de calibración de caudal en curso", \
    "Calibrage du débit Impression du motif en cours", \
    "Stampa del modello di calibrazione del flusso in corso", \
    "Impressão de padrão de calibração de fluxo em andamento", \
    "Выполняется шаблонная печать с калибровкой потока", \
    "Akış kalibrasyon deseni yazdırma işlemi devam ediyor", \
    "流量校正パターン印刷中",
};

const char *COOL_DOWN[MAX_LANGUAGE] = { \
    "降温中", \
    "Cooling…", \
    "Kühlung...", \
    "Refrigerando…", \
    "Refroidissement...", \
    "Raffreddamento in corso...", \
    "Resfriando...", \
    "Охлаждение…", \
    "Soğutuluyor…", \
    "降温中",
}; 

const char *SCAN_MODEL[MAX_LANGUAGE] = { \
    "激光扫描中", \
    "Laser scanning in progress", \
    "Laserscan läuft", \
    "Escaneado láser en curso", \
    "Balayage laser en cours", \
    "Scansione laser in corso", \
    "Digitalização a laser em andamento", \
    "Выполняется лазерное сканирование", \
    "Lazer tarama işlemi devam ediyor", \
    "レーザ走査中",
}; 

const char *FLOOR_SCAN_TABLE[MAX_LANGUAGE] = { \
    "首层扫描中", \
    "First layer scanning in progress", \
    "Scannen der ersten Schicht läuft", \
    "Escaneado de la primera capa en curso", \
    "Numérisation de la première couche en cours", \
    "Scansione primo strato in corso", \
    "Digitalização da primeira camada em andamento", \
    "Выполняется сканирование первого слоя", \
    "İlk katman tarama işlemi devam ediyor", \
    "初層走査中",
}; 

const char *FLOOR_PRINT_LINE[MAX_LANGUAGE] = { \
    "正在打印首层", \
    "First layer printing in progress", \
    "Druck der ersten Schicht läuft", \
    "Primera capa de impresión en curso", \
    "Impression de la première couche en cours", \
    "Stampa primo strato in corso", \
    "Impressão da primeira camada em andamento", \
    "Выполняется печать первого слоя", \
    "İlk katman yazdırma işlemi devam ediyor", \
    "初層印刷中",
};

const char *FLOOR_COOL_DOWN[MAX_LANGUAGE] = { \
    "喷嘴降温中", \
    "Nozzle cooling in progress", \
    "Düsenkühlung läuft", \
    "Refrigeración de la boquilla en curso", \
    "Refroidissement de la buse en cours", \
    "Raffreddamento ugello in corso", \
    "Resfriamento do bocal em andamento", \
    "Выполняется охлаждение сопла", \
    "Nozul soğutma işlemi devam ediyor", \
    "ノズル降温中",
}; 

const char *FLOOR_SCAN_MODEL[MAX_LANGUAGE] = { \
    "首层扫描中", \
    "First layer scanning in progress", \
    "Scannen der ersten Schicht läuft", \
    "Escaneado de la primera capa en curso", \
    "Numérisation de la première couche en cours", \
    "Scansione primo strato in corso", \
    "Digitalização da primeira camada em andamento", \
    "Выполняется сканирование первого слоя", \
    "İlk katman tarama işlemi devam ediyor", \
    "初層走査中",
}; 

const char *FLOOR_AI_CALCULATE[MAX_LANGUAGE] = { \
    "计算中", \
    "Calculating…", \
    "Berechnen...", \
    "Calculando…", \
    "Calcul...", \
    "Calcolo in corso…", \
    "Calculando...", \
    "Расчет…", \
    "Hesaplanıyor…", \
    "計算中",
}; 

const char *FLOOR_HEAT_UP[MAX_LANGUAGE] = { \
    "喷嘴升温中", \
    "Nozzle heating in progress", \
    "Erwärmen der Düse läuft", \
    "Calentamiento de la boquilla en curso", \
    "Chauffage de la buse en cours", \
    "Riscaldamento ugello in corso", \
    "Aquecimento do bocal em andamento", \
    "Выполняется нагрев сопла", \
    "Nozul ısıtma işlemi devam ediyor", \
    "ノズル昇温中",
}; 
/*************************error**************************/
const char *ErrorCode[MAX_LANGUAGE] = { \
    "错误码",\
    "Error Code",\
    "Fehlercode",\
    "Código de error",\
    "Code d'erreur",\
    "Codice di errore",\
    "Código de Erro",\
    "Код ошибки",\
    "Hata Kodu",\
    "エラーコード"
};

const char *ErrorTime[MAX_LANGUAGE] = { \
    "时间",\
    "Time",\
    "Zeit",\
    "Tiempo",\
    "Temps",\
    "Tempo",\
    "Tempo",\
    "Время",\
    "Zaman",\
    "時間"
};

const char *ErrorBtnInfo[MAX_LANGUAGE] = { \
    "详情",\
    "Details",\
    "Details",\
    "Detalles",\
    "Détails",\
    "Dettagli",\
    "Detalhes",\
    "Подробности",\
    "Detaylar",\
    "詳細"
};

const char *ErrorBtnConfirm[MAX_LANGUAGE] = { \
    "确定", \
    "Ok", \
    "Ja",\
    "Sí",\
    "Oui",\
    "Sì",\
    "Sim",\
    "Да",\
    "Evet",\
    "確認"
};

const char *ErrorBtnFileManagement[MAX_LANGUAGE] = { \
    "前往清理", \
    "Proceed to Clean", \
    "Weiter zur Reinigung",\
    "Proceder a Limpiar",\
    "Procéder au Nettoyage",\
    "Procedere alla Pulizia",\
    "Proceder para Limpar",\
    "Перейти к Уборке",\
    "Temizlemeye Git",\
    "クリーニングへ進む",
};

const char *ErrorBtnFileIgnore[MAX_LANGUAGE] = { \
    "忽略", \
    "Forget", \
    "Esquecer", \
    "Vergessen", \
    "Забыть", \
    "Olvidar", \
    "Oublier", \
    "Unutmak", \
    "Dimenticare", \
    "忘れる",
};

const char *ErrorBtnStopPrint[MAX_LANGUAGE] = { \
    "停止打印",\
    "Stop printing",\
    "Stoppen Sie den Druck",\
    "Detener impresión",\
    "Arrêter l'impression",\
    "Interrompere la stampa",\
    "Interromper impressão",\
    "Остановить печать",\
    "Yazdırmayı durdur",\
    "印刷を中止する"
};

const char *ErrorBtnContinuePrint[MAX_LANGUAGE] = { \
    "继续打印",\
    "Continue",\
    "Weiter",\
    "Continuar",\
    "Continuer",\
    "Continua",\
    "Continuar",\
    "Продолжить",\
    "Devam",\
    "印刷続行"
};

const char *MaterialSeneorTips[MAX_LANGUAGE] = { \
    "未检测到耗材，是否继续打印",\
    "No filaments detected. Continue printing?",\
    "Keine Filamente erkannt. Weiterdrucken?",\
    "No se han detectado filamentos. ¿Continuar la impresión?",\
    "Aucun filament détecté. Poursuivre l'impression ?",\
    "Nessun filamento rilevato. Continuare la stampa?",\
    "Nenhum filamento foi detectado. Continuar a impressão?",\
    "Нить не обнаружена. Продолжить печать?",\
    "Filaman algılanmadı. Yazdırma işlemine devam edilsin mi?",\
    "消耗品が検出されませんでした。印刷を続行しますか？",
};

const char *ErrorTitile1[MAX_LANGUAGE] = { \
    "严重错误",\
    "Warning",\
    "Warnung",\
    "Advertencia",\
    "Avertissement",\
    "Avvertenza",\
    "Aviso",\
    "Предупреждение",\
    "Uyarı",\
    "シリアスエラー"
};

const char *ErrorTitile2[MAX_LANGUAGE] = { \
    "错误",\
    "Error",\
    "Fehler",\
    "Error",\
    "Erreur",\
    "Errore",\
    "Erro",\
    "Ошибка",\
    "Hata",\
    "エラー"
}; 

const char *ErrorTitile3[MAX_LANGUAGE] = { \
    "AI检测提示",\
    "AI detection prompt",\
    "Meldung zur Erkennung von KI",\
    "Aviso de detección de IA",\
    "Invite de détection IA",\
    "Richiesta di rilevamento dell'AI",\
    "Mensagem de detecção da IA",\
    "Подсказка об обнаружении ИИ",\
    "Yapay zeka tanı talimatı",\
    "AI検知プロンプト"
}; 

const char *ErrorTitile4[MAX_LANGUAGE] = { \
    "提示",\
    "Hint",\
    "Hinweis",\
    "Sugerencia",\
    "Indice",\
    "Suggerimento",\
    "Dica",\
    "Подсказка",\
    "İpucu",\
    "ヒント",
}; 

const char *Error001Content[MAX_LANGUAGE] = { \
    "电机驱动异常", \
    "Motor drive exception", \
    "Ausnahme beim Antriebsmotor", \
    "Excepción de controlador de motor", \
    "Exception au niveau du disque moteur", \
    "Eccezione azionamento motore", \
    "Exceção da unidade do motor", \
    "Исключение привода двигателя", \
    "Motor tahriği istisnası", \
    "モータ駆動異常"
}; 

const char *Error002Content[MAX_LANGUAGE] = { \
    "内部错误", \
    "Internal errors", \
    "Interne Fehler", \
    "Errores internos", \
    "Erreurs internes", \
    "Errori interni", \
    "Erros internos", \
    "Внутренние ошибки", \
    "İç hatalar", \
    "内部エラー"
}; 

const char *Error003Content[MAX_LANGUAGE] = { \
    "通信异常", \
    "Communication exceptions", \
    "Ausnahmen bei der Kommunikation", \
    "Excepciones de comunicación", \
    "Exceptions de communication", \
    "Eccezioni di comunicazione", \
    "Exceções de comunicação", \
    "Исключения связи", \
    "İletişim istisnaları", \
    "通信異常"
}; 

const char *Error004Content[MAX_LANGUAGE] = { \
    "未按预期加热", \
    "Not heated as expected", \
    "Nicht wie erwartet erwärmt", \
    "No se calentó como se esperaba", \
    "Pas chauffé comme prévu", \
    "Non riscaldato come previsto", \
    "Não aquecido como esperado", \
    "Не нагревается, как положено", \
    "Beklendiği gibi ısınmadı", \
    "所定どおり加熱せず"
};

const char *Error005Content[MAX_LANGUAGE] = { \
    "热床温度异常", \
    "Hotbed temperature exception", \
    "Ausnahme bei der Heizbetttemperatur", \
    "Excepción de temperatura de cama caliente", \
    "Exception relative à la température du lit chauffant", \
    "Eccezione temperatura piano riscaldante", \
    "Exceção de temperatura da mesa", \
    "Исключение температуры очага", \
    "Sıcak yatak sıcaklığı istisnası", \
    "ヒートベッド温度異常"
};

const char *Error006Content[MAX_LANGUAGE] = { \
    "挤出机异常", \
    "Extruder failure", \
    "Extruder-Fehler", \
    "Falla de extrusor", \
    "Défaillance de l'extrudeuse", \
    "Guasto estrusore", \
    "Falha da extrusora", \
    "Сбой экструдера", \
    "Ekstrüder arızası", \
    "押出機異常"
};

const char *Error007Content[MAX_LANGUAGE] = { \
    "打印文件坐标异常", \
    "Printing file coordinate exception", \
    "Ausnahme bei Druckdateikoordinaten", \
    "Excepción coordinada de impresión de archivo", \
    "Exception relative aux coordonnées du fichier d\'impression", \
    "Eccezione coordinate file di stampa", \
    "Exceção de coordenadas do arquivo de impressão", \
    "Исключение координат файла печати", \
    "Yazdırma dosyası koordinat istisnası", \
    "印刷ファイル座標異常"
};

const char *Error008Content[MAX_LANGUAGE] = { \
    "AI检测暂停", \
    "AI detection paused", \
    "KI-Erkennung pausiert", \
    "Detección de IA pausada", \
    "Arrêt de la détection de l'IA", \
    "Rilevamento AI in pausa", \
    "Detecção da IA pausada", \
    "ИИ-обнаружение приостановлено", \
    "Yapay zeka algılama duraklatıldı", \
    "AI検出一時停止"
};

const char *Error008_104Content[MAX_LANGUAGE] = { \
    "请清理打印平台，打印已暂停", \
    "Please clear the print platform. Printing has been paused", \
    "Bitte löschen Sie die Druckplattform. Der Druckvorgang wurde unterbrochen", \
    "Limpie la plataforma de impresión. Se pausó la impresión", \
    "Merci de vider la plate-forme d\'impression. Impression interrompue", \
    "Cancella la piattaforma di stampa. La stampa è stata messa in pausa", \
    "Por favor, limpe a plataforma de impressão. A impressão foi pausada", \
    "Очистите платформу для печати Печать приостановлена", \
    "Lütfen baskı platformunu temizleyin. Yazdırma işlemi duraklatıldı", \
    "印刷定盤を清掃してください。印刷が一時停止しました"
};

const char *Error009Content[MAX_LANGUAGE] = { \
    "振纹优化传感器异常", \
    "Ringing optimization sensor failure", \
    "Ausfall des Welligkeitoptimierungssensors", \
    "Fallo del sensor de optimización del pitido", \
    "Erreur du capteur d'optimisation de sonnerie", \
    "Guasto del sensore di ottimizzazione dei segni di vibrazione", \
    "Falha no sensor de otimização de toque", \
    "Сбой датчика оптимизации звонка", \
    "Zil çalma optimizasyonu sensör arızası", \
    "モアレ最適化センサ異常"
};

const char *Error200Content[MAX_LANGUAGE] = { \
    "打印发生未知错误", \
    "An unknown error occurred during printing", \
    "Während des Druckens ist ein unbekannter Fehler aufgetreten", \
    "Se produjo un error inesperado al imprimir", \
    "Une erreur inconnue s\'est produite pendant l\'impression", \
    "Si è verificato un errore sconosciuto durante la stampa", \
    "Ocorreu um erro desconhecido durante a impressão", \
    "Неизвестная ошибка при печати", \
    "Yazdırma sırasında bilinmeyen bir hata meydana geldi", \
    "印刷で未知のエラーが発生しました"
};

const char *Error201Content[MAX_LANGUAGE] = { \
    "传感器温度异常", \
    "Sensor temperature exception", \
    "Ausnahme bei der Sensortemperatur", \
    "Excepción de temperatura del sensor", \
    "Erreur de température du capteur", \
    "Eccezione temperatura sensore", \
    "Erro de temperatura do sensor", \
    "Исключение температуры датчика", \
    "Sensör sıcaklığı istisnası", \
    "センサ温度異常"
};

const char *Error204Content[MAX_LANGUAGE] = { \
    "风扇异常", \
    "Fan anomaly	", \
    "Anomalie im Ventilator", \
    "Error en el ventilador", \
    "Anomalie du ventilateur", \
    "Anomalia ventola", \
    "Anomalia da ventoinha", \
    "Аномалия вентилятора", \
    "Fan anomalisi", \
    "ファン異常"
};

const char *Error205Content[MAX_LANGUAGE] = { \
    "网络异常", \
    "Network anomaly", \
    "Netzwerk-Anomalie", \
    "Error de red", \
    "Anomalie du réseau", \
    "Anomalia di rete", \
    "Anomalia de rede", \
    "Сетевая аномалия", \
    "Ağ anomalisi", \
    "ネットワーク異常"
};

const char *Error207Content[MAX_LANGUAGE] = { \
    "检测到z-Touch异常", \
    "z-Touch exception detected", \
    "z-Touch-Ausnahme erkannt", \
    "z-Excepción táctil detectada", \
    "Exception z-Touch détectée", \
    "Rilevata eccezione z-Touch", \
    "Detectada exceção de z-touch", \
    "Обнаружено исключение z-Touch", \
    "z-Touch istisnası algılandı", \
    "z-Touch異常検出"
};
const char *Error208Content[MAX_LANGUAGE] = { \
    "文件异常，请重试", \
    "File exception, please retry", \
    "Dateiausnahme, bitte erneut versuchen", \
    "Excepción de archivo, volver a intentar", \
    "Erreur du fichier, veuillez réessayer", \
    "Eccezione file, riprovare", \
    "Erro de arquivo, por favor, tente novamente", \
    "Исключение файла, повторите попытку", \
    "Dosya istisnası, lütfen tekrar deneyin", \
    "ファイル異常。再試行してください"
};

const char *Error210Content[MAX_LANGUAGE] = { \
    "雷达异常", \
    "Radar exception", \
    "Radar-Ausnahme", \
    "Excepción de radar", \
    "Erreur du radar", \
    "Eccezione radar", \
    "Erro de radar", \
    "Исключение радара", \
    "Radar istisnası", \
    "レーダ異常"
};

const char *Error500Content[MAX_LANGUAGE] = { \
    "未知异常", \
    "Unknown exception", \
    "Unbekannte Ausnahme", \
    "Excepción desconocida", \
    "Exception inconnue", \
    "Eccezione sconosciuta", \
    "Exceção desconhecida", \
    "Неизвестное исключение", \
    "Bilinmeyen istisna", \
    "未知エラー"
};

const char *Error800Content[MAX_LANGUAGE] = { \
    "轴移动前请先归位 ", \
    "Please home in before moving the axes", \
    "Bitte zur Startposition gehen, bevor Sie die Achsen bewegen", \
    "Vuelva a la posición inicial antes de mover los ejes", \
    "Veuillez faire le point avant de faire progresser les axes.", \
    "Ritornare alla posizione iniziale prima di spostare gli assi", \
    "Retorne antes de mover os eixos", \
    "Вернитесь к нулю для перемещения осей", \
    "Lütfen eksenleri taşımadan önce ana sisteme geri dönün", \
    "軸の移動前にホーミングしてください"
};

const char *Error800_2242_Content[MAX_LANGUAGE] = { \
    "坐标超限", \
    "Coordinate overrun", \
    "Koordinatenüberschreitung", \
    "Sobrecarga coordinada", \
    "Dépassement de coordonnées", \
    "Superamento delle coordinate", \
    "Coordenada excedente", \
    "Превышение координат", \
    "Koordinat aşırı çalışma", \
    "座標オーバーラン"
};

const char *Error800_2211_Content[MAX_LANGUAGE] = { \
    "打印任务已暂停 ", \
    "Print task paused", \
    "Druckauftrag unterbrochen", \
    "Tarea de impresión pausada", \
    "Interruption de la tâche d'impression", \
    "Attività di stampa in pausa", \
    "Tarefa de impressão pausada", \
    "Задание печати приостановлено", \
    "Baskı görevi duraklatıldı", \
    "印刷ジョブが一時停止しました"
};

const char *Error801Content[MAX_LANGUAGE] = { \
    "机器启动中", \
    "Machine start-up in progress", \
    "Maschine wird gerade gestartet", \
    "Inicio de máquina en progreso", \
    "Démarrage de la machine en cours", \
    "Avviamento macchina in corso", \
    "Inicialização da máquina em andamento", \
    "Выполняется запуск машины", \
    "Makine başlatma devam ediyor", \
    "機器起動中"
};

const char *Key000Content[MAX_LANGUAGE] = { \
    "检测到打印发生未知错误", \
    "Unknown printing error detected", \
    "Unbekannter Druckfehler erkannt", \
    "Error de impresión desconocido detectado", \
    "Erreur d'impression inconnue détectée", \
    "Rilevato errore di stampa sconosciuto", \
    "Erro de impressão desconhecido detectado", \
    "Обнаружена неизвестная ошибка печати", \
    "Bilinmeyen yazdırma hatası algılandı", \
    "印刷中に未知のエラーが検出されました"
};

const char *Key101Content[MAX_LANGUAGE] = { \
    "检测到打印质量问题，打印已暂停", 
    "A print quality problem has been detected and printing has been paused", \
    "Es wurde ein Problem mit der Druckqualität festgestellt und der Druckvorgang wurde unterbrochen", \
    "Se detectó un problema de calidad de impresión y se pausó la impresión", \
    "Le système a détecté un problème de qualité d'impression et a interrompu la tâche", \
    "È stato rilevato un problema di qualità di stampa e la stampa è stata messa in pausa", \
    "Foi detectado um problema de qualidade de impressão e a impressão foi pausada", \
    "Обнаружена проблема качества печати, печать приостановлена", \
    "Baskı kalitesi problemi algılandı, yazdırma işlemi duraklatıldı", \
    "印刷品質問題が検出されました。印刷が一時停止しました"
};

const char *Key103Content[MAX_LANGUAGE] = { \
    "检测到打印质量问题，打印已暂停", 
    "A print quality problem has been detected and printing has been paused", \
    "Es wurde ein Problem mit der Druckqualität festgestellt und der Druckvorgang wurde unterbrochen", \
    "Se detectó un problema de calidad de impresión y se pausó la impresión", \
    "Le système a détecté un problème de qualité d'impression et a interrompu la tâche", \
    "È stato rilevato un problema di qualità di stampa e la stampa è stata messa in pausa", \
    "Foi detectado um problema de qualidade de impressão e a impressão foi pausada", \
    "Обнаружена проблема качества печати, печать приостановлена", \
    "Baskı kalitesi problemi algılandı, yazdırma işlemi duraklatıldı", \
    "印刷品質問題が検出されました。印刷が一時停止しました"
};

const char *Key104Content[MAX_LANGUAGE] = { \
    "检测到打印平台板有异物，打印已暂停", 
    "Foreign object detected on the printing platform, printing paused", \
    "Fremdkörper auf der Druckplattform erkannt, Druckvorgang unterbrochen", \
    "Objeto extraño detectado en la Plataforma de impresión; impresión en pausa", \
    "Un objet étranger a été détecté sur la plate-forme d'impression, l'impression a été interrompue.", \
    "Rilevato oggetto estraneo sulla piattaforma di stampa, stampa in pausa", \
    "Objeto estranho detectado na plataforma de impressão, a impressão foi pausada", \
    "Обнаружен инородный предмет на платформе для печати, печать приостановлена", \
    "Yazdırma platformunda yabancı nesne algılandı, yazdırma işlemi duraklatıldı", \
    "印刷定盤プレートに異物が検出されました。印刷が一時停止しました"
};

const char *Key109Content[MAX_LANGUAGE] = { \
    "风扇反馈异常", 
    "Fan feedback exception", \
    "Ausnahme bei Rückmeldung des Ventilators", \
    "Excepción de retroalimentación del ventilador", \
    "Erreur de retour d'information du ventilateur", \
    "Eccezione feedback ventola", \
    "Erro de feedback do ventilador", \
    "Исключение обратного сигнала вентилятора", \
    "Fan geri bildirimi istisnası", \
    "ファンフィードバック異常"
};

const char *Key500Content[MAX_LANGUAGE] = { \
    "AI检测到打印质量问题", 
    "Printing quality problems detected by AI", \
    "Von der KI erkannte Probleme mit der Druckqualität", \
    "Detección de problemas de calidad de impresión por IA", \
    "Problèmes de qualité d\'impression détectés par l\'IA", \
    "Problemi di qualità di stampa rilevati dall'AI", \
    "Problemas de qualidade de impressão detectados pela IA", \
    "Проблемы с качеством печати, обнаруженные ИИ", \
    "Yapay zeka tarafından algılanan yazdırma kalitesi problemleri", \
    "AIによる印刷品質問題検出"
};

const char *Key501Content[MAX_LANGUAGE] = { \
    "喉管风扇异常", 
    "Heat break fan exception", \
    "Ausnahme beim Ventilator der Wärmeunterbrechung", \
    "Excepción del ventilador por episodio de calor", \
    "Erreur du ventilateur en cas de rupture de la source de chaleur", \
    "Eccezione della ventola di dissipazione del calore", \
    "Erro do ventilador de dissipação de calor", \
    "Исключение вентилятора теплового разрыва", \
    "Isıl kırılma fan istisnası", \
    "ベンチュリ管ファン異常"
};

const char *Key502Content[MAX_LANGUAGE] = { \
    "主板风扇异常", 
    "Mainboard fan exception", \
    "Ausnahme beim Ventilator des Mainboards", \
    "Excepción del ventilador del cuadro principal", \
    "Erreur au niveau du ventilateur de la carte mère", \
    "Eccezione ventola scheda madre", \
    "Erro da ventoinha da placa-mãe", \
    "Исключение вентилятора материнской платы", \
    "Anakart fan istisnası", \
    "マザーボードファン異常"
};

const char *Key503Content[MAX_LANGUAGE] = { \
    "检测到打印质量问题", 
    "A print quality problem has been detected and printing has been paused.", \
    "Es wurde ein Problem mit der Druckqualität erkannt und der Druckvorgang wurde unterbrochen.", \
    "Se ha detectato un problema de calidad de impresión y se ha suspendido la misma.", \
    "Un problème de qualité d'impression a été détecté et l'impression a été suspendue.", \
    "È stato rilevato un problema di qualità di stampa e la stampa è stata sospesa.", \
    "Foi detectado um problema de qualidade da impressão e esta foi suspensa.", \
    "Обнаружена проблема с качеством печати, печать приостановлена.", \
    "Baskı kalitesi problemi algılandı ve yazdırma işlemi askıya alındı.", \
    "印刷品質の問題が検出され印刷が中断されました。",
};

const char *Key504Content[MAX_LANGUAGE] = { \
    "当前文件不支持流量校准", 
    "Current file does not support flow detection", \
    "Die aktuelle Datei unterstützt die Flusserkennung nicht", \
    "El archivo actual no es compatible con la detección de caudal", \
    "Le fichier actuel ne prend pas en charge la détection de flux", \
    "Il file corrente non supporta il rilevamento del flusso", \
    "O arquivo atual não é compatível com a detecção de fluxo", \
    "Текущий файл не поддерживает обнаружение потока", \
    "Mevcut dosya akış algılamayı desteklemiyor", \
    "現ファイルは流量検出に非対応です"
};

const char *Key505Content[MAX_LANGUAGE] = { \
    "AI激光雷达异常", 
    "AI LiDAR anomaly", \
    "KI LiDAR Anomalie", \
    "Anomalía de AI LiDAR", \
    "Erreur AI LiDAR", \
    "Anomalia AI LiDAR", \
    "Anomalia AI LiDAR", \
    "Аномалия лидара ИИ", \
    "AI LiDAR anomalisi", \
    "AIレーザーレーダ異常"
};

const char *Key506Content[MAX_LANGUAGE] = { \
    "AI激光雷达标定失败", 
    "AI LiDAR calibration failure", \
    "Ausfall der KI LiDAR-Kalibrierung", \
    "Fallo de calibración de AI LiDAR", \
    "Erreur de calibration AI LiDAR", \
    "Errore calibrazione AI LiDAR", \
    "Falha na calibração do AI LiDAR", \
    "Сбой калибровки лидара ИИ", \
    "AI LiDAR kalibrasyon arızası", \
    "AIレーザーレーダ・キャリブレーション失敗"
};

const char *Key507Content[MAX_LANGUAGE] = { \
    "AI激光雷达校准失败", 
    "AI LiDAR alignment failure", \
    "Ausfall der KI LiDAR Ausrichtung", \
    "Fallo de alineación de AI LiDAR", \
    "Erreur d\'alignement AI LiDAR", \
    "Errore allineamento AI LiDAR", \
    "Falha no alinhamento do AI LiDAR", \
    "Сбой юстировки лидара ИИ", \
    "AI LiDAR hizalama arızası", \
    "AIレーザーレーダ・アライメント失敗"
};

const char *Key508Content[MAX_LANGUAGE] = { \
    "当前存储空间占用已达 %s,请及时清理", 
    "Current storage space usage has reached %s, please clean up in time", \
    "Der aktuelle Speicherplatzverbrauch hat %s erreicht, bitte rechtzeitig aufräumen", \
    "El uso actual del espacio de almacenamiento ha alcanzado %s, por favor limpie a tiempo", \
    "L'utilisation actuelle de l'espace de stockage a atteint %s, veuillez nettoyer à temps", \
    "L'uso attuale dello spazio di archiviazione ha raggiunto %s, si prega di pulire in tempo", \
    "O uso atual do espaço de armazenamento atingiu %s, por favor, limpe a tempo", \
    "Текущее использование места для хранения достигло %s, пожалуйста, вовремя уберите", \
    "Güncel depolama alanı kullanımı %s'e ulaştı, lütfen zamanında temizleyin", \
    "現在のストレージスペースの使用量は%sに達しています, タイムリーにクリーンアップしてください", 
};

const char *Key2520Content[MAX_LANGUAGE] = { \
    "调平传感器芯片异常", 
    "Leveling Sensor Chip Abnormality", \
    "Abnormalität des Nivelliersensor-Chips", \
    "Anormalidad del Chip del Sensor de Nivelación", \
    "Anomalie de la Puce du Capteur de Nivellement", \
    "Anomalia del Chip del Sensore di Livellamento", \
    "Anomalia do Chip do Sensor de Nivelamento", \
    "Аномалия Чипа Датчика Уровня", \
    "Seviye Sensörü Çip Anormalliği", \
    "レベリングセンサーチップの異常", 
};

const char *Key2521Content[MAX_LANGUAGE] = { \
    "Z轴传感器芯片异常或传感器损坏", 
    "Z-axis sensor chip anomaly or sensor damaged", \
    "Anomalie des Z-Achsen-Sensorchips oder Sensor beschädigt", \
    "Anomalía del chip del sensor del eje Z o sensor dañado", \
    "Anomalie de la puce du capteur de l\'axe Z ou capteur endommagé", \
    "Anomalia chip sensore asse Z o sensore danneggiato", \
    "Anomalia no chip do sensor do eixo Z ou sensor danificado", \
    "Аномалия кристалла датчика оси Z или датчик поврежден", \
    "Z ekseni sensör çipi anomalisi ya da sensör arızalı", \
    "Z軸センサチップ異常またはセンサ破損"
};

const char *Key2522Content[MAX_LANGUAGE] = { \
    "Z轴传感器数据传输异常", 
    "Z-axis sensor data transmission anomaly", \
    "Anomalie bei der Datenübertragung des Z-Achsen-Sensors", \
    "Anomalía en la transmisión de datos del sensor del eje Z", \
    "Anomalie de la transmission des données du capteur de l'axe Z", \
    "Anomalia trasmissione dati sensore asse Z", \
    "Anomalia na transmissão de dados do sensor do eixo Z", \
    "Аномалия передачи данных датчика оси Z", \
    "Z ekseni sensörü veri aktarım anomalisi", \
    "Z軸センサデータ転送異常"
};

const char *Key2523Content[MAX_LANGUAGE] = { \
    "Z轴传感器数据传输异常", 
    "Z-axis sensor data transmission anomaly", \
    "Anomalie bei der Datenübertragung des Z-Achsen-Sensors", \
    "Anomalía en la transmisión de datos del sensor del eje Z", \
    "Anomalie de la transmission des données du capteur de l\'axe Z", \
    "Anomalia trasmissione dati sensore asse Z", \
    "Anomalia na transmissão de dados do sensor do eixo Z", \
    "Аномалия передачи данных датчика оси Z", \
    "Z ekseni sensörü veri aktarım anomalisi", \
    "Z軸センサデータ転送異常"
};

const char *Key2524Content[MAX_LANGUAGE] = { \
    "Z轴传感器芯片异常，传感器损坏或受环境影响", 
    "Z-axis sensor chip anomaly, sensor damaged or affected by the environment", \
    "Anomalie des Z-Achsen-Sensorchips, Sensor beschädigt oder durch die Umgebung beeinträchtigt", \
    "Anomalía del chip del sensor del eje Z, sensor dañado o afectado por el entorno", \
    "Anomalie de la puce du capteur de l\'axe Z, capteur endommagé ou affecté par l\'environnement", \
    "Anomalia chip sensore asse Z, sensore danneggiato o influenzato dall\'ambiente", \
    "Anomalia no chip do sensor do eixo Z, sensor danificado ou afetado pelo ambiente", \
    "Аномалия кристалла датчика оси Z, датчик поврежден или подвергается влиянию окружающей среды", \
    "Z ekseni sensör çipi anomalisi, sensör hasar görmüş veya çevreden etkilenmiş durumda", \
    "Z軸センサーチップ異常、センサ破損もしくは周辺環境による影響を受け"
};

const char *Key2525Content[MAX_LANGUAGE] = { \
    "调平或Z轴归零不正常", 
    "Leveling or Z-axis homing anomaly", \
    "Anomalie bei der Nivellierung oder der Z-Achse Zur Startseite", \
    "Nivelación o anomalía del inicio del eje Z", \
    "Anomalie de nivellement ou d'orientation de l'axe Z", \
    "Anomalia di livellamento o ritorno asse Z", \
    "Anomalia no nivelamento ou no retorno do eixo Z", \
    "Аномалия возврата при юстировке или оси Z", \
    "Düzleştirme veya Z ekseni sıfırlama anomalisi", \
    "レベリングまたはZ軸原点復帰異常"
};

const char *Key2526Content[MAX_LANGUAGE] = { \
    "Z轴运动不畅，或丝杆旋转不畅", 
    "Z-axis movement not smooth or lead screw rotation not smooth", \
    "Ungleichmäßige Bewegung der Z-Achse oder ungleichmäßige Drehung der Leitspindel", \
    "Movimiento no suave del eje Z o rotación no suave del tornillo principal", \
    "Le mouvement de l\'axe Z n\'est pas régulier ou la rotation de la vis-mère n\'est pas régulière", \
    "Movimento dell\'asse Z o rotazione della vite principale non regolari", \
    "O movimento do eixo Z não é suave ou a rotação do parafuso de avanço não é suave", \
    "Перемещение по оси Z не равномерное или вращение ведущего винта не равномерное", \
    "Z ekseni hareketi düzgün değil veya kılavuz vida dönüşü doğru değil", \
    "Z軸走行、またはリードスクリュー旋回が不円滑"
};

const char *Key2527Content[MAX_LANGUAGE] = { \
    "Z轴传感器数据传输异常", 
    "Z-axis sensor data transmission anomaly", \
    "Anomalie bei der Datenübertragung des Z-Achsen-Sensors", \
    "Anomalía en la transmisión de datos del sensor del eje Z", \
    "Anomalie de la transmission des données du capteur de l\'axe Z", \
    "Anomalia trasmissione dati sensore asse Z", \
    "Anomalia na transmissão de dados do sensor do eixo Z", \
    "Аномалия передачи данных датчика оси Z", \
    "Z ekseni sensörü veri aktarım anomalisi", \
    "Z軸センサデータ転送異常"
};

const char *Key2528Content[MAX_LANGUAGE] = { \
    "配置文件配置项异常", 
    "Configuration item of configuration file exception", \
    "Ausnahme bei einem Konfigurationselement der Konfigurationsdatei", \
    "Elemento de configuración de la excepción del archive de configuración", \
    "Anomalie de l'élément de configuration du fichier de configuration", \
    "Eccezione di configurazione del file di configurazione", \
    "Item de configuração do arquivo de configuração com erro", \
    "Исключение элемента конфигурации файла конфигурации", \
    "Yapılandırma dosyası yapılandırma öğesi istisnası", \
    "プロファイル構成項目異常"
};

const char *Key2529Content[MAX_LANGUAGE] = { \
    "Z轴传感器芯片异常，传感器损坏或受环境影响", 
    "Z-axis sensor chip anomaly, sensor damaged or affected by the environment", \
    "Anomalie des Z-Achsen-Sensorchips, Sensor beschädigt oder durch die Umgebung beeinträchtigt", \
    "Anomalía del chip del sensor del eje Z, sensor dañado o afectado por el entorno", \
    "Anomalie de la puce du capteur de l\'axe Z, capteur endommagé ou affecté par l\'environnement", \
    "Anomalia chip sensore asse Z, sensore danneggiato o influenzato dall\'ambiente", \
    "Anomalia no chip do sensor do eixo Z, sensor danificado ou afetado pelo ambiente", \
    "Аномалия кристалла датчика оси Z, датчик поврежден или подвергается влиянию окружающей среды", \
    "Z ekseni sensör çipi anomalisi, sensör hasar görmüş veya çevreden etkilenmiş durumda", \
    "Z軸センサーチップ異常、センサ破損もしくは周辺環境による影響を受け"
};

const char *Key2530Content[MAX_LANGUAGE] = { \
    "Z轴传感器芯片异常，传感器损坏或受环境影响", 
    "Z-axis sensor chip anomaly, sensor damaged or affected by the environment", \
    "Anomalie des Z-Achsen-Sensorchips, Sensor beschädigt oder durch die Umgebung beeinträchtigt", \
    "Anomalía del chip del sensor del eje Z, sensor dañado o afectado por el entorno", \
    "Anomalie de la puce du capteur de l\'axe Z, capteur endommagé ou affecté par l\'environnement", \
    "Anomalia chip sensore asse Z, sensore danneggiato o influenzato dall\'ambiente", \
    "Anomalia no chip do sensor do eixo Z, sensor danificado ou afetado pelo ambiente", \
    "Аномалия кристалла датчика оси Z, датчик поврежден или подвергается влиянию окружающей среды", \
    "Z ekseni sensör çipi anomalisi, sensör hasar görmüş veya çevreden etkilenmiş durumda", \
    "Z軸センサーチップ異常、センサ破損もしくは周辺環境による影響を受け"
};

const char *Key2531Content[MAX_LANGUAGE] = { \
    "热床的床面太软", 
    "Surface of hotbed too soft", \
    "Oberfläche des Heizbetts zu weich", \
    "Superficie del sumidero demasiado suave", \
    "Surface du lit chauffant trop molle", \
    "Superficie del letto riscaldante troppo morbida", \
    "Superfície da mesa muito macia", \
    "Слишком мягкая поверхность очага", \
    "Sıcak yatağın yüzeyi çok yumuşak", \
    "ヒートベッド表面が柔らかすぎ"
};

const char *Key2532Content[MAX_LANGUAGE] = { \
    "接线连接异常或接触不良", 
    "Abnormal wiring connection or poor contact", \
    "Abnormale Verkabelung oder schlechter Kontakt", \
    "Conexión de cable anormal o mal contacto", \
    "Connexion de câblage anormale ou mauvais contact", \
    "Collegamento elettrico anomalo o scarso contatto", \
    "Conexão anormal da fiação ou mau contato", \
    "Ненормальное подключение или плохой контакт проводки", \
    "Anormal kablo bağlantısı veya zayıf temas", \
    "配線接続異常または接触不良"
};

const char *Key2533Content[MAX_LANGUAGE] = { \
    "参数异常，请重新调平", 
    "Parameter anomaly, please re-level", \
    "Anomalie der Parameter, bitte neu nivellieren", \
    "Anomalía del parámetro; vuelva a nivelarlo", \
    "Anomalie de paramètre, veuillez remettre à niveau", \
    "Anomalia parametro, si prega di eseguire un nuovo livellamento", \
    "Anomalia de parâmetro, por favor, refaça o nivelamento", \
    "Аномалия параметра, выполните юстировку повторно", \
    "Parametre anomalisi, lütfen yeniden düzleştirin", \
    "パラメータ異常。再度レベリングしてください"
};

const char *Key2534Content[MAX_LANGUAGE] = { \
    "硬件故障，请重新调平", 
    "Hardware failure, please re-level", \
    "Hardwareausfall, bitte neu nivellieren", \
    "Fallo de hardware; vuelva a nivelarlo", \
    "Défaillance du matériel, veuillez remettre à niveau", \
    "Errore hardware, si prega di eseguire un nuovo livellamento", \
    "Falha de hardware, por favor, refaça o nivelamento", \
    "Сбой аппаратного обеспечения, выполните юстировку повторно", \
    "Donanım arızası, lütfen yeniden düzleştirin", \
    "ハードウェア故障。再度レベリングしてください"
};

const char *Key2535Content[MAX_LANGUAGE] = { \
    "热床上有残渣、请清理热床", 
    "Residue on the hotbed, please clean it", \
    "Rückstände auf dem Heizbett, bitte reinigen Sie es", \
    "Residuo en el sumidero, límpielo", \
    "Résidus sur le lit chauffant, veuillez le nettoyer", \
    "Residuo sul letto riscaldante, eseguire la pulizia", \
    "Resíduos na mesa, por favor, realize a limpeza", \
    "В очаге обнаружен остаточный материал, выполните очистку", \
    "Sıcak yatağın üzerinde kalıntı var, lütfen temizleyin", \
    "ヒートベッドに残滓がある。ヒートベッドを掃除してください"
};

const char *Key2560Content[MAX_LANGUAGE] = { \
    "与主MCU通讯异常", 
    "Abnormal communication with the main MCU", \
    "Abnormal communication with the main MCU", \
    "Abnormal communication with the main MCU", \
    "Abnormal communication with the main MCU", \
    "Abnormal communication with the main MCU", \
    "Abnormal communication with the main MCU", \
    "Abnormal communication with the main MCU", \
    "Abnormal communication with the main MCU", \
    "Abnormal communication with the main MCU"
};

const char *Key2561Content[MAX_LANGUAGE] = { \
    "与喷头MCU通讯异常", 
    "Abnormal communication with print head MCU", \
    "Abnormal communication with print head MCU", \
    "Abnormal communication with print head MCU", \
    "Abnormal communication with print head MCU", \
    "Abnormal communication with print head MCU", \
    "Abnormal communication with print head MCU", \
    "Abnormal communication with print head MCU", \
    "Abnormal communication with print head MCU", \
    "Abnormal communication with print head MCU"
};

const char *Key2562Content[MAX_LANGUAGE] = { \
    "与热床MCU通讯异常", 
    "Abnormal communication with hot bed MCU", \
    "Abnormal communication with hot bed MCU", \
    "Abnormal communication with hot bed MCU", \
    "Abnormal communication with hot bed MCU", \
    "Abnormal communication with hot bed MCU", \
    "Abnormal communication with hot bed MCU", \
    "Abnormal communication with hot bed MCU", \
    "Abnormal communication with hot bed MCU", \
    "Abnormal communication with hot bed MCU"
};

const char *Key2563Content[MAX_LANGUAGE] = { \
    "与rpi MCU通讯异常", 
    "Abnormal communication with rpi MCU", \
    "Abnormal communication with rpi MCU", \
    "Abnormal communication with rpi MCU", \
    "Abnormal communication with rpi MCU", \
    "Abnormal communication with rpi MCU", \
    "Abnormal communication with rpi MCU", \
    "Abnormal communication with rpi MCU", \
    "Abnormal communication with rpi MCU", \
    "Abnormal communication with rpi MCU"
};

const char *Key2564Content[MAX_LANGUAGE] = { \
    "喷头未按预期加热", 
    "Extruder not heating as expected", \
    "Extruder not heating as expected", \
    "Extruder not heating as expected", \
    "Extruder not heating as expected", \
    "Extruder not heating as expected", \
    "Extruder not heating as expected", \
    "Extruder not heating as expected", \
    "Extruder not heating as expected", \
    "Extruder not heating as expected"
};

const char *Key2565Content[MAX_LANGUAGE] = { \
    "热床未按预期加热", 
    "The heated bed is not heating as expected", \
    "The heated bed is not heating as expected", \
    "The heated bed is not heating as expected", \
    "The heated bed is not heating as expected", \
    "The heated bed is not heating as expected", \
    "The heated bed is not heating as expected", \
    "The heated bed is not heating as expected", \
    "The heated bed is not heating as expected", \
    "The heated bed is not heating as expected"
};

/*************************error**************************/