//
//  QMapCoordinatePoint.h
//  QMapFoundationKit
//
//  Created by Zhang Tian on 2019/8/9.
//  Copyright © 2019 Tencent. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

/// 经纬度的数据类
@interface QMapCoordinatePoint : NSObject

/**
 * @brief 经纬度坐标
 */
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

@end

NS_ASSUME_NONNULL_END
