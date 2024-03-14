//
//  QArcView.h
//  QMapKit
//
//  Created by Keith Cao on 2020/11/19.
//  Copyright © 2020 tencent. All rights reserved.
//

#import "QArc.h"
#import "QOverlayPathView.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  @brief 此类是QArc用于显示弧线的view
 */

@interface QArcView : QOverlayPathView

/**
 *  @brief  根据指定的QArc生成一个弧线view
 *
 *  @param arc 指定的QArc
 *
 *  @return 新生成的弧线view
 */
- (instancetype)initWithArc:(QArc *)arc;

/**
 *  @brief  关联的QArc对象
 */
@property (nonatomic, readonly) QArc *arc;

/**
 * @brief 描边的宽度。 单位：Point. 宽度为0时无描边(描边宽度请小于lineWidth的一半)
 */
@property(nonatomic, assign) CGFloat     borderWidth;

/**
 * @brief 描边的颜色。 宽度为0时无描边
 */
@property(nonatomic, strong) UIColor     *borderColor;

/**
 * @brief 实线和虚线的线长序列(元素个数必须是偶数)。默认为nil为实线
 */
@property (nonatomic, copy) NSArray<NSNumber *> *lineDashPattern;

/**
 * @brief 是否绘制箭头图标
 */
@property (nonatomic, assign, getter=isDrawSymbol) BOOL   drawSymbol;

/**
 * @brief 箭头之间的间距. 单位：Point
 */
@property (nonatomic, assign) CGFloat   symbolGap;

/**
 * @brief 当与底图上的POI/道路名 相交时，是否将其碰撞掉。默认为NO（碰撞掉）
 */
@property(nonatomic, assign) BOOL disableCollideLabel;

@end

NS_ASSUME_NONNULL_END
