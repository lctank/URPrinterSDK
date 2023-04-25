//
//  URPrinterOptions.h
//  URPrinterSDK
//
//  Created by urovo on 2023/4/20.
//

#ifndef URPrinterOptions_h
#define URPrinterOptions_h

typedef NS_ENUM(NSInteger, URBluetoothState) {
    URBluetoothStateUnknown = 0,
    URBluetoothStateResetting,
    URBluetoothStateUnsupported,
    URBluetoothStateUnauthorized,
    URBluetoothStatePoweredOff,
    URBluetoothStatePoweredOn,
};

typedef NS_ENUM(NSInteger, URConnectState) {
    URConnectStateUnknown = 0,
    URConnectStateDisconnect,
    URConnectStateConnecting,
    URConnectStateConnected,
    URConnectStateConnectTimeOut,
    URConnectStateConnectFail,
};

/**
 *  @enum TextAngle
 *
 *  @discussion 文本旋转角度(Text rotation Angle)
 */
typedef NS_ENUM (NSUInteger,TextAngle) {
    TEXT_ANGLE_0,   ///<旋转角度为0度  (The rotation Angle is 0 degrees)
    TEXT_ANGLE_90,  ///<旋转角度为90度 (The rotation Angle is 90 degrees)
    TEXT_ANGLE_180, ///<旋转角度为180度(The rotation Angle is 180 degrees)
    TEXT_ANGLE_270  ///<旋转角度为270度(The rotation Angle is 270 degrees)
};

/**
 *  @enum BarcodeType
 *
 *  @discussion 条码类型(Bar code type)
 */
typedef NS_ENUM (NSUInteger,BarcodeType) {
    UPCA,///<纯数字，位数11位(Pure numbers, eleven digits)
    UPCE,///<纯数字，位数7位，首位必须为0(A pure number with seven digits. The first digit must be 0)
    EAN13,///<EAN/JAN-13 存数字，位数为12位(Save a number with 12 digits)
    EAN8,///<内容可包含A~Z大写英文字母，0~9数字以及一些特殊符号，共计有44个字元(The content can contain A~Z capital English letters, 0~9 numbers and some special symbols, A total of 44 characters)
    CODE39,///<内容可包含A~Z大写英文字母，0~9数字以及一些特殊符号，共计有44个字元(The content can contain A~Z capital English letters, 0~9 numbers and some special symbols, A total of 44 characters)
    CODE93,///<Code93/Ext.93 可使用ASCII全部（128个）字符(All (128) ASCII characters are available)
    CODE128,///<Code128Auto 内容包括大小写字母、数字、常用的标点符号和一些控制符(It includes upper and lower case letters, numbers, common punctuation marks, and some control characters)
    CODABAR///<内容包括包括数字、7个特殊符号(Contents include numbers and 7 special symbols)（”+“、“-”、“*”、“/”、“$”、“.”、“：”）、A、B、C、D
};

/**
 *  @enum Alignment
 *
 *  @discussion 打印方向(The print direction)
 */
typedef NS_ENUM (NSUInteger,Orientation) {
    HORIZONTAL,///<水平打印(Horizontal print)
    VERTICAL///<垂直打印(Vertical print)
};

/**
 *  @enum QRCodeLevel
 *
 *  @discussion 二维码纠错等级(QR code error correction level)
 */
typedef NS_ENUM (NSUInteger,QRCodeLevel) {
    QRCODE_LEVEL_H,///<极高可靠性级别（H级）Extremely high reliability level (Class H)
    QRCODE_LEVEL_Q,///<高可靠性级别（Q级）High reliability level (Q-level)
    QRCODE_LEVEL_M,///<标准级别（M级）Standard grade (M grade)
    QRCODE_LEVEL_L///<高密度级别（L级）High Density Level (L Level)
};

/**
 *  @enum Mode
 *
 *  @discussion 二维码输入模式(QR code input mode)
 */
typedef NS_ENUM (NSUInteger,Mode) {
    QRCODE_INPUTMODE_A,///<自动(automatic)
    QRCODE_INPUTMODE_M///<手动（该模式暂不支持）(Manual (this mode is not currently supported))
};

/**
 *  @enum Alignment
 *
 *  @discussion 对齐方式(alignment)
 */
typedef NS_ENUM (NSUInteger,Alignment) {
    ALIGNMENT_CENTER,///<居中对齐所有后续字段(Center to align all subsequent fields)
    ALIGNMENT_LEFT,///<左对齐所有后续字段(Left align all subsequent fields)
    ALIGNMENT_RIGHT,///<右对齐所有后续字段(Right-align all subsequent fields)
};

/**
 *  @enum Graphics
 *
 *  @discussion 图形(graphics)
 */
typedef NS_ENUM (NSUInteger,Graphics) {
    EXPANDED_GRAPHICS,///<横向打印扩展图形(Print the extended graph horizontally)
    COMPRESSED_GRAPHICS,///<横向打印压缩图形(Print compressed graphics laterally)
};



#endif /* URPrinterOptions_h */
