//
//  QMapView+VisualLayer.h
//  QMapKit
//
//  Created by Keith Cao on 2021/5/17.
//  Copyright © 2021 tencent. All rights reserved.
//

#import <QMapKit/QMapKit.h>
#import "QVisualLayer.h"

NS_ASSUME_NONNULL_BEGIN
/**
 *  @brief  可视化数据图层相关的API
 */
@interface QMapView (VisualLayer)

/**
 * @brief  向地图添加一个可视化数据图层
 * @param visualOverlay 要添加的图层
 */
- (void)addVisualLayer:(QVisualLayer *) visualOverlay;

/**
 * @brief  从地图移除一个个性化图层
 * @param visualOverlay 要移除的图层
 */
- (void)removeVisualLayer:(QVisualLayer *) visualOverlay;

@end

NS_ASSUME_NONNULL_END
