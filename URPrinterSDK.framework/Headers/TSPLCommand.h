//
//  TSCCommand.h
//  URPrinterSDK
//
//  Created by urovo on 2023/4/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  @enum Response
 *
 *  @discussion 自动返回状态功能(Automatic return status function)
 */
typedef NS_ENUM (NSUInteger,Response){
    OFF     = 0,///<关闭自动返回状态功能(Turn off auto-return status)
    ON      = 1,///<打开自动返回状态功能，每打印完一张返回一次(Turn on the function of automatic return status, and return once after each print)
    BATCH   = 2,///<打开自动返回状态功能，打印完毕后返回一次(Turn on the automatic return function, and return once after printing)
};

@interface TSPLCommand : NSObject

/// 设置标签尺寸的宽和高(Sets the width and height of the label dimensions)
/// @param width 标签宽度(The label width)
/// @param height 标签高度(The label height)
- (void)addSize:(int) width :(int)height;

/// 设置标签间隙尺寸 单位mm(Sets the label gap size The unit of mm)
/// @param m 间隙长度(The length of the gap)
/// @param n 间隙偏移(The interval offset)
- (void)addGapWithM:(int) m withN:(int)n;

/// 设置黑标高度 单位mm(Set the height of the black mark in mm)
/// @param m 黑标长度(The length of the black mark)
/// @param n 黑标偏移(The black mark offset)
- (void)addBlineWithM:(int)m withN:(int)n;

/// 设置送纸偏移量 单位mm
/// @param offset 偏移量
- (void)addOffset:(int)offset;

/// 设置打印速度(Set print speed)
/// @param speed 打印速度(The printing speed)
- (void)addSpeed:(int)speed;

/// 设置打印浓度(Set the print concentration)
/// @param density 浓度(The concentration of)
- (void)addDensity:(int)density;

/// 设置打印方向(Set the print direction)
/// @param direction 方向(The direction of)
- (void)addDirection:(int) direction;

/// 设置标签原点坐标(Sets the label origin coordinates)
/// @param x 横坐标(abscissa)
/// @param y 纵坐标(ordinate)
- (void)addReference:(int) x :(int)y;

/// 清除打印缓冲区(Clear the print buffer)
/// 必须在SIZE后执行
- (void)addCls;

/// 设置送纸长度
/// @param feed  送纸长度
- (void)addFeed:(int)feed;

/// 在标签上绘制文字(Draws text on the label)
/// @param x 横坐标(abscissa)
/// @param y 纵坐标(ordinate)
/// @param font 字体类型(Font type)
/// @param rotation 旋转角度(Rotation Angle)
/// @param xScal 横向放大(Lateral magnification)
/// @param yScal 纵向放大(Longitudinal magnification)
/// @param text 文字字符串(Literal string)
- (void)addTextwithX:(int)x withY:(int)y withFont:(NSString*)font withRotation:(int)rotation withXscal:(int)xScal withYscal:(int)yScal withText:(NSString*) text;

/// 在标签上绘制文字(Draws text on the label)
/// @param x 横坐标(abscissa)
/// @param y 纵坐标(ordinate)
/// @param font 字体类型(Font type)
/// @param rotation 旋转角度(Rotation Angle)
/// @param xScal 横向放大(Lateral magnification)
/// @param yScal 纵向放大(Longitudinal magnification)
/// @param text 文字字符串(Literal string)
/// @param encoding 字符所用编码(Character encoding)
- (void)addTextwithX:(int)x withY:(int)y withFont:(NSString*)font withRotation:(int)rotation withXscal:(int)xScal withYscal:(int)yScal withText:(NSString *)text encoding:(NSStringEncoding)encoding;

/// 打印图片(Print pictures)
/// @param x 点阵影像的水平启始位置(The horizontal starting position of the lattice image)
/// @param y 点阵影像的垂直启始位置(The vertical starting position of the lattice image)
/// @param width 影像的宽度，以 byte 表示(The width of the image, expressed in byte)
/// @param height 影像的高度，以点(dot)表示(The height of the image, expressed as dot (dot))
/// @param mode 影像绘制模式(Image rendering mode)
/// 0 OVERWRITE
/// 1 OR
/// 2 XOR
/// @param data 影像数据(Image data)
- (void)addBitmapwithX:(int)x withY:(int)y withWidth:(int)width withHeight:(int)height withMode:(int)mode withData:(NSData *)data;

/// 打印图片(Print pictures)
/// @param x 点阵影像的水平启始位置(The horizontal starting position of the lattice image)
/// @param y 点阵影像的垂直启始位置(The vertical starting position of the lattice image)
/// @param mode 影像绘制模式(Image rendering mode)
/// 0 OVERWRITE
/// 1 OR
/// 2 XOR
/// @param width 图片宽度(Image width)
/// @param image 需要打印的图片(A picture that needs to be printed)
- (void)addBitmapwithX:(int)x withY:(int)y withMode:(int)mode withWidth:(int)width withImage:(UIImage *)image;

/// 打印图片(Print pictures)
/// @param x 点阵影像的水平启始位置(The horizontal starting position of the lattice image)
/// @param y 点阵影像的垂直启始位置(The vertical starting position of the lattice image)
/// @param mode 影像绘制模式(Image rendering mode)
/// 0 OVERWRITE
/// 1 OR
/// 2 XOR
/// @param image 需要打印的图片(A picture that needs to be printed)
- (void)addBitmapwithX:(int)x withY:(int)y withMode:(int)mode withImage:(UIImage *)image;

/// 在标签上绘制一维条码(Draws a one-dimensional bar code on the label)
/// @param x 横坐标(abscissa)
/// @param y 纵坐标(ordinate)
/// @param barcodeType 条码类型(Bar code type)
/// @param height 条码高度，默认为40(Bar code height, default is 40)
/// @param readable 是否可识别，0:人眼不可识，1:人眼可识(是否可识别，0:人眼不可识，1:人眼可识)
/// @param rotation 旋转角度，条形码旋转角度，顺时钟方向，0不旋转，90顺时钟方向旋转90度，180顺时钟方向旋转180度，270顺时钟方向旋转270度
/// Rotation Angle, Bar Code Rotation Angle, Clockwise, 0 does not rotate, 90 rotates 90 degrees Clockwise, 180 rotates 180 degrees Clockwise, 270 rotates 270 degrees Clockwise
/// @param narrow 默认值2，窄 bar 宽度，以点(dot)表示(Default value 2, narrow bar width, represented by dot (dot))
/// @param wide 默认值4，宽 bar 宽度，以点(dot)表示(Default value 4, wide bar width, expressed as dot (dot))
/// @param content 条码内容(Bar code content)
- (void)add1DBarcodewithX:(int)x withY:(int)y withBarcodeType:(NSString *)barcodeType withHeight:(int)height withReadable:(int)readable withRotation:(int)rotation withNarrow:(int)narrow withWide:(int)wide withContent:(NSString *)content;

/// 在标签上绘制QRCode二维码(Draw QRCode QR code on the label)
/// @param x 横坐标(abscissa)
/// @param y 纵坐标(ordinate)
/// @param ecclever 选择QRCODE纠错等级,默认为L，L为7%,M为15%,Q为25%,H为30%(Select QRCode error correction level, default is L, L is 7%,M is 15%,Q is 25%,H is 30%)
/// @param cellWidth 二维码宽度1~10，默认为4(QR code width 1~10, the default is 4)
/// @param mode 默认为A，A为Auto,M为Manual(The default is A, A is Auto, and M is Manual)
/// @param rotation 旋转角度，默认为0，QRCode二维旋转角度，顺时钟方向，0不旋转，90顺时钟方向旋转90度，180顺时钟方向旋转180度，270顺时钟方向旋转270度()
/// Rotation Angle, Bar Code Rotation Angle, Clockwise, 0 does not rotate, 90 rotates 90 degrees Clockwise, 180 rotates 180 degrees Clockwise, 270 rotates 270 degrees Clockwise
/// @param content 条码内容(Bar code content)
- (void)addQRCodewithX:(int)x withY:(int)y withEcclever:(NSString *)ecclever withCellWidth:(int)cellWidth withMode:(NSString *)mode withRotation:(int)rotation withContent:(NSString *)content;

/// 执行打印(Perform print)
/// @param m 指定打印的份数(Specifies the number of copies to be printed)
/// @param n 每张标签需要重复打印的张数(Number of duplicate prints per label)
- (void)addPrint:(int)m :(int)n;

/// 发送一些TSC的固定命令，在cls命令之前发送(Send some TSC fixed commands before CLS commands)
- (void)addComonCommand;

/// 打印自检页，打印测试页(Print the self-check page, print the test page)
- (void)addSelfTest;

/// 查询打印机型号(Query Printer Type)
- (void)queryPrinterType;

/// 设置打印机剥离模式(Set printer stripping mode)
/// @param peel ON/OFF 是否开启(Whether open)
- (void)addPeel:(NSString *)peel;

/// 设置打印机撕离模式(Set the printer to tear mode)
/// @param tear ON/OFF 是否开启(Whether open)
- (void)addTear:(NSString *)tear;

/// 设置切刀是否有效(Sets whether the cutter is valid)
/// @param cutter 是否开启 OFF/pieces(Whether open)
- (void)addCutter:(NSString *)cutter;

/// 设置切刀半切是否有效(Sets whether half cutting of the cutter is effective)
/// @param cutter 是否开启(Whether open)
- (void)addPartialCutter:(NSString *)cutter;

/// 设置蜂鸣器(Set the buzzer)
/// @param level 频率(frequency)
/// @param interval 时间ms(Time ms)
- (void)addSound:(int)level :(int)interval;

/// 打开钱箱命令,CASHDRAWER m,t1,t2(Open the cash box command,CASHDRAWER m,t1,t2)
/// @param m  钱箱号 m 0，48 钱箱插座的引脚2 1，49 钱箱插座的引脚5
/// Cashbox No. M 0,48 Pins of Cashbox Socket 2, 1,49 Pins of Cashbox Socket 5
/// @param t1 高电平时间0 ≤ t1 ≤ 255输出由t1和t2设定的钱箱开启脉冲到由m指定的引脚
/// The high level time 0 ≤ T1 ≤ 255 outputs the moneybox opening pulse set by T1 and T2 to the pin specified by M
/// @param t2 低电平时间0 ≤ t2 ≤ 255输出由t1和t2设定的钱箱开启脉冲到由m指定的引脚
/// Low level time 0 ≤ T2 ≤ 255 Output from the money box set by T1 and T2 opening pulse to pin specified by M
- (void)addCashdrawer:(int)m :(int)t1 :(int)t2;

/// 在标签上绘制黑块，画线(Draw a black block on the label and draw a line)
/// @param x 起始横坐标(Initial abscissa)
/// @param y 起始纵坐标(Initial ordinate)
/// @param width 线宽，以点(dot)表示(Line width, expressed as dot (dot))
/// @param height 线高，以点(dot)表示(The height of the line is indicated by a dot (dot))
- (void)addBar:(int)x :(int)y :(int)width :(int)height;

/// 在标签上绘制矩形(Draws a rectangle on the label)
/// @param xStart 起始横坐标(Initial abscissa)
/// @param yStart 起始纵坐标(Initial ordinate)
/// @param xEnd 终点横坐标(Terminal abscissa)
/// @param yEnd 终点纵坐标(Terminal ordinate)
/// @param lineThickness 矩形框线厚度或宽度，以点(dot)表示(The thickness or width of a rectangular frame line, denoted by a dot (dot))
- (void)addBox:(int)xStart :(int)yStart :(int)xEnd :(int)yEnd :(int)lineThickness;

/// 查询打印机状态(Query printer status)
- (void)queryPrinterStatus;

/// 将指定的区域反向打印（黑色变成白色，白色变成黑色）(Prints the specified area backwards (black to white, white to black))
/// @param xStart 起始横坐标(Initial abscissa)
/// @param yStart 起始横坐标(Initial abscissa)
/// @param width X坐标方向宽度，dot为单位(The width in the direction of the X coordinate, in dot)
/// @param height Y坐标方向高度，dot为单位(The height in the Y direction, in dot)
- (void)addReverse:(int)xStart :(int)yStart :(int)width :(int)height;

/// 打印机打印完成时，自动返回状态。可用于实现连续打印功能
/// When the printer finishes printing, it returns to the state automatically. Can be used to achieve continuous printing function
/// @param response 自动返回状态(Automatic return state)
- (void)addQueryPrinterStatus:(Response)response;

/// 查询打印机电量(Query Printer Power)
- (void)queryElectricity;

/// 设定黑标高度及定义标签印完后标签额外送出的长度
/// Set the height of the black label and define the extra length of the label after printing
/// @param m 黑标高度（0≤m≤1(inch)，0≤m≤25.4(mm)）(Height of black mark (0≤m≤1(inch), 0≤m≤25.4(mm)))
/// @param n 额外送出纸张长度 n≤标签纸纸张长度(inch或mm)(Extra paper length N ≤ label paper length (inch or mm))
- (void)addBLine:(int)m :(int)n;

/// 添加代码页 Add a code page
/// @param codepage 字符集代表 Character set representation
- (void)addCodepage:(NSString *)codepage;

/// 获得打印命令
/// @return 指令集
- (NSData *)getCommand;

@end

NS_ASSUME_NONNULL_END
