//
//  QVectorHeatOverlayView.h
//  QMapKit
//
//  Created by fan on 2020/3/9.
//  Copyright © 2020 tencent. All rights reserved.
//

#ifndef _QVECTORHEATOVERLAYVIEW_H_
#define _QVECTORHEATOVERLAYVIEW_H_

#import <Foundation/Foundation.h>
#import <QMapKit/QGLOverlayView.h>
#import "QVectorHeatOverlay.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 用于热力图视图的类
 */
@interface QVectorHeatOverlayView : QGLOverlayView

/**
 * @brief 构造函数
 */
- (instancetype)initWithHeatOverlay:(QVectorHeatOverlay *)overlay;

/**
 * @brief 本View对应的数据类
 */
@property (nonatomic, strong, readonly) QVectorHeatOverlay *overlay;

@end

NS_ASSUME_NONNULL_END

#endif
