//
//  QOverlayObject.h
//  QMapKit
//
//  Created by KeithCao on 2022/7/15.
//  Copyright © 2022 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 可被点击对象的抽象基类
 */
@interface QOverlayObject : NSObject

/**
 * @brief 点击的经纬度
 */
@property (nonatomic, assign) CLLocationCoordinate2D clickedPosition;

/**
 * @brief 被点击对象的标识符
 */
@property (nonatomic, copy) NSString *identifier;

/**
 * @brief 被点击对象的名称，可能为空
 */
@property (nonatomic, copy) NSString *name;

@end

NS_ASSUME_NONNULL_END
