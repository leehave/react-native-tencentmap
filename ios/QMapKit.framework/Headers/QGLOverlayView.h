//
//  QGLOverlayView.h
//  QMapKit
//
//  Created by fan on 2020/5/21.
//  Copyright © 2020 tencent. All rights reserved.
//

#import "QOverlayView.h"
#import "QGLOverlay.h"

NS_ASSUME_NONNULL_BEGIN

@interface QGLOverlayView : QOverlayView

/**
 * @brief 构造函数
 */
- (instancetype)initWithOverlay:(QGLOverlay *)overlay;

/**
 * @brief 本View对应的数据类
 */
@property (nonatomic, strong, readonly) QGLOverlay *overlay;

@end

NS_ASSUME_NONNULL_END
