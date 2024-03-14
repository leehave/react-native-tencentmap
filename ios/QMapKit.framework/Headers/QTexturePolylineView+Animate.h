//
//  QTexturePolylineView+Animate.h
//  QMapKit
//
//  Created by fan on 2019/9/10.
//  Copyright © 2019 tencent. All rights reserved.
//

#import "QTexturePolylineView.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief QTexturePolylineView的动画扩展类
 */
@interface QTexturePolylineView (Animate)

/**
 * @brief 线被添加时的动画. 默认为无(目前只有多段的蚯蚓线支持动画)
 */
@property (nonatomic, assign, nullable) QAnimation    *emergeAnimation;


@end

NS_ASSUME_NONNULL_END
