//
//  URPrinterOptions.h
//  URPrinterSDK
//
//  Created by urovo on 2023/4/20.
//

#ifndef URPrinterOptions_h
#define URPrinterOptions_h

/**
 *  @enum URBluetoothState
 *
 *  @discussion 蓝牙状态
 */
typedef NS_ENUM(NSInteger, URBluetoothState) {
    URBluetoothStateUnknown = 0,   ///<未知状态
    URBluetoothStateResetting,     ///<蓝牙正在重置
    URBluetoothStateUnsupported,   ///<不支持蓝牙
    URBluetoothStateUnauthorized,  ///<用户未未授权
    URBluetoothStatePoweredOff,    ///<蓝牙关闭
    URBluetoothStatePoweredOn,     ///<蓝牙开启
};

/**
 *  @enum URConnectState
 *
 *  @discussion 设备连接状态
 */
typedef NS_ENUM(NSInteger, URConnectState) {
    URConnectStateUnknown = 0,     ///<未知状态
    URConnectStateDisconnect,      ///<连接断开
    URConnectStateConnecting,      ///<连接中
    URConnectStateConnected,       ///<已连接
    URConnectStateConnectTimeOut,  ///<连接超时
    URConnectStateConnectFail,     ///<连接失败
};

/**
 *  @enum URTextAngle
 *
 *  @discussion 文本旋转角度(Text rotation Angle)
 */
typedef NS_ENUM (NSUInteger,URTextAngle) {
    URTextAngle_0,   ///<旋转角度为0度  (The rotation Angle is 0 degrees)
    URTextAngle_90,  ///<旋转角度为90度 (The rotation Angle is 90 degrees)
    URTextAngle_180, ///<旋转角度为180度(The rotation Angle is 180 degrees)
    URTextAngle_270  ///<旋转角度为270度(The rotation Angle is 270 degrees)
};

/**
 *  @enum URBarcodeType
 *
 *  @discussion 条码类型(Bar code type)
 */
typedef NS_ENUM (NSUInteger,URBarcodeType) {
    URBarcodeTypeUPCA,///<纯数字，位数11位(Pure numbers, eleven digits)
    URBarcodeTypeUPCE,///<纯数字，位数7位，首位必须为0(A pure number with seven digits. The first digit must be 0)
    URBarcodeTypeEAN13,///<EAN/JAN-13 存数字，位数为12位(Save a number with 12 digits)
    URBarcodeTypeEAN8,///<内容可包含A~Z大写英文字母，0~9数字以及一些特殊符号，共计有44个字元(The content can contain A~Z capital English letters, 0~9 numbers and some special symbols, A total of 44 characters)
    URBarcodeTypeCODE39,///<内容可包含A~Z大写英文字母，0~9数字以及一些特殊符号，共计有44个字元(The content can contain A~Z capital English letters, 0~9 numbers and some special symbols, A total of 44 characters)
    URBarcodeTypeCODE93,///<Code93/Ext.93 可使用ASCII全部（128个）字符(All (128) ASCII characters are available)
    URBarcodeTypeCODE128,///<Code128Auto 内容包括大小写字母、数字、常用的标点符号和一些控制符(It includes upper and lower case letters, numbers, common punctuation marks, and some control characters)
    URBarcodeTypeCODABAR///<内容包括包括数字、7个特殊符号(Contents include numbers and 7 special symbols)（”+“、“-”、“*”、“/”、“$”、“.”、“：”）、A、B、C、D
};

/**
 *  @enum URPrintOrientationType
 *
 *  @discussion 打印方向(The print direction)
 */
typedef NS_ENUM (NSUInteger,URPrintOrientationType) {
    URPrintOrientationTypeHorizontal,///<水平打印(Horizontal print)
    URPrintOrientationTypeVertical///<垂直打印(Vertical print)
};

/**
 *  @enum URQRCodeLevel
 *
 *  @discussion 二维码纠错等级(QR code error correction level)
 */
typedef NS_ENUM (NSUInteger,URQRCodeLevel) {
    URQRCodeLevel_H,///<极高可靠性级别（H级）Extremely high reliability level (Class H)
    URQRCodeLevel_Q,///<高可靠性级别（Q级）High reliability level (Q-level)
    URQRCodeLevel_M,///<标准级别（M级）Standard grade (M grade)
    URQRCodeLevel_L///<高密度级别（L级）High Density Level (L Level)
};

/**
 *  @enum URQRCodeInputMode
 *
 *  @discussion 二维码输入模式(QR code input mode)
 */
typedef NS_ENUM (NSUInteger,URQRCodeInputMode) {
    URQRCodeInputMode_A,///<自动(automatic)
    URQRCodeInputMode_M///<手动（该模式暂不支持）(Manual (this mode is not currently supported))
};

/**
 *  @enum URPrintAlignment
 *
 *  @discussion 对齐方式(alignment)
 */
typedef NS_ENUM (NSUInteger,URPrintAlignment) {
    URPrintAlignmentCenter,///<居中对齐所有后续字段(Center to align all subsequent fields)
    URPrintAlignmentLeft,///<左对齐所有后续字段(Left align all subsequent fields)
    URPrintAlignmentRight,///<右对齐所有后续字段(Right-align all subsequent fields)
};

/**
 *  @enum Graphics
 *
 *  @discussion 图形(graphics)
 */
typedef NS_ENUM (NSUInteger,URPrintGraphicsType) {
    URPrintGraphicsTypeExpanded,///<横向打印扩展图形(Print the extended graph horizontally)
    URPrintGraphicsTypeCompressed,///<横向打印压缩图形(Print compressed graphics laterally)
};
/**
 *  @enum URPaperType
 *
 *  @discussion 纸张类型(适用于ZPL指令)
 */
typedef NS_ENUM (NSUInteger,URPaperType){
    URPaperTypePaper_N = 0,//连续纸张
    URPaperTypePaper_Y = 2,//非连续间隙纸张
    URPaperTypePaper_W = 3,//非连续间隙纸张
    URPaperTypePaper_M = 4,//非连续黑标纸张
    URPaperTypePaper_A = 5//自动选择
};


/**
 *  @enum UROrientationType
 *
 *  @discussion 条码方向(适用于ZPL指令)
 */
typedef NS_ENUM (NSUInteger,UROrientationType) {
    UROrientationTypeNormal = 0,   //正常
    UROrientationTypeRoated = 1,   //顺时针旋转 90 度
    UROrientationTypeInverted = 2, //顺时针旋转 180 度
    UROrientationTypeBottom = 3    //顺时针旋转 270 度
};

/**
 *  @enum URPrintType
 *
 *  @discussion 蓝牙或者wifi打印
 */
typedef NS_ENUM (NSUInteger,URPrintType) {
    URPrintTypeBLE = 0,   //蓝牙
    URPrintTypeWiFi = 1,  //wifi
};

#endif /* URPrinterOptions_h */
