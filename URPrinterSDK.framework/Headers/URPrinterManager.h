//
//  URPrinterManager.h
//  URPrinterSDK
//
//  Created by urovo on 2023/4/20.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "URPrinterOptions.h"

NS_ASSUME_NONNULL_BEGIN


@interface URPrinterManager : NSObject

/// 是否连接设备（蓝牙或者wifi）
@property(nonatomic,assign,readonly)BOOL isConnect;

/// 当前蓝牙状态
@property(nonatomic,assign,readonly)URBluetoothState bluetoothState;

/// 打印方式（蓝牙或者wifi）
@property(nonatomic,assign,readonly)URPrintType printType;

/// 是否正在打印，用户自行设置
@property(nonatomic,assign)BOOL isPrinting;


+ (instancetype)sharedInstance;

/** 蓝牙 */

/// 初始化蓝牙
/// - Parameter state: 蓝牙状态
- (void)initBluetooth:(void(^_Nonnull)(URBluetoothState state))bluetoothState;

/// 扫描设备
/// - Parameters:
///   - serviceUUIDs: 需要发现外设的UUID，设置为nil则发现周围所有外设
///   - options: 其它可选操作
///   - discover: 发现的设备
- (void)scanForPeripheralsWithServices:(nullable NSArray<CBUUID *> *)serviceUUIDs options:(nullable NSDictionary<NSString *, id> *)options discover:(void(^_Nullable)(CBPeripheral *_Nullable peripheral,NSDictionary<NSString *, id> *_Nullable advertisementData,NSNumber *_Nullable RSSI))discover;

/// 停止扫描
- (void)stopScan;

/// 连接外设
/// @param peripheral 需要连接的外设
/// @param options 其他可选操作
/// @param timeout 连接超时时间  默认30秒
/// @param connectState 连接状态
-(void)connectPeripheral:(CBPeripheral *)peripheral options:(nullable NSDictionary<NSString *,id> *)options timeout:(NSUInteger)timeout connectBlack:(void(^_Nullable)(URConnectState state))connectState;

/// 写入数据，此方法只适用于蓝牙数据发送
/// @param data 写入的数据
/// @param progress 写入进度
/// @param callBack 蓝牙返回的数据
-(void)write:(NSData *_Nullable)data progress:(void(^_Nullable)(NSUInteger total,NSUInteger progress))progress callBack:(void (^_Nullable)(NSData *_Nullable))callBack;

/// 断开蓝牙外设
/// @param peripheral 需要断开连接的外设
/// @param connectState 连接状态
- (void)disConnectPeripheral:(CBPeripheral *)peripheral connectBlack:(void(^_Nullable)(URConnectState state))connectState;


/** WIFI */

/// 连接设备
/// @param ip 连接设备的ip地址
/// @param port 连接设备的端口号
/// @param connectState 连接状态
-(void)connectIP:(NSString *)ip port:(int)port connectState:(void (^)(URConnectState state))connectState;

/// 发送数据,此方法只适用于WiFi数据发送
/// @param data 要发送的数据
/// @param callBack 结果回调
-(void)write:(NSData *_Nullable)data callBack:(void (^_Nullable)(NSData *_Nullable))callBack;

/// 断开WIFI连接
- (void)disConnectIP;

/// 断开连接，不区分WIFI和蓝牙
- (void)closeAllConnect;

@end

NS_ASSUME_NONNULL_END
