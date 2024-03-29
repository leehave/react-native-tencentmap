//
//  QOverlayPathView.h
//  QMapKit
//
//  Created by fan on 2017/5/17.
//  Copyright © 2017年 Tencent. All rights reserved.
//

#import "QOverlayView.h"

/**
 *  @brief  该类提供基于几何路径的overlay
 *
 *  基类, 希望不要直接实例化, 可以使用该类的子类QCircleView, QPolylineView, QPolygonView或者继承该类,
 */
@interface QOverlayPathView : QOverlayView

/**
 * @brief  填充颜色
 */
@property(nonatomic, strong) UIColor *fillColor;

/**
 * @brief  画笔颜色
 */
@property(nonatomic, strong) UIColor *strokeColor;

/**
 * @brief  画笔宽度.  单位：CGPoint长度.
 */
@property(nonatomic, assign) CGFloat lineWidth;

/**
 * @brief 透明度[0，1]，默认为1.
 */
@property (nonatomic, assign) CGFloat alpha;

@end
