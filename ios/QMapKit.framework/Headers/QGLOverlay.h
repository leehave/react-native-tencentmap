//
//  QGLOverlay.h
//  QMapKit
//
//  Created by fan on 2020/5/21.
//  Copyright © 2020 tencent. All rights reserved.
//

#import "QShape.h"
#import "QOverlay.h"
#import "QOverlayObject.h"

NS_ASSUME_NONNULL_BEGIN

@class QGLOverlay;
/**
 *  @brief 可自定义渲染内容的覆盖物加载状态
*/
typedef enum : NSInteger {
    QGLOverlayLoadError_Internal        = -20,
    QGLOverlayLoadSuccess               = 0,
    QGLOverlayLoading                   = 1
} QGLOverlayLoadStatus;

/**
 * @brief QGLOverlayDelegate:GLOverlay的Delegate,GLOverlay通过此类来通知用户对应的事件
 **/
@protocol QGLOverlayDelegate <NSObject>

@optional
/**
 *  @brief  glOverlay被点击后会调用此接口
 *
 *  @param glOverlay  被点击的GLOverlay
 *  @param overlayObject  可被点击对象
*/
- (void)glOverlay:(QGLOverlay *)glOverlay didTap:(QOverlayObject *)overlayObject;

/**
 * @brief 可自定义渲染内容的覆盖物加载回调协议
 * @param overlay 对应的自定义覆盖物
 * @param status 加载状态
 * @param progress 加载进度
*/
- (void)glOverlay:(QGLOverlay *)overlay loadStatus:(QGLOverlayLoadStatus)status withProgress:(CGFloat)progress;

@end

/**
* @brief 可自定义渲染内容的覆盖物
*/
@interface QGLOverlay : QShape <QOverlay>

/*!
 *  @brief  实现QGLOverlayDelegate协议的对象
 */
@property (nonatomic, weak) id<QGLOverlayDelegate> delegate;

/**
 * @brief 是否可见. (默认YES)
 */
@property (nonatomic, assign) BOOL visible;
/**
 * @brief 整个图层的透明度. (默认1.0)
 */
@property (nonatomic, assign) CGFloat opacity;

/**
 * @brief 最小显示级别. (默认3)
 */
@property (nonatomic, readonly) int minZoomLevel;
/**
 * @brief 最大显示级别. (默认22)
 */
@property (nonatomic, readonly) int maxZoomLevel;

/**
 * @brief 设置最小显示级别.
 */
- (void)setMinZoomLevel:(int)minZoomLevel maxZoomLevel:(int)maxZoomLevel;

/**
 * @brief 获取覆盖物类型.
 */
- (NSString *)getType;

/**
 * @brief 覆盖物渲染实现. 请不要直接调用
 */
- (void)render;

/**
* @brief 触发一次渲染
*/
- (void)setNeedsDisplay;

/**
* @brief 覆盖物的外接矩形
*/
@property(nonatomic, readonly) QMapRect boundingMapRect;

/**
 * @brief 覆盖物是否响应点击, 默认：NO
 */
@property (nonatomic, assign) BOOL interactive;

/**
 * @brief 获取覆盖物是否支持点击
 */
- (BOOL)isSupportClick;

/**
 *  @brief 获取当前地图view矩阵
 *  @return 矩阵数组（长度为16）
 */
- (float *)glViewMatrix;

/**
 *  @brief 获取当前地图projection矩阵
 *  @return 矩阵数组（长度为16）
 */
- (float *)glProjectionMatrix;

/**
* @brief 将经纬度坐标转换为OpenGL使用的坐标
* @param coordinate 经纬度坐标
* @return OpenGL坐标系下的坐标
*/
- (CGPoint)glVertexForCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 * @brief  返回每屏幕Point单位对应的OpenGL坐标系下的长度
 * @return OpenGL/屏幕Point 的比例关系
 */
- (CGFloat)glPointRatio;

@end

NS_ASSUME_NONNULL_END
