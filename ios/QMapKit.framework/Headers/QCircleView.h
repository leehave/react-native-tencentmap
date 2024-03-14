//
//  QCircleView.h
//  QMapKit
//
//  Created by fan on 2017/5/21.
//  Copyright © 2017年 tencent. All rights reserved.
//

#import "QOverlayPathView.h"
#import "QCircle.h"

/**
 *  @brief  该类是QCircle用来显示圆的view
 *
 * 可以通过QOverlayPathView修改其fill和stroke相关属性来配置样式
 */
@interface QCircleView : QOverlayPathView

/**
 *  @brief  根据指定圆生成对应的view
 *
 *  @param circle 指定的QCircle对象
 *
 *  @return 生成的view
 */
- (id)initWithCircle:(QCircle *)circle;

/**
 *  @brief  关联的QCirlce对象
 */
@property (nonatomic, readonly) QCircle *circle;

/**
 *  @brief 圆的描边样式，。默认为 QOverlayStrokeType_Default 实线。
 *
 *   QOverlayStrokeType_Default： 实线
 *   QOverlayStrokeType_Dash：长方块虚线，虚线间隔配置参考 lineDashPattern变量
 *   QOverlayStrokeType_Dot：  圆点虚线，虚线间隔配置参考 lineDashPattern变量
 */
@property (nonatomic, assign) QOverlayStrokeType lineType;

/**
 *  @brief 圆的描边虚线间隔配置。单位是屏幕长度(CGPoint长度)。
 *  只有当 lineType 为 QOverlayStrokeType_Dash，QOverlayStrokeType_Dot 时有效.
 *
 *  一 长方块虚线。当用户设置的参数无效或者未设置时，使用 @[@(2 * lineWidth), @(lineWidth] 作为默认值。
 *  当 lineType == QOverlayStrokeType_Dash 时，lineDashPattern 数组中的前两个元素有效
 *      lineDashPattern[0] 表示 长方块宽度，
 *      lineDashPattern[1] 表示 空白宽度.
 *
 *   配置示例：lineDashPattern = @[@(8), @(4)];
 *
 *  二 圆点虚线。当用户设置的参数无效或者未设置时，使用 @[@(lineWidth] 作为默认值。
 *  当 lineType == QOverlayStrokeType_Dot 时，lineDashPattern 数组中的第一个元素有效
 *      lineDashPattern[0] 表示 空白宽度，
 *
 *   配置示例：lineDashPattern = @[@(8)];
 *
 */
@property (nonatomic, copy) NSArray<NSNumber *> *lineDashPattern;

@end
