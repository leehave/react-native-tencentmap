//
//  QVectorHeatOverlay.h
//  QMapKit
//
//  Created by fan on 2020/3/9.
//  Copyright © 2020 tencent. All rights reserved.
//

#ifndef _QVECTORHEATOVERLAY_H_
#define _QVECTORHEATOVERLAY_H_

#import <QMapKit/QHeatNodeProtocol.h>
#import <QMapKit/QGLOverlay.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @enum  QVectorHeatType
 * @brief 热力图的类型
 */
typedef enum QVectorHeatType {
    QVectorHeatTypeHoneyComb,   ///<  蜂窝状
    QVectorHeatTypeSquare       ///<  正方形
} QVectorHeatType;


/**
 * @brief 用于配置热力图属性
 */
@interface QVectorHeatOverlayOption : NSObject

/**
 * @brief 热力图类型 (默认为蜂窝状类型QVectorHeatTypeHoneyComb)
 */
@property (nonatomic, assign) QVectorHeatType type;

/**
 * @brief 显示时边框单元的宽度（内切圆的直径） 单位：米
 *
 * 使用size+gap来计算热力。 size: 左右两端边框的距离，gap: 两个框之间的间隔
 * 默认 2000
 */
@property (nonatomic, assign) CLLocationDistance size;

/**
 * @brief 显示时边框之间的间隔 单位：米
 *
 * 使用size+gap来计算热力。 size: 左右两端 边框的距离，gap: 两个框之间的间隔
 */
@property (nonatomic, assign) CLLocationDistance gap;

/**
 * @brief 透明度，取值范围[0,1] ，默认为1不透明
 */
@property (nonatomic, assign) CGFloat opacity;

/**
 * @brief 最小显示级别 默认 3
 */
@property (nonatomic, assign) CGFloat minZoom;

/**
 * @brief 最大显示级别  默认  22
 */
@property (nonatomic, assign) CGFloat maxZoom;

/**
 * @brief 最小高度 默认 0
 */
@property (nonatomic, assign) CGFloat minHeight;

/**
 * @brief 最大高度 默认 100
 */
@property (nonatomic, assign) CGFloat maxHeight;

/**
 * @brief 设置热力值范围. 如果不设置则根据数据源的数值计算
 * @param minIntensity 最小热力值
 * @param maxIntensity 最大热力值
 */
- (void)setMinIntensity:(CGFloat)minIntensity maxIntensity:(CGFloat)maxIntensity;

/**
 * @brief 颜色变化数组。
 * 与startPoints配合使用。注意：colors和startPoints两数组长度必须一致且不能为0，
 */
@property (nonatomic, readonly) NSArray<UIColor *> *colors;

/**
 * @brief 颜色变化起点，需为递增数组，每个元素代表权重的一个节点(此节点为显示颜色的切换点)
 *
 *  与colors配合使用。注意：colors和startPoints两数组长度必须一致且不能为0。
 *  用法说明：
 *		例如：startPoints = @[@0.0, @0.6, @0.8] 表示在3个区间分别显示3种颜色。
 * 		当在区间[0, 0.6)使用第一个颜色，区间[0.6，0.8)使用第二个颜色，区间[0.8,  1.0]使用第三个颜色。
 *		startPoints第一个元素需要为0.0
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *startPoints;

/**
 *	@brief 设置颜色变化数组和颜色变化起点
 *	@param colors 颜色变化数组, 与startPoints配合使用
 *	@param startPoints 颜色变化起点，需为递增数组，每个元素代表权重的一个节点(此节点为显示颜色的切换点)
 *					   与colors配合使用
 */
- (void)setColors:(NSArray<UIColor *> *)colors startPoints:(NSArray<NSNumber *> *)startPoints;

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



/**
 * @brief 热力图展示单元
 *
 * 用以描述一个聚合单元：如蜂窝或一个网格
 */
@interface QVectorHeatAggregationUnit : NSObject

/**
 * @brief 中心点坐标
 */
@property (nonatomic, assign) CLLocationCoordinate2D center;

/**
 * @brief 当前热力值，求和后的权重
 */
@property (nonatomic, assign) float intensity;

/**
 * @brief 落在此单元区域内的所有热力点的索引数组
 */
@property (nonatomic, strong) NSArray<NSNumber *> *nodeIndices;

@end


/**
 * @brief 热力图overlay
 *
 * 与QVectorHeatOverlayView配合使用
 */
@interface QVectorHeatOverlay : QGLOverlay
{
    @package
    QMapRect _boundingRect;
}

/**
 *  @brief  热力图数据: 原始的节点数据. 数组每个元素符合 QHeatNodeProtocol 协议
 *
 */
@property (nonatomic, copy ) NSArray<id<QHeatNodeProtocol> > *nodes;

/**
 * @brief 地理基准点。 会用于米到墨卡托单位的转换。如果不设置（默认）则会使用nodes数据集的中心点
 */
@property (nonatomic, assign) CLLocationCoordinate2D geoReferencePoint;

/**
 *  @brief  热力图配置项
 *
 */
@property (nonatomic, readonly) QVectorHeatOverlayOption *option;

/**
 * @brief 颜色变化数组。
 * 与startPoints配合使用。注意：colors和startPoints两数组长度必须一致且不能为0，
 */
@property (nonatomic, readonly) NSArray<UIColor *> *colors;

/**
 * @brief 颜色变化起点，需为递增数组，每个元素代表权重的一个节点(此节点为显示颜色的切换点)
 *
 *  与colors配合使用。注意：colors和startPoints两数组长度必须一致且不能为0。
 *  用法说明：
 *		例如：startPoints = @[@0.0, @0.6, @0.8] 表示在3个区间分别显示3种颜色。
 * 		当在区间[0, 0.6)使用第一个颜色，区间[0.6，0.8)使用第二个颜色，区间[0.8,  1.0]使用第三个颜色。
 *		startPoints第一个元素需要为0.0
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *startPoints;

/**
 *	@brief 设置颜色变化数组和颜色变化起点
 *	@param colors 颜色变化数组, 与startPoints配合使用
 *	@param startPoints 颜色变化起点，需为递增数组，每个元素代表权重的一个节点(此节点为显示颜色的切换点)
 *					   与colors配合使用
 */
- (void)setColors:(NSArray<UIColor *> *)colors startPoints:(NSArray<NSNumber *> *)startPoints;

/**
 * @brief 热力图类型 (默认为蜂窝状类型QVectorHeatTypeHoneyComb)
 */
@property (nonatomic, assign) QVectorHeatType type;

/**
 * @brief 最小高度 默认 0.
 */
@property (nonatomic, readonly) CGFloat minHeight;

/**
 * @brief 最大高度 默认 100.
 */
@property (nonatomic, readonly) CGFloat maxHeight;

/**
 * @brief 设置热力高度范围. 如果不设置则根据数据源的数值计算
 * @param minHeight 最小高度
 * @param maxHeight 最大高度
 */
- (void)setMinHeight:(CGFloat)minHeight maxHeight:(CGFloat)maxHeight;

/**
 * @brief 设置热力值范围
 * @param minIntensity 最小热力值
 * @param maxIntensity 最大热力值
 */
- (void)setMinIntensity:(CGFloat)minIntensity maxIntensity:(CGFloat)maxIntensity;

/**
 * @brief 显示时边框单元的宽度（内切圆的直径） 单位：米
 *
 * 使用size+gap来计算热力。 size: 左右两端边框的距离，gap: 两个框之间的间隔
 * 默认 2000, 最小值 10
 */
@property (nonatomic, assign) CLLocationDistance size;

/**
 * @brief 显示时边框之间的间隔 单位：米
 *
 * 使用size+gap来计算热力。 size: 左右两端 边框的距离，gap: 两个框之间的间隔
 */
@property (nonatomic, assign) CLLocationDistance gap;

/**
 *  @brief  是否支持拔高3D效果. 默认NO
 *
 */
@property (nonatomic, assign) BOOL enable3D;

/**
 * @brief  区域外接矩形
 */
@property(nonatomic, readonly) QMapRect boundingMapRect;

/**
 *  @brief  生成热力图overlay
 *
 *  @param heatNodes 热力图节点元素数组, 每个元素符合 QHeatNodeProtocol 协议
 *  @return heatOverlay
 */
- (instancetype)initWithHeatNodes:(NSArray<id<QHeatNodeProtocol> > *)heatNodes option:(QVectorHeatOverlayOption*)option;

/**
 * @brief 根据经纬度获取对应的热力展示单元
 * @param coordinate 经纬度
 */
- (QVectorHeatAggregationUnit *)getAggregationUnit:(CLLocationCoordinate2D)coordinate;

@end



NS_ASSUME_NONNULL_END

#endif
