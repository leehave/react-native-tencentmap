//
//  QVisualLayer.h
//  QMapKit
//
//  Created by Keith Cao on 2021/5/18.
//  Copyright © 2021 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class QMapView;
@class QVisualLayer;


/**
 *  @brief QVisualLayer的加载状态
*/
typedef enum : NSInteger {
    QVisualLayerLoadSuccess               = 0,
    QVisualLayerLoadError_Network         = 1,
    QVisualLayerLoadError_Auth            = 2,
    QVisualLayerLoadError_Decode          = 3,
    QVisualLayerLoadError_BadFormat       = 4,
    QVisualLayerLoadError_Internal        = 20,
} QVisualLayerLoadStatus;


/// QVisualLayer可视化数据图层的事件回调协议
@protocol QVisualLayerDelegate <NSObject>

@optional

/**
 *  @brief  可视化数据图层加载时会调用此接口
 *
 *  @param layer 可视化数据图层
 *  @param error 错误信息. 如果nil则成功。errorcode目前支持：
 *  			 系统网络错误码          1
 *               权限错误               2
 *               数据错误               3
 */
- (void)visualLayerDidFinshLoading:(QVisualLayer *)layer withError:(NSError *)error;

/**
 *  @brief 回调统一出口.
 *  @param layer layer实例
 *  @param eventType 事件类型
 *  @param eventInfoJson 事件详情信息.
 */
- (void)onVisualLayerEvent:(QVisualLayer *)layer eventType:(NSString *)eventType eventInfoJson:(NSString *)eventInfoJson;

/**
 *  @brief  可视化数据图层日志
 *
 *  @param log 可视化数据图层
 *  @param level logcat:
 *  0: Verbose (lowest priority)
 *  1: Debug
 *  2: Info
 *  3: Warning
 *  4: Error
 *  5: Fatal
 */
- (void)onVisualLayerLog:(QVisualLayer *)layer log:(NSString *)log logLevel:(int)level;

@end

/**
 * @brief 用于可视化数据图层的类
 */
@interface QVisualLayer : NSObject
/**
 * @brief 初始化
 * @param layerID 图层的唯一标识
 */
- (instancetype)initWithUID:(NSString *)layerID;

/**
 * @brief 创建图层副本对象
 */
- (instancetype)clone;

/**
 * @brief 图层的唯一标识. 在可视化数据图层编辑平台成功上传图层数据时得到的其标识字符串
 */
@property (nonatomic, copy, readonly) NSString *layerID;

/**
 *  @brief  是否显示. 默认YES
 */
@property (nonatomic, assign) BOOL visible;

/**
 * @brief 透明度，取值范围[0,1] ，默认为1不透明
 */
@property (nonatomic, assign) CGFloat opacity;

/**
 * @brief 覆盖物的显示顺序，决定了它与其它QGLOverlay的压盖关系. 默认为0.
 *
 * 大值压盖小值. 只有同displayLevel的QGLOverlayView才会比较zIndex
 */
@property (nonatomic, assign) int zIndex;

/**
 *  @brief 回调代理
 */
@property (nonatomic, weak) id<QVisualLayerDelegate> delegate;

/**
 *  @brief 图层刷新数据时间, 单位:秒。
 *  	   0为不刷新, 最小时间间隔为15秒, 默认为0
 */
@property (nonatomic, assign) NSTimeInterval interval;

/**
 *  @brief 清理图层本地缓存
 */
- (void)clearCache;

@end

@interface QVisualLayer (GeneralProtocol)

/**
 *  @brief 通用协议函数调用统一入口.
 *  @param mapView 地图实例
 *  @param commandJson 命令Json字符串
 *  @return 函数返回值.
 */
- (NSString *)executeCommand:(QMapView *)mapView commandJson:(NSString *)commandJson __attribute__ ((deprecated("use QMapView - (NSString *)executeCommand:(NSString *)commandJson withVisualLayer:(QVisualLayer *)visualLayer")));

@end
