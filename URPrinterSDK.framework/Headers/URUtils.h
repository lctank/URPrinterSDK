//
//  URUtils.h
//  URPrinterSDK
//
//  Created by urovo on 2023/4/23.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "URPrinterOptions.h"

NS_ASSUME_NONNULL_BEGIN

@interface URUtils : NSObject

/// 图片抖动处理(Image dithering)
/// @param reverse 是否取反(Whether to take the)
/// @return 处理完成的图片(Process the finished picture)
+ (UIImage *)ditherWithImage:(UIImage *) image andReverse:(BOOL)reverse;

/// 图片缩放(Image Zoom)
/// @param image 原图(The original image)
/// @param width 目标宽度(The target width)
+ (UIImage *)imageWithScaleImage:(UIImage *)image andScaleWidth:(int)width;

/// ESC指令图片数据(ESC instruction picture data)
/// @param image 图片(Image)
+ (NSData *)printEscData:(UIImage *)image;

/// TSC指令图片数据(TSC instruction picture data)
/// @param image 图片(Image)
+ (NSData *)printTscData:(UIImage *)image;

/// Tsc指令图片数据(TSC instruction picture data)
/// @param image 图片(Image)
/// @param mode 模式 0:不压缩 3:压缩(mode 0:Non-compacting 3:compression)
+ (NSData *)printTscData:(UIImage *)image andMode:(int)mode;

/// CPCL指令图片数据(CPCL instruction picture data)
/// @param image 图片(Image)
+ (NSData *)printCpclData:(UIImage *)image;

/// CPCL指令图片数据(CPCL instruction picture data)
/// @param image 图片(Image)
/// @param threshold 二值化阈值 0:自动 1-255:手动(Binarization threshold 0: automatic 1-255: manual)
+ (NSData *)printCpclData:(UIImage *)image withThreshold:(int)threshold;

/// ZPL指令图片数据
/// @param image 图片
+ (NSString *)printZplData:(UIImage *)image;

/// 图像二值化 - 指定阈值 (Image binarization - Specify Thresholds)
/// @param image 图片(Image)
/// @param threshold 阈值 0-255 (threshold 0-255)
/// @param reverse 黑白反转 (Black and white and reverse)
+ (UIImage *)binaryzation:(UIImage *)image withThreshold:(int)threshold withReverse:(BOOL)reverse;

/// 图像二值化 - 自适应阈值 (Image binarization - Adaptive thresholds)
/// @param image 图片(Image)
/// @param reverse 黑白反转 (Black and white and reverse)
+ (UIImage *)binaryzationAutoThreshold:(UIImage *)image withReverse:(BOOL)reverse;

/// 图像灰度化处理(Image graying processing)
/// @param image 图片(Image)
+ (UIImage *)grayImage:(UIImage *)image;

/// 图片处理。使用该方法处理需打印图片，图片将进行灰度化及抖动处理，保留图片信息较全
/// Image processing. This method is used to process the picture to be printed, the picture will be grayscale and dither processing, to retain the picture information is more complete
/// @param img 需打印的图像(Image)
+ (UIImage *)convertGreyImgByFloyd:(UIImage *)img;

/// BarcodeType -> String
/// @param type BarcodeType
+ (NSString *)barcodeTypeToStr:(URBarcodeType)type;

/// Alignment -> String
/// @param alignment Alignment
+ (NSString *)alignmentToStr:(URPrintAlignment)alignment;

/// TextAngle -> String
/// @param angle TextAngle
+ (NSString *)textAlignmentToStr:(URTextAngle)angle;

/// QRCodeLevel -> String
/// @param level QRCodeLevel
+ (NSString *)qrcodeLevelToStr:(URQRCodeLevel)level;

/// Mode -> String
/// @param mode Mode
+ (NSString *)qrcodeInputModeToStr:(URQRCodeInputMode)mode;

/// Orientation -> String
/// @param orientation orientation
+ (NSString *)orientationToStr:(URPrintOrientationType)orientation;

/// 检测字符串是否为数字(Checks if the string is a number)
/// @param str 字符串(String)
+ (BOOL)checkStringIsNumber:(NSString *)str;

/// Graphics -> String
/// @param graphics Graphics
+ (NSString *)graphicsToStr:(URPrintGraphicsType)graphics;

/// 截图(screenshot)
/// @param views 目标视图(Objective view)
+ (UIImage *)view2Image:(UIView *)views;

/// 改变图片方向(Change the orientation of the picture)
/// @param image 图片(Image)
/// @param orientation 方向(orientation)
+ (UIImage *)image:(UIImage *)image rotation:(UIImageOrientation)orientation;

@end

NS_ASSUME_NONNULL_END
