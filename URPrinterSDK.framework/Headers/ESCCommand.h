//
//  ESCCommand.h
//  URPrinterSDK
//
//  Created by urovo on 2023/4/23.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ESCCommand : NSObject

/// 打印UPCA条码
/// Print UPCA barcode
/// @param content 数据范围0-9，长度为11位
/// The data range is 0-9 and the length is 11 bits
- (void)addUPCAtest:(NSString *)content;

/// 添加文字
/// Add Text
/// @param text 文本(Text)
- (void)addText:(NSString *)text;

/// 打印机初始化，必须是第一个打印命令0x1b,0x40
/// Printer initialization, must be the first print command 0x1b,0x40
- (void)addInitializePrinter;

/// 打印并且走纸多少行，默认为8行，打印完内容后发送
/// Print and move the number of lines of paper, the default is 8 lines, after printing the content to send
/// @param n 行数(Lines)
- (void)addPrintAndFeedLines:(int)n;

/// 换行
/// Line feed
- (void)addPrintAndLineFeed;

/// 设置打印模式，0x1B 0x21 n(0-255)，根据n的值设置字符打印模式
/// Set the print mode, 0x1B 0x21N (0-255), and set the character print mode according to the value of n
/// @param n 参数n二进制默认为00000000(0X0),10001000(0X88)表示下划线和加粗，00001000(0X08)表示加粗，10000000(0X80)表示下划线
/// The binary default for parameter n is 00000000(0X0),10001000(0X88) for underscore and bold, 00001000(0X08) for bold, and 10000000(0X80) for underscore
- (void)addPrintMode:(int)n;

/// 设置国际字符集，默认为美国0
/// Set the international character set. Default is US 0
/// @param n 字符集编号
/// Character set number
- (void)addSetInternationalCharacterSet:(int)n;

/// 设置字符是否旋转90°，默认为0
/// Sets whether the character is rotated by 90°. Default is 0
/// @param n 是否旋转
/// Whether the rotation
- (void)addSet90ClockWiseRotatin:(int)n;

/// 设置对齐方式
/// Set Alignment
/// @param n 0左对齐,1中间对齐,2右对齐
/// 0 left aligned,1 middle aligned,2 right aligned
- (void)addSetJustification:(int)n;

/// 开钱箱
/// Open the box
/// @param m 钱箱引脚号(Money box pin number)
/// @param t1 高电平时间(High level time)
/// @param t2 低电平时间(Low level time)
- (void)addOpenCashDawer:(int)m :(int)t1 :(int)t2;

/// 蜂鸣器(buzzer)
/// @param m 报警灯和鸣叫次数(Alarm lights and beep times)
/// @param t 时间(Time)
/// @param n 方式(way)
- (void)addSound:(int)m :(int)t :(int)n;

/// 设置行间距，不用设置，打印机默认为30
/// Set the line spacing, do not set, the printer defaults to 30
/// @param n 行间距高度，包含文字
/// Line spacing height, including text
- (void)addLineSpacing:(int)n;

/// 设置倒置模式 选择/取消倒置打印模式。
/// Set upside-down mode to select/deselect upside-down print mode.
/// @param n 是否倒置，默认为0， 0 ≤n ≤255 当n的最低位为0时，取消倒置打印模式。当n的最低位为1时，选择倒置打印模式。只有n的最低位有效；
/// The default value is 0, 0 ≤n ≤255. When the lowest value of n is 0, cancel the inverted printing mode. When the lowest order of n is 1, choose the inverted printing mode. Only the lowest order of n is valid;
- (void)addSetUpsideDownMode:(int)n;

/// 设置字符放大，限制为不放大和放大2倍，n=0x11
/// Sets character magnification to no magnification and 2 times magnification, n=0x11
/// @param n n=width | height 宽度放大倍数，0 ≤n ≤255 （1 ≤ 纵向放大倍数 ≤8，1 ≤ 横向放达倍数 ≤8）[描述] 用0 到2 位选择字符高度，4 到7 位选择字符宽度
/// N = width | magnification, height width 0 n 255 or less or less (1 longitudinal magnification 8, 1 or less or less lateral or less with multiple 8) or less [description] with 0 to 2 choose height of characters, four to seven choice character width
- (void)addSetCharcterSize:(int)n;

/// 设置反白模式，黑白反显打印模式
/// Set anti-white mode, black and white anti-print mode
/// @param n 是否反白，当n的最低位为0时，取消反显打印模式。当n的最低位为1时，选择反显打印模式。只有n的最低位有效；
/// Whether to reverse white or not. When the lowest order of n is 0, cancel the reverse printing mode. When the lowest order of n is 1, the reverse print mode is selected. Only the lowest order of n is valid;
- (void)addSetReverseMode:(int)n;

/// 打印机实时状态请求
/// Printer real-time status request
/// @param n 1 ≤n ≤4
/// PRINTER_STATUS  1
/// PRINTER_OFFLINE 2
/// PRINTER_ERROR   3
/// PRINTER_PAPER   4
- (void)queryRealtimeStatus:(int)n;

/// 设置切纸后走纸
/// Set up paper cutting after paper walking
/// @param n 走纸距离
/// Paper distance
- (void)addCutPaperAndFeed:(int)n;

/// 切纸
/// paper cut
/// @param m 0全切纸，1是半切
/// 0 is a full cut, 1 is a half cut
- (void)addCutPaper:(int)m;

/// 设置条码可识别字符，选择HRI字符的打印位置
/// Set bar code identifiable characters and select the printing position of HRI characters
/// @param n 可识别字符位置，0, 48  不打印 1, 49  条码上方 2, 50  条码下方 3, 51  条码上、下方都打印
/// Identifiable character position, 0, 48 do not print 1, 49 bar code above 2, 50 bar code below 3, 51 bar code on and below the print
- (void)addSetBarcodeHRPosition:(int)n;

/// 设置条码字符种类，选择HRI使用字体
/// Set bar code character type and select HRI font to use
/// @param n 固定为0 0,48  标准ASCII码字符 (12 × 24)  1,49  压缩ASCII码字符 (9 × 17)
/// Fixed as 0,48 standard ASCII characters (12 × 24) 1,49 compressed ASCII characters (9 × 17)
-(void)addSetBarcodeHRIFont:(int)n;

/// 设置条码高度
/// Set the bar code height
/// @param n 高度 条码高度为n点，默认为40
/// Height bar code height is n points, the default is 40
-(void)addSetBarcodeHeight:(int)n;

/// 设置条码单元宽度，不用设置，使用打印机内部默认值
/// Set the bar code unit width. Use the printer's internal default value
/// @param n 条码宽度 2 ≤n ≤6
/// Barcode width 2 ≤n ≤6
-(void)addSetBarcodeWidth:(int)n;

/// 打印EAN13码
/// Print the EAN13 code
/// @param content 数据范围0-9，长度为12位
/// The data range is 0-9 and the length is 12 bits
-(void)addEAN13:(NSString *)content;

/// 打印EAN8码
/// Print EAN8 code
/// @param content 数据范围0-9，长度为7位
/// The data range is 0-9 and the length is 7 bits
-(void)addEAN8:(NSString *)content;

/// 打印UPCA条码
/// Print UPCA barcode
/// @param content 数据范围0-9，长度为11位
/// The data range is 0-9 and the length is 11 bits
-(void)addUPCA:(NSString *)content;

/// 打印ITF14条码
/// Print the ITF14 barcode
/// @param content 数据范围 0-9 数据长度偶数个
/// Data range 0-9 even number of data lengths
-(void)addITF:(NSString *)content;

/// 打印CODE39条码
/// Print Code39 barcode
/// @param content 数据范围0-9 A-Z SP $ % + - . / ，*为 (开始/结束字符)
/// Data range 0-9 A-Z SP $ % + - . / , * for (start/end character)
-(void)addCODE39:(NSString *)content;

/// 打印CODE128码 采用的是1D 6B 49 n的命令格式，n为后面所有打印字符串的长度，包括了字符集的声明。默认使用CODEB字符集:  {B , 0x7B, 0x42
/// Print CODE128 code The command format is 1D 6B 49 N, where N is the length of all subsequent printed strings, including the declaration of the character set. The default CODEB character set is: {B, 0x7B, 0x42
/// @param charset CODEB字符集有 {A  {B  {C，charset默认值用B ，实际上，字符集可以插入到content中，一个content可以有多个字符集定义。
/// The CODEB character set has {A {B {C, and the charset default value is B. In fact, A character set can be inserted into A content. A content can have multiple character sets defined.
/// @param content 数据范围0x00-0x7f
/// Data range 0x00-0x7F
-(void)addCODE128:(char)charset :(NSString *)content;

/// 打印CODE128码支持混合{A {B {C打印，支持58mm纸打印超过14位的奇数数字，例如15位 17位 19位的数字串 采用的是1D 6B 49 n的命令格式，n为后面所有打印字符串的长度，包括了字符集的声明。默认使用CODEB字符集:  {B , 0x7B, 0x42
/// Printing Code128 code supports mixed {A {B {C printing. It supports 58mm paper printing of odd digits larger than 14 digits. For example, 15, 17, and 19 digits are printed in the command format 1D, 6B, 49 N, where N is the length of all subsequent printed strings, including character set declarations. The default CODEB character set is: {B, 0x7B, 0x42
/// @param height 条码高度(The barcode height)
/// @param width 条码宽度(Bar code width)
/// @param data 数据范围0x00-0x7f，全部为16进制(Data range 0x00-0x7F, all hexadecimal)
-(void)addCODE128ABC:(int)height :(int)width :(NSData*)data;

/// addNVLOGO
/// @param n n为序号，1<=n<=20(N is the ordinal number, 1<=n<=20)
/// @param m m默认为0(M defaults to 0)
-(void)addNVLOGO:(int)n :(int)m;

/*
 十六进制码(Hexadecimal code)
 1D 76 30 m xL xH yL yH d1...dk
 0 ≤ m ≤ 3, 48 ≤ m ≤ 51
 0 ≤ xL ≤ 255
 0 ≤ xH ≤ 255
 0 ≤ yL ≤ 255
 0 ≤ yH ≤ 255
 0 ≤ d ≤ 255
 k = ( xL + xH × 256) × ( yL + yH × 256) ( k ≠ 0)
 */
/// 添加ESC位图(Add an ESC bitmap)
/// @param m 模式 0, 48 正常 1, 49 倍宽 2, 50 倍高 3, 51 倍宽、倍高
/// Mode 0, 48 Normal 1, 49 wide 2, 50 high 3, 51 wide and high
/// @param xL 表示水平方向位图字节数（xL + xH × 256）
/// Denotes the number of bytes of horizontal bitmap (XL + XH × 256)
/// @param xH 表示水平方向位图字节数（xL + xH × 256）
/// Denotes the number of bytes of horizontal bitmap (XL + XH × 256)
/// @param yL 表示垂直方向位图点数（yL + yH × 256）
/// Represents the number of bitmap points in the vertical direction (YL + YH × 256)
/// @param yH 表示垂直方向位图点数（yL + yH × 256）
/// Represents the number of bitmap points in the vertical direction (YL + YH × 256)
/// @param data 影像数据(Image data)
-(void)addESCBitmapwithM:(int)m withxL:(int)xL withxH:(int)xH withyL:(int)yL withyH:(int) yH withData:(NSData*) data;

/// 打印光栅位图(Print raster bitmap)
/// @param image 图片(Image)
/// @param width 图片宽度(Image width)
-(void)addOriginrastBitImage:(UIImage *)image width:(int)width;

/// 打印光栅位图(Print raster bitmap)
/// @param image 图片(Image)
-(void)addOriginrastBitImage:(UIImage *)image;

/*
 正确的ESC指令下QRCode打印流程为四步：
 1、设定QRCode大小；（可以省略）
 2、设定纠错等级；（一般无需设定，忽略）
 3、将QRCode对应的文字信息存入打印机缓存中；（必须要有）
 4、发送打印QRCode命令。
 
 Under the correct ESC instruction, the printing process of QRCODE is four steps:
 1. Set the size of QRCODE; (may be omitted)
 2. Set the error correction level; (Generally do not need to set, ignore)
 3. Store the corresponding text information of QRCODE in the printer cache; (Must be)
 4. Send the print QRCODE command.
 
 */
/// 设定QRCode大小(可以省略)
/// Set QRCode size (can be omitted)
/// @param cn cn=49
/// @param fn fn=67
/// @param n n=3
-(void)addQRCodeSizewithpL:(int)pL withpH:(int)pH withcn:(int)cn withyfn:(int)fn withn:(int)n;

/// 设定纠错等级(一般无需设定，忽略)
/// Set error correction level (generally do not need to set, ignore)
/// @param cn cn=49
/// @param fn fn=69
/// @param n 48≤n≤51 默认n=48
-(void)addQRCodeLevelwithpL:(int)pL withpH:(int)pH withcn:(int)cn withyfn:(int)fn withn:(int)n;

/// 将QRCode对应的文字信息存入打印机缓存中(必须要有)
/// Put the corresponding text information of QRCode into the printer cache (must have)
/// @param cn cn=49
/// @param fn fn=80
/// @param m m=48
/// @param data data
-(void)addQRCodeSavewithpL:(int)pL withpH:(int)pH withcn:(int)cn withyfn:(int)fn withm:(int)m withData:(NSData*)data;

/// 发送打印QRCode命令
/// Send the print QRCODE command
/// @param cn cn = 49
/// @param fn fn = 81
/// @param m m = 48
-(void)addQRCodePrintwithpL:(int)pL withpH:(int)pH withcn:(int)cn withyfn:(int)fn withm:(int)m;

/// 设置是否汉字字体 Sets whether or not a Chinese font is present
/// @param n 是否倍宽 是否倍高 是否下划线
/// Whether to double the width, whether to double the height, whether to underline
-(void)addSetKanjiFontMode:(int)n;

/// 设置汉字有效 Set Chinese character valid
-(void)addSelectKanjiMode;

/// 设置汉字下划线 Set Chinese characters to underline
/// @param n 根据 n 的值，选择或取消汉字的下划线
/// Select or deselect the underlined character based on the value of n
-(void)addSetKanjiUnderLine:(int)n;

/// 设置汉字无效 Invalid setting of Chinese character
-(void)addCancelKanjiMode;

/// 设置字符右间距(Sets the right spacing of characters)
/// @param n 间距长度(Span length)
-(void)addSetCharacterRightSpace:(int)n;

/// 设置汉字左右间距
/// Sets the left and right spacing of Chinese characters
/// @param n1 左间距 0 ≤ n1 ≤ 255 (The left space 0 ≤ n1 ≤ 255)
/// @param n2 右间距 0 ≤ n2 ≤ 255 (The right spacing 0 ≤ n2 ≤ 255)
-(void)addSetKanjiLefttandRightSpace:(int)n1 :(int)n2;

/// 设置加粗模式(Set the bold mode)
/// @param n 是否加粗0 ≤ n ≤ 255 (Whether the bold 0 ≤ n ≤ 255)
-(void)addTurnEmphasizedModeOnOrOff:(int)n;

/// 设置加重模式(Set the weighting mode)
/// @param n 是否加重 0 ≤ n ≤ 255(Whether increasing 0 ≤ n ≤ 255)
-(void)addTurnDoubleStrikeOnOrOff:(int)n;

/// 设置水平和垂直单位距离(Sets horizontal and vertical unit distances)
/// @param x 水平单位(The level of the unit)
/// @param y 垂直单位(Vertical units)
-(void)addSetHorAndVerMotionUnitsX:(int)x Y:(int)y;

/// 设置绝对打印位置
/// Sets the absolute print location
/// @param n 与起始打印位置距离(Distance from the starting printing position)
-(void)addSetAbsolutePrintPosition:(int)n;

/// 设置打印宽度(Set the print width)
/// @param width 打印宽度(Print width)
-(void)addSetPrintingAreaWidth:(int)width;

/// 票据默认倍高（重启不失效）
/// The ticket is doubled by default (restart does not invalidate)
/// @param n1 宽     默认为0，翻倍为1 (Width defaults to 0 and doubled to 1)
/// @param n2 高     默认为0，翻倍为1 (Height defaults to 0 and doubled to 1)
/// @param n3 汉字宽  默认为0，翻倍为1 (The width of a character defaults to 0 and is doubled to 1)
/// @param n4 汉字高  默认为0，翻倍为1 (The character high defaults to 0 and doubles to 1)
-(void)receiptDoubleHeightOrDefaultPrintN1:(int)n1 N2:(int)n2 N3:(int)n3 N4:(int)n4;

/// 设置默认代码页(Set the default code page)
/// @param n 代码页 n的参数范围为（0-10，16-32，50-89）
/// The parameter range of code page n is (0-10, 16-32, 50-89)
-(void)setDefaultCodePage:(int)n;

/// 设置波特率(Set baud rate)
/// @param baudRate 波特率(Baud rate)
-(void)setBaudRate:(int)baudRate;

/// 查询打印机电量。 Query printer power.
/// <p>31（低电量）；32 (中电量)；33 (高电量)；35 (正在充电)</p>
/// 31 (low power); 32 (medium electric quantity); 33 (high power); 35 (charging)
-(void)queryElectricity;

/// 打印自检页 Print the self-check page
-(void)addSelfTest;

/// 设置黑标偏移量（Set the black mark offset）
/// @param a 设置切/撕纸位置或打印位置的偏移量（Sets the offset of the cutting/tearing position or the printing position）
/// @param m 选择偏移量为前进纸方向计算（Select the offset as the forward paper direction for calculation）
/// @param nL,nH 设置的偏移量对应的实际距离（The actual distance corresponding to the offset set）
- (void)setBlackMarkPositioningOffset:(int)pL pH:(int)pH a:(int)a m:(int)m nl:(int)nL nH:(int)nH;

/// 设置黑标起始位置（Set the black mark starting position）
- (void)setBlackMarkStartingPosition;

/// 获得打印命令
/// @return 指令集
- (NSData *)getCommand;

@end

NS_ASSUME_NONNULL_END
