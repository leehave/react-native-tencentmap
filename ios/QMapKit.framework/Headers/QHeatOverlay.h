//
//  QHeatOverlay.h
//  QMapKit
//
//  Created by Keith Cao on 2020/9/10.
//  Copyright © 2020 tencent. All rights reserved.
//

#ifndef _QHEATOVERLAY_H_
#define _QHEATOVERLAY_H_

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <QMapKit/QHeatNodeProtocol.h>
#import <QMapKit/QGLOverlay.h>

/**
 * @brief 热力图渐变属性
 */
@interface QHeatGradient : NSObject

/**
 * @brief 颜色变化数组
 */
@property (nonatomic, readonly) NSArray<UIColor *> *colors;

/**
 * @brief 颜色变化节点，需为严格递增数组，区间为[0, 1.0]
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *startPoints;

/**
 * @brief 热力图样式的颜色梯度
 * @param colors      颜色列表
 * @param startPoints 颜色变化节点列表，需为严格递增数组(无相同值)，区间为[0, 1.0]
 * @return QHeatGradient
 *
 * @notes colors和startPoints的个数必须相同
 */
- (instancetype)initWithColor:(NSArray<UIColor *> *)colors andWithStartPoints:(NSArray<NSNumber *> *)startPoints;

@end

/**
 *  @brief  矢量热力图overlay，支持高度效果
 *
 */
@interface QHeatOverlay : QGLOverlay
{
	@package
	QMapRect _boundingRect;
}

/**
 *  @brief  生成热力图overlay
 *
 *  @param heatNodes 热力图节点元素数组, 每个元素符合 QHeatNodeProtocol 协议
 *  @return QHeatOverlay
 */
- (instancetype)initWithHeatNodes:(NSArray<id<QHeatNodeProtocol> > *)heatNodes;

/**
 *  @brief  热力图数据: 原始的节点数据. 数组每个元素符合 QHeatNodeProtocol 协议
 *
 */
@property (nonatomic, copy) NSArray<id<QHeatNodeProtocol> > *nodes;

/**
 *  @brief  热力图样式: 衰变半径. 单位 point
 *
 *  范围越大计算耗时越长。默认10. 取值范围 [6, 50]
 */
@property (nonatomic, assign) NSInteger decayRadius;

/**
 *  @brief  热力图样式: 颜色梯度
 *
 */
@property (nonatomic, strong) QHeatGradient *gradient;

/**
 *  @brief  热力图最大拔高高度. 单位 point. 默认20.
 *
 */
@property (nonatomic, assign) CGFloat maxHeight;

/**
 * @brief 设置热力阈值范围
 * @param minIntensity 最小热力阈值.默认为0
 * @param maxIntensity 最大热力阈值.默认为数据中最大值
 */
- (void)setMinIntensity:(CGFloat)minIntensity maxIntensity:(CGFloat)maxIntensity;

/**
 *  @brief  是否支持拔高3D效果. 默认NO
 *
 */
@property (nonatomic, assign) BOOL enable3D;

/**
 *  @brief  显示时的动画
 *
 */
@property (nonatomic, strong) QAnimation *animation;


@end

#endif
