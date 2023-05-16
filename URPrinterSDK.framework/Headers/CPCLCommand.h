//
//  CPCLCommnad.h
//  URPrinterSDK
//
//  Created by urovo on 2023/4/23.
//

#import <Foundation/Foundation.h>
#import <URPrinterSDK/URPrinterOptions.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CPCLCommand : NSObject

/// 标签初始化(Tag initialization)
/// @param offset 标签横向偏移量 (Label lateral offset)
/// @param horizontalDpi 横向DPI (Transverse DPI)
/// @param verticalDpi 纵向DPI (Vertical DPI)
/// @param height 标签最大高度 (Maximum label height)
/// @param qty 打印的数量 (Number of Prints)
- (void)addInitializePrinterOffset:(int)offset horizontalDpi:(int)horizontalDpi verticalDpi:(int)verticalDpi height:(int)height qty:(int)qty;

/// 执行打印(Perform print)
- (void)addPrint;

/// 执行反向打印(Perform reverse printing)
- (void)addPOPrint;

/// 打印文本(Print text)
/// @param angle 文本旋转角度(Text rotation Angle)
/// @param font 文本字体(The text font)
/// @param size 字体大小(Size)
/// @param x 文本横向起始位置(The horizontal starting position of the text)
/// @param y 文本纵向起始位置(Vertical starting position of the text)
/// @param content 需要打印的内容(What needs to be printed)
- (void)addTextAngle:(URTextAngle)angle withFont:(int)font size:(int)size x:(int)x y:(int)y content:(NSString *)content;

/// 文本串联(Text series)
/// @param x 文本横向起始位置(The horizontal starting position of the text)
/// @param y 文本纵向起始位置(Vertical starting position of the text)
- (void)addConcatText:(int)x withY:(int)y;

/// 串联文本内容(Tandem text content)
/// @param font 字体名称/编号(Font name/number)
/// @param size 字体大小(Size)
/// @param offset 文本相对起始位置偏置单位值(The unit value of the text is offset relative to the starting position)
/// @param content 要打印的文本(The text to print)
- (void)addTextFont:(int)font size:(int)size offset:(int)offset content:(NSString *)content;

/// 终止文本串联(Terminate text concatenation)
- (void)endConcatText;

/// 放大字体(enlarge font)
/// @param w 宽度放大倍数，有效放大倍数为1~16(Width magnification, effective magnification is 1~16)
/// @param h 高度放大倍数，有效放大倍数为1~16(High magnification, effective magnification is 1~16)
- (void)addSetmagWidth:(int)w height:(int)h;

/// 字体加粗(font bold)
/// @param isBlod YES:加粗(bold) NO:(Not bold)
- (void)addSetBlod:(BOOL)isBlod;

/// 打印条形码(Print Barcode)
/// @param orientation 条码方向(Direction of the barcode)
/// @param type 条码类型(Bar code type)
/// @param width 窄条的单位宽度(The unit width of a narrow strip)
/// @param ratio 宽条与窄条的比率(The ratio of wide bars to narrow bars)
/// @param height 条码单位高度(Bar code unit height)
/// @param x 条码横向起始位置(Horizontal starting position of barcode)
/// @param y 条码纵向起始位置(Longitudinal starting position of the barcode)
/// @param content 条码数据(Barcode data)
- (void)addBarcodeOrientation:(URPrintOrientationType)orientation type:(URBarcodeType)type withWidth:(int)width ratio:(int)ratio height:(int)height x:(int)x y:(int)y content:(NSString *)content;

/// 打印PDF-417条码(Print PDF-417 barcode)
/// @param orientation 条码方向(Direction of the barcode)
/// @param x 条码横向起始位置(Horizontal starting position of barcode)
/// @param y 条码纵向起始位置(Longitudinal starting position of the barcode)
/// @param XD 宽度最小点数，值的范围为1-32，默认为2(Width minimum number of points, values range from 1 to 32, default is 2)
/// @param YD 高度最小点数，值的范围为1-32，默认为6(Height minimum number of points, values range from 1 to 32, default is 6)
/// @param C 每行容纳的码数，值的范围为1-30，默认为3(The number of yards per line. Values range from 1 to 30. Default is 3)
/// @param S 纠错等级，值的范围为0-8，默认为1(Error correction level. Values range from 0 to 8. Default is 1)
/// @param content PDF-417条码数据(PDF-417 barcode data)
- (void)addPDF417Orientation:(URPrintOrientationType)orientation x:(int)x y:(int)y XD:(int)XD YD:(int)YD C:(int)C S:(int)S content:(NSString *)content;

/// DATAMATRIX
/// @param x 条码横向起始位置(Horizontal starting position of barcode)
/// @param y 条码纵向起始位置(Longitudinal starting position of the barcode)
/// @param H 条码点密度，值的范围是0-标签范围，一般设置为3-8(Bar code point density, the value range is 0- label range, generally set to 3-8)
/// @param content 条码数据(barcode data)
- (void)addDatamatrixWithX:(int)x y:(int)y H:(int)H content:(NSString *)content;

/// 用于通过创建条码时所用的相同数据来标记条码，避免了使用单独文本命令注释条码的必要。文本位于条码下方的中间位置
/// Used to mark a bar code with the same data that was used when it was created, eliminating the need to annotate the bar code with a separate text command. The text is in the middle below the bar code
/// @param font 注释条码时要使用的字体号 (The font number to use when commenting the barcode)
/// @param offset 文本距离条码的单位偏移量 (The unit offset of the text distance bar code)
- (void)addBarcodeTextFont:(int)font offset:(int)offset;

/// 禁用BARCODE-TEXT命令效果 (Disable the barcode-text command effect)
- (void)addBarcodeTextOff;

/// 初始化二维码参数(Initialize QR code parameters)
/// @param orientation 打印方向(The print direction)
/// @param x 横向起始位置(Lateral starting position)
/// @param y 纵向起始位置(Longitudinal starting position)
/// @param m QR Code 规范编号,1 或 2，推荐为 2(QR Code specification number,1 or 2, recommended as 2)
/// @param u 模块的单位宽度/单位高度 1-32，默认为 6(The unit width/unit height of the module is 1-32, default is 6)
- (void)addQRCodeVertical:(URPrintOrientationType)orientation x:(int)x y:(int)y m:(int)m u:(int)u;

/// 打印二维码(Print QR code)
/// @param level 纠错等级(Error correction level)
/// @param mask 掩码，掩码有效范围为0-8，mask<0||mask>8省略掩码，交由下位机处理(Mask, mask valid range is 0 to 8, mask < 0 | | mask > 8 omit mask, to the next bit machine processing)
/// @param mode 输入模式(The input mode)
/// @param content 二维码内容(QR code content)
- (void)addQRCodeLevel:(URQRCodeLevel)level mask:(int)mask mode:(URQRCodeInputMode)mode content:(NSString *)content;

/// 打印二维码(Print QR code)
/// @param level 纠错等级(Error correction level)
/// @param content 二维码内容(QR code content)
- (void)addQRCodeLevel:(URQRCodeLevel)level content:(NSString *)content;

/// 结束QR Code指令(End the QR Code instruction)
- (void)endQRCode;

/// 打印矩形(Print rectangular)
/// @param x0 左上角的 X 坐标(The top left x-coordinate)
/// @param y0 左上角的 Y 坐标(The top left y-coordinate)
/// @param x1 右下角的 X 坐标(The lower right x-coordinate)
/// @param y1 右下角的 Y 坐标(The lower right y-coordinate)
/// @param width 形成矩形框线条的单位宽度(The unit width of a line that forms a rectangle)
- (void)addBoxX0:(int)x0 y0:(int)y0 x1:(int)x1 y1:(int)y1 width:(int)width;

/// 打印线条(Print lines)
/// @param x0 起始点的 X 坐标(The x-coordinate of the starting point)
/// @param y0 起始点的 Y 坐标(The y-coordinate of the starting point)
/// @param x1 终止点的 X 坐标(The x-coordinate of the termination point)
/// @param y1 终止点的 Y 坐标(The y-coordinate of the termination point)
/// @param width 线条的单位宽度(The unit width of a line)
- (void)addLineX0:(int)x0 y0:(int)y0 x1:(int)x1 y1:(int)y1 width:(int)width;

/// INVERSE-LINE 命令的语法与 LINE 命令相同。位于 INVERSE-LINE 命令所定义 区域内的以前创建的对象的黑色区域将重绘为白色，白色区域将重绘为黑色。这 些对象可以包括文本、条码和/或图形。INVERSE-LINE 对在其之后创建的对象不 起作用，即使这些对象位于该命令的覆盖区域内也是如此
/// The inverse-line command has the same syntax as the LINE command. The black areas of previously created objects that are within the areas defined by the inverse-line command are redrawn as white, and the white areas are redrawn as black. These objects can include text, bar codes, and/or graphics. Inverse-line does not work on objects created after it, even if they are in the overlay area of the command
/// @param x0 起始点的 X 坐标(The x-coordinate of the starting point)
/// @param y0 起始点的 Y 坐标(The y-coordinate of the starting point)
/// @param x1 终止点的 X 坐标(The x-coordinate of the termination point)
/// @param y1 终止点的 Y 坐标(The y-coordinate of the termination point)
/// @param height 反色区域高度(Height of the color inversion area)
- (void)addInverseLineX0:(int)x0 y0:(int)y0 x1:(int)x1 y1:(int)y1 height:(int)height;

/// 图形命令打印位映射图形(The graphics command prints the bitmap graph)
/// @param graphics 图形打印模式(Graphic printing mode)
/// @param width 图形的宽度(Width of the figure)
/// @param x 横向起始位置(Lateral starting position)
/// @param y 纵向起始位置(Longitudinal starting position)
/// @param image 图片(Image)
/// @param threshold 二值化阈值 0:自动 1-255:手动(Binarization threshold 0: automatic 1-255: manual)
- (void)addImageGraphics:(URPrintGraphicsType)graphics width:(int)width x:(int)x y:(int)y image:(UIImage *)image withThreshold:(int)threshold;

/// 使用对齐命令可以控制字段的对齐方式(Use the alignment command to control the alignment of fields)
/// @param alignment 对齐方式(alignment)
/// @param end 对齐的结束点。如果未输入参数，则对于横向打 印，对齐命令将使用打印头的宽度;而对于纵向 打印，对齐命令将使用零(页头)
/// End point of alignment. If no arguments are entered, the alignment command uses the width of the print head for landscape printing; For portrait printing, the alignment command will use zero (header)
- (void)addJustification:(URPrintAlignment)alignment end:(int)end;

/// 字段的对齐方式(Field alignment)
/// @param alignment 对齐方式(alignment)
- (void)addJustification:(URPrintAlignment)alignment;

/// 打印机假定页面宽度为打印机的完整宽度(The printer assumes that the page width is the full width of the printer)
/// @param width 页面的单位宽度(The unit width of the page)
-(void)addPageWidth:(int)width;

/// 设置打印速度(Set print speed)
/// @param level 速度级别(Speed level)
- (void)addSpeed:(int)level;

/// 设置蜂鸣器(Set the buzzer)
/// @param time 蜂鸣持续时间，以 1/8 秒为单位递增(The duration of buzzing is increased by 1/8 of a second)
- (void)addBeep:(int)time;

/// 查询打印机状态(Query printer status)
- (void)queryPrinterStatus;

/// 添加水印 (Add a watermark)
/// @param font 字体名称/编号(Font name/number)
/// @param size 字体大小(Size)
/// @param x 文本横向起始位置(The horizontal starting position of the text)
/// @param y 文本纵向起始位置(Vertical starting position of the text)
/// @param content 要打印的文本(The text to print)
- (void)addWatermarkText:(int)font size:(int)size x:(int)x y:(int)y content:(NSString *)content;

/// 设置水印背景浓度（Sets the watermark background concentration）
/// @param n 水印背景浓度 0 < n < 255 (Watermark background concentration 0 < n < 255)
- (void)setWatermark:(UInt8)n;

/// 设置右黑标检测指令（Set the right black mark detection instruction）
- (void)setBarSense;

/// 设置左黑标检测指令（Set the left black mark detection instruction）
- (void)setBarSenseLeft;

/// 设置间隙检测指令（Set clearance detection instruction）
- (void)setGapSense;

/// 设置检测指令结尾（Sets the end of the detection instruction）
- (void)setForm;

/// 获得打印命令
/// @return 指令集
- (NSData *)getCommand;

@end

NS_ASSUME_NONNULL_END
