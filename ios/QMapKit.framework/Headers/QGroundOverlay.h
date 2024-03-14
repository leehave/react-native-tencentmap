//
//  QGroundOverlay.h
//  QMapKit
//
//  Created by fan on 2020/4/21.
//  Copyright © 2020 tencent. All rights reserved.
//

#import <QMapKit/QGLOverlay.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief   用于地面(图片)覆盖物的数据类
 */
@interface QGroundOverlay : QGLOverlay
{
    @package
    QMapRect _boundingRect;
}

/**
 * @brief  区域外接矩形
 */
@property(nonatomic, readonly) QMapRect boundingMapRect;

///**
// * @brief 图片纹理透明度, 最终透明度 = 纹理透明度 * opacity, 取值范围为[0.0f, 1.0f]，默认为1.0f
// */
//@property(nonatomic, assign) CGFloat opacity;

/**
 * @brief 根据指定区域生成一个groundOverlay
 * @param bounds 指定的经纬度区域
 * @param icon 绘制使用的图片
 * @return 新生成的groundOverlay对象
 */
+ (QGroundOverlay *)groundOverlayWithBounds:(QCoordinateBounds)bounds
                                         icon:(UIImage*)icon;

/**
 * @brief 根据指定经纬度坐标生成一个groundOverlay
 * @param position 图片在地图上的经纬度坐标
 * @param zoomLevel 不损失精度绘制原始图片的地图等级
 * @param anchor 绘制图片的锚点. 左上角为(0,1). 有效区间[0,1]
 * @param icon   绘制使用的图片
 * @return 新生成的groundOverlay对象
 */
+ (QGroundOverlay *)groundOverlayWithCoordinate:(CLLocationCoordinate2D)position
                                        zoomLevel:(CGFloat)zoomLevel
                                           anchor:(CGPoint)anchor
                                             icon:(UIImage*)icon;

/**
 * @brief 更新GroundOverlay. 
 * @param bounds 图片的在地图的覆盖范围
 * @param icon   覆盖图片
 */
- (void)setGroundOverlayWithBounds:(QCoordinateBounds)bounds icon:(UIImage *)icon;
/**
 * @brief 更新GroundOverlay, 内部会自动计算覆盖物大小，以满足zoomLevel下显示大小为icon大小.
 * @param position 图片在地图上的经纬度坐标
 * @param zoomLevel  图片在地图尺寸等同于像素的zoom值
 * @param anchor 绘制图片的锚点. 左上角为(0,1). 有效区间[0,1]
 * @param icon       覆盖图片
 */
- (void)setGroundOverlayWithCoordinate:(CLLocationCoordinate2D)position
                             zoomLevel:(CGFloat)zoomLevel
                                anchor:(CGPoint)anchor
                                  icon:(UIImage *)icon;

@end

NS_ASSUME_NONNULL_END
