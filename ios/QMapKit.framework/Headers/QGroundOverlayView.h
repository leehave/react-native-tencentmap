//
//  QGroundOverlayView.h
//  QMapKit
//
//  Created by fan on 2020/4/21.
//  Copyright © 2020 tencent. All rights reserved.
//

#import <QMapKit/QGLOverlayView.h>
#import "QGroundOverlay.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 用于地面(图片)覆盖物视图的类
*/
@interface QGroundOverlayView : QGLOverlayView

/**
 * @brief 构造函数
 */
- (instancetype)initWithOverlay:(QGroundOverlay *)overlay;

/**
 * @brief 本View对应的数据类
 */
@property (nonatomic, strong, readonly) QGroundOverlay *overlay;

@end

NS_ASSUME_NONNULL_END
